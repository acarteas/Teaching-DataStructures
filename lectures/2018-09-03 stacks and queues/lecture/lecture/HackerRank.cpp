#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int getHeight(vector<int>& some_stack)
{
    int counter = 0;
    for (auto i : some_stack)
    {
        counter += i;
    }
    return counter;
}

/*
* Complete the equalStacks function below.
*/
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {

    //h1[0] is the top
    vector<int> s1{};
    vector<int> s2{};
    vector<int> s3{};

    while (h1.size() > 0)
    {
        s1.push_back(h1.back());
        h1.pop_back();
    }
    while (h2.size() > 0)
    {
        s2.push_back(h2.back());
        h2.pop_back();
    }
    while (h3.size() > 0)
    {
        s3.push_back(h3.back());
        h3.pop_back();
    }

    //Continually loop through all 3 stacks.
    //For the selected stack ask if any of the other two are smaller.
    //  If one is smaller, pop top item from stack.  Otherwise pass.
    //If we observe three passes in a row, we're done
    int current_stack = 0;
    int counter = 0;
    vector<vector<int>*> all_stacks{ &s1, &s2, &s3 };

    //We believe this is broken when under certain unknown circumstances our WHILE
    //loop never terminates.  
    while (counter < 3)
    {
        //consider adjacent stacks
        int second_stack = (current_stack + 1) % 3;
        int third_stack = (second_stack + 1) % 3;

        //Is the stack larger than at least one other stack?
        if (getHeight(*all_stacks[current_stack]) > getHeight(*all_stacks[second_stack])
            ||
            getHeight(*all_stacks[current_stack]) > getHeight(*all_stacks[third_stack])
            )
        {
            //cout << "Removing " << all_stacks[current_stack]->back() << " from " << current_stack
            //  << endl;
            all_stacks[current_stack]->pop_back();
            counter = 0;
        }
        else
        {
            //not smaller, pass
            counter++;
        }


        //consider the next stack
        current_stack = (current_stack + 1) % 3;
    }


    return getHeight(s1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n1N2N3_temp;
    getline(cin, n1N2N3_temp);

    vector<string> n1N2N3 = split_string(n1N2N3_temp);

    int n1 = stoi(n1N2N3[0]);

    int n2 = stoi(n1N2N3[1]);

    int n3 = stoi(n1N2N3[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split_string(h1_temp_temp);

    vector<int> h1(n1);

    for (int h1_itr = 0; h1_itr < n1; h1_itr++) {
        int h1_item = stoi(h1_temp[h1_itr]);

        h1[h1_itr] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split_string(h2_temp_temp);

    vector<int> h2(n2);

    for (int h2_itr = 0; h2_itr < n2; h2_itr++) {
        int h2_item = stoi(h2_temp[h2_itr]);

        h2[h2_itr] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split_string(h3_temp_temp);

    vector<int> h3(n3);

    for (int h3_itr = 0; h3_itr < n3; h3_itr++) {
        int h3_item = stoi(h3_temp[h3_itr]);

        h3[h3_itr] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

#include <unordered_map>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int keyFromString(string s) {
    int hash = 0;
    for (auto ch : s) {
        hash += (int)ch;
    }
    return hash;
}

//doesn't work.  needs fixing
unsigned long keyFromStringV2(string s) {
    unsigned long hash = 1;
    for (int i = 0; i < s.size(); i++) {
        unsigned long char_value = (int)s[i];
        unsigned long temp = char_value << 2;
        temp = char_value * char_value * temp;
        temp += char_value;
        temp *= (i + 1);
        hash = temp << 2;
    }
    return hash;
}

int main(void)
{
    //declare an unordered map whose key is a string
    //and whose value is an integer
    unordered_map<string, int> counts{};
    counts["a"] = 1;
    counts["dog"] = 2;
    counts["bwerewr"] = 3;
    counts["bssadfwer"] = 4;

    //looping through a HT requires an auto FOR loop
    for (auto item : counts)
    {
        //our item variable is a complex data type
        //IT IS NOT our key NOR is it our value
        //item has two properties
        //item.first -> the key
        //item.second -> the value
        cout << item.first << " : " << item.second << endl;
    }

    //very good example of HT usage
    counts.clear(); //removes all entries from HT

    //collate data (frequency distribution)
    string data = "seoifnaspoisahdvoiewqfnsalkvuapoioiewr";
    for (char ch : data)
    {
        counts[string{ ch }]++;
    }

    //note: data comes out unsorted
    for (auto item : counts)
    {
        cout << item.first << ": " << item.second << endl;
    }

    //to come sorted, we could use a map, but those are
    //slow.  Instead, we can exploit our data domain.
    for (char i = 'a'; i <= 'z'; i++)
    {
        //cout << i << ": " << counts[string{ i }] << endl;
    }

    //the above outputs a lot blanks.  What if we didn't
    //want to do that?  Well, again we could use a map,
    //but that isn't this lecture.  Instead, we will
    //maintain a parallel array to use for indexing.
    vector<string> sorted_keys{};
    for (auto item : counts)
    {
        sorted_keys.push_back(item.first);
    }
    sort(sorted_keys.begin(), sorted_keys.end());
    cout << endl << endl;
    for (auto key : sorted_keys)
    {
        cout << key << ": " << counts[key] << endl;
    }

    cout << keyFromStringV2("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz") << endl;

    return 0;
}
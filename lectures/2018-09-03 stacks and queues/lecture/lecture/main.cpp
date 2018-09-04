#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int fib(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

string reverse(string source)
{
    //w/o a stack
    /*int j = source.length() - 1;
    char temp = '\0';
    for (int i = 0; i < source.length() / 2; i++)
    {
        temp = source[i];
        source[i] = source[j];
        source[j] = temp;
        j--;
    }
    return source;*/

    stack<char> workspace{};
    string reversed = source;
    for (char ch : source)
    {
        //adds a new item onto the top of the stack
        workspace.push(ch);
    }
    //a   d   a   m
    int i = 0;
    while (workspace.size() > 0)
    {
        //Top lets us see what's on top of the stack
        char temp = workspace.top();
        reversed[i] = temp;
        i++;

        //pop removes the top item from the stack
        workspace.pop();
    }
    return reversed;
}

int main(void)
{
    cout << reverse("adam") << endl;
}
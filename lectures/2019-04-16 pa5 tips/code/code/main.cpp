#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <cctype>
#include <algorithm>
#include <queue>
#include <sstream>
#include <stack>
using namespace std;

string toBinary(int n)
{
   stack<char> flip{};
   ostringstream result{};
   int mask = 1;
   if (n == 0)
   {
      return "0";
   }
   while (mask <= n)
   {
      int temp = n & mask;
      if (temp == 0)
      {
         flip.push('0');
      }
      else
      {
         flip.push('1');
      }
      mask = mask << 1;
   }
   while (flip.size() > 0)
   {
      result << flip.top();
      flip.pop();
   }
   return result.str();
}

vector<string> getBinarySequences(int num_sequences)
{
   vector<string> result{};

   //return empty if user askesd for no sequences
   if (num_sequences == 0)
   {
      return result;
   }
   result.push_back("0");
   
   //return 1 if user asked for one sequence
   if (num_sequences == 1)
   {
      return result;
   }
   result.push_back("1");

   //2 less than # sequences because we already have 2 items in vector
   int num_loops = num_sequences / 2;
   for (int i = 0; i < num_loops; i ++)
   {
      for (char ch = '0'; ch < '2' && result.size() < num_sequences; ch++)
      {
         result.push_back(result[i] + ch);
      }
   }
   return result;
}

int main(void)
{
   /*
   for (int i = 0; i < 17; i++)
   {
      cout << i << ": " << toBinary(i) << endl;
   }
   */
   vector<string> result = getBinarySequences(17);
   for (int i = 0; i < result.size(); i++)
   {
      cout << i << ": " << result[i] << endl;
   }
   
}
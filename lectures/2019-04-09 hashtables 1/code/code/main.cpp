#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

class Person 
{
public:
   string name;
   int age;

   Person(int age = 0, string name = "")
   {
      this->age = age;
      this->name = name;
   }

   //optional to do it this way, but it is kind of nice
   int getPriority() const
   {
      //in a more complex class, this might be an intricate formula
      return age;
   }
};

//in order for a PQ to work, C++ needs to know how to compare them
bool operator<(const Person& a, const Person& b)
{
   return a.getPriority() < b.getPriority();
}

bool operator>(const Person& a, const Person& b)
{
   return a.getPriority() > b.getPriority();
}

int main(void)
{
   //unordered maps are great for counting things
   //e.g. frequency of characters in a string

   //            KEY    VALUE
   //KEY -> how we refer / access box
   //VALUE -> what is inside the box
   //Time comparison of HT vs map
   //HT: O(N)
   //Map: O(NLogN)
   unordered_map<char, int> frequencies{};
   string example = "This is a test, what fun!";
   for (auto ch : example)
   {
      //In C++, keys do not have to exist before we try to access them
      frequencies[tolower(ch)]++;
   }

   //if we care about order, either switch to a map or build and
   //sort a parallel vector of keys
   //HT: O(N)
   //MAP: O(1) - not needed
   vector<char> keys{};
   for (auto kvp : frequencies)
   {
      keys.push_back(kvp.first);
   }

   //HT: O(NLogN)
   //MAP: O(1) - not needed
   sort(keys.begin(), keys.end());

   //output frequencies (sorted)
   //HT: O(N)
   //MAP: O(N)
   for (auto key : keys)
   {
      //              KEY                        VALUE
      cout << "'" << key << "' = " << frequencies[key] << endl;
   }

   //HT: N + N + NLogN + N
   //Map: NLogN + N
   //Using HT would be a bit slower (not too noticable)

   //output the frequencies (unsorted)
   cout << endl << endl;
   for (auto kvp : frequencies)
   {
      //              KEY                        VALUE
      cout << "'" << kvp.first << "' = " << kvp.second << endl;
   }
}
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <cctype>
#include <algorithm>
#include "Person.h"
using namespace std;

class Name {
public:
   string value;

   Name(string n)
   {
      value = n;
   }
};

int main(void)
{
   //AC NOTE: Custom hash ONLY needed if you're using a custom type as
   //the KEY. Nothing special is required if you're using custom type as
   //the VALUE.
   unordered_map<Person, string> test{};
   test[Person{ 55, "Bob" }] = "abc";
   test[Person{ 22, "Sam" }] = "def";

   //example of avoiding custom hash when dealing with pointers
   //If using pointers, be sure to clean up dynamic memory
   unordered_map<Name*, int> test1{};
   test1[new Name{"Bob"}] = 5;
   test1[new Name{"Sam"}] = 7;

   for (auto kvp : test)
   {
      cout << kvp.first.name << " " << kvp.second << endl;
   }

}
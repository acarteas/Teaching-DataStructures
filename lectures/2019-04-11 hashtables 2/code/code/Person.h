#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
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
/*
namespace std {

   //AC: this is called a template specialization 
   template <>
   struct hash<Key>
   {
      std::size_t operator()(const Key& k) const
      {
         using std::size_t;
         using std::hash;
         using std::string;

         // Compute individual hash values for first,
         // second and third and combine them using XOR
         // and bit shifting:
         return ((hash<string>()(k.first)
            ^ (hash<string>()(k.second) << 1)) >> 1)
            ^ (hash<int>()(k.third) << 1);
      }
   };
}
*/

#endif
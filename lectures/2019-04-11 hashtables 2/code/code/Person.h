#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <functional>
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

//AC: operator== is needed to hash items in a hash table
bool operator==(const Person& left, const Person& right)
{
   return left.name == right.name && left.age == right.age;
}

namespace std {

   //AC: this is called a template specialization 
   template <>

   //change this to be for whatever type you're trying to hash
   struct hash<Person>
   {
      std::size_t operator()(const Person& p) const
      {

         // Compute individual hash values for first,
         // second and third and combine them using XOR
         // and bit shifting:
         auto computed_hash = hash<int>()(p.age) * hash<string>()(p.name);
         return computed_hash;
      }
   };
}

#endif
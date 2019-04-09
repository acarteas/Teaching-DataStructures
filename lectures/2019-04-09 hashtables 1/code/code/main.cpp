#include <iostream>
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
   
}
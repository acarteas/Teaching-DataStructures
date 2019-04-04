#include <iostream>
#include <string>
#include <queue> //includes standard queue as well as PQ
#include <functional> //allows for construction of min-heap
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
   //default PQ is max heap
   priority_queue<int> max_heap{};

   //more work is required to define a min heap...
   //        data type(varies), always same, always same
   priority_queue<int, vector<int>, greater<int>> min_heap{};

   //add 10 items to each queue
   for (int i = 0; i < 10; i++)
   {
      max_heap.push(i);
      min_heap.push(i);
   }

   //remove items from queues
   while (max_heap.size() > 0)
   {
      //remember to use top when getting element
      cout << max_heap.top() << " " << min_heap.top() << " ";

      //and remember to do pop to remove the element
      max_heap.pop();
      min_heap.pop();
   }
   cout << endl;

   //example max heap of people
   priority_queue<Person> people_queue{};
   people_queue.push(Person{ 35, "Bob" });
   people_queue.push(Person{ 20, "Sam" });
   people_queue.push(Person{ 40, "Betty" });
   Person p{ 22, "Dave" };
   people_queue.push(p);
   while (people_queue.empty() == false)
   {
      cout << people_queue.top().name << endl;
      people_queue.pop();
   }
}
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

void selectionSort(vector<int>& data)
{
   int temp = 0;
   for (int i = 0; i < data.size(); i++)
   {
      int smallest_index = i;

      //finds the smallest element
      for (int j = i + 1; j < data.size(); j++)
      {
         if (data[smallest_index] > data[j])
         {
            smallest_index = j;
         }
      }
      
      //swap smallest index with value at i
      temp = data[i];
      data[i] = data[smallest_index];
      data[smallest_index] = temp;

   }
}

void bubbleSort(vector<int>& data)
{
   //compare adjacent items, swap if out of order
   int temp;
   for (int i = data.size(); i > 0; i--)
   {
      bool has_swapped = false;
      for (int j = 0; j < i - 1; j++)
      {
         if (data[j] > data[j + 1])
         {
            temp = data[j];
            data[j] = data[j + 1];
            data[j + 1] = temp;
            has_swapped = true;
         }
      }
      if (has_swapped == false)
      {
         break;
      }
   }
}

void insertionSort(vector<int>& data)
{
   int temp;

   //i loop tracks sorted section
   for (int i = 0; i < data.size() - 1; i++)
   {
      //j loop puts next item into sorted section of array
      for (int j = i + 1; j > 0; j--)
      {
         if (data[j] < data[j - 1])
         {
            temp = data[j];
            data[j] = data[j - 1];
            data[j - 1] = temp;
         }
         else
         {
            //if no swap made, we're in the right place
            break;
         }
      }
   }
}

int main(void)
{
   vector<int> data{};
   for (int i = 0; i < 20; i++)
   {
      data.push_back(rand() % 100);
   }
   selectionSort(data);
}
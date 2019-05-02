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

void quickSortHelper(vector<int>& data, int start, int end)
{
   
   if (end < start)
   {
      return;
   }
   //base case #1: array of size 1
   if (start == end)
   {
      return;
   }
   else if (end - start == 1)
   {
      //array size 2
      if (data[end] < data[start])
      {
         int temp = data[end];
         data[end] = data[start];
         data[start] = temp;
      }
   }

   int first_item = data[start];
   int last_item = data[end];
   int midpoint = (start + end) / 2;
   int middle_item = data[midpoint];

   //select pivot
   
   int pivot_index = start;

   //1 5 10
   if (middle_item > first_item && middle_item < last_item ||

      //10 5 1
      middle_item < first_item && middle_item > last_item)
   {
      pivot_index = midpoint;
   }
   else if (last_item > first_item && last_item < middle_item ||
      last_item < first_item && last_item > middle_item)
   {
      pivot_index = end;
   }

   //swap piviot with last item
   int pivot_value = data[pivot_index];
   data[pivot_index] = data[end];
   data[end] = pivot_value;

   /*
   	1. Define i = front; j = end - 1
	2. WHILE data[i] < pivot AND i < j
		a. Increment i
	3. WHILE data[j] > pivot AND i < j
		a. Decrement j
	4. If i != j:
		a. Swap numbers[i] with numbers[j]
		b. Go back to step #2
	5. Loop is done.  Swap numbers[end] with numbers[i]
Recursively repeat this process on the divided array
   */
   int i = start;
   int j = end - 1;
   while (i < j)
   {
      while (data[i] < pivot_value && i < j)
      {
         i++;
      }
      while (data[j] > pivot_value && i < j)
      {
         j--;
      }
      if (i < j)
      {
         int temp = data[i];
         data[i] = data[j];
         data[j] = temp;
      }
   }

   //swap pivot back
   int temp = data[i];
   data[i] = data[end];
   data[end] = temp;

   quickSortHelper(data, start, i - 1);
   quickSortHelper(data, i + 1, end);
}

void quickSort(vector<int>& data)
{
   quickSortHelper(data, 0, data.size() - 1);
}


int main(void)
{
   vector<int> data{};
   for (int i = 0; i < 20; i++)
   {
      data.push_back(rand() % 100);
   }
   quickSort(data);
}
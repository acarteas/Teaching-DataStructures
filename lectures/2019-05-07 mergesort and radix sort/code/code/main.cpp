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

void mergeSortHelper(vector<int>&data, int start, int end)
{
   if (start == end)
   {
      //array of size 1, sorted!
      return;
   }
   else if (end - start == 1)
   {
      //array of size 2, swap if necessary
      if (data[end] < data[start])
      {
         int temp = data[end];
         data[end] = data[start];
         data[start] = temp;
      }
      return;
   }

   //not a base case, recurse!
   int midpoint = (start + end) / 2;

   //sanity check: ensure midpoint is above start and below end
   if (start < midpoint)
   {
      mergeSortHelper(data, start, midpoint);
   }
   if (end > midpoint)
   {
      mergeSortHelper(data, midpoint, end);
   }

   //at this point, we have at minimum an array of size 3
   //where from start-midpoint is sorted and from midpoint-end is sorted
   int left_index = start;
   int right_index = midpoint;
   vector<int> merged{};
   while (left_index < midpoint && right_index < end)
   {
      //which is smaller?
      if (data[left_index] < data[right_index])
      {
         merged.push_back(data[left_index]);
         left_index++;
      }
      else
      {
         merged.push_back(data[right_index]);
         right_index++;
      }
   }

   //After this WHILE breaks
   //1. left_index and right_index are invalid
   //2. left_index is still valid.  Still need to add things from left side
   //3. right_index is still valid.  Same thing for right side.

   //how to handle case #2
   while (left_index < midpoint)
   {
      merged.push_back(data[left_index]);
      left_index++;
   }

   //case #3
   while (right_index < end)
   {
      merged.push_back(data[right_index]);
      right_index++;
   }

   //put stuff back into original array
   for (int i = 0, j = start; i < merged.size(); i++, j++)
   {
      data[j] = merged[i];
   }
}

void mergeSort(vector<int>& data)
{
   mergeSortHelper(data, 0, data.size() - 1);
}

void radixSort(vector<int>& data)
{
   //two sets of buckets: one for current items, one for new items
   vector<vector<int>> current_buckets{};
   vector<vector<int>> next_buckets{};

   //set bucket sizes to 10
   current_buckets.resize(10);
   next_buckets.resize(10);

   //put all of data's values into current's zero bucket
   current_buckets[0] = move(data);

   bool is_not_sorted = true;
   int power_of_ten = -1;
   while (is_not_sorted == true)
   {
      is_not_sorted = false;
      power_of_ten++;
      int divisor = pow(10, power_of_ten);
      for (int i = 0; i < 10; i++)
      {
         for (auto& item : current_buckets[i])
         {
            int destination_bucket = (item / divisor) % 10;
            next_buckets[destination_bucket].push_back(item);

            if (item / divisor > 0)
            {
               is_not_sorted = true;
            }
         }
      }

      current_buckets = move(next_buckets);
      next_buckets.resize(10);
   }

   data = move(current_buckets[0]);
}

int main(void)
{
   vector<int> data{};
   for (int i = 0; i < 20; i++)
   {
      data.push_back(rand() % 100);
   }
   radixSort(data);
}
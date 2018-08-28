int PRIME_QUUE::D()
{
    if(!EMPTY())
    {
        front++;
        
int smallest = Array_queue[front];
int index = front;
        
for(int i = front + 1; i <= back; i++)
{
    if(Array_queue[i] < smallest)
            {
    smallest = Array_queue[i];
    index = i;
    }
}
        
for(int j = index; j > front; j--)
Array_queue[j] = Array_queue[j - 1];
Array_queue[front] = 0;
numberofitems--;
        return smallest;
}
    
        return -1;
}
find(5, numbers, 0, numbers.size());
int find(int value, vector<int> numbers, int start_index, int end_index){
    int mid_index = (start_index + end_index) / 2;

    //base case
    if(start_index > end_index)
    {
        return -1;
    }
    else if(start_index == end_index)
    {
        if(value[start_index] == value) {return start_index};
        else {return -1};
    }

    //item found?
    if(numbers[mid_index] > value)
    {
        //too big, move to "the left"
        return find(value, numbers, start_index, mid_index);
    }
    else if(numbers[mid_index] < value)
    {
        return find(value, numbers, mid_index, end_index);
    }
    else
    {
        return mid_index;
    }
}
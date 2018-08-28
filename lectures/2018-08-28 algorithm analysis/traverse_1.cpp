void printLinkedList(SinglyLinkedListNode* head)
{
    // assigning a Node current to point to the head
    SinglyLinkedListNode *current = head;

    // while the current pointer is not NULL(empty)
    // cout the data(elements) of the singly linked lists
    // this prints out the elements until there are no more
    while(current != nullptr)
    {
        // current pointer -> data (element)
        // assign current pointer to next(new) element
        cout << current->data << endl;
        current = current->next;
    }
}

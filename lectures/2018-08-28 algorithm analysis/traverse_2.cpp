void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* to_print = head;
    while (to_print != nullptr)
    {
        cout << to_print->data << endl; 
        to_print = to_print->next;
    }
}
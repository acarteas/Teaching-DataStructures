SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data,
                                               int position) 
{
    SinglyLinkedListNode* prevNode = nullptr;
    SinglyLinkedListNode* next = nullptr;
    SinglyLinkedListNode* currentNode = head;
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
   
    
    for(int i=0; i<position; i++)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;        
        next = currentNode->next; 
    }
    
    prevNode->next = node;
    node->next = currentNode;
    
    return head;   
      
}
bool has_cycle(SinglyLinkedListNode* head) {
    if(head == NULL || head->next == NULL)
        return false;
    
    SinglyLinkedListNode* one = head;
    SinglyLinkedListNode* two = head->next;
    
    //O(N) linear relationship
    while(two != NULL && two->next != NULL)
    {
        one = one->next;
        two = two->next->next;
        
        if(one == two)
            return true;
    }
    
    return false;
    
}
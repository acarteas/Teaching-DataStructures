int main(int argc, char** argv) 
{
    typedef SuitorNode* SuitorPtr;
    
    // Get the number of suitorNodes you will need to create.  
    int numberOfSuitors = getSuitorQuant(MINIMUM_SUITORS); 
    
    // Create the objects for each suitor, link them linearly, and then connect
    // the end of the list to the head to create a circular list. 
    SuitorPtr head, end, temp, toDelete; 
    head = new SuitorNode(numberOfSuitors);
    end = head; 
    for(int i = (numberOfSuitors - 1); i >= MINIMUM_SUITORS; i--)
    {
        headInsert(head, i); 
    } 
    end->setNext(head); 
    
    // Start eliminating suitors until only one is left. 
    cout << "Beginning the suitor elimination process. " << endl; 
    int elementQuantity = numberOfSuitors; 
    printSuitorList(elementQuantity, head);
    
    temp = end; 
    while(temp != temp -> getNext())
    {
        for(int i = 0; i < (PRINCESS_NAME_LENGTH - 1); i++)
            temp = temp -> getNext(); 
        
        toDelete = temp -> getNext(); 
        temp -> setNext(toDelete->getNext()); 
        if(head == toDelete)
            head = toDelete -> getNext(); // Move head forward by one suitorNode.
        if(end == toDelete)
            end = temp; // Move end backward by one suitorNode.
        delete toDelete; 
        
        elementQuantity--; 
        printSuitorList(elementQuantity, head);
    }
    
    // Report the results of the selection process.
    temp = head; 
    reportResults(numberOfSuitors, temp);
    
    // Delete the final node.
    delete head; 
    
    return 0;
}
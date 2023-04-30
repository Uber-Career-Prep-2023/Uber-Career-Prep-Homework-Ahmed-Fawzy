/*
n is number of nodes

Time spent:       25 minutes
Technique:        Linked list fixed-distance two-pointer
Time complexity:  O(n)
Space complexity: O(1)
*/

#include "header.h"
#include <iostream>

void DedupSortedList(Node* node)
{

    if (node == nullptr)
        return;

    Node* nextNode = node->next;

    while(nextNode != nullptr){

        if (nextNode->data == node->data){

            Node* temp = nextNode;
            node->next = nextNode->next;

            delete temp;

            nextNode = node->next;
        }

       else{ 
        node = node->next;
        nextNode = nextNode->next;
       }

    }

  
}

int main()
{
    Node* head = new Node;
    head->data = 1;
    head->next =nullptr;

    insertAtBack(head, 2);
    insertAtBack(head, 2);
    insertAtBack(head, 4);
    insertAtBack(head, 5);
    insertAtBack(head, 5);
    insertAtBack(head, 5);
    insertAtBack(head, 10);
    insertAtBack(head, 10);

    Node* head2 = new Node;
    head2->data = 8;
    head2->next = nullptr;

    insertAtBack(head2, 8);
    insertAtBack(head2, 8);
    insertAtBack(head2, 8);



    std::cout<<"Original List: ";
    printList(head);

    DedupSortedList(head);
    std::cout<<"List after duplicates removed: ";
    printList(head);
    std::cout<<std::endl;


    std::cout<<"Original List: ";
    printList(head2);


    DedupSortedList(head2);
    std::cout<<"List after duplicates removed: ";
    printList(head2);



    clearList(head);
    clearList(head2);

}
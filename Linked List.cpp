#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};

void printList(Node* n){
    while(n != 0){
        cout << n -> data << " ";
        n = n -> next;
    }
}

void insert(Node** head_ref, int new_data){
    Node* new_node = new Node(); //allocation of node in the heap
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}


void insertAfter(Node* prev_node, int new_data){
    
    if (prev_node == NULL){
        cout << "The given node cannot be null";
        return;
    }
    Node* new_node = new Node();
    new_node -> data = new_data;
    new_node -> next = prev_node -> next;
    prev_node -> next = new_node;
}

void insertAtLast(Node** head_ref,int new_data){
    Node* new_node = new Node();
    Node* last = (*head_ref);
    new_node -> data = new_data;
    new_node -> next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last -> next;
    }
    
    last -> next = new_node;
    return;
    
}


void deleteWithKey(Node** head_ref, int key){
    Node* temp = *head_ref;
    Node* prev = NULL;
    
    if(temp!= NULL && temp -> data == key){
        *head_ref = temp -> next;
        delete temp;
        return;
    }
    else{
        while(temp != NULL && temp -> data != key){
            prev = temp;
            temp = temp -> next;
        }
        if(temp == NULL){
            return;
        }
        
        prev-> next = temp -> next;
        delete temp;
    }
    
}


void deleteAtPos(Node** head_ref, int pos){
    if(*head_ref == NULL){
        return;
    }
    Node* temp = *head_ref;
    if(pos == 0){
        *head_ref = temp -> next;
        //temp -> next = NULL;
        delete temp;
        return;
    }
    
    for(int i = 0; temp!=NULL && i<pos -1; i++){
        temp = temp -> next;
    }
    if(temp == NULL && temp -> next == NULL){
        return;
    }
    Node* next = temp->next->next;
    delete temp -> next;
    temp -> next = next;
    
}


void deleteLL(Node** head_ref){
    Node* current = *head_ref;
    Node* next = NULL;
    
    while(current!=NULL){
        next = current ->next;
        delete current;
        current = next;
    }
    
    *head_ref = NULL;
}


int getCount(Node* head){
    Node* current = head;
    int count = 0;
    while(current != NULL){
        count++;
        current = current -> next;
    }
    cout<< "the count is " ;
    return count;
}


int getRecursiveCount(Node* head){
    if(head == NULL) return 0;
    else return 1 + getRecursiveCount(head -> next);
}

bool iterativeSearch(Node* head, int key){
    Node* current = head;
    while(current != NULL){
        if(current -> data == key) return true;
        current = current -> next;
    }
    return false;
}


bool recursiveSearch(Node* head, int key){
    if(head == NULL) return 0;
    else if(head -> data == key) return 1;
    else return recursiveSearch(head->next, key);
}

int getNthNode(Node* head, int index){
    int count = 0;
    Node* current = head;
    while(current != NULL){
        if (count == index) return current -> data;
        count++;
        current = current -> next;
        
    }
    //After coming out of the loop, we reach to a non-existent node and hence we assert fail
    
    assert(0);
    
}


int getRecursiveNth(Node* head, int index){
    int count = 0;
    if(count == index) return head->data;
    else return getRecursiveNth(head -> next, index-1);
}


void nthNodeFromLast(Node* head, int index){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp -> next;
        len++;
    }
    
    if(len<index) //if given index is more than length
    return;
    
    temp = head;
    
    for(int i = 1; i<len-index+1;i++){
        temp = temp ->next;
    }
    cout << temp -> data;
    return;
}


void RecursiveNthNodeFromLast(Node* head , int index){
    //Why the hell should we use static key word here?
    static int i = 0;
    if(head == NULL) return;
    RecursiveNthNodeFromLast(head -> next, index);
    if(++i == index) cout<< head->data;
}


void middle(Node* head){
    Node* current = head;
    Node* final = head;
    int l = 0;
    while(current != NULL){
        l++;
        current = current -> next;
    }
    //cout << l;
    for(int i = 0; i < (l/2) ;i++){
        final = final -> next;
    }
    cout << final->data;
}



void twoPointerMiddle(Node* head){
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    if(head != NULL){
    while(fast_ptr!=NULL && fast_ptr -> next != NULL){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    cout << slow_ptr -> data;
    }
    
}




int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    
    //Aloocation of nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
    
    head -> data = 1;
    head -> next = second;
    second -> data = 2;
    second -> next = third;
    third -> data = 3;
    third -> next = NULL;
    
    
    
    printList(head);
    cout<<"\n";
    insert(&head, 4);
    //printList(head);
    cout<<"\n";
    insertAfter(second, 5);
    //printList(head);
    insertAtLast(&head, 6);
    cout << "\n";
    //printList(head);
    cout << "\n";
    deleteWithKey(&head, 3);
    //printList(head);
    cout << "\n";
    deleteAtPos(&head, 3);
   // printList(head);
    deleteLL(&head);
    cout << "\n";
    insert(&head,5);
    insert(&head, 7);
    insert(&head, 8);
    insertAtLast(&head, 9);
    insertAtLast(&head, 3);
    insertAtLast(&head, 2);
    printList(head);
    cout << "\n";
    cout << getCount(head);
    cout << "\n";
    cout << getRecursiveCount(head);
    cout << "\n";
    cout << iterativeSearch(head, 9) << "\n";
    cout << iterativeSearch(head, 4);
    cout << "\n";
    cout << recursiveSearch(head, 8)<<"\n";
    cout << recursiveSearch(head, 0)<< "\n";
    cout << getNthNode(head, 2)<<"\n";
    cout << getRecursiveNth(head,2)<<"\n";
    nthNodeFromLast(head, 1);
    cout << "\n";
    RecursiveNthNodeFromLast(head, 4);
    cout<<"\n";
    twoPointerMiddle(head);
    cout << "\n";
    middle(head);
    
    return 0;
    
}

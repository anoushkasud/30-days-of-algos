#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int data){
        this->val = data;
        next = NULL;
    }
};

Node *head = NULL;
class ListNode{
public:
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode; 
        }
        else{
            Node* x = head;
            while(x->next != NULL){
                x = x->next;
            }
            x->next = newNode;
        }
    }
    void addLoop(int val1, int val2){
        Node* x = head;
        Node* y = head;
        while(x->val != val1){
            x = x->next;
        }
        while(y->val != val2){
            y = y->next;
        }
        y->next = x;
    }
};

int main(){
    ListNode l1;
    // inserting new values
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    l1.insert(50);
    // add loop
    l1.addLoop(30,50);

    // Floyd's loop detecting algo
    Node *fast = head, *slow = head;
    // if 2 pointers start from the same point with different speeds and never meet there is no cycle
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(slow == fast){
        // the distance from meeting point to start of the cycle == distance from head to start of cycle 
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        cout<<"cycle starts at: "<<slow->val;
    }
    else{
        //they never met
        cout<<"No cycle";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;
int sz = 0;

void printL(){
    cout<<"L -> ";
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void printR(){
    cout<<"R -> ";
    Node* temp = tail;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

void insertAt(int idx, int val){

    if(idx<0 || idx>sz){
        cout<<"Invalid"<<endl;
        return;
    }
    Node* newNode = new Node(val);

    if(sz == 0){
        head = tail = newNode;
    }
    else if(idx == 0){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if(idx == sz){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else {
        Node* temp = head;
        for(int i=0; i<idx-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    sz++;

    printL();
    printR();
}

int main(){

    int Q; cin>>Q;

    while(Q--){
        int X,V;
        cin>>X>>V;
        insertAt(X,V);
    }

    return 0;
}

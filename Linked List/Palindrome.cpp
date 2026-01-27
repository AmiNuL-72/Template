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

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int x;
    while(1){
        cin>>x;
        if(x==-1) break;

        Node* newNode = new Node(x);

        if(head==NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool ck=1;

    Node* left=head;
    Node* right=tail;

    while(left != right && left->prev != right){
        if(left->data != right->data){
            ck=0; break;
        }
        left = left->next;
        right = right->prev;
    }

    if(ck) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

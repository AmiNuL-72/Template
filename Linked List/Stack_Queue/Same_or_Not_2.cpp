#include <bits/stdc++.h>
using namespace std;

const int MX=1000005;

int st[MX];
int top_idx=-1;

void push_stack(int x){
    st[++top_idx]=x;
}
int top_stack(){
    return st[top_idx];
}
void pop_stack(){
    top_idx--;
}
bool empty_stack(){
    return top_idx == -1;
}

int q[MX];
int front_idx=0, back_idx= -1;

void push_queue(int x){
    q[++back_idx] = x;
}
int front_queue(){
    return q[front_idx];
}
void pop_queue(){
    front_idx++;
}
bool empty_queue(){
    return front_idx > back_idx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int x; cin>>x;
        push_stack(x);
    }
    for(int i=0; i<M; i++){
        int x; cin>>x;
        push_queue(x);
    }

    if(N != M){
        cout<<"NO\n"; return 0;
    }

    while(!empty_stack() && !empty_queue()){
        if(top_stack() != front_queue()){
            cout<<"NO\n";
            return 0;
        }
        pop_stack();
        pop_queue();
    }

    cout<<"YES\n";

    return 0;
}

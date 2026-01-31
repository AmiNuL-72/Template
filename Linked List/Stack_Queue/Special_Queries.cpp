#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin>>Q;

    queue<string>q;

    while(Q--){
        int type;
        cin>>type;

        if(type==0){
            string name;
            cin>>name;
            q.push(name);
        }
        else {  
            if(q.empty()){
                cout<<"Invalid\n";
            } 
            else{
                cout<<q.front()<<"\n";
                q.pop();
            }
        }
    }

    return 0;
}

// istringstream ->> split all word from a sentence

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    string s;
    getline(cin,s);
    istringstream ans(s);
    string word;
    while(ans>>word){
        cout<<word<<endl;
    }
}
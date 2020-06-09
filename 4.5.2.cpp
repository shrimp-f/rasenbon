#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;




int main(){
    stack<int> S;
    int a,b,x;
    string s;

    while(cin>>s){
        cout << s << endl;
        if(s[0]=='+'){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(a+b);
        }else if(s[0]=='-'){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(a-b);
        }else if(s[0]=-'*'){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(a*b);
        }else{
            cout << "here" << endl;
            S.push(atoi(s.c_str()));
        }

        cout << S.top() << endl;

        return 0;
    }
}
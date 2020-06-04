#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;




int top, S[1000];

void push(int x){
    S[++top] = x;
}

int pop(){
    top--;
    return S[top+1];
}

int main(){
    int a, b;
    top = 0;
//    char s[100];
    string s;

    while(cin >> s){
        if(s[0]=='+'){
            a = pop();
            b = pop();
            push(a+b);
        }else if(s[0]=='-'){
            b = pop();
            a = pop();
            push(a-b);
        }else if(s[0]=='*'){
            a = pop();
            b = pop();
            push(a*b);
        }else{
            push(atoi(s.c_str()));
        }
        
        /*
        //デバッグ用
        for(int i = 0; i<10;i++){
            if(i>0){
                cout << " "<< S[i];
            }else{
                cout << S[i];
            }
        }
        cout << endl;
        */
    }

    printf("%d\n", pop());

    return 0;
}
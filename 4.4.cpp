#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;




struct Node{
    int key;
    Node *next, *prev;
};

Node *nil;

Node* listSearch(int key){
    Node * cur = nil->next;
    while(cur != nl && cur->key != key){
        cur = cur->next;
    }
    return cur;
}

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

void printList(){
    Node *cur = nil->next;
    int isf = 0;
    while(1){
        if(cur==nil) break;
        if(isf++ > 0) printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}
#include <bits/stdc++.h>

using namespace std;


#define M 1046527
#define NIL (-1)
#define L 14

char H[M][L];


int getChar(char ch){
    if(ch == 'A') return 1;
    else if(ch == 'C') return 2;
    else if(ch == 'G') return 3;
    else if(ch == 'T') return 4;
    else return 0;
}


long long getKey(char str[]){
    long long sum = 0, p = 1, i;
    for(i=0; i<strlen(str); i++){
        sum += p*(getChar(str[i]));
        p *= 5;
    }
    return sum;
}


int h1(int key){
    return key % M;
}

int h2(int key){
    return 1 + (key % (M - 1));
}


int find(char str[]){
    long long key, i, h;
    key = getKey(str);
    for(i=0; ; i++){
        h = (h1(key) + i * h2(key)) % M;
        if(strcmp(H[h], str) == 0) return 1;
        else if(strlen(H[h]) == 0) return 0;
    }
    return 0;
}


int insert(char str[]){
    long long key, i, h;
    key = getKey(str);
    for(i=0; ; i++){
        h = (h1(key) + i*h2(key)) % M;
        if(strcmp(H[h], str) == 0) return 1;
        else if(strlen(H[h]) == 0){
            strcpy(H[h], str);
            return 0;
        }
    }
    return 0;
}


int main(){
    int i, q, key, sum = 0;
    int A[1000000], n;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for(i=0; i<q; i++){
        scanf("%d", &key);
        if(binarySearch(A, n, key)) sum++;
    }
    printf("%d\n", sum);

    return 0;
}
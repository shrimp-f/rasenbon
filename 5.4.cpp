#include <bits/stdc++.h>

using namespace std;


#define M 1046527
#define NIL (-1)
#define L 14

char H[M][L];


// 文字を数値に変換
int getChar(char ch){
    if(ch == 'A') return 1;
    else if(ch == 'C') return 2;
    else if(ch == 'G') return 3;
    else if(ch == 'T') return 4;
    else return 0;
}

//　getCharで変換した数値を元にkeyを生成する
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
        // 探しているものと、ハッシュテーブルの中身が一緒かどうかを比較で確認
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

        // insertしようとしている文字とハッシュテーブルに入っている文字（入ってない場合もある）を比較
        if(strcmp(H[h], str) == 0) return 1;
        else if(strlen(H[h]) == 0){
            // ハッシュテーブルの中身が空のとき、そこに入れる
            strcpy(H[h], str);
            return 0;
        }
    }
    return 0;
}


int main(){
    int i, n, h;
    char str[10000][L], com[10000][9];
    for(i=0; i<M; i++)  H[i][0] = '\0';
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s %s", com[i], str[i]);
    }

    for(i=0; i<n; i++){
        if(com[i][0]=='i'){
            insert(str[i]);
        }else{
            if(find(str[i])){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
    }

    return 0;
}
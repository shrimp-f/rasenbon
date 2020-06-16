#include <bits/stdc++.h>

using namespace std;




int binarySearch(int A[], int n, int key){
    int left = 0;
    int right = n;
    int mid;

    while(left < right){
        mid = (left + right) / 2;
        if(key==A[mid]) return 1;
        else if(key > A[mid]) left = mid + 1;
        else if(key < A[mid]) right = mid;
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
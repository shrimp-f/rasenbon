#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N){
    int count = 0;
    for(int i = 0; i < N-1; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[minj] > A[j]) minj = j;
        }
        int tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        if(i != minj) count++;
    }
    return count;
}





int main(void)
{
    int N, A[100];
    std::cin >> N;

    for(int i=0; i<N; i++) std::cin >> A[i];

    int count = selectionSort(A, N);

    for(int i = 0; i<N; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;

    return 0;
}

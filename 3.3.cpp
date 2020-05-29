#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int A[], int N){
    int count = 0;
    bool flag = 1;
    for(int i = 0; flag; i++){
        flag = 0;
        for(int j = N-1; j >= i+1; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                count++;
                flag = 1;
            }
        }
    }
    return count;
}





int main(void)
{
    int N, A[100];
    std::cin >> N;

    for(int i=0; i<N; i++) std::cin >> A[i];

    int count = bubbleSort(A, N);

    for(int i = 0; i<N; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;

    return 0;
}

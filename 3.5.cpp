#include <bits/stdc++.h>
using namespace std;




struct Card{
    char suit, value;
};


void bubbleSort(struct Card A[], int N){
    for(int i = 0; i<N; i++){
        for(int j = N-1; j >= i+1; j--){
            if(A[j].value < A[j-1].value){
                Card tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
        }
    }
}


void selectionSort(struct Card A[], int N){
    for(int i = 0; i < N-1; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[minj].value > A[j].value) minj = j;
        }
        Card tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
    }
}


void print(struct Card A[], int N){
    for(int i=0; i<N; i++){
        if(i>0) cout << " ";
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}


bool isStable(struct Card C1[], struct Card C2[], int N){
    for (int i=0; i<N; i++){
        if(C1[i].suit != C2[i].suit) return false;
    }
    return true;
}




int main(void){
    Card C1[100], C2[100];
    int N;
    char ch;

    cin >> N;
    for(int i=0; i<N; i++) std::cin >> C1[i].suit >> C1[i].value;
    for(int i=0; i<N; i++) C2[i] = C1[i];

    bubbleSort(C1,N);
    selectionSort(C2, N);

    print(C1, N);
    cout << "Stable" << endl;
    print(C2, N);
    if(isStable(C1, C2, N)){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }

    return 0;
}

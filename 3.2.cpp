#include <bits/stdc++.h>


int main(void)
{
    int N, A[200];
    std::cin >> N;

    for(int i=0; i<N; i++) std::cin >> A[i];

    for(int i=1; i<N; i++){
        int v = A[i];
        int j = i - 1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            A[j] = v;
            j--;
        }

        for(int i=0; i<N-1; i++) std::cout  << A[i] << " ";
        std::cout << A[N-1] << std::endl;
    }


    return 0;
}

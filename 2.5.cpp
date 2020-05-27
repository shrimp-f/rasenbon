#include <bits/stdc++.h>


int main(void)
{
    int R[200000], n;
    std::cin >> n;

    for (int i=0; i<n; i++) std::cin >> R[i];

    int maxp = -2000000000;
    int min_R = R[0];

    for (int i=1; i<n; i++){
        maxp = std::max(maxp, R[i] - min_R);
        min_R = std::min(min_R, R[i]);
    }

    std::cout << maxp << std::endl;

    return 0;
}

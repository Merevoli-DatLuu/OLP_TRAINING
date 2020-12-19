// Time: O(1)
// Space: O(1)

#include <bits/stdc++.h>

using namespace std;

/*  Cách 1  */
int solve_1(int n){
    int res = 0;
    for (int i=1; i<=n; i++){
        res ^= i;
    }
    return res;
}

/*  Cách 2  */
int solve_2(int n){
    if (n % 4 == 1){
        return 1;
    }
    else if (n % 4 == 2){
        return n + 1;
    }
    else if (n % 4 == 3){
        return 0;
    }
    else if (n % 4 == 0){
        return n;
    }
}

int main(){
    int n = 102;
    cout << solve_1(n) << "\t" << solve_2(n) << "\n";
}

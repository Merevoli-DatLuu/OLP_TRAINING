#include <bits/stdc++.h>

using namespace std;
#define cerr(x) cout << "[LINE " << __LINE__ << "]: " << #x << " -> " << x << '\n';

int n;
int a;

int getFul(int n){
    if (n % 4 == 1){
        return 1;
    }
    else if (n % 4 == 2){
        return n + 1;
    }
    else if (n % 4 == 3){
        return 0;
    }
    else{
        return n;
    }
}

void solve(){
    cin >> n;
    int res = 0;
    int ful = getFul(n);

    for (int i=1; i<=n; i++){
        cin >> a;
        if (a <= n){
            res ^= a;
        }
    }

    res = ful ^ res;

    cout << res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
}

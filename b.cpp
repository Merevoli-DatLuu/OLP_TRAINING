#include <bits/stdc++.h>

using namespace std;
#define cerr(x) cout << "[LINE " << __LINE__ << "]: " << #x << " -> " << x << '\n';

struct hcn{
    int x0, y0, x1, y1;

    hcn(){
        this->x0 = 0;
        this->x1 = 0;
        this->y0 = 0;
        this->y1 = 0;
    }

    hcn(int x0, int y0, int x1, int y1){
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
};

int n;
vector <hcn> a;

void inputData(){
    cin >> n;

    int x0, y0, x1, y1;
    for (int i=1; i<=n; i++){
        cin >> x0 >> y0 >> x1 >> y1;
        a.push_back(hcn(x0, y0, x1, y1));
    }
}

bool compare(hcn a, hcn b){
    if (a.x0 < b.x0){
        return true;
    }
    else if (a.x0 == b.x0){
        if (a.y0 >= b.y0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool hcnin(hcn a, hcn b){
    if (a.x0 >= b.x0 &&
        a.y0 <= b.y0 &&
        a.x1 <= b.x1 &&
        a.y1 >= b.y1){
            return true;
        }
    return false;
}

void solve(){
    sort(begin(a), end(a), compare);

    int res = 1;
    int high[1007];

    memset(high, 0, sizeof(high));
    for (int i=0; i<n; i++){
        high[i]++;
    }

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (hcnin(a[j], a[i])){
                high[j] = max(high[j], high[i] + 1);
            }
        }
    }

    for (int i=0; i<n; i++){
        res = max(res, high[i]);
    }

    cout << res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    inputData();
    solve();
}


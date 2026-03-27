/* GTCoder */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 2e5 + 10;

vector<vector<ll>> arr(2024);
void precompute(){
    arr[1].push_back(1);
    for(ll i=2;i<=2023;i++){
        ll start = ((i*(i-1))/2)+1;
        ll curr = start;
        arr[i].push_back(arr[i-1][0]+(curr*curr));
        curr++;
        for(int j = 1; j <= i-2; j++, curr++){
            arr[i].push_back(arr[i-1][j-1] + arr[i-1][j] - arr[i-2][j-1] + (curr * curr));
        }
        arr[i].push_back(arr[i-1].back()+(curr*curr));
    }
}



void solve() {

    ll n;
    cin>>n;
    ll l = 1,r = 2023;
    while(l <= r){
        ll mid = l + (r-l)/2;
        ll prev = (mid*(mid+1))/2;
        if(prev < n){
            l = mid+1;
        }
        else{
            if(prev-mid < n){
                ll start = prev - mid + 1;
                ll idx = n - start;
                cout << arr[mid][idx] << endl;
                return;
            }
            else r = mid-1;
        }
    }
    
    

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t = 1;
    cin >> t;
    while(t--) solve();
}

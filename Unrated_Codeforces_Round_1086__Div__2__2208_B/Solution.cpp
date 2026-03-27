/* GTCoder */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 2e5 + 10;




void solve() {
    int n,k,p,m;
    cin>>n>>k>>p>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];


    int t = arr[p-1];
    int ans = 0;
    int first = 0;
    if(p <= k){
        first = t;
    }
    else{
        multiset<int> st;
        int sum = 0;
        for(int i = 0;i < k;i += 1){
            st.insert(arr[i]);
        }
        for(int i = k ;i < p-1;i += 1){
            sum += *st.begin();
            st.erase(st.find(*st.begin()));
            st.insert(arr[i]);
        }
        first = sum + *st.begin() + t;
    }
    if(first > m){
        cout<<0<<endl;
        return;
    }
    arr.erase(arr.begin()+p-1);
    sort(arr.begin(),arr.end());
    int cost = accumulate(arr.begin(),arr.begin()+n-k,0)+t;
    // cout<<cost<<" "<<m<<" ";
    ans += (m - first)/cost + 1;
    cout<<ans<<endl;    

    
    





    
    


}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}

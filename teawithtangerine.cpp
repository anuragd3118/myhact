#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        int count = 0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v[i] >= 2*v[0]-1){
                count+=ceil(v[i]/(2.0*v[0]-1))-1;
            }
        }
        cout<<count<<endl;
    }

return 0;
}

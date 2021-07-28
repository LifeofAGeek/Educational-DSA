#include<bits/stdc++.h>
using namespace std;
#define int long long

void computeLPS(vector<int>& lps, string& pat){
    int n = lps.size();
    for(int i = 1; i < n; i++){
        int j = lps[i - 1];

        while(j > 0 && pat[i] != pat[j]) j--;

        if(pat[i] == pat[j]) lps[i] = j + 1;
    }
}


void KMPsearch(string& pat, string& txt){
    int i=0, j=0, n = txt.size(), m = pat.size();
    vector<int> LPS(m,0);
    computeLPS(LPS,pat);
    while(i < n){
        if(pat[j] == txt[i]){
            i++; j++;
        }
        else{
            if(j!=0) j = LPS[j-1];
            else i++;
        }
        if(j == m){
            cout<<"pattern found at index "<<(i-j)<<endl;
            j = LPS[j-1];
        }
    }
    return;
}

void solve(){
    //code goes here
    string txt, pat;
    cin>>txt>>pat;
    KMPsearch(pat,txt);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}

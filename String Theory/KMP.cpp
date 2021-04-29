#include<bits/stdc++.h>
using namespace std;
#define int long long

void computeLPS(vector<int>& lps, string& pat){
    int m = pat.size();
    int i = 1, len = 0;
    while(i < m){
        if(pat[len] == pat[i]){
            lps[i] = len + 1;
            len++;
            i++;
        }
        else{
            if(len) len = lps[len-1];
            else lps[i++] = 0;
        }
    }
    return;
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

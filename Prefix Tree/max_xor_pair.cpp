struct Trie
{
    Trie* next[2];
    bool end;
    Trie(){
        for(int i=0;i<2;i++) next[i]=NULL;
        end=false;
    }
};

Trie *root = new Trie();

void insert(int n){
    Trie *curr=root;

    for(int i=31;i>=0;i--){
        int bit = (n>>i)&1;

        if(bit){
            if(!curr->next[1]) curr->next[1] = new Trie();
            curr=curr->next[1];
        }
        else{
            if(!curr->next[0]) curr->next[0] = new Trie();
            curr=curr->next[0];   
        }
    }
    // ending of a string 
    curr->end=true;
}

int maxXor(int val){
    int ans=0;
    Trie *curr = root;

    for(int i=31;i>=0;i--){
        int bit = (val>>i)&1;

        if(bit){
            // find compliment of 1
            if(curr->next[0]){
                ans+=(1<<i);
                curr=curr->next[0];
            }
            else curr=curr->next[1];
        }
        else{
            // find compliment of 0
            if(curr->next[1]){
                ans+=(1<<i);
                curr=curr->next[1];
            }
            else curr=curr->next[0];
        }
    }
    return ans;
}

void solve(){
    //code goes here
    int n; cin>>n;
    vi arr(n); read(arr,n);

    int curr_max_xor=0,ans=0;

    for(int i=0;i<n;i++){
        insert(arr[i]);
        curr_max_xor=maxXor(arr[i]);
        ans=max(ans,curr_max_xor);
    }
    
    cout<<ans;
}

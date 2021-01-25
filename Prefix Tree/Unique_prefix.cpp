/*
Given strings array, print unique prefixes for every string in array.
Example:
Words[] = {"cobra", "cobras", "dog", "dove", "duck"}
output[] = {-1, "cobras", "dog", "dov", "du"}
*/

struct Trie
{
    Trie* next[26];
    int count;
    bool end;
    Trie(){
        for(int i=0;i<26;i++) next[i]=NULL;
        end=false;
        count=0;
    }
};

Trie *root = new Trie();

void insert(string s){
    Trie *curr=root;
    for(char ch:s){
        if(!curr->next[ch-'a']) curr->next[ch-'a'] = new Trie();
        curr = curr->next[ch-'a'];
        curr->count+=1;
    }
    // ending of a string 
    curr->end=true;
}

int search(string s){
    Trie *curr=root;

    int i=0,n=s.size();
    while(i<n){
        curr=curr->next[s[i++]-'a'];
        if(curr->count==1) return i;
    }
    return -1;
}

void solve(){
    //code goes here
    int n; cin>>n;
    string arr[n]; read(arr,n);

    for(int i=0;i<n;i++){
        insert(arr[i]);
    }

    vector<string> ans;
    for(auto s:arr){
        int pos=search(s);
        if(pos!=-1){
            ans.push_back(s.substr(0,pos));
        }
    }
    for(auto s:ans) cout<<s<<" ";
}

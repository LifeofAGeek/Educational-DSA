struct Trie
{
    Trie* next[26];
    bool end;
    Trie(){
        for(int i=0;i<26;i++) next[i]=NULL;
        end=false;
    }
};

Trie *root = new Trie();

void insert(string s){
    Trie *curr=root;
    for(char ch:s){
        if(!curr->next[ch-'a']) curr->next[ch-'a'] = new Trie();
        curr = curr->next[ch-'a'];
    }
    // ending of a string 
    curr->end=true;
}

bool search(string s){
    Trie *curr=root;

    for(char ch:s){
        if(!curr->next[ch-'a']) return false;
        curr = curr->next[ch-'a'];
    }
    return true;
}

void solve(){
    //code goes here
    string pattern, text;
    cin>>text>>pattern;
    int n=text.size(), m=pattern.size();

    for(int i=0;i<n;i++){
        insert(text.substr(i));
    }

    if(search(pattern)){
        cout<<"Found";
    }
    else cout<<"Not Found";
}

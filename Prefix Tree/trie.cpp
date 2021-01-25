// basic structure of trie
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
    return curr->end;
}

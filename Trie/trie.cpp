#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool terminal;
    TrieNode(char ch){
        data = ch;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
        terminal = false;
    }
};
class Trie{
    TrieNode* root;
    bool isEmpty(TrieNode* root){
        for(int i = 0;i<26;i++){
            if(root->children[i]){
                return false;
            }
        }
        return true;
    }
    void insertUtil(string word,TrieNode* root){
        if(word.size() == 0){
            root->terminal = true;
            return;
        }
        TrieNode* child;
        if(root->children[word[0]-'a']){
            child = root->children[word[0]-'a'];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[word[0]-'a'] = child;
        }
        insertUtil(word.substr(1),child);
    }
    bool searchUtil(string word, TrieNode* root){
        if(word.size() == 0){
            return root->terminal;
        }
        TrieNode* child;
        if(root->children[word[0]-'a']){
            child = root->children[word[0]-'a'];
        }
        else{
            return false;
        }
        return searchUtil(word.substr(1),child); 
    }
    void removeUtil(string word, TrieNode* root){
        if(word.size() == 0){
            root->terminal = false;
            if(isEmpty(root)){
                delete(root);
            }
        }
        TrieNode* child;
        if(root->children[word[0]-'a']){
            child = root->children[word[0]-'a'];
        }
        else{
            return;
        }
        removeUtil(word.substr(1),child);
    }
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string word){
        insertUtil(word,root);
    }
    bool search(string word){
        return searchUtil(word,root);
    }
    void remove(string word){
        removeUtil(word,root);
    }
};

int main(){
    Trie *t = new Trie();
    t->insert("abcd");
    t->insert("word");
    cout<<t->search("abcd")<<endl;
    t->remove("word");
    cout<<t->search("word");
    return 0;
}
// if we are told to create a dictionary (insert, search, delete) the datastructure to do it efficiently that comes in our mind is hash_map
// as (insert: O(1), search:O(1), delete:O(1)) but this is only the average case in worst case it can go to O(l), l = length of the word
// in trie (insert: O(l), search:O(l), delete:O(l)) but space is optimized in trie

// eg: ARM, ARMILO, ARE, ARENA, ARDENO --> 5 DIFFERENT ENTIRES IN DICTIONARY, but not in trie
// trie = optimal space utilization
//        can give suggestions what words can exist

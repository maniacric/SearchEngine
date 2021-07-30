#include <bits/stdc++.h>
using namespace std;


class TrieNode{
    public:
        char data;
        TrieNode ** children;
        bool isTerminal;
        TrieNode(char data){
            this->data= data;
            children = new TrieNode*[26];
            for(int i=0;i<26;i++)
                children[i]=NULL;
            isTerminal = false;
        }

};


class Trie{

    TrieNode * root = new TrieNode('\0');
    
    void insertWord(string s,TrieNode *root){
        if(s.size()==0){
            root->isTerminal = true;
            return ;
        }
        int ix = s[0]-'a';
        TrieNode * child;
        if(root->children[ix]!=NULL)
            child = root->children[ix];
        else {
            child = new TrieNode(s[0]);
            root->children[ix]=child;
        }
        insertWord(s.substr(1),child);

    }

     
    bool search(string val,TrieNode *root){
        if(root==NULL)
            return false;
        if(val.size()==1 ){
            if(root->isTerminal)
            	return true;
            return false;
        }
        int ix = val[1]-'a';
        return search(val.substr(1),root->children[ix]);
    }

   
    public:

    void insertWord(string s){
        insertWord(s,root);
    }

    bool search(string val){
        if(val.size()==0)
            return true;
        if(root == NULL)
            return false;
        int ix = val[0]-'a';
        return search(val,root->children[ix]);
    }

};


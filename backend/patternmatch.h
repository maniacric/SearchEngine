#include <iostream>
#include <string>
#include <vector>


using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }
    
    bool search(string s,TrieNode * root){
        if(root==NULL)
            return false;
        if(s.size()==1){
            return true;
        }
        int ix = s[1]-'a';
        return search(s.substr(1),root->children[ix]);
    }
    
 
    
    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    bool search(string s){
        if(s.size()==0)
            return true;
    	int ix = s[0]-'a';
        //cout << ix << endl;
        return search(s,root->children[ix]);
    }
    
    bool patternMatching(vector<string> vect, string pattern) {
        // Write your code here
        for(int i=0;i<vect.size();i++){
            string s = vect[i];
            for(int j=0;j<s.size();j++)
                insertWord(s.substr(j));
        }
        return search(pattern);
        
    }
};


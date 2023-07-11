#include <iostream>
using namespace std;
#include "TrieNode.h"

class Trie { 
    TrieNode *root = nullptr;
    int num_of_words;
    
    public:     
        Trie(); 
        ~Trie();
        bool insert(string word); 
        bool search(string word); 
        void erase(string word);
        bool empty() const; 
        bool check_for_children(string word);
        void print_word(); 
        void print(TrieNode *node, string print_word, int num_of_letters); 
        void clear(); 
        void spellcheck(string word); 
        int size() const; 
};
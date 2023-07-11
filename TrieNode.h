#include <iostream>
using namespace std;

class TrieNode { 

    bool endofword;
    TrieNode *children[26];
    char letter; 
    int word; 
    

    public:
        TrieNode(); 
        ~TrieNode(); 

        void set_endofword(bool value); 
        bool get_endofword() const; 

        void set_letter(char value); 
        char get_letter() const; 

        void increase_word(); 
        void decrease_word();
        int get_word() const; 

        void set_node(int i); 
        TrieNode *get_node(int i) const;

        void set_nullptr(int i); 

};
#include <iostream>
using namespace std;
#include "TrieNode.h"

TrieNode::TrieNode() { 
    endofword = false; 
    word = 0; 
    letter = '\0';
    for (int i = 0; i < 26; i++) { 
        children[i] = nullptr;
    }
}

TrieNode::~TrieNode() { 
    for (int i = 0; i < 26; i++) { 
        if (children[i] != nullptr) { 
            delete children[i];
        }
        
    }
}

void TrieNode::set_node(int i) { 
    children[i] = new TrieNode();
}
void TrieNode::set_nullptr(int i) { 
    children[i] = nullptr;
    
}

TrieNode* TrieNode::get_node(int i) const{ 
    return children[i];
}

void TrieNode::set_endofword(bool value) { 
    endofword = value;
}

bool TrieNode::get_endofword() const{ 
    return endofword; 
}

void TrieNode::set_letter(char value) {
    letter = value;
}

char TrieNode::get_letter() const { 
    return letter;
}

void TrieNode::increase_word() { 
    word++;
}
void TrieNode::decrease_word() { 
    word--;
}

int TrieNode::get_word() const { 
    return word; 
}

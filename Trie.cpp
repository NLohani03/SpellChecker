#include <iostream>
using namespace std;
#include "Trie.h"

Trie::Trie() { 
    num_of_words = 0; 
    root = new TrieNode(); 
}

Trie::~Trie(){ 
    delete root;
    root = nullptr;
}

bool Trie::insert(string word) { 
    if (word.length() == 0) { 
        return false;
    }
    else if (search(word)) { 
        return false;
    }

    TrieNode *newNode = root; 
    int i = 0;
    for (i = 0; i < word.length(); i++) { 
         if (newNode->get_node(word[i] - 'a') == nullptr ) { 
            //create a new node if no word exists
            newNode->set_node(word[i] - 'a'); 
            newNode->get_node(word[i] - 'a')->set_letter(word[i]);
        } 
        newNode->get_node(word[i] - 'a')->increase_word(); 
        newNode = newNode->get_node(word[i] - 'a');
    }
    newNode->set_endofword(true); 
    num_of_words++; 
    return true;
}

bool Trie::search(string word) { 
    if (word.length() == 0) { 
        return false;
    }
    else if (empty()) { 
        return false;
    }

    TrieNode *newNode = root;
    for (int i = 0; i < word.length(); i++) { 
        if (newNode->get_node(word[i] - 'a') == nullptr) { 
            return false;
        }
        //go to the next node
        newNode = newNode->get_node(word[i] - 'a');
    }
    if (newNode->get_endofword()) { 
            return true;
    } else { 
            return false;
    }
    return false;
}

void Trie::erase(string word) { 
    if (word.length() == 0) { 
        cout << "failure" << endl;
        return;
    }
    else if (empty()) { 
        cout << "failure" << endl;
        return;
    } else if (!search(word)) { 
        cout << "failure" << endl;
        return;
    }
    
    if(check_for_children(word)) { 
        // there are children at the end of this word
        // deletion is done by removing endofword 
    } else { 
        //if there are no children and there is only one word in that link
        TrieNode *newNode = root;
        for(int i= 0; i < word.length(); i++) {
             if (newNode->get_node(word[i] - 'a')->get_word() == 1) { 
                delete newNode->get_node(word[i] - 'a');
                newNode->set_nullptr(word[i] - 'a');
                num_of_words--;
                cout << "success" << endl;
                return;
            } else { 
                newNode->get_node(word[i] - 'a')->decrease_word(); 
                newNode = newNode->get_node(word[i] - 'a');

            }
        }
        num_of_words--;
    }
}

bool Trie::empty() const { 
    for (int i = 0; i < 26; i++) { 
        if (root->get_node(i) != nullptr) { 
            return false;
        }
        
    }
    return true;
}


bool Trie::check_for_children(string word) { 
    TrieNode *newNode = root; 
    for (int i = 0; i < word.length(); i++) { 
        //go to the next node
        newNode = newNode->get_node(word[i] - 'a');
    }
    for (int i = 0; i < 26; i++) { 
        if (newNode->get_node(i) != nullptr) { 
            newNode->set_endofword(false);
            num_of_words--;
            cout << "success" << endl;
            return true;
        } else {
            
        }
    }
    return false;
}

void Trie::print_word() { 
    if (empty()) { 
        return;
    }
    TrieNode *temp = root;
    string print_word = "";
    int num_of_letters = 0;
    for(int i=0; i < 26; i++) { 
        if (temp->get_node(i) != nullptr) { 
            print(temp->get_node(i), print_word, num_of_letters); 
        }
    }
    cout << endl;
    return;
}

void Trie::print(TrieNode *node, string print_word, int num_of_letters) { 
    if (node->get_letter() != '\0') { 
        num_of_letters++; 
        print_word.push_back(node->get_letter()); 
        //cout << print_word << endl;
    }
    if (node->get_endofword() == true) { 
        cout << print_word;
        cout << " ";
    }
    for (int i = 0; i < 26; i++) { 
        if (node->get_node(i) != nullptr) {
            print(node->get_node(i), print_word, num_of_letters); 
        }
    }
}

int Trie::size() const { 
    return num_of_words;
}

void Trie::clear() { 
    if (empty()) { 
        cout << "success" << endl;
        return;
    }

    TrieNode *temp = root;
    for(int i=0; i < 26; i++) { 
        if (temp->get_node(i) != nullptr) { 
            delete temp->get_node(i); 
            temp->set_nullptr(i); 

        }
    }
    num_of_words = 0;
    cout << "success" << endl;
}
 
void Trie::spellcheck(string word) { 
    if (empty()) { 
        return;
    } else if (word.length() == 0) {
        return;
    }
    else if (search(word)) { 
        cout << "correct" << endl;
        return;
    }
    string prefix; 
    TrieNode *newNode = root;
    int num_of_letters = 0;
    for (int i = 0; i < word.length(); i++) { 
        if (newNode->get_node(word[i] - 'a') != nullptr) { 
            newNode = newNode->get_node(word[i] - 'a'); 
            prefix.push_back(newNode->get_letter()); 
        } else { 
            // cout << prefix << endl;
            if (prefix == "") { 
                cout << endl;
                return;
            }
            print(newNode, prefix.substr(0, prefix.length()-1), num_of_letters);
            cout << endl;
            return;
        }
    }
    print(newNode, prefix.substr(0, prefix.length() -1), num_of_letters);
    cout << endl;
    return; 
    }

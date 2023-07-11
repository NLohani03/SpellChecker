#include "Trie.h"
#include "illegal_exception.h"
#include <fstream>
#include <iostream>
using namespace std; 


int main() { 

    Trie *myTrie;
    myTrie = new Trie();
    string cmd; 
    string addWord; 

    while (cin >> cmd) { 
        if (cmd == "load") { 
            ifstream fin;
            fin.open("corpus.txt"); 
            while (fin >> addWord) { 
                myTrie->insert(addWord); 
            }
            fin.close();
            cout << "success" << endl;

        } else if (cmd == "i") { 
            cin >> addWord;
            try { 
                for (auto ch : addWord) { 
                    if (ch < 'a' && ch < 'z') { 
                        throw illegal_exception();
                    }
                }
                if (myTrie->insert(addWord)) { 
                    cout << "success" << endl;
                } else { 
                    cout << "failure" << endl;
                }
            } 
            catch (illegal_exception word){ 
            }
            
        } else if (cmd == "s") { 
            cin >> addWord; 
            try { 
                for (auto ch : addWord) { 
                    if (ch < 'a' && ch < 'z') { 
                        throw illegal_exception();
                    }
                }
                if (myTrie->search(addWord)) { 
                cout << "found " << addWord << endl;
                } else { 
                    cout << "not found" << endl;
                }
            } 

            catch (illegal_exception word){ 
            }

        } else if (cmd == "e") { 
            cin >> addWord;
            try { 
                for (auto ch : addWord) { 
                    if (ch < 'a' && ch < 'z') { 
                        throw illegal_exception();
                    }
                }
                myTrie->erase(addWord);
            } 
            catch (illegal_exception word){ 
            }
           
        } else if (cmd == "p") { 
            myTrie->print_word();

        } else if (cmd == "spellcheck") { 
            cin >> addWord; 
            myTrie->spellcheck(addWord);

        } else if (cmd == "empty") { 
            if (myTrie->empty()) { 
                cout << "empty 1" << endl;
            } else { 
                cout << "empty 0" << endl;
            }
        } else if (cmd == "clear") { 
            myTrie->clear();

        } else if (cmd == "size") { 
            cout << "number of words is: " << myTrie->size() << endl;

        } else if (cmd == "exit") { 
            break;
        }
    }
    delete myTrie;
    return 0; 
}

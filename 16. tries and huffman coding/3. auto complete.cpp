// tries 
// auto complete

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    
    vector<string> ans;
    
    void helper(TrieNode *root, string a){
        for(int i = 0; i < 26; i++) {
            if(root -> children[i]) {
                char x = root -> children[i] -> data;                
                if(root -> children[i] -> isTerminal) 
                    ans.push_back(a + x);                
                helper(root -> children[i], a + x);
            }
        }
    }
        
    void fill(TrieNode *root, string pattern) {
        if(pattern.size() == 0){
    		if(root -> isTerminal)
                ans.push_back("");
            helper(root, "");
            return;
        }
        int index = pattern[0] - 'a';        
        if(root -> children[index] == NULL)
            return;        
        fill(root -> children[index], pattern.substr(1));
    }
    
    void autoComplete(vector<string> input, string pattern) {
        for(int i = 0; i < input.size(); i++){            
            insertWord(input[i]);
        }        
        fill(root, pattern);        
        for(int i = 0; i < ans.size(); i++) {
            cout << pattern + ans[i] << endl;
        }
    }
    
};

int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}
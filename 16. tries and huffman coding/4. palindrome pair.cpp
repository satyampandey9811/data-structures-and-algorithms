// tries
// palindrome pair

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
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
			root->childCount++;
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

    bool search(TrieNode *root, string word) {
        if(word.size() == 0) {
            return root -> isTerminal;
        }
        int index = word[0] - 'a';
        if(root -> children[index] == NULL)
            return 0;
        return search(root -> children[index], word.substr(1));
    }
    
	bool findIfPalindromePair(vector<string> a) {
		for(int i = 0; i < a.size(); i++) {
            insertWord(a[i]);
        }
        string b, c;
        bool ans;
        for(int i = 0; i < a.size(); i++) {
            b = a[i];
            reverse(b.begin(), b.end());
            c = b.substr(1);
            ans = search(root, b);
            if(ans) return 1;
            ans = search(root, c);
            if(ans) return 1;
        }
        return 0;
	}
};

int main() {
    Trie t;
    vector <string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    
    bool ans = t.findIfPalindromePair(vect);
    if (ans){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}
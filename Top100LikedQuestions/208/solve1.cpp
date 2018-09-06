//Implement a trie with insert, search, and startsWith methods.
//
//Example:
//
//Trie trie = new Trie();
//
//trie.insert("apple");
//trie.search("apple");   // returns true
//trie.search("app");     // returns false
//trie.startsWith("app"); // returns true
//trie.insert("app");   
//trie.search("app");     // returns true
//Note:
//
//You may assume that all inputs are consist of lowercase letters a-z.
//All inputs are guaranteed to be non-empty strings.


class TrieNode {
public:
    bool isEnd;
    TrieNode* sons[26];
    TrieNode() {
        memset(sons, 0, sizeof(sons));
        isEnd = false;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
	~Trie() {
		clear(root);
	}

	void clear(TrieNode *root) {
		for (int i = 0; i < 26; i++) {
			if (root->sons[i] != nullptr) {
				clear(root->sons[i]);
			}
		}
		delete root;
	}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (auto ch:word) {
            if (node->sons[ch-'a'] == nullptr) {
                node->sons[ch-'a'] = new TrieNode();
            }
            node = node->sons[ch-'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (int i=0; i<word.length(); i++) {
            char ch = word[i];
            if (node->sons[ch-'a'] == nullptr) 
                return false;
            node = node->sons[ch-'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (auto ch:prefix) {
            if (node->sons[ch-'a'] == nullptr) 
                return false;
            node = node->sons[ch-'a'];
        }
        return true;        
    }
    TrieNode* root;
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

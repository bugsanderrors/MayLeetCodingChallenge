/*
    Implement Trie (Prefix Tree)

    Implement a trie with insert, search, and startsWith methods.

    Example:

    Trie trie = new Trie();

    trie.insert("apple");
    trie.search("apple");   // returns true
    trie.search("app");     // returns false
    trie.startsWith("app"); // returns true
    trie.insert("app");   
    trie.search("app");     // returns true

    Note:
        * You may assume that all inputs are consist of lowercase letters a-z.
        * All inputs are guaranteed to be non-empty strings.
*/

const int ALPHABET_SIZE = 26;
class TrieNode {
public:
    TrieNode() {
        for (int i=0;i<ALPHABET_SIZE;i++){
            children[i] = NULL;
        }
    }
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord = false;
};

class Trie {
private:
    struct TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *pCrawl = root; 
  
        for (int i = 0; i < word.length(); i++) 
        { 
            int index = word[i] - 'a'; 
            if (!pCrawl->children[index]) 
                pCrawl->children[index] = new TrieNode(); 

            pCrawl = pCrawl->children[index]; 
        } 

        pCrawl->isEndOfWord = true; 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *pCrawl = root;

        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return (pCrawl != NULL && pCrawl->isEndOfWord);
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *pCrawl = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            int index = prefix[i] - 'a';
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return (pCrawl != NULL);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
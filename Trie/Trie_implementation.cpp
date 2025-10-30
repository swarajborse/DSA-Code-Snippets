class Trie{
    private:
    Trie* links[26];
        bool flag;
    public:

    Trie(){
        for(int i = 0; i < 26; i++){
            links[i] = nullptr;
        }
        flag = false;
    }

    bool ContainsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    Trie* get_next(char ch){
        return links[ch - 'a'];
    }

    void put_char(char ch, Trie* t){
        links[ch - 'a'] = t;
    }
    
    void setEnd(){
      flag = true;
    }

    void insert(string word) {
        Trie* ptr = this;
        for(int i = 0; i < word.length(); i++){
            if(!ptr->ContainsKey(word[i])){
                ptr->put_char(word[i], new Trie());
            }
            ptr = ptr->get_next(word[i]);
        }
        ptr->setEnd();
    }
    
    bool isEnd(){
        return flag;
    }

    bool search(string word) {
        Trie* ptr = this;

        for(int i = 0; i < word.length(); i++){
            if(!ptr->ContainsKey(word[i])){
                return false;
            }
           ptr = ptr->get_next(word[i]);
        }
        return ptr->isEnd();
    }


    bool startsWith(string word) {
        Trie* ptr = this;

        for(int i = 0; i < word.length(); i++){
            if(!ptr->ContainsKey(word[i]))return false;
            ptr = ptr->get_next(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
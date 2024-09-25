class Node{
    private:
    Node* links[26];
    bool flag=false;
    public:
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    void put(char c,Node* node){
        links[c-'a']=node;
    }
    Node* getNext(char c){
        return links[c-'a'];
    }
    void setFlag(){
        flag=true;
    }
    bool getFlag(){
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->getNext(word[i]);
        }
        node->setFlag();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])) return false;
            node=node->getNext(word[i]);
        }
        
        return node->getFlag();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])) return false;
            node=node->getNext(prefix[i]);
        }
        return true;
    }
};

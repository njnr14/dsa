#include <bits/stdc++.h> 

struct Node{
        Node* link[26];
        int cntEndWith=0;
        int cntPrefix = 0;


        bool containsKey(char ch){
            return (link[ch-'a']!=NULL);
        }

        Node* get(char ch){
            return link[ch-'a'];
        }

        void put(char ch , Node* node){
            link[ch-'a'] = node;
            return;
        }

        void increaseEnd(){
            cntEndWith++;
        }
        void increasePrefix(){
            cntPrefix++;
        }
        void deleteEnd(){
            cntEndWith--;
        }
        void reducePrefix(){
            cntPrefix--;
        }

};

class Trie{

    private:
     Node* root;

    public:


    Trie(){
        // Write your code here.
        root= new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;

        for(int i =0 ; i< word.size() ;i++){
            if(!node->containsKey(word[i])){
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }

        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.Node* node = root;
        Node* node = root;

        for(int i =0 ; i< word.size() ;i++){
            if(!node->containsKey(word[i])){
                return 0 ;
            }
            node = node->get(word[i]);
            
        }

        return node->cntEndWith;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node =root;
        for(int i =0 ; i< word.size() ;i++){
            if(!node->containsKey(word[i])){
                return 0 ;
            }
            node = node->get(word[i]);
            
        }

        return node->cntPrefix;
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;

        for(int i =0 ; i< word.size() ;i++){
            
            node = node->get(word[i]);
            node->reducePrefix();
            
        }

        node->deleteEnd();
    }
};

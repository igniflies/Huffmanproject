#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>


using namespace std;
class charnode{
    public:
    charnode* next;
    char ch;
    string bit_size;
    int frequency;

    charnode(char ch,const string & code,int frequency){
        this-> ch=ch;
        this-> bit_size=code;
        this->frequency=frequency;
        this->next=nullptr;

    }
};
class charlinkedlist{
    private:
    charnode* head;
    charnode*tail;
    int size;

    
    
    public:
    charlinkedlist(){
        head=nullptr;
        tail=nullptr;
        size=0;

    }
    bool isempty() const{
        return head== nullptr;
    
    }
    int getSize() const {
        return size;
    }
   


    void add(char ch, const string& code, int frequency) {
        charnode* newest = new charnode(ch, code, frequency);
        if (isEmpty()) {
            head = tail = newest;
        } else {
            tail->next = newest;
            tail = newest;
        }
        size++;
    }

    


    charnode* getCharNode(char ch) const {
        if (isEmpty()) {
            return nullptr;
        }
        charnode* trav = head;
        while (trav != nullptr) {
            if (trav->ch == ch) {
                break;
            }
            trav = trav->next;
        }
        return trav;
    }

    charnode* getLink() const {
        return head;
    }

    ~charlinkedlist() {
        charnode* current = head;
        charnode* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
        
};
class message {
    public:
    static const int char_size=8;
    string text;
    
    message(const string &text){
        this->text=text;

    }
    int getsize() const{
        return text.length()* char_size;

    }
};
class node{
    public:
    char character;
    int frequency;
    node*left;
    node*right;

    
    node(char character,
    int frequency,
    node*left=nullptr,
    node*right=nullptr){
        if (frequency<0){
            throw invalid_argument("error :frequency must be >=0");

        }
        this->character=character;
        this->frequency=frequency;
        this->left= left;
        this->right=right;


        }
        bool isleaf() const{
            return left== nullptr && right==nullptr;
        }
};
class huffmanencoder{
    private:
    string text;
    message msgobject;
    huffmantree huffmantree;
    charlinkedlist charset;
    bool hasbeencompressed;

    public:
    huffmanencoder(const string&text){
        msgobject=text;
        text= (msgobject.getmessage());
        huffmantree= msgobject;
        hasbeencompressed=false;


    }
    huffmanencoder(const message & msg){
        msgobject=msg;
        text=msg.getmessage();
        huffmantree=msg;
        hasbeencompressed=false;

    }
    void compress(){
        lookup(huffmantree.getroot(),"");
        hasbeencompressed=true;

    }
    void lookup(node* node,const string&s){
        if(!node->isleaf()){
            lookup(node->left,s+"0");
            lookup(node->right,s+"1");

        }
        else{
            charset.add(node->character,s,node->frequency);

        }
    }
    double howmuchcompressed() const{
        if(!hasbencompressed){
            throw runtime_error(" error: message has not been compressed");

        }
        return ((msgobject.getsize()-getsizeofsequence()))/static_cast<double>(msgobject.getsize())*100;

    }
    charlinkedlist get_charset() const{
        return charset;

    }
    vector<string> compressbinarycode() const{
        if (!hasbeencompressed){
            throw runtime_error(" error: message has not been compressed");

        }
        vector<string> d(text.length());
        for(size_t i=0;i< text.length();i++){
            d[i]=charset.getcharnode(text[i])->bit_size;


        }
        return d;

    }
    void indivsequence() const{
        if(!hasbeencompressed){
            throw runtime_error(" error: message has not been compressed");


        }
        charnode* trav=charset.getlink();
        while(trav!=nullptr){
            cout<< trav->ch<<" :" << trav->bit_size()<<endl;
            trav=trav->next;

        }

    }
    int getsizeofsequence() const{
        if (!hasbeencompressed){
            throw runtime_error(" error: message has not been compressed");
        }
        int totalsize=0;
        int bits=0;
        charnode*n=charset.getlink();
        while(n!=nullptr){
            totalsize+= n->frequency* n->bit_size.length();
            bits+=n->bit_size.length();
            n=n->next;
      
        }
        totalsize+=(message:: char_size* charset.getsize()+bits);
        return totalsize;


    }
    

};
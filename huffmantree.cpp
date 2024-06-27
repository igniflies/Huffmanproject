#include<iostream>
#include<stdexcept>
#include<queue>
#include<vector>
using namespace std;
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
        
        this->character=character;
        this->frequency=frequency;
        this->left= left;
        this->right=right;


        }
        bool isleaf() const{
            return left== nullptr && right==nullptr;

    }
};

class message{
    public:
    static const int char_size=8;
    string text;
    message(const string & text){
        this->text=text;
   
    }
    string getmeaage() const{
        return text;

    }
    int getsize() const{
        return text.length()* char_size;

    }
    vector<int> getfrequencies() const{
        vector<int> freqs(256,0);
        for(char ch: text){
            freqs[ch]++;

        }
        return freqs;

    }
    bool isEmpty() const{
        return text.empty();

    }

};
template<typename T>
class minpriorityqueue{
    private:
    vector<T> data;
    void siftup(int index){
        while(index>0){
            int parent=(index-1)/2;
            if (data[index]<data[parent]){
                swap(data[index],data[parent]);
                index=parent;

            }
            else{
                break;

            }
        }
    }
    void siftdown(int index){
        int size=data.soze();
        while(true){
            int left=2*index+1;
            int right=2*index +2;
            int smallest=index;
            if(left<size&& data[left]<data[smallest]){
                smallest=left;

            }
            if (left<size&& data[right]<data[smallest]){
                smallest=right;
            }
            if(smallest!=index){
                swap(data[index],data[smallest]);
                index=smallest;

            }
            else{
                break;

            }
        }
    }
public:
    void add(const T& elem){
        data.push_back(elem);
        siftup(data.size()-1);

    }
    T poll(){
        if(data.empty()){
            throw runtime_error('QUEUE IS EMPTY');
        }
        T result=data[0];
        data[0]=data.back();
        data.pop_back;
        siftdown(0);
        return result;

    }
    int len() const{
        return data.size();

    } 
    bool isEmpty() const{
        retrun data.empty();

    }   
    
};
class huffmantree{
    private:

    node* root;
    message sequence;

    node* buildhuffmantree(){
        minpriorityqueue<node*> priorityqueue=populatepq();
        if(priorityqueue.len()==1){
            priorityqueue.add(new node('\0',1,nullptr,nullptr));


        }
        while(priorityqueue.len()>1){
           
           node*left= priorityqueue.poll();
           node*right=priorityqueue.poll();
           node*parent = new node('\0',left->frequency,right->frequency,left,right):
           priorityqueue.add(parent);

        }
        return priorityqueue.poll();
    
    }
    minpriorityqueue<node*>populatepq(){
        minpriorityqueue<node*>pq;
        vector<int>freqs=sequence.getfrequencies();
        for(char i=0;i<freqs.size();++i){
            if (freqs[i]>0){
                pq.add(new node(i,freqs[i],nullptr,nullptr));

            }
        }
        return pq;

    }
    void inorder(node* node)const{
        if(node== nullptr){
            return;

        }
        inorder(node->left);
        cout<< node->frequency<<" ";
        inorder(node->right);

    }
    void postorder(node* node) const{
        if(node!=nullptr){
            postorder(node->left);
            postorder(node->right);
            cout<< node->frequency<<" ";

        }
    }

    void preorder(node* node)const{
        if(node== nullptr){
            return;

        }
        cout<< node->frequency<<" ";
        preorder(node->left);
        
        preorder(node->right);

    }
    public:
    huffmantree( const message & sequence): sequence (sequence){
        if(sequence.isEmpty()){
            throw runtime_error(" error: sequence of length 0");


        }
        root=buildhuffmantree();

    }
    message getmessage() const{
        return sequence;

    }
    void inorder() const{
        inorder(root);
        cout<< endl;

    }
    void preorder() const{
        inorder(root);
        cout<< endl;

    }
    void postorder() const{
        postorder(root);
        cout<< endl;

    }
    void levelorder() const{
        if(root== nullptr){
            return;

        }
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node* trav =q.front();
            q.pop();
            if (trav!=nullptr){
                cout<< trav-> frequency<<" ";
                q.push(trav->left);
                q.push(trav->right);

            }
        }
        cout<<endl;

    }
    node* getroot() const{
        return root;

    }
    ~huffmantree(){
        // recursively delete nodes
        function<void(node*)>deletetree=[&](node*node){
            if(node!-nullptr){
                deletetree(node->left);
                deletetree(node->right);
                delete node;


            }
        };
        deletetree(root);
        
    }



};

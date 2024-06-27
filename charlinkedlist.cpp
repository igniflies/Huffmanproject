#include<iostream>
#include<string>
using namespace std;
class charnode{
    public:
    char ch;
    string code;
    int frequency;
    charnode* next;
    charnode(char ch,const string & code,int frequency){
        this->ch=ch;
        this->code=code;
        this->frequency=frequency;
        this->next=nullptr;

    }
};
class charlinkedlist{
    private:
    charnode* head;
    charnode* tail;
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
    int getsize() const{
        return size;

    }
    void add(char ch,const string& code,int frequency){
        charnode* newest=new charnode(ch,code ,frequency);
        if(isempty()){
            head=tail=newest;

        }
        else{
            tail->next=newest;
            tail=newest;

        }
        size++;

    }
    charnode* getcharnode(char ch)const{
        if(isempty()){
            return nullptr;

        }
        charnode* trav=head;
        while(trav!=nullptr){
            if(trav->ch==ch){
                break;

            }
            trav=trav->next;

        }
        return trav;

    }
    charnode* getlink()const{
        return head;

    }
    ~charlinkedlist(){
        charnode* current =head;
        charnode* nextnode=nullptr;
        while(current!=nullptr){
            nextnode=current->next;
            delete current;
            current=nextnode;

        }
    }

};
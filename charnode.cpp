#include<iostream>
#include<string>

using namespace std;
class charnode{
    public:
    charnode* next;
    char ch;
    string bit_size;
    int frequency;

    charnode(char ch,const string& code,int frequency){
        this->ch =ch;
        this->bit_size= code;
        this ->frequency=frequency;
        this->next=nullptr;

    }

};
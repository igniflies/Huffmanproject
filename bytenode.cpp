#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;
class bytenode{
    public:
    uint8_t data;
    int frequency;
    bytenode*left;
    bytenode*right;
    
    bytenode(uint8_t data,int weight){
        data=data;
        frequency=weight;
        left=nullptr;
        right=nullptr;

    }
    bool operator<(const bytenode& other)const{
        return this-> frequency< other.frequency;

    }
    int compareto(const bytenode& other)const{
        return this->frequency -other.frequency;
    }


};
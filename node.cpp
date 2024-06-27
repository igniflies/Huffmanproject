#include<iostream>
#include<stdexcept>
#include<string>

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
        bool operator<(const node& that)const{
            if(this->frequency != that.frequency){
                return this->frequency < that.frequency;

            }
            return this-> character<that.character;

        }
        string tostring() const{
            return string(1,character);

        }
   
};

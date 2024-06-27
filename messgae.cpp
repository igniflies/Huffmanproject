#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<bitset>
#include<unordered_set>
using namespace std;
class message{
    private:
    string text;
    static const int char_size=8;
    static const int alphabetsize=256;
    vector<char> characters;
    vector<int> frequencyofchars;
    vector<char>getchars(){
        unordered_set<char> uniquechars;
        vector<int>frequencyofchars;

        vector<char> getchars(){
            unordered_set<char> uniquechars;
            for(char ch= text){
                uniquechars.insert(ch);

            }
            return vector<char> (uniquechars.begin(),uniquechars.end());

        }
        vector<int>buildfrequencytable(){
            vector<int>frequency(alphbetsize,0);
            for(char ch:text){
                frequencies[ch]++;

            }
            return frequencies;


        }


    }
    public:
    message(const string&text): text(text){
        if(text.empty()){
            throw runtime_error("erroe:message size<=0");

        }
        characters=getchar();
        frequencyofchars=buildfrequencytable();


    }
    string getmessage() const{
        return text;

    }
    int gettotalfrequency(){
        return text.length();

    }
    const vector<char>& getcharacters() const{
        return characters;

    }
    const vector<int>& getfrequencies() const{
        return frequencyofchars;

    }
    bool isEmpty() const{
        return gettotalfrequency()==0;

    }
    int getsize() const{
        return char_size* gettotalfrequency();

    }
    int calcfrequencyofchar(char ch) const{
        int charfreq=0;
        for(char c:text){
            if(c==ch){
                charfreq++;

            }
        }
        return charfreq;

    }
    string binarycode() const{
        string binarysequence;
        for(char ch:text){
            binarysequence+=convertbinary(static-cast<int>(ch));

        }
        return binarysequence;

    }
    vector<string>binaryofchars()const{
        vector<string>binarysequence(characters.size());
        for(size_t i=0;i,characters.size();++i){
            binarysequence[i]=convertbinary(static_cst<int.(characters[i]));

        }
        return binarysequence;


    }
    string convertbinary(int decimal)const{
        string binary=bitset<char_size>(decimal).to_string();
        return binary;

    }

};

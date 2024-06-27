#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<queue>
#include<bitset>
#include<sstream>
using namespace std;

struct bytenode{
    unsigned char data;
    int frequency;
    bytenode* left;
    bytenode* right;
    
    bytenode(unsigned char d, int f){
        data=d;
        frequency=f;
        left=nullptr;
        right=nullptr;

    }
    bytenode(int f){
        data=0;
        frequency=f;
        left=nullptr;
        right=nullptr;

    }

};
struct compare{
    bool operator()(bytenode* l, bytenode* r){
        return (l->frequency > r->frequency);

    }
};
class huffmancompression{
    private:
    static string sb;
    static map<unsigned char, string> huffmap;
    
    public:
    static void compress(const string &src,const string & dst){
        try{
            ifstream instream (src,ios::binary);
            vector<unsigned char> b((istreambuf_iterator<char>(instream)),istreambuf_iterator<char>());
            vector<unsigned char> huffmanbytes=createzip(b);
            ofstream outstream(dst,ios::binary);
            outstream.write(reinterpret_cast<char*>(huffmanbytes.data()),huffmanbytes.size());

            instream.close();
            outstream.close();

        } 
        catch(exception& e){
            cerr<< e.what()<<endl;

        }

    }
    static vector<unsigned char> createzip(const vector<unsigned char>& bytes){
        priority_queue<bytenode*,vector<bytenode*>,compare>nodes=getbytenodes(bytes);
        bytenode*root=createhuffmantree(nodes);
        map<unsigned char,string> huffmancodes=gethuffmancodes(root);
        vector<unsigned char> huffmancodebytes= zipbyteswithcodes(bytes,huffmancodes);
        return huffmancodebytes;

    }
    static priority_queue<bytenode*,vector<bytenode*>,compare>getbytenodes(const vector<unsigned char>& bytes){
        priority_queue<bytenode*,vector<bytenode*>,compare>nodes;
        map<unsigned char,int>tempmap;
        for (unsigned char b: bytes){
            tempmap[b]++;
        }
        for (const auto& entry:tempmap){

        

            nodes.push(new bytenode(entry.first,entry.second));

        }
        return nodes;


    }
    static bytenode* createhuffmantree(priority_queue<bytenode*,vector<bytenode*>,compare>& nodes){
        while(nodes.size()>1){
            bytenode* left= nodes.top();
            nodes.pop();
            bytenode*right=nodes.top();
            nodes.pop();
            bytenode* parent =new bytenode(left->frequency+right->frequency);
            parent->left=left;
            parent->right=right;
            nodes.push(parent);


        }
        return nodes.top();

    }
    static map<unsigned char,string> gethuffmancodes(bytenode*root){
        if(!root){
            return map<unsigned char, string>();
             

        }
        gethuffmancodes(root,"",sb);
        return huffmap;


    }
    static void gethuffmancodes(bytenode*root,const string &codes,string&sb1){
        string sb2=sb1+codes;
        if (root){
            if(root->left==nullptr&& root->right==nullptr){
                huffmap[root->data]=sb2;

            }
            else{
                gethuffmancodes(root->left,"0",sb);
                gethuffmancodes(root->right,"1",sb);

            }
        }
    }
    static vector<unsigned char > zipbyteswithcodes(const vector<unsigned char>& bytes,const map<unsigned char,string >& huffcodes){
        stringstream strbuilder;
        for(unsigned char b: bytes){
            strbuilder<< huffcodes.at(b);

        }
        string bitstring=strbuilder.str();
        size_t length =(bitstring.size()+7)/8;
        vector<unsigned char> huffcodebytes(length);
        for(size_t i=0; i< bitstring.size();i+=8){
            string strbyte= bitstring.substr(i,8);
            huffcodebytes[i/8]=bitset<8>(strbyte).to_ulong();

        }
        return huffcodebytes;



    }
    static void decompress(const string & src,const string & dst){
        try{
            ifstream instream (src,ios::binary);
            vector<unsigned char> huffmanbytes((istreambuf_iterator<char>(instream)),istreambuf_iterator<char>());
            map<unsigned char,string> huffmancodes=loadhuffmancodes();
            
            vector<unsigned char> bytes=decomp(huffmancodes,huffmanbytes);
            ofstream outstream(dst,ios::binary);
            outstream.write(reinterpret_cast<char*>(bytes.data()),bytes.size());

            instream.close();
            outstream.close();

        } 
        catch(exception& e){
            cerr<< e.what()<<endl;

        }

    }
    static vector<unsigned char>decomp(const map<unsigned char,string>&huffmancodes,const vector<unsigned char>&huffmanbytes){
        stringstream sb1;
        for(size_t i=0;i<huffmanbytes.size();++i){
            sb1<< convertbytetobit((i!=huffmanbytes.size()-1),huffmanbytes[i]);

        }
        map<string,unsigned char>maprev;
        for(const auto& entry: huffmancodes){
            maprev[entry.second]=entry.first;
        }
        vector<unsigned char>list;
        for(size_t i=0;i<sb1.str().size();){
            int count =1;
            bool flag=true;
            unsigned char b;
            while(flag){
                string key=sb1.str().substr(i,count);
                if(maprev.find(key)== maprev.end()){
                    ++count;

                }
                else{
                    b=maprev[key];
                    flag=false;

                }

            }
            list.push_back(b);
            i+=count;

        }
        return list;

    }
    static string convertbytetobit(bool flag,unsigned char b){
        bitset<8>bits(b);
        if (flag)bits.set(8);
        string str0=bits.to_string();
        return flag|| bits[7]?str0.substr(str0.size()-8):str0;
    }
    static map<unsigned char,string> loadhuffmancodes(){
        return map<unsigned char,string>();
    }
    
};



string huffmancompression:: sb="";
map<unsigned char,string> huffmancompression:: huffmap;
int main(){
    huffmancompression::compress("input.txt","compressed.bin");
    huffmancompression::decompress("compressed.bin","output.txt");
    return 0;
    
}


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
std::vector<std::string> split(const std::string &s, char delim)
{ 
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    } 
    return elems;
} 

struct code_t {
    
    bool current_bit;
    std::string bit_pack;
    std::vector<string> coded;
    
    code_t& operator<<=(bool b) {
        if (current_bit != b) {
            finish_bit_pack();
        }
        current_bit = b;
        bit_pack.push_back('0');
        return *this;
    }
    
    code_t& operator<<=(char c) {
        if (c == 0) { 
            finish_bit_pack(); 
        } else {
            for (int i = 0; i < 7; ++i) {
                *this <<= bool( c & 0x40);
                c <<= 1;
                c &= 0x7f;
            }
        }
        return *this;
    }
    
    void finish_bit_pack() {
        if (bit_pack.length()) {
            if (current_bit == true)
                coded.push_back("0");
            else 
                coded.push_back("00");
            coded.push_back(bit_pack);
        
            bit_pack ="";
        }
    
    }
};

template <class T>
ostream& operator<<(ostream& out, const vector<T> &vec) {
    string separator = "";
    for (auto elem : vec) {
        out << separator << elem ;
        separator = " ";
    }
    return out;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    
    code_t code;
    
    for (auto ch : MESSAGE) {
        code <<= ch;
    }
    code <<= char(0);
    
    cout << code.coded << endl;


}

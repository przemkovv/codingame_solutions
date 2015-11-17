
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


typedef std::string letter_line_t;
struct letter_t {
    std::vector<letter_line_t > data;
    letter_line_t& get_line(const int line) {
        return data[line];
    }
    
    letter_t() : letter_t{0}
    {}
    letter_t(int lines_number) : data{lines_number} 
    {}
};

std::map<char, letter_t> letters;

std::string all_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";

bool isascii(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
std::string get_letter_line(char c, int line) {
    letter_t letter_to_print;
    if (isascii(c))  {
        letter_to_print = letters.at(toupper(c));
    } else {
        letter_to_print = letters.at('?');
    }
    return letter_to_print.get_line(line);
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    
    for (auto ch : all_letters) {
        letters.emplace(std::make_pair(ch, letter_t{H}));
    }
    
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        
        auto chunk_begin = begin(ROW);
        
        for (auto ch : all_letters) {
            copy_n(chunk_begin, L, std::back_inserter(letters.at(ch).get_line(i)));
            advance(chunk_begin, L);
        }
    }
    
    for (int i = 0; i < H; i++) {
        for (auto ch : T) {
            cout << get_letter_line(ch, i);
        }
        cout << endl;
    
    }

}

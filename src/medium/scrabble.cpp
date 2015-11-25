#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct word_points_t {
    string word;
    int points;
};


ostream& operator<<(ostream& out, word_points_t wp) {
    return out << "("<< wp.word << ": " << wp.points << ")";
}
template <class T>
ostream& operator<<(ostream& out, vector<T> C) {
    out << "[";
    string separator ="";
    for (auto x : C) {
        out << separator << x << endl;
        separator = " ";
    }
    return out << "]";
}


int letter_to_points(char c) {
    switch (c){
        case 'e': case 'a': case 'i': case 'o': case 'n':
        case 'r': case 't': case 'l': case 's': case 'u':
            return 1;
        case 'd': case 'g': 
            return 2;
        case 'b': case 'c': case 'm': case 'p':
            return 3;
        case 'f': case 'h': case 'v': case 'w': 
        case 'y':
            return 4;
        case 'k':
            return 5;
        case 'j': case 'x':
            return 8;
        case 'q': case 'z':
            return 10;
    }
    return 0;
}

int score_the_word(string word) {
    return accumulate(begin(word), end(word), 0, [](int score, char c) { 
        return score + letter_to_points(c);
    });
}

bool can_compose(word_points_t word, string letters) {
    
    sort(begin(word.word), end(word.word));
    
    auto it = begin(letters);
    for (auto c : word.word) {
        bool check_next = true;
        while(check_next) {
            if (c == *it) {
                it++;
                check_next = false;
            } else if (c < *it) {
                return false;
            } else {
                if (it == end(letters))
                    return false;
                check_next = true;
                it++;
            }
        }
    }
    return true;
    

}


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<word_points_t> words;
    for (int i = 0; i < N; i++) {
        string W;
        getline(cin, W);
        words.push_back({W, score_the_word(W)});
    }
    
    stable_sort(begin(words), end(words), [](word_points_t wp1, word_points_t wp2){
        return wp1.points > wp2.points; 
    });
    
    cerr << words << endl;
    string LETTERS;
    getline(cin, LETTERS);
    
    sort(begin(LETTERS), end(LETTERS));
    cerr << LETTERS << endl;
    
    for (auto word : words) {
        if (can_compose(word, LETTERS)) {
            cout << word.word << endl;
            break;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& out, vector<int> C) {
    string sep = "";
    for (auto x : C) {
        out << sep << x;
        sep = " ";
    }
    return out;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 vector<int> compress(vector<int> sequence) {
     vector<int> next_sequence;
    auto it = begin(sequence);
    {
        int count = 1;
        int number = *it;
        ++it;
        for (; it != end(sequence); ++it) {
            if (number == *it) {
                count++;
            } else {
                next_sequence.push_back(count);
                next_sequence.push_back(number);
                count = 1;
                number = *it;
            }
        }
        next_sequence.push_back(count);
        next_sequence.push_back(number);
        count = 0;
        number = *it;
        
    }
    return next_sequence;
 }
 
 
 
int main()
{
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    vector<int> sequence, next_sequence;
    sequence.push_back(R);
    
    for (int i=1; i< L; ++i) {
        //cerr << i << ": " << sequence << endl;
        sequence = compress(sequence);
    }
    
    cout << sequence << endl;
}

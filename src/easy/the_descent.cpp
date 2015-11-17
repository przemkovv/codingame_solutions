#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    // game loop
    while (1) {
        int SX;
        int SY;
        vector<int> heights;
        cin >> SX >> SY; cin.ignore();
        for (int i = 0; i < 8; i++) {
            int MH; // represents the height of one mountain, from 9 to 0. Mountain heights are provided from left to right.
            cin >> MH; cin.ignore();
            heights.push_back(MH);
        }
        
        auto it_highest = std::max_element(heights.begin(), heights.end());
        cerr << it_highest - heights.begin() << " " << SX << endl;
        if (SX == (it_highest - heights.begin())  ) {
            cout << "FIRE" << endl;
        } else  {
            cout << "HOLD" << endl;
        }
    }
}

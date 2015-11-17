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
    int N; // the number of temperatures to analyse
    cin >> N; cin.ignore();
    int closest = 0;
    int temperature;
    if (N) {
        
        cin >> closest;
        for (int i = 1; i < N; ++i) {
            cin >> temperature;
            if (std::abs(temperature) < std::abs(closest)) {
                closest = temperature;
            } else if (std::abs(temperature) == std::abs(closest)) {
                closest = temperature > 0 ? temperature : closest;
            }
            
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << closest<< endl;
}

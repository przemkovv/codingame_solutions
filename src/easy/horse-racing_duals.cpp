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
    int N;
    vector<int> strengths;
    cin >> N; cin.ignore();
    strengths.reserve(N);
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        strengths.push_back(Pi);
    }
    sort(strengths.begin(), strengths.end());
    vector<int> differences;
    differences.reserve(N-1);
    adjacent_difference(strengths.begin(), strengths.end(), back_inserter(differences),
            [](int x, int y){ return abs(x-y); });
    
    cout << *min_element(differences.begin(), differences.end()) << endl;
    

}

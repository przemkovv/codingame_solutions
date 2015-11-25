#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

 struct coords_t {
     long long x;
     long long y;
 };

ostream& operator<<(ostream& out, coords_t c) {
    return out << "(" << c.x << ", " << c.y << ")";
}

template <class T>
ostream& operator<<(ostream& out, vector<T> C) {
    out << "[";
    string separator ="";
    for (auto x : C) {
        out << separator << x;
        separator = " ";
    }
    return out << "]";
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 
 
int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<coords_t> buildings;
    buildings.reserve(N);
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        buildings.push_back({X, Y});
    }

    sort(begin(buildings), end(buildings), [](coords_t b1, coords_t b2){return b1.y < b2.y; });
    
    cerr << buildings << endl;
    long long middle_y;
    if (N % 2 ) {
        middle_y = buildings[N/2].y;
    } else {
        middle_y = (buildings[N/2-1].y + buildings[N/2].y)/2;
    }
    cerr << middle_y << endl;
    cerr << buildings << endl;
    
    auto minmax = minmax_element(begin(buildings), end(buildings), [](coords_t b1, coords_t b2) {
        return b1.x < b2.x;
    });
    
    auto dist_x_y= [](long long x, long long y) {
        return x > y ? x - y : y - x;
    };
    
    auto length = accumulate(begin(buildings), end(buildings), 0ll, [=](long long distance, coords_t coords){
        return distance + dist_x_y(coords.y, middle_y);
    });
    
    cerr << "L: "<< length << endl;
    cerr << "Min: " << *minmax.first<< " Max: " << *minmax.second<< endl;
    auto length_x = dist_x_y(minmax.second->x, minmax.first->x);
    
    cerr << "Lx: "<< length_x << endl;
    cerr << "L: "<< length << endl;
    length += length_x;
    cerr << "La: "<< length << endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << length << endl;
}

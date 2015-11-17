#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
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

double to_double(string number) {
    replace(number.begin(), number.end(), ',' , '.');
    return stod(number);
}


struct longlat_t {
    double longtitude;
    double latitude;
};

double distance(longlat_t p1, longlat_t p2) {
    double x = (p2.longtitude-p1.longtitude ) * cos((p1.latitude + p2.latitude)/2.0);
    double y = p2.latitude - p1.latitude;
    const int K = 6371;
    return sqrt(x*x + y*y) * K;
}

struct defib_t {
    int id;
    string name;
    string address;
    string phone;
    longlat_t position;
    
    defib_t() {}
    defib_t(string line) {
        auto data = split(line, ';');
        id = stoi(data[0]);
        name = data[1];
        address = data[2];
        phone = data[3];
        position = longlat_t{to_double(data[4]), to_double(data[5])};
    
    }
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    longlat_t user_position{to_double(LON), to_double(LAT)};
    
    int N;
    cin >> N; cin.ignore();
    defib_t closest_defib;
    double closest_distance = numeric_limits<double>::max();;
    
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        
        defib_t defib{DEFIB};
        auto defib_distance = distance(user_position, defib.position);
        if (closest_distance > defib_distance) {
            closest_distance = defib_distance;
            closest_defib = defib;
        }
    }
    
    cout << closest_defib.name << endl;

}

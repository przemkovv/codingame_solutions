#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int vSpeedThreshold = 40;
const int hSpeedThreshold = 20;


struct coords_t {
    int x;
    int y;
};

struct lander_t {
    coords_t position;
    int hSpeed; // the horizontal speed (in m/s), can be negative.
    int vSpeed; // the vertical speed (in m/s), can be negative.
    int fuel; // the quantity of remaining fuel in liters.
    int rotate; // the rotation angle in degrees (-90 to 90).
    int power; // the thrust power (0 to 4).
};

template <typename T> 
int sgn(T val) { return (T(0) < val) - (val < T(0)); }

std::ostream& operator<<(std::ostream& out, const coords_t& c) {
    return out << "(X: " << c.x << " Y: " << c.y << ") ";
}

std::istream& operator>>(std::istream& in, lander_t& lander) {
    return in >> lander.position.x >> lander.position.y
        >> lander.hSpeed >> lander.vSpeed
        >> lander.fuel >> lander.rotate
        >> lander.power;
}

std::vector<coords_t> surface;

void position_above_landing_zone() ;
void reduce_horizontal_speed() ;
void land() ;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();
    surface.reserve(surfaceN);

    for (int i = 0; i < surfaceN; i++) {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> landX >> landY; cin.ignore();

        surface.push_back(coords_t{landX, landY});
    }





    position_above_landing_zone();
    reduce_horizontal_speed();
    land();


}

void position_above_landing_zone() {

    auto flat_ground_it = std::adjacent_find(surface.begin(), surface.end(),
            [](const coords_t &c1, const coords_t &c2) { return c1.y == c2.y; });

    auto &flat_ground_start = *flat_ground_it;
    auto &flat_ground_stop = *(flat_ground_it+1);

    cerr << "Flat ground: " << flat_ground_start << flat_ground_stop << endl;
    int flat_ground_center_x = (flat_ground_start.x + flat_ground_stop.x) / 2;
    int flat_ground_width = flat_ground_stop.x - flat_ground_start.x;

    cerr << "Center: " << flat_ground_center_x << " Width: " << flat_ground_width << endl;



    lander_t lander;
    double power;
    int rotate;
    const int close_distance  = 750;

    do {
        cin >> lander;
        cin.ignore();
        int landing_zone_x = flat_ground_center_x - 0.5 * flat_ground_width;
        int distance = landing_zone_x - lander.position.x;
        int distance_abs = std::abs(distance);
        cerr << "Distance: " << distance << endl;

        if (landing_zone_x < lander.position.x) {
            cerr <<"Turning left" << endl;
            rotate=20 ;
        } else if (landing_zone_x > lander.position.x) {
            cerr <<"Turning right" << endl;
            rotate=-20;
        } else {
            rotate = 0;
        }
        if (distance_abs < 1000) {
            rotate *=  distance_abs/1000.0;
        }
        if (distance_abs < 1000 && lander.hSpeed < hSpeedThreshold) {
            rotate = -lander.rotate *  distance_abs/1000.0;
        }
        if (sgn(distance) == -sgn(lander.hSpeed) && lander.hSpeed > hSpeedThreshold) {
            rotate *= lander.hSpeed/hSpeedThreshold * 3.0 / 2.0;
        }


        if (std::abs(distance) < close_distance) {
            power = 4;
        }

        if (lander.vSpeed > -5) {
            power = 0;
        } else {
            power = 4;
        }
        //power = std::abs(distance)/1000.0 * 4.0;
        cerr << "Power Distance: " << power << endl;
        if (sgn(distance) == -sgn(lander.hSpeed) && std::abs(lander.hSpeed) > hSpeedThreshold) {
            power = 4;
            cerr << "Power hSpeed: " << power << endl;
        }

        cout << rotate << " " << int(power>4?4:power) << endl;

    } while( std::abs(lander.hSpeed) > hSpeedThreshold/8
            || lander.position.x < flat_ground_start.x
            || lander.position.x > flat_ground_stop.x);

    cerr << "Finished positioning" << endl;
}

void reduce_horizontal_speed() {

}

template <class T>
T clip(const T& value, T left, T right) {
    if (value > right) return right;
    if (value < left) return left;
    return value;
}

void land() {
    lander_t lander;
    double power;
    int rotate;

    do {
        cin >> lander;
        cin.ignore();

        rotate = 0;-lander.rotate * lander.hSpeed;
        if (lander.vSpeed < -35) {
            power = 4;
        } else {
            power = 2;
        }

        cout << clip(rotate, -90, 90) << " " << clip(int(power), 0, 4) << endl;

    } while(1);
}

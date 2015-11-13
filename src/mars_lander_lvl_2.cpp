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

template <class T>
T clip(const T& value, T left, T right) {
    if (value > right) return right;
    if (value < left) return left;
    return value;
}

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

void braking();
void position_above_landing_zone() ;
void reduce_horizontal_speed() ;
void land() ;
void output(int rotate, int power);

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





    //braking();
    position_above_landing_zone();
    reduce_horizontal_speed();
    land();


}

void braking() {
    lander_t lander;
    double power;
    int rotate;
    const int close_distance  = 750;

    do {
        cin >> lander;
        cin.ignore();
        power  =4;

        int speed = std::abs(lander.hSpeed);

        if ( speed > hSpeedThreshold *3) {
            rotate = 20 * lander.hSpeed/hSpeedThreshold;
            cerr << "H 4" << endl;
        } else if ( speed > hSpeedThreshold ) {
            rotate = 10 * lander.hSpeed/hSpeedThreshold;
            cerr << "H 3" << endl;
        } else if ( speed <= hSpeedThreshold) {
            rotate = 5 * lander.hSpeed/hSpeedThreshold;
            cerr << "H 2" << endl;
        } else if ( speed < hSpeedThreshold/4) {
            rotate = 0;
            cerr << "H 1" << endl;
        }
        cerr << "Braking" << endl;
        output(rotate, power);

    } while( std::abs(lander.hSpeed) > hSpeedThreshold);
}

void position_above_landing_zone() {

    auto flat_ground_it = std::adjacent_find(surface.begin(), surface.end(),
            [](const coords_t &c1, const coords_t &c2) { return c1.y == c2.y; });

    auto &flat_ground_start = *flat_ground_it;
    auto &flat_ground_stop = *(flat_ground_it+1);

    cerr << "Flat ground: " << flat_ground_start << flat_ground_stop << endl;
    int flat_ground_center_x = (flat_ground_start.x + flat_ground_stop.x) / 2;
    int flat_ground_width = flat_ground_stop.x - flat_ground_start.x;
    
    int landing_zone_x_center = flat_ground_center_x;
    int landing_zone_x_left = flat_ground_start.x;
    int landing_zone_x_right = flat_ground_stop.x;

    cerr << "Center: " << flat_ground_center_x << " Width: " << flat_ground_width << endl;

    int offset = 0 * flat_ground_width;


    auto in_landing_zone = [flat_ground_start, flat_ground_stop, offset](coords_t position) {
        if (position.x < flat_ground_start.x + offset) return -1;
        if (position.x > flat_ground_stop.x - offset) return 1;
        return 0;
    };



    lander_t lander;
    double power;
    int rotate;
    const int close_distance  = 750;

    do {
        cin >> lander;
        cin.ignore();
        int distance = landing_zone_x_center - lander.position.x;
        int distance_abs = std::abs(distance);
        cerr << "Distance: " << distance << endl;

        if (lander.vSpeed > -5) {
            power = 0;
        } else if (lander.vSpeed > -7) {
            power = 1;
        } else if (lander.vSpeed > -10) {
            power = 2;
        } else if (lander.vSpeed > -20) {
            power = 3;
        } else {
            power = 4;
        }

        if (in_landing_zone(lander.position) == 1) {
            cerr <<"Turning left" << endl;
            rotate=20 ;
        } else if (in_landing_zone(lander.position) == -1) {
            cerr <<"Turning right" << endl;
            rotate=-20;
        } else {
            int speed = std::abs(lander.hSpeed);
            if ( speed > hSpeedThreshold *3) {
                rotate = 20 * lander.hSpeed/hSpeedThreshold;
                cerr << "H 4" << endl;
            } else if ( speed > hSpeedThreshold ) {
                rotate = 15 * lander.hSpeed/hSpeedThreshold;
                power = 5;
                cerr << "H 3" << endl;
            } else if ( speed <= hSpeedThreshold) {
                rotate = 5 * lander.hSpeed/hSpeedThreshold;
                cerr << "H 2" << endl;
            } else if ( speed < hSpeedThreshold/2) {
                rotate = 0;
                cerr << "H 1" << endl;
            }
            //if (distance_abs < 1000) {
                //rotate *=  distance_abs/1000.0;
            //}
            //if (distance_abs < 1000 && std::abs(lander.hSpeed) < hSpeedThreshold) {
                //rotate = -lander.rotate *  distance_abs/1000.0;
            //}
            //if (sgn(distance) == -sgn(lander.hSpeed) && std::abs(lander.hSpeed) > hSpeedThreshold) {
                //rotate = 10* lander.hSpeed/hSpeedThreshold ;
            //}
        }


        output(rotate, power);

    } while( std::abs(lander.hSpeed) > hSpeedThreshold/8
            || lander.position.x < flat_ground_start.x
            || lander.position.x > flat_ground_stop.x);

    cerr << "Finished positioning" << endl;
}

void reduce_horizontal_speed() {

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
        output(rotate, power);


    } while(1);
}

void output(int rotate, int power){
    cout << clip(rotate, -90, 90) << " " << clip(int(power), 0, 4) << endl;
}


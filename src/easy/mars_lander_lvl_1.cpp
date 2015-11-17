#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct coords {
    int x;
    int y;
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    std::vector<coords> surface;

    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();
    surface.reserve(surfaceN);

    for (int i = 0; i < surfaceN; i++) {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> landX >> landY; cin.ignore();

        surface.push_back(coords{landX, landY});
    }

    const int vSpeedThreshold = -40;

    // game loop
    while (1) {
        coords lander_position;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> lander_position.x >> lander_position.y
            >> hSpeed >> vSpeed
            >> fuel >> rotate
            >> power; cin.ignore();

        rotate = 0;
        if (vSpeed <= vSpeedThreshold) {
            power = 4;
        } else {
            power = 0;
        }

        cout << rotate << " " << power << endl;

    }
}

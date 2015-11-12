#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int road_length; // the length of the road before the gap.
int gap_length; // the length of the gap.
int landing_platform_length; // the length of the landing platform.

int speed; // the motorbike's speed.
int position; // the position on the road of the motorbike.

int speed_increase ;
int waits = 0;
int Dc ;
int jump_position ;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void speed_up(){
   cout << "SPEED" << endl;
}
void slow_down(){
   cout << "SLOW" << endl;
}
void jump(){
   cout << "JUMP" << endl;
}
void wait(){
   cout << "WAIT" << endl;
}


void readSX() {
   cin >> speed >> position;
}

void debug() {

   cerr << "road_length: " << road_length << " gap_length: " << gap_length << " landing_platform: " << landing_platform_length << " speed: " << speed << " position: " << position << endl;
   cerr << "speed_increase: " << speed_increase << " Dc: " << Dc << endl;
   cerr << "waits: " << waits <<  endl;

}
int main()
{
   cin >> road_length; cin.ignore();
   cin >> gap_length; cin.ignore();
   cin >> landing_platform_length; cin.ignore();

   cin >> speed; cin.ignore();
   cin >> position; cin.ignore();

   if (!speed) {
      speed_up();
      readSX();
   }

   int minimum_speed = gap_length ;

   if (speed > minimum_speed)
      speed--;


   do {
      minimum_speed++;
      cerr << "minimum_speed: " << minimum_speed << endl;
      speed_increase = minimum_speed - speed ;
      Dc = (speed + minimum_speed) * (std::abs(speed_increase)+1)/2;
      debug();
   } while (Dc > road_length - position + 1);

   if (minimum_speed > speed) {
      waits = (road_length - position) / speed - Dc ;
   } else {
      waits = (road_length - position - Dc) / minimum_speed;
   }

   debug();


   if (speed_increase > 0) {

      while(--waits >= 0) {
         debug();
         wait();
         readSX();
      }
      while(speed_increase-->0) {
         debug();
         speed_up();
         readSX();
      }
   } else  if (speed_increase < 0) {

      while(speed_increase++<=0) {
         debug();
         slow_down();
         readSX();
      }
      while(--waits >= 0) {
         debug();
         wait();
         readSX();
      }
   }
   debug();
   jump();
   readSX();

   while(1) {
      debug();
      slow_down();
      readSX();
   }
}

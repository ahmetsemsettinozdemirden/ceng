
#include <iostream>
#include "GPSCoord.h"

using namespace std;

int main(int argc, char** argv){

    GPSCoord iyteLib (38.319818, 26.639823);
    GPSCoord iyteMath (38.323257, 26.632739);

    // cout << "iyteLib -> " << iyteLib.getLatitude() << ", " << iyteLib.getLongitude() << endl;
    // cout << "iyteMath -> " << iyteMath.getLatitude() << ", " << iyteMath.getLongitude() << endl;
    cout << "Distance between Library and Mathematics department: " << iyteLib.distanceTo(iyteMath) << "m" << endl;

    GPSCoord ankara (39.9035662, 32.4825642);
    GPSCoord izmir (38.4178796, 26.7995155);

    // cout << "ankara -> " << ankara.getLatitude() << ", " << ankara.getLongitude() << endl;
    // cout << "izmir -> " << izmir.getLatitude() << ", " << izmir.getLongitude() << endl;
    
    cout << "Distance between Ankara and Izmir: " << metersToKilometers(ankara.distanceTo(izmir)) << "km" << endl;
    
    return 0;
}

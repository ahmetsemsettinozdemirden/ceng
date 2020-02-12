#ifndef GPSCoord_H
#define GPSCoord_H

#include "Utils.h"
#include <string>

using std::to_string;
using std::string;

class GPSCoord{

    private:
        double latitude; // degrees
        double longitude; // degrees

    public:
        GPSCoord(double latitude, double longitude);

        double getLatitude() const { return latitude; } // returns in degrees
        double getLongitude() const { return longitude; } // returns in degrees
        double getLatitudeInRad() const { return degToRad(latitude); }
        double getLongitudeInRad() const { return degToRad(longitude); }

        double distanceTo(const GPSCoord&);  
        string print() const { return "(" + to_string(latitude) + ", " + to_string(longitude) + ")"; }
};

#endif
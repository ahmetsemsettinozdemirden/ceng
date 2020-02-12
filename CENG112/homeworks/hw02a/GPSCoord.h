
#ifndef GPSCoord_H // class ismiyle ayni olmamasina dikkat et you have hacked by murat...
#define GPSCoord_H

#include "Utils.h"

class GPSCoord{

    // members are private by default ?
    private:
        double latitude; // degrees
        double longitude; // degrees

    public:
        GPSCoord(double latitude, double longitude); // constructor tipi yoktur

        double getLatitude() const { return latitude; } // returns in degrees
        double getLongitude() const { return longitude; } // returns in degrees
        double getLatitudeInRad() const { return degToRad(latitude); }
        double getLongitudeInRad() const { return degToRad(longitude); }

        double distanceTo(const GPSCoord&);  
};

#endif
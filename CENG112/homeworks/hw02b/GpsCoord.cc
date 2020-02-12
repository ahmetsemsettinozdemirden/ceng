#include <iostream>
#include <cmath>

#include "GpsCoord.h"
#include "Utils.h"

using namespace std;

GPSCoord::GPSCoord(double _latitude, double _longitude){ // function basina class ismini yazmayi unutma 'GPSCoord::'
    latitude = _latitude;
    longitude = _longitude;
}

double GPSCoord::distanceTo(const GPSCoord &otherGpsCoord){

    const double R = 6371e3;

    double lat1 = getLatitudeInRad();
    double lat2 = otherGpsCoord.getLatitudeInRad();
    
    double deltaLat = degToRad(otherGpsCoord.getLatitude() - getLatitude());
    double deltaLong = degToRad(otherGpsCoord.getLongitude() - getLongitude());

    double a = pow(sin(deltaLat/2), 2.0) + pow(sin(deltaLong/2), 2.0) * cos(lat1) * cos(lat2);
    double distance = R * 2 * atan2(sqrt(a), sqrt(1-a));
    
    return distance;
}

#define _USE_MATH_DEFINES
#include <cmath>
#include "Utils.h"

double degToRad(double degree){
    return degree * M_PI / 180;
}

double metersToKilometers(double meters){
    return meters / 1000.0;
}

double distanceBetweenCoords(double lat1, double long1, double lat2, double long2){
	
	const double R = 6371e3;

    double lat1InRad = degToRad(lat1);
    double lat2InRad = degToRad(lat2);
    
    double deltaLat = degToRad(lat2 - lat1);
    double deltaLong = degToRad(long2 - long1);

    double a = pow(sin(deltaLat/2), 2.0) + pow(sin(deltaLong/2), 2.0) * cos(lat1InRad) * cos(lat2InRad);
    double distance = R * 2 * atan2(sqrt(a), sqrt(1-a));
    
    return distance;
}

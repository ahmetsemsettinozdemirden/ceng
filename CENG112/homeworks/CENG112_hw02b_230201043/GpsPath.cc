
#include <iostream>

#include "GpsPath.h"
#include "GpsCoord.h"

using std::cout;

void GPSPath::addPoint(double latitude, double longitude){

	GPSCoord newCoord = GPSCoord(latitude, longitude);
	m_points.push_back(newCoord);

}

void GPSPath::print(){

	for (int i = 0; i < m_points.size(); ++i){
		cout << m_points[i].print() << " -- ";
	}

}

double GPSPath::totalDistance(){

	double distance = 0;

	int i = 0;
	size_t s = m_points.size();

	while(i+1 != s){
		distance += m_points[i].distanceTo(m_points[i+1]);
		i++;
	}

	return distance;
}

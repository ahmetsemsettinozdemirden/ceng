
#include "GpsPathList.h"
#include "Utils.h"

#include <iostream>

using std::cout;
using std::endl;
using std::to_string;


void GPSPathList::addNode(const double& latitude, const double& longitude){

	GPSCoordNode *newCoord = new GPSCoordNode;
	newCoord->latitude = latitude;
	newCoord->longitude = longitude;

	if(path == 0){

		newCoord->next = path;
		path = newCoord;

	}else{

		GPSCoordNode *p = path;

		while(p->next != 0)
			p = p->next;

		newCoord->next = p->next;
		p->next = newCoord;

	}
	sizeOfPath++;	
}

void GPSPathList::print() const {
	
	GPSCoordNode *p = path;

	while(p != 0){
		cout << "(" + to_string(p->latitude) + ", " + to_string(p->longitude) + ")" << " -- ";
		p = p->next;
	}
		
}

double GPSPathList::totalDistance() const {
	
	double distance = 0;
	GPSCoordNode *p = path;

	if(p == 0)
		return -1.0; // throw error

	while(p->next != 0){

		distance += distanceBetweenCoords(p->latitude, p->longitude, p->next->latitude, p->next->longitude);

		p = p->next;
	}	

	return distance;
}

void GPSPathList::deletePath(){
	
	GPSCoordNode *p1 = path;

	while(p1 != 0){
		GPSCoordNode *p2 = p1->next;
		delete p1;
		p1 = p2;
	}
	
}





#ifndef GPSPATH_H
#define GPSPATH_H

#include <vector>

#include "GpsCoord.h"

class GPSPath{

	private:
		std::vector<GPSCoord> m_points;

	public:
		void addPoint(double latitude, double longitude);
		void print();
		double totalDistance();

};

#endif

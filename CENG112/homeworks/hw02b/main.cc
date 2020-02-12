
#include <iostream>
#include <string>

#include "Utils.h"
#include "GpsPath.h"

using std::cout;
using std::cin;
using std::endl;
using std::stod;

int main(int argc, char const *argv[]){

	GPSPath path;

	while(true){
		
		cout << "Please enter coordinates in type of <latitude>, <longitude>. Enter \"exit\" to calculate path." << endl << "->";

		string strCoord = "";

		getline(cin, strCoord);

		if(strCoord == "exit")
			break;

		int commaPos = strCoord.find(",");

		double latitude = stod(strCoord.substr(0, commaPos));
		double longitude = stod(strCoord.substr(commaPos+1, strCoord.length()-commaPos));

		path.addPoint(latitude, longitude);
	}

	path.print();

	cout << "Total distance between coordinates: " << path.totalDistance() << endl;

	return 0;
}
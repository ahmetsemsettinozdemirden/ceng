
#include <iostream>
#include <string>

#include "GpsPathList.h"
#include "Utils.h"

using std::cout;
using std::cin;
using std::endl;
using std::stod;
using std::string;

int main(int argc, char const *argv[]){

	GPSPathList path;

	while(true){
		
		cout << "Please enter coordinates in type of <latitude>,<longitude>. Enter \"exit\" to calculate path in meters." << endl << "->";

		string strCoord = "";

		getline(cin, strCoord);

		if(strCoord == "exit")
			break;

		int commaPos = strCoord.find(",");

		double latitude = stod(strCoord.substr(0, commaPos));
		double longitude = stod(strCoord.substr(commaPos+1, strCoord.length()-commaPos));

		path.addNode(latitude, longitude);
	}

	path.print();

	cout << "Total distance between coordinates: " << path.totalDistance() << endl;

	return 0;
}
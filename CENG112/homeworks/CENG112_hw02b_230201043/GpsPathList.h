
#ifndef GPSPATHLIST_H
#define GPSPATHLIST_H

class GPSPathList{

	public:
		GPSPathList() { sizeOfPath = 0; path = 0; }
		~GPSPathList() { deletePath(); }

		void addNode(const double& latitude, const double& longitude);
		void print() const;
		double totalDistance() const;
	
	private:

		struct GPSCoordNode{
			double latitude;
			double longitude;
			GPSCoordNode *next;
		};

		void deletePath();

		int sizeOfPath;
		GPSCoordNode *path;

};

#endif
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <sstream>
#include <fstream>

using namespace std;

struct st {

	string städer;
	string tempFar;
	string årstid;

};
vector<st> para_vector;
int main() {

	while(true){
	string filname;
	cout << endl << "Enter the name of the file to read: ";
	cin >> filname;
	if (filname == "0") {
		break;
	}
	ifstream fil(filname);

	string filename;
	cout << "Enter the new file name for storing Celsius Data: ";
	cin >> filename;
	if (filename == "0") {
		break;
	}
	ifstream filed(filename);

	string rad;
	

	while (getline(fil, rad)) {

		st tempdata;

		istringstream iss(rad);


		getline(iss >> ws, tempdata.städer, ',');
		getline(iss >> ws, tempdata.tempFar, ',');
		iss >> tempdata.årstid;

		string s;
		getline(iss, s);
		para_vector.push_back(tempdata);

	}
	ofstream file(filename);
	for (st tempdata : para_vector) {
		int fahr = stoi(tempdata.tempFar);
		int Cel = (fahr - 32) * 5 / 9;					
		
		
		

		file << tempdata.städer  << "," << Cel<< "," << tempdata.årstid << endl;
	}
	
	


	
	cout << "Reading from file: " << filename << endl;
	while (getline(filed, rad)) {

		cout << rad << endl;

	}


	}

}
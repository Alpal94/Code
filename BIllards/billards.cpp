#include<iostream>
#include <cstdio>
#include<sstream>
#include<cmath>
#include<string>
using namespace std;

int main () {
	string line;
	float array[7];


	float pi = 3.1415926535897;	
	float Y; double theta; double thetaOrig; 
	float xBall; double yBall;
	float xHole; double yHole;
	float C; double D; double u; double a;	
	float B; bool terminated = false;
	float xSol; double ySol; double angleSol;

	while(getline(cin,line)) {
        // Read input
		istringstream iss(line);
		iss >> ws;	
		for (int i = 0; i < 7; i++ ) iss >> array[i] >> ws;
			
        // Make the input easier to manipulate
		xBall = array[0]; yBall = array[1]; xHole = array[2]; yHole = array[3];
		u = array[4]; a = array[5]; theta = array[6]; thetaOrig = array[6];
        
        // Find distance ball travelled
		D = -u*u/a + u*u/(2*a);	
			
        // Find theta
		if (theta > 90.0) theta = abs(90 - theta);
		if (thetaOrig < -90.0) theta = -abs(90 - thetaOrig);
		theta = pi*theta/180;
		theta = abs(abs(atanf((yHole - yBall)/(xHole - xBall))) - theta);
        
        //Find distance between hole and ball
		C = pow(pow(yHole - yBall, 2) + pow(xHole - xBall, 2), 0.5);

        //Check if hole in one or impossible, print result
		if(D == C) {
			cout << "Hole in one" << endl;
			terminated = true;
		}	
		if (D < C) {
			cout << "Impossible" << endl;
			terminated = true;
		}
		if ((xBall == yBall) && (xHole == yHole)) {
			cout << "Hole in one" << endl;
			terminated = true;
		}
	




        //Find B
		B = (D*D - C*C)/(2*D - 2*C*cos(theta));
		//Find Y
		Y = pi - acos((B*cos(theta) - C)/(D-B));

		//Find solution using B and the angle of the direction
		xSol = B*cos(thetaOrig*pi/180) +  xBall;
		ySol = B*sin(thetaOrig*pi/180) +  yBall;
		angleSol = 180*(Y + theta)/(2*pi);
		
		xSol = round(10*xSol)/10;
		ySol = round(10*ySol)/10;
		angleSol = round(10*angleSol)/10;

		if (xSol == 0) xSol = 0;
		if (ySol == 0) ySol = 0;
		if (angleSol == 0) angleSol = 0;
        // Print output if not impossible or hole in one
		if(terminated == false) {
			printf("%.1f %.1f %.1f", xSol, ySol, angleSol);
			cout << endl;
		}
		//
		//
		// cout << xxSol << " " <<  ySol << " " <<  AangleSol << endl;	
		terminated = false;
	}
}

#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;



double ForcaUM(double t){

	return 0;
}

double ForcaDOIS(double t){
	return 0;
}


void forwardEuller(double t, double deltaT, double k1, double k2, double m1, double m2, double u1, double u2, double v1, double v2){

	double i = deltaT;
	double u1_ant,u2_ant,v1_ant,v2_ant;
	double u1_new,u2_new,v1_new,v2_new;


	u1_ant = u1;
	u2_ant = u2;
	v1_ant = v1;
	v2_ant = v2;

	while (i <= t){



		u1_new = u1_ant + (deltaT*v1_ant);

		u2_new = u2_ant + (deltaT*v2_ant);

		v1_new = v1_ant + deltaT*((1.0/m1)*((ForcaUM(i)+(k2*((u2_ant-u1_ant))-(k1*u1_ant)))));

		v2_new = v2_ant + deltaT*((1.0/m2)*((ForcaDOIS(i)-(k2*(u2_ant-u1_ant)))));

		u1_ant = u1_new;

		u2_ant = u2_new;

		v1_ant = v1_new;
 
		v2_ant = v2_new;

		i = i + deltaT;
	}

	cout << "u1 é: " << u1_new <<endl;
	cout << "u2 é: " << u2_new <<endl;
	cout << "v1 é: " << v1_new <<endl;
	cout << "v2 é: " << v2_new <<endl;




}



int main(int argc, char const *argv[]){
	
	double t,deltaT,k1,k2,m1,m2,u1,u2,v1,v2;


	cout << "Entre t : " <<endl;
	cin >> t;

	cout << "Entre delta t : " <<endl;
	cin >> deltaT;

	cout << "Entre k1 : " <<endl;
	cin >> k1;

	cout << "Entre k2 : " <<endl;
	cin >> k2;

	cout << "Entre m1 : " <<endl;
	cin >> m1;

	cout << "Entre m2 : " <<endl;
	cin >> m2;

	cout << "Entre u1 : " <<endl;
	cin >> u1;

	cout << "Entre u2 : " <<endl;
	cin >> u2;

	cout << "Entre v1 : " <<endl;
	cin >> v1;

	cout << "Entre v2 : " <<endl;
	cin >> v2;


	forwardEuller( t,  deltaT,  k1,  k2,  m1,  m2,  u1,  u2,  v1,  v2);




	return 0;
}
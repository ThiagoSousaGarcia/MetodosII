#include <iostream>
#include <math.h>

#define _USE_MATH_DEFINES

using namespace std;

double f(double x, double y) {

	return sqrt(100.0 - ((x * x) + (y * y)));

}

double n2(double a, double b) {

	return -(1.0 / 4.0) * (a + 1.0) * (b - 1.0);

}

double n3(double a, double b) {

	return (1.0 / 4.0) * (a + 1.0) * (b + 1.0);

}

double n4(double a, double b) {

	return -(1.0 / 4.0) * (a - 1.0) * (b + 1.0);

}

double xab(double alpha, double beta) {

	return 2.0 * n2(alpha, beta) + 3.0 * n3(alpha, beta) + n4(alpha, beta);

}

double yab(double alpha, double beta) {

	return n2(alpha, beta) * 3.0 * n3(alpha, beta) + 2.0 * n4(alpha, beta);

}

double dxdalpha() {

	return 1.0;

}

double dxdbeta() {

	return 0.5;

}

double dydalpha() {

	return 0.5;

}

double dydbeta() {

	return 1.0;

}

double detJacob() {

	return 3.0 / 4.0;

}

int main() {
	
	double a;
	double b;
	
	double wi[3] = {(5.0 / 9.0), (8.0 / 9.0), (5.0 / 9.0)};
	double wj[3] = {(5.0 / 9.0), (8.0 / 9.0), (5.0 / 9.0)};
	
	double alpha[3] = {-sqrt(3.0 / 5.0), 0.0, sqrt(3.0 / 5.0)};
	double beta[3] = {-sqrt(3.0 / 5.0), 0.0, sqrt(3.0 / 5.0)};
	
	double volume = 0.0;
	
	for (int i = 0; i < 3; i++) {
	
		for (int j = 0; j < 3; j++) {
		
			volume += wi[i] * wj[j] * f(xab(alpha[i], beta[j]),
					yab(alpha[i], beta[j])) * detJacob();
		
		}
	
	}
	
	cout << "O volume é : " << volume << endl;
	
	return 0;

}

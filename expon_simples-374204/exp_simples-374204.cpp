#include <iostream>
#include <math.h>

using namespace std;

double xs(double a, double b, double s) {

	return ((a + b) / 2) + ((b - a) / 2) * tanh(s);

}

double f(double x) {

	return (x/tan(x));

}

double g(double origina, double originb, double s) {

	return f(xs(origina, originb, s)) * (4.0 / (exp(2 * s) + 2 +
			(exp(-2 * s))));

}

double newton_cotes_g2(double origina, double originb, double a, double b) {

	double h = (b - a) / 2.0;
	
	return (h / 3.0) * (g(origina, originb, a) + 4.0 *
			g(origina, originb, a + h) + g(origina, originb, b));

}

double integral(double origina, double originb, double a, double b,
				double epsilon) {
	
	double n = 1;
	double oldintegral;
	double step;
	double linf;
	double lsup;
	
	double integralv = newton_cotes_g2(origina, originb, a, b);
	
	do {
		
		oldintegral = integralv;
		integralv = 0.0;
		
		n = n * 2;
		step = (b - a) / n;
		
		for (int i = 0; i < n; i++) {
		
			linf = a + i * step;
			lsup = linf + step;
			
			integralv += newton_cotes_g2(origina, originb, linf, lsup);
		
		}
	
	} while (fabs(integralv - oldintegral) > epsilon);
	
	return integralv;

}

int main() {
	
	double a;
	double b;
	double precisao;
	double linfg;
	double lsupg;
	
	cout << "Entre o valor de a: ";
	cin >> a;
	
	cout << "Entre o valor de b: ";
	cin >> b;

	cout << "Entre a precisão desejada : " ;
	cin >> precisao;


	linfg = a;
	lsupg = b;
	
	double integr = ((b - a) / 2) * integral(a, b, linfg, lsupg, precisao);
	double oldintegr;
	
	do {
	
		oldintegr = integr;
		
		linfg = linfg - 1;
		lsupg = lsupg + 1;
		
		integr = ((b - a) / 2) * integral(a, b, linfg, lsupg, precisao);
		
	} while (fabs(integr - oldintegr) > precisao);
	
	cout << "O valor da integral é " << integr << endl;
	
	return 0;

}

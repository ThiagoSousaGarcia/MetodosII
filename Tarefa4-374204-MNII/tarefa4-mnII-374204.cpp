#include <cmath>
#include <iostream>

using namespace std;


double f(double x,double y){
	return (2*y*sin(x)) + (cos(x)*cos(x));
}

double xAlphaBeta(double a, double b,double alpha){
	return ((a+b)/2) + (((b-a)/2)*alpha);
}

double yAlphaBeta(double a,double b,double alpha,double beta){
	return (((sin(xAlphaBeta(a,b,alpha))+cos(xAlphaBeta(a,b,alpha)))/2) + (((cos(xAlphaBeta(a,b,alpha))-sin(xAlphaBeta(a,b,alpha)))/2)*beta));
}

double dxdalpha(double a,double b){
	return (b-a)/2;
}

double dydbeta(double a, double b,double alpha){
	return (cos(xAlphaBeta(a,b,alpha))-sin(xAlphaBeta(a,b,alpha)))/2;
}

int main(int argc, char const *argv[]){
	
	double a,b;
	double wi[3] = {5.0/9.0, 8.0/9.0, 5.0/9.0};
	double wj[2] = {1,1};
	double raizes_alpha[3] = {-sqrt(3.0/5.0),0,sqrt(3.0/5.0)};
	double raizes_beta[2] = {-sqrt(1.0/3.0),sqrt(1.0/3.0)};
	double integral = 0;

    cout << "Entre o intervalo de integração (a, b):" << endl;
    cout << "a = ";
    cin  >>  a;
    cout << endl << "b = ";
    cin  >> b;
	
	for (int i = 0; i < 3; i++){//alpha
		for (int j = 0; j < 2; j++){//beta
			integral += (wi[i]*wj[j]) * f(xAlphaBeta(a,b,raizes_alpha[i]),yAlphaBeta(a,b,raizes_alpha[i],raizes_beta[j])) * (dxdalpha(a,b)*dydbeta(a,b,raizes_alpha[i]));
		}
	}

	cout<<"A integral calculada é "<< integral << endl;

	return 0;
}
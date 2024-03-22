#include <iostream>
#include <cmath>
using namespace std;
void main() {
	float c,	 dt, t, num, anal;
	// differentiation
	cout << " c ? = ";
	cin >> c;
	cout << " t dt ? = ";
	cin >> t >> dt;
	anal = 1/t;
	num = (log(-c * (t + dt)) - log(-c * t)) / dt;
	cout << " num " << num << " anal " << anal << endl;
	cout << " error = " << (num - anal) / anal * 100 << "%\n";

	//integration
	float a, b;
	int N;
	cout << " a b N = ";
	cin >> a >> b >> N;
	anal = b * log(-c * b) - a * log(-c * a) - (b - a);
	dt = (b - a) / N;
	num = 0;
	for (int i = 0; i < N; i++) {
		num += log(-c * (a + dt * i)) * dt;
	}
	cout << " num " << num << " anal " << anal << endl;
	cout << " error = " << (num - anal) / anal * 100 << "%\n";
}
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	int n, a;
	double min;
	if(file.is_open()) {
		while(true) {
			file >> n;
			if(n <= 0)
				return 0;
			vector<double> x;
			vector<double> y;
			for(int i = 0; i < n; i++) {
				file >> a;
				x.push_back(a);
				file >> a;
				y.push_back(a);
			}
			min = 10000;
			for(int i = 0; i < n - 1; i++) {
				for(int j = i + 1; j < n; j++) {
					double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
					if(dist < min)
						min = dist;
				}
			}
			if(min < 10000) {
				cout.precision(4);
				cout << fixed;
				cout << min << "\n";
			}
			else
				cout << "INFINITY\n";
		}
	}
}

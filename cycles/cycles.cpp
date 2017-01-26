#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string find_cycle(vector<int> number);

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;
	if(file.is_open()) {
		getline(file, line);
		while(getline(file, line)) {
			vector<int> numbers;
			stringstream stream(line);
			while(stream) {
				int n;
				stream >> n;
				numbers.push_back(n);
			}
			cout << find_cycle(numbers);
		}
		file.close();
	}
	return 0;
}

string find_cycle(vector<int> numbers)
{
	return "numbers";
}

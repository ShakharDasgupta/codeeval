#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;
	if(file.is_open()) {
		getline(file, line);
		int limit;
		stringstream(line) >> limit;
		vector<string> strings;
		while(getline(file, line))
			strings.push_back(line);
		file.close();
		sort(strings.begin(), strings.end(), [] (string s1, string s2) { return s1.size() > s2.size(); });
		for(int i = 0; i < limit; i++)
			cout << strings.at(i) << endl;
		return 0;
	}
}

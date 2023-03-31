#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int devs, teams;
	vector<int> quality;
	cin >> devs >> teams;
	for (int i = 0; i < devs; ++i) {
		int el;
		cin >> el;
		quality.push_back(el);
	}

}


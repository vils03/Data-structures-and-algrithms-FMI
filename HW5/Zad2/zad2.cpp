#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int main()
{
	int people, group;
	cin >> people >> group;
	if (group < 0 || people < 0)
		cout << 0;
	vector<long long int> allPeople;
	for (int i = 0; i < people; ++i) {
		long long int el;
		cin >> el;
		allPeople.push_back(el);
	}


	long long int minWork = 0;
	deque<int> check(group);
	int minN = INT_MAX;
	if (group > people) {
		for (int i = 0; i < people; ++i) {
			if (allPeople[i] < minN)
				minN = allPeople[i];
		}
		cout << minN;
	}
	else {
		for (int i = 0; i < group; i++)
		{
			while ((!check.empty()) && allPeople[check.back()] >= allPeople[i])
				check.pop_back();
			check.push_back(i);
		}
		for (int i = group; i < people; ++i) {
			minWork += allPeople[check.front()];
			while (!check.empty() && check.front() <= i - group)
				check.pop_front();
			while ((!check.empty()) && allPeople[check.back()] >= allPeople[i])
				check.pop_back();
			check.push_back(i);
		}
	}
	minWork += allPeople[check.front()];
	cout << minWork;
}

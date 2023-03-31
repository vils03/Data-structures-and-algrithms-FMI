#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tour {
	int min, max;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int students, tours;
	cin >> students >> tours;
	vector<int> weight;
	vector<tour> interval(tours);
	for (int i = 0; i < students; ++i) {
		int element;
		cin >> element;
		weight.push_back(element);
	}
	for (int i = 0; i < tours; ++i) {
		int min, max;
		cin >> min >> max;
		interval[i].min = min;
		interval[i].max = max;
	}
	sort(weight.begin(), weight.end());
	vector<int> results;
	for (int i = 0; i < interval.size(); ++i) {
		if (interval[i].min > interval[i].max) {
			results.push_back(0);
		}
		else {
			auto low = lower_bound(weight.begin(), weight.end(), interval[i].min);
			auto up = upper_bound(weight.begin(), weight.end(), interval[i].max);
			int ret = up - low;
			if (ret < 0 || ret > students) {
				results.push_back(0);
			}
			else
				results.push_back(ret);
		}
	}
	for (int i = 0; i < results.size(); ++i) {
		cout << results[i] << "\n";
	}
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string movies;
	cin >> movies;

	vector<int> found (127, 0);
	vector<int> toReturn;
	for (unsigned int i = 0; i < movies.size(); ++i) {
		found[int(movies[i])]++;
	}
	for (unsigned int i = 0; i < found.size(); ++i) {
		if (found[i] == 1) {
			size_t ind = movies.find(char(i));
			toReturn.push_back(ind);
		}
	}
	sort(toReturn.begin(), toReturn.end());
	for (unsigned int i = 0; i < toReturn.size(); ++i) {
		cout << toReturn[i] << " ";
	}
}



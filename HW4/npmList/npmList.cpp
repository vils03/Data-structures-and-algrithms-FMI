#include <iostream>
#include <list>
#include <vector>
using namespace std;

bool install(vector<int>& countArray, list<int>& lst, int number, int size, int& counter) {
	
	if (counter < size) { 
		if (countArray[number] == 0) {
			lst.push_front(number);
			countArray[number]++;
			counter++;
			return false;
		}
		else {
			countArray[number]++;
			lst.push_front(number);
			lst.pop_back();
			return true;
		}
	}
	else {
		if (countArray[number] == 0) { 
			int el = lst.back();
			if (countArray[el] > 1) {
				countArray[el]--;
				countArray[number]++;
				lst.pop_back();
				return false;
			}
			else {
				lst.pop_back();
				countArray[el]--;
				countArray[number]++;
				lst.push_front(number);
				return false;
			}
		}
		else { 
			lst.push_front(number);
			countArray[number]++;
			lst.pop_back();
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int requests, maxP;
	cin >> requests >> maxP;
	vector<int> all;
	int maxNum = 0;
	
	list<int> llist;
	for (int i = 0; i < requests; ++i) {
		int el;
		cin >> el;
		if (el > maxNum) {
			maxNum = el;
		}
		all.push_back(el);
	}
	int counter = 0;
	vector<int> countArray(maxNum + 1, 0);
	for (int i = 0; i < all.size(); ++i) {
		cout << boolalpha << install(countArray, llist, all[i], maxP, counter) << "\n";
	}
}


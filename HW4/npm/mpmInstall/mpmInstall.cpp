#include <iostream>
#include <list>
#include <vector>
using namespace std;

bool install(list<int>& lst, int number, int size) {
	int itCount = 0;
	auto it = lst.begin();
	while (it != lst.end()) {
		int tocheck = *it;
		if (tocheck == number) {
			it++;
			itCount++;
			lst.remove(number); 
			lst.push_front(number);
			return true;
		}
		else if (itCount == size - 1)
		{
			lst.push_front(number);
			it++;
			lst.pop_back();
			return false;
		}
		it++;
		itCount++;
	}
	return false;
}
		
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int requests, maxP;
	cin >> requests >> maxP;
	vector<bool> answers;
	list<int> llist(maxP, -1);
	for (int i = 0; i < requests; ++i) {
		int el;
		cin >> el;
		answers.push_back(install(llist, el, maxP));
	}
	
	for (int i = 0; i < answers.size(); ++i) {
		cout << boolalpha << answers[i] << "\n";
	}
}
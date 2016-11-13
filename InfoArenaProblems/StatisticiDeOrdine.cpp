#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ifstream in("sdo.in");
	ofstream out("sdo.out");

	int n, k;
	vector<int> numbers;

	in >> n >> k;

	k--;
	numbers.resize(n);

	for (int i = 0; i < n; i++)
	{
		int nr;
		in >> nr;
		numbers[i] = nr;
	}

	nth_element(numbers.begin(), numbers.begin() + k , numbers.end());

	out << numbers[k];

	return 0;
}
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	int n;
	vector<int> A;
	vector<int> B;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}

	int toAdd = A[n-1];
	B.push_back(A[n - 1]);

	for (int i = n-1; i >= 1; i--) {
		int currentNumber = toAdd + A[i - 1];;
		B.push_back(currentNumber);
		toAdd = -toAdd + currentNumber;
		if (B.size() == n)
			break;
	}

	for (int i = B.size() - 1; i >= 0; i--) {
		cout << B[i];
		if(i != 0)
			cout << " ";
	}

	return 0;
}
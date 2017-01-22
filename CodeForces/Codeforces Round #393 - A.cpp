#include <iostream>
#include <vector>
int main() {

	int month, day;
	int answer = 0;
	std::cin >> month>> day;
	month--;
	std::vector<int> months = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	int days = months[month];

	for (int date = 1; date <= days; date++) {
		if (date != 1) {
			day++;
		}
		if (day == 7) {
			answer++;
			day = 0;
		}
		if (date == days && day != 0) {
			answer++;
		}
	}

	std::cout << answer;
	return 0;
}
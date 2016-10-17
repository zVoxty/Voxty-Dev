#include <iostream>
#include "engine.h"
#include <string>

using namespace std;

int secvenceExist(string mainSecv, string searchSecv) {
	int numberOfAparitions = 0;
	bool exist;
	int range1 = mainSecv.length() - searchSecv.length();
	for (int i = 0; i <= range1; i++) {
		exist = true;
		int range2 = i + searchSecv.length() - 1;
		for (int j = i; j <= range2; j++) {
			if (mainSecv[j] != searchSecv[j - i]) {
				exist = !exist;
				break;
			}
		}
		if (exist) {
			numberOfAparitions++;
		}

	}
	return numberOfAparitions;
}
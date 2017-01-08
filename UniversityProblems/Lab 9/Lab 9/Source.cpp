#include "Matrix.h"

using namespace std;

int main() {

	Sort<int> Integers;
	Integers.create();
	Integers.Print();
	Integers.SortElem();
	Integers.Print();

	cout << endl << endl;

	Sort<float> Floats;
	Floats.create();
	Floats.Print();
	Floats.SortElem();
	Floats.Print();

	cout << endl << endl;

	Sort<string> Strings;
	Strings.create();
	Strings.Print();
	Strings.SortElem();
	Strings.Print();

	cout << endl << endl;

	Sort<Matrix> Matrixx;
	Matrixx.Create();
	Matrixx.SortMatrix();
	Matrixx.Print();

	system("PAUSE");
}
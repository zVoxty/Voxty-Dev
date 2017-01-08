#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<class T>

class Sort
{
public:
	Sort() {

	}
	~Sort() {

	}

private:
	vector<T> myArray;
	int n;
public:
	void create() {
		cout << "How much elements : ";
		cin >> n;

		for (int i = 0; i < n; i++) {
			cout << "Element " << i + 1 << " : ";
			T element;
			cin >> element;
			myArray.push_back(element);
		}
		cout << endl;
	}

	void Print() {
		cout << "Printing array : ";
		for (int i = 0; i < myArray.size(); i++)
			cout << myArray[i] << " ";
		cout << endl;
	}

	void SortElem() {
		sort(myArray.begin(), myArray.end());
	}
};


class Matrix
{
public:
	Matrix() {

	}
	~Matrix() {

	}
private:
	int dimensiune;
	int matrix[100][100];
public:
	int sum = 0;

	void CreateMatrix() {
		cout << "Matrix Dimension : ";
		cin >> dimensiune;
		for (int i = 0; i < dimensiune; i++) {
			for (int j = 0; j < dimensiune; j++) {
				cout << "Element [" << i << "][" << j << "] : ";
				cin >> matrix[i][j];
				sum += matrix[i][j];
			}
		}
	}

	void PrintMatrix() {
		for (int i = 0; i < dimensiune; i++){
			for (int j = 0; j < dimensiune; j++){
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "\n\n";
	}
};

template<> class Sort<Matrix> {
private:
	int dimension;
	Matrix matrix[10];
public:
	void Create() {
		cout << "Elements dimension : ";
		cin >> dimension;
		for (int i = 0; i < dimension; i++) {
			matrix[i].CreateMatrix();
		}
	}

	void Print() {
		for (int i = 0; i < dimension; i++) {
			matrix[i].PrintMatrix();
		}
	}

	void SortMatrix() {
		cout << "Matrix array sort ." << endl << endl;
		for (int i = 0; i < dimension; i++) {
			for (int j = i + 1; j < dimension; j++) {
				if (matrix[i].sum > matrix[j].sum) {
					Matrix temp = matrix[i];
					matrix[i] = matrix[j];
					matrix[j] = temp;
				}
			}
		}
	}
};


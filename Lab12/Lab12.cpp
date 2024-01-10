#include "pch.h"
#include <iostream>
#include <cstring>

using namespace std;

class OneDimensionalArray {
private:
	char* elements;
	int size;

public:
	OneDimensionalArray(const char* str) {
		size = strlen(str);
		elements = new char[size];
		memcpy(elements, str, size * sizeof(char));
	}

	bool operator!=(const OneDimensionalArray& other) const {
		if (size != other.size) {
			return true;
		}
		for (int i = 0; i < size; i++) {
			if (elements[i] != other.elements[i]) {
				return true;
			}
		}
		return false;
	}

	OneDimensionalArray operator+(const OneDimensionalArray& other) const {
		int newSize = size + other.size;
		char* newArray = new char[newSize];
		memcpy(newArray, elements, size * sizeof(char));
		memcpy(newArray + size, other.elements, other.size * sizeof(char));
		OneDimensionalArray result(newArray);
		return result;
	}

	void RemoveVowels() {
		char vowels[] = "aeiouAEIOU";
		for (int i = 0; i < size; i++) {
			if (strchr(vowels, elements[i])) {
				elements[i] = ' ';
			}
		}
	}

	void RemoveFirstFiveElements() {
		if (size > 5) {
			size -= 5;
			char* newArray = new char[size];
			memcpy(newArray, elements + 5, size * sizeof(char));
			delete[] elements;
			elements = newArray;
		}
		else {
			
			size = 0;
		}
	}

	void Print() const {
		for (int i = 0; i < size; i++) {
			if (elements[i] < 'A' || elements[i] > 'z') {
				cout << "";
			}
			else {
				cout << elements[i];
			}

		}
		cout << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Ru");

	const char* str1 = "Hello";
	const char* str2 = "Worldfffff";

	OneDimensionalArray array1(str1);
	OneDimensionalArray array2(str2);

	bool arraysNotEqual = array1 != array2;
	cout << "Строки идентичны: " << boolalpha << arraysNotEqual << endl;

	OneDimensionalArray mergeArray = array1 + array2;
	cout << "Строки после слияния: ";
	mergeArray.Print();

	array1.RemoveVowels();
	cout << "Удаляем английские гласные: ";
	array1.Print();

	array2.RemoveFirstFiveElements();
	cout << "Строка №2 после удаления пяти первых char: ";
	array2.Print();

	return 0;
}
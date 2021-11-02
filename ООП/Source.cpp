#include <iostream>
#include <stdio.h>

using namespace std;

class String
{
	friend std::ostream& operator<<(std::ostream&, String&);
	friend std::istream& operator>>(std::istream&, String&);
	char* str = nullptr;
	int length;
public:
	String() {}
	String(const char* arr, int& n) { //инициализация строкой 1: передаем в массив строку и количество элементов в ней
		length = n; //строка str* в классе инициализируется переданной строкой
		str = new char[length];
		for (int i = 0; i < n; ++i) {
			str[i] = arr[i];
		}
	}
	String(char* arr) { //инициализация строкой 2, тоже самое, что и сверху, тольк не надо передавать колво символов в строке
		int i = 0;
		while (arr[i]) {
			i++;
		}
		length = i;
		str = new char[length];
		for (int i = 0; i < length; ++i) {
			str[i] = arr[i];
		}
	}

	String(String& tip) { //инициализация классом String(конструктор копирования)
		length = tip.length;
		str = new char[length];
		for (int i = 0; i < length; ++i) {
			str[i] = tip.str[i];
		}
	}
	String& Concat(String* temp) {
		char* nstr = new char[length + temp->length];
		for (int i = 0; i < length; ++i) {
			nstr[i] = str[i];
		}
		length += temp->length;
		for (int i = 0; i < temp->length; ++i) {
			nstr[length - temp->length + i] = temp->str[i];
		}
		str = nstr;
		return *this;
	}
	int& Length() {
		return length;
	}
	char* Char(int) {
		for (int i = 0; i < length; ++i)
			return (char*)str[i];
	}
	friend void Print(String&);

	String& operator=(const char* arr) {
		int i = 0;
		while (arr[i]) {
			i++;
		}
		length = i;
		if (str)
			delete[] str;
		str = new char[length];
		for (int i = 0; i < length; ++i) {
			str[i] = arr[i];
		}
		return *this;
	}

	String& operator=(const String* tip) {
		length = tip->length;
		if (str)
			delete[] str;
		str = new char[length];
		for (int i = 0; i < length; ++i) {
			str[i] = tip->str[i];
		}
		return *this;
	}

	String& operator+=(const String& temp) {
		char* nstr = new char[length + temp.length];
		for (int i = 0; i < length; ++i) {
			nstr[i] = str[i];
		}
		length += temp.length;
		for (int i = 0; i < temp.length; ++i) {
			nstr[length - temp.length + i] = temp.str[i];
		}
		str = nstr;
		return *this;
	}

	String& operator+=(const char* arr) {
		int i = 0;
		while (arr[i]) {
			i++;
		}
		char* nstr = new char[length + i];
		for (int i = 0; i < length; ++i) {
			nstr[i] = str[i];
		}
		length = length + i;
		for (int j = 0; j < i; ++j) {
			nstr[length - i + j] = arr[j];
		}
		delete[] str;
		str = nstr;
		return *this;
	}

	char operator[](int ind) {
		return str[ind];
	}

};
std::ostream& operator<<(std::ostream& os, String& t1) {
	os << t1.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& t1) {
	is >> t1.length;
	t1.str = new char[t1.length];
	is >> t1.str;
	return is;
}

void Print(String& s) {
	for (int i = 0; i < s.length; ++i)
		std::cout << s.str[i];
}

int main() {
	int n = 8;
	char a[] = "lalalala";
	char b[] = "cherry pie";
	String str(a, n); //инициализация строкой 1
	String m(b); //инициализация строкой 2
	String s(m); //инициализация классом String
	String ss;
	char ch[] = "nanana";
	ss = ch;
	ss.Concat(&m);
	Print(ss);
	std::cout << ss.Length();

	//тестим операторы
	String st;
	char k[] = "tadam!";
	st = k;
	Print(st);
	std::cout << '\n';
	st = m;
	Print(st);
	std::cout << '\n';
	st += m;
	Print(st);
	std::cout << '\n';
	st += k;
	Print(st);
	std::cout << '\n' << st[3] << '\n';
	std::cout << st;
	String nns;
	std::cin >> nns;
	Print(nns);

	return 0;
}
#include <string>

// Implementati o clasa care sa lucreze cu siruri de caractere, asemeni clasei String din std.

class MyString {

	char* str = nullptr;
	int len = 0;

public:

/*	- constructor cu 2 parametri
*	- constructor de copiere
*	- metode de set si get
*	- destructor
*	- supraincarcare operator =
*/

	MyString() {

	}

	MyString(const char* _str, int _len) {

		this->setString(_str, _len);
	}

	MyString(const MyString& s) : MyString(s.str, s.len) {

	}

	char* getString() {

		if (this->str == nullptr) {
			return nullptr;
		}

		char* copy = new char[this->len + 1];
		strcpy_s(copy, this->len + 1, this->str);
		return copy;

	}

	int getLen() { return this->len; }

	void setString(const char* _str, int _len) {

		if (this->str != nullptr) {
			delete[] this->str;
		}

		this->str = new char[_len + 1];
		strcpy_s(this->str, _len + 1, _str);
		this->len = _len;

	}

	MyString operator=(const MyString& source) {

		if (&source == this) {
			return *this;
		}

		if (this->str != nullptr) {
			delete[] this->str;
		}
		this->setString(source.str, source.len);

		return source;

	}

	~MyString() {

		delete[] this->str;
	}
};

/*	- exemplificare in main:
*	* evidentiere apel constructor cu param
*	* evidentiere apel constructor de copiere
*	* evidentiere apel operator =
*/

int main() {

	MyString str1("Piata Victoriei", strlen("Piata Victoriei"));

	MyString str2 = str1;

	MyString str3;
	str3 = str1;

//	str3 = str3;
}
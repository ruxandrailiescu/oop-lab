#include <iostream>

using namespace std;

// Composition: "has a" relationship -> avem atribut de tip A in clasa B
// Inheritance: "is a" relationship -> clasa B e derivata din clasa A

class Date {

	int day = 0;
	int month = 0;
	int year = 0;

public:
	Date() {}

	Date(int d, int m, int y) :day(d), month(m), year(y) {}
};


class Person {

protected:
	string name = "";
	Date birthDate;
	string pin = "";
	string* addresses = nullptr;
	int addressCount = 0;

public:
	Person() {}

	Person(string _name, Date _birthDate, string _pin, string* _addresses, int _addressCount) :name(_name), birthDate(_birthDate), pin(_pin) {

		if (_addresses != nullptr) {
			this->addresses = new string[_addressCount];
			for (int i = 0; i < _addressCount; i++)
				this->addresses[i] = _addresses[i];
			this->addressCount = _addressCount;
		}
		else {
			this->addresses = nullptr;
			this->addressCount = 0;
		}
	}

	Person(const Person& p) :Person(p.name, p.birthDate, p.pin, p.addresses, p.addressCount) {}

	Person& operator=(const Person& p) {

		if (this == &p) {
			return *this;
		}
		else {
			this->name = p.name;
			this->birthDate = p.birthDate;
			this->pin = p.pin;
			this->addressCount = p.addressCount;
			if (this->addresses != nullptr)
				delete[] this->addresses;
			this->addresses = new string[this->addressCount];
			for (int i = 0; i < this->addressCount; i++)
				this->addresses[i] = p.addresses[i];
		}
		return *this;
	}

	virtual string listDetails() {
		return "I'm a Person";
	}

	~Person() {

		if (this->addresses != nullptr) {
			delete[] this->addresses;
			this->addresses = nullptr;		// not necessary here since obj is destroyed after main stack is terminated
		}
	}
};


class Student : public Person {

	int regNo = 0;
	double* grades = nullptr;
	int gradesCount = 0;

public:
	Student() {}

	Student(string _name, Date _birthDate, string _pin, string* _addresses, int _addressCount, int _regNo, double* _grades, int _gradesCount)
		: Person(_name, _birthDate, _pin, _addresses, _addressCount) {

		this->regNo = _regNo;
		this->gradesCount = _gradesCount;
		this->grades = new double[this->gradesCount];
		for (int i = 0; i < this->gradesCount; i++)
			this->grades[i] = _grades[i];
	}

	Student(const Student& s) : Student(s.name, s.birthDate, s.pin, s.addresses, s.addressCount, s.regNo, s.grades, s.gradesCount) {}

	Student& operator=(const Student& s) {

		if (this != &s) {
			Person::operator=(s);
			this->regNo = s.regNo;
			this->gradesCount = s.gradesCount;
			delete[] this->grades;
			this->grades = new double[this->gradesCount];
			for (int i = 0; i < this->gradesCount; i++)
				this->grades[i] = s.grades[i];
		}
		return *this;
	}

	string listDetails() {
		return "I'm a Student";
	}

	~Student() {

		// called by default
		//Person::~Person();
		if (this->grades != nullptr)
			delete[] this->grades;
	}
};


class Employees : public Person {

	string salary;
	string position;

public:
	string listDetails() {
		return "I'm an Employee";
	}
};


class Professor : public Person {

	string title = "";

public:
	Professor() {}

	Professor(string _name, Date _birthDate, string _pin, string* _addresses, int _addressCount, string _title)
		: Person(_name, _birthDate, _pin, _addresses, _addressCount), title(_title) {}

	string listDetails() {
		return "I'm a Professor.";
	}
};


class Admin :public Person {

	string area = "";

public:
	Admin() {}

	Admin(string _name, Date _birthDate, string _pin, string* _addresses, int _addressCount, string _area)
		: Person(_name, _birthDate, _pin, _addresses, _addressCount), area(_area) {}

	string listDetails() {
		return "I'm an Admin.";
	}
};


class University {

	string name = "";
	string city = "";
	Person** all = nullptr;
	int allCount = 0;

public:
	University() {}

	University(string _name, string _city) : name(_name), city(_city) {}

	void setAll(Person** _all, int _allCount) {

		this->allCount = _allCount;

		// !!!!! - we do this because we allocate it dynamically in main
		this->all = _all;
	}

	void listDetails() {
		for (int i = 0; i < this->allCount; i++)
			cout << endl << this->all[i]->listDetails() << endl;
	}
};


int main() {

	Date d(2, 2, 1990);
	string* addresses = new string[3];
	addresses[0] = "Bucuresti";
	addresses[1] = "Moara Vlasiei";
	addresses[2] = "Arad";
	Person p("Cristescu V", d, "43327bt871664", addresses, 3);

	double* grades = new double[5];
	grades[0] = 9;
	grades[1] = 10;
	grades[2] = 9;
	grades[3] = 8;
	grades[4] = 10;
	string* addresses2 = new string[2];
	addresses2[0] = "Brasov";
	addresses2[1] = "Gruiu";
	Date d2(5, 9, 2001);
	Student s("Popescu A", d2, "43327bt871664", addresses2, 2, 511003, grades, 5);

	Person* person = new Person("Person", d, "43327bt871664", addresses, 3);
	Person* student = new Student("Student", d2, "43327bt871664", addresses2, 2, 511003, grades, 5);
	Person* admin = new Admin("Admin", d, "1234567", addresses, 3, "Lab");
	Person* prof = new Professor("Professor", d2, "345678", addresses2, 2, "Conf");
	Person** all = new Person * [4];
	all[0] = person;
	all[1] = student;
	all[2] = admin;
	all[3] = prof;

	University univ("ASE", "Bucuresti");
	univ.setAll(all, 4);
	univ.listDetails();
}
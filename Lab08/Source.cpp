#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string grupa = "1234";
	int nr_matricol;
	int* note;
	int nr_note;
	char* adresa = nullptr;
	const int aniDeStudiu;
	static string universitate;

public:
	string nume;
	int varsta;

	Student() : aniDeStudiu(3)
	{
		nume = "anonim";
		varsta = 18;
		nr_matricol = 0;
		note = nullptr;
		nr_note = 0;
	}

	Student(string n, int v, string g, int aniDeStudiu) : note(nullptr), nr_note(0), aniDeStudiu(aniDeStudiu)
	{
		nume = n;
		grupa = g;
		if (v > 0)
		{
			varsta = v;
		}
		else
		{
			varsta = 18;
		}
	}

	Student(string nume, const char* adresa) :Student()
	{
		this->nume = nume;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	}

	Student(string nume, int* note, int nr_note) :Student()
	{
		this->nume = nume;
		if (note != nullptr && nr_note > 0)
		{
			this->nr_note = nr_note;
			this->note = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				this->note[i] = note[i];
			}
		}

	}

	Student(const Student& s) : aniDeStudiu(s.aniDeStudiu)
	{
		this->nume = s.nume;
		this->varsta = s.varsta;
		this->nr_matricol = s.nr_matricol;
		this->grupa = s.grupa;
		if (s.note != nullptr && s.nr_note != 0)
		{
			this->nr_note = s.nr_note;
			this->note = new int[s.nr_note];
			for (int i = 0; i < s.nr_note; i++)
			{
				this->note[i] = s.note[i];
			}
		}
		else
		{
			this->note = nullptr;
			this->nr_note = 0;
		}
		if (s.adresa != nullptr)
		{
			this->adresa = new char[strlen(s.adresa) + 1];
			strcpy_s(this->adresa, strlen(s.adresa) + 1, s.adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
	}

	Student& operator=(const Student& s)
	{
		if (note != nullptr)
		{
			delete[] note;
		}
		if (adresa != nullptr)
		{
			delete[] adresa;
		}
		this->nume = s.nume;
		this->varsta = s.varsta;
		this->nr_matricol = s.nr_matricol;
		this->grupa = s.grupa;
		if (s.note != nullptr && s.nr_note != 0)
		{
			this->nr_note = s.nr_note;
			this->note = new int[s.nr_note];
			for (int i = 0; i < s.nr_note; i++)
			{
				this->note[i] = s.note[i];
			}
		}
		else
		{
			this->note = nullptr;
			this->nr_note = 0;
		}
		if (s.adresa != nullptr)
		{
			this->adresa = new char[strlen(s.adresa) + 1];
			strcpy_s(this->adresa, strlen(s.adresa) + 1, s.adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
		return *this;
	}

	~Student()
	{
		if (note != nullptr)
		{
			delete[] note;
		}
		if (adresa != nullptr)
		{
			delete[] adresa;
		}
	}

	//operatorul de negatie
	bool operator!() {

		if (nr_note > 0) {
			double sum = 0;

			for (int i = 0; i < nr_note; i++)
				sum += note[i];

			if (sum / nr_note >= 5)
				return true;
		}
		return false;
	}

	/*
	bool operator!()
	{
		if (nr_note > 0)
		{
			for (int i = 0; i < nr_note; i++)
				note[i] = 10 - note[i];
			return true;
		}
		return false;
	}
	*/

	//operatorul de preincrementare
	/*
		Student operator++()
	{
		this->varsta++;
		return *this;
	}
	*/

	Student operator++()
	{
		for (int i = 0; i < nr_note; i++) {
			if (note[i] < 10) {
				note[i]++;
			}
			else {
				note[i] += 10 - note[i];
			}
		}
		return *this;
	}

	//operatorul de postincrementare
	/*	
	Student operator++(int)
	{
		Student copie = *this;
		this->varsta += 5;
		return copie;
	}
	*/

	Student operator++(int)
	{
		Student copie = *this;
		for (int i = 0; i < nr_note; i++) {
			if (note[i] < 10) {
				note[i]++;
			}
			else {
				note[i] += 10 - note[i];
			}
		}
		return copie;
	}

	//operator +
	Student operator+(int valoare)
	{
		Student copie = *this;
		copie.varsta += valoare;
		return copie;
	}

	//operator index cu rol de citire-scriere
	int& operator[](int index)
	{
		if (index >= 0 && index < nr_note)
		{
			return note[index];
		}
		throw exception("index invalid");
	}

	//operator de cast la int explicit
	explicit operator int()
	{
		return varsta;
	}

	//operator functie ce returneaza lungimea adresei
	int operator()()
	{
		if (adresa != nullptr)
		{
			return strlen(adresa);
		}
		else
		{
			return 0;
		}
	}

	string getGrupa()
	{
		return grupa;
	}

	int getMatricol()
	{
		return nr_matricol;
	}

	void setMatricol(int nr_matricol)
	{
		if (nr_matricol > 0)
		{
			this->nr_matricol = nr_matricol;
		}
	}

	int* getNote()
	{
		if (note != nullptr)
		{
			int* copie = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				copie[i] = note[i];

			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getNote(int index)
	{
		if (index >= 0 && index < nr_note && note != nullptr)
		{
			return note[index];
		}
	}

	int getNrNote()
	{
		return nr_note;
	}

	void setNote(int* note, int nr_note)
	{
		if (note != nullptr && nr_note != 0)
		{
			this->nr_note = nr_note;
			if (this->note != nullptr)
			{
				delete[] this->note;

			}
			this->note = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				this->note[i] = note[i];
			}
		}
	}


	static string getUniversitate()
	{
		return universitate;
	}

	static void setUniversitate(string universitate)
	{
		Student::universitate = universitate;
	}

	static float medieSerie(Student* studenti, int nrStudenti)
	{
		float suma = 0;
		int nr = 0;
		if (studenti != nullptr && nrStudenti > 0)
		{
			for (int i = 0; i < nrStudenti; i++)
			{
				if (studenti[i].note != nullptr)
				{
					for (int j = 0; j < studenti[i].nr_note; j++)
					{
						suma += studenti[i].note[j];
						nr++;
					}
				}
			}
			if (nr > 0)
			{
				return suma / nr;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}

	//friend functions are allowed to accesss private and protected members
	friend ostream& operator<<(ostream&, Student);
	friend istream& operator>>(istream&, Student&);
};
string Student::universitate = "ASE";

//a+b   and b+a
Student operator+(int valoare, Student s)
{
	s.varsta += valoare;
	return s;
}

//
ostream& operator<<(ostream& out, Student s)
{
	//out << "nume:" <<"#"<< s.nume << endl;
	//out << "varsta: " << -1 << endl;
	out << "nume: " << s.nume << endl;
	out << "varsta: " << s.varsta << endl;
	out << "matricol: " << s.nr_matricol << endl;
	out << "grupa: " << s.grupa << endl;
	out << "ani de studiu: " << s.aniDeStudiu << endl;
	out << "adresa: ";
	if (s.adresa != nullptr)
	{
		out << s.adresa;
	}
	out << endl;
	out << "numar note: " << s.nr_note << endl;
	out << "note: ";
	if (s.note != nullptr)
	{
		for (int i = 0; i < s.nr_note; i++)
		{
			out << s.note[i] << " ";
		}
	}
	return out;
}

//
istream& operator>>(istream& in, Student& s)
{
	cout << "nume = ";
	in >> s.nume;
	cout << "varsta = ";
	in >> s.varsta;
	cout << "numar matricol = ";
	in >> s.nr_matricol;
	cout << "grupa = ";
	in >> s.grupa;
	string buffer;
	cout << "adresa: ";
	in >> buffer;
	if (s.adresa != nullptr)
	{
		delete[] s.adresa;
	}
	s.adresa = new char[buffer.length() + 1];
	strcpy_s(s.adresa, buffer.length() + 1, buffer.c_str());
	cout << "numar note = ";
	in >> s.nr_note;
	if (s.note != nullptr)
	{
		delete[] s.note;
	}
	if (s.nr_note > 0)
	{
		s.note = new int[s.nr_note];
		for (int i = 0; i < s.nr_note; i++)
		{
			cout << "note[" << i << "] = ";
			in >> s.note[i];
		}
	}
	else
	{
		s.nr_note = 0;
		s.note = nullptr;
	}
	return in;
}

int main()
{
	Student s;
	s.nume = "Ion Popescu";
	cout << s.nume << endl;
	cout << s.varsta << endl;

	Student* ps;
	ps = &s;
	cout << (*ps).nume << endl;
	cout << ps->nume << endl;
	cout << sizeof(s) << endl;
	Student s2 = s;
	cout << sizeof(s2) << endl;

	ps = new Student();
	cout << ps->nume << endl;
	delete ps;

	Student s3("Maria Popescu", 20, "1050", 2);
	cout << s3.nume << endl;

	Student s4("Vasile Musat", "Str Ion Creanga, nr 8");
	cout << s4.nume << endl;

	Student vector[3];

	Student* ps2 = new Student("Marcel Ionascu", "Str Avionului, nr 4");
	cout << ps2->nume << endl;

	delete ps2;

	int note[] = { 7,4,9 };

	Student s5("Dan", note, 3);

	Student s6(s5);

	cout << s.getGrupa() << endl;

	s6.setMatricol(5);
	cout << s6.getMatricol() << endl;

	int z[] = { 1,2,3,4,5 };
	s6.setNote(z, 5);
	int* n = s6.getNote();

	bool res = !s6;

	for (int i = 0; i < s6.getNrNote(); i++)
	{
		cout << n[i] << " ";
	}
	cout << endl;

	delete[] n;
	n = nullptr;

	Student::setUniversitate("Politehnica");
	cout << s.getUniversitate() << endl;
	cout << s5.getUniversitate() << endl;
	cout << Student::getUniversitate() << endl;

	Student studenti[] = { s5, s6 };
	float medie = Student::medieSerie(studenti, 2);
	cout << medie << endl;

	//copy constr
	Student s7 = s5;
	//operator=
	s = s6;
	//operator= 
	s = s5 = s6;
	//
	bool areNote = !s5;
	cout << areNote << endl;
	//pre
	Student s8 = ++s5;
	//post
	Student s9 = s6++;

	//
	s8 = s5 + 7;
	//global +
	s9 = 3 + s5;

	cout << s5 << endl;
	Student s10;
	//
	cin >> s10;
	//
	cout << s10 << endl;
	//
	s5[1] = 10;
	//
	cout << s5[1] << endl;

	//cast op
	int varsta = (int)s9;
	cout << varsta << endl;
	//funct op
	cout << s10();
}
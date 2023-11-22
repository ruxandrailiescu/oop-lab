/*
Sa se implementeze o clasa Spital, conform urmatoarelor cerinte:
Clasa are cel putin urmatoarele atribute:
	* cif (cod identificare fiscala - valoare de tip sir de caractere - se atribuie valoare la crearea obiectului si apoi nu mai este modificata)
	* nume (sir de caractere)
	* adresa (sir de caractere)
	* medici (vector de valori string, alocat dinamic)
	* nrMedici
	* nrSpitale (va retine numarul de spitale - obiecte de tip Spital - instantiate vreodata - static int)

Se vor implementa:
- constructor fara parametri
- constructor cu toti parametrii necesari instantierii unui obiect complet
- constructor de copiere
- destructor

- supraincarcare operator=
- supraincarcare operatori de citire si scriere din/in consola (>> si <<)
- supraincarcare operator [] - returneaza medicul de pe o pozitie data - atat in mod scriere cat si in mod citire
- supr op !
- cast explicit int - returneaza numarul de spitale instantiate

- metode de get si set
- cel putin unul dintre atributele de tip sir de caractere trebuie sa fie de tip char*
- toate atributele trebuie sa fie private
*/

#include<iostream>
using namespace std;

class Spital {

	const string cif;
	char* nume;
	string adresa;
	string* medici;
	int nrMedici;
	static int nrSpitale;

public:

	Spital() : cif("") {

		this->nume = nullptr;
		this->adresa = "";
		this->medici = nullptr;
		this->nrMedici = 0;

		Spital::nrSpitale++;
	}

	Spital(string _cif, const char* _nume, string _adresa, const string* _medici, int _nrMedici) :cif(_cif), adresa(_adresa) {

		/*if (_nume != nullptr) {
			this->nume = new char[strlen(_nume) + 1];
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		}*/
		this->setNume(_nume);

		/*if ((_medici != nullptr) && (_nrMedici > 0)) {
			this->medici = new string[_nrMedici];
			for (int i = 0; i < _nrMedici; i++) {
				this->medici[i] = _medici[i];
			}
		}*/
		this->setMedici(_medici, _nrMedici);

		Spital::nrSpitale++;
	}

	Spital(const Spital& s) :Spital(s.cif, s.nume, s.adresa, s.medici, s.nrMedici) {
		
		Spital::nrSpitale++;
	}

	char* getNume() {

		if (this->nume != nullptr) {
			char* copy = new char[strlen(this->nume) + 1];
			strcpy_s(copy, strlen(this->nume) + 1, this->nume);
			return copy;
		}
		return nullptr;
	}

	void setNume(const char* _nume) {

		if (_nume != nullptr) {
			if (this->nume != nullptr)
				delete[] this->nume;

			this->nume = new char[strlen(_nume) + 1];
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		}
	}

	string* getMedici() {

		if (this->medici != nullptr) {
			string* copy = new string[this->nrMedici];
			for (int i = 0; i < this->nrMedici; i++) {
				copy[i] = this->medici[i];
			}
			return copy;
		}
		return nullptr;
	}

	int getNrMedici() {
		return this->nrMedici;
	}

	void setMedici(const string* _medici, int _nrMedici) {

		if ((_medici != nullptr) && (_nrMedici > 0)) {
			if (this->medici != nullptr)
				delete[] this->medici;
			this->medici = new string[_nrMedici];
			for (int i = 0; i < _nrMedici; i++) {
				this->medici[i] = _medici[i];
			}
			this->nrMedici = _nrMedici;
		}
	}

	Spital& operator=(const Spital& s) {

		if (this == &s)
			return *this;

		this->setNume(s.nume);
		this->setMedici(s.medici, s.nrMedici);
		this->adresa = s.adresa;

		return *this;
	}

	friend ostream& operator<<(ostream& out, const Spital& s);
	friend istream& operator>>(istream& in, Spital& s);

	bool operator!() {
		if (this->medici == nullptr) {
			return true;
		}
		return false;
	}

	explicit operator int() {
		return Spital::nrSpitale;
	}

	string operator[](int index) {

		if (index >= this->nrMedici) {
			return "Index out of bounds.";
		}
		return this->medici[index];
	}

	~Spital() {

		if (this->nume != nullptr) {
			delete[] this->nume;
		}

		if (this->medici != nullptr)
			delete[] this->medici;

		Spital::nrSpitale--;
	}

};

ostream& operator<<(ostream& out, const Spital& s) {

	out << endl << "CIF: " << s.cif;
	out << endl << "Nume: " << s.nume;
	out << endl << "Adresa: " << s.adresa;
	out << endl << "Nr medici: " << s.nrMedici;
	out << endl << "Medicii: ";
	for (int i = 0; i < s.nrMedici; i++) {
		out << endl << s.medici[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, Spital& s) {

	cout << endl << "Nume: ";
	char* temp = new char[256];
	in.getline(temp, 256);
	s.setNume(temp);

	delete[] temp;

	cout << endl << "Adresa: ";
	in.clear();
	in >> s.adresa;

	cout << endl << "Nr medici: ";
	int nr;
	in >> nr;
	string* temp1 = new string[nr];
	for (int i = 0; i < nr; i++) {
		cout << endl << "Medic " << i + 1 << ": ";
		in >> temp1[i];
	}
	s.setMedici(temp1, nr);

	delete[] temp1;
	return in;
	
}

int Spital::nrSpitale = 0;

int main() {

	Spital s;
	string* medici = new string[3];
	medici[0] = "Voicu";
	medici[1] = "Paraschiv";
	medici[2] = "Stan";
	Spital s1("RO12345", "Floreasca", "Bucuresti", medici, 3);

	//cout << endl << s1;

	s = s1;

	Spital s2;
	cin >> s2;

	//cout << endl<< (!s2);
	//cout << endl<< s1[1];
	//cout << endl<< (int)s1;

	int nr = s2.getNrMedici();
	string* medici1 = new string[nr];
	medici1 = s2.getMedici();
	for (int i = 0; i < nr; i++) {
		cout << endl << medici1[i] << " ";
	}

	//cout << endl<< s1.getNume();
	//s2.setNume("Medlife");
	//s2.setMedici(medici, 3);
	//cin >> s1[1];

	delete[] medici;
	delete[] medici1;
}
#include <iostream>
#include <string>

using namespace std;

enum finantare
{
	UNSPECIFIED = 0,
	TAXA = 1,
	BUGET = 2,
	BUGET_BURSA = 3
};


class Student
{

	int* note;
	string numar_matricol;
	finantare tip_finantare;
	int numar_materii;
	string nume;
	char* adresa;
	int varsta;
	int an_studii;

public:

	//constructori
	Student()
	{
		this->note = nullptr;
		this->adresa = nullptr;
		this->nume = "";
		this->varsta = -1;
		this->numar_matricol = "";
		this->tip_finantare = finantare::UNSPECIFIED;
		this->numar_materii = -1;
		this->an_studii = -1;

	}

	Student(string _nume, char* _adresa, int _varsta, int _an_studii, int* _note, int _numar_materii, string _numar_matricol, finantare _finantare) 
	//	: nume(_nume), varsta(_varsta), an_studii(_an_studii), numar_matricol(_numar_matricol), numar_materii(_numar_materii)
	{

		this->set_nume(_nume);

		//care este diferenta?
		// 
		//this->adresa = _adresa;

		this->set_adresa(_adresa);
		/*
		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);
		*/

		this->set_varsta(_varsta);
		this->set_an_studii(_an_studii);

		this->set_note(_note, _numar_materii);
		//this->note = new int[_numar_materii];
		//for (int index = 0; index < _numar_materii; index++)
		//{
		//	this->note[index] = _note[index];
		//}

		this->set_numar_matricol(_numar_matricol);
		this->set_finantare(_finantare);
	}

	// Implementarea constructorului de copiere va rezolva problema care genereaza exceptiile lansate la executia destructorului - incercarea de a 
				//dezaloca a doua oara aceeasi zona de memorie care a fost anterior dezalocata
	// Aceasta implementare apeleaza constructorul cu parametri. In cadrul constructorului cu parametri alocarea memoriei este facuta corect pentru cele doua variabile membre de tip pointer

	/*
	Student(const Student& student):
		Student(student.nume, student.adresa, student.varsta, student.an_studii, student.note, student.numar_materii, student.numar_matricol, student.finantare)
	{

	}
	*/

   //Sa se implementeze constructorul de copiere fara a apela constructorul cu parametri astfel incat:
   //				- copierea valorilor (in noul obiect) sa se realizeze corect  
   //              - dezalocarea memoriei sa se realizeze fara a genera exceptii

   
   Student(const Student& student)
   {
	   this->note = nullptr;
	   this->adresa = nullptr;

	   this->set_nume(student.nume);
	   this->set_varsta(student.varsta);
	   this->set_an_studii(student.an_studii);
	   this->set_finantare(student.tip_finantare);
	   this->set_numar_matricol(student.numar_matricol);

	   if (student.note != nullptr) {
		   this->note = new int[student.numar_materii];
		   for (int i = 0; i < student.numar_materii; i++) {
			   this->note[i] = student.note[i];
		   }
	   }

	   if (student.adresa != nullptr) {
		   this->adresa = new char[strlen(student.adresa) + 1];
		   strcpy_s(this->adresa, strlen(student.adresa) + 1, student.adresa);
	   }

   }
   

   //setters
	void set_note(int* _note, int _numar_materii)
	{
		this->numar_materii = _numar_materii;
		//this->note = _note;

		if (this->note != nullptr) {
			delete[] this->note;		//delete this->note - we only deallocate space for one int
		}

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	void set_numar_matricol(string _nr_matricol)
	{
		this->numar_matricol = _nr_matricol;
	}

	void set_finantare(finantare _finantare)
	{
		this->tip_finantare = _finantare;
	}

	void set_adresa(char* _adresa) {

		if (this->adresa != nullptr) {
			delete[] this->adresa;
		}

		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);
	}

	void set_nume(string _nume) {

		this->nume = _nume;
	}

	void set_varsta(int _varsta) {

		if (_varsta >= 5 && _varsta <= 100) {
			this->varsta = _varsta;
		}
	}

	void set_an_studii(int _an_studii) {

		if (_an_studii >= 1 && _an_studii <= 3) {
			this->an_studii = _an_studii;
		}
	}


	//getters
	int* get_note() {

		if (this->note == nullptr) {
			return nullptr;
		}

		int* copy = new int[this->numar_materii];
		
		for (int i = 0; i < this->numar_materii; i++) {
			copy[i] = this->note[i];
		}

		return copy;			// memory must be deallocated outside function, after completion of scope
	}

	char* get_adresa() {

		if (this->adresa == nullptr) {
			return nullptr;
		}

		char* copy = new char[strlen(this->adresa) + 1];
		strcpy_s(copy, strlen(this->adresa) + 1, this->adresa);

		return copy;			// memory must be deallocated outside function, after completion of scope
	}

	string get_numar_matricol() { return this->numar_matricol; }
	finantare get_finantare() { return this->tip_finantare; }
//	int get_numar_materii() { return this->numar_materii; }		// not necessary - length of note
	string get_nume() { return this->nume; }
	int get_varsta() { return this->varsta; }
	int get_an_studii() { return this->an_studii; }


	//destructor
	~Student()
	{
		delete[] this->adresa;
		delete[] this->note;
	}

};


//exemple vizibilitate - constructori/destructori/metode/atribute
//exemplu constructor de copiere

int main()
{
	int note[10] = { 9,10,10,10,8,9,10,10,10,10 };

	Student s0("Jane Doe", (char*)"Bucuresti, Sector 1", 21, 2, note, 10, "S111111", finantare::UNSPECIFIED);
	Student s1 = s0;

	//s0.set_nume("Anghel Mihai");

	//s0.set_adresa((char*)"Bucuresti, Sector 1");

	//s0.set_varsta(21);
	//s0.set_an_studii(2);

	////de ce este generata eroarea?
	////s0.note = new int[20];

	//s0.set_numar_matricol("A689867");
	//s0.set_finantare(finantare::BUGET_BURSA);

	//// discutie eroare invalid heap pointer
	//int note[10] = { 9,10,10,10,8,9,7,10,5,10 };
	//s0.set_note(note, 10);


	//Student s1 = Student("Popescu I", (char*)"Bucuresti, Sector 1", 21, 2, note, 10, "A689867", finantare::BUGET_BURSA);

	//Student s2 = s1;
	//s2.nume = "Ionescu C";
}

// All getters & setters for Student class implemented in Lab04/Source.cpp
// 
// Lab06/Source.cpp - focus on Book class & its public interface (accessor methods) implemented in class  

#include <iostream>
#include <string>

using namespace std;

enum finantare
{
	TAXA = 1,
	BUGET = 2,
	BUGET_BURSA = 3
};

class Book {

	char* author;
	char* title;
	int pages_no;
	int* page_words_count;
	bool online;

public:

	Book(char* _author, char* _title, int _pages_no, int* _pages_words_count, bool _online) : pages_no(_pages_no), online(_online) {

		this->set_author(_author);
		this->set_title(_title);
//		this->set_pages_no(_pages_no);
		this->set_page_words_count(_pages_words_count);
//		this->set_online(_online);
	}

	Book(const Book& book) :
		Book(book.author, book.title, book.pages_no, book.page_words_count, book.online) {

	}

	char* get_author() {

		if (this->author == nullptr) {
			return nullptr;
		}

		char* copy = new char[strlen(this->author) + 1];
		strcpy_s(copy, strlen(this->author) + 1, this->author);
		return copy;
	}

	char* get_title() {

		if (this->title == nullptr) {
			return nullptr;
		}

		char* copy = new char[strlen(this->title) + 1];
		strcpy_s(copy, strlen(this->title) + 1, this->title);
		return copy;
	}

	int get_pages() {

		return this->pages_no;
	}

	int* get_page_words_count() {

		if (this->page_words_count == nullptr) {
			return nullptr;
		}

		int* copy = new int[this->pages_no];
		for (int i = 0; i < this->pages_no; i++) {
			copy[i] = this->page_words_count[i];
		}

		return copy;
	}

	bool is_online() {

		return this->online;
	}

	void set_author(char* _author) {

		if (this->author != nullptr) {
			delete[] this->author;
		}

		this->author = new char[strlen(_author) + 1];
		strcpy_s(this->author, strlen(_author) + 1, _author);
	}

	void set_title(char* _title) {

		if (this->title != nullptr) {
			delete[] this->title;
		}

		this->title = new char[strlen(_title) + 1];
		strcpy_s(this->title, strlen(_title) + 1, _title);
	}

	void set_pages_no(int _pages_no) {

		this->pages_no = _pages_no;
	}

	void set_page_words_count(int* _page_words_count) {

		if (this->page_words_count != nullptr) {
			delete[] this->page_words_count;
		}

		this->page_words_count = new int[this->pages_no];
		for (int i = 0; i < this->pages_no; i++) {
			this->page_words_count[i] = _page_words_count[i];
		}
	}

	void set_online(bool _online) {

		if (_online) {
			this->online = true;
		}
		else {
			this->online = false;
		}
	}

	~Book() {
		delete[] this->author;
		delete[] this->title;
		delete[] this->page_words_count;
	}
};



class Student
{
public:
	string nume;
	char* adresa;
	int varsta;
	int an_studii;

	//constructori
	Student()
	{

	}

	Student(string _nume, char* _adresa, int _varsta, int _an_studii, int* _note, int _numar_materii, string _numar_matricol, finantare _finantare) :
		nume(_nume), varsta(_varsta), an_studii(_an_studii), numar_matricol(_numar_matricol), finantare(_finantare), numar_materii(_numar_materii)
	{
		//care este diferenta?
		// 
		//this->adresa = _adresa;

		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	// Implementarea constructorului de copiere va rezolva problema care genereaza exceptiile lansate la executia destructorului - incercarea de a 
				//dezaloca a doua oara aceeasi zona de memorie care a fost anterior dezalocata
	// Aceasta implementare apeleazza constructorul cu parametri. In cadrul constructorului cu parametri alocarea memoriei este facuta corect pentru cele doua variabile membre de tip pointer


	/*Student(const Student& student):
		Student(student.nume, student.adresa, student.varsta, student.an_studii, student.note, student.numar_materii, student.numar_matricol, student.finantare)
	{

	}*/


	//Sa se implementeze constructorul de copiere fara a apela constructorul cu parametri astfel incat:
   //				- copierea valorilor (in noul obiect) sa se realizeze corect  
   //              - dezalocarea memoriei sa se realizeze fara a genera exceptii


	Student(const Student& student)
	{
		this->nume = student.nume;
		this->set_finantare(student.finantare);
		this->set_note(student.note, student.numar_materii);
		this->set_numar_matricol(student.numar_matricol);

		this->varsta = student.varsta;
		this->an_studii = student.an_studii;

		this->adresa = new char[strlen(student.adresa) + 1];
		strcpy_s(this->adresa, strlen(student.adresa) + 1, student.adresa);

	}


	//setters
	void set_note(int* _note, int _numar_materii)
	{
		this->numar_materii = _numar_materii;
		//this->note = _note;

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
		this->finantare = _finantare;
	}


	//getters
	int* get_note() { return this->note; }
	string get_numar_matricol() { return this->numar_matricol; }
	finantare get_finantare() { return this->finantare; }
	int get_numar_materii() { return this->numar_materii; }


	//destructor
	~Student()
	{
		delete[] this->adresa;
		delete[] this->note;
	}

private:
	int* note;
	string numar_matricol;
	finantare finantare;
	int numar_materii;

};


//exemple vizibilitate - constructori/destructori/metode/atribute
//exemplu constructor de copiere

int main()
{
	int* pages = new int[2];
	Book b0((char*)"Eminescu", (char*)"Luceafarul", 2, pages, true);
	Book b1 = b0;

	delete[] pages;

	//Student s0;

	//s0.nume = "Anghel Mihai";

	//s0.adresa = new char[20];
	//strcpy_s(s0.adresa, 20, "Bucuresti, Sector 1");

	//s0.varsta = 21;
	//s0.an_studii = 2;

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
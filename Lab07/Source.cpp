#include <iostream>
#include<cassert>
using namespace std;

class Fractie
{
private:
    int m_numarator{ 0 };
    int m_numitor{ 1 };
    static int count;

public:
    // static int x;

    // Default constructor
    Fractie(int numarator = 0, int numitor = 1)
        : m_numarator(numarator), m_numitor(numitor)
    {
        assert(numitor != 0);
        Fractie::count++;
    }

    // Copy constructor
    Fractie(const Fractie& copy)
        : m_numarator{ copy.m_numarator }, m_numitor{ copy.m_numitor }
    {
        // nu mai este nevoie de verificarea numitorului pentru ca operatiile se fac asupra a doua obiecte existente - au fost verificate in cadrul constructorului
        cout << "S-a apelat constructorul de copiere.\n";
        Fractie::count++;
    }


    // Supraincarcarea operatorului de atribuire: =
//    Fractie& operator= (const Fractie& fractie);
//    void operator= (const Fractie& fractie);

//    Fractie& operator= (const Fractie& fractie) = delete; // nu se permite efectuarea copiilor prin asignare!

    Fractie& operator= (const Fractie& fractie);

    /*  
    void set_x(int _x) {
          this->x = _x;
    }
    */

    static void set_count(int _count) {

        Fractie::count = _count;
    }
};

int Fractie::count = 0;
// O alta implementare => void??

//void Fractie::operator= (const Fractie& fractie)
//{
//    // se evita autoasignarea - !!! see for pointers
//    if (this == &fractie)
//        return;
//
//    m_numarator = fractie.m_numarator;
//    m_numitor = fractie.m_numitor;
//
//
//    return;
//}


// O implementare mai buna - corecta => discutie
// why Fractie& and not Fractie - we would create unnecessary duplicates

Fractie& Fractie::operator= (const Fractie& fractie)
{
    // se evita autoasignarea
    if (this == &fractie)
        return *this;

    m_numarator = fractie.m_numarator;
    m_numitor = fractie.m_numitor;


    return *this;
}




int main()
{
    Fractie fff(1, 2);
    Fractie fff1;
    fff1 = fff;

    Fractie fff2 = fff;

    Fractie::set_count(4);

    //    Fractie::x = 1;
    //    cout << endl << Fractie::x << endl;
    //    fff.set_x(2);

    Fractie _5p3{ 5, 3 };
    Fractie f = _5p3;
//    Fractie::x = 3;
    Fractie ff;      //cine se apeleaza?
    ff = _5p3; //cine se apeleaza?

    Fractie f1(3, 5);       //Fractie f1{3, 5};
    Fractie f2(2, 4);       //Fractie f2{2, 4};
    Fractie f3(1, 3);       //Fractie f3{1, 3};

    f1 = f2 = f3; //asignare inlantuita
    //  f1 = f2;// = f3; //asignare inlantuita
    //
    //  f1 = f1; // autoasignare
    //
    //
    //  return 0;
}
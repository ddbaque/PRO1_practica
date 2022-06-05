#include "Entrada.hpp"

//------CONSTRUCTORS-----

// Pre:
// Post: Crea una entrada buida.
Entrada::Entrada()
{
    simbol = 0;
    codificacio = "";
    frequencia = 0;
}

// Pre:  f > 0
// Post: Crea una entrada de símbol c i freqüència f sense codi Huffman.
Entrada::Entrada(char c, double f)
{
    simbol = c;
    frequencia = f;
    codificacio = "";
}

// Pre:
// Post: Crea una entrada amb els valors de l'entrada e.
Entrada::Entrada(const Entrada &e)
{
    simbol = e.simbol;
    frequencia = e.frequencia;
}

// Pre:
// Post: Crea una entrada amb els valors de l'entrada e.
Entrada &Entrada::operator=(const Entrada &e)
{
    this->simbol = e.simbol;
    this->frequencia = e.frequencia;
    return *this;
}

//------DESTRUCTOR-----

// Post: Esborra automàticament els objectes locals en sortir d'un
//       àmbit de visibilitat.
Entrada::~Entrada()
{
}

//------MODIFICADORS-----

// Pre:  f > 0
// Post: La freqüència de l'entrada p.i. passa a ser f.
void Entrada::setFrequencia(double f)
{
    frequencia = f;
}

// Pre:
// Post: El codi Huffman de l'entrada p.i. passa a ser co.
void Entrada::setCodificacio(string co)
{
    codificacio = co;
}

// Consultors

// Pre:
// Post: El resultat és el símbol de l'entrada p.i.
char Entrada::getSimbol() const
{
    return simbol;
}

// Pre:
// Post: El resultat és la freqüència de l'entrada p.i.
double Entrada::getFrequencia() const
{
    return frequencia;
}

// Pre:
// Post: El resultat és el codi Huffman de l'entrada p.i.
string Entrada::getCodificacio() const
{
    return codificacio;
}

// Pre:
// Post: El resultat indica si la freqüència de l'entrada p.i.
//       és estrictament menor que la freqüència de l'entrada e.
bool Entrada::operator<(const Entrada &e) const
{
    return frequencia < e.frequencia;
}

//------ESCRIPTURA-----

// Pre:
// Post: S'han escrit els atributs de l'entrada e al canal
//       estàndard de sortida.
ostream &operator<<(ostream &os, const Entrada &e)
{
    os << "Simbol:" << e.getSimbol();
    os << ", Frequencia: " << e.getFrequencia();
    os << ", Codificacio: " << e.getCodificacio();
    return os;
}
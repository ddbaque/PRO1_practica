#include "TaulaFreq.hpp"

// Pre:
// Post: Crea una taula de freqüències buida.
TaulaFreq::TaulaFreq()
{
}

// Consultors

// Pre:
// Post: El resultat és el nombre d'elements de la taula p.i.
int TaulaFreq::mida() const
{
    return m.size();
}

// Pre:
// Post: El resultat és la llista d'entrades
list<Entrada> &TaulaFreq::getList()
{
    return m;
}

// Modificadors

// Pre:
// Post: Omple la taula p.i. a partir dels caràcters de text.
void TaulaFreq::construirTaula(string text)
{
    int s = text.size();
    map<char, double> dicc;

    /* Inv: cada elemet i-êsim té una frequecia asociada */
    for (int i = 0; i < s; i++)
    {
        if (dicc[text[i]] < 1) // si és la primera vegada que apareix
        {
            Entrada e(text[i], 0);
            afegirEntrada(e);
            dicc[text[i]]++;
        }
        else // cas contrari
        {
            dicc[text[i]]++;
        }
    }
    auto iter = m.begin();
    /* Inv: iter = "cada element de la llista", cada element iter-i-êsim hi serà modificada la seva freqüència */
    while (iter != m.end())
    {
        double freq = dicc[(*iter).getSimbol()] / text.size();
        (*iter).setFrequencia(freq);
        ++iter;
    }
}

// Pre:
// Post: Afegeix l'entrada e al final de la taula p.i.
void TaulaFreq::afegirEntrada(const Entrada &e)
{
    m.push_back(e);
}

// Pre:
// Post: S'ha mostrat pel canal estàndard de sortida el contingut
//       de la taula p.i.
void TaulaFreq::mostrarTaula() const
{
    auto iter = m.begin();
    int i = 0;
    cout << "\n Bolcat taula frequencies ---->" << endl;
    cout << "\n Mida: " << m.size() << " simbols" << endl;
    /* Inv: mentres l'iterador no arribi a l'últim element de la llista m s'escriurà pel canal de sortida l'element que està senyalant l'iterador.*/
    while (iter != m.end())
    {
        cout << "Entrada " << i << ". ";
        cout << *iter << endl;
        ++iter;
        i++;
    }
    cout << "----> Fi bolcat taula" << endl;
    cout << endl;
}

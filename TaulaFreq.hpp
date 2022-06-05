#ifndef TAULAFREQ_HPP
#define TAULAFREQ_HPP

#include "Entrada.hpp"
#include <list>
#include <map>

using namespace std;

class TaulaFreq
{
	// Tipus de mòdul: dades
	// Descripció del tipus: Taula de símbols i freqüències per la codificació Huffman.

private:
	list<Entrada> m;

	// COMPLETEU
public:
	// Constructors

	// Pre:
	// Post: Crea una taula de freqüències buida.
	TaulaFreq();

	// Consultors

	// Pre:
	// Post: El resultat és el nombre d'elements de la taula p.i.
	int mida() const;

	// Pre:
	// Post: El resultat és la llista d'entrades
	list<Entrada> &getList();

	// Modificadors

	// Pre:
	// Post: Omple la taula p.i. a partir dels caràcters de text.
	void construirTaula(string text);

	// Pre:
	// Post: Afegeix l'entrada e al final de la taula p.i.
	void afegirEntrada(const Entrada &e);

	// Escriptura

	// Pre:
	// Post: S'ha mostrat pel canal estàndard de sortida el contingut
	//       de la taula p.i.
	void mostrarTaula() const;
};

#endif
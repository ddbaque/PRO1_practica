#include "Huffman.hpp"

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	TaulaFreq table;
	table.construirTaula(s);

	Huffman codif(table);
	string codificaciofinal = codif.codificar(s);
	codif.mostrarCodis();

	cout << " Missatge d'entrada (com a string):" << endl;
	cout << s << endl;
	cout << " Missatge codificat (com a string):" << endl;
	cout << codificaciofinal << endl;
}

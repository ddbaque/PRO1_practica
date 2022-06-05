#include "Huffman.hpp"

// Constructors

// Pre:  tf = TF
// Post: Crea una codificació Huffman buida a partir de la taula de freqüències
//       TF on només hi ha els símbols i la seva freqüència.
Huffman::Huffman(const TaulaFreq &tf)
{
    table = tf;
}
// Consultors

// Pre:
// Post: El resultat és la traducció del text d'entrada a un text
//       amb la codificació Huffman ((string de 0 i 1)
string Huffman::codificar(const string &textE)
{
    inserirCodis();
    string text = "";
    int s = (int)textE.size();

    for (int i = 0; i < s; i++)
    {
        // Inv: tot caracter i-esim hi es dins del map dicc[]
        text += dicc[textE[i]];
    }
    return text;
}

// Pre: una queue no buida
// Post: una cua amb un sol element, que representa l'arbre Huffman
void crearArbre(Queue<BTe> &q)
{
    if (q.size() != 1) // hi ha un sol element a la cua, per tant el nostre arbre està creat al 100%.
    {
        BTe front1, front2;
        front1 = q.front();
        q.pop();
        front2 = q.front();
        q.pop();
        Entrada e(0, front1.getRoot().getFrequencia() + front2.getRoot().getFrequencia());
        BTe aux(e, front1, front2);
        q.push(aux);
        crearArbre(q);
        /* HI: q es el nombre d'arbres on la seva arrel es un objecte de la classe Entrada, cada vegada amb un element menys */
        /* Fita: nombre d'elements de q, de dos en dos, fins a 1*/
    }
}

// Pre: bt és un arbre binari no buit
// Post: un map on cada caràcter queda codificat, per Huffman
void codifiHT(const BTe &bt, map<char, string> &m, string s)
{
    if (bt.getRoot().getSimbol() != 0) // el simbol de l'entrada es un caràcter no buit, per tant és pot associar una codificació Huffman
    {
        m[bt.getRoot().getSimbol()] = s;
    }
    else // cas contrari
    {
        codifiHT(bt.getLeft(), m, s + "0");
        /* HI: m conté la coficació Huffman del caràcters no buits del fill esquerra de l'arbre */
        /* Fita: nombre de nodes de l'arbre */

        codifiHT(bt.getRight(), m, s + "1");
        /* HI: m conté la coficació Huffman del caràcters no buits del fill dret de l'arbre*/
        /* Fita: nombre de nodes de l'arbre */
    }
}

// Pre:
// Post: Calcula la codificació Huffman (els codis de Huffman per cada símbol
//       segons la freqüència de cadascun d'ells).
void Huffman::inserirCodis()
{
    Queue<BTe> q;
    list<Entrada> &gtable = table.getList();
    auto iter = gtable.begin();
    while (iter != gtable.end())
    {
        BTe bt(*iter, BTe(), BTe());
        q.push(bt);
        ++iter;
    }
    crearArbre(q); /* crida incial */
    string s = "";
    BTe Huffman_tree = q.front();
    if (Huffman_tree.getLeft().isEmpty() and Huffman_tree.getRight().isEmpty()) // si l'arbre només té un node
    {
        dicc[Huffman_tree.getRoot().getSimbol()] = "0";
    }
    else // cas contrari
    {
        codifiHT(q.front(), this->dicc, s); /* crida inicial */
    }
}

// Pre:
// Post: S'ha mostrat pel canal estàndard de sortida el contingut
//       de la TaulaFreq del p.i., amb els símbols, freqüències i
//       codis Huffman.
void Huffman::mostrarCodis()
{
    list<Entrada> &gtable = table.getList();
    auto it = gtable.begin();
    /* Inv: it = "direcció on es troba cada element de table.getList()" */
    while (it != gtable.end())
    {
        it->setCodificacio(dicc[it->getSimbol()]);
        ++it;
    }
    table.mostrarTaula();
}
#include <vector>

using namespace std;

/**
 * @brief Funcao que que procura um elemento do tipo Comparable num vetor de Comparable's.
 * E necessario fazer o overloading do operador == para a classe que e usada como comparable
 *
 * @param v Vetor onde vamos procurar o elemento
 * @param x Elemento a procurar no vetor
 *
 * @return Posicao no vetor se encontrou, ou -1 se nao encontrou
 */
template <class Comparable>
int sequentialSearch(const vector<Comparable> &v, Comparable x)
{
	for (unsigned int i = 0; i < v.size(); i++){
		if (v[i] == x)
			return i;   // encontrou
	}
	return -1;     // nao encontrou
}

/**
 * @brief Funcao que que procura um elemento do tipo Comparable num vetor de Comparable's.
 * E igual ao sequentialSearch com o pequeno pormenor de procurar elementos do tipo pointer num vetor de pointers.
 * E necessario fazer o overloading do operador == para a classe que e usada como comparable
 *
 * @param v Vetor onde vamos procurar o elemento
 * @param x Elemento a procurar no vetor
 *
 * @return Posicao no vetor se encontrou, ou -1 se nao encontrou
 */
template <class Comparable>
int pointerSequentialSearch(const vector<Comparable*> v, Comparable *x)
{
	for (unsigned int i = 0; i < v.size(); i++) {
		if (*v[i] == *x)
			return i;   // encontrou
	}
	return -1;     // nao encontrou
}

/**
 * @brief Funcao que ordena um vetor do tipo Comparable.
 * E necessario fazer o overloading do operador<
 *
 * @param v Vetor que vai ser ordenado.
 */
template <class Comparable>
void insertionSort(vector<Comparable> &v)
{
	for (unsigned int p = 1; p < v.size(); p++){
		Comparable tmp = v[p];
		int j;
		for (j = p; j > 0 && tmp < v[j - 1]; j--)
			v[j] = v[j - 1];
		v[j] = tmp;
	}
}

/**
 * @brief Funcao que elimina elementos repetidos de um vetor.
 * E necessario fazer o overloading do operator==
 *
 * @param v Vetor que vai sofrer as alteracoes.
 */
template<class Comparable>
void eliminaRepetidos(vector<Comparable *> &v)
{
	int size = v.size();
	for (unsigned int i = 0; i < size - 1; i++) //dá o elemento
		for (unsigned int j = i + 1; j < size; j++) //percorre o vetor
			if (v.at(i) == v.at(j)){
				v.erase(v.begin() + j);
				size--;
				j--;
			}
}

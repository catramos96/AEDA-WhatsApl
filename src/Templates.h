#include <vector>

using namespace std;

template <class Comparable>
int sequentialSearch(const vector<Comparable> &v, Comparable x)
{
	for (unsigned int i = 0; i < v.size(); i++){
		if (v[i] == x)
			return i;   // encontrou
	}
	return -1;     // nao encontrou
}

template <class Comparable>
int pointerSequentialSearch(const vector<Comparable*> v, Comparable *x)
{
	for (unsigned int i = 0; i < v.size(); i++) {
		if (*v[i] == *x)
			return i;   // encontrou
	}
	return -1;     // nao encontrou
}

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

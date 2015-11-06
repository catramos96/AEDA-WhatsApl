#include <vector>

using namespace std;

template <class Comparable>
int sequentialSearch(const vector<Comparable> v, Comparable x)
{
	for (unsigned int i = 0; i < v.size(); i++){
		if (v[i] == x)
			return i;   // encontrou
	}
	return -1;     // nao encontrou
}

<<<<<<< HEAD
=======
template <class Comparable>
int pointerSequentialSearch(const vector<Comparable*> v, Comparable *x)
{
  for (unsigned int i = 0; i < v.size(); i++) {
    if (*v[i] == *x)
      return i;   // encontrou
  }
  return -1;     // nao encontrou
}

template <class T>
void insertionSort(vector<T> &v)
{
	for (unsigned int p = 1; p < v.size(); p++){
		T tmp = v[p];
		int j;
		for (j = p; j > 0 && tmp < v[j - 1]; j--)
			v[j] = v[j - 1];
		v[j] = tmp;
	}
}
/*
>>>>>>> f5a603996ce0c360e6acbad41c2ded9a73aa3ee0
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

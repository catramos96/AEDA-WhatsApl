#include <vector>
using namespace std;

template <class Comparable>
int sequentialSearch(const vector<Comparable> &v, Comparable x)
{
	for (unsigned int i = 0; i < v.size(); i++){
		if (*v[i] == *x)
			return i;   // encontrou
	}
	return -1;     // não encontrou
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

/************************************
*	    	    EXCECAO MAIN        		*
***********************************/
template <class N>
class OpccaoInvalida {
public:
  OpccaoInvalida(N op, N min, N max) { this->op = op; this->min = min; this->max = max; };
  getMin() const { return min; };
  getMax() const { return max; };
  getOp() const { return op; };
private:
  N op;
  N min;
  N max;
};
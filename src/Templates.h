#include <vector>

template <class T>
int BinarySearch(const vector<T> &v, T x)
{
	int left = 0, right = v.size()-1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (v[middle] < x)
			left = middle + 1;
		else if (x < v[middle])
			right = middle-1;
		else
			return middle; // encontrou
	}
	return - 1; // não encontrou
}
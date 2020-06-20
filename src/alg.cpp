#include <iostream>
#include <vector>

using namespace std;

int cBinSearch(const vector<int> &a, const int value) {
	int lp = 0;
	int rp = a.size() - 2;
	int mp = (lp + rp) / 2;

	int low = -1;
	int high = a.size() - 1;

	// Search low pair
	if (a[0] != value) {
		while (lp <= rp) {
			if (a[mp] < value and a[mp + 1] == value) {
				low = mp;
				break;
			} else if ((a[mp] == value and a[mp + 1] == value)
					or a[mp] > value) {
				rp = mp - 1;
				mp = (rp + lp) / 2;
			} else {
				lp = mp + 1;
				mp = (rp + lp) / 2;
			}
		}
		// Nonexistent value
		if (low == -1) {

			return 0;
		}
	}

	lp = 0;
	rp = a.size() - 2;
	mp = (lp + rp) / 2;

	// Search high pair
	if (a.back() != value) {
		while (lp <= rp) {
			if (a[mp] == value and a[mp + 1] > value) {
				high = mp;

				break;
			} else if ((a[mp] == value and a[mp + 1] == value)
					or a[mp] < value) {
				lp = mp + 1;
				mp = (rp + lp) / 2;
			} else {
				rp = mp - 1;
				mp = (rp + lp) / 2;
			}
		}
	}

	return high - low;
}

int cbinsearch(int *arr, int size, int value) {
	vector<int> v;
	copy(arr, arr + size, back_inserter(v));

	return cBinSearch(v, value);
}

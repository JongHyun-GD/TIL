#include <iostream>
#include <vector>

using namespace std;

const int HEAPSIZE = 200010;
const unsigned int INIT_VALUE = 2147483650;

class MinHeap {
	public:
		void init();
		unsigned int pop();
		void push(unsigned int value);
	private:
		vector<unsigned int> arr;
		int size;
		void swap(int ai, int bi);
};

void MinHeap::init() {
	size = 0;
	arr = vector<unsigned int> (HEAPSIZE, INIT_VALUE);
}

void MinHeap::swap(int ai, int bi) {
	// cout << ai << " " << bi << endl;
	unsigned int temp = arr[ai];
	arr[ai] = arr[bi];
	arr[bi] = temp;
}

unsigned int MinHeap::pop() {
	if (size == 0) return 0;
	unsigned int topValue = arr[1];
	arr[1] = arr[size];
	arr[size] = INIT_VALUE;
	size--;

	// find right place
	int ci = 1, ri = ci * 2 + 1, li = ci * 2;
	while (arr[ci] > arr[li] || arr[ci] > arr[ri]) {
		if (arr[li] < arr[ri]) {
			swap(ci, li);
			ci = li;
		}
		else {
			swap(ci, ri);
			ci = ri;
		}
		ri = ci * 2 + 1, li = ci * 2;
	}

	return topValue;
}

void MinHeap::push(unsigned int value) {
	size++;
	arr[size] = value;
	int ci = size;

	int pi = ci / 2;
	while (arr[ci] < arr[pi] && arr[pi] < INIT_VALUE) {
		swap(ci, pi);
		ci = pi;
		pi = ci / 2;
	}
}



int main() {
	cin.tie(0);
	MinHeap heap; heap.init();

	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		unsigned int input; cin >> input;

		if (input > 0) {
			heap.push(input);
		} else {
			cout << heap.pop() << "\n";
		}
	}

	return 0;
}

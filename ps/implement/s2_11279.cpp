#include <iostream>

using namespace std;

const int HEAPSIZE = 200010;

class MaxHeap {
	public:
		void init();
		unsigned int pop();
		void push(unsigned int value);
	private:
		unsigned int arr[HEAPSIZE];
		int size;
		void swap(int ai, int bi);
};

void MaxHeap::init() {
	size = 0;
}

void MaxHeap::swap(int ai, int bi) {
	// cout << ai << " " << bi << endl;
	unsigned int temp = arr[ai];
	arr[ai] = arr[bi];
	arr[bi] = temp;
}

unsigned int MaxHeap::pop() {
	if (size == 0) return 0;
	unsigned int topValue = arr[1];
	arr[1] = arr[size];
	arr[size] = 0;
	size--;

	// find right place
	int ci = 1, ri = ci * 2 + 1, li = ci * 2;
	while (arr[ci] < arr[li] || arr[ci] < arr[ri]) {
		if (arr[li] > arr[ri]) {
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

void MaxHeap::push(unsigned int value) {
	size++;
	arr[size] = value;
	int ci = size;

	int pi = ci / 2;
	while (arr[ci] > arr[pi] && arr[pi] > 0) {
		swap(ci, pi);
		ci = pi;
		pi = ci / 2;
	}
}



int main() {
	cin.tie(0);
	MaxHeap heap; heap.init();

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

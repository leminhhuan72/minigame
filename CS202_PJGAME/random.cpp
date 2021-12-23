#include "random.h"
#include <ctime>
#include <random>
namespace Random {
	void Init() {
		srand(time(nullptr));
	}

	int Int(int l, int r) {
		return rand() % (r - l + 1) + l;
	}
}
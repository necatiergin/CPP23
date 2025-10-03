#include <iostream>

int main()
{
	auto fact = [](this auto self, int x) {
		if (x < 2) return 1;
		return x * self(x - 1);
	};

	std::cout << fact(5) << '\n';

}

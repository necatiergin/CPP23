#include <iostream>
#include <type_traits>

struct Nec {
	template <typename T>
	void foo(this T&& self)
	{
		using type = std::remove_cv_t<T>;
		std::cout << typeid(T).name() << '\n';
		if constexpr (std::is_lvalue_reference_v<T>) {
			if constexpr (std::is_const_v < std::remove_reference_t<T>>)
				std::cout << "const L value\n";
			else
				std::cout << "non const L value\n";
		}
		else if constexpr (std::is_const_v<T>)
			std::cout << "const R value\n";
		else
			std::cout << "non const R value\n";
	}
};


struct Der : Nec {};
struct Fer : Der {};

int main()
{
	Fer fer{};
	const Fer cfer{};

	fer.foo();
	Fer{}.foo();
	std::move(fer).foo();
	std::move(cfer).foo();


}

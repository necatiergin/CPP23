#include <concepts>

struct 	Nec {

	template <std::regular Self>
	void foo(this Self self)
	{
		// ...
	}
	
	void bar(this std::regular auto self)
	{
		// ...
	}

};

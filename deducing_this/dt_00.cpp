struct Myclass {

	void foo(this Myclass& self)
	{
		self.x = 5; //ok
		x = 5; // error
		this->x = 5; //error
	}

	int x{};
	void bar();
};

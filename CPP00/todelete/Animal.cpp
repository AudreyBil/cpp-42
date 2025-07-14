#include <iostream>


struct Cat {
	int legs {4};
	std::string name{"Cat"};
};

struct Dog {
	int legs{4};
	std::string name{"Dog"};
	void aboyersur(const Cat& cat) {
		std::cout << "The " << name << " barks at the " << cat.name << "." << std::endl;
	}
};

struct	Snake{
	int legs{0};
	std::string name{"Snake"};
};

int main()
{
	Dog animal;
	Cat cat;
	animal.aboyersur(cat);
}

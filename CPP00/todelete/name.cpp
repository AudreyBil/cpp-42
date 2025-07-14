#include <iostream>

class Employee
{
	private:
		std::string m_name;
		char m_initial;

	public:
		void setName(std::string name)
		{
			m_name = name;
			m_initial = name.front();
		}

		void print()
		{
			std::cout << "Employee " << m_name << " has first initial " << m_initial << std::endl;
		}
};

int main()
{
	Employee a;
	a.setName("Audrey");
	a.print();

}

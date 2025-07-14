#include <iostream>

// Provide the definition for IntPair and the print() member function here

class IntPair {
	private:
		int m_first;
		int m_second;

	public:
		IntPair(int first, int second)
			: m_first {first}, m_second {second}
		{
			std::cout << "object created" << std::endl;
		}
		void print()
		{
			std::cout << "Pair(" << m_first << "," << m_second << ")" << std::endl;
		}
		int isEqual(const IntPair& pair)
		{
			if (m_first + m_second == pair.m_first + pair.m_second)
				return 1;
			return 0;
		}
		void set_values(int first, int second)
		{
			m_first = first;
			m_second = second;
		}
};


int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3 ,4};

	p1.set_values(1, 3);
	std::cout << "p1: ";
	p1.print();

	p2.set_values(4, 5);
	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}

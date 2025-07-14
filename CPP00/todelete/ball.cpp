#include <iostream>

class Ball
{
	public:
		Ball()
		{
			print();
		};
		Ball(std::string color)
		: Ball(color, 10.0) {};
		Ball(double radius)
		: Ball("black", radius) {};
		Ball (std::string color, double radius)
		: m_color{color}, m_radius{radius}
		{
			print();
		};

		const std::string getColor() const { return m_color;}
		double getRadius() const {return m_radius;}


	private:
		std::string m_color {"black"};
		double m_radius {10.0};
};

void print(Ball ball)
{
	std::cout << "Ball(" << ball.getColor() << "," << ball.getRadius() << ")" << std::endl;
}



int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}

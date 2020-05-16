#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Pair
{
protected:
	int first;
	int second;
public:

	Pair(int a, int b)
	{
		first = a;
		second = b;
		//cout << "Pair constructed\n";
	}

	Pair(Pair* p)
	{
		first = p->first;
		second = p->second;
		//cout << "Pair constructed\n";
	}

	Pair()
	{
		first = 0;
		second = 0;
		//cout << "Pair constructed\n";
	}

	int mult()
	{
		return first * second;
	}

	virtual void read()
	{
		cout << "Введите пару: ";
		cin >> first >> second;
	}

	virtual void display()
	{
		cout << "Pair{first: " << first << ", second: " << second << "}\n";
	}

	void set_first(int value)
	{
		first = value;
	}

	void set_second(int value)
	{
		second = value;
	}
};

class Rect : public Pair
{
public:
	Rect(int a, int b) : Pair(a, b)
	{
		//cout << "Rect constructed\n";
	}

	Rect(Pair* p) : Pair(*p)
	{
		//cout << "Rect constructed\n";
	}

	Rect() : Pair()
	{
		//cout << "Rect constructed\n";
	}

	int get_perimeter()
	{
		return 2 * (first + second);
	}

	int get_area()
	{
		return mult();
	}

	void display() override
	{
		cout << "Rect{a: " << first << ", b: " << second <<
			", perimeter: " << get_perimeter() << ", area: " << get_area() << "}\n";
	}
};

int main()
{
	setlocale(LC_ALL, "russian");

	Rect rect1;
	cout << "Rect1(пустой): ";
	rect1.display();
	Rect rect2(7, 13);
	cout << "Rect2(конструктор): ";
	rect2.display();
	Rect rect3(&rect1);
	cout << "Rect3(копия Rect1): ";
	rect3.display();
	Pair pair_from_rect(&rect2);
	cout << "Pair_From_Rect(конструктор от производного класса): ";
	pair_from_rect.display();
	cout << "Pair1(конструктор): ";
	Pair pair1(1, 3);
	pair1.display();
	Rect rect_from_pair(&pair1);
	cout << "Rect_From_Pair(конструктор от базового класса): ";
	rect_from_pair.display();

	system("pause");
	return 0;
}

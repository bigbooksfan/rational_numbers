#include <iostream>

using namespace std;

int a;
unsigned b;

double c (0.0);

class rational
{

public:
	
	rational(int a_in, unsigned b_in);

	bool is_zero_dividing(const rational r_check);

	rational operator+(const rational n2);
	rational operator*(const rational n2);

	bool operator==(const rational n2);
	bool operator!=(const rational n2);

	friend ostream& operator<< (ostream& os, const rational r_out);

private:

	int numerator = 0;
	unsigned denominator = 0;

};



int main()
{

	rational a1(225, 34);
	rational a2(101, 522);

	rational a3 = a1 * a2; // Equal to: rational a3 = a1.operator*(a2);
	rational a4 = a1 + a2;
	

	cout << "a1 = " << a1 << "a2 = " << a2 << "product = " << a3 << "sum = " << a4 << endl;

	a1 != a2;

	return 0;
}

rational::rational(int a_in, unsigned b_in)
{

	numerator = a_in;
	denominator = b_in;

}

bool rational::is_zero_dividing(const rational r_check)
{

	return (denominator == 0) ? false : true;		// Скобки точно нужны?

}

bool rational::operator==(const rational n2)
{

	// Добавить проверку на кратность

	if (numerator == n2.numerator) if (denominator == n2.denominator) return true;

	return false;
}

rational rational::operator+(const rational n2)
{

	int s_numerator = 0;
	unsigned s_denominator = 0;

	s_numerator = this->numerator * n2.denominator + n2.numerator * this->denominator;
	s_denominator = this->denominator * n2.denominator;

	return rational(s_numerator, s_denominator);
}

rational rational::operator*(const rational n2)
{
	return rational(numerator * n2.numerator, denominator * n2.denominator);
}

bool rational::operator!=(const rational n2)
{
	
	return ((*this).operator==(n2)) ? false : true;

}

ostream& operator<<(ostream& os, const rational r_out)
{
	
	c = static_cast<double> (r_out.numerator) / r_out.denominator;

	os << r_out.numerator << "/" << r_out.denominator << " = " << c << endl;

	c = 0.0;

	return os;

}

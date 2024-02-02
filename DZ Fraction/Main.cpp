#include<iostream>


class Fraction {

	size_t  numerator;
	size_t  denominator;
public:
	Fraction(size_t numerator_, size_t denominator_) {
		if ( denominator_ == 0) {
			throw std::exception("message");
		}
		numerator = numerator_;
		denominator = denominator_;
	}

	void print_fraction() {
		std::cout << numerator << '/' << denominator << std::endl;
	}

	double valid_number() {
		if (numerator == 0 && denominator == 1) {
			return 1;
		}
		return double (numerator) / denominator;
	}

	void true_fraction() {
		if (denominator > numerator)
			std::cout << "Дробь правильная" << '\n';
		else
			std::cout << "Дробь не правильная " << '\n';
	}

	friend Fraction sum(Fraction,Fraction);
	friend Fraction dif(Fraction, Fraction);
	friend Fraction div(Fraction, Fraction);
	friend Fraction mult(Fraction, Fraction);

	friend Fraction sum(Fraction, size_t);
	friend Fraction dif(Fraction, size_t);
	friend Fraction div(Fraction, size_t);
	friend Fraction mult(Fraction, size_t);
};

Fraction sum(Fraction a, Fraction b) {
	size_t sum_num = a.numerator * b.denominator + b.numerator * a.denominator;
	size_t sum_den = a.denominator * b.denominator;
	return Fraction(sum_num, sum_den);

}

Fraction dif(Fraction a, Fraction b) {
	size_t sum_num = a.numerator * b.denominator - b.numerator * a.denominator;
	size_t sum_den = a.denominator * b.denominator;
	return Fraction(sum_num, sum_den);

}

Fraction div(Fraction a, Fraction b) {
	size_t sum_num = a.numerator * b.denominator;
	size_t sum_den = a.denominator * b.numerator;
	return Fraction(sum_num, sum_den);

}

Fraction mult(Fraction a, Fraction b) {
	size_t sum_num = a.numerator * b.numerator;
	size_t sum_den = a.denominator * b.denominator;
	return Fraction(sum_num, sum_den);

}

Fraction sum(Fraction a, size_t b) {
	b *= a.denominator;
	return Fraction(a.numerator + b, a.denominator);
}

Fraction dif(Fraction a, size_t b) {
	a.numerator -= b * a.denominator;
	return a;
}

Fraction div(Fraction a, size_t b) {
	size_t div_num = a.denominator * b;
	return Fraction(a.numerator, div_num);
};

Fraction mult(Fraction a, size_t b) {
	size_t mult_num = a.numerator * b;
	return Fraction(mult_num, a.denominator);
};



int main() {
	setlocale(LC_ALL, "ru");

	Fraction fra1(1,2);
	Fraction fra2(2,3);

	fra1.print_fraction();
	std::cout<< fra1.valid_number();
	fra1.true_fraction();
	
	//Fraction fra3 = sum(fra1, fra2);
	//Fraction fra3 = dif(fra1, fra2);
	//Fraction fra3 = div(fra1, fra2);
	//Fraction fra3 = mult(fra1, fra2);
	//Fraction fra3 = sum(fra1, 2);
	//Fraction fra3 = mult(fra1, 4);
	Fraction fra3 = div(fra1, 1);
	fra3.print_fraction();



	return 0;
}



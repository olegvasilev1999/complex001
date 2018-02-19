#include <iostream>

using namespace std;

struct complex_t {
    complex_t() { real=0.0f; imag=0.0f;
    }
    float real;
    float imag;


    istream & read(istream & stream, complex_t & complex) {
        float x, y;
        char a, b, c;

        if (stream >> a && a == '(' && stream >> x && stream >> b && b == ',' && stream >> y && stream >> c && c == ')') {
            real = x;
            imag = y;
        }
        else stream.setstate(std::ios::failbit);

        return stream;
    }

    ostream & write(ostream & stream, complex_t complex) {
        stream << "(" << real << "," << imag << ")";
        return stream;
    }

    complex_t add( complex_t other)const {
        complex_t result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }

    complex_t sub( complex_t other)const {
        complex_t result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }

    complex_t mul(complex_t other)const {
        complex_t result;
        result.real = (real * other.real) - (imag * other.imag) ;
        result.imag = (real * other.imag) + (imag * other.real);

        return result;
    }

    complex_t div( complex_t other)const {
        complex_t result;
        result.real = (real * other.real + imag * other.imag) / ((other.real)*(other.real) + (other.imag)*(other.imag));
        result.imag = (imag * other.real - real * other.imag) / ((other.real)*(other.real) + (other.imag)*(other.imag));
        return result;
    }

};


int main() {

    complex_t a,b,c;
    char op;

    if (a.read(cin, a)) {
        cin >> op;
        if (b.read(cin, b)) {
            switch (op) {
                case '+':
                    c = a.add(b);
                    c.write(cout,c);
                    break;
                case '-':
                    c = a.sub(b);
                    c.write(cout,c);

                    break;
                case '*':
                    c = a.mul(b);
                    c.write(cout,c);
                    break;
                case '/':
                    c = a.div(b);
                    c.write(cout,c);
                    break;
            }
        }else  cout <<"An error has occured while reading input data";

    }else  cout << "An error has occured while reading input data";

    cin.get();
    cin.get();

    return 0;
}

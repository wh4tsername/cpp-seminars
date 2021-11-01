#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class Complex {
public:
  Complex(double re, double im) : re_(re), im_(im) {
  }

  Complex(int re) : Complex(re, 0) {
  }

  Complex() : Complex(0, 0) {
  }
  
  Complex(const Complex& other) : Complex(other.re_, other.im_) {
//    std::cout << "copy!" << std::endl;
  }

  Complex& operator+=(const Complex& other) {
    re_ += other.re_;
    im_ += other.im_;    

    return *this;  
  }

  double& operator[](size_t index) {
    return index == 0 ? re_ : im_;
  }

  const double& operator[](size_t index) const {
    return index == 0 ? re_ : im_;
  }

  double abs() const {
    return sqrt(re_ * re_ + im_ * im_);
  }

  double GetReal() const {
    return re_;
  }

  Complex& operator++() {
    *this += 1;
    return *this;
  }

  Complex operator++(int) {
    Complex copy = *this;
    ++*this;
    return copy;
  }
  
private:
  double re_;
  double im_;
};

/*
struct Comparator {
  bool operator()(const Complex& lhs, const Complex& rhs){
     return lhs.abs() > rhs.abs();
  } 
};
*/

const double EPS = 1e-9;

bool operator<(const Complex& lhs, const Complex& rhs) {
  return lhs.abs() < rhs.abs();
}

bool operator>(const Complex& lhs, const Complex& rhs) {
  return rhs < lhs;
}

bool operator==(const Complex& lhs, const Complex& rhs) {
  return std::fabs(lhs.abs() - rhs.abs()) < EPS;
}

bool operator!=(const Complex& lhs, const Complex& rhs) {
  return !(lhs == rhs);
}

const Complex operator+(const Complex& lhs, const Complex& rhs) {
  Complex copy = lhs;
  copy += rhs;
  return copy;
}

std::ostream& operator<<(std::ostream& out, const Complex& object) {
  out << object[0] << " " << object[1];

  return out;
}

std::istream& operator>>(std::istream& in, Complex& object) {
  in >> object[0] >> object[1];

  return in;
}

void bar(int& a, bool) {
  a += 2;
}

void bar(int& a) {
  a += 1;
}

int main() {
  Complex c;
  Complex cc;

  std::cin >> c >> cc;
  std::cout << c << std::endl;
  std::cout << cc << std::endl;

  if (cc > c) {
    std::cout << "greater" << std::endl;
  }

  //Comparator comparator;
  std::vector<Complex> numbers;
  numbers.push_back(cc);
  numbers.push_back(c);
  numbers.push_back(cc);

  std::sort(numbers.begin(), numbers.end());

  for (size_t i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i] << std::endl;
  }

  int num = 10;
  bar(num);
  bar(num, true);

  std::cout << num << std::endl; 

  return 0;
}


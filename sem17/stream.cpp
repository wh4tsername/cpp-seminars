#include<istream>
#include <sstream>
#include <vector>
#include <iostream>

template <class T>
struct istream_iterator {
    istream_iterator(std::istream& stream) : stream_(stream) {}

    istream_iterator<T>& operator++() {
        stream_ >> value_;

        return *this;
    }

    T& operator*() {
       return value_; 
    }

private:
    std::istream& stream_;
    T value_;
};

template <class T>
struct ostream_iterator {
    ostream_iterator(std::ostream& stream) : stream_(stream) {}

    ostream_iterator<T>& operator++() {
        return *this;
    }

    ostream_iterator<T>& operator*() {
        return *this;
    }

    ostream_iterator<T>& operator=(const T& value) {
        stream_ << value;

        return *this;
    }

private:
    std::ostream& stream_;
};

int main() {
    std::string s = "123 10 11 12";

    std::istringstream ss(s);

    std::vector<int> a(4);
    istream_iterator<int> it(ss);
    ++it;
    for (size_t i = 0; i < 4; ++i, ++it) {
        a[i] = *it; 
    }

    for (int value : a) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}


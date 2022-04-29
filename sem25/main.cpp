#include <tuple>
#include <iostream>
#include <memory>

struct S {
    size_t num;
    float price; // 8 bytes
};

int main() {
    int b = 10;
    std::tuple<int, char, int&> a = {1, 'a', b};

    auto& [num, symbol, ref] = a;

    b = 11;
    std::get<0>(a) = 2;

    std::cout << ref << " " << num << std::endl;

    f(std::unique_ptr<char[]>(new char[10]), g());

    return 0;
}


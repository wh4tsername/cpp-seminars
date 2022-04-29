#include <iostream>
#include <type_traits>

template <class ...Args>
class tuple {
};

template <class Head, class ...Tail>
class tuple<Head, Tail...> {
public:
    Head head;
    tuple<Tail...> tail;
};

template <class T, class Head, class ...Tail>
T& get(tuple<Head, Tail...>& tuple) {
    if constexpr (std::is_same_v<T, decltype(tuple.head)>) {
        return tuple.head;
    } else {
        return get<T>(tuple.tail);
    }
}

template <size_t I, class Head, class ...Tail>
auto& get(tuple<Head, Tail...>& tuple) {
    if constexpr (I == 0) {
        return tuple.head;
    } else {
        return get<I - 1>(tuple.tail);
    }
}

int main() {
    tuple<int, char, double> t;

    get<0>(t) = 1;
    get<2>(t) = 1.3;

    std::cout << get<0>(t) << " " << get<2>(t) << std::endl;
    std::cout << get<int>(t) << " " << get<double>(t) << std::endl;

    return 0;
}


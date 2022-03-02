#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <type_traits>

template <class Container>
struct back_insert_iterator {
public:
    using value_type = typename Container::value_type;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = long;
    using pointer = std::add_pointer_t<value_type>;
    using reference = std::add_lvalue_reference<value_type>;

    explicit back_insert_iterator(Container& container)
        : container_(container) {}

    back_insert_iterator<Container>& operator++() {
        return *this;
    }

    back_insert_iterator<Container>& operator*() {
        return *this;
    }

    typename Container::value_type& operator=(
            const typename Container::value_type& value) {
        container_.push_back(value);
        return container_.back();
    }

private:
    Container& container_;
};

// *a = 123;
// *a = "str"; 

int main() {
    std::vector<int> a = {1, 4, 5, 7};
    std::vector<int> b;

    //std::copy(a.begin(), a.end(), back_insert_iterator<std::vector<int>>(b));
    std::copy(a.begin(), a.end(), b.end());

    for (int value : b) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}


#include <algorithm>

template <class Container>
struct back_insert_iterator {
public:
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
        container.push_back(value);
        return container.back();
    }

private:
    Container& container_;
};

int main() {
    std::vector<int> a = {1, 4, 5, 7};
    std::vector<int> b;

    std::copy(a.begin(), a.end(), back_insert_iterator{b});

    for (int value : b) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}


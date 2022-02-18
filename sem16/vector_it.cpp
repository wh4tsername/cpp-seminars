#include <cstddef>
#include <iterator>

template <bool F, class T, class U>
struct Conditional;

template <class T, class U>
struct Conditional<false, T, U> {
    using type = U;
};

template <class T, class U>
struct Conditional<true, T, U> {
    using type = T;
};

template <bool F, class T, class U>
using ConditionalValue = typename Conditional<F, T, U>::type;

template <class It>
class Reverse {
public:
    Reverse(const It& it) : it_(it) {}

    Reverse<It>& operator++() {
        --it_;
        
        return *this;
    }

private:
    It it_;
};

namespace detail {

template <class It, class ItCategory>
void my_advance_h(It& it, int n, ItCategory) {
    for (int i = 0; i < n; ++i) {
        ++it;
    }
}

template <class It>
void my_advance_h(It& it, int n, std::random_access_iterator_tag) {
    it += n;
}

}

template <class It>
void my_advance(It& it, int n) {
    if constexpr (std::is_same_v<typename std::iterator_traits<It>::iterator_category(), std::random_access_iterator_tag>) {
        // +=
    } else {
        // for
    }
    //detail::my_advance_h(it, n, typename std::iterator_traits<It>::iterator_category());
}

// it1 -> it2



template <class T>
class Vector {
private:
    template <bool IsConst>
    struct common_iterator {
        public:
            explicit common_iterator(ConditionalValue<IsConst, const T*, T*> data) : data_(data), index_(0) {}

            ConditionalValue<IsConst, const T&, T&> operator*() {
                return data_[index_];
            }

            ConditionalValue<IsConst, const T*, T*> operator->() {
                return data_ + index_;
            }

            common_iterator<IsConst> operator++() & {
                common_iterator<IsConst> it = *this;

                ++index_;

                return it;
            }

            common_iterator<IsConst>& operator++(int) {
                ++index_;

                return *this;
            }

            common_iterator<IsConst>& operator+=(size_t n) {
                index_ += n;

                return *this;
            }

            common_iterator<IsConst>& operator+(size_t n) {
                *this += n;

                return *this;
            }

            bool operator==(const common_iterator<IsConst>& rhs) {
                return index_ == rhs.index_;
            }

        private:
            T* data_;
            size_t index_;
    };

public:
    using iterator = common_iterator<false>;
    using const_iterator = common_iterator<true>;

    Reverse<iterator> RBegin() {
        return Reverse<iterator>{iterator{data_}};
    }

    Reverse<iterator> REnd() {
        iterator it{data_};

        it.index_ = size_;

        return Reverse<iterator>{it};
    }

    const_iterator CBegin() const {
        return const_iterator{data_};
    }

    const_iterator CEnd() const {
        const_iterator it(nullptr);
        
        it.index_ = size_;

        return it;
    }

    iterator Begin() {
        return iterator{data_};
    }

    iterator End() {
        iterator it(nullptr);

        it.index_ = size_;

        return it;
    }

private:
    size_t size_;
    T* data_;
};

template <class T>
typename Vector<T>::iterator& operator+(size_t n, typename Vector<T>::iterator& other) {
    return other + n;
}

int main() {
    return 0;
}


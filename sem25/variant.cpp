template <class ...Args>
class variant {};

template <class Head, class ...Tail>
class variant {
    template <class Head, class ...Tail>
    union Union {
        Head head;
        Union<Tail...> tail;
    };

    Union<Head, Tail...> storage;
};

int main() {
    return 0;
}

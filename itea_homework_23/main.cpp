#include<iostream>

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(const T1& value1, const T2& value2) : first(value1), second(value2) {}
    // Конструктор копіювання
    Pair(const Pair& other) : first(other.first), second(other.second) {}

    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    // Перегрузка оператора виведення в потік
    friend std::ostream& operator<<(std::ostream& os, const Pair& pair) {
        os << "(" << pair.first << ", " << pair.second << ")";
        return os;
    }

    // Перегрузка оператора введення з потоку
    friend std::istream& operator>>(std::istream& is, Pair& pair) {
        is >> pair.first >> pair.second;
        return is;
    }

    // Перегрузка оператора присвоєння
    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first  = other.first;
            second = other.second;
        }
        return *this;
    }

    // Перегрузка оператора порівняння ==   
    bool operator==(const Pair& other) const {
        if (&other == this)
            return true;
        
        return (first == other.first) && (second == other.second);
    }

    // Перегрузка оператора порівняння !=
    bool operator!=(const Pair& other) const {
        return !(*this == other);
    }
};

int main() {
    Pair<int, std::string> pair1(42, "Hello");
    Pair<int, std::string> pair2(42, "Hello");

    std::cout << "pair1: " << pair1 << std::endl;
    std::cout << "pair2: " << pair2 << std::endl;

    if (pair1 == pair2) {
        std::cout << "pair1 is equal to pair2" << std::endl;
    }
    else {
        std::cout << "pair1 is not equal to pair2" << std::endl;
    }

    Pair<int, std::string> pair3(10, "World");
    std::cin >> pair3;
    std::cout << "pair3: " << pair3 << std::endl;

    return 0;
}
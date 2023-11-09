#include<iostream>

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(const T1& value1, const T2& value2) : first(value1), second(value2) {}
    // ����������� ���������
    Pair(const Pair& other) : first(other.first), second(other.second) {}

    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    // ���������� ��������� ��������� � ����
    friend std::ostream& operator<<(std::ostream& os, const Pair& pair) {
        os << "(" << pair.first << ", " << pair.second << ")";
        return os;
    }

    // ���������� ��������� �������� � ������
    friend std::istream& operator>>(std::istream& is, Pair& pair) {
        is >> pair.first >> pair.second;
        return is;
    }

    // ���������� ��������� ���������
    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first  = other.first;
            second = other.second;
        }
        return *this;
    }

    // ���������� ��������� ��������� ==   
    bool operator==(const Pair& other) const {
        if (&other == this)
            return true;
        
        return (first == other.first) && (second == other.second);
    }

    // ���������� ��������� ��������� !=
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
#include <algorithm>
#include <iostream>
#include <vector>

// Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
// Policz, ile jest elementów większych lub równych 5
// Sprawdź, czy istnieje element mniejszy od 1
// Sprawdź, czy wszystkie elementy są większe od 1

int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

    auto countMore5 = [](auto x) { return x >= 5; };
    auto f1 = [](auto x) { return x < 1; };

    auto valMore5 = std::count_if(begin(v), end(v), countMore5);
    std::cout << valMore5 << '\n';
    auto lessThanOne = std::count_if(begin(v), end(v), f1);
    std::cout << lessThanOne << '\n';

    std::cout << "none_of 1: "<< std::boolalpha << none_of(begin(v), end(v), f1) << '\n';
    std::cout << "any_of 1: " << std::boolalpha << any_of(begin(v), end(v), f1) << '\n';
    return 0;
}

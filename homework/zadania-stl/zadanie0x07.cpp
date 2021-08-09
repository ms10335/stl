#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
// Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9}; (ten sam co ostatnio)
// Znajdź wszystkie elementy większe od 6 i wypisz je
// Znajdź wszystkie elementy równe 2, 4, 6 lub 8 i wypisz je
// Przeszukaj wektor v w poszukiwaniu zakresów {6, 6} i {7, 7}
// Użyj std::adjacent_find na wektorze v

int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    std::copy_if(begin(v),
                 end(v),
                 std::ostream_iterator<int>(std::cout, " "),
                 [](auto a) { return a > 6; });

    std::cout << '\n';
    std::copy_if(begin(v),
                 end(v),
                 std::ostream_iterator<int>(std::cout, " "),
                 [](auto x) { return x == 2 || x == 4 || x == 6 || x == 8; });

    std::cout << '\n';
    auto it = std::search_n(begin(v), end(v),2,6);
    if(it != v.end()) {
        std::cout << *it << '\n';
        it++;
        std::cout << *it << '\n';
    }
    
    it = std::adjacent_find(begin(v), end(v));
    if(it != v.end()) {
        std::cout << *it << '\n';
        it++;
        std::cout << *it << '\n';
    }
     return 0;
}

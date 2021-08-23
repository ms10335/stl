#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <experimental/iterator>

// Zadanie1: Wykorzystaj (sensownie) jak najwięcej algorytmów, aby wypisać dane z wektora na strumień wyjścia (std::cout).
//   Zasady:
// 	- Każde poprawne rozwiązanie 1 eurogąbek.
// 	- Każde niepoprawne rozwiązanie -0.5 eurogąbki.
// 	- std::count_if w którym umieścimy lambdę wypisująca dane do strumienia to złe rozwiązanie.
// 	- std::generate jest zbyt dużym naciągnięciem, więc również odpada.
// 	- Nie używamy raw pętli (for, while etc...).
// 	- Jest 13 poprawnych algorytmów (4 z nich są lekkim nagięciem, ale są sensowne w niekotnych przypadkach).
// 	- Maksymalna ilość punktów do zdobycia to 10 eurogąbek (zatem wystarczy 10 rozwiązań, nie trzeba zgadywać wszystkich).

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& data) {
    std::for_each(begin(data), end(data), [&os](auto& a) { os << a << " "; });
    return os;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8};

    //1. transform
    std::cout << "1. transform:\n";
    std::transform(begin(data), end(data), std::ostream_iterator<int>(std::cout, " "), [](auto& a) { return a; });
    std::cout << '\n';
    //2.for_each
    std::cout << "2. for_each:\n";
    std::for_each(begin(data), end(data), [](auto& a) { std::cout << a << " "; });
    std::cout << '\n';
    //3.ostram operator <<
    std::cout << "3. ostream operator<< with NO raw loop:\n";
    std::cout << data;
    std::cout << '\n';
    //4. copy
    std::cout << "4. copy:\n";
    std::copy(begin(data), end(data), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    //5. lambada itself :) 
    std::cout << "5. Lambada itself :)\n";
    [&data](){std::cout << data;}();
    std::cout << '\n';
    //6. experiental joiner and copy
    std::cout << "6. experimental joiner and copy:\n";
    std::copy(begin(data), end(data), std::experimental::make_ostream_joiner(std::cout," "));
    std::cout << '\n';
    //7. MOVE ??
    std::cout << "7. Move:\n";  
    std::move(begin(data), end(data),std::ostream_iterator<int>(std::cout," "));
    std::cout << '\n';
    //8.copy_if
    std::cout << "8. copy_if: \n";
    std::copy_if(begin(data), end(data), std::ostream_iterator<int>(std::cout," "), [](auto& a){return a;});
    std::cout << '\n';
    //9. reverse_copy
    std::cout << "9. Reverse copy:\n";
    std::reverse_copy(rbegin(data), rend(data), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    //10. rotate_copy
    std::cout << "10. Rotate copy:\n";
    std::rotate_copy(begin(data),begin(data),end(data),std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    //11. eqal range ???
    
    return 0;
}
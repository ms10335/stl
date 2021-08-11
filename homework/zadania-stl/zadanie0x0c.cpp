#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <iterator>

// Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
// Usuń wszystkie duplikaty z v
// Wypisz wszystkie elementy, używając std::copy i std::ostream_iterator
// Pomieszaj losowo wszystkie elementy
// Wypisz je raz jeszcze


int main()
{
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    std::cout << "Przed usunieciem duplikacji: \n";
    std::sort(v.begin(), v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    // Usuń wszystkie duplikaty z v
    auto last = std::unique(begin(v), end(v));
    v.erase(last, end(v));
    std::cout << "Przy użyciu std::copy: \n";
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    
    // Pomieszaj losowo wszystkie elementy
    std::mt19937 g(10000);
    std::shuffle(v.begin(), v.end(), g);
    std::cout << "Przy użyciu mt19937: \n";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    std::sort(begin(v), end(v));
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    return 0;
}

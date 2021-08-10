#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::pair<int, std::string>> v{
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};

    //Utwórz wektor intów v2 i wypełnij go wszystkimi intami (pierwszymi elementami pary) z wektora v
    std::vector<int> v2(v.size());
    std::transform(begin(v), end(v), begin(v2), [](auto a) { return a.first; });
    for (auto i : v2) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    // Utwórz wektor stringów v3 i wypełnij go konkatenacją string + dwukropek + int ze wszystkich par z wektora v
    std::vector<std::string> v3(v.size());
    std::transform(begin(v), end(v), begin(v3), [](auto a) { return a.second + ": " + std::to_string(a.first); });
    for (auto i : v3) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    // Utwórz wektor charów v4 i wypełnij go co drugą literą alfabetu
    constexpr int size{13};
    std::vector<char> v4(size);

    std::generate_n(begin(v4), size, [x{'a' - 2}]()mutable{x += 2; return x;});
    for (auto i : v4) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    return 0;
}

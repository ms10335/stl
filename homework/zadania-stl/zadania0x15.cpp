#include <unistd.h>
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

// Utwórz wektor v1 z liczbami od 1 do 1000
// Oblicz sumę tych liczb
// Utwórz wektor v2 z 1000 elementów powtarzających się w następującej sekwencji: -1, 0, 1, 0, -1, 0, 1, 0, ...
// Oblicz iloczyn skalarny wektorów v1 i v2
// Oblicz sumę tych liczb z v1, które są na pozycjach dodatnich jedynek z wektora v2

void Print(std::vector<int>& vec) {
    for(auto& a: vec) {
        std::cout << a << ' ';
    }
    std::cout << '\n';
}
int main() {
    std::vector<int> v1(1000);
    std::iota(begin(v1), end(v1), 1);

    auto sumV1 = std::accumulate(begin(v1), end(v1), v1[0], std::plus<>());
    std::cout << "Suma liczb v1: " << sumV1 << '\n';

    std::vector<int> v2{};
    v2.reserve(1000);
    std::array<int, 4> arrseq{-1, 0, 1, 0};

    for(auto i = 0; i < v2.capacity(); i += 4) {
        for(auto j = 0; j < arrseq.size(); ++j) {
            v2.emplace(v2.end(),arrseq[j]);
        }
    }
    
    std::cout << "Inner_product: ";

    int inn_product{0};
    if(v1.size() == v2.size()) {
        inn_product = std::inner_product(v1.begin(), v1.end(), v2.begin(),0);
    }
    std::cout << inn_product << '\n';

    std::cout << "Suma z dodatnich jedynek: ";
    std::vector<int>v3{};
    v3.reserve(1000);
    for(auto i = 2; i < v1.size(); i +=4) {
        v3.emplace(v3.end(), v1[i]);
    }
    v3.shrink_to_fit();
    auto sumV3 = std::accumulate(begin(v3), end(v3), v3[0],std::plus<>());
    std::cout << sumV3 << '\n';
    std::cout << '\n';
    return 0;
}
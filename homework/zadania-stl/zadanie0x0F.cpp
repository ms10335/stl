#include <algorithm>
#include <deque>
#include <iostream>

// Utwórz std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};
// Utwórz funkcję do wypisywania zawartości kontenera d
// Napisz 2 komparatory:
//     pointXCompare, który porównuje tylko wartości x ze struktury Point
//     pointYCompare, który porównuje tylko wartości y ze struktury Point
// Sprawdź czy d jest posortowane względem pointXCompare oraz pointYCompare
// Użyj stable_sort do posortowania d względem wartości x
// Użyj sort do posortowania d względem wartości y

struct Point {
    int x, y;
};

void Print(std::deque<Point>& d) {
    for (auto& a : d) {
        std::cout << "x: " << a.x << " y: " << a.y << '\n';
    }
}
bool pointXCompare(const Point& lhs, const Point& rhs) {
    return lhs.x < rhs.x;
}

bool pointYCompare(const Point& lhs, const Point& rhs) {
    return lhs.y < rhs.y;
}

int main() {
    std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};
    std::cout << "Inicjalne wywolanie deque:\n";
    Print(d);
    std::cout << "Po uzyciiu komparatora X:\n";
    std::sort(begin(d), end(d), pointXCompare);
    Print(d);
    std::cout << "Po uzyciiu komparatora Y:\n";
    std::sort(begin(d), end(d), pointYCompare);
    Print(d);
    return 0;
}
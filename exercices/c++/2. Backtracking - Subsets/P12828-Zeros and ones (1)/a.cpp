#include <iostream>
#include <string>

void print_combinations(int n, std::string comb) {
    if (n == 0) {
        std::cout << comb << std::endl;
        return;
        }
    std::string space = " ";
    if (n == 1) space = "";  // If last item dont put space
    print_combinations(n-1, comb + "0" + space);
    print_combinations(n-1, comb + "1" + space);
}


int main() {
    int n;
    std::cin >> n;
    print_combinations(n, "");
}
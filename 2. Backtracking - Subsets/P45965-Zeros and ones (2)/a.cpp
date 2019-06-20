#include <iostream>
#include <vector>

void print_combination(const std::vector<bool> &combination) {
    int size = combination.size();
    for (int i = 0; i < size - 1; ++i)
        if (combination[i]) std::cout << "1 ";
        else std::cout << "0 ";
    std::cout << combination[size - 1] << std::endl;
    return;
}

void print_combinations(int z, int o, std::vector<bool> combination) {
    if (z + o == 0) {
        print_combination(combination);
        return;
    }
    int pos = combination.size() - z - o;
    if (z > 0) {
        combination[pos] = 0;
        print_combinations(z - 1, o, combination);
    }
    if (o > 0) {
        combination[pos] = 1;
        print_combinations(z, o - 1, combination);
    }
}

int main() {
    int n, o;
    std::cin >> n >> o;
    std::vector<bool> combination(n);
    print_combinations(n-o, o, combination);
}
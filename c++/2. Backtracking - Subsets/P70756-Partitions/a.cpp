#include <iostream>
#include <string>
#include <vector>

void print_subset(const std::vector<unsigned int> &selected_words,
                  const std::vector<std::string> &words) {
  int size = selected_words.size();
  std::cout << "{";
  for (int i = 0; i < size - 1; ++i)
    std::cout << words[selected_words[i]] << ",";
  if (size > 0) std::cout << words[selected_words[size - 1]];
  std::cout << "}" << std::endl;
  return;
}

void print_partition(const unsigned int &p,
                     const std::vector<unsigned int> &distribution,
                     const std::vector<std::string> &words) {
  for (unsigned int i = 1; i <= p; ++i) {
    std::cout << "subset " << i << ": ";
    std::vector<unsigned int> words_of_subset_i;
    for (unsigned int j = 0; j < distribution.size(); ++j)
      if (distribution[j] == i) words_of_subset_i.push_back(j);
    print_subset(words_of_subset_i, words);
  }
  std::cout << std::endl;
}

void print_subsets(unsigned int pos, const unsigned int &p,
                   std::vector<unsigned int> &distribution,
                   const std::vector<std::string> &words) {
  unsigned int size = distribution.size();
  if (pos == size) {
    print_partition(p, distribution, words);
    return;
  }
  for (unsigned int i = 1; i <= p; ++i) {
    distribution[pos] = i;
    print_subsets(pos + 1, p, distribution, words);
  }
}

int main() {
  unsigned int n, p;
  std::cin >> n;
  std::vector<std::string> words(n);
  std::vector<unsigned int> distribution(n);
  for (unsigned int i = 0; i < n; ++i) std::cin >> words[i];

  std::cin >> p;
  print_subsets(0, p, distribution, words);
}
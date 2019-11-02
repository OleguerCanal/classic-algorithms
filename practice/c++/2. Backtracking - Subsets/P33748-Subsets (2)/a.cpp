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

void print_subsets(unsigned int num_no, unsigned int num_yes,
                   std::vector<unsigned int> &selected_words,  // Should be a pointer
                   const std::vector<std::string> &words) {
  if (num_yes == 0) {
    print_subset(selected_words, words);
    return;
  }
  if (num_no > 0) print_subsets(num_no - 1, num_yes, selected_words, words);
  if (num_yes > 0) {
    unsigned int selected_pos = selected_words.size() - num_yes;
    selected_words[selected_pos] = words.size() - num_no - num_yes;
    print_subsets(num_no, num_yes - 1, selected_words, words);
  }
}

int main() {
  unsigned int m, n;
  std::cin >> m >> n;
  std::vector<std::string> words(n);
  for (unsigned int i = 0; i < n; ++i) std::cin >> words[i];

  std::vector<unsigned int> selected_words(m);
  print_subsets(n - m, m, selected_words, words);
}
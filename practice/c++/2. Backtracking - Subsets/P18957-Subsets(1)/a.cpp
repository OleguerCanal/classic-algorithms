#include <iostream>
#include <string>
#include <vector>

void print_subset(const std::vector<std::string> &selected_words) {
  int size = selected_words.size();
  std::cout << "{";
  for (int i = 0; i < size - 1; ++i) std::cout << selected_words[i] << ",";
  if (size > 0) std::cout << selected_words[size - 1];
  std::cout << "}" << std::endl;
  return;
}

void print_subsets(unsigned int n, std::vector<std::string> selected_words,
                   const std::vector<std::string> &words) {
  if (n == words.size()) {
    print_subset(selected_words);
    return;
  }
  print_subsets(n + 1, selected_words, words);
  selected_words.push_back(words[n]);
  print_subsets(n + 1, selected_words, words);
}

int main() {
  unsigned int n;
  std::cin >> n;
  std::vector<std::string> words(n);
  for (unsigned int i = 0; i < n; ++i) std::cin >> words[i];
  std::vector<std::string> selected_words;
  print_subsets(0, selected_words, words);
}
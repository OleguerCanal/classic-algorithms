#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

typedef std::vector<bool> vb;
typedef std::vector<std::vector<bool>> mb;

typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> mi;

typedef std::pair<int, int> Coord;

const int size = 9;

struct Possibilites {
  vi vals = vi(10, 0);  // Possible values (first elem is num of possibilities)
  int i, j;             // Position

  void FromVector(const int &a, const int &b, const vi &possibilities) {
    i = a;
    j = b;
    vals = possibilities;
  }
};

// Struct to hold all sudoku info:
// Values in each position
// numbers found in each row, column and square of a sudoku
// IDEA: Optimize IsSolved, IsPossibleVal kind of cheks with matrices of bools
// instead of iterate over sudolu
class Sudoku {
 public:
  Sudoku() {
    values_ = mi(size, vi(size, -1));
    rows_ = mb(size, vb(size, false));
    cols_ = mb(size, vb(size, false));
    squares_ = mb(size, vb(size, false));

    // Fill pos_to_sqare_matrix_
    pos_to_sqare_matrix_ = mi(size, vi(size, 0));
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
        pos_to_sqare_matrix_[i][j] = (i / 3) * 3 + (j / 3);
  }
  ~Sudoku() {}

  // Whether the sudoku is solved
  bool IsSolved() {  // TODO(oleguer): Could be optimized
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
        if (!rows_[i][j] || !cols_[i][j] || !squares_[i][j]) return false;
    return true;
  }

  // Mark value val in position i, j
  void InputValue(const int &val, const int &i, const int &j) {
    values_[i][j] = val;
    int v = val - 1;
    rows_[i][v] = true;
    cols_[j][v] = true;
    squares_[pos_to_sqare_matrix_[i][j]][v] = true;
  }

  // Assume that the value was correctly placed
  void RemoveValue(const int &i, const int &j) {
    int val = values_[i][j];
    values_[i][j] = -1;
    if (val != -1) {
      int v = val - 1;
      rows_[i][v] = false;
      cols_[j][v] = false;
      squares_[pos_to_sqare_matrix_[i][j]][v] = false;
    }
  }

  // Whether it is possible to put val in position i, j
  bool IsPossible(const int &val, const int &i, const int &j) {
    // row, col, sqare val must be false (it cant be in any of these positions)
    int v = val - 1;
    if (values_[i][j] != -1) return false;
    return !rows_[i][v] && !cols_[j][v] &&
           !squares_[pos_to_sqare_matrix_[i][j]][v];
  }

  // Wheter there is already a number at position i, j
  bool IsEmpty(const int &i, const int &j) { return (values_[i][j] == -1); }

  std::vector<int> GetPossibilities(const int &i, const int &j) {
    std::vector<int> possibilities(
        10, -1);  // First value indicates number of possibilities (idea: fix
                  // vector size)
    int pos_num = 0;
    for (int val = 1; val <= size; ++val)
      if (IsPossible(val, i, j)) {
        pos_num += 1;
        possibilities[pos_num] = val;
      }
    possibilities[0] = pos_num;
    return possibilities;
  }

  // Get the empty slot with least possible values to fit in
  Possibilites GetLeastPossibilities() {
    int min_found = size;
    Possibilites poss;
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j) {
        if (IsEmpty(i, j)) {
          std::vector<int> possibilities = GetPossibilities(i, j);
          if (possibilities[0] == 2) {  // 2 is the minimum in this scenario
            poss.FromVector(i, j, possibilities);
            return poss;
          }
          if (possibilities[0] < min_found) {
            min_found = possibilities[0];
            poss.FromVector(i, j, possibilities);
          }
        }
      }
    return poss;
  }

  // Fill all the spots that can only fit a single number
  bool FillCertain() {
    bool filled_something = true;
    while (filled_something) {
      filled_something = false;
      for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
          if (IsEmpty(i, j)) {
            std::vector<int> possibilities = GetPossibilities(i, j);
            if (possibilities[0] == 0) return false;  // Found an inconsistency
            if (possibilities[0] == 1) {
              InputValue(possibilities[1], i, j);
              filled_something = true;
            }
          }
        }
    }
    return true;
  }

  // IO functions
  // Read from statement
  void ReadSudoku() {
    char c;
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j) {
        std::cin >> c;
        while (c == '|' || c == '-' || c == '+') std::cin >> c;  // Get next one
        if (c == '0')
          values_[i][j] = -1;
        else {
          int val = c - '0';
          InputValue(val, i, j);
        }
      }
  }

  // Print current sudoku
  void Print() {
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size - 1; ++j) {
        std::cout << values_[i][j] << " ";
        if (j == 2 || j == 5) std::cout << "| ";
      }
      std::cout << values_[i][size - 1] << std::endl;
      if (i == 2 || i == 5) std::cout << "------+-------+------" << std::endl;
    }
    std::cout << std::endl;
  }

 private:
  mi values_;
  mb rows_;
  mb cols_;
  mb squares_;

  mi pos_to_sqare_matrix_;
};

int calls;

void SolveSudoku(Sudoku *sudoku, bool *found_solution) {
  calls += 1;
  if (*found_solution)
    return;  // Idea: Only one possible solution, so if it has been found, stop

  bool possible = sudoku->FillCertain();  // Fill all obvious blanks
  if (!possible) return;  // If inconsistent, surrender this branch

  if (sudoku->IsSolved()) {  // Check if it is solved
    sudoku->Print();
    *found_solution = true;
    return;
  }

  // If can't fill any obvious and is not solved:
  // make an assumption and try to solve it:
  Possibilites possibilities = sudoku->GetLeastPossibilities();
  for (int i = 1; i < possibilities.vals[0]; ++i) {
    sudoku->InputValue(possibilities.vals[i], possibilities.i, possibilities.j);
    SolveSudoku(sudoku, found_solution);
    sudoku->RemoveValue(possibilities.i, possibilities.j);
  }
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    calls = 0;
    Sudoku sudoku;
    sudoku.ReadSudoku();
    bool found_solution = false;
    SolveSudoku(&sudoku, &found_solution);
    std::cout << "Calls: " << calls << std::endl;
  }
}
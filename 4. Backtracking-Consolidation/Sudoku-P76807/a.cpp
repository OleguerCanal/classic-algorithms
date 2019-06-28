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

// Struct to hold all sudoku info:
// Values in each position
// numbers found in each row, column and square of a sudoku
// IDEA: Optimize IsSolved, IsPossibleVal kind of cheks with matrices of bools
// instead of iterate over sudolu
class Sudoku {
 public:
  mi values;
  mb rows;
  mb cols;
  mb squares;

  Sudoku() {
    values = mi(size, vi(size, -1));
    rows = mb(size, vb(size, false));
    cols = mb(size, vb(size, false));
    squares = mb(size, vb(size, false));
  }

  // Whether the sudoku is solved
  bool IsSolved() {  // TODO(oleguer): Could be optimized
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
        if (!rows[i][j] || !cols[i][j] || !squares[i][j]) return false;
    return true;
  }

  // Get flatted square position
  int GetSquare(const int &i, const int &j) {
    int square = (i / ((int)std::sqrt(size))) * ((int)std::sqrt(size)) +
                 (j / ((int)std::sqrt(size)));
    return square;
  }

  // Mark value val in position i, j
  void InputValue(const int &val, const int &i, const int &j) {
    std::cout << "i:" << i << ", j:" << j << ", sq:" << GetSquare(i, j)
              << ", v:" << val << std::endl;
    values[i][j] = val;
    std::cout << values[i][j] << std::endl;
    // Print();
    int v = val - 1;
    rows[i][v] = true;
    cols[j][v] = true;
    squares[GetSquare(i, j)][v] = true;
  }

  // Assume that the value was correctly placed
  void RemoveValue(const int &i, const int &j) {
    int val = values[i][j];
    values[i][j] = -1;
    if (val != -1) {
      int v = val - 1;
      rows[i][v] = false;
      cols[j][v] = false;
      squares[GetSquare(i, j)][v] = false;
    }
  }

  // Whether it is possible to put val in position i, j
  bool IsPossible(const int &val, const int &i, const int &j) {
    // row, col, sqare val must be false (it cant be in any of these positions)
    int v = val - 1;
    if (values[i][j] != -1) return false;
    return !rows[i][v] && !cols[j][v] && !squares[GetSquare(i, j)][v];
  }

  // Wheter there is already a number at position i, j
  bool IsEmpty(const int &i, const int &j) { return (values[i][j] != -1); }

  // IO functions
  // Read from statement
  void ReadSudoku() {
    char c;
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j) {
        std::cin >> c;
        // std::cout << c << std::endl;
        if (c == '.')
          values[i][j] = -1;
        else {
          int val = c - '0';
          InputValue(val, i, j);
        }
      }
    // Print();
  }

  // Print current sudoku
  void Print() {
    std::cout << std::endl;
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        std::cout << values[i][i] << " ";  // TODO(oleguer): Probably wrong
      }
      std::cout << std::endl;
    }
  }
};

Coord GetCoord(const int &pos) {
  int i = pos / size;
  int j = pos % size;
  return Coord(i, j);
}

void SolveSudoku(const int &pos, Sudoku *sudoku) {
  if (pos == size * size - 1) {
    if (sudoku->IsSolved()) sudoku->Print();
    return;
  }

  Coord cord = GetCoord(pos);
  int i = cord.first;
  int j = cord.second;

  bool tried_value = false;
  if (sudoku->IsEmpty(i, j)) {
    for (int val = 0; val < size; ++val)
      if (sudoku->IsPossible(val, i, j)) {
        tried_value = true;
        sudoku->InputValue(val, i, j);
        SolveSudoku(pos + 1, sudoku);
        sudoku->RemoveValue(i, j);
      }
  }
  if (!tried_value) return;  // If no value is possible
}

int main() {
  int n;
  std::cin >> n;
  std::cout << n << std::endl;
  for (int i = 0; i < n; ++i) {
    Sudoku sudoku;
    sudoku.ReadSudoku();
    std::cout << i << std::endl;
    sudoku.Print();
    SolveSudoku(0, &sudoku);
  }
}
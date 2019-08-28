#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::vector<bool>> vvb;
typedef std::pair<int, int> position;

enum class Solvable { solved, impossible, unknown };  // Solvability of the game


class Game {
 public:
  Game(const int& size_x, const int& size_y) {
    size_x_ = size_x;
    size_y_ = size_y;
  }
  ~Game() {}

  // Convert (i,j) pos to mapped CellId
  int PosToCellId(const position& pos) {
    return pos.first * size_y_ + pos.second;
  }

  // Convert mapped CellId to (i,j) pos
  position CellIdToPos(const int& cellid) {
    return position(cellid / size_y_, cellid % size_y_);
  }

  // Returns distance between 2 positions
  int Distance(const position& pos_1, const position& pos_2) {
    return (pos_1.first - pos_2.first) * (pos_1.first - pos_2.first) +
           (pos_1.second - pos_2.second) * (pos_1.second - pos_2.second);
  }

  // Populates map, player_pos and objective_pos
  // Returns either solved, impossible or unknown solvability
  Solvable ReadMap() {
    vvb map = vvb(size_x_, std::vector<bool>(size_y_, false));
    for (size_t i = 0; i < map.size(); i++) {
      for (size_t j = 0; j < map[0].size(); j++) {
        char c;
        std::cin >> c;
        std::string element = elements_[c];
        if (element == "EMPTY" || element == "GOAL" || element == "PLAYER") {
          map[i][j] = true;
          if (element == "GOAL") goal_pos_ = position(i, j);
          if (element == "PLAYER") player_pos_ = position(i, j);
        }
        if (element == "DONE") return Solvable::solved;
        if (element == "IMPOSSIBLE") return Solvable::impossible;
      }
    }
    map_ = map;  // TODO(oleguer): Unnecessary copying?
    return Solvable::unknown;
  }

 private:
  const std::map<char, std::string> elements_ = {
      {' ', "EMPTY"}, {'#', "WALL"}, {'.', "GOAL"},      {'@', "PLAYER"},
      {'+', "DONE"},  {'$', "WALL"}, {'*', "IMPOSSIBLE"}};

  int size_x_, size_y_;  /// Shape of map
  vvb map_;              /// 1 == walkable path, 0 == blocked
  position player_pos_, goal_pos_;
};

int main() {
  Game game(6, 8);
  Solvable solvable = game.ReadMap();  
  switch (solvable) {
  case Solvable::impossible:
    std::cout << "no path" << std::endl;
    break;
  case Solvable::solved:
    break;
  default:
    break;
  }
  
}
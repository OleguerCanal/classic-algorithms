#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace sokoban {
typedef std::vector<std::vector<bool>> vvb;
typedef std::vector<std::vector<int>> vvi;
typedef std::pair<int, int> position;

enum class Solvable { solved, impossible, unknown };  // Solvability of the game
const std::map<char, std::string> map_elements = {
    {' ', "EMPTY"}, {'#', "WALL"}, {'.', "GOAL"},      {'@', "PLAYER"},
    {'+', "DONE"},  {'$', "WALL"}, {'*', "IMPOSSIBLE"}};

class Game {
 public:
  Game(const int& size_x, const int& size_y) {
    size_x_ = size_x;
    size_y_ = size_y;
    vvi graph = std::vector(size_x * size_y, std::vector<int>(0));
    graph_ = graph;
  }
  ~Game() {}

  // Populates map, player_pos and objective_pos
  // Returns either solved, impossible or unknown solvability
  Solvable ReadMap() {
    vvb map = vvb(size_x_, std::vector<bool>(size_y_, false));
    for (size_t i = 0; i < map.size(); i++) {
      for (size_t j = 0; j < map[0].size(); j++) {
        char c;
        std::cin >> c;
        std::string element = map_elements[c];
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

  // Solvable Find

 private:
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
  
  
  // Populates graph_ private variable
  void BuildGraph() {
    int x_dif[4] = {1, -1, 0, 0};
    int y_dif[4] = {0, 0, 1, -1};
    for (size_t i = 0; i < map_.size(); i++)
      for (size_t j = 0; j < map_[0].size(); j++)  // Each elem of map
        if (map_[i][j]) {                          // If its walkable
          int current_cell_id = PosToCellId(position(i, j));
          for (size_t a = 0; a < 4; a++)
            if (map_[i + x_dif[a]]
                    [j + y_dif[a]])  // If walkable append as connected
              graph_[current_cell_id].push_back(
                  PosToCellId(position(i + x_dif[a], j + y_dif[a])));
        }
  }

  int size_x_, size_y_;  /// Shape of map
  vvb map_;              /// 1 == walkable path, 0 == blocked
  position player_pos_, goal_pos_;
  vvi graph_;  /// Each element contains a vector of the connected nodes
};

};  // namespace sokoban

int main() {
  sokoban::Game game(6, 8);
  sokoban::Solvable solvable = game.ReadMap();
  std::string solution = "";
  if (solvable == sokoban::Solvable::unknown) {
    // TODO(oleguer): Solve it
  }

  switch (solvable) {
    case sokoban::Solvable::impossible:
      std::cout << "no path" << std::endl;
      break;
    case sokoban::Solvable::solved:
      std::cout << solution << std::endl;
      break;
  }
}
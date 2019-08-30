// Soku pathfinding
#include <stdlib.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace sokoban {
typedef std::pair<int, int> position;

enum class Solvable { solved, impossible, unknown };  // Solvability of the game
const std::map<char, std::string> map_elements = {
    {' ', "EMPTY"}, {'#', "WALL"}, {'.', "GOAL"},      {'@', "PLAYER"},
    {'+', "DONE"},  {'$', "WALL"}, {'*', "IMPOSSIBLE"}};

struct Node {
  position pos, parent_pos;
  std::vector<position> child_pos;
  int g, h = 0;

  int f() { return g + h; }

  // Returns Manhattan distance between passed and this node
  int ComputeDistance(const Node& node2) {
    h = std::abs(pos.first - node2.pos.first) +
        std::abs(pos.second - node2.pos.second);
  }
};

class Game {
 public:
  Game(const int& size_x, const int& size_y) {
    size_x_ = size_x;
    size_y_ = size_y;
    std::vector<std::vector<Node>> graph =
        std::vector(size_x, std::vector<Node>(size_y));
    for (size_t i = 0; i < graph.size(); i++)
      for (size_t j = 0; j < graph[0].size(); j++) {

      }
    graph_ = graph;
  }
  ~Game() {}

  // Populates map, player_pos and objective_pos
  // Returns either solved, impossible or unknown solvability
  Solvable ReadMap() {
    std::vector<std::vector<bool>> map = std::vector<std::vector<bool>>(
        size_x_, std::vector<bool>(size_y_, false));
    for (size_t i = 0; i < map.size(); i++) {
      for (size_t j = 0; j < map[0].size(); j++) {
        char c;
        std::cin >> c;
        std::string element = map_elements[c];
        if (element == "EMPTY" || element == "GOAL" || element == "PLAYER") {
          map[i][j] = true;
          if (element == "GOAL") start_pos_ = position(i, j);
          if (element == "PLAYER") goal_pos_ = position(i, j);
        }
        if (element == "DONE") return Solvable::solved;
        if (element == "IMPOSSIBLE") return Solvable::impossible;
      }
    }
    map_ = map;  // TODO(oleguer): Unnecessary copying?
    return Solvable::unknown;
  }

  Solvable FindPath(std::string* solution) {}

 private:
  // Populates graph_ private variable
  void BuildGraph() {
    // Get goal node to pre-compute euristics
    Node* goal_node = &graph_[goal_pos_.first][goal_pos_.second];
    goal_node->ComputeDistance(*goal_node);

    int x_dif[4] = {1, -1, 0, 0};
    int y_dif[4] = {0, 0, 1, -1};
    char movement = {"R", }
    for (size_t i = 0; i < map_.size(); i++)
      for (size_t j = 0; j < map_[0].size(); j++)  // Each elem of map
        if (map_[i][j]) {                          // If its walkable
          // Fill node info (h, child_ids)
          Node* current_node = &graph_[i][j];
          current_node->ComputeDistance(*goal_node);  // Aprox distance to goal
          for (size_t a = 0; a < 4; a++)  // Childs
            if (map_[i + x_dif[a]]
                    [j + y_dif[a]]) {  // If walkable append as connected
              current_node->child_pos.push_back(
                  position(i + x_dif[a], j + y_dif[a]));
            }
        }
  }

  int size_x_, size_y_;  /// Shape of map
  position start_pos_, goal_pos_;         /// Ids of the start and end nodes
  std::vector<std::vector<bool>> map_;    /// 1 == walkable path, 0 == blocked
  std::vector<std::vector<Node>> graph_;  // Stores node info
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
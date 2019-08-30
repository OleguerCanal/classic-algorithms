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

// Holds the position of a connection and the relative movement from parent to
// this node
struct Connection {
  position pos;
  char movement;
  Connection(const position& p, const char& move) {
    pos = p;
    movement = move;
  }
};

// Struct to hold Node info
struct Node {
  position pos;
  Connection parent;
  std::vector<Connection> child_pos;
  int g, h = 0;

  int f() { return g + h; }

  // Returns Manhattan distance between passed and this node
  int ComputeDistance(const Node& node2) {
    h = std::abs(pos.first - node2.pos.first) +
        std::abs(pos.second - node2.pos.second);
  }
};

// Struct to hold current game info
struct GameInfo {
  size_t size_x, size_y;  // Shape of map
  Solvable solvability = Solvable::unknown;
  position start_pos, goal_pos;          // Ids of the start and end nodes
  std::vector<std::vector<bool>> map;    // 1 == walkable path, 0 == blocked
  std::vector<std::vector<Node>> graph;  // Stores node info

  GameInfo(const int& x, const int& y) {
    size_x = x;
    size_y = y;
  }
};

GameInfo ReadMap(const size_t& size_x, const size_t& size_y) {
  GameInfo game_info(size_x, size_y);
  game_info.map =
      std::vector<std::vector<bool>>(size_x, std::vector<bool>(size_y, false));
  for (size_t i = 0; i < game_info.map.size(); i++)
    for (size_t j = 0; j < game_info.map[0].size(); j++) {
      char c;
      std::cin >> c;
      std::string element = map_elements[c];
      if (element == "EMPTY" || element == "GOAL" || element == "PLAYER") {
        game_info.map[i][j] = true;
        if (element == "GOAL") game_info.start_pos = position(i, j);
        if (element == "PLAYER") game_info.goal_pos = position(i, j);
      }
      if (element == "DONE") {
        game_info.solvability = Solvable::solved;
        return game_info;
      }
      if (element == "IMPOSSIBLE") {
        game_info.solvability = Solvable::impossible;
        return game_info;
      }
    }
  return game_info;
}

Solvable FindPath(std::string* solution) {}

// Populates graph_ private variable
void BuildGraph(GameInfo* game_info) {
  // Initialize graph
  std::vector<std::vector<Node>> graph(game_info->size_x,
                                       std::vector<Node>(game_info->size_y));
  game_info->graph = graph;

  // Get goal node to pre-compute euristics
  Node* goal_node = &(
      game_info->graph[game_info->goal_pos.first][game_info->goal_pos.second]);
  goal_node->ComputeDistance(*goal_node);

  int x_dif[4] = {1, -1, 0, 0};
  int y_dif[4] = {0, 0, 1, -1};
  char movement[4] = {'R', 'L', 'U', 'D'};
  for (size_t i = 0; i < game_info->size_x; i++)
    for (size_t j = 0; j < game_info->size_y; j++)  // Each elem of map
      if (game_info->map[i][j]) {                   // If its walkable
        // Fill node info (h, child_ids)
        Node* current_node = &(game_info->graph[i][j]);
        current_node->ComputeDistance(*goal_node);  // Aprox distance to goal
        for (size_t a = 0; a < 4; a++)              // Childs
          if (game_info
                  ->map[i + x_dif[a]]
                       [j + y_dif[a]]) {  // If walkable append as connected
            current_node->child_pos.push_back(
                Connection(position(i + x_dif[a], j + y_dif[a]), movement[a]));
          }
      }
}
};  // namespace sokoban

int main() {
  sokoban::GameInfo game = sokoban::ReadMap(6, 8);
  std::string solution = "";
  if (game.solvability == sokoban::Solvable::unknown) { // If solvability is unknown, solve it
    BuildGraph(&game);
    
  }

  switch (game.solvability) {
    case sokoban::Solvable::impossible:
      std::cout << "no path" << std::endl;
      break;
    case sokoban::Solvable::solved:
      std::cout << solution << std::endl;
      break;
  }
}
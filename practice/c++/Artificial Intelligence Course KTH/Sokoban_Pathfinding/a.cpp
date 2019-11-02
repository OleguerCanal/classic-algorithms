// Soku pathfinding
#include <stdlib.h>

#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace sokoban {
typedef std::pair<int, int> position;

enum class Solvable { solved, impossible, unknown };  // Solvability of the game

// Holds the position of a connection and the relative movement from parent to
// this node
struct Connection {
  Node* node;
  char movement;
  Connection(Node* n, const char& move) {
    node = n;
    movement = move;
  }
};

// Struct to hold Node info
struct Node {  // TODO(Oleguer): Remove position and use pointer for connections
  position pos;
  Connection parent;
  std::vector<Connection> child_pos;
  int f, g = std::numeric_limits<int>::max();
  int h = std::numeric_limits<int>::infinity();

  bool is_goal = false;
  bool is_goal = false;

  // Sets h to be Manhattan distance between passed and this node
  // We set the h value to be the minimum of the goals compared
  int ComputeDistance(const Node& node2) {
    int dist = std::abs(pos.first - node2.pos.first) +
               std::abs(pos.second - node2.pos.second);
    if (dist < h) h = dist;
  }
};

// Struct to hold current game info
struct GameInfo {
  size_t size_x, size_y;  // Shape of map
  Solvable solvability = Solvable::unknown;
  position start_pos;
  std::vector<position> goal_pos;        // Ids of the start and end nodes
  std::vector<std::vector<bool>> map;    // 1 == walkable path, 0 == blocked
  std::vector<std::vector<Node>> graph;  // Stores node info
  std::string solution = "";

  GameInfo(const int& x, const int& y) {
    size_x = x;
    size_y = y;
  }
};

GameInfo ReadMap(const size_t& size_x, const size_t& size_y) {
  std::map<char, std::string> map_elements = {
      {' ', "EMPTY"}, {'#', "WALL"}, {'.', "GOAL"},      {'@', "PLAYER"},
      {'+', "DONE"},  {'$', "WALL"}, {'*', "IMPOSSIBLE"}};

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
        if (element == "PLAYER") game_info.goal_pos.push_back(position(i, j));
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

// True if first Node a.h < b.h
bool compareF(const Node* a, const Node* b) { return a->f < b->f; }

// Apply A* to solve it
void FindPath(GameInfo* game_info) {
  std::set<Node*, decltype(compareF)> open;  // Open set to be sorted by f
  std::set<Node*> closed;
  std::set<Node*>::iterator closed_it;

  Node* node_start =
      &(game_info
            ->graph[game_info->start_pos.first][game_info->start_pos.second]);

  node_start->g = 0;        // g of first node initialization
  open.insert(node_start);  // Feed node_start into open list
  while (!open.empty) {
    Node* current_node = *open.begin();
    current_node->f = current_node->g + current_node->h;

    if (game_info->IsGoal(current_node)) {  // Check if we reached destination
      game_info->solvability = Solvable::solved;
      return;
    }

    for (size_t i = 0; i < current_node->child_pos.size(); ++i) {
      position successor_pos = current_node->child_pos[i].pos;
      Node* successor_node =
          &(game_info->graph[successor_pos.first][successor_pos.second]);
      int successor_current_cost = current_node->g + 1;
      if (open.find(successor_node) != open.end()) {  // IF NOT IN OPEN
        if (successor_node->g <= successor_current_cost)
          continue;  // We already found a better way to reach this
                     // node
      } else {
        closed_it = closed.find(successor_node);
        if (closed_it != closed.end()) {  // IF NOT IN CLOSED
          if (successor_node->g <= successor_current_cost)
            continue;  // Path found previously was shorter
          // Otherwise: We found a new better way to reach it, open it again
          closed.erase(closed_it);
          open.insert(successor_node);
        } else {                        // IF NOT IN CLOSED
          open.insert(successor_node);  // Add to open list to explore it
        }
        successor_node->g = successor_current_cost;
        successor_node->parent =
            Connection(current_node->pos, current_node->child_pos[i].movement);
      }
    }
    closed.insert(current_node);
  }
  game_info->solvability = Solvable::impossible;
  return;
}

void backtrack(GameInfo* game_info) {
  position end_position = game_info->goal_pos;
  Node* node = &(game_info->graph[end_position.first][end_position.second]);
  if (node->parent.pos.first == -1) return "";
  std::string track = "";
  while (node->pos != game_info->start_pos) {
    game_info->solution.insert(0, 1, node->parent.movement);
    game_info->solution.insert(0, 1, ' ');
    node = &(game_info->graph[node->parent.pos.first][node->parent.pos.second]);
  }
}

};  // namespace sokoban

int main() {
  sokoban::GameInfo game = sokoban::ReadMap(6, 8);
  std::string solution = "";
  if (game.solvability == sokoban::Solvable::unknown) {  // solve it
    sokoban::BuildGraph(&game);
    sokoban::FindPath(&game);
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
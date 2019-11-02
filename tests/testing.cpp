#include <stdlib.h>
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <stack>
#include <set>

// void printArray(int a[]) {
//     // Option 1:
//     int a_size = sizeof(a)/sizeof(a[0]);
//     for (int i = 0; i < a_size; i++)
//         std::cout << a[i] << std::endl;
        
//     // Option 2:
//     for(const int& val : a)
//         std::cout << val << std::endl;
// }

int main() {
    // int a[] = {1, 2, 3, 4};

  std::stack<int> st;

  st.push(1);
  st.push(2);
  st.push(3);

  while (!st.empty()) {
    std::cout << st.top() << std::endl;  // Returns top
    st.pop();  // Removes top
  }
  // Prints 3 2 1
}
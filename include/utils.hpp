#pragma once

#include <array>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

namespace utils
{
  const double pi = std::acos(-1);

  float sign(float v)
  {
    if (v < 0)
      return -1.f;
    if (v > 0)
      return 1.f;
    return 0.f;
  }

  // Start timer
  time_t tic()
  {
    return clock();
  }

  // Stop counting time and print timer
  void toc(time_t t, std::string print)
  {
    t = clock() - t;
    std::cout << "-->[TIME]: " << print << ": " << ((float)t) / CLOCKS_PER_SEC << '\n';
  }

  // Prints object
  void print(std::vector<int> vec)
  {
    for (size_t i = 0; i < vec.size(); i++)
      std::cout << vec[i] << " ";
    std::cout << std::endl;
  }
} // namespace utils

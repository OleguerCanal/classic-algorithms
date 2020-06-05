#include "basic_functions.hpp"

namespace basic{
  const double pi = std::acos(-1);


  float sign(float v) {
    if (v < 0) return -1.f;
    if (v > 0) return 1.f;
    return 0.f;
  }

  std::string get_timestamp(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y-%m-%d_%H:%M:%S",timeinfo);
    return std::string(buffer);
  }

  std::vector<std::string> split_string(std::string s,
                                        const std::string delimiter) {
      std::vector<std::string> list;
      size_t pos = 0;
      std::string token;
      while ((pos = s.find(delimiter)) != std::string::npos) {
          token = s.substr(0, pos);
          list.push_back(token);
          s.erase(0, pos + delimiter.length());
      }
      list.push_back(s);
      return list;
  }

  std::vector<std::string> get_files_in_path(const std::string dir){
    std::vector<std::string> files;
    glob_t glob_result;
    glob((dir+"*").c_str(), GLOB_TILDE, NULL, &glob_result);
    for(unsigned int i=0; i<glob_result.gl_pathc; ++i){
      // cout << glob_result.gl_pathi << endl;
      files.push_back(std::string(glob_result.gl_pathv[i]));
    }
    return files;
  }

  // Deletable stuff:
  time_t tic(){
    return clock();
  }

  // Stop counting time and print timer
  void toc(time_t t, std::string print){
    t = clock() - t;
    std::cout << "-->[TIME]: " << print << ": " << 
      ((float)t)/CLOCKS_PER_SEC << '\n';
  }
}

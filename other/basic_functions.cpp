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

  //Populate transform from rvec, tvec
  void get_camera_transform(const std::string filename , Eigen::Matrix4f &transform){
    std::string filecontent;
    std::ifstream infile;
    infile.open (filename);
    while(!infile.eof()) {
      getline(infile, filecontent); // Saves the line in STRING.
    }
    infile.close();

    std::string delimiter = ",";
    std::vector<float> values;
    size_t pos = 0;
    std::string token;
    while ((pos = filecontent.find(delimiter)) != std::string::npos) {
        token = filecontent.substr(0, pos);
        values.push_back(std::strtof((token).c_str(),0));
        filecontent.erase(0, pos + delimiter.length());
    }

    std::vector<float> rvec;
    std::vector<float> tvec2;
    for(int i=0; i<3; i++) rvec.push_back(values[i]);
    for(int i=0; i<3; i++) tvec2.push_back(values[3+i]);

    cv::Mat R;
    cv::Rodrigues(rvec, R);

    cv::Mat tvec = cv::Mat(tvec2);
    tvec = R.t()*tvec;
    
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++) transform (i, j) = R.at<float>(j, i);
      transform (i, 3) = - tvec.at<float>(0, i)*0.001;
    }
  }


  // // Simple CSV managing ########################################################
  // void ParseCSV(const std::string& filename, std::vector<std::vector<std::string>>& traj){
  //   std::ifstream data(filename);
  //   std::string line;
  //   // std::vector<std::vector<float>> traj;
  //   while(std::getline(data,line)){
  //       std::stringstream lineStream(line);
  //       std::string cell;
  //       std::vector<std::string> parsedRow;
  //       while(std::getline(lineStream,cell,',')){
  //         parsedRow.push_back(cell);
  //       }
  //       traj.push_back(parsedRow);
  //   }
  // }

  // std::string get_db_field(const std::string shoe_id, const std::string field_name, const std::vector<std::vector<std::string>> &shoe_db){
  //   int field_col = -1;
  //   for(int i=0; i<shoe_db[0].size(); i++){
  //     // std::cout << shoe_db[0][i] << '\n';
  //     if(shoe_db[0][i] == field_name){ // we assume first row is header
  //       field_col = i;
  //       break;
  //     }
  //   }
  //   // std::cout << field_col << '\n';
  //   for(int i=1; i<shoe_db.size(); i++)
  //     if(shoe_db[i][0] == shoe_id)  // we assume first col is shoe_id
  //       return shoe_db[i][field_col];

  //   return "ERROR";
  // }

  // void set_db_field(const std::string shoe_id, const std::string field_name, const std::string field, std::vector<std::vector<std::string>> &shoe_db){
  //   int field_col;
  //   for(int i=0; i<shoe_db[0].size(); i++)
  //     if(shoe_db[0][i] == field_name){ // we assume first row is header
  //       field_col = i;
  //       break;
  //     }

  //   for(int i=1; i<shoe_db.size(); i++)
  //     if(shoe_db[i][0] == shoe_id) {  // we assume first col is shoe_id
  //       shoe_db[i][field_col] = field;
  //       return;
  //     }
  // }

  // void save_shoe_db(const std::string filename, const std::vector<std::vector<std::string>> &shoe_db){
  //   std::ofstream ofs;
  //   ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
  //   for (const auto &e : shoe_db) ofs << e[0] << "," << e[1] << "," << e[2] << "," << e[3] << "," << e[4] << "," << e[5] << "\n"; // First
  //   ofs.close();
  // }
}

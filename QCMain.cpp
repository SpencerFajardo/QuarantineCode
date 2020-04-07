#include "QC.h"
#include <iostream>

int main(int argv, char** argc){
  // create QC object and great myself!
  QC qc;
  std::cout << "----------------" << "\n";
  std::cout << "\n";
  std::cout << "Hello, Spencer!" << std::endl; 
  
  // use my methods
  std::cout << std::endl;
  std::string date_string = qc.todays_date();
  std::cout << date_string << std::endl;
  std::string days_string = qc.days_spent_in_quarantine();
  std::cout << days_string << std::endl;

  std::string file_name = qc.make_file_title();
  // std::cout << file_name;

  // make these file write lines
  //std::cout << "----------------" << "\n";
  //std::cout << "\n";
  //std::cout << "Hello, Spencer!" << std::endl; 
  
  // use my methods
  //std::cout << std::endl;
  //std::cout << date_string << std::endl;
  //std::cout << days_string << std::endl;
  // file write info found here : https://stackoverflow.com/questions/347949/how-to-convert-a-stdstring-to-const-char-or-char
  //const char * file_name_2 = file_name.c_str();

  //FILE *f = fopen("file_name.txt", "w");
  //if (f == NULL)
  //{
    //printf("Error opening file!\n");
    //exit(1);
  //}

  // print some text 
  //const char *text = "Write this to the file";
  //fprintf(f, "Some text: %s\n", text);

  // print integers and floats 
  //int i = 1;
  //float py = 3.1415927;
  //fprintf(f, "Integer: %d, float: %f\n", i, py);

  // printing single chatacters 
  //char c = 'A';
  //fprintf(f, "A character: %c\n", c);

  //fclose(f);

  return 0;
}

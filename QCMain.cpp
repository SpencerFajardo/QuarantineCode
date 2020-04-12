#include "QC.h"
#include <iostream>

int main(int argv, char** argc)
{
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
  qc.write_file();

  return 0;
}

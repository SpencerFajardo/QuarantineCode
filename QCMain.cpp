#include "QC.h"
#include <iostream>

int main(int argv, char** argc){
  // create QC object and great myself!
  QC qc;
  std::cout << "----------------" << "\n";
  std::cout << "\n";
  std::cout << "Hello, Spencer!" << "\n"; 
  
  // use my methods
  qc.todays_date();
  qc.days_spent_in_quarantine();
  std::cout << "\n";
  return 0;
}

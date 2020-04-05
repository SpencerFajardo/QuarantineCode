#include "QC.h"
#include <iostream>

int main(int argv, char** argc){
  QC qc;
  std::cout << "\n";
  std::cout << "Hello, Spencer!" << "\n"; 
  qc.todays_date();
  qc.days_spent_in_quarantine();
  return 0;
}

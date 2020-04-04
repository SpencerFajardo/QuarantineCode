#include "QC.h"
#include <ctime>
#include <iostream>
#include <sstream>

// This method prints the current date at the time of calling it.
void QC::todays_date(){
  // time object
  time_t current_time;
  time(&current_time);

  // print date from time object 
  std::string test = ctime(&current_time);
  std::cout << "\n";
  std::cout << "Today's Date: " << test << "\n";
}

// This method will tell you the number of days you have spent in quarantine.
// Some assumptions:
// 1. Quarantine started Martch 14th, 2020
// 2. The tally is only correct until November 30th, 2020.
void QC::days_spent_in_quarantine(){
   // time object
  time_t current_time;
  time(&current_time);

  // print date from time object, also prove that we can extract things
  std::string test = ctime(&current_time);
  std::cout << "\n";
  std::string test2 = test.substr(8,2);

  // this section shows how to convert string to int
  std::stringstream geek (test2);
  int x = 0;
  geek >> x; // I added this comment really easily using vim!

  // here we need to add a switch statement to tally up the number of days
  // if we are considering the number of days in the months that have passed
  // since March 14th
  switch (x)
  {
    case 4: x = x + 18;
            break;
    case 5: x = x + 48;
            break;
    case 6: x = x + 79;
            break;
    case 7: x = x + 109;
            break;
    case 8: x = x + 140;
            break;
    case 9: x = x + 171;
            break;
    case 10: x = x + 201;
  }
  
  std::cout << "Days in quarantine: " << x << "\n";
}
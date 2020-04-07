#include "QC.h"
#include <ctime>
#include <iostream>
#include <sstream>

// This method creates a string with the current date
// returns return_string with the date
std::string QC::todays_date(){
  // time object
  time_t current_time;
  time(&current_time);

  // return the date_string to the main program to print.
  std::string date_string = ctime(&current_time);
  std::string return_string = "Today's Date: " + date_string;
  return return_string;
}

// This method will tell you the number of days you have spent in quarantine.
// Some assumptions:
// 1. Quarantine started Martch 14th, 2020
// 2. The tally is only correct until November 30th, 2020.
std::string QC::days_spent_in_quarantine(){
   // time object
  time_t current_time;
  time(&current_time);

  // print date from time object, also prove that we can extract things
  std::string day_extract_string = ctime(&current_time);
  std::string day_string = day_extract_string.substr(8,2);
  std::string month_string = day_extract_string.substr(4,3);

  // this section shows how to convert string to int
  std::stringstream geek (day_string);
  int x = 0;
  geek >> x; // I added this comment really easily using vim!

  // here we need to add a switch statement to tally up the number of days
  // if we are considering the number of days in the months that have passed
  // since March 14th
  if(strcmp(month_string.c_str(),"Apr") == 0)
  {
     x = x + 18;
  }
  else if(strcmp(month_string.c_str(),"May") == 0)
  {
     x = x + 48;
  }
  else if(strcmp(month_string.c_str(),"Jun") == 0)
  {
     x = x + 79;
  }
  else if(strcmp(month_string.c_str(),"July") == 0)
  {
     x = x + 109;
  }
  else if(strcmp(month_string.c_str(),"Aug") == 0)
  {
     x = x + 140;
  }
  else if(strcmp(month_string.c_str(),"Sep") == 0)
  {
     x = x + 171;
  }
  else if(strcmp(month_string.c_str(),"Oct") == 0)
  {
     x = x + 201;
  }
  
  std::string return_string = "Days in quarantine: " + std::to_string(x);
  return return_string;

}

std::string QC::make_file_title()
{
  time_t current_time;
  time(&current_time);

  // print date from time object, also prove that we can extract things
  std::string day_extract_string = ctime(&current_time);
  std::string day_string = day_extract_string.substr(8,2);
  std::string month_string = day_extract_string.substr(4,3);

  std::stringstream geek (day_string);
  int day_int = 0;
  geek >> day_int;

  std::string return_string = month_string + std::to_string(day_int);
  return return_string;
}
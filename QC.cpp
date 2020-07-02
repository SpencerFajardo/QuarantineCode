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
// Edit: The count was incorrect on July 1, 2020. This was fixed on
// the same day. I was checking for "July" on line 56, when it should
// have been "Jul".
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
  else if(strcmp(month_string.c_str(),"Jul") == 0)
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

// make_file_title uses the current date to make a name for
// the file qc will write to, using the format month_day.txt.
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

  std::string return_string = month_string + "_" + std::to_string(day_int) + ".txt";
  return return_string;
}

// write_file takes the same information thats output by the main method,
// and puts the text into a file.
void QC::write_file()
{
   // file write info found here : https://stackoverflow.com/questions/347949/how-to-convert-a-stdstring-to-const-char-or-char
  std::string file_name = make_file_title();
  const char * file_name_2 = file_name.c_str();
  FILE *f = fopen(file_name_2, "w");
  if (f == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }

  //print some text 
  const char *text = "----------------";
  fprintf(f, "%s\n", text);
  const char *text2 = "";
  fprintf(f, "%s\n", text2);
  const char *text3 = "Hello, Spencer!";
  fprintf(f, "%s\n", text3);
  
  const char *text4 = "";
  fprintf(f, "%s\n", text4);

  std::string date_string = todays_date();
  const char *text5 = date_string.c_str();
  fprintf(f, "%s\n", text5);

  std::string days_string = days_spent_in_quarantine();
  const char *text6 = days_string.c_str();
  fprintf(f, "%s\n", text6);

  fclose(f);
}

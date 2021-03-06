"""
coronavirus_scraper.py

Reads data from wiki table and prints it to terminal. Also writes to a file.

Author: Spencer
"""

from bs4 import BeautifulSoup
import re
import requests
import os

# This is the main method, that tells the scraper to run.
def main():
   get_infection_information()

# This is the method that does the heavy lifting.
# It scrapes a wikipedia page with a table of coronavirus
# cases per country. Then, it adds all the cases up 
# and prints the value.
def get_infection_information():
   # This is the url for the wiki page with the necessary information
   url = "https://en.wikipedia.org/wiki/Template:2019–20_coronavirus_pandemic_data" 
   
   # Requests allows us to search for url
   r = requests.get(url)
   soup = BeautifulSoup(r.content, 'html.parser')
   # This searches through the soup to find the tables
   tables = soup.find_all('table')

   #Create array to hold the data we extract
   cases = []

   for table in tables:
       rows = table.find_all('tr')
    
       for row in rows:
            cells = row.find_all('td')
        
        
            if len(cells) > 1:
               # cells[0] holds the case counts
               case = cells[0]

               # I had some issues here. For some reason
               # I was getting the cases information,
               # and then some additional stuff afterwards.
               # My fix was to add things until the process_num
               # funtion didn't work, and then to exit the loop.
               try:
                  cases.append(process_num(case.text.strip()))
               except ValueError:
                  break
   # Add all cases, and then print
   total = 0
   for case in cases:
      total = total + case
   print()
   print("Coronavirus Cases World Total: " + str(total))
   print()
   print("----------------")
   
   # print to file as well
   write_file(total) 

# Writes information to a file.
# The file is initially started in the C++ part
# of this project, so this method first
# finds the only (supposedly) .txt file in the current
# directory and appends the case count to the file.
def write_file(total):
   all_files = os.listdir()
   txt_files = filter(lambda x: x[-4:] == ".txt", all_files)
   for i in txt_files:
      f = open(i, "a")
      f.write("\n")
      f.write("Coronavirus Cases World Total: " + str(total))
      f.write("\n")
      f.write("\n")
      f.write("----------------")
      f.write("\n")
      f.close()


# This method processes the strings from the table, and prepares
# them to be just numbers
def process_num(num):
   return float(re.sub(r'[^\w\s.]','',num))

main()

from bs4 import BeautifulSoup
import re
import requests

def main():
   get_infection_information()

def get_infection_information():
   # We have to find out what the url is for the JHU interactive map.
   url = "https://en.wikipedia.org/wiki/Template:2019–20_coronavirus_pandemic_data" 
   
   # Requests allows us to search for url
   r = requests.get(url)
   soup = BeautifulSoup(r.content, 'html.parser')
   tables = soup.find_all('table')

   #Create array to hold the data we extract
   cases = []

   for table in tables:
       rows = table.find_all('tr')
    
       for row in rows:
            cells = row.find_all('td')
        
        
            if len(cells) > 1:
                case = cells[0]
                print(process_num(case.text.strip()))
                cases.append(case)


def process_num(num):
   return float(re.sub(r'[^\w\s.]','',num))

main()
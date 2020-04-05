from bs4 import BeautifulSoup
import requests

def main():
   print("This information is scraped from the Johns Hopkins Interactive Map")
   get_infection_information()

def get_infection_information():
   # We have to find out what the url is for the JHU interactive map.
   url = "https://www.worldometers.info/coronavirus/"
   
   # Requests allows us to search for url
   r = requests.get(url)
   soup = BeautifulSoup(r.content, 'html.parser')
   print(soup.prettify())

main()
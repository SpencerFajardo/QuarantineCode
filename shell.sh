make
./qc 
python coronavirus_scraper.py > scrape.txt
cat scrape.txt | grep "Last updated" > cases.txt
cat cases.txt

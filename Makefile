QCMain: QCMain.o QC.o
	g++ -o qc QCMain.o QC.o -I .

QCMain.o: QCMain.cpp QC.o
	g++ -c QCMain.cpp -I .

QC.o: QC.cpp QC.h
	g++ -c QC.cpp -I .

clean:
	rm *.o

finalFileAnalysis: finalFileAnalysis.o fileAnalysis.o
	clang -o finalFileAnalysis finalFileAnalysis.o fileAnalysis.o

finalFileAnalysis.o: finalFileAnalysis.c fileAnalysis.h
	clang -c finalFileAnalysis.c

fileAnalysis.o: fileAnalysis.c fileAnalysis.h
	clang -c fileAnalysis.c

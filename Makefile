wordCount:
	g++ -o WordCount wordCount.cpp

groupVector:
	g++ -o GroupVector groupVector.cpp
	./GroupVector 1 1 1 1 0 1 0 1 1 0 1 1 1 0 0

nextSubString:
	g++ -o NextSubString nextSubString.cpp
	./NextSubString heyhey-friend 1 hey

clean:
	rm -f WordCount
	rm -f GroupVector
	rm -f NextSubstring
wordCount:
	g++ -o WordCount wordCount.cpp

groupVector:
	g++ -o GroupVector groupVector.cpp
	./GroupVector 1 1 1 1 0 1 0 1 1 0 1 1 1 0 0

clean:
	rm -f WordCount
	rm -f GroupVector
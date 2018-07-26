apa:*.cpp
	g++ -std=c++14 *.cpp -o apa

.PHONY: clean

clean:
	rm apa

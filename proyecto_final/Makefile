all: ramdom_example.x ejecutar

%.x: ramdom_example.cpp
	g++ -std=c++11 -Wall $< -o ramdom_example.x

ejecutar:
	./ramdom_example.x




.PHONY: clean
clean:
	rm -f *.x *~ a.out *.pdf *.gp *.dat 

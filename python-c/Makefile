all:
	g++ -O3 -Wall -shared -std=c++11 -fPIC $(shell python3 -m pybind11 --includes) main.cpp -o trypython$(shell python3-config --extension-suffix)
run:
	python3 ./pytest.py
clean:
	rm -f *.so

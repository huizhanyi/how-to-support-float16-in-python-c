all:
	g++ -O3 -Wall -shared -std=c++11 -fPIC $(shell python3 -m pybind11 --includes) trypython.cpp -o trypython$(shell python3-config --extension-suffix)
run:
	python3 ./pytest.py

all:
	g++ -shared -fPIC -std=c++17 $(shell python3 -m pybind11 --includes) -I./half-2.2.0/include -o example$(shell python3-config --extension-suffix) main.cpp
run:
	python3 ./pytest.py
clean:
	rm -f *.so

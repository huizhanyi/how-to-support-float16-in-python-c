PYTHON_HEADER_DIR := $(shell python3 -c 'from distutils.sysconfig import get_python_inc; print(get_python_inc())')
INCLUDES = -I ${PYTHON_HEADER_DIR}
INCLUDES += -I /usr/local/lib/python3.8/dist-packages/torch/include -I /usr/local/lib/python3.8/dist-packages/torch/include/torch/csrc/api/include
LIBS = -L/usr/local/lib/python3.8/dist-packages/torch/lib
all:
	g++ -DTORCH_API_INCLUDE_EXTENSION_H -D_GLIBCXX_USE_CXX11_ABI=0 -fPIC -std=c++17 -shared ${INCLUDES} -o mymodule.so main.cpp ${LIBS} -lc10 -ltorch_cpu -ltorch -ltorch_python
run:
	python3 ./pytest.py

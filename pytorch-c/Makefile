PYTHON_HEADER_DIR := $(shell python3 -c 'from distutils.sysconfig import get_python_inc; print(get_python_inc())')
INCLUDES = -I ${PYTHON_HEADER_DIR}
SITE_PATH=$(shell python -c "import site; print(site.getsitepackages()[0])")
INCLUDES += -I ${SITE_PATH}/torch/include -I ${SITE_PATH}/torch/include/torch/csrc/api/include
LIBS = -L${SITE_PATH}/torch/lib
all:
	g++ -DTORCH_API_INCLUDE_EXTENSION_H -D_GLIBCXX_USE_CXX11_ABI=0 -fPIC -std=c++17 -shared ${INCLUDES} -o mymodule.so main.cpp ${LIBS} -lc10 -ltorch_cpu -ltorch -ltorch_python
run:
	python3 ./pytest.py
clean:
	rm -f *.so

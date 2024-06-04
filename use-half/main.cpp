// ref: https://github.com/pybind/pybind11/issues/1776
//      https://github.com/eacousineau/repro/blob/43407e3/python/pybind11/custom_tests/test_numpy_issue1776.cc#L21-L29
//      https://gitlab.com/-/snippets/2519639
#include <iostream>
#include <type_traits>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

#include "half.hpp"  /* from https://half.sourceforge.net/ */
using half = half_float::half;
static_assert(sizeof(half) == 2, "Bad half size");

namespace pybind11 {
    namespace detail {
        template <>
        struct npy_format_descriptor<half> {
          static constexpr auto name = _("float16");
          static pybind11::dtype dtype() {
            handle ptr = npy_api::get().PyArray_DescrFromType_(23);  /* import numpy as np; print(np.dtype(np.float16).num */
            return reinterpret_borrow<pybind11::dtype>(ptr);
          }
          static std::string format() {
            return "e";
          }
        };
    }
}

template<typename T>
void multiply(py::array_t<T>& data) {
    auto data_ptr = static_cast<T*>(data.request().ptr);
    auto size = data.size();
    std::cout << std::hex << data_ptr << std::endl;
    for (int i = 0; i < size; i++) {
        if constexpr (std::is_same_v<T, long double>) { data_ptr[i] *= T(5); }
        else if constexpr (std::is_same_v<T, double>) { data_ptr[i] *= T(4); }
        else if constexpr (std::is_same_v<T, float>)  { data_ptr[i] *= T(3); }
        else if constexpr (std::is_same_v<T, half>)   { data_ptr[i] *= T(2); }
    }
}


PYBIND11_MODULE(example, m) {
    m.def("multiply", &multiply<half>);
    m.def("multiply", &multiply<float>);
    m.def("multiply", &multiply<double>);
    m.def("multiply", &multiply<long double>);
}

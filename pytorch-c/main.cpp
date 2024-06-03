#include <torch/extension.h>

at::Tensor test(const at::Tensor& a, const at::Tensor& b, double c) {
  TORCH_CHECK(a.sizes() == b.sizes());
  TORCH_CHECK(a.dtype() == at::kFloat);
  TORCH_CHECK(b.dtype() == at::kFloat);
  TORCH_INTERNAL_ASSERT(a.device().type() == at::DeviceType::CPU);
  TORCH_INTERNAL_ASSERT(b.device().type() == at::DeviceType::CPU);
  at::Tensor a_contig = a.contiguous();
  at::Tensor b_contig = b.contiguous();
  at::Tensor result = torch::empty(a_contig.sizes(), a_contig.options());
  const float* a_ptr = a_contig.data_ptr<float>();
  const float* b_ptr = b_contig.data_ptr<float>();
  float* result_ptr = result.data_ptr<float>();
  for (int64_t i = 0; i < result.numel(); i++) {
    result_ptr[i] = a_ptr[i] * b_ptr[i] + c;
  }
  return result;
}

void test_half(const at::Tensor& a) {
  TORCH_CHECK(a.dtype() == at::kHalf);
  at::Tensor a_contig = a.contiguous();
  const at::Half* a_ptr = a_contig.data_ptr<at::Half>();
  std::cout << "C++ " << std::hex << a_ptr << std::endl;

}

PYBIND11_MODULE(mymodule, m) {
  m.def("test", torch::wrap_pybind_function(test), "test");
  m.def("test_half", torch::wrap_pybind_function(test_half), "test float16");
}

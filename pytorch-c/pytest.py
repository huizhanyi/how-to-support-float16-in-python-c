import torch
import mymodule
a = torch.tensor([1,2], dtype=torch.float32)
b = torch.tensor([1,2], dtype=torch.float32)
print(hex(a.data_ptr()))
c = mymodule.test(a, b, 1)
print(c)

x = torch.tensor([1,2], dtype=torch.float16)
print(hex(x.data_ptr()))
mymodule.test_half(x)

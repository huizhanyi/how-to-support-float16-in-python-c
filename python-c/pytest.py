import numpy as np
import trypython
a = np.array([1,2,3], dtype=np.float16)
b = np.array([1,2,3], dtype=np.float16)
a_addr = a.ctypes.data
b_addr = b.ctypes.data
print("python a: ", hex(a_addr))
print("python b: ", hex(b_addr))
map = {"a" : a_addr, "b" : b_addr}
x = trypython.add_arrays(a, b, map)
print(x)

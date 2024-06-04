import pybind11
import numpy as np
import example

def test_multiply(example):
    input128 = np.array([[1.0, 2.0], [3.0, 4.0]], dtype=np.float128)
    output128 = input128.copy()
    print(hex(output128.ctypes.data))
    example.multiply(output128)
    print('float128', abs(output128 - 5*input128).max())
    assert np.allclose(output128, 5*input128)

    input64 = np.array([[1.0, 2.0], [3.0, 4.0]], dtype=np.float64)
    output64 = input64.copy()
    print(hex(output64.ctypes.data))
    example.multiply(output64)
    print('float64 ', abs(output64 - 4*input64).max())
    assert np.allclose(output64, 4*input64)

    input32 = np.array([[1.0, 2.0], [3.0, 4.0]], dtype=np.float32)
    output32 = input32.copy()
    print(hex(output32.ctypes.data))
    example.multiply(output32)
    print('float32 ', abs(output32 - 3*input32).max())
    assert np.allclose(output32, 3*input32)

    input16 = np.array([[1.0, 2.0], [3.0, 4.0]], dtype=np.float16)
    output16 = input16.copy()
    print(hex(output16.ctypes.data))
    example.multiply(output16)
    print('float16 ', abs(output16 - 2*input16).max())
    assert np.allclose(output16, 2*input16)

if __name__ == "__main__":
    test_multiply(example)


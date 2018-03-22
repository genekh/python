import unittest
from test_env import TestEnv
import numpy as np

from pythran.typing import NDArray


@TestEnv.module
class TestBroadcasting(TestEnv):

    def test_broadcast_scalar0(self):
        self.run_test('def broadcast_scalar0(x): return x + 1',
                      np.arange(12000),
                      broadcast_scalar0=[NDArray[int, :]])

    def test_broadcast_scalar1(self):
        self.run_test('def broadcast_scalar1(x): return x + 1',
                      np.arange(12000).reshape(40, 300),
                      broadcast_scalar1=[NDArray[int, :, :]])

    def test_broadcast_array0(self):
        self.run_test('def broadcast_array0(x, y): return x + y',
                      np.arange(12000).reshape(40,300),
                      np.arange(300),
                      broadcast_array0=[NDArray[int,:,:], NDArray[int,:]])

    def test_broadcast_array1(self):
        self.run_test('def broadcast_array1(x, y): return x + y',
                      np.arange(12000).reshape(4,30,100),
                      np.arange(100),
                      broadcast_array1=[NDArray[int,:,:,:], NDArray[int,:]])

    def test_broadcast_same_dim0(self):
        self.run_test('def broadcast_same_dim0(x, y): return x + y',
                      np.arange(12000).reshape(40,300),
                      np.arange(300).reshape(1,300),
                      broadcast_same_dim0=[NDArray[int, :, :], NDArray[int, :, :]])

    def test_broadcast_same_dim1(self):
        self.run_test('def broadcast_same_dim1(x, y): return x + y',
                      np.arange(12000).reshape(40,300),
                      np.arange(300),
                      broadcast_same_dim1=[NDArray[int, :, :], NDArray[int, :]])

    def test_broadcast_both_dims(self):
        self.run_test('def broadcast_both_dims(x, y): return x + y',
                      np.arange(100).reshape(1,100),
                      np.arange(100).reshape(100, 1),
                      broadcast_both_dims=[NDArray[int, :, :], NDArray[int, :, :]])

    def test_broadcast_update_scalar0(self):
        self.run_test('def broadcast_update_scalar0(x):  x += 1; return x',
                      np.arange(12000),
                      broadcast_update_scalar0=[NDArray[int, :]])

    def test_broadcast_update_scalar1(self):
        self.run_test('def broadcast_update_scalar1(x): x += 1; return x',
                      np.arange(12000).reshape(40, 300),
                      broadcast_update_scalar1=[NDArray[int, :, :]])

    def test_broadcast_update_array0(self):
        self.run_test('def broadcast_update_array0(x, y): x += y ; return x',
                      np.arange(12000).reshape(40,300),
                      np.arange(300),
                      broadcast_update_array0=[NDArray[int, :, :], NDArray[int, :]])

    def test_broadcast_update_array1(self):
        self.run_test('def broadcast_update_array1(x, y): x += y; return x',
                      np.arange(12000).reshape(4,30,100),
                      np.arange(100),
                      broadcast_update_array1=[NDArray[int, :, :,:], NDArray[int, :]])

    def test_broadcast_update_same_dim0(self):
        self.run_test('def broadcast_update_same_dim0(x, y): x += y; return x',
                      np.arange(12000).reshape(40,300),
                      np.arange(300).reshape(1,300),
                      broadcast_update_same_dim0=[NDArray[int, :, :], NDArray[int, :, :]])

    def test_broadcast_update_same_dim1(self):
        self.run_test('def broadcast_update_same_dim1(x, y): x += y; return x',
                      np.arange(12000).reshape(40,300),
                      np.arange(300),
                      broadcast_update_same_dim1=[NDArray[int, :, :], NDArray[int, :]])

    def test_broadcast_compute_scalar0(self):
        self.run_test('def broadcast_compute_scalar0(x): return -(x + 1)',
                      np.arange(12000),
                      broadcast_compute_scalar0=[NDArray[int, :]])

    def test_broadcast_compute_scalar1(self):
        self.run_test('def broadcast_compute_scalar1(x): return -(x + 1)',
                      np.arange(12000).reshape(40, 300),
                      broadcast_compute_scalar1=[NDArray[int, :, :]])

    def test_broadcast_compute_array0(self):
        self.run_test('def broadcast_compute_array0(x, y): return -(x + y)',
                      np.arange(12000).reshape(40,300),
                      np.arange(300),
                      broadcast_compute_array0=[NDArray[int, :, :], NDArray[int, :]])

    def test_broadcast_compute_array1(self):
        self.run_test('def broadcast_compute_array1(x, y): return -(x + y)',
                      np.arange(12000).reshape(4,30,100),
                      np.arange(100),
                      broadcast_compute_array1=[NDArray[int, :, :, :], NDArray[int, :]])

    def test_broadcast_compute_same_dim0(self):
        self.run_test('def broadcast_compute_same_dim0(x, y): return -(x + y)',
                      np.arange(12000).reshape(40,300),
                      np.arange(300).reshape(1,300),
                      broadcast_compute_same_dim0=[NDArray[int, :, :], NDArray[int, :, :]])

    def test_broadcast_compute_same_dim1(self):
        self.run_test('def broadcast_compute_same_dim1(x, y): return -(x + y)',
                      np.arange(12000).reshape(40,300),
                      np.arange(300),
                      broadcast_compute_same_dim1=[NDArray[int, :, :], NDArray[int, :]])

    def test_broadcast_compute_both_dims(self):
        self.run_test('def broadcast_compute_both_dims(x, y): return -(x + y)',
                      np.arange(100).reshape(1,100),
                      np.arange(100).reshape(100, 1),
                      broadcast_compute_both_dims=[NDArray[int, :, :], NDArray[int, :, :]])

    def test_broadcast_sum(self):
        code = '''
        def broadcast_sum(x, y):
            n = x.size
            return (x.reshape(n, 1) * y.reshape(1, n)).sum()
        '''
        self.run_test(code,
                      np.arange(100).reshape(1,100),
                      np.arange(100).reshape(100, 1),
                      broadcast_sum=[NDArray[int, :, :], NDArray[int, :, :]])

    def test_broadcast_sum_axis(self):
        code = '''
            import numpy as np
            def broadcast_sum_axis(forecasted_array, observed_array):
                return np.abs(forecasted_array[:, None] - observed_array).sum()
            '''
        self.run_test(code,
                      np.arange(100.),
                      np.arange(100.),
                      broadcast_sum_axis=[NDArray[float, :], NDArray[float, :]])

#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j) { return i + j; }

PYBIND11_MODULE(pybind_test_lib, m) {
    m.doc() = "It's testing.";
    m.def("add", &add, "Simple add function.");
}

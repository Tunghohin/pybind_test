#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j) { return i + j; }

PYBIND11_MODULE(test, m) {
    m.doc() = "It's testing.";
    m.def("add", &add, "Simple add function.");
}

#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j) { return i + j; }

struct Node {
    Node(std::string const& name) : name_(name) {}
    auto set_name(std::string const& name) -> void { name_ = name; }
    auto get_name() -> std::string const& { return name_; }
    
    std::string name_;
    int const ID = 42;
};

PYBIND11_MODULE(pybind_test_lib, m) {
    m.doc() = "It's testing.";
    m.def(
        "add", &add, 
        "Simple add function.",
        py::arg("i"), py::arg("j")
    );
    m.attr("magic") = 233;

    py::class_<Node>(m, "Node")
        .def(py::init<std::string const&>())
        .def("set_name", &Node::set_name)
        .def("get_name", &Node::get_name)
        .def_readwrite("name", &Node::name_)
        .def_readonly("id", &Node::ID);
}

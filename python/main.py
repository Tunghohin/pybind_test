import pybind_test as pyt

if __name__ == "__main__":
    print(pyt.core.add(2, 3))
    print(pyt.core.magic)

    a = pyt.core.Node("Mola")
    print(a.get_name())
    a.set_name("MolaMola")
    print(a.get_name())
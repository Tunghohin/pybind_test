.PHONY : install-python
install-python:
	pip uninstall pybind_test
	mkdir -p pybind_test
	cp ./pyproject.toml ./pybind_test
	mkdir -p ./pybind_test/src
	mkdir -p ./pybind_test/src/pybind_test
	rm ./pybind_test/src/pybind_test/pybind_test*.so -rf
	cp ./build/$(TYPE)/pybind_test*.so ./pybind_test/src/pybind_test/
	pip install -e ./pybind_test
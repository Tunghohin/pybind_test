.PHONY : build install-python

build:
	/usr/bin/cmake --build /home/sgimage/Labs/pybind_test/build --config Debug --target all

install-python: build
	yes | pip uninstall pybind_test
	mkdir -p pybind_test
	cp ./pyproject.toml ./pybind_test
	mkdir -p ./pybind_test/src
	mkdir -p ./pybind_test/src/pybind_test
	rm ./pybind_test/src/pybind_test/pybind_test*.so -rf
	cp ./build/$(TYPE)/pybind_test*.so ./pybind_test/src/pybind_test/
	pip install -e ./pybind_test
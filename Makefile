.PHONY : install-python
install-python:
	mkdir -p test
	cp ./build/$(TYPE)/pybind_test*.so ./test
	pip install -e ./test
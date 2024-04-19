prepare: 
	mkdir buildLinux
	cmake -S . -B buildLinux/

prepare_all: 
	mkdir buildLinux
	cmake -S . -B buildLinux/ -DBUILD_TESTING=True -DCLANG_TIDY=True -DENABLE_VALGRIND=True

build_app:
	cd buildLinux/ && make -j

rebuild: 
	cmake -S . -B buildLinux/
	cd buildLinux/ && make -j

clean:
	rm -rf buildLinux/

run:
	./buildLinux/bin/MyProject

rerun: rebuild run

run_test:
	./buildLinux/bin/MyProjectTests -v

# Build app, tests and run tests
all: clean prepare_all build_app run_test

# Build app without tests
build: clean prepare build_app
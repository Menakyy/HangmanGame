prepare: 
	mkdir buildLinux
	cmake -S . -B buildLinux/

build:
	cd buildLinux/ && make -j

rebuild: 
	cmake -S . -B buildLinux/
	cd buildLinux/ && make -j

clean:
	rm -rf buildLinux/

run:
	./buildLinux/bin/MyProject

runtest:
	./buildLinux/bin/MyProjectTests

all: clean prepare build
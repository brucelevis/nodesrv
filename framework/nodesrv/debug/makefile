
gatesrv:
	bin/gatesrv gatesrv1

scenesrv:
	bin/scenesrv scenesrv1

clean:
	cd ../gatesrv;make clean

nodesrv:
	cd ../../../src/engine;make clean;make

install:
	rm -rf bin/gatesrv
	ln -s ../../gatesrv/gatesrv bin/gatesrv


gatesrv:
	cd ../gatesrv;make tolua;make
	proc/gatesrv1/gatesrv

clean:
	cd ../gatesrv;make clean

nodesrv:
	cd ../../../src/engine;make clean;make

install:
	rm -rf bin/gatesrv
	ln -s ../../gatesrv/gatesrv bin/gatesrv

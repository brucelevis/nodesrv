
reload:
	bin/reload

adminsrv:
	bin/logicsrv adminsrv

test:
	bin/client Login.login

localsrv:
	bin/logicsrv localsrv  

gatesrv:
	bin/gatesrv gatesrv1

scenesrv:
	bin/scenesrv scenesrv1

datasrv:
	bin/logicsrv datasrv1

clean:
	cd ../gatesrv;make clean

nodesrv:
	cd ../../../src/engine;make clean;make

install:
	rm -rf bin/gatesrv
	ln -s ../../gatesrv/gatesrv bin/gatesrv

start:
	bin/srvstartall

stop:
	bin/srvstopall

list:
	bin/srvlist

help:
	@echo 'make reload'

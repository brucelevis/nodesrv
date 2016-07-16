
linux:
	tar xzvf hiredis.tar.gz
	cd hiredis;make
	tar xzvf http-parser.tar.gz
	tar xzvf lua.tar.gz
	cd lua;make linux 
	tar xzvf protobuf-2.6.0.tar.gz
	mv protobuf-2.6.0 protobuf
	cd protobuf;./configure;make;sudo make install
	tar xzvf tolua++.tar.gz
	cd tolua++;make
	rm -rf mysql
	cp -rf mysql-connector-c64 mysql

macosx:
	tar xzvf hiredis.tar.gz
	cd hiredis;make clean;make
	tar xzvf http-parser.tar.gz
	tar xzvf lua.tar.gz
	cd lua;make clean;make macosx
	tar xzvf protobuf-2.6.0.tar.gz
	mv protobuf-2.6.0 protobuf
	cd protobuf;./configure;make;sudo make install
	tar xzvf tolua++.tar.gz
	cd tolua++;make clean;make
	rm -rf mysql
	cp -rf mysql-connector-c64-mac mysql

install:
	cp -rf hiredis/libhiredis.a ../lib/libhiredis.a
	cp -rf lua/src/liblua.a ../lib/liblua.a
	cp -rf tolua++/tolua++.a ../lib/tolua++.a
	cp -rf /usr/local/lib/libprotobuf.a ../lib/libprotobuf.a
	cp -rf mysql/lib/libmysqlclient.a ../lib/libmysqlclient.a
	rm -rf ../include
	cp -rf /usr/local/include/google ../include
	mkdir ../include/mysql;cp -rf mysql/include/* ../include/mysql
	mkdir ../include/lua;cp -rf lua/src/*.h ../include/lua
	mkdir ../include/tolua++;cp -rf tolua++/*.h ../include/tolua++
	mkdir ../include/hiredis;cp -rf hiredis/*.h ../include/hiredis;cp -rf hiredis/adapters ../include/hiredis

clean:
	rm -rf hiredis
	rm -rf http-parser
	rm -rf lua
	rm -rf mysql
	rm -rf protobuf
	rm -rf tolua++


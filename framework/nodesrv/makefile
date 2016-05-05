
INCLUDE_DIRS =-I. -I../../3rd/protobuf/src -I../../3rd/lua/src -I../../3rd/mysql/include -I../../3rd/hiredis -I../../3rd/tolua++ -I../../3rd/http-parser

LIB_DIRS =

LIBS =../../3rd/lua/src/liblua.a ../../3rd/mysql/lib/libmysqlclient.a ../../3rd/hiredis/libhiredis.a ../../3rd/tolua++/tolua++.a  

DY_LIBS = -lm -ldl -lreadline -lhistory -lncurses -lpthread

CFLAGS=-O2 -Wall

SOURCE = $(wildcard \
		 entity/*.cc\
		 msg/*.cc\
		 node/*.cc\
		 net/*.cc\
		 component/*.cc\
		 components/*.cc\
		 script/*.cc\
		 type/*.cc\
		 encrypt/*.cc\
		 ../../3rd/http-parser/http_parser.cc\
		 interface.cc\
		 nodeapi.cc\
		 ) 


OBJ = $(patsubst %.cc,%.o,$(SOURCE))


EXE = nodesrv


LIB = nodesrv.a


all:$(EXE) $(LIB)


%.o:%.cc
	g++ $(CFLAGS) -c $< -o $@ $(INCLUDE_DIRS)


${EXE}:$(OBJ) test.o
	g++ -o $(EXE) $(OBJ) test.o $(LIBS) $(DY_LIBS) $(LIB_DIRS) 

$(LIB):$(OBJ)
	ar rcu $@ $(OBJ) 
	ranlib $@

tolua:
	../../3rd/tolua++/tolua++ -n nodeapi -o interface.cc interface.pkg


clean:
	rm -rf $(EXE)
	rm -rf $(LIB)
	rm -rf $(OBJ) test.o

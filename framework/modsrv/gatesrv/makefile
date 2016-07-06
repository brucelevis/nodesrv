
ROOT_PATH = ../../..

INCLUDE_DIRS=-I. -I$(ROOT_PATH)/3rd/protobuf/src -I$(ROOT_PATH)/3rd/lua/src -I$(ROOT_PATH)/3rd/mysql/include -I$(ROOT_PATH)/3rd/hiredis -I$(ROOT_PATH)/3rd/tolua++ -I$(ROOT_PATH)/src/engine

LIBS =$(ROOT_PATH)/src/engine/libneox.a $(ROOT_PATH)/lib/libprotobuf.a $(ROOT_PATH)/3rd/tolua++/tolua++.a $(ROOT_PATH)/3rd/lua/src/liblua.a $(ROOT_PATH)/3rd/mysql/lib/libmysqlclient.a $(ROOT_PATH)/3rd/hiredis/libhiredis.a 

DY_LIBS = -lm -ldl -lreadline -lhistory -lncurses -lpthread

CFLAGS=-O2 -Wall

SOURCE = $(wildcard \
		 *.cc\
		 ) 

OBJ = $(patsubst %.cc,%.o,$(SOURCE))

EXE = gatesrv1

%.o:%.cc
	g++ $(CFLAGS) -c $< -o $@ $(INCLUDE_DIRS)

${EXE}:$(OBJ)
	g++ -o $(EXE) $(OBJ) $(LIBS)  $(DY_LIBS)

tolua:
	$(ROOT_PATH)/3rd/tolua++/tolua++ -n gatesrv -o interface.cc interface.pkg

clean:
	rm -rf $(EXE)
	rm -rf $(OBJ)

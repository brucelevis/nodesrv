
INCLUDE_DIRS=-I. -I../../3rd/protobuf/src -I../../3rd/lua/src -I../../3rd/mysql/include -I../../3rd/hiredis -I../../3rd/tolua++ -I../../framework/nodesrv

LIBS =../../framework/nodesrv/nodesrv.a ../../3rd/lua/src/liblua.a ../../3rd/mysql/lib/libmysqlclient.a ../../3rd/hiredis/libhiredis.a ../../3rd/tolua++/tolua++.a 
DY_LIBS = -lm -ldl -lreadline -lhistory -lncurses -lpthread

CFLAGS=-O2 -Wall

SOURCE = $(wildcard \
		 entity/*.cc\
		 gate/*.cc\
		 *.cc\
		 ) 

OBJ = $(patsubst %.cc,%.o,$(SOURCE))

EXE = gatesrv

%.o:%.cc
	g++ $(CFLAGS) -c $< -o $@ $(INCLUDE_DIRS)

${EXE}:$(OBJ)
	g++ -o $(EXE) $(OBJ) $(LIBS)  $(DY_LIBS)

tolua:
	../../3rd/tolua++/tolua++ -n gatesrv -o interface.cc interface.pkg

clean:
	rm -rf $(EXE)
	rm -rf $(OBJ)

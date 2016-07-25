

ROOT_PATH = ../..

INCLUDE_DIRS =-I. -I$(ROOT_PATH)/include -I$(ROOT_PATH)/include/lua -I$(ROOT_PATH)/include/tolua++ -Ilualib 

LIB_DIRS =

LIBS =$(ROOT_PATH)/lib/libprotobuf.a $(ROOT_PATH)/lib/liblua.a $(ROOT_PATH)/3rd/mysql/lib/libmysqlclient.a $(ROOT_PATH)/lib/libhiredis.a $(ROOT_PATH)/lib/tolua++.a  

DY_LIBS = -lm -ldl -lreadline -lncurses -lpthread

CFLAGS=-O2 -Wall

SOURCE = $(wildcard \
		 entity/*.cc\
		 msg/*.cc\
		 node/*.cc\
		 net/*.cc\
		 log/*.cc\
		 component/*.cc\
		 container/*.cc\
		 script/*.cc\
		 file/*.cc\
		 type/*.cc\
		 encrypt/*.cc\
		 display/*.cc\
		 lualib/redis/*.cc\
		 lualib/json/*.cc\
		 lualib/date/*.cc\
		 lualib/string/*.cc\
		 lualib/port/*.cc\
		 lualib/srvapp/*.cc\
		 lualib/pblua/*.cc\
		 lualib/system/*.cc\
		 lualib/mysql/*.cc\
		 interface.cc\
		 neox.cc\
		 ) 

OBJ = $(patsubst %.cc,%.o,$(SOURCE))


TEST = test
LIB = libneox.a
EXE = lneox


all:$(TEST) $(LIB) $(EXE)


%.o:%.cc
	g++ $(CFLAGS) -c $< -o $@ $(INCLUDE_DIRS)

${EXE}:$(OBJ) lneox.o
	g++ -o $(EXE) $(OBJ) lneox.o $(LIBS) $(DY_LIBS) $(LIB_DIRS) 

${TEST}:$(OBJ) test.o
	g++ -o $(TEST) $(OBJ) test.o $(LIBS) $(DY_LIBS) $(LIB_DIRS) 

$(LIB):$(OBJ)
	ar rcu $@ $(OBJ) 
	ranlib $@

tolua:
	$(ROOT_PATH)/3rd/tolua++/tolua++ -n neox -o interface.cc interface.pkg


clean:
	rm -rf $(TEST)
	rm -rf $(EXE)
	rm -rf $(LIB)
	rm -rf $(OBJ) test.o

include ./Inc.mk

CFLAGS  := -g 
INCLUDE := -I./comm#-I../../comm/ $(WBL_INC) 
LIBPATH :=  ${LIB_COMM} -L./lib -lcomm -lpthread
#-L ../../lib -luniform_pay -L../../comm/UnionVerifyAPI -lUnionVerifyAPI $(WBL_LIB)

BIN_TRANSFER = server
OBJ_TRANSFER = main.o

all: $(BIN_TRANSFER)

$(BIN_TRANSFER):$(OBJ_TRANSFER)
	$(CXX) -W1 -static $(CFLAGS) -o $@ $^ $(LIBPATH)
%.o:%.cpp
	$(CXX) -c -o $@ $(CFLAGS) $(INCLUDE) $^

.PHONY:
clean:
	rm -rf $(OBJ_TRANSFER) $(OBJ_TRANSFER)



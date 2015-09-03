include ../Inc.mk
INCLUDE = #-I. -I$(API_MB)/include -I$(MYSQL_PATH)/include/mysql $(SHM_NDS_INC) -I${WBL_PATH}/include -I$(TLIB_PATH)/include  -I./ssp -I./coupon/ -I./cajun -I./mc_api -I./tips/include -I./UnionVerifyAPI  -I./curl-7.21.1/include -I../comm/upay_titan/include  -I../comm/uniform_oidb/include -I../include $(CURL_INC) -I../src

LIB_TOOLS = ../lib/libcomm.a

OBJS_TOOLS = tools.o transfer_server.o threadpool.o task.o lockmutex.o\
			lockcond.o
	#PwdProtected.o ptlogin2_api.o CBalanceCredit.o tools.o \ 
	#CGameCoinTools_v2.o 
	#channel_pay_base.o channel_pay_tools.o


LIBS = $(LIB_TOOLS)
OBJS = $(OBJS_TOOLS)

all: $(LIBS)

$(LIB_TOOLS): $(OBJS_TOOLS) 
	$(AR) $(AROPT) $@ $? 
	$(RANLIB) $@
		
clean:
	rm -f $(OBJS) $(LIBS)

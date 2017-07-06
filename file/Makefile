# 可执行文件  
TARGET=file  
# C文件  
SRCS = file.c  
# 目标文件  
OBJS = $(SRCS:.c=.o)  
  
# 指令编译器和选项  
CC=gcc  
CFLAGS=-Wall -std=gnu99  
  
$(TARGET):$(OBJS)  
#   @echo TARGET:$@  
#   @echo OBJECTS:$^  
	$(CC) -o $@ $^  
  
clean:  
	rm -rf $(TARGET) $(OBJS)  
  
%.o:%.c  
	$(CC) $(CFLAGS) -o $@ -c $< 
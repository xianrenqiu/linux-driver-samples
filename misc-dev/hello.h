#include <linux/types.h>

/* type(设备类型) nr(序列号) size(数据长度)**/
#define DATA_WRITE _IOR('c', 102, char*)
#define DATA_READ _IOR('c', 103, char*)
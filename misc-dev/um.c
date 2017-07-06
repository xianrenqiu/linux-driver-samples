#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "hello.h"

int main(void)
{
	char buff[100];
	memset(buff, 0, 100);	
	char *str = "Hello World!";
	
	/* Open the hello device */
	int fd = open("/dev/hello", O_RDWR, 0);
	if (fd < 0) 
	{
		printf("open /dev/hello filed.\n");
		goto err;
	}	

	if (ioctl(fd, DATA_WRITE, str)) 
	{
		printf("hello data write failed.\n");
		goto err;
	}

	if (ioctl(fd, DATA_READ, buff)) 
	{
		printf("hello data read failed.\n");
		goto err;
	}	

	printf("%s\n", buff);

err:
	close(fd);	

	return 0;
}
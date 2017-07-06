#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define LENGTH 100

void linux_file_sample(void)
{
	int fd, len;
	char str[LENGTH];

	fd = open("hello.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if(fd)
	{
		write(fd, "Hello World from linux_file_sample\n", strlen("Hello World from linux_file_sample\n"));
		close(fd);
	}

	fd = open("hello.txt", O_RDWR);
	len = read(fd, str, LENGTH);

	str[len] = '\0';
	printf("%s\n", str);
	close(fd);	
}

void c_file_sample(void)
{
	FILE *fd;
	char str[LENGTH];

	fd = fopen("hello.txt", "w+");
	if(fd)
	{
		fputs("Hello World form c_file_sample\n", fd);
		fclose(fd);
	}

	fd = fopen("hello.txt", "r");
	fgets(str, LENGTH, fd);
	printf("%s\n", str);
	fclose(fd);
}

int main(void)
{
	linux_file_sample();
	c_file_sample();

	return 0;
}
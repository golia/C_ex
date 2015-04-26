#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd_in, fd_out;
	char c;
	if ((fd_in = open ("file.in", O_RDWR)) == -1)
	{
		perror ("Fail to open file");
		return 1;
	}
	if (ftruncate(fd_in, 10) == -1)
	{
		perror ("Fail to truncate");
		return 1;
	} 
	close(fd_in);
}

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd_in, fd_out, cur, n;
	char c;
	fd_in = open ("file.in", O_RDWR);
	fd_out = open ("file.out", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
	cur = lseek ( fd_in, -1, SEEK_END);
	n = -1;
	while (read(fd_in, &c, 1) > 0)
	{
		write(fd_out, &c, 1);
		n -= 1;
		cur = lseek ( fd_in, n, SEEK_END);	
		if (cur<0)
			break;
	}

	close(fd_in);
	close(fd_out);

}

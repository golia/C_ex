#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char c[10];
	int in, out, n;
	in = open("file.in", O_RDONLY);
	out = open ("file.out", O_RDWR|O_TRUNC|O_CREAT, S_IRUSR|S_IWUSR);
	
	while ((n=read(in, &c, 1))>0)
	{
		write(out, &c, n);
	} 

	close(in);
	close(out);
	
	return 0;
}


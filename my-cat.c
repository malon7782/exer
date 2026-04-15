#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char buf[4096];
	ssize_t n;
	int fd;

	if (argc < 2) return 1;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 ) return 1;

	while ((n = read(fd, buf, sizeof(buf))) != 0){
		ssize_t total = 0;

		while (total < n) {
			ssize_t written = write(1, buf + total, n - total);
			if (written < 0) {
				close(fd);
				return 1;
			}
			total += written;
		}
	}

	close(fd);
	return 0;
}

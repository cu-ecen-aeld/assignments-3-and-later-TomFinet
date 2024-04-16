#include <string.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	openlog(NULL, 0, LOG_USER);

	if (argc - 1 != 2) {
		syslog(LOG_ERR, "Expected 2 command line arguments. Received %d\n", argc - 1);
		return 1;
	}

	char* path = argv[1];
	char* content = argv[2];

	int fd = open(path, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd == -1) {
		syslog(LOG_ERR, "Could not open file at %s\n", path);
		return 1;
	}

	int nbytes = write(fd, content, strlen(content));
	if (nbytes != strlen(content)) {
		syslog(LOG_ERR, "Wrote %d bytes to file. Failed.\n", nbytes);
		return 1;
	}

	syslog(LOG_DEBUG, "Wrote %s to %s\n", content, path);	

	close(fd);
	closelog();

	return 0;
}

#include<sys/mount.h>
#include <stdio.h>
#include <errno.h>


int main(int argc, char ** argv) {
	if (argc < 4) {
		fprintf(stderr, "Usage: %s type device mountpoint\n", argv[0]);
		return 1;
	}

	int ret = mount(argv[2], argv[3], argv[1], 0, NULL);

	if (ret < 0) {
		fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
		return ret;
	}

	return 0;
}
#include <libc.h>

void log_wrapper(FILE *file, char *str, char *filename) {
	char buf[1000];

	strcpy(buf, str);
	snprintf(buf + strlen(str), strlen(filename) + 1, filename, 0);
	buf[strcspn(buf, "\n")] = 0;
	fprintf(file, "LOG: %s\n", buf);
	return ;
}

int main(int arg0, char **argv) {
	if (arg0 != 2) {
		printf("Usage: %s filename\n", argv[0]);
	}
	FILE *fd = fopen("./backups/.log", "w");
	if (!fd) {
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	else {
		log_wrapper(fd, "Starting back up: ", argv[1]);
		FILE *fd2 = fopen(argv[1], "r");
		if (!fd2) {
			printf("ERROR: Failed to open %s\n", argv[1]);
			exit(1);
		}
		else {
			char file[100] = "./backups/";
			strncat(file, argv[1], strlen(argv[1]));
			int fd3 = open(file, O_WRONLY | O_CREAT, S_IRUSR | S_IRGRP/*0xc1*/);
			if (fd < 0) {
				printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
				exit(1);
			}
			else {
				do {
					char c = fgetc(fd2);
					if ((c & 0xff) == 0xff) {
						break;
					}
					write(fd3, &c, 1);
				} while (1);
				log_wrapper(fd, "Finished back up ", argv[1]);
				fclose(fd2);
				close(fd3);
			}
		}
	}
	return 0;
}

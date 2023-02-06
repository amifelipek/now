#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>

void help(void);
void version(void);

int main(int argc, char *argv[])
{
	int help_flag = 0;
	int version_flag = 0;

	int c;
	while ((c = getopt(argc, argv, "hv")) != -1) {
		switch (c) {
		case 'h':
			help_flag = 1;
			break;
		case 'v':
			version_flag = 1;
			break;
		default:
			help_flag = 1;
			break;
		}
	}

	if (help_flag) {
		help();
	}

	if (version_flag) {
		version();
	}

	time_t t = time(NULL);

	struct tm lt = *localtime(&t);

	printf("%02d:%02d:%02d\n", lt.tm_hour, lt.tm_min, lt.tm_sec);
}

void help(void)
{
	printf("Usage: now [OPTION]\n");
	printf("Outputs your current time to stardard output.\n");
	printf("\n  -v\t\t\toutput version information and exit.\n");
	printf("  -h\t\t\tdisplay this help and exit.\n");
	exit(EXIT_SUCCESS);
}

void version(void)
{
	printf("now 0.1\n");
	printf("\nWritten by Felipe Kinoshita.\n");
	exit(EXIT_SUCCESS);
}

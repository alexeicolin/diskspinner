#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define FILE_SIZE (16*1024*1024)

static char *data = "0xdeadbeef";

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s garbagefile interval_sec\n", argv[0]);
        return 1;
    }

    const char *filepath = argv[1];
    char *interval_str = argv[2];

    FILE *fd = fopen(argv[1], "w");
    if (fd == NULL) {
        fprintf(stderr, "open failed: %s\n", strerror(errno));
        return 2;
    }

    unsigned interval;
    if (sscanf(interval_str, "%u", &interval) != 1) {
        fprintf(stderr, "failed to parse interval: %s\n", interval_str);
        return 2;
    }

    while (1) {

        long offset;
        offset = rand();
        offset <<= 16;
        offset |= rand();
        offset %= FILE_SIZE;


        int rc = fseek(fd, FILE_SIZE, SEEK_SET);
        if (rc) {
            fprintf(stderr, "seek open failed: %s\n", strerror(errno));
            return 2;
        }
        int len = strlen(data);
        if (fwrite(data, sizeof(char), len, fd) != len) {
            fprintf(stderr, "write failed: %s\n", strerror(errno));
            return 2;
        }

        fsync(fileno(fd));

        sleep(interval);
    }

    return 0;
}

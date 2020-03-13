#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]){
    const int MAX_BUFFER_LENGTH = 2048;

    printf("copying %s into %s...\n", argv[1], argv[2]);

    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {
      printf("error while opening %s\n", argv[1]);
      return -1;
    }
    char buffer[MAX_BUFFER_LENGTH];
    int fd1_length = read(fd1, buffer, MAX_BUFFER_LENGTH);
    if (fd1_length < 0) {
      printf("error while reading %s\n", argv[1]);
    }
    int fd2 = creat(argv[2], S_IRUSR | S_IWUSR);
    write(fd2, buffer, fd1_length);

    return 0;
}

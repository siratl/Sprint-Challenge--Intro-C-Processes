#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct stat buf;
  char *dir;
  DIR *diropen;

  if (argc == 2)
  {
    dir = argv[1];
  }
  else if (argc == 1)
  {
    dir = ".";
  }
  else
  {
    printf("There are %d command line argument(s):\n", argc);
    exit(1);
  }

  // Open directory
  struct dirent *entry;

  diropen = opendir(dir);

  if (diropen == NULL)
  {
    perror("opendir() error");
    exit(1);
  }

  // Repeatly read and print entries
  while ((entry = readdir(diropen)) != NULL)
  {
    stat(entry->d_name, &buf);

    printf("%10ld %s\n", buf.st_size, entry->d_name);
  }

  // Close directory
  closedir(diropen);

  return 0;
}
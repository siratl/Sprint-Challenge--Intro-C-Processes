#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;
  struct stat buf;

  printf("There are %d command line argument(s):\n", argc);

  // Open directory
  for (i = 1; i < (argc); i++)
  {
    DIR *dir = opendir(argv[i]);
    struct dirent *entry;

    if (dir == NULL)
    {
      perror("opendir() error");
    }
    else
    {
      // Repeatly read and print entries
      while ((entry = readdir(dir)) != NULL)
      {
        stat(entry->d_name, &buf);

        printf("%10ld %s\n", buf.st_size, entry->d_name);
      }
      // Close directory
      closedir(dir);
    }
  }

  return 0;
}
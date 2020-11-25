#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char ** argv){
  char buffer[256];
  DIR * d;

  if (argc > 1){
    strcpy(buffer, argv[1]);
  }

  else{
    printf("Please enter a directory: ");
    scanf("%s", buffer);
  }

  d = opendir(buffer);

  if (d == NULL) {
    printf("%s\n", strerror(errno));
    return 0;
  }

  struct dirent *entry;
  entry = readdir(d);
  int dirtype = entry->d_type;

  struct stat sb;
  stat(buffer, &sb);

  printf("Statistics for directory: %s\n", buffer);
  printf("Total Directory Size: %lld Bytes\n", sb.st_size);
  printf("Directories:\n");


  while(entry != NULL){
  if (entry->d_type == dirtype) printf("%s\n", entry->d_name);
  entry = readdir(d);
  }

  printf("Regular files:\n");
  rewinddir(d);
  entry = readdir(d);

  while(entry != NULL){
  if (entry->d_type != dirtype) printf("%s\n", entry->d_name);
  entry = readdir(d);
  }

  closedir(d);

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
  DIR * d;
  d = opendir("./");
  struct dirent *entry;
  entry = readdir(d);
  int dirtype = entry->d_type;

  struct stat sb;
  stat("./", &sb);

  printf("Statistics for directory: %s\n", entry->d_name);
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

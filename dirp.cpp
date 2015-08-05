#include<unistd.h>
#include<dirent.h>
#include<stdio.h>

int main(){

DIR *dir;
struct dirent *ent;
if ((dir = opendir ("/")) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    printf ("%s\n", ent->d_name);
  }
  closedir (dir);
} else {
  /* could not open directory */
  perror ("");
  return 0;
}

}

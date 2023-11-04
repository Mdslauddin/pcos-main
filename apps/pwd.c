#include<stdio.h>
#include<unistd.h>

int main(int argc, char * argv[]){

 char tmp[1024];
 if (getcwd(tmp, 1023)) {
  puts(tmp);
  return 0;

 }
else {

return 1;
}



}

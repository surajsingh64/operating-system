#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
using namespace std;
int main(){
        int fd,n,fd1;
        fd=open("file1.txt",O_RDONLY);
        char b[50];
        n=read(fd,b,20);
        fd1=open("filea",O_CREAT|O_WRONLY,0642);
        write(fd1,b,n);
       

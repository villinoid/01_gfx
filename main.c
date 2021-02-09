#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

int main() {
	int i;
	int j;
	int file=open("out.ppm", O_WRONLY|O_CREAT, 0755);
	int r;
	int g;
	int b;
	char header[]= "P3\n512 512\n256\n";
	char buffer[256];
	write(file, header,strlen(header));
	for(i=0;i<512;i++){
		for(j=0;j<512;j++){
			r = round(sqrt(pow(i,2)+pow(j,2)));
			g = round(sqrt(pow(i-256,2)+pow(j-256,2)));
			b = round(sqrt(pow(i-511,2)+pow(j-511,2)));
			r=r%256;
			g=g%256;
			b=b%256;
			sprintf(buffer, "%d %d %d\t",r,g,b);
			write(file, buffer, strlen(buffer));
		}
		write(file, "\n", 1);
	}
	close(file);
	return 0;
	

}
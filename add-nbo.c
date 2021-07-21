#include <stdio.h>
#include <stdint.h>
#include "add-nbo.h"

int main(int argc, char* argv[])
{
	FILE *f1, *f2;
	f1 = fopen(argv[1], "rb");
	f2 = fopen(argv[2], "rb");
	

	uint32_t n1, n2;
	
	int r1 = fread(&n1, sizeof(uint32_t), 1, f1);
	int r2 = fread(&n2, sizeof(uint32_t), 1, f2);

	uint32_t num1 = ntohl(n1);
	uint32_t num2 = ntohl(n2);

	if(r1!=1 || r2!=1)
		printf("fread error!");
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);
	
	fclose(f1);
	fclose(f2);

	return 0;
}

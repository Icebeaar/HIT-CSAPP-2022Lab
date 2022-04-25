#include <stdio.h>

int main()
{
	printf("%d	char\n",sizeof(char));
	printf("%d	short\n",sizeof(short));
	printf("%d	unsigned int\n",sizeof(unsigned));
	printf("%d	int\n",sizeof(int));
	printf("%d	float\n",sizeof(float));
	printf("%d	double\n",sizeof(double));
	printf("%d	long double\n",sizeof(long double));
	printf("%d	long int\n",sizeof(long));
	printf("%d	long long int\n",sizeof(long long));
	printf("%d	pointer\n",sizeof(void *));
	return 0;
}

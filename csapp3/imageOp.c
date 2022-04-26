#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <immintrin.h>

long long img[1920][1080];

__inline __m256i VecLoad(long long* A)
{
	return _mm256_load_si256((__m256i*) A);
}

__inline __m256i VecAdd(__m256i a, __m256i b) {
	return _mm256_add_epi64(a, b);
}

__inline __m256i VecShl(__m256i a, int b) {
	return _mm256_srli_epi64(a, b);
}

__inline void VecSto(long long* A, __m256i a) {
	_mm256_store_si256((__m256i*) A, a);
}
void img_init()
{
	int k = 0;
	for (int i = 0; i < 1920; i++)
	{
		for (int j = 0; j < 1080; j=j+2)
		{
			img[i][j] = k++;
			img[i][j + 1] = k++;
		}
	}
}

void img_fluent_()
{
	long long* buffer = (long long*)malloc(1920 * sizeof(long long));
	for (int i = 0; i < 1919; i++)
		buffer[i] = img[i][0];
	for (int j = 1; j < 1079; j++)
	{
		for (int i = 1; i < 1919; i++)
		{
			long long cache = img[i][j] = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) / 4;
			img[i - 1][j] = buffer[j];
			buffer[j] = cache;
		}
	}
	for (int j = 1; j < 1919; j++)
		img[j][1078] = buffer[j];
	free(buffer);
}

void img_fluent()
{
	long long *buffer = (long long*)malloc(1080 * sizeof(long long));
	for (int i = 0; i < 1080; i++)
		buffer[i] = img[0][i];
	for (int i = 1; i < 1919; i++)
	{
		for (int j = 1; j < 1079; j++)
		{
			long long cache = img[i][j] = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) / 4;
			img[i - 1][j] = buffer[j];
			buffer[j] = cache;
		}
	}
	for (int j = 1; j < 1079; j++)
		img[1918][j] = buffer[j];
	free(buffer);
}

void img_fluentOp()
{
	long long* buffer = (long long*)malloc(1080 * sizeof(long long));
	for (int i = 0; i < 1080; i++)
		buffer[i] = img[0][i];
	for (int i = 1; i < 1919; i++)
	{
		for (int j = 1; j < 1076; j=j+4)
		{
			long long cache = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) / 4;
			img[i - 1][j] = buffer[j];
			buffer[j] = cache;
			long long cache1 = (img[i - 1][j+1] + img[i + 1][j+1] + img[i][j] + img[i][j + 2]) / 4;
			img[i - 1][j+1] = buffer[j+1];
			buffer[j+1] = cache1;
			long long cache2 = (img[i - 1][j + 2] + img[i + 1][j + 2] + img[i][j+1] + img[i][j + 3]) / 4;
			img[i - 1][j + 2] = buffer[j + 2];
			buffer[j + 2] = cache2;
			long long cache3 = (img[i - 1][j + 3] + img[i + 1][j + 3] + img[i][j + 2] + img[i][j + 4]) / 4;
			img[i - 1][j + 3] = buffer[j + 3];
			buffer[j + 3] = cache3;
		}
	}
	for (int j = 1; j < 1079; j++)
		img[1918][j] = buffer[j];
	free(buffer);
}

void img_fluentOp1()
{
	long long* buffer = (long long*)malloc(1080 * sizeof(long long));
	for (int i = 0; i < 1080; i++)
		buffer[i] = img[0][i];
	for (int i = 1; i < 1919; i++)
	{
		for (int j = 1; j < 1076; j = j + 4)
		{
			long long cache = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1])>>2;
			img[i - 1][j] = buffer[j];
			buffer[j] = cache;
			long long cache1 = (img[i - 1][j + 1] + img[i + 1][j + 1] + img[i][j] + img[i][j + 2])>>2;
			img[i - 1][j + 1] = buffer[j + 1];
			buffer[j + 1] = cache1;
			long long cache2 = (img[i - 1][j + 2] + img[i + 1][j + 2] + img[i][j + 1] + img[i][j + 3])>>2;
			img[i - 1][j + 2] = buffer[j + 2];
			buffer[j + 2] = cache2;
			long long cache3 = (img[i - 1][j + 3] + img[i + 1][j + 3] + img[i][j + 2] + img[i][j + 4])>>2;
			img[i - 1][j + 3] = buffer[j + 3];
			buffer[j + 3] = cache3;
		}
	}
	for (int j = 1; j < 1079; j++)
		img[1918][j] = buffer[j];
	free(buffer);
}

void img_fluentOp2()
{
	long long* buffer = (long long*)malloc(1080 * sizeof(long long));
	for (int i = 0; i < 1080; i++)
		buffer[i] = img[0][i];
	for (int i = 1; i < 1919; i++)
	{
		for (int j = 1; j < 1076; j = j + 4)
		{
			int m = i - 1;
			int n = i + 1;
			long long cache = (img[m][j] + img[n][j] + img[i][j - 1] + img[i][j + 1]) >> 2;
			img[i - 1][j] = buffer[j];
			buffer[j] = cache;
			long long cache1 = (img[m][j + 1] + img[n][j + 1] + img[i][j] + img[i][j + 2]) >> 2;
			img[i - 1][j + 1] = buffer[j + 1];
			buffer[j + 1] = cache1;
			long long cache2 = (img[m][j + 2] + img[n][j + 2] + img[i][j + 1] + img[i][j + 3]) >> 2;
			img[i - 1][j + 2] = buffer[j + 2];
			buffer[j + 2] = cache2;
			long long cache3 = (img[m][j + 3] + img[n][j + 3] + img[i][j + 2] + img[i][j + 4]) >> 2;
			img[i - 1][j + 3] = buffer[j + 3];
			buffer[j + 3] = cache3;
		}
	}
	for (int j = 1; j < 1079; j++)
		img[1918][j] = buffer[j];
	free(buffer);
}

void img_fluentOp3()
{
	long long* buffer = (long long*)malloc(1080 * sizeof(long long));
	for (int i = 0; i < 1080; i++)
		buffer[i] = img[0][i];
	for (int i = 1; i < 1919; i++)
	{
		for (int j = 1; j < 1076; j = j + 4)
		{
			__m256i up, down, left, right;
			__m256i sum1, sum2, sum3, res;
			up = VecLoad(&img[i - 1][j]);
			down = VecLoad(&img[i + 1][j]);
			left = VecLoad(&img[i][j - 1]);
			right = VecLoad(&img[i][j + 1]);
			sum1 = VecAdd(up, left);
			sum2 = VecAdd(right, down);
			sum3 = VecAdd(sum1, sum2);
			res = VecShl(sum3, 2);
			img[i - 1][j] = buffer[j];
			img[i - 1][j + 1] = buffer[j + 1];
			img[i - 1][j + 2] = buffer[j + 2];
			img[i - 1][j + 3] = buffer[j + 3];
			VecSto(&buffer[j], res);
		}
	}
	for (int j = 1; j < 1079; j++)
		img[1918][j] = buffer[j];
	free(buffer);
}

int main()
{
	img_init();
	img_fluent();
	clock_t start1, end1;
	start1 = clock();
	for (int i = 0; i < 1000; i++)
		img_fluent_();
	end1 = clock();
	printf("time=%f\n", ((double)end1 - (double)start1) / CLOCKS_PER_SEC);
	clock_t start2, end2;
	start2 = clock();
	for(int i=0;i<1000;i++)
		img_fluent();
	end2 = clock();
	printf("time=%f\n", ((double)end2 - (double)start2) / CLOCKS_PER_SEC);
	clock_t start3, end3;
	start3 = clock();
	for (int i = 0; i < 1000; i++)
		img_fluentOp();
	end3 = clock();
	printf("time=%f\n", ((double)end3 - (double)start3) / CLOCKS_PER_SEC);
	clock_t start4, end4;
	start4 = clock();
	for (int i = 0; i < 1000; i++)
		img_fluentOp1();
	end4 = clock();
	printf("time=%f\n", ((double)end4 - (double)start4) / CLOCKS_PER_SEC);
	clock_t start5, end5;
	start5 = clock();
	for (int i = 0; i < 1000; i++)
		img_fluentOp2();
	end5 = clock();
	printf("time=%f\n", ((double)end5 - (double)start5) / CLOCKS_PER_SEC);
	clock_t start6, end6;
	start6 = clock();
	for (int i = 0; i < 1000; i++)
		img_fluentOp3();
	end6 = clock();
	printf("time=%f\n", ((double)end6 - (double)start6) / CLOCKS_PER_SEC);
	return 0;
}

#include <stdio.h>

int BinarySearch(int tb[], int len, int K);

int main(void)
{
	int tb[] = {5, 8, 19, 27, 36, 51, 57, 60, 78};
	int len = sizeof(tb) / sizeof(int);
	int K;
	scanf("%d", &K);
	int result = BinarySearch(tb, len, K);

	return 0;
}

int BinarySearch(int tb[], int len, int K)
{
	int left = 0, right = len - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (tb[mid] > K)
		{	
			right = mid - 1;
		}
		else if (tb[mid] < K)
		{
			left = mid + 1;
		}
		else if (tb[mid] == K)
		{
			printf("Find %d\n", K);
			return 1;
		}
	}
	printf("Not Found %d\n", K);
	return 0;
}

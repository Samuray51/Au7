#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>
int Max(int *mas, int k)
{
	int i = 0, max = 0, max1 = 0;
	for (i; i <= k; i++)
	{
		if (mas[i] > max)
		{
			max = mas[i];
			max1 = i;
		}
	}
	return max1;
}


int Proverka(char *A, char N, int I)
{
	int i = 0, j = 0;
	i = I - 1;
	while (i >= 0)
	{
		if (N == A[i])
		{
			j++;
		}
		i--;
	}
	return j;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	FILE *in, *out;
	fopen_s(&in, "input.txt", "r");
	fopen_s(&out, "output.txt", "w");

	int i = 0, j = 0, k = 0, m = 2000, *leight;
	char n, **mas;
	leight = (int*)malloc(m * sizeof(int));
	mas = (char**)malloc(m * sizeof(char*));
	for (i = 0; i < m; i++)
	{
		mas[i] = (char*)malloc(m * sizeof(char));
	}
	i = 0;
	while (!feof(in))
	{
		fscanf_s(in, "%c", &mas[i][j], 1);
		n = mas[i][j];
		k = Proverka(mas[i], n, j);
		if (k == 0)
		{
			j++;
		}
		else
		{
			mas[i][j] = '\0';
			leight[i] = j;
			i = i + 1;
			j = 0;
			mas[i][j] = n;
			j++;
		}
	}
	mas[i][j - 1] = '\0';
	leight[i] = j - 1;



	for (j = 0; j <= i; j++)
	{
		for (k = 0; k < leight[j]; k++)
		{
			printf("%c", mas[j][k]);
		}
		printf("\n");
	}

	i = Max(leight, i);
	printf("%s", mas[i]);
	fprintf(out, "%s", mas[i]);

	fclose(in);
	fclose(out);
	free(leight);
	for (i = 0; i < m; i++)
	{
		free(mas[i]);
	}
	free(mas);
	system("pause");
	return 0;
}
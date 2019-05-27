#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void egunak(int a);
void erabiltzailea(int a);
float efizentzia(float a, float b, float c);
float handiena(float a[], int luzera);
int poshandiena(int a[][3], int luz1, int luz2);
int posizioa(float a[], float zenb, int luzera);

int main()
{
	char str[128];
	float tabla[6][4];
	float ef[5];
	int tot[5][3];
	int i, y, u, k, posMax, kont = 0, intento = 0;
	int tot1 = 0;
	float efi, max;
	int piez, denb, def;
	float x;



	printf("SARTU PASAHITZA: ");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &x);

	while (x != 88)
	{
		intento++;
		printf("Kode okerra. Saiatu berriro.\n");

		printf("SARTU PASAHITZA: ");
		fgets(str, 128, stdin);
		sscanf(str, "%f", &x);
	}
	if (x == 88)
	{
		printf("\n\t     ONGI ETORRI\n");
		
		for (y = 0; y < 5; y++)
		{
			printf("\nKaixo ");
			erabiltzailea(y + 1);
			printf("\n");

			for (k = 0; k < 5; k++)
			{
				kont = 0;

				egunak(k);
				tabla[k][kont] = k + 1;
				kont++;

				printf("Zenbat pieza egin dira? ");
				fgets(str, 128, stdin);
				sscanf(str, "%f", &x);

				tabla[k][kont] = x;
				kont++;

				printf("Zenbat minututan? ");
				fgets(str, 128, stdin);
				sscanf(str, "%f", &x);

				while ((tabla[k][1] > 0) && (x == 0))
				{
					printf("Ezin dira 0 minutu izan.\nMesedez sartu denbora erreala: ");
					fgets(str, 128, stdin);
					sscanf(str, "%f", &x);
				}
				tabla[k][kont] = x;
				kont++;

				printf("Zenbat defektuzko pieza egon dira? ");
				fgets(str, 128, stdin);
				sscanf(str, "%f", &x);

				tabla[k][kont] = x;
			}

			printf("\n");

			printf("\n\t*****ASTE OSOAN*****\n\n");

			for (u = 0; u < 5; u++)
			{
				for (i = 0; i < 4; i++)
				{
					printf("%.0f ", tabla[u][i]);
				}
				printf("\n");
			}

			printf("\n");

			for (k = 1; k < 4; k++)
			{
				for (i = 0; i < 5; i++)
				{
					tot1 = tot1 + tabla[i][k];
				}

				if (k == 1)
				{
					piez = tot1;
					tot[y][0] = piez;
					printf("Guztira egindako piezak: %d\n", tot1);
				}
				if (k == 2)
				{
					denb = tot1;
					tot[y][1] = denb;
					printf("Guztira erabili den denbora: %d\n", tot1);
				}
				if (k == 3)
				{
					def = tot1;
					tot[y][2] = def;
					printf("Guztira defektuzko piezak: %d\n\n", tot1);
				}
				tot1 = 0;
			}
			efi = efizentzia(piez, def, denb);
			printf("Langilearen efizentzia koefizientea, programaren kalkuluaren arabera: %.2f\n\n", efi);
			ef[y] = efi;
		}
	}
	
	max = handiena(ef, 5);
	posMax = posizioa(ef, max, 5);
	erabiltzailea(posMax + 1);
	printf(" izan da langile efizienteena: %.2f\n", max);

	posMax = poshandiena(tot, 5, 0);
	erabiltzailea(posMax + 1);
	printf("-(e)k egin ditu pieza gehien: %d\n", tot[posMax][0]);

	posMax = poshandiena(tot, 5, 1);
	erabiltzailea(posMax + 1);
	printf("-(e)k egin ditu minutu gehien lanean: %d\n", tot[posMax][1]);

	posMax = poshandiena(tot, 5, 2);
	erabiltzailea(posMax + 1);
	printf("-(e)k egin ditu defektuzko pieza gehien: %d", tot[posMax][2]);
	
	printf("\n\n");

	printf("Sakatu \"return\" amaitzeko .....");
	fgets(str, 128, stdin);
	return 0;
}

void egunak(int a)
{
	if (a == 0)
	{
		printf("\n\t*****ASTELEHENA*****\n\n");
	}
	if (a == 1)
	{
		printf("\n\t*****ASTEARTEA*****\n\n");
	}
	if (a == 2)
	{
		printf("\n\t*****ASTEAZKENA*****\n\n");
	}
	if (a == 3)
	{
		printf("\n\t*****OSTEGUNA*****\n\n");
	}
	if (a == 4)
	{
		printf("\n\t*****OSTIRALA*****\n\n");
	}
}

void erabiltzailea(int a)
{
	char str[128];

	while ((a < 1) || (5 < a))
	{
		printf("KODE OKERRA. SARTU ZURE LANGILE KODEA: ");
		fgets(str, 128, stdin);
		sscanf(str, "%d", &a);
	}

	if (a == 1)
	{
		printf("G. IBABE");
	}
	if (a == 2)
	{
		printf("I. ALTUNA");
	}
	if (a == 3)
	{
		printf("D. RODRIGUEZ");
	}
	if (a == 4)
	{
		printf("U. ETXARRI");
	}
	if (a == 5)
	{
		printf("J. ARANZABAL");
	}
}

float efizentzia(float a, float b, float c)
{
	float tot;

	tot = (a - b) / c;

	return tot;
}

float handiena(float a[], int luzera)
{
	float max = 0;
	int i;

	for (i = 0; i < luzera; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}

	return max;
}

int posizioa(float a[], float zenb, int luzera)
{
	int pos, i;

	for (i = 0; i < luzera; i++)
	{
		if (zenb == a[i])
		{
			pos = i;
		}
	}

	return pos;
}

int poshandiena(int a[][3], int luz1, int luz2)
{
	int i, max = 0, maxpos;

	for (i = 0; i < luz1; i++)
	{
		if (a[i][luz2] > max)
		{
			max = a[i][luz2];
			maxpos = i;
		}
	}

	return maxpos;
}
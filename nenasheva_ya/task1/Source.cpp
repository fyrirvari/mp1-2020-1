#include <iostream>
#include "Konvert.h"

int main()
{
	double z;
	printf("Vvedite znachenie v metrah: ");
	scanf_s("%lf", &z);
	Konvert Z(z);

	int r;
	printf("Meri velichini dlya perevoda:\n1)dume\n2)fut\n3)yard\n");
	printf("Viberite mery velichini dlya perevoda: ");
	scanf_s("%d", &r);

	double result;
	switch (r)
	{
	case 1:
		result = Z.dume();
		printf("result = %lf(dume)\n", result);
		break;
	case 2:
		result = Z.fut();
		printf("result = %lf(fut)\n", result);
		break;
	case 3:
		result = Z.yard();
		printf("result = %lf(yard)\n", result);
		break;
	}

	printf("Vvedite novoe znachenie v metrah: ");
	scanf_s("%lf", &z);
	Z.set(z);
	printf("V danniy moment vnytri menya nahoditsya: %lf\n", Z.get());
	printf("Pechataem soderzhanie ob'ekta: ");
	Z.write();
	printf("\n");

	system("pause");
}
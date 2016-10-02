#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

/*
- ��������� �������� �� ���� ������ ������.
- ��������� � ������� �����, ����� ����� ���������� ������������ ������
- ����� � ����� 0.1 �������� �� ���� �������� ������� ����� ������� � ������ ������ � ������� ������ � ���� ������ �������
- ����� ����, ����������� ��������� ������ �������� ������ � ������ ����� ������
*/

/*
	���������:
	1. ������ ������������ ������ ������ �� ������������
	2. �������� ������������ �����:
		a) ����� ������ ���� �������������
		b) ����� �� ������ �������� �� ������� ������������� �������� int
	4. ������ ��������� ������
		a) ������ ������� ����� ����� ���������� ������������ ������
				�� ������� timeOfMaxHeight = sqrt(maxHeight * 2 / g);
		b) ������ ��������� �������� �� ������� initialSpeed = g * timeOfMaxHeight
	5. � ����� 0.1 ����� ������ �� ��� ������� ������� ����� ������� � ������ ������
		a) ����� ������� ���������� ���������� ������ ������ (�������� ������)
		b) ����� ������� ���������� ��������� ������ ������ (����� ������)
*/

int main()
{
	const float g = 9.8f;
	float timeOfMaxHeight;
	int maxHeight;
	printf("S: ");
	if (0 == scanf("%d", &maxHeight))
	{
		printf("\n" "expected floating-point number" "\n");
		exit(1);
	}
	// v(t) == v0 - g * t
	// v0 = g * T
	// s(t) == v0 * t - 0.5 * g * t * t
	timeOfMaxHeight = sqrt(maxHeight * 2 / g);
	printf("T=%f\n", timeOfMaxHeight);
	bool flag = false;
	for (float currentTimePoint = 0; currentTimePoint < timeOfMaxHeight * 2; currentTimePoint += 0.1f)
	{
		if (currentTimePoint > timeOfMaxHeight && !flag)
		{
			flag = true;
			float initialSpeed = g * timeOfMaxHeight;
			float currentHeight = initialSpeed * timeOfMaxHeight - 0.5 * g * timeOfMaxHeight * timeOfMaxHeight;
			printf("t=%f, s=%f\n", timeOfMaxHeight, currentHeight);
		}
		float initialSpeed = g * timeOfMaxHeight;
		float currentHeight = initialSpeed * currentTimePoint - 0.5 * g * currentTimePoint * currentTimePoint;
		printf("t=%f, s=%f\n", currentTimePoint, currentHeight);
	}

	float initialSpeed = g * timeOfMaxHeight;
	float currentHeight = initialSpeed * (timeOfMaxHeight * 2) - 0.5 * g * (timeOfMaxHeight * 2) * (timeOfMaxHeight * 2);
	printf("t=%f, s=%f\n", timeOfMaxHeight * 2, currentHeight);

	// TODO: remove system("pause") and never use it again.
	system("pause");

	return 0;
}
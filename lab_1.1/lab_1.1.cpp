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
				�� ������� t(h(max)) = sqrt(h(max) * 2 / g);
		b) ������ ��������� �������� �� ������� v(0) = g * t(h(max))
	5. � ����� 0.1 ����� ������ �� ��� ������� ������� ����� ������� � ������ ������,
				������ �� ������� h(t) = v(0)*t + g*t^2/2
		a) ����� ������� ���������� ������������ ������ ������ (�������� ������)
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
	timeOfMaxHeight = sqrt(maxHeight * 2 / g);
	float initialSpeed = g * timeOfMaxHeight;
	printf("T=%f\n", timeOfMaxHeight);
	bool flag = false;
	for (float currentTimePoint = 0; currentTimePoint < timeOfMaxHeight * 2; currentTimePoint += 0.1f)
	{
		if (currentTimePoint > timeOfMaxHeight && !flag)
		{
			flag = true;
			float currentHeight = initialSpeed * timeOfMaxHeight - 0.5 * g * timeOfMaxHeight * timeOfMaxHeight;
			printf("t=%f, s=%f\n", timeOfMaxHeight, currentHeight);
		}
		float currentHeight = initialSpeed * currentTimePoint - 0.5 * g * currentTimePoint * currentTimePoint;
		printf("t=%f, s=%f\n", currentTimePoint, currentHeight);
	}

	float currentHeight = initialSpeed * (timeOfMaxHeight * 2) - 0.5 * g * (timeOfMaxHeight * 2) * (timeOfMaxHeight * 2);
	printf("t=%f, s=%f\n", timeOfMaxHeight * 2, currentHeight);

	// TODO: remove system("pause") and never use it again.
	system("pause");

	return 0;
}
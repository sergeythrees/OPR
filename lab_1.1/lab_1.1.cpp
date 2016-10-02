#include "stdafx.h"
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
float calcTimeOfCurrentHeight(int currentHeight)
{
	return sqrt(currentHeight * 2 / 9.8f);
}
int main()
{
	const float g = 9.8f;
	float timeOfMaxHeight;
	float currentHeight;
	int maxHeight;
	printf("S: ");
	if (0 == scanf("%d", &maxHeight))
	{
		printf("\n" "expected floating-point number" "\n");
		return 1;
	}
	timeOfMaxHeight = calcTimeOfCurrentHeight(maxHeight);
	float initialSpeed = g * timeOfMaxHeight;
	printf("T=%f\n", timeOfMaxHeight);
	bool flag = false;
	for (float currentTimePoint = 0; currentTimePoint < timeOfMaxHeight * 2; currentTimePoint += 0.1f)
	{
		if (currentTimePoint > timeOfMaxHeight && !flag)
		{
			flag = true;
			currentHeight = initialSpeed * timeOfMaxHeight - 0.5 * g * timeOfMaxHeight * timeOfMaxHeight;
			printf("t=%f, s=%f\n", timeOfMaxHeight, currentHeight);
		}
		currentHeight = initialSpeed * currentTimePoint - 0.5 * g * currentTimePoint * currentTimePoint;
		printf("t=%f, s=%f\n", currentTimePoint, currentHeight);
	}

	currentHeight = initialSpeed * (timeOfMaxHeight * 2) - 0.5 * g * (timeOfMaxHeight * 2) * (timeOfMaxHeight * 2);
	printf("t=%f, s=%f\n", timeOfMaxHeight * 2, currentHeight);

	return 0;
}
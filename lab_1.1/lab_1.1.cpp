#include "stdafx.h"
#include <cmath>
#define G 9.8f

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
int getInput(int &maxHeight)
{
	printf("Enter jump height: ");
	if (scanf("%d", &maxHeight) == 0)
	{
		printf("\n" "expected floating-point number" "\n");
		return 0;
	}
	return 1;
}
float calcTimeOfCurrentHeight(int Height)
{
	return sqrt(Height * 2 / G);
}
float calc�urrentHeight(float initialSpeed, float TimePoint)
{
	return initialSpeed * TimePoint - 0.5 * G * TimePoint * TimePoint;
}
void calcStartingValues(int maxHeight, float &timeOfMaxHeight, float &initialSpeed)
{
	timeOfMaxHeight = calcTimeOfCurrentHeight(maxHeight);
	initialSpeed = G * timeOfMaxHeight;
}
int main()
{
	int maxHeight;
	
	if (!getInput(maxHeight))
		return 1;
	
	float timeOfMaxHeight, initialSpeed;
	calcStartingValues(maxHeight, timeOfMaxHeight, initialSpeed);
	printf("T=%f\n", timeOfMaxHeight);

	float currentHeight;
	bool flag = false;
	for (float currentTimePoint = 0; currentTimePoint < timeOfMaxHeight * 2; currentTimePoint += 0.1f)
	{
		if (currentTimePoint > timeOfMaxHeight && !flag)
		{
			flag = true;
			currentHeight = calc�urrentHeight(initialSpeed, timeOfMaxHeight);
			printf("t=%f, s=%f\n", timeOfMaxHeight, currentHeight);
		}
		currentHeight = calc�urrentHeight(initialSpeed, currentTimePoint);
		printf("t=%f, s=%f\n", currentTimePoint, currentHeight);
	}

	currentHeight = calc�urrentHeight(initialSpeed, timeOfMaxHeight * 2);
	printf("t=%f, s=%f\n", timeOfMaxHeight * 2, currentHeight);

	return 0;
}
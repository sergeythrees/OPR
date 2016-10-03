#include "stdafx.h"
#include <cmath>
#define GRAVITY_CONST 9.8f

// This program takes max jump height from input and prints
// jump height for every time point with step 0.1 seconds.
// Program should print all time points when height is min and max.

int GetInput(int &maxHeight)
{
	printf("Enter jump height: ");
	if (scanf("%d", &maxHeight) == 0)
	{
		printf("\n" "expected floating-point number" "\n");
		return 0;
	}
	return 1;
}
float CalculateTimeOfCurrentHeight(int Height)
{
	return sqrt(Height * 2 / GRAVITY_CONST);
}
float Calculate—urrentHeight(float initialSpeed, float TimePoint)
{
	return initialSpeed * TimePoint - 0.5 * GRAVITY_CONST * TimePoint * TimePoint;
}
void CalculateStartingValues(int maxHeight, float &timeOfMaxHeight, float &initialSpeed)
{
	timeOfMaxHeight = CalculateTimeOfCurrentHeight(maxHeight);
	initialSpeed = GRAVITY_CONST * timeOfMaxHeight;
}
void PrintCurrentHeight(float &initialSpeed, float currentTime)
{
	float currentHeight = Calculate—urrentHeight(initialSpeed, currentTime);
	printf("t=%f, h=%f\n", currentTime, currentHeight);
}
void PrintStats(float &timeOfMaxHeight, float &initialSpeed)
{
	bool isMaxHeight = false;
	printf("Time when height has it's maximum value = %f\n", timeOfMaxHeight);
	for (float time = 0; time < timeOfMaxHeight * 2; time += 0.1f)
	{
		if (time > timeOfMaxHeight && !isMaxHeight)
		{
			isMaxHeight = true;
			PrintCurrentHeight(initialSpeed, time);
		}
		PrintCurrentHeight(initialSpeed, time);
	}

	PrintCurrentHeight(initialSpeed, timeOfMaxHeight * 2);
}
int main()
{
	int maxHeight;
	
	if (!GetInput(maxHeight))
		return 1;
	
	float timeOfMaxHeight, initialSpeed;
	CalculateStartingValues(maxHeight, timeOfMaxHeight, initialSpeed);

	PrintStats(timeOfMaxHeight, initialSpeed);

	return 0;
}
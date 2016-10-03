#include "stdafx.h"
#include <cmath>
#define GRAVITY_CONST 9.8f

/*
- Программа получает на вход высоту прыжка.
- Вычисляет и выводит время, когда будет достигнута максимальная высота
- Затем с шагом 0.1 проходит по всем моментам времени между началом и концом прыжка и выводит высоту в этот момент времени
- Кроме того, обязательно выводится момент середины прыжка и момент конца прыжка
*/

/*
Псевдокод:
1. Запрос максимальной высоты прыжка от пользователя
2. Проверка корректности ввода:
a) число должно быть положительным
b) число не должно выходить за пределы максимального значения int
3. Расчет начальных данных
a) Расчет времени когда будет достигнута максимальная высота
по формуле t(h(max)) = sqrt(h(max) * 2 / g);
b) Расчет начальной скорости по формуле v(0) = g * t(h(max))
4. С шагом 0.1 вывод высоты во все моменты времени между началом и концом прыжка,
расчет по формуле h(t) = v(0)*t + g*t^2/2
a) вывод времени достижения максимальной высоты прыжка (середина прыжка)
b) вывод времени достижения начальной высоты прыжка (конец прыжка)
*/

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
float CalculateСurrentHeight(float initialSpeed, float TimePoint)
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
	float currentHeight = CalculateСurrentHeight(initialSpeed, currentTime);
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
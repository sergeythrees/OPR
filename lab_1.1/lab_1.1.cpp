#include "stdafx.h"
#include <cmath>
#define G 9.8f

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
	4. Расчет начальных данных
		a) Расчет времени когда будет достигнута максимальная высота
				по формуле t(h(max)) = sqrt(h(max) * 2 / g);
		b) Расчет начальной скорости по формуле v(0) = g * t(h(max))
	5. С шагом 0.1 вывод высоты во все моменты времени между началом и концом прыжка,
				расчет по формуле h(t) = v(0)*t + g*t^2/2
		a) вывод времени достижения максимальной высоты прыжка (середина прыжка)
		b) вывод времени достижения начальной высоты прыжка (конец прыжка)
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
float calcСurrentHeight(float initialSpeed, float TimePoint)
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
			currentHeight = calcСurrentHeight(initialSpeed, timeOfMaxHeight);
			printf("t=%f, s=%f\n", timeOfMaxHeight, currentHeight);
		}
		currentHeight = calcСurrentHeight(initialSpeed, currentTimePoint);
		printf("t=%f, s=%f\n", currentTimePoint, currentHeight);
	}

	currentHeight = calcСurrentHeight(initialSpeed, timeOfMaxHeight * 2);
	printf("t=%f, s=%f\n", timeOfMaxHeight * 2, currentHeight);

	return 0;
}
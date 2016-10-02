#include "stdafx.h"
#include <cmath>

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
float calcTimeOfCurrentHeight(int Height)
{
	return sqrt(Height * 2 / 9.8f);
}
float calcСurrentHeight(float initialSpeed, float TimePoint)
{
	return initialSpeed * TimePoint - 0.5 * 9.8f * TimePoint * TimePoint;
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
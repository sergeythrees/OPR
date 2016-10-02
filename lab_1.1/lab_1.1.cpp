#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
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
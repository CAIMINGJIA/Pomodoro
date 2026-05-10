#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <graphics.h>

const short Radius = 50;

int main()
{
	initgraph(1000, 600);

	printf("Press any key to pause/resume.\n");
	
	ExMessage msg;
	unsigned long long counter = 0;
	short x = 0, y = Radius;
	bool pause = 1;

	BeginBatchDraw();

	while (true)
	{
		DWORD begin_time = GetTickCount();

		//while (peekmessage(&msg, EX_KEY))
		//{
		//	if (peekmessage(&msg, WM_KEYDOWN))
		//		pause = !pause;
		//}

		++counter;
		if (counter == 10)
		{
			y += 2 * Radius;
			counter = 1;
		}
		x = counter * Radius * 2;

		solidcircle(x, y, Radius);
		if (x == 900 && y == 550)
		{
			x = 0;
			y = Radius;
			cleardevice();
		}

		FlushBatchDraw();

		DWORD end_time = GetTickCount();
		DWORD detal_time = end_time - begin_time;

		if (detal_time < 10)
			Sleep(10 - detal_time);
	}

	EndBatchDraw();
}

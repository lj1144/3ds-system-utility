#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>

int main(int argc, char* argv[])
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);



	// Main loop
	int selectedOption = 0;
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		// Your code goes here
		consoleClear();
		printf("System Utility 1.0 | The Ultimate\n\n");
		if (selectedOption == 0)
		{
			printf("> System Information\n");
			printf(" Hardware Diagnostics\n");
			printf(" Configuration\n");
		}
		if (selectedOption == 1)
		{
			printf(" System Information\n");
			printf("> Hardware Diagnostics\n");
			printf(" Configuration\n");
		}
		if (selectedOption == 2)
		{
			printf(" System Information\n");
			printf(" Hardware Diagnostics\n");
			printf("> Configuration\n");
		}

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		if (kDown & (KEY_DDOWN))
		{
			if (selectedOption < 2)
			{
				selectedOption++;
			}
		}
		else if (kDown & (KEY_DUP))
		{
			if (selectedOption > 0)
			{
				selectedOption--;
			}

		}


	}


	gfxExit();
	return 0;
}
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "ansi_colors.h"

int RandomNumber() {

	srand(time(NULL));

	int MinNumber = 1;
	int MaxNumber = 6;

	int RandomNum = (rand() % MaxNumber) + MinNumber;

	return RandomNum;
}


int main() {	

	printf("Ich lege einen wurf vor du sagst ob du das selbe/höher oder niedriger wirfst\n");
	printf("ich Fange an.\n");

	int guthaben = 20;
	char *weiter = "ja";

	while (guthaben > 0 && weiter == "ja"){
		int ComputerWurf = RandomNumber();
		printf(ANSI_BLUE"Computer würfelt: %d"ANSI_RESET,ComputerWurf);

		//printf("Deine Chancen: \n");

		char EingabeOk = false;
		while (!EingabeOk) {
			char spieleransage[10];
			printf("Was wirst du würfeln: ");
			fgets(spieleransage, sizeof(spieleransage), stdin);
			spieleransage[strcspn(spieleransage, "\n")] = 0;

			if (strcmp(spieleransage, "weniger") == 0 && ComputerWurf < 1) {
				printf("Weniger als 1 mutig...");
			} else if (strcmp(spieleransage, "mehr") == 0 && ComputerWurf == 6) {
				printf("Klar merh als 6...");
			} else {
				EingabeOk = spieleransage == "weniger" || spieleransage == "mehr" || spieleransage == "gleich";
			}

			int einsatz = guthaben + 1;
			printf("wie viel setzt du drauf: ");
			fgets(einsatz, sizeof(einsatz), stdin);
			guthaben -= einsatz;
			printf("OK dann los!\n");
			int SpielerWurf = RandomNumber();
			printf("Du Wuerfelst: %d", SpielerWurf);



		}


	}

	return 0;
}

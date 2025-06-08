#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 8
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

int main() {
	int soupCount = 0;
	int relationship = 2;
	int prevCatPos = 1;
	int catPos = 2;
	int input, dice;

	srand(time(NULL));

	printf("**** 야옹이와 수프 ****\n\n");
	printf(" /\\_/\\   \n");
	printf("( o.o )  \n");
	printf(" > ^ <\n\n");
	printf("야옹이의 이름은 쫀떡입니다.\n");
	Sleep(1000);
	system("cls");

	while (1) {
		Sleep(2500);
		system("cls");

		printf("==================== 현재 상태 ===================\n");
		printf("현재까지 만든 수프: %d개\n", soupCount);
		printf("집사와의 관계(0~4): %d\n", relationship);
		if (relationship == 0) printf("곁에 오는 것조차 싫어합니다.\n");
		else if (relationship == 1) printf("간식 자판기 취급입니다.\n");
		else if (relationship == 2) printf("그럭저럭 쓸 만한 집사입니다.\n");
		else if (relationship == 3) printf("훌륭한 집사로 인정 받고 있습니다.\n");
		else if (relationship == 4) printf("집사 껌딱지입니다.\n");
		printf("==================================================\n");

		printf("쫀떡 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n");
		int target = 6 - relationship;
		printf("주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다.\n", target);
		printf("주사위를 굴립니다. 또르륵...\n");
		Sleep(1000);

		dice = rand() % 6 + 1;
		printf("%d이(가) 나왔습니다!\n", dice);
		Sleep(500);

		prevCatPos = catPos;
		if (dice >= target) {
			if (catPos < ROOM_WIDTH - 2) {
				catPos++;
				printf("냄비 쪽으로 움직입니다.\n");
			}
		}
		else {
			if (catPos > 1) {
				catPos--;
				printf("집 쪽으로 움직입니다.\n");
			}
		}

		if (catPos == HME_POS) {
			printf("쫀떡은(는) 자신의 집에서 편안함을 느낍니다.\n\n");
		}
		else if (catPos == BWL_POS) {
			int soupType = rand() % 3;
			printf("쫀떡이(가) ");
			if (soupType == 0) printf("감자 수프를 만들었습니다!\n");
			else if (soupType == 1) printf("양송이 수프를 만들었습니다!\n");
			else printf("브로콜리 수프를 만들었습니다!\n");
			soupCount++;
			printf("현재까지 만든 수프: %d개\n\n", soupCount);
		}

		for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
		printf("\n");

		printf("#");
		for (int i = 1; i < ROOM_WIDTH - 1; i++) {
			if (i == HME_POS) printf("H");
			else if (i == BWL_POS) printf("B");
			else printf(" ");
		}
		printf("#\n");

		printf("#");
		for (int i = 1; i < ROOM_WIDTH - 1; i++) {
			if (i == catPos) printf("C");
			else if (i == prevCatPos && catPos != prevCatPos) printf(".");
			else printf(" ");
		}
		printf("#\n");

		for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
		printf("\n");

		printf("\n어떤 상호작용을 하시겠습니까?  0. 아무것도 하지 않음 1. 긁어 주기\n>> ");

		while (1) {
			scanf_s("%d", &input);
			if (input == 0 || input == 1) break;
			else printf(">> ");
		}

		if (input == 0) {
			printf("아무것도 하지 않습니다.\n");
			Sleep(500);
			printf("4/6의 확률로 친밀도가 떨어집니다.\n");
			Sleep(500);
			printf("주사위를 굴립니다. 또르륵...\n");
			Sleep(1000);
			dice = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다!\n", dice);
			Sleep(500);

			if (dice <= 4) {
				if (relationship > 0) {
					relationship--;
					printf("친밀도가 떨어집니다.\n");
				}
				else {
					printf("이미 친밀도가 0이라 더 이상 떨어지지 않습니다.\n");
				}
			}
			else {
				printf("다행히 친밀도가 떨어지지 않았습니다.\n");
			}
		}
		else if (input == 1) {
			printf("쫀떡의 턱을 긁어주었습니다.\n");
			Sleep(500);
			printf("2/6 확률로 친밀도가 높아집니다.\n");
			Sleep(500);
			printf("주사위를 굴립니다. 또르륵...\n");
			Sleep(1000);
			dice = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다!\n", dice);
			Sleep(500);

			if (dice >= 5) {
				if (relationship < 4) {
					relationship++;
					printf("친밀도가 높아집니다.\n");
				}
				else {
					printf("이미 친밀도가 최고치입니다.\n");
				}
			}
			else {
				printf("친밀도는 그대로입니다.\n");
			}
		}

		printf("현재 친밀도: %d\n", relationship);
	}

	return 0;
}
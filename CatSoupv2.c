#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 8
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)
#define SCR_POS 3
#define TOW_POS 4

int main() {
	int soupCount = 0;
	int relationship = 2;
	int prevCatPos = 1;
	int catPos = 2;
	int input, dice;
	int cp = 0;
	int mood = 3;
	int Scratch = 0;
	int Tower = 0;
	int toyMouse = 0;
	int toyLaser = 0;
	int beforeMood = mood;
	int beforeRel = relationship;

	srand((unsigned int)time(NULL));

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
		printf("CP: %d 포인트\n", cp);
		printf("쫀떡이 기분(0~3): %d\n", mood);
		if (mood == 0) printf("  기분이 매우 나쁩니다.\n");
		else if (mood == 1) printf("  심심해합니다.\n");
		else if (mood == 2) printf("  식빵을 굽습니다.\n");
		else if (mood == 3) printf("  골골송을 부릅니다.\n");
		printf("집사와의 관계(0~4): %d\n", relationship);
		if (relationship == 0) printf("  곁에 오는 것조차 싫어합니다.\n");
		else if (relationship == 1) printf("  간식 자판기 취급입니다.\n");
		else if (relationship == 2) printf("  그럭저럭 쓸만한 집사입니다.\n");
		else if (relationship == 3) printf("  훌륭한 집사로 인정받고 있습니다.\n");
		else if (relationship == 4) printf("  집사 껌딱지입니다.\n");
		printf("==================================================\n");

		int target = 6 - relationship;
		printf("\n6-2: 주사위 눈이 %d이하면 그냥 기분이 나빠집니다.\n", target);
		printf("주사위를 굴립니다. 또르륵...\n");
		Sleep(1000);

		dice = rand() % 6 + 1;
		printf("%d이(가) 나왔습니다.\n", dice);
		Sleep(500);

		if (dice <= target) {
			if (mood > 0) {
				printf("쫀떡이의 기분이 나빠집니다: %d -> %d\n", mood, mood - 1);
				mood--;
			}
		}

		prevCatPos = catPos;

		if (mood == 0) {
			if (catPos > HME_POS) {
				catPos = catPos - 1;
				printf("기분이 매우 나쁜 쫀떡은 집으로 향합니다.\n");
			}
		}
		else if (mood == 1) {
			if (Scratch == 1 || Tower == 1) {
				int distScr = ROOM_WIDTH;
				int distTow = ROOM_WIDTH;

				if (Scratch == 1) {
					if (SCR_POS > catPos) distScr = SCR_POS - catPos;
					else distScr = catPos - SCR_POS;
				}
				if (Tower == 1) {
					if (TOW_POS > catPos) distTow = TOW_POS - catPos;
					else distTow = catPos - TOW_POS;
				}

				int target;
				if (distScr <= distTow) target = SCR_POS;
				else target = TOW_POS;

				if (catPos < target) catPos = catPos + 1;
				else if (catPos > target) catPos = catPos - 1;

				if (target == SCR_POS) printf("쫀떡은 심심해서 스크래처 쪽으로 이동합니다.\n");
				else printf("쫀떡은 심심해서 캣타워 쪽으로 이동합니다.\n");
			}
			else {
				mood = mood - 1;
				printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
			}
		}
		else if (mood == 2) {
			printf("쫀떡은 기분좋게 식빵을 굽고 있습니다.\n");
		}
		else if (mood == 3) {
			if (catPos < BWL_POS) {
				catPos = catPos + 1;
				printf("쫀떡은 골골송을 부르며 수프를 만들러 갑니다.\n");
			}
		}

		if (catPos == HME_POS && prevCatPos == HME_POS) {
			if (mood < 3) {
				mood = mood + 1;
				printf("쫀떡은 집에서 휴식을 취하며 기분이 좋아졌습니다.\n");
			}
		}
		else if (catPos == BWL_POS) {
			int soupType = rand() % 3;
			printf("쫀떡이 ");
			if (soupType == 0) printf("감자 수프를 만들었습니다!\n");
			else if (soupType == 1) printf("양송이 수프를 만들었습니다!\n");
			else printf("브로콜리 수프를 만들었습니다!\n");
			soupCount = soupCount + 1;
			printf("현재까지 만든 수프: %d개\n", soupCount);
		}
		else if (catPos == SCR_POS && Scratch == 1) {
			if (mood < 3) mood = mood + 1;
			printf("쫀떡은 스크래처를 긁고 놀았습니다.\n");
		}
		else if (catPos == TOW_POS && Tower == 1) {
			if (mood <= 1) mood = mood + 2;
			else mood = 3;
			printf("쫀떡은 캣타워를 뛰어다닙니다.\n");
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


		for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
		printf("\n");

		for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
		printf("\n");

		int optionCount = 2;
		printf("\n어떤 상호작용을 하시겠습니까?\n");
		printf("0. 아무것도 하지 않음\n");
		printf("1. 긁어 주기\n");

		if (toyMouse == 1 && toyLaser == 1) {
			printf("2. 장난감 쥐로 놀아 주기\n");
			printf("3. 레이저 포인터로 놀아 주기\n");
			optionCount = 4;
		}
		else if (toyMouse == 1) {
			printf("2. 장난감 쥐로 놀아 주기\n");
			optionCount = 3;
		}
		else if (toyLaser == 1) {
			printf("2. 레이저 포인터로 놀아 주기\n");
			optionCount = 3;
		}

		beforeMood = mood;
		beforeRel = relationship;

		while (1) {
			printf(">> ");
			scanf_s("%d", &input);
			if (input >= 0 && input < optionCount) break;
		}

		dice = rand() % 6 + 1;

		if (input == 0) {
			if (mood > 0) {
				mood = mood - 1;
				printf("쫀떡의 기분이 나빠졌습니다: %d -> %d\n", beforeMood, mood);
			}

			if (dice <= 5) {
				if (relationship > 0) {
					relationship = relationship - 1;
					printf("집사와의 관계가 나빠집니다.\n");
				}
			}
		}
		else if (input == 1) {
			printf("쫀떡의 기분은 그대로 입니다: %d\n", mood);

			if (dice >= 5) {
				if (relationship < 4) {
					relationship = relationship + 1;
					printf("집사와의 관계가 깊어집니다.\n");
				}
			}
		}
		else if (input == 2) {
			if (mood < 3) {
				mood = mood + 1;
			}
			printf("장난감 쥐로 놀아주었습니다. 쫀떡의 기분이 조금 좋아졌습니다: %d -> %d\n", beforeMood, mood);

			if (dice >= 4) {
				if (relationship < 4) {
					relationship = relationship + 1;
					printf("집사와의 관계가 깊어집니다.\n");
				}
			}
		}
		else if (input == 3) {
			if (mood <= 1) {
				mood = mood + 2;
			}
			else {
				mood = 3;
			}
			printf("레이저 포인터로 신나게 놀아 주었습니다. 쫀떡의 기분이 꽤 좋아졌습니다: %d -> %d\n", beforeMood, mood);

			if (dice >= 2) {
				if (relationship < 4) {
					relationship = relationship + 1;
					printf("집사와의 관계가 깊어집니다.\n");
				}
			}
		}


		printf("현재 친밀도: %d\n", relationship);
	}

	return 0;
}
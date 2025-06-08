#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 12
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

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
	int SCR_POS = -1;
	int TOW_POS = -1;

	srand((unsigned int)time(NULL));

	printf("**** �߿��̿� ���� ****\n\n");
	printf(" /\\_/\\   \n");
	printf("( o.o )  \n");
	printf(" > ^ <\n\n");
	printf("�߿����� �̸��� �˶��Դϴ�.\n");
	Sleep(1000);
	system("cls");

	while (1) {
		Sleep(2500);
		system("cls");

		printf("==================== ���� ���� ===================\n");
		printf("������� ���� ����: %d��\n", soupCount);
		printf("CP: %d ����Ʈ\n", cp);
		printf("�˶��� ���(0~3): %d\n", mood);
		if (mood == 0) printf("  ����� �ſ� ���޴ϴ�.\n");
		else if (mood == 1) printf("  �ɽ����մϴ�.\n");
		else if (mood == 2) printf("  �Ļ��� �����ϴ�.\n");
		else if (mood == 3) printf("  ������ �θ��ϴ�.\n");
		printf("������� ����(0~4): %d\n", relationship);
		if (relationship == 0) printf("  �翡 ���� ������ �Ⱦ��մϴ�.\n");
		else if (relationship == 1) printf("  ���� ���Ǳ� ����Դϴ�.\n");
		else if (relationship == 2) printf("  �׷����� ������ �����Դϴ�.\n");
		else if (relationship == 3) printf("  �Ǹ��� ����� �����ް� �ֽ��ϴ�.\n");
		else if (relationship == 4) printf("  ���� �������Դϴ�.\n");
		printf("==================================================\n");

		int target = 6 - relationship;
		printf("\n6-2: �ֻ��� ���� %d���ϸ� �׳� ����� �������ϴ�.\n", target);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		Sleep(1000);

		dice = rand() % 6 + 1;
		printf("%d��(��) ���Խ��ϴ�.\n", dice);
		Sleep(500);

		if (dice <= target) {
			if (mood > 0) {
				printf("�˶����� ����� �������ϴ�: %d -> %d\n", mood, mood - 1);
				mood--;
			}
		}

		prevCatPos = catPos;

		if (mood == 0) {
			if (catPos > HME_POS) {
				catPos = catPos - 1;
				printf("����� �ſ� ���� �˶��� ������ ���մϴ�.\n");
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

				if (target == SCR_POS) printf("�˶��� �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n");
				else printf("�˶��� �ɽ��ؼ� ĹŸ�� ������ �̵��մϴ�.\n");
			}
			else {
				mood = mood - 1;
				printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
			}
		}
		else if (mood == 2) {
			printf("�˶��� ������� �Ļ��� ���� �ֽ��ϴ�.\n");
		}
		else if (mood == 3) {
			if (catPos < BWL_POS) {
				catPos = catPos + 1;
				printf("�˶��� ������ �θ��� ������ ���鷯 ���ϴ�.\n");
			}
		}

		if (catPos == HME_POS && prevCatPos == HME_POS) {
			if (mood < 3) {
				mood = mood + 1;
				printf("�˶��� ������ �޽��� ���ϸ� ����� ���������ϴ�.\n");
			}
		}
		else if (catPos == BWL_POS) {
			int soupType = rand() % 3;
			printf("�˶��� ");
			if (soupType == 0) printf("���� ������ ��������ϴ�!\n");
			else if (soupType == 1) printf("����� ������ ��������ϴ�!\n");
			else printf("����ݸ� ������ ��������ϴ�!\n");
			soupCount = soupCount + 1;
			printf("������� ���� ����: %d��\n", soupCount);
		}
		else if (catPos == SCR_POS && Scratch == 1) {
			if (mood < 3) mood = mood + 1;
			printf("�˶��� ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n");
		}
		else if (catPos == TOW_POS && Tower == 1) {
			if (mood <= 1) mood = mood + 2;
			else mood = 3;
			printf("�˶��� ĹŸ���� �پ�ٴմϴ�.\n");
		}


		for (int i = 0; i < ROOM_WIDTH; i++) printf("#");
		printf("\n");

		printf("#");
		for (int i = 1; i < ROOM_WIDTH - 1; i++) {
			if (i == HME_POS) printf("H");
			else if (i == BWL_POS) printf("B");
			else if (i == SCR_POS && Scratch == 1) printf("S");  
			else if (i == TOW_POS && Tower == 1) printf("T");    
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
		printf("\n� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
		printf("0. �ƹ��͵� ���� ����\n");
		printf("1. �ܾ� �ֱ�\n");

		if (toyMouse == 1 && toyLaser == 1) {
			printf("2. �峭�� ��� ��� �ֱ�\n");
			printf("3. ������ �����ͷ� ��� �ֱ�\n");
			optionCount = 4;
		}
		else if (toyMouse == 1) {
			printf("2. �峭�� ��� ��� �ֱ�\n");
			optionCount = 3;
		}
		else if (toyLaser == 1) {
			printf("2. ������ �����ͷ� ��� �ֱ�\n");
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
				printf("�˶��� ����� ���������ϴ�: %d -> %d\n", beforeMood, mood);
			}

			if (dice <= 5) {
				if (relationship > 0) {
					relationship = relationship - 1;
					printf("������� ���谡 �������ϴ�.\n");
				}
			}
		}
		else if (input == 1) {
			printf("�˶��� ����� �״�� �Դϴ�: %d\n", mood);

			if (dice >= 5) {
				if (relationship < 4) {
					relationship = relationship + 1;
					printf("������� ���谡 ������ϴ�.\n");
				}
			}
		}
		else if (input == 2) {
			if (mood < 3) {
				mood = mood + 1;
			}
			printf("�峭�� ��� ����־����ϴ�. �˶��� ����� ���� ���������ϴ�: %d -> %d\n", beforeMood, mood);

			if (dice >= 4) {
				if (relationship < 4) {
					relationship = relationship + 1;
					printf("������� ���谡 ������ϴ�.\n");
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
			printf("������ �����ͷ� �ų��� ��� �־����ϴ�. �˶��� ����� �� ���������ϴ�: %d -> %d\n", beforeMood, mood);

			if (dice >= 2) {
				if (relationship < 4) {
					relationship = relationship + 1;
					printf("������� ���谡 ������ϴ�.\n");
				}
			}
		}

		int produce = 0;
		if (mood > 0) {
			produce = (mood - 1) + relationship;
		}
		else {
			produce = relationship;
		}
		cp = cp + produce;

		printf("�˶��� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", produce);
		printf("���� CP: %d ����Ʈ\n", cp);

		int shopChoice;
		while (1) {
			printf("\n�������� ������ �� �� �ֽ��ϴ�.\n");
			printf("� ������ �����ұ��?\n");
			printf("  0. �ƹ� �͵� ���� �ʴ´�.\n");

			printf("  1. �峭�� ��: 1 CP");
			if (toyMouse == 1) printf(" (ǰ��)");
			printf("\n");

			printf("  2. ������ ������: 2 CP");
			if (toyLaser == 1) printf(" (ǰ��)");
			printf("\n");

			printf("  3. ��ũ��ó: 4 CP");
			if (Scratch == 1) printf(" (ǰ��)");
			printf("\n");

			printf("  4. Ĺ Ÿ��: 6 CP");
			if (Tower == 1) printf(" (ǰ��)");
			printf("\n");

			printf(">> ");
			scanf_s("%d", &shopChoice);

			if (shopChoice < 0 || shopChoice > 4) continue;

			if (shopChoice == 0) break;

			if ((shopChoice == 1 && toyMouse == 1) ||
				(shopChoice == 2 && toyLaser == 1) ||
				(shopChoice == 3 && Scratch == 1) ||
				(shopChoice == 4 && Tower == 1)) {
				printf("�̹� ������ �����Դϴ�.\n");
				continue;
			}

			int cost = 0;
			if (shopChoice == 1) cost = 1;
			if (shopChoice == 2) cost = 2;
			if (shopChoice == 3) cost = 4;
			if (shopChoice == 4) cost = 6;

			if (cp < cost) {
				printf("CP�� �����մϴ�.\n");
				continue;
			}

			cp = cp - cost;

			if (shopChoice == 1) {
				toyMouse = 1;
				printf("�峭�� �㸦 �����߽��ϴ�.\n");
			}
			else if (shopChoice == 2) {
				toyLaser = 1;
				printf("������ �����͸� �����߽��ϴ�.\n");
			}
			else if (shopChoice == 3) {
				Scratch = 1;
				printf("��ũ��ó�� �����߽��ϴ�.\n");
				while (1) {
					int pos = rand() % (ROOM_WIDTH - 2) + 1;
					if (pos != HME_POS && pos != BWL_POS && pos != TOW_POS && pos != catPos) {
						SCR_POS = pos;
						break;
					}
				}
			}
			else if (shopChoice == 4) {
				Tower = 1;
				printf("ĹŸ���� �����߽��ϴ�.\n");
				while (1) {
					int pos = rand() % (ROOM_WIDTH - 2) + 1;
					if (pos != HME_POS && pos != BWL_POS && pos != SCR_POS && pos != catPos) {
						TOW_POS = pos;
						break;
					}
				}
			}

			break;
		}


		printf("���� ģ�е�: %d\n", relationship);
	}

	return 0;
}
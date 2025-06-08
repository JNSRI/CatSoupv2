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
	int cp = 0;
	int mood = 3;
	int Scratch = 0;
	int Tower = 0;

	srand(time(NULL));

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

		printf("\n� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?  0. �ƹ��͵� ���� ���� 1. �ܾ� �ֱ�\n>> ");

		while (1) {
			scanf_s("%d", &input);
			if (input == 0 || input == 1) break;
			else printf(">> ");
		}

		if (input == 0) {
			printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
			Sleep(500);
			printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			Sleep(500);
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			Sleep(1000);
			dice = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			Sleep(500);

			if (dice <= 4) {
				if (relationship > 0) {
					relationship--;
					printf("ģ�е��� �������ϴ�.\n");
				}
				else {
					printf("�̹� ģ�е��� 0�̶� �� �̻� �������� �ʽ��ϴ�.\n");
				}
			}
			else {
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
			}
		}
		else if (input == 1) {
			printf("�˶��� ���� �ܾ��־����ϴ�.\n");
			Sleep(500);
			printf("2/6 Ȯ���� ģ�е��� �������ϴ�.\n");
			Sleep(500);
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			Sleep(1000);
			dice = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			Sleep(500);

			if (dice >= 5) {
				if (relationship < 4) {
					relationship++;
					printf("ģ�е��� �������ϴ�.\n");
				}
				else {
					printf("�̹� ģ�е��� �ְ�ġ�Դϴ�.\n");
				}
			}
			else {
				printf("ģ�е��� �״���Դϴ�.\n");
			}
		}

		printf("���� ģ�е�: %d\n", relationship);
	}

	return 0;
}
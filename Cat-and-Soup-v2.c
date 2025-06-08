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
		printf("������� ����(0~4): %d\n", relationship);
		if (relationship == 0) printf("�翡 ���� ������ �Ⱦ��մϴ�.\n");
		else if (relationship == 1) printf("���� ���Ǳ� ����Դϴ�.\n");
		else if (relationship == 2) printf("�׷����� �� ���� �����Դϴ�.\n");
		else if (relationship == 3) printf("�Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
		else if (relationship == 4) printf("���� �������Դϴ�.\n");
		printf("==================================================\n");

		printf("�˶� �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n");
		int target = 6 - relationship;
		printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", target);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		Sleep(1000);

		dice = rand() % 6 + 1;
		printf("%d��(��) ���Խ��ϴ�!\n", dice);
		Sleep(500);

		prevCatPos = catPos;
		if (dice >= target) {
			if (catPos < ROOM_WIDTH - 2) {
				catPos++;
				printf("���� ������ �����Դϴ�.\n");
			}
		}
		else {
			if (catPos > 1) {
				catPos--;
				printf("�� ������ �����Դϴ�.\n");
			}
		}

		if (catPos == HME_POS) {
			printf("�˶���(��) �ڽ��� ������ ������� �����ϴ�.\n\n");
		}
		else if (catPos == BWL_POS) {
			int soupType = rand() % 3;
			printf("�˶���(��) ");
			if (soupType == 0) printf("���� ������ ��������ϴ�!\n");
			else if (soupType == 1) printf("����� ������ ��������ϴ�!\n");
			else printf("����ݸ� ������ ��������ϴ�!\n");
			soupCount++;
			printf("������� ���� ����: %d��\n\n", soupCount);
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
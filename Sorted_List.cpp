#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef struct Record { // ���ڵ� ����
	char code;
	char sNum[20];
	char name[20];
	char major[20];
	char grade[20];
	char pNum[20];
} Record;

FILE *tempFile;			// n�� Ʈ����� �� ���ϱ� ���� ����
FILE *transactionFile;		// Ʈ����� ����
FILE *new_masterFile;        	// �� ������ ����

Record trans;              	// Ʈ����� ���ڵ� ����
Record result[100];		// n�� �ִ� 100�̹Ƿ� ũ�� 100�� ����ü �迭 ���� 

char tBuff[51];			// �ӽ� ����
char arr[4];			// ù �� n�� ���� �˻�
char ch[100];			// n�� Ʈ����� ���� ���ϱ� ����

void sortedList();		// �������� ����
void getNextTrans();        	// ���� Ʈ������ ���� ���ڵ�
void swap(Record*, Record*);	// �������� �ϱ� ���� �Լ�

int n;				// Ʈ����� ���ڵ��� �� ����
int cnt;				// n�� Ʈ����� ���� ���ϱ� ���� ���� 
int index;			// ����ü �迭 result�� index
bool flag;			// ������ �й��� �ִ��� Ȯ���ϱ� ���� 

int main() {
	sortedList();
	return 0;
}

void sortedList() { // ����, ����, ���� Ʈ������� ó��
	int i = 0;
	tempFile = fopen("input.txt", "r");
	transactionFile = fopen("input.txt", "r");
	new_masterFile = fopen("output.txt", "w");

	fgets(arr, sizeof(arr), transactionFile);
	n = atoi(arr);
	if (n < 1 || n>100) { // ���� : n�� ������ �߸� �Ǿ��� ���
		printf("error: n is out of range\n");
		return;
	}
	while (fgets(ch, sizeof(ch), tempFile) != NULL) {
		cnt++;
	}
	if (n != cnt - 1) { // ���� : n�� Ʈ����� ���ڵ� ���� �ٸ� ���
		printf("error: n and number of transaction records are different\n");
		return;
	}
	cnt = 0;
	fclose(tempFile);

	while (cnt != n) { // ���ڵ� Ʈ����� �� ��ŭ �ݺ�
		cnt++;
		getNextTrans();
		switch (trans.code) { // ���� �ڵ� I: ����, C: ����, D: ����
		case 'I':
			i = 0;
			while (i != index - 1) {
				if (i == index - 1) break;
				if (!strcmp(result[i].sNum, trans.sNum)) { // ������ �й��� ���ڵ尡 �����ϴ� ��� �˻�
					printf("%d��° Ʈ�����(����) ���� ����[�ߺ��� Ű ���� ���ڵ�]\n", cnt);
					memset(&result[--index], 0, sizeof(Record));
					break;
				}
				i++;
			}
			break;
		case 'C':
			i = 0;
			flag = false;
			if (!index) {
				printf("%d��° Ʈ�����(����) ���� ����[������ Ű ���� ���ڵ�]\n", cnt);
				break;
			}
			while (i != index - 1) {
				if (!strcmp(result[i].sNum, trans.sNum)) { //������ �й��� ���ڵ尡 �����ϴ� ��� �˻�
					flag = true;
					break;
				}
				i++;
			}
			if (flag) { // ������ �й��� ���ڵ尡 �����ϸ� ���� ������
				result[i] = trans;
			}
			else {
				printf("%d��° Ʈ�����(����) ���� ����[������ Ű ���� ���ڵ�]\n", cnt);
			}
			break;
		case 'D':
			i = 0;
			flag = false;
			if (!index) {
				printf("%d��° Ʈ�����(����) ���� ����[������ Ű ���� ���ڵ�]\n", cnt);
				break;
			}
			while (i != index - 1) {
				if (!strcmp(result[i].sNum, trans.sNum)) { //������ �й��� ���ڵ尡 �����ϴ� ���
					flag = true;
					break;
				}
				i++;
			}
			if (flag) { // ������ �й��� ���ڵ尡 �����ϸ� �����Ѵ�.
				memset(&result[i], 0, sizeof(Record));
			}
			else {
				printf("%d��° Ʈ�����(����) ���� ����[������ Ű ���� ���ڵ�]\n", cnt);
			}
			break;
		}
	}
	for (int i = 0; i < n; i++) { // result ����ü �迭�� �ִ� �ӽ� ����� ������ ���������Ѵ�.
		for (int j = i; j < n; j++) {
			if (atoi(result[i].sNum) > atoi(result[j].sNum)) {
				swap(&result[i], &result[j]);
			}
		}
	}

	i = 0;
	while (i != n) { // index ����ŭ new_masterFile�� ����Ѵ�.
		if (strcmp(result[i].sNum, ""))
			fprintf(new_masterFile, "%s %s %s %s %s\n", result[i].sNum, result[i].name, result[i].major, result[i].grade, result[i].pNum);
		i++;
	}

	fclose(transactionFile);
	fclose(new_masterFile);
}

void getNextTrans() { // ���� Ʈ����� ������ �ҷ���
	int i = 0;
	fgets(tBuff, sizeof(tBuff), transactionFile);
	while (tBuff[i] != '\0') {
		if (tBuff[i] == ',') { //','���ڰ� ������ �������� �������ش�.
			tBuff[i] = ' ';
		}
		i++;
	}
	sscanf(tBuff, "%c %s %s %s %s %s", &trans.code, trans.sNum, trans.name, trans.major, trans.grade, trans.pNum);
	
	if (tBuff[0] == 'I') // �Է� ����� ��� result ����ü �迭�� �����Ѵ�.
		result[index++] = trans;
}

void swap(Record *first, Record *second){ // �� ���� ����ü �迭�� ��ȯ�ϴ� �Լ�
	Record temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
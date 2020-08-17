#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef struct Record { // 레코드 정의
	char code;
	char sNum[20];
	char name[20];
	char major[20];
	char grade[20];
	char pNum[20];
} Record;

FILE *tempFile;			// n과 트랜잭션 수 비교하기 위한 파일
FILE *transactionFile;		// 트랜잭션 파일
FILE *new_masterFile;        	// 뉴 마스터 파일

Record trans;              	// 트랜잭션 레코드 버퍼
Record result[100];		// n이 최대 100이므로 크기 100인 구조체 배열 선언 

char tBuff[51];			// 임시 버퍼
char arr[4];			// 첫 줄 n의 범위 검사
char ch[100];			// n과 트랜잭션 수를 비교하기 위함

void sortedList();		// 순차파일 갱신
void getNextTrans();        	// 다음 트랜젝션 파일 레코드
void swap(Record*, Record*);	// 버블정렬 하기 위한 함수

int n;				// 트랜잭션 레코드의 총 개수
int cnt;				// n과 트랜잭션 수를 비교하기 위한 변수 
int index;			// 구조체 배열 result의 index
bool flag;			// 동일한 학번이 있는지 확인하기 위함 

int main() {
	sortedList();
	return 0;
}

void sortedList() { // 삽입, 변경, 삭제 트랜잭션을 처리
	int i = 0;
	tempFile = fopen("input.txt", "r");
	transactionFile = fopen("input.txt", "r");
	new_masterFile = fopen("output.txt", "w");

	fgets(arr, sizeof(arr), transactionFile);
	n = atoi(arr);
	if (n < 1 || n>100) { // 오류 : n의 범위가 잘못 되었을 경우
		printf("error: n is out of range\n");
		return;
	}
	while (fgets(ch, sizeof(ch), tempFile) != NULL) {
		cnt++;
	}
	if (n != cnt - 1) { // 오류 : n과 트랜잭션 레코드 수가 다를 경우
		printf("error: n and number of transaction records are different\n");
		return;
	}
	cnt = 0;
	fclose(tempFile);

	while (cnt != n) { // 레코드 트랜잭션 수 만큼 반복
		cnt++;
		getNextTrans();
		switch (trans.code) { // 갱신 코드 I: 삽입, C: 수정, D: 삭제
		case 'I':
			i = 0;
			while (i != index - 1) {
				if (i == index - 1) break;
				if (!strcmp(result[i].sNum, trans.sNum)) { // 동일한 학번의 레코드가 존재하는 경우 검사
					printf("%d번째 트랜잭션(삽입) 실행 실패[중복된 키 값의 레코드]\n", cnt);
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
				printf("%d번째 트랜잭션(수정) 실행 실패[누락된 키 값의 레코드]\n", cnt);
				break;
			}
			while (i != index - 1) {
				if (!strcmp(result[i].sNum, trans.sNum)) { //동일한 학번의 레코드가 존재하는 경우 검사
					flag = true;
					break;
				}
				i++;
			}
			if (flag) { // 동일한 학번의 레코드가 존재하면 값을 변경함
				result[i] = trans;
			}
			else {
				printf("%d번째 트랜잭션(수정) 실행 실패[누락된 키 값의 레코드]\n", cnt);
			}
			break;
		case 'D':
			i = 0;
			flag = false;
			if (!index) {
				printf("%d번째 트랜잭션(삭제) 실행 실패[누락된 키 값의 레코드]\n", cnt);
				break;
			}
			while (i != index - 1) {
				if (!strcmp(result[i].sNum, trans.sNum)) { //동일한 학번의 레코드가 존재하는 경우
					flag = true;
					break;
				}
				i++;
			}
			if (flag) { // 동일한 학번의 레코드가 존재하면 삭제한다.
				memset(&result[i], 0, sizeof(Record));
			}
			else {
				printf("%d번째 트랜잭션(삭제) 실행 실패[누락된 키 값의 레코드]\n", cnt);
			}
			break;
		}
	}
	for (int i = 0; i < n; i++) { // result 구조체 배열에 있는 임시 저장된 값들을 버블정렬한다.
		for (int j = i; j < n; j++) {
			if (atoi(result[i].sNum) > atoi(result[j].sNum)) {
				swap(&result[i], &result[j]);
			}
		}
	}

	i = 0;
	while (i != n) { // index 수만큼 new_masterFile에 출력한다.
		if (strcmp(result[i].sNum, ""))
			fprintf(new_masterFile, "%s %s %s %s %s\n", result[i].sNum, result[i].name, result[i].major, result[i].grade, result[i].pNum);
		i++;
	}

	fclose(transactionFile);
	fclose(new_masterFile);
}

void getNextTrans() { // 다음 트랜잭션 파일을 불러옴
	int i = 0;
	fgets(tBuff, sizeof(tBuff), transactionFile);
	while (tBuff[i] != '\0') {
		if (tBuff[i] == ',') { //','문자가 나오면 공백으로 변경해준다.
			tBuff[i] = ' ';
		}
		i++;
	}
	sscanf(tBuff, "%c %s %s %s %s %s", &trans.code, trans.sNum, trans.name, trans.major, trans.grade, trans.pNum);
	
	if (tBuff[0] == 'I') // 입력 명령일 경우 result 구조체 배열에 저장한다.
		result[index++] = trans;
}

void swap(Record *first, Record *second){ // 두 개의 구조체 배열을 교환하는 함수
	Record temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
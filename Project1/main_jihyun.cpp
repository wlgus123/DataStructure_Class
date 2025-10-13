#include "Common.h"

// 구조체
typedef struct _Node
{
	string data;	// 실제 데이터
	struct _Node* link = NULL;	 // 다음 리스트 주소
} Node;


// =======================컨베이어 벨트=======================

Array <Node*> convayor;	// 가방 원형 리스트 생성
Node* head, * current, * pre;

// 노드 삽입
void insertConvayor(string findData, string insertData)
{
	Node* node;
	Node* last;	// 마지막 데이터
	// 현재 데이터가 찾던 데이터일 경우
	if (head->data == findData)
	{
		// 노드 삽입
		node = new Node;
		node->data = insertData;
		node->link = head;
		last = head;
		while (last->link != head)
			last = last->link;
		last->link = node;
		head = node;
		convayor.push_back(node);
		return;
	}

	// 현재 데이터가 찾던 데이터가 아닐 경우
	current = head;
	// 리스트 데이터 탐색
	while (current->link != head)
	{
		pre = current;
		current = current->link;
		// 현재 데이터가 찾던 데이터일 경우
		if (current->data == findData)
		{
			// 노드 삽입
			node = new Node;
			node->data = insertData;
			node->link = current;
			pre->link = node;
			convayor.push_back(node);
			return;
		}
	}

	// 데이터를 찾지 못했을 경우
	// 맨 앞에 데이터 삽입
	node = new Node;
	node->data = insertData;
	current->link = node;
	node->link = head;
	convayor.push_back(node);
}

// 노드 삭제
void deleteConvayor(string deleteData)
{
	Node* last;
	// 삭제할 데이터가 맨 앞에 있을 경우
	if (head->data == deleteData)
	{
		current = head;
		head = head->link;	// 다음 노드로 헤드 변경
		last = head;
		// 마지막 노드를 찾으면 반복 종료
		while (last->link != current)
		{
			last = last->link;
		}
		last->link = head;	// 마지막 노드의 링크와 맨 앞에 있는 노드 연결
		current->data = "None";	// 현재 노드 제거
		return;
	}

	// 삭제할 데이터가 맨 앞이 아닌 경우
	current = head;
	// 데이터 탐색
	while (current->link != head)
	{
		pre = current;
		current = current->link;
		// 현재 데이터가 삭제해야 할 데이터일 경우
		if (current->data == deleteData)
		{
			// 현재 노드의 앞 노드와 뒤 노드 연결
			pre->link = current->link;
			current->data = "None";
			return;
		}
	}
}

// 현재 컨베이어 벨트 출력
void printConvayor(Node* start)
{
	// 출력 횟수 카운트
	int printCnt = 1;

	if (start == NULL)
		return;
	Node* current = start;

	print(current->data);	// 첫 번째 데이터 출력
	while (current->link != start)
	{
		// 5칸마다 들여쓰기 하기
		if (printCnt % 5 == 0)
			println("");

		current = current->link;	// 현재 노드를 다음 노드로 변경
		print(current->data);	// 노드 출력

		++printCnt;	// 출력 횟수 증가
	}
}

// 노드 할당 해제
void freeConvayor()
{
	for (int i = 0; i < len(convayor); i++)
	{
		delete convayor[i];
	}
}
// ==========================================================


// =====================인벤토리 주머니=======================

// 스택 선언 (비어있는 10개)
const int INVEN_SIZE = 10;
Array<string> Inventory;
int top = -1;

// 스택이 꽉 찼는지 확인하는 함수
bool isStackFull()
{
	// 탑과 스택 크기가 같을 경우: 꽉 참
	if (top >= (INVEN_SIZE - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 스택이 비었는지 확인하는 함수
bool isStackEmpty()
{
	// 탑이 -1일 경우(데이터 없음. 초기값)
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 스택에 데이터를 삽입하는 함수
void pushInventory(string data)
{
	if (isStackFull())
	{
		println("스택이 꽉 찼습니다. ");
		return;
	}
	top++;	// 탑 위치 증가
	Inventory[top] = data;	// 제일 위에 데이터 추가
}

// 스택에서 데이터를 추출하는 함수
string popInventory()
{
	// 스택이 비었을 경우
	if (isStackEmpty())
	{
		println("스택이 비었습니다. ");
		return "None";
	}
	string data = Inventory[top];	// 맨 위 데이터 불러오기
	Inventory[top] = "None";	// 맨 위 데이터 삭제
	top--;						// 탑 줄이기
	return data;
}

// 스택에서 데이터를 확인하는 함수
string peek()
{
	// 스택이 비었을 경우
	if (isStackEmpty())
	{
		println("스택이 비었습니다. ");
		return "None";
	}
	return Inventory[top];	// 가장 위에 있는 데이터 반환
}

// ==========================================================


// ==================== 3. 전화번호부 (이중 연결리스트) ====================
typedef struct _Contact
{
	string name;
	string phone;
	struct _Contact* prev = NULL;
	struct _Contact* next = NULL;
} Contact;

Contact* headContact = NULL;
Contact* tailContact = NULL;

// 추가
void addContact(string name, string phone)
{
	Contact* node = new Contact;
	node->name = name;
	node->phone = phone;

	if (headContact == NULL)
		headContact = tailContact = node;
	else
	{
		tailContact->next = node;
		node->prev = tailContact;
		tailContact = node;
	}
}

// 삭제
void deleteContact(string name)
{
	Contact* cur = headContact;
	while (cur != NULL)
	{
		if (cur->name == name)
		{
			if (cur->prev) cur->prev->next = cur->next;
			else headContact = cur->next;
			if (cur->next) cur->next->prev = cur->prev;
			else tailContact = cur->prev;

			println(cur->name + " 삭제됨");
			delete cur;
			return;
		}
		cur = cur->next;
	}
	println(name + " 을(를) 찾을 수 없음");
}

// 출력
void printContacts()
{
	println("\n현재 전화번호부:");
	Contact* cur = headContact;
	while (cur != NULL)
	{
		println(cur->name + " : " + cur->phone);
		cur = cur->next;
	}
}

void PhoneBook()
{
	println("------ 3. 전화번호부 (이중 연결리스트) ------\n");

	// 기본 5명
	addContact("홍길동", "010-1111-1111");
	addContact("김철수", "010-2222-2222");
	addContact("이영희", "010-3333-3333");
	addContact("박민수", "010-4444-4444");
	addContact("최지훈", "010-5555-5555");
	printContacts();

	// 추가 5명
	println("\n------ 추가 (5명 추가) ------");
	addContact("지현", "010-6666-6666");
	addContact("민지", "010-7777-7777");
	addContact("도윤", "010-8888-8888");
	addContact("하준", "010-9999-9999");
	addContact("유진", "010-0000-0000");
	printContacts();

	// 삭제 3명
	println("\n------ 삭제 (3명 삭제) ------");
	deleteContact("김철수");
	deleteContact("박민수");
	deleteContact("유진");
	printContacts();
}


// -----1. 공항 짐 컨베이어벨트: 원형리스트 사용-----
void ConvayorBelt()
{
	// 초기 가방 세팅 배열 (10개)
	string bags[10] = { "가방1", "가방2", "가방3", "가방4", "가방5", "가방6", "가방7", "가방8", "가방9", "가방10" };

	// 컨베이어 초기 세팅
	Node* node = new Node;
	node->data = bags[0];
	head = node;
	node->link = head;
	for (int i = 1; i < 10; i++)
	{
		pre = node;
		node = new Node;
		node->data = bags[i];		// 초기 가방 세팅 배열값 노드에 삽입
		pre->link = node;			// 이전 노드와 현재 노드 연결
		node->link = head;			// 현재 추가한 값의 링크는 항상 처음으로
		convayor.push_back(node);	// 배열에 넣기
	}

	// -----컨베이어 벨트-----
	// 컨베이어 출력 (기본 모습)
	println("\n1. 공항 짐 컨베이어벨트(원형리스트 사용)");
	println("-------------------------------------------\n");
	printConvayor(head);
	println("\n\n-------------------------------------------");

	// -----가방 추가-----
	// 새 가방 추가
	insertConvayor("", "캐리어");
	insertConvayor("", "백팩");
	insertConvayor("", "핸드백");
	insertConvayor("", "슈트케이스");
	insertConvayor("", "미니캐리어");

	// 컨베이어 출력 (가방 추가 후)
	println("-----------------가방 추가-----------------\n");
	printConvayor(head);
	println("\n\n-------------------------------------------");

	// -----가방 삭제-----
	// 기존 가방 삭제
	deleteConvayor("가방1");
	deleteConvayor("가방2");
	deleteConvayor("가방3");
	deleteConvayor("가방4");
	deleteConvayor("가방5");
	deleteConvayor("가방6");
	deleteConvayor("가방7");
	deleteConvayor("가방8");

	// 컨베이어 출력 (가방 삭제 후)
	println("-----------------가방 삭제-----------------\n");
	printConvayor(head);
	println("\n\n-------------------------------------------");

	freeConvayor();		// 컨베이어 벨트 할당 해제
}

// -----2. 인벤토리 주머니: 스택 사용-----
void InventoryPocket()
{
	println("2. 인벤토리 주머니 (스택 사용)\n");
	println("-------------------------------------------\n");

	for (int i = 0; i < INVEN_SIZE; i++)
	{
		Inventory.push_back("None");	// 빈 값 삽입
	}

	// 아이템 추가
	for (int i = 1; i <= 8; i++)
		pushInventory("아이템" + to_string(i));
	printArray(Inventory);	// 인벤토리 출력

	// 꽉 찬 경우 테스트
	pushInventory("아이템9");
	pushInventory("아이템10");
	pushInventory("아이템11"); // 풀로 찼음 표시됨

	// 아이템 삭제
	println("\n------ 아이템 삭제 (5개 제거) ------");
	for (int i = 0; i < 5; i++)
		popInventory();
	printArray(Inventory);	// 인벤토리 출력
}

int main()
{
	// 1. 공항 짐 컨베이어벨트: 원형리스트 사용
	//ConvayorBelt();

	// 2. 인벤토리 주머니: 스택 사용
	InventoryPocket();

	return 0;
}
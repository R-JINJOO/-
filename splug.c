include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char *name, *address, *p_num;
	struct Node *Next;
}Node;

struct Node *head=NULL, *save=NULL, *current=NULL, *tail=NULL, *get=NULL;
void insert(char arr[]);
void file_manage();
int file_add();
int print_info();
int register_member();
int search_info();
int modify_info();
int delete_member();

FILE *fp;

int main()
{
	system("clear");
	int n;
	fp = fopen("스플럭 명단관리.txt","w+");

	head=(Node *)malloc(sizeof(Node));
	tail=(Node *)malloc(sizeof(Node));
	head->Next=tail;
	file_add();

	printf("           = 메뉴=            \n");
	printf("1. 모든 주소록 정보 출력\n");
	printf("2. 회원 등록\n");
	printf("3. 회원 정보 검색\n");
	printf("4. 회원 정보 수정\n");
	printf("5. 회원 삭제\n");
	printf("6. 프로그램 종료\n");
	printf("\n");
	printf("\n");
	while(1)
	{
		printf("===========================================\n");
		printf("선택할 기능을 입력하세요  : ");
		scanf("%d",&n);
		if(n==1)
			print_info();
		if(n==2)
			register_member();
		if(n==3)
			search_info();
		if(n==4)
			modify_info();
		if(n==5)
			delete_member();
		if(n==6)
		{
			printf("===========================================\n");
			printf("프로그램을 종료합니다.");
			exit(1);
		}
	}
	fclose(fp);

	return 0;
}

int file_add()
{
	char arr1[300], arr2[300], arr3[300];

	current=head->Next;
	while(get!=tail) 
	{
		if(feof(fp))
			break;
		fscanf(fp,"%s",arr1);
		fscanf(fp,"%s",arr2);
		fscanf(fp,"%s",arr3);

		insert(arr1);
		get = (Node *)malloc(sizeof(Node));
		get->name = (char *)malloc(strlen(arr1));
		strcpy(get->name,arr1);

		get->Next=current;
		save->Next=get;

		get->address = (char *)malloc(strlen(arr2));
		strcpy(get->address,arr2);
		get->p_num = (char *)malloc(strlen(arr3));
		strcpy(get->p_num,arr3);
	}
	save=head;
	current=head->Next;
	while(current->Next!=tail)
	{
		save=current;
		current=current->Next;
	}
	free(current->name);
	free(current->address);
	free(current->p_num);
	save->Next=current->Next;
}

void insert(char arr[])
{
	save=head;
	current=head->Next;
	while(current!=tail && strcmp(current->name,arr)<0)
	{
		save=current;
		current=current->Next;
	}
}

int print_info()
{
	current=head->Next;
	while(current!=tail)
	{
		printf("%s\n", current->name);
		printf("%s\n", current->address);
		printf("%s\n", current->p_num);
		current=current->Next;
	}
}

int register_member()
{
	char arr[300];

	get = (Node *)malloc(sizeof(Node));
	printf("===========================================\n");
	printf("이름 : ");
	scanf("%s",arr);
	insert(arr);
	get->name = (char *)malloc(strlen(arr));
	strcpy(get->name,arr);

	get->Next=current;
	save->Next=get;

	printf("주소 : ");
	scanf("%s",arr);
	get->address = (char *)malloc(strlen(arr));
	strcpy(get->address,arr);
	printf("전화번호 : ");
	scanf("%s",arr);
	get->p_num = (char *)malloc(strlen(arr));
	strcpy(get->p_num,arr);
	printf("\n");
	printf("추가되었습니다.\n");

	file_manage();
}

int search_info()
{
	char arr[300];
	int a=0;

	printf("===========================================\n");
	printf("찾으실 회원의 이름 또는 주소 또는 전화번호를 입력하세요 : ");
	scanf("%s",arr);
	current=head->Next;
	while(current!=tail)
	{
		if(strstr(current->name,arr) || strstr(current->address,arr) || strstr(current->p_num,arr))
		{
			printf("%s\n", current->name);
			printf("%s\n", current->address);
			printf("%s\n", current->p_num);
			a=1;
		}
		current=current->Next;
	}
	if(current==tail && a==0)
		printf("회원이 존재하지 않습니다.\n");
}

int modify_info()
{
	char arr[300];
	char arr1[300], arr2[300], arr3[300];
	char ch;

	printf("===========================================\n");
	printf("수정할 회원의 이름을 입력하세요 : ");
	scanf("%s",arr);
	current=head->Next;
	while(current!=tail)
	{
		if(strcmp(arr,current->name)==0)
		{
			get = (Node *)malloc(sizeof(Node));
			printf("이름 : ");
			scanf("%s",arr1);
			printf("주소 : ");
			scanf("%s",arr2);
			printf("전화번호 : ");
			scanf("%s",arr3);

			printf("저장하시겠습니까? ");
			ch = getchar();
			ch = getchar();

			if(ch == 'N')
			{
				printf("\n");
				printf("정보 수정이 취소되었습니다.\n");
			}
			else if(ch == 'Y')
			{
				free(current->name);
				free(current->address);
				free(current->p_num);
				save->Next=current->Next;
				insert(arr1);
				get->name = (char *)malloc(strlen(arr1));
				strcpy(get->name,arr1);

				get->Next=current;
				save->Next=get;

				get->address = (char *)malloc(strlen(arr2));
				strcpy(get->address,arr2);
				get->p_num = (char *)malloc(strlen(arr3));
				strcpy(get->p_num,arr3);
				file_manage();
				printf("\n");
				printf("정보가 수정되었습니다.\n");
			}
			break ;
		}
		current=current->Next;
	}
}

int delete_member()
{
	char arr[300];

	printf("===========================================\n");
	printf("삭제할 회원의 이름을 입력하세요 : ");
	scanf("%s",arr);
	save=head;
	current=head->Next;
	while(current!=tail)
	{
		if(strcmp(arr,current->name)==0)
		{
			free(current->name);
			free(current->address);
			free(current->p_num);
			save->Next=current->Next;
			break;
		}
		save=current;
		current=current->Next;
	}
	printf("\n");
	printf("정보가 삭제되었습니다.\n");
	file_manage();
}

void file_manage()
{
	fclose(fp);
	fp=fopen("스플럭 명단관리.txt","w");

	current=head->Next;
	while(current!=tail)
	{
		fprintf(fp,"%s",current->name);
		fprintf(fp," %s",current->address);
		fprintf(fp,"  %s\n",current->p_num);
		current=current->Next;
	}
}

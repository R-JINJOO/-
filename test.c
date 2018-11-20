#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define stralloc(x,y) x=(char *)malloc(strlen(y)+1); strcpy(x,y);

typedef struct node{
	char *id;
	char *password;
	char *name;
	char *address;
	char *phone;
	struct node *next;
}node;

void mygets(char *str){
	int i=0;

	while(1){
		str[i]=getchar();
		if(str[i]=='\n'||str[i]==EOF){
			str[i]='\0';
			break;
		}
		i++;
	}
}

int menu(){
	int select;
	printf(">>도서관 서비스<<\n1. 회원가입 2. 로그인 3. 프로그램종료\n\n번호를 선택하세요 : ");
	scanf("%d",select);
	return select;
}

struct node *insert(struct node *head_p){
	struct node *now = head_p;
	while(now->next != 0){
		now = now->next;
	}
	if(now->next==0){
		now->next = (struct node *)calloc(sizeof(struct node),1);
	}
	return now->next;
}

void change_to_node(struct node *haed_p){
	struct node *now;
	now->next=head_p;
	while(now->next==NULL){
		fscanf





void sign_up(struct node *head_p){
	struct node *client_p;
	client_p->next=insert(head_p);
	char tmp_id[10];
	char tmp_password[20];
	char tmp_name[20];
	char tmp_address[30];
	char tmp_phone[20];
	char check[20];
	FILE *client_fp;
	client_fp=fopen("client.txt","a");
	if(client_fp==NULL)
		printf("오류 : 파일을 열 수 없습니다");


	printf(">>회원 가입<<\n학번, 비밀번호, 이름, 주소, 전화번호를 입력하세요.\n");
	printf("학번 : ");
	scanf("%s",tmp_id);

	printf("비밀번호 : ");
	scanf("%s", tmp_password);
	printf("이름 : ");
	scanf("%s", tmp_name);
	printf("주소 : ");
	getchar();
	mygets(tmp_address);
	printf("전화번호 : ");
	scanf("%s",tmp_phone);
	stralloc(client_p->next->id,tmp_id);
	stralloc(client_p->next->password,tmp_password);
	stralloc(client_p->next->name,tmp_name);
	stralloc(client_p->next->address,tmp_address);
	stralloc(client_p->next->phone,tmp_phone);

	printf("회원가입이 되셨습니다");
	fprintf(client_fp,"%s | %s | %s | %s | %s\n",client_p->next->id,client_p->next->password,client_p->next->name,client_p->next->address,client_p->next->phone);
	fclose(client_fp);
}




int main(){
	struct node client;
	struct node* head = &client;
	sign_up(&client);
	return 0;
}

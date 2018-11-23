#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define stralloc(x,y) x=(char *)malloc(strlen(y)+1); strcpy(x,y);

typedef struct node{
	char id[15];
	char password[20];
	char name[10];
	char address[40];
	char phone[15];
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
	struct node *now = head_p; //이건 또 뭐야
	while(now->next != 0){ //파일 끝이 아닐 떄까지
		now = now->next; //이건 왜 있는거야?
	}
	if(now->next==0){
		now->next = (struct node *)calloc(sizeof(struct node),1); //이건 왜해주는거야
	}
	return now->next;
}

int data_count(){
	int count=0;
	char str[200];
	FILE *client_fp;
	client_fp=fopen("client.txt","r");
	while(1){
		if(fscanf(client_fp,"%[^\n]\n",str)!=EOF)
			count++;
		else
			break;
	}
	fclose(client_fp);
	return count;
}



void text_to_node_client(struct node *client_p){
	struct node *new=client_p;
	FILE *client_fp;
	int check;
	client_fp=fopen("client.txt","r");
	if(client_fp==NULL)
		printf("오류 : 파일을 열 수 없습니다");
	while(1){
		check = fscanf(client_fp,"%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]", new->id, new->password, new->name, new->address, new->phone);
		if(check!=5){
			new=client_p;
			while(new->next->next!=NULL){
				new=new->next;
			}
			free(new->next);
			new->next=NULL;
			break;
		}
		else{
			new->next=insert(client_p);
			new=new->next;
		}
	}

	fclose(client_fp);
}



void client_list(struct node *client_p){ //이거랑 texttonode랑 다른게 뭐야?
	struct node *now=client_p;
	FILE *client_fp;
	client_fp=fopen("client.txt","r");
	if(client_fp==NULL)
		printf("오류 : 파일을 열 수 없습니다.");
	while(1){
		printf("%s|%s|%s|%s|%s", now->id, now->password, now->name, now->address, now->phone);
   if(now->next==NULL)
	   break;
   else
	   now=now->next;
	}
	fclose(client_fp);
}


void sign_up(struct node *client_p){
	struct node *nb;
	nb=insert(client_p);
	FILE *client_fp;
	client_fp=fopen("client.txt","a");
	if(client_fp==NULL)
		printf("오류 : 파일을 열 수 없습니다");

	printf(">>회원 가입<<\n학번, 비밀번호, 이름, 주소, 전화번호를 입력하세요.\n");
	printf("학번 : ");
	scanf("%s", nb->id);
	printf("비밀번호 : ");
	scanf("%s", nb->password);
	printf("이름 : ");
	scanf("%s", nb->name);
	printf("주소 : ");
	getchar();
	mygets(nb->address);
	printf("전화번호 : ");
	scanf("%s",nb->phone);

	printf("회원가입이 되셨습니다\n");
	fprintf(client_fp,"%s|%s|%s|%s|%s",nb->id, nb->password, nb->name, nb->address, nb->phone);
	fclose(client_fp);
}




int main(){
	struct node client;
	struct node* head = &client;
	text_to_node_client(&client);
	sign_up(&client);
	client_list(&client);
	return 0;
}

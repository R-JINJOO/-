#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char id[20];
	char password[20];
	char name[10];
	char address[200];
	char phone[15];
	struct node *next;
}node;	//node 구조체

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
}	// \n 전까지 문자열을 입력 받는 mygets함수

int menu(){
	int select;
	printf(">>도서관 서비스<<\n1. 회원가입 2. 로그인 3. 프로그램종료\n\n번호를 선택하세요 : ");
	scanf("%d",select);
	return select;
}	// 1번째 메뉴 출력

struct node *insert(struct node *head_p){
	struct node *now = head_p;
	while(now->next != 0){
		now = now->next;
	}
	if(now->next==0){
		now->next = (struct node *)calloc(sizeof(struct node),1);
	}
	now->next->next=NULL;
	return now->next;
}	// node의 첫번째 주소를 받아 node(now)->next가 NULL을 가리키지 않을 때 다음 노드로 이동, node(now)->next가NULL을 가리키면 node(now)->next에 새로운 노드를 할당하고 그 노드의 next가NULL을 가리키도록 함


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
}	// client.txt에 있는 데이터의 개수를 세서 리턴해주는 함수



void text_to_node_client(struct node *client_p){
	struct node *new=client_p;
	FILE *client_fp;
	int check=1;
	client_fp=fopen("client.txt","r");
	if(client_fp==NULL)
		printf("오류 : 파일을 열 수 없습니다");

	//	fseek(client_fp, 3, SEEK_SET);
	while(1){
		check = fscanf(client_fp,"%s | %s | %s | %[^|] | %s", new->id, new->password, new->name, new->address, new->phone);
		if(check!=5){
			break;
		}
		else{
			new->next=insert(client_p);
			new=new->next;
		}
	}
	new=client_p;
	while(new->next->next!=NULL){
		new=new->next;
	}
	free(new->next);
	new->next=NULL;
	fclose(client_fp);
}	//



void client_list(struct node *client_p){
	struct node *now=client_p;
	FILE *client_fp;
	client_fp=fopen("client.txt","r");
	if(client_fp==NULL)
		printf("오류 : 파일을 열 수 없습니다.");
	while(1){
		printf("%s | %s | %s | %s | %s\n", now->id, now->password, now->name, now->address, now->phone);
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
	fprintf(client_fp,"%s | %s | %s | %s | %s\n",nb->id, nb->password, nb->name, nb->address, nb->phone);
	fclose(client_fp);
}


char* log_in(struct node *head_p){
	struct node account;
	struct node *cur;
	cur = head_p;
	char tmp_id[20];
	char tmp_password[20];

	printf(">>로그인<<\n");
	printf("학번 : ");
	scanf("%s", tmp_id);
	printf("비밀번호 : ");
	scanf("%s", tmp_password);

	if((strcmp(tmp_id,"admin")==0)&&(strcmp(tmp_password,"lib_admin7")==0))
		return "admin ";

	else{
		while(1){
			cur = cur->next;
			if(strcmp(cur->id,tmp_id)&&!strcmp(cur->password,tmp_password)){
				return cur->id;
			}
			if(cur->next==NULL){
				printf("아이디와 비밀번호를 확인해주세요\n");
				cur=head_p;
				break;
			}
		}
	}
	return 0;
}

int main(){
	int log_in_output;
	struct node client;
	struct node* head = &client;
	text_to_node_client(&client);
	sign_up(&client);
	client_list(&client);
	log_in_output = log_in(head);
	printf("%d",log_in_output);
	return 0;
}

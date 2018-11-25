#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

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

/*int menu(){
	int select;
	printf(">>도서관 서비스<<\n1. 회원가입 2. 로그인 3. 프로그램종료\n\n번호를 선택하세요 : ");
	scanf("%d",select);
	return select;
}	// 1번째 메뉴 출력
*/

struct book *insert2(struct book *head_p){
	struct book *now = head_p;
	while(now->next != 0){
		now = now->next;
	}
	if(now->next==0){
		now->next = (struct book *)calloc(sizeof(struct book),1);
	}
	now->next->next=NULL;
	return now->next;
}	// node의 첫번째 주소를 받아 node(now)->next가 NULL을 가리키지 않을 때 다음 노드로 이동, node(now)->next가NULL을 가리키면 node(now)->next에 새로운 노드를 할당하고 그 노드의 next가NULL을 가리키도록 함

int data_count(){
	int count=0;
	char str[200];
	FILE *book_fp;
	book_fp=fopen("book.txt","r");
	while(1){
		if(fscanf(book_fp,"%[^\n]\n",str)!=EOF)
			count++;
		else
			break;
	}
	fclose(book_fp);
	return count;
}	// client.txt에 있는 데이터의 개수를 세서 리턴해주는 함수



void text_to_node_book(struct book *book_p){
	struct book *new=book_p;
	FILE *book_fp;
	int check=1;
	book_fp=fopen("book.txt","r");
	if(book_fp==NULL)
		printf("오류 : 파일을 열 수 없습니다");

	//	fseek(client_fp, 3, SEEK_SET);
	while(1){
		check = fscanf(book_fp,"%s | %[^|] | %[^|] | %[^|] | %s | %[^|] | %s", 
				new->booknum, new->bookname, new->publisher, 
				new->writer, new->ISBN, new->place, new->YorN);
		if(check!=7){
			break;
		}
		else{
			new->next=insert2(book_p);
			new=new->next;
		}
	}
	new=book_p;
	while(new->next->next!=NULL){
		new=new->next;
	}
	free(new->next);
	new->next=NULL;
	fclose(book_fp);
}	//



void book_list(struct book *book_p){
	struct book *now=book_p;
	FILE *book_fp;
	book_fp=fopen("book.txt","r");
	if(book_fp==NULL)
		printf("오류 : 파일을 열 수 없습니다.");
	while(1){
		printf("%s | %s | %s | %s | %s | %s | %s\n", 
				now->booknum, now->bookname, now->publisher, 
				now->writer, now->ISBN, now->place, now->YorN);
		if(now->next==NULL)
			break;
		else
			now=now->next;
	}
	fclose(book_fp);
}


void add_book(struct book *book_p){
	struct book *nbk;
	nbk=insert2(book_p);
	FILE *book_fp;
	book_fp=fopen("book.txt","a");
	if(book_fp==NULL)
		printf("오류 : 파일을 열 수 없습니다");

	printf(">>도서 등록<<\n도서명, 출판사, 저자명, ISBN, 소장처를 입력하세요.\n");
	printf("도서명 : ");
	getchar();
	mygets(nbk->bookname);
	printf("출판사 : ");
	getchar();
	mygets(nbk->publisher);
	printf("저자명 : ");
	getchar();
	mygets(nbk->writer);
	printf("ISBN : ");
	scanf("%s", nbk->ISBN);
	printf("소장처 : ");
	getchar();
	mygets(nbk->place);

	printf("도서 등록이 되셨습니다\n");
	fprintf(book_fp,"%s | %s | %s | %s | %s\n",
			nbk->bookname, nbk->publisher, nbk->writer, 
			nbk->ISBN, nbk->place);
	fclose(book_fp);
	//도서 대여가능 여부 Y로, 도서번호 마지막 등록된 도서의 도서번호+1로
}

int main(){
	struct book bookh;
	struct book* head = &bookh;
	text_to_node_book(head);
	add_book(head);
	book_list(head);
	return 0;
}

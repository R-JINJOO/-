#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
#define stralloc(x,y) x=(char *)malloc(strlen(y)+1); strcpy(x,y);

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

void text_to_node_client(struct node *client_p){
   node *new=client_p;
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

void client_list(struct node *client_p){ //이거랑 text_to_node랑 다른게 뭐야?
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


int IntInput(int max){
   int num;
   while(1){
	  scanf("%d",&num);
	  if(num>0||num<=max){ //이게 왜 && 가아닌지도 모르겠고
		 return num;
	  }
	  else{
		 printf("번호를 잘못입력하셨습니다.\n");
	  }
   }
}


void text_to_node_book(Book *head_p){         //책의 텍스트 파일을 구조체로 저장하는 함수
   FILE *book_fp;
   int check;
   Book *now=head_p; //head_p가 뭐야
   Book *new=head_p;
   book_fp=fopen("book.txt","r+");
   if(book_fp==NULL){
	  printf("오류 : 파일을 열 수 없습니다.\n");
   }
   else{
	  while(1){
		 check=fscanf(book_fp,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c",now->booknum,now->bookname,now->publisher,now->writer,now->ISBN,now->place,&now->YorN); //뭔 소리야 이거
		 if(check==EOF){
			break;
		 }
		 else{
			now->next=(Book *)malloc(sizeof(Book)); //이건 왜 필요해 또
			now=now->next;
			now->next=NULL;
		 }
	  }

	  while(new->next->next!=NULL){       //삭제중.
		 new=new->next;              //삭제중..
	  }
	  new->next=NULL;                     //삭제중...
	  free(now);                          //삭제끝
   // now=NULL;
   }
   return;
}

void client_menu(char *ID,Book *book_hp,node *client_hp){
   int n;
   struct node tmp; 
   if(book_hp->next==NULL)
	  printf("C END\n");

   while(1)
   {
	  printf("1번 5번 6번만 됨\n");
	  printf(">> 회원 메뉴 <<\n");
	  printf("1. 도서 검색\t\t2. 내 대여 목록\n");
	  printf("3. 개인정보 수정\t4. 회원 탈퇴\n");
	  printf("5. 로그아웃\t\t6. 프로그램 종료\n");
	  printf("\n"); printf("\n");
	  printf("번호를 선택하세요 : ");
	  n=IntInput(6);				//18행 참고
	  if(n==1)
		 find_book(book_hp);
	  /*	   else if(n==2)
			   my_borrow_list(ID,book_hp);
			   else if(n==3)
			   client_information_modification(ID,client_hp);
			   else if(n==4)
			   membership_quit(ID,client_hp);*/
	  //else if(n==3){
	  //	 while(client_hp->next != NULL) //내가 로그인한 학번을 기억하고 그 걸 비교하여 찾은 후 수정아 잠만 이게 필요한가? 걍 1로 하면 되는건가?
	  //	 {
	  //		if(strcmp(client_hp->id, /*여기에 내 학번*/) == 0)
	  //		{
	  //		   printf("새 비밀번호 : \n");
	  //		   scanf("%s", client_hp->password); //이거 client_p야 아님 nb? 이거와 97, 99 행
	  //		   printf("새 조소 : \n");
	  //		   getchar();
	  //		   mygets(client_hp->address);
	  //		   printf("새 전화번호 : \n");
	  //		   scanf("%s", client_hp->phone);
	  //		}
	  //		else
	  //		   return //이게 맞나? 난 아니면 그냥 넘어가고 싶은데 break야 아님 이거?
	  //	 }
	  //	 printf("수정되었습니다.\n");
	  //}
	  else if(n==4){
		 membership_quit(ID, client_hp);
	  }
	  else if(n==5){
		 printf("\n로그아웃\n");
		 return;
	  }
	  else if(n==6) {
		 printf("프로그램을 종료합니다,");
		 exit(1);
	  }
   }
   return;
}

void membership_quit(ID,client_hp)
{
   FILE *client_fp;
   node *now=client_hp;
   node *before_now=client_hp;
   client_fp=fopen("client.txt", "r+");
   if(client_fp==NULL)
	  printf("오류 : 파일을 열 수 없습니다.\n");
   else{
	  while(now->next!=NULL)
	  {
		 if(strcmp(now->id, ID)!=0)
		 {
			now=now->next;
		 }
		 else
		 {
			while(before_now->next != now)
			{
			   before_now=before_now->next;
			}
			before_now->next=now->next; //이게 삭제할 거 전 거를 삭제할 거 다음거를 가리키게 하는거
			free(now);
			now=NULL;
		 }
	  }
	  fclose(client_fp);
	  printf("탈퇴되었습니다.");
   }
}

void find_book(Book *book_hp)
{
   int a;
   char s[100];

   while(1){
	  printf("1번 5번 6번만 됨\n");
	  printf("\n>> 도서 검색 <<\n");
	  printf("1. 도서명 검색\t2. 출판사 검색\n");
	  printf("3. ISBN 검색\t4. 저자명 검색\n");
	  printf("5. 전체 검색\t6. 이전 메뉴\n");
	  printf("\n");
	  printf("\n");
	  printf("번호를 선택하세요 : ");
	  a=IntInput(6);				//18행 참고
	  switch(a){
		 case 1:
			bookname_search(book_hp);
			break;/*
					 case 2:
					 publisher_search(book_hp);
					 break;
					 case 3:
					 ISBN_search(book_hp);
					 break;
					 case 4:
					 writer_search(book_hp);
					 break;*/
		 case 5:
			search_all(book_hp);
			break;
		 case 6:
			return;
		 default:
			break;
	  }
   }
}

void bookname_search(Book *book_hp){				//검색메뉴1 제목검색 함수
   char name[50];																		//중복책 검사 해야함
   printf("도서명을 입력하세요 : ");//출력화면도 바꿔야함
   getchar();
   mygets(name);
   while(book_hp->next!=NULL){
	  if(strstr(book_hp->bookname,name)!=NULL){
		 printf("%s|%s|%s|%s|%s|%s|%c\n",book_hp->booknum,book_hp->bookname,book_hp->publisher,book_hp->writer,book_hp->ISBN,book_hp->place,book_hp->YorN);
	  }
	  else;
	  book_hp=book_hp->next;
   }
   return;
}



void search_all(Book *book_hp){				//검색메뉴5 전체검색 함수
   while(book_hp->next!=NULL){
	  printf("%s|%s|%s|%s|%s|%s|%c\n",book_hp->booknum,book_hp->bookname,book_hp->publisher,book_hp->writer,book_hp->ISBN,book_hp->place,book_hp->YorN);
	  book_hp=book_hp->next;
   }
}

int main(){
   Book *book_hp=(Book *)malloc(sizeof(Book));
   node *client_hp;
   FILE *book_ifp=fopen("book.txt","r+"),*client_ifp=fopen("client.txt","r+");
   text_to_node_book(book_hp);

   //client노드 생성해야함
   client_menu("ID",book_hp,client_hp);
   return 0;
}

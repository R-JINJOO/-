#include<stdio.h>
#include<stdlib.h>
typedef struct book{
   char booknum[100];
   char bookname[100];
   char publisher[100];
   char writer[100];
   char ISBN[1000];
   char place[100];
   char YorN;
   struct book *next;
}Book;

Book* EndNode(Book *head_p){
   Book *now=head_p;
   while(now->next!=NULL){
	  now=now->next;
   }
   return now;
}

Book* AllocNode(){
   Book *now=(Book *)malloc(sizeof(Book));
   return now;
}

void AddNode(Book *a){
   a->next=(Book *)malloc(sizeof(Book));
}

void text_to_node_book(Book *head_p){
   FILE *book_fp;
   int check;
   Book *now=head_p;
   book_fp=fopen("book.txt","r");
   if(book_fp==NULL){
	  printf("오류 : 파일을 열 수 없습니다.\n");
   }
   else{
	  while(1){
		 check=fscanf(book_fp,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c",now->booknum,now->bookname,now->publisher,now->writer,now->ISBN,now->place,&now->YorN);
		 printf("%s|%s|%s|%s|%s|%s|%c",now->booknum,now->bookname,now->publisher,now->writer,now->ISBN,now->place,now->YorN);
		 if(check==EOF){
			printf("EOF?\n");
			break;
		 }
		 else{
			now->next=(Book *)malloc(sizeof(Book));
			now=now->next;
		 }
	  }
   }
   return;
}

int main(){
   Book *head_p=(Book *)malloc(sizeof(Book));
   text_to_node_book(head_p);
   while(head_p->next!=NULL){
	  printf("%s|%s|%s|%s|%s|%s|%c",head_p->booknum,head_p->bookname,head_p->publisher,head_p->writer);
	  head_p=head_p->next;
   }
   return 0;
}


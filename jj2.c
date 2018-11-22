#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
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

int IntInput(int max){
								int num;
								while(1){
																scanf("%d",&num);
																if(num>0||num<=max){
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
        Book *now=head_p;
        Book *new=head_p;
        book_fp=fopen("book.txt","r");
        if(book_fp==NULL){
                printf("오류 : 파일을 열 수 없습니다.\n");
        }
        else{
                while(1){
                        check=fscanf(book_fp,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c",now->booknum,now->bookname,now->publisher,now->writer,now->ISBN,now->place,&now->YorN);
                        if(check==EOF){
                                break;
                        }
                        else{
                                now->next=(Book *)malloc(sizeof(Book));
                                now=now->next;
                                now->next=NULL;
                        }
                }

                while(new->next->next!=NULL){       //삭제중.
                        new=new->next;              //삭제중..
                }
                new->next=NULL;                     //삭제중...
                free(now);                          //삭제끝
        }
        return;
}

void client_menu(char *ID,Book *book_hp,node *client_hp){
	int n;
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
								 else	if(n==5){
																	printf("\n로그아웃\n");
																	return;
									}
									else if(n==6) {
																printf("프로그램을 종료합니다,");
																exit(1);
	  					 }
									else;
	}
	return;
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

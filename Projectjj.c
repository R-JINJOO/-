#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int client_menu()
{
	system("clear");
	int n;

	printf(">> 회원 메뉴 <<\n");
	printf("1. 도서 검색\t2. 내 대여 목록\n");
	printf("3. 개인정보 수정\t4. 회원 탈퇴\n");
	printf("5. 로그아웃\t6. 프로그램 종료\n");
	printf("\n");
	printf("\n");
	printf("번호를 선택하세요 : ");

	while(1)
	{
	   scanf("%d", &n);
	   if(n==1)
		  find_book();
	   if(n==2)
		  my_borrow_list();
	   if(n==3)
		  client_imformation_modification();
	   if(n==4)
		  membership_quit();
	   if(n==5)
		  client_logout();
	   if(n==6)
	   {
		  printf("프로그램을 종료합니다,");
		  exit(1);
	   }
	   if(n!=1 || n!=2 || n!=3 || n!=4 || n!=5 || n!=6)
		  printf("번호를 잘못 입력하셨습니다.");
	}
	return 0;
}

/*int find_book()
{
   system("clear");
   int a;
   char s[100];

   printf(">> 도서 검색 <<\n");
   printf("1. 도서명 검색\t2. 출판사 검색\n");
   printf("3. ISBN 검색\t4. 저자명 검색\n");
   printf("5. 전체 검색\t6. 이전 메뉴\n");
   printf("\n");
   printf("\n");
   printf("번호를 선택하세요 : ");
   while(1)
   {
	  scanf("%d", &a);
	  if(a==1)
	  {
		 printf("도서명을 입력하세요 : ");
		 gets(s);
		 for(int i=0; i<100 ;i++) //이거 근데 책 권수 바뀌면 100 바뀌니까 define으로 바꿔야 할 텐데
		 {
			if(strstr(Book->bookname))
			{
				 printf(">> 검색 결과 <<\n");
				 printf("도서명 : %s\n", Book->bookname);
				 printf("출판사 : %s\n", Book->publisher);
				 printf("저자명 : %s\n", Book->writer);
				 printf("ISBN : %s\n", Book->ISBN);
				 printf("소장처 : %s\n", Book->place);
				 printf("대여가능 여부 : %s\n", Book->YorN); //이거 중복도서는 (2/2)이거 필요하던데
			}
		 }
	  if(a==2)
*/

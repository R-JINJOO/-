typedef struct book{
								char booknum[15];
								char bookname[100];
								char publisher[100];
								char writer[100];
								char ISBN[14];
								char place[100];
								char YorN;
								struct book *next;
}Book;

typedef struct node{
								char id[15];
								char password[20];
								char name[10];
								char address[40];
								char phone[15];
								struct node *next;
}node;


void mygets(char *);
int menu();
struct node *insert(struct node*);
void text_to_node_client(node *);			//텍스트 파일을 구조체로 변환
void client_list(node *);				//학생 리스트  출력
void sign_up(node *);				//회원가입
								
//***************************회원*************************************************//

void client_menu(char *ID,Book *,node *);				//회원 메뉴
void find_book(Book *);				//도서 검색
//도서 검색 서브 메뉴 6개
void bookname_search(Book *);				//도서명 검색
void publisher_search(Book *);				//출판사 검색
void ISBN_search(Book *);				//ISBN 검색
void writer_search(Book *);				//저자명 검색
void search_all(Book *);				//전체 검색
//도서 검색 서브 메뉴 끝
void my_borrow_list(char *,Book *);//첫번쨰 인자는 학번 		//내 대여 목록
void client_information_modification(char *ID,node *);//첫번째 인자는 학번 	//개인 정보 수정
void membership_quit(char *ID,node *);				//회원 탈퇴
void client_logout();

//****************************회원**********************************************//


int strinput(char *str,int num){					//제대로 입력받으면 1return 넘어가면 0return
								char c;
								int i=0;
								while(c=getchar()!='\n'){
																str[i]=c;
																i++;
																if(i==num){
																								return 1;
																}
								}
								str[i]='\0';
								return 0;
}

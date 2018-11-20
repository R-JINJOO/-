#include<stdio.h>
struct node{
	char id[20];
	char password[20];
	char name[20];
	char address[50];
	char phone[10];
};


int main(){
	FILE *client_fp;
	struct node client1,client2;
	client_fp = fopen("client.txt","r");
	fscanf(client_fp,"%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", client1.id, client1.password, client1.name, client1.address, client1.phone);
	int pos=ftell(client_fp);
	//getc(client_fp);
	fscanf(client_fp,"%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", client2.id, client2.password, client2.name, client2.address, client2.phone);
	printf("%s|%s|%s|%s|%s\n", client1.id, client1.password, client1.name, client1.address, client1.phone);
	printf("%s|%s|%s|%s|%s\n", client2.id, client2.password, client2.name, client2.address, client2.phone);
	return 0;
}

#include"stdio.h"
#include"string.h"
#define maxlength 100

int checka(int);
int phi[12]={1,3,5,7,9,11,15,17,19,21,23,25};
int phi_[12]={1,9,21,15,3,19,7,23,11,5,17,25};
int main()
{	//lay thong tin co ban
	int a=-1,b=-1;
	char input[maxlength],output[maxlength];
	printf("Input:");
	fgets(input,sizeof(input),stdin);
	while(!checka(a)||b<0||b>26)
	{
	printf("Nhap 2 khoa (a b)=");
	scanf("%d",&a);
	scanf("%d",&b);}
	//viet hoa tat ca ky tu
	for(int i=0;i<strlen(input);i++)
		if(input[i]<=122&input[i]>=97) input[i]-=32;
	
	//thuc hien thuat toan
	int count=0;
	for(int i=0;i<strlen(input)-1;i++)
	{
	output[count++]=((input[i]-65)*a+b)%26+65;
	
	
	}
	//kiem tra output
	printf("Output:");
	for(int i=0;i<strlen(output);i++)
	printf("%c",output[i]);
	
}
//tra lai 1 neu dung 0 neu sai
int checka(int a)
{
for(int i=0;i<12;i++) if(a==phi[i]) return 1;
return 0; 	
}
#include"stdio.h"
#include"string.h"
#define maxlength 100

int checka(int);
void run(int a, int b, char* input,char* output);

int phi[12]={1,3,5,7,9,11,15,17,19,21,23,25};
int phi_[12]={1,9,21,15,3,19,7,23,11,5,17,25};
int main()
{	//lay thong tin co ban
	int a=-1,b=-1,base;
	char input[maxlength],output[maxlength];
	printf("Input:");
	fgets(input,sizeof(input),stdin);
	//viet hoa tat ca ky tu
	for(int i=0;i<strlen(input);i++)
		if(input[i]<=122&input[i]>=97) input[i]-=32;
	printf("Neu co key thi chon 1\n");
	printf("Neu khong co key thi chon 0\n");
	scanf("%d",&base);
	switch(base){
	case 0:
	{
	for(int i=0;i<12;i++)	
		for(int j=0;j<26;j++)
		{
			run(phi_[i],j,&input[0],&output[0]);
			printf("Output:");
			for(int i=0;i<strlen(output);i++)
			printf("%c",output[i]);
			
			printf("             Key(a,b)=(%d,%d)\n",phi[i],j);
			
		}
	}
	break;
	case 1: 
	{
	while(!checka(a)||b<0||b>26)
	{
	printf("Nhap 2 khoa (a b) ");
	scanf("%d",&a);
	scanf("%d",&b);}
	int i1;
	for(int i=0;i<12;i++)
	{
		if(phi[i]==a) {
			i1=i;
			break;
		}
	}
	a=phi_[i1];
	
	run(a,b,&input[0],&output[0]);
	//kiem tra output
	printf("Output:");
	for(int i=0;i<strlen(output);i++)
	printf("%c",output[i]);
	}
	break;
	default: printf("ERROR");
	}
	
	
}


//thuc hien thuat toan
void run(int a, int b, char* input,char* output)
{
	
	int count=0,i=0,chuanhoa;
	
	do{
	chuanhoa=(a*((*input-65)-b))%26;
	if(chuanhoa<0) chuanhoa+=26;
	output[count++]=chuanhoa+65;
	input++;
	  }while(*input!='\0');
	  
	output[--count]='\0';
}
//tra lai 1 neu dung 0 neu sai
int checka(int a)
{
for(int i=0;i<12;i++) if(a==phi[i]) return 1;
return 0; 	
}



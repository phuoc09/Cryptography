#include"stdio.h"
#include"string.h"
#include"conio.h"

#define maxlength 100
int check(char* matrix,char cha);
int main()
{
	int i,k=0;
	char key[maxlength],input[maxlength],output[2*maxlength];
	printf("Input:");
	fgets(input,sizeof(input),stdin);
	
	printf("\nKey:");
	fgets(key,sizeof(key),stdin);
// CHUYEN TAT CA CHU THANH CHU HOA
	for(i=0;i<strlen(key);i++)
		if(key[i]<=122&key[i]>=97) key[i]-=32;
	for(i=0;i<strlen(input);i++)
		if(input[i]<=122&input[i]>=97) input[i]-=32;	
// CHUYEN TAT CA CHU J THANH I
	for(i=0;i<strlen(key);i++)
	if(key[i]==74) key[i]=73;
//in thu de test
  
	
int count=0;	
// lap ma tran
	char matrix[5][5];
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++) 
		{	
			if(count<strlen(key)-1)
		
			{	
			while(check(&matrix[0][0],key[count])) 
			 count++;							
				if(count<strlen(key)-1){				
				matrix[i][j]=key[count++];
				continue;}
				
			}
		   
		k=65;			
		while (k>=65&k<=90)
		{
				
			while(check(&matrix[0][0],k)) 
			 {k++;	
			 if (k==74) k++;
			 }							
			matrix[i][j]=k;
			break;	}		
		}	

			
	
// ma hoa 2 ky tu	
	int xi1,xi2,yi1,yi2;
	int x1,x2,y1,y2;
	int count_out=0, length_input=strlen(input);
	if	(length_input%2==0) 
	{
	input[length_input-1]=input[length_input-2];
	input[length_input]='\0';}
	
for(int i=0;i<strlen(input)/2;i++){
		for(x1=0;x1<5;x1++)
		for(y1=0;y1<5;y1++)
		{ 
		if(matrix[x1][y1]==input[i*2]) {
			xi1=x1;
			yi1=y1;
		}
		}
	for(x2=0;x2<5;x2++)
		for(y2=0;y2<5;y2++)
		{ 
		if(matrix[x2][y2]==input[i*2+1]) {
			xi2=x2;
			yi2=y2;
		}
		}
	if (matrix[xi2][yi2]=='X') 
	{
		output[count_out++]=matrix[xi1][yi1];
		output[count_out++]=matrix[xi1][yi1];
		continue;
	}
	if (xi1==xi2&yi1!=yi2) 
	{   if(yi1==0) yi1=yi1+5;
		if(yi2==0) yi2=yi2+5;
		output[count_out++]=matrix[xi1][yi1-1];
		output[count_out++]=matrix[xi2][yi2-1];
	}
	if (xi1!=xi2&yi1==yi2) 
	{   if(xi1==0) xi1=xi1+5;
		if(xi2==0) xi2=xi2+5;
		output[count_out++]=matrix[xi1-1][yi1];
		output[count_out++]=matrix[xi2-1][yi2];
	}
	if (xi1!=xi2&yi1!=yi2) 
	{   
		output[count_out++]=matrix[xi1][yi2];
		output[count_out++]=matrix[xi2][yi1];
	}
	
};
 
 
	

//kiem tra matrix	

    printf("\nMa tran ma hoa:\n");
	for (int i=0;i<5;i++)
		{
		printf("\n");for (int j=0;j<5;j++) 
	  {
			printf("%c ",matrix[i][j]);
		}
	}
	printf("\n");
//kiem tra output
	printf("\nOutput:");
	for(i=0;i<strlen(output);i++)
	printf("%c",output[i]);
	
}







int check(char* matrix,char cha)
{
	//1 la co trung 0 la ko trung
	for( int i=0;i<24;i++) {
		if(*matrix==cha) return 1;
		else matrix++;
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>	
void gammaGen(int*,int*,int);
void DecToBin(int,int*);
void samosinhronny(int*,int*,int*,int*,int,int);
void sinhronny(int*,int*,int*,int*,int,int);  
void decrypt(int,int*,int*,int*,int*,int);
int main (void){
	int registr[4],i,j,count,choice,k=0,c=0,countPlain=0;
	int plaintext[100],mass[8]={0,0,0,0,0,0,0,0},ciphertext[100],plaintext1[100];
	char ch;
	printf ("Enter to gamma generate count :  ");
	scanf (" %d",&count);
	int gamma[count];
	srand(time(NULL));
	printf ("registr = ");
	for (i=0;i<4;i++){
		registr[i]=rand()%2;
		printf ("%d",registr[i]);		
	}
	printf ("\n");
	gammaGen(registr,gamma,count);
	printf ("gamma = ");
	for (j=0;j<count;j++){
	printf ("%d",gamma[j]);
}
	printf ("\n");
	printf("Enter some text (# to end):\n");
	while ((ch=getchar())!='#'){
		if(ch=='#') break;
		plaintext1[k]=plaintext[k]=ch;
		++k;
		countPlain++;
}
	printf("Enter crypted mode (1-sinhronny , 2- samosinhronny): \n");
			scanf (" %d",&choice);
			if (choice==1){
				printf("\n");
				int cryptedMode=1;
				printf("8-byte sinhronny ciphertext:\n");
			sinhronny(plaintext,mass,gamma,ciphertext,countPlain,count);
			printf("decrypt this text :\n");
			decrypt(cryptedMode,plaintext1,ciphertext,gamma,plaintext,countPlain);				
			}
			if (choice==2){
				printf("\n");
				int cryptedMode=2;
				printf("8-byte samosinhronny ciphertext:\n");
			samosinhronny(plaintext,mass,gamma,ciphertext,countPlain,count);
			printf("decrypt this text :\n");
			decrypt(cryptedMode,plaintext1,ciphertext,gamma,plaintext,countPlain);	
			}		
				
	return 0;
}
void gammaGen(int* reg,int* gamma,int count){
	for (int i=0;i<count;i++){
		gamma[i]=reg[i%4]^reg[(i+1)%4];
		reg[i%4]=gamma[i];
	}
}
void sinhronny(int* plaintext,int* mass,int* gamma,int* ciphertext,int countPlain,int countGamma){
	for (int i=0;i<countPlain-1;i++){
		DecToBin((int)plaintext[i],mass);
			for(int j=0;j<8;j++)
		ciphertext[j]=mass[j]^gamma[j%countGamma];
		    for (int i=0;i<8;i++)
		printf ("%d ",ciphertext[i]);
		printf("\n");
	}
}
void DecToBin(int a,int*mass){
	int i=0;
	while (a != 0){
 if (a % 2 == 0)
 {
 mass[i] = 0;
 a = a / 2;
 }
 else
 {
 mass[i] = 1;
 a = a / 2;
 }
 i++;
 }
}
void samosinhronny(int* plaintext,int* mass,int* gamma,int* ciphertext,int countPlain,int countGamma){
	for (int i=0;i<countPlain-1;i++){
		DecToBin((int)plaintext[i],mass);
			for(int j=0;j<8;j++){
		ciphertext[j]=mass[j]^gamma[j%countGamma];
		gamma[j]=ciphertext[j];
	}
		    for (int i=0;i<8;i++)
		printf ("%d ",ciphertext[i]);
		printf("\n");
	}
}
void decrypt(int cryptedMode,int* plaintext1,int*ciphertext,int*gamma,int*plaintext,int countPlain){
	if(cryptedMode==1){
	for (int i=1;i<countPlain;i++){
		plaintext[i]=gamma[i]^ciphertext[i];
		printf("%d is ACSII %c\n",plaintext1[i],plaintext1[i]);	}	
	}
	if (cryptedMode==2){
for (int i=1;i<countPlain;i++){
		plaintext[i]=gamma[i]^ciphertext[i];
		printf("%d is ACSII %c\n",plaintext1[i],plaintext1[i]);
	}
}
}
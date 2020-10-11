#include <stdio.h>
#include <stdlib.h> 
#include <time.h>	
void gammaGen(int*,int*,int); // 
int main (void){
	int registr[4],i,j,count;
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
		if (count && (j%15==0))
			printf(" ");
	printf ("%d",gamma[j]);
}
	printf ("\n");
	return 0;
}
void gammaGen(int* reg,int* gamma,int count){
	for (int i=0;i<count;i++){
		gamma[i]=reg[i%4]^reg[(i+1)%4];
		reg[i%4]=gamma[i];
	}
}



























 



































  
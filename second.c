#include <stdio.h>
#include <stdlib.h>
#define max(x, y) ( (x) > (y) ? (x) : (y) )

int main(void){
	int matrix[30][30];
	int i=0,j=0;
    FILE *file;
    int a = 0, b = 0, c, k = 0, d = 0;
    char is = 'T';
    
    //Ïðèðàâíèåì âñå ýëåìåíòû ìàòðèöû ê íóëþ
	for(i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
			matrix[i][j]=0;
	}
	
    file = fopen("Toshmamatov.gv", "w");
    fputs("graph{\n", file);

    c = scanf("%d-%d\n", &a, &b);
    if(c != 0){
        while(c != 0)
		{
            d = max(d, max(a, b));
            k++;
            if(c == 1){
                is = 'F';
                fprintf(file, "\t%d\n", a);
            }
            if(c == 2) 
			{
				fprintf(file, "\t%d--%d\n", a, b);
				matrix[a][b]++;
				matrix[b][a]++;
			}
            c = scanf("%d-%d\n", &a, &b);
        }
        //Âûâîä ìàòðèöû ñìåæíîñòè
        printf(" ");
        for(j=1;j<=d;j++)
        {
        	printf(" %d",j);
		}
		printf("\n");
   for(i=1;i<=d;i++)
   {
   		printf("%d ",i);
   		for(j=1;j<=d;j++)
   		{
   			printf("%d ", matrix[i][j]);
	   	}
	   	printf("\n");
   }
   
        if((is == 'T') && (d == k + 1)) printf("True");
        else printf("False");
        fputc('}', file);
        fclose(file);
        system("dot -Tpng Toshmamatov.gv -o Toshmamatov.png");
        return 0;
    }
   else{
        printf("Warning");
        return 19;
   }
   
}

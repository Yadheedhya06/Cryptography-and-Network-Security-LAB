#include<stdio.h>
#include<string.h>
 
int encrypt[3][1], mes[3][1], a[3][3];
char msg[100];

void encryption(); 
void getKeyMessage(); 

void main() {
    getKeyMessage();
    encryption();
}


void getKeyMessage() {
int i, j;
 
printf("Enter 3x3 matrix for key (It should be inversible):\n");
for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) {
        scanf("%d", &a[i][j]);
}

printf("\nEnter a message: ");
scanf("%s", msg);
}



void encryption() {
 
 int i, j, k=0;
 printf("\nEncrypted string is: ");
 
 for(i = 0; msg[i]!='\0'; i++){
     mes[k][0] = msg[i] - 97;
     k++;
     if(k == 3){
        for(int i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                 encrypt[i][0] = encrypt[i][0] + a[i][j] * mes[j][0];
        
        for(int i = 0; i < 3; i++)
            printf("%c", (char)((encrypt[i][0] % 26) + 97));

        for(int i=0; i<3; i++){
            encrypt[i][0] = 0;
            mes[i][0] = 23;}
        
        k = 0;}
    }

 if(strlen(msg)%3 != 0){

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                 encrypt[i][0] = encrypt[i][0] + a[i][j] * mes[j][0];

        
        for(int i = 0; i < 3; i++)
            printf("%c", (char)((encrypt[i][0] % 26) + 97));
     }

    
}



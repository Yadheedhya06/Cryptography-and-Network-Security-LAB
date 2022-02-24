#include<stdio.h>
 
int encrypt[3][1], mes[3][1], a[3][3];
char  k[9];

void encryption(); 
void getKeyMessage(); 

void main() {
    getKeyMessage();
    encryption();
}


void getKeyMessage() {
int i, j, t = -1;
char msg[3];
 
printf("Enter Key string:\n");
scanf("%s",k);
for(i = 0; i < 3; i++)
    for(j = 0; j < 3 ; j++) {
        ++t;
        if(t<9){
            a[i][j] = k[t] - 97;
        }
    }

printf("\nEnter a 3 letter string: ");
scanf("%s", msg);
for(i = 0; i < 3; i++)
    mes[i][0] = msg[i] - 97;
}



void encryption() {
int i, j, k;
for(i = 0; i < 3; i++)
    for(j = 0; j < 1; j++)
        for(k = 0; k < 3; k++)
            encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];

printf("\nEncrypted string is: ");
for(i = 0; i < 3; i++)
    printf("%c", (char)((encrypt[i][0] % 26) + 97));
 
}
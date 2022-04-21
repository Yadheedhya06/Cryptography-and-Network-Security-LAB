#include<stdio.h>
#include<string.h>

int main(){
    char a[26],p[20];
    int c;
    for(int i = 0; i < 26; i++){
        a[i] = (char)(i + 97);
    }

    printf("enter plain text:");
    scanf("%s",p);

    printf("Cipher text is:");
    for(int i = 0; i < strlen(p); i++){
        for(int j = 0; j < 26; j++){
            if(p[i] == a[j]){
                c = ((3*j)+12) % 26;
                printf("%c",a[c]);
            }
        }
    }

    return 0;
}
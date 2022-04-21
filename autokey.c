#include<stdio.h>
#include<string.h>

int s = 13;
void main(){
    char a[26], p[20], ks[20], k = 'n';
    int c;
    for(int i = 0; i < 26; i++){
        a[i] = (char)(i + 97);
    }

    printf("enter plain text:");
    scanf("%s",p);

    strcpy(ks,p);

    for(int i = (strlen(ks) - 1); i > 0; i--){
        ks[i] = ks[i - 1];
    }
    ks[0] = k;
    
    printf("The Cipher text is:");
    for(int i = 0; i < strlen(p); i++){
        for(int j = 0; j < 26; j++){
            if(p[i] == a[j]){
                c = (j + s)%26;
                printf("%c",a[c]);
                s = j;
            }
        }
    }
}


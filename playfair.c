#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateKeyTable(char key[], int ks, char keyT[5][5]);
void encrypt(char str[], char keyT[5][5], int ps);

int main()
{
    char str[20], key[10];
 
    strcpy(key, "ldrp");
    printf("Key text: %s\n", key);
 
    strcpy(str, "instruments");
    printf("Plain text: %s\n", str);

    char ps, ks, keyT[5][5];
 
    ks = strlen(key);

    ps = strlen(str);

    if (ps % 2 != 0) {
        str[ps++] = 'z';
        str[ps] = '\0';
    }

    generateKeyTable(key, ks, keyT);
 
    encrypt(str, keyT, ps);

    printf("Cipher text: %s\n", str);
 
    return 0;
}

void generateKeyTable(char key[], int ks, char keyT[5][5])
{
    int i, j, k, flag = 0, *ptr;

    ptr = (int*)calloc(26, sizeof(int));
    for (i = 0; i < ks; i++) {
        if (key[i] != 'j')
            ptr[key[i] - 97] = 2;
    }
 
    ptr['j' - 97] = 1;
 
    i = 0;
    j = 0;
 
    for (k = 0; k < ks; k++) {
        if (ptr[key[k] - 97] == 2) {
            ptr[key[k] - 97] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
 
    for (k = 0; k < 26; k++) {
        if (ptr[k] == 0) {
            keyT[i][j] = (char)(k + 97);
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
}

void encrypt(char str[], char keyT[5][5], int ps)
{
    int i, a[4];
 
    for (i = 0; i < ps; i += 2) {

        int n, m;

	    if (str[i] == 'm')
		    str[i] = 'n';
	    else if (str[i + 1] == 'm')
		    str[i + 1] = 'n';

	    for (n = 0; n < 5; n++) {

		    for (m = 0; m < 5; m++) {

			    if (keyT[n][m] == str[i]) {
				    a[0] = n;
				    a[1] = m;
			    }
			    else if (keyT[n][m] == str[i + 1]) {
				    a[2] = n;
				    a[3] = m;
			    }
		    }
	    }
        
        if (a[0] == a[2]) {
            str[i] = keyT[a[0]][(a[1] + 1)%5];
            str[i + 1] = keyT[a[0]][(a[3] + 1)%5];
        }
        else if (a[1] == a[3]) {
            str[i] = keyT[(a[0] + 1)%5][a[1]];
            str[i + 1] = keyT[(a[2] + 1)%5][a[1]];
        }
        else {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}



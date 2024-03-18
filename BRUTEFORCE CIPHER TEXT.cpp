#include<stdio.h>
#include<string.h>
int main() {
			char cipherText="UIH IWHUEHDE IEUHMDMDBNBH";
			int maxshift=25;
void decryptcaesarcipher(char cipher[],int shift){
	int length=strlen(cipher);
	char decrypted[length+1];
	for(int i=0;i<length;i++)
	{
		if(cipher[i]>='a' && cipher[i] <= 'z'){
			decrypted[i]='a'+(cipher[i]-'a'-shift+26)%26;
		} else if(cipher[i]>='A' && cipher[i] <='Z'){
			decrypted[i]='A'+(cipher[i]-'A'-shift+26)%26;
		} else {
			decrypted[i]=cipher[i];
		}
	}
	decrypted[length]='\0';
	printf("Shift %d: %s\n",shift,decrypted);

		}
			printf("Brute Force Decryption:\n");
			for(int i=0;i<=maxshift;i++)
			decryptcaesarcipher(cipherText,i);
		}
		return 0;
		
	}
}


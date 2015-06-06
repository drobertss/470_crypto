#include <stdio.h>
#include <crypt.h>
#include <unistd.h>
#include <string.h>


void words(char *str, int idx, int len) {
	char x;
	char* pass;
	int ret;
 	const char *const pass  = "$1$BXSY90uv";
	const char *const finalPassword = "$1$BXSY90uv$Enq2BCpzLMF4QMzv9GBEV/"; 
	if(idx < (len -1) && ret != 0) {
 		for (x = 'a'; x <='z'; ++x) { 
			str[idx] = x;
			words(str, idx + 1, len);
			pass = crypt(str, pass);
			ret = strcmp(pass, finalPassword);

			if(ret == 0) {

				printf("The password is: ");
				printf(str);
				break;
			}
		}
	} else {
		for (x = 'a'; x<='z'; ++x) {
			str[idx] = x;

			pass = crypt(str, pass);
		

			ret = strcmp(pass, finalPassword);			

			if(ret ==  0) { 
				printf("password is.. ");
				printf(str);
				break;
			}
		}
	}



}

#define LEN 4
int main(int argc, char **argv)
{
	printf("crack this puppy...\n");
	
	char str[LEN + 1];

	memset(str,0, LEN + 1);
	
	words(str, 0, LEN);
	
	
	return 0;
}
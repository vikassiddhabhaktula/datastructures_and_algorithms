#include <stdio.h>
#include <string.h>

int pal(char *str) {
	int l = strlen(str);
	int ret = 0;
	printf("%s %d\n", str, l);
	if (l < 2) return 1;
	int i=0;
	char new_str[l];
	if (str[0] == str[l-1]) {
		for (i=0; i<l-2; i++) {
			new_str[i] = str[i+1];
		}
		new_str[i] = '\0';
		ret = pal(new_str);
	}
	return ret;
} 

int main(int argc, char **argv) {
	printf("%d\n", pal(argv[1]) == 1);
	return 0;
}

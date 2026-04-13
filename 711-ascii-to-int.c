#include<stdio.h>

int ascii_to_integer(char *string);

int ascii_to_integer(char *str){
	if (str == NULL)
		return -1;
	
	int sign = 1;
	int value = 0;

	if (*str == '-'){
		sign = -1;
		str++;
	} else if (*str == '+'){
		str++;
	}

	while(*str != '\0'){
		if (*str >= '0' && *str <= '9')
			value = value*10 + *str++ - '0';
		else
			return -1;
	}
	return sign * value;
}

int main(void){
	char *test = "-10291";
	printf("%d", ascii_to_integer(test));
	return 0;
}

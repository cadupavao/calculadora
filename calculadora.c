#include <stdio.h>
#include <stdlib.h>

int soma (int x, int y){
	//Aleração feita na branch fsoma
	return x+y;
}
int subtrai (int x, int y){
	//Alteração feita na branch fsubtrai
	return x-y;
}
int multiplica (){}
int divide (){}

int main(){

	printf("hello git!\n\n");
	printf("Soma: %d\n", soma (2,2));
	printf("Subtração: %d\n", subtrai (2,2));


}

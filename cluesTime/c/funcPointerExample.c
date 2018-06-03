#include<stdio.h>
#include<stdlib.h>

void haiku(){
printf("I am haiku function\n");
}

void simi(){
printf("I am simi function\n");
}

int sum(int a,int b){
 return a+b;
}

int sub(int a,int b){
   return a-b;
}

int max(int a,int b){
  return a>b?a:b;
}

int min(int a,int b){
    return a<b?a:b;
}

int main(){

	void (*fun_array[2])(void)={haiku,simi};
        fun_array[0]();
        fun_array[1]();



        typedef void (*fun_blue_print)();
        fun_blue_print funList[3];
	funList[0] = haiku;
	funList[1] = &simi ; // both syntax have same mining , with or without & symbol
	funList[1]();
	funList[0]();



	typedef int (*function_int_int_int)(int,int);

        function_int_int_int *fun = calloc(3,sizeof(function_int_int_int));

	fun[0]= sum;
        fun[1] = sub;
	fun[2] = max;
	fun[3] = min;

	int aPLUSb = fun[0](6,7);
	printf(" a+b = %d\n",aPLUSb);
  int i;

  scanf("%d\n",&i);
  printf("i=%d\n",i);

}

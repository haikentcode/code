int main(){
char *ptr="haikent";

printf("%c\n",*&ptr);
printf("%c\n",*&*&ptr);

getchar();

return 0;
}

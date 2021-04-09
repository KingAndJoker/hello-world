/* Свиридков Влад, Вариант 16
    Задача 4.2
      Дано предложение. Сформировать новое слово из первых и последних символов
      таких слов предложения, которые не содержат цифр. Добавить полученное
      слово в предложение после любого самого длинного слова.
*/

#include <stdio.h>
#include <windows.h>
#define MAX_LENGTH 80
int main() {
  system("chcp 1251 > nul");

  char s[MAX_LENGTH]={};
  gets(s);

  int i=0,j,ians=0,num_bool,iml=0,sml=0;
  char word[MAX_LENGTH];
  char ans[MAX_LENGTH]={};
  while(s[i]!='\0') {
		j=0;
		num_bool=1;
		while(s[i]!='\0' && s[i]!=' ') {
			word[j]=s[i];
			if(s[i]>='0' && s[i]<='9')
			  num_bool = 0;
			j++;
			i++;
		}

		word[j]='\0';
		if(j>0 && num_bool) {
			ans[ians]=word[0];
			ians++;
			ans[ians]=word[j-1];
			ians++;
			ans[ians]='\0';
		}

		if(j>sml) {
			sml=j;
			iml=i-j;
		}

		i++;
	}

	ans[ians]=' ';
	ians++;

	int n=0;
	while (s[n]!='\0')n++;

	for(i=iml+sml;i<n;i++)s[i+ians]=s[i];
	for(i=iml+sml+1;i<iml+sml+ians+1;i++)
	  s[i]=ans[i-iml-sml-1];

	printf("%s\n", s);

  system("PAUSE");
  return 0;
}

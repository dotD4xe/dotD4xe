#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main(int argc, char *argv[]){
    system("chcp 1251");
    int *arr, n, max, min, i = 0;
    printf("Введите количество члеов посдовательности не более 100\n"); //Записываем кол-во элементов
    scanf("%d", &n);
    if(n < 1 || n > 100){
    	printf("Некорректные данные");
    	exit(0);
	}
    arr = malloc(sizeof(int) * n);
    
    printf("Введите элементы в массив:\n");
    for (i = 0; i < n; i++)            
	{
		printf("arr[%d] = ", i);      //Записываем элементы в массив
		scanf("%d", &arr[i]);
	}
        //Задание 1

    for (min=max=0, i=1; i<n; i++)
    {
        if (arr[i] > arr[max]) max = i;    //Находим минимальное и максимальное значение
        if (arr[i] < arr[min]) min = i;
    }
    double arithmeticAverage = (arr[max] + arr[min]) / 2;   //считаем среднее арифметическое
    int count = 0;
    for(i = 0; i < n; i++)
    {
        if(arithmeticAverage < arr[i])              //Находим кол-во элементов которые были больше средне арифетического
        {
            count++;
        }
    }
    if(count > 0){
        printf("A) количество элементов массива, больших по значению, чем среднее арифметическое максимального и минимального элементов = %d\n", count);
    }
    else{                                                       // проверка на корректность
        printf("A)Нет числа больше чем среднее значение\n");
    }
        //задание 2
    
    int one, sum = 0, cnt = 0, cnt1 =0 ;
    for (i=0;i<n;i++)
    {
        if (arr[i]<0 && cnt<1)
        {                                  //Находим первое отрицательно число
            one=i;
            cnt++;
        }
    }
    int last;
    for (i = n - 1; i>0; i--)
    {
        if (arr[i]<0 && cnt1<1)
        {
            cnt1++;                         //находим последнее отрицательно число
            last=i;
        }
    }
    for (i=one+1;i<last;i++)
    {
        sum+=arr[i];                        //складываем эллементы массива расположенных между первым и последним отрицательным элементомм
    }
    if(cnt == 1 && cnt1 == 1){
        printf("B) произведение элементов массива, расположенных между первым и последним отрицательными элементами = %d\n", sum);     
    }
    else if(cnt == 0 && cnt1 == 0){
        printf("B) Нет отрицательных элементов\n ");          //проверка на корректность
    }
    else{
        printf("B) Имеется только 1 отрицательный элемент вместо двух\n");
    }
        // задание 3
    int max1, j;
    for (max1=0, i=1; i<n; i++)
    {
        if (arr[i] > arr[max1]) max1 = i;    //Находим максимальное значение
    }
    int maxim = arr[max1];
    for(i = 0; i < n; i++)
	{
        if(maxim == arr[i])
		{              
            for(j = i;j<n-1;j++)
			{
            	arr[j] = arr[j + 1];            //замещаем макс значение
			}
			n--;
			i = -1;
        }
    }
    printf("Массив без максимальных элементов:\n");
    for(i = 0; i<n; i++){
    	printf("%d ", arr[i]);
	}
    return 0; 
   
}


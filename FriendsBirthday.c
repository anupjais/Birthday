#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
# include<string.h>
# include<ctype.h>
# include<termios.h>


char getch(void)
{
	struct termios old, new;
	char ch;
	tcgetattr(0, &old);
	new=old;
	new.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( 0, TCSANOW, &new);
	ch=getchar();
	tcsetattr(0, TCSANOW, &old);
	return(ch);
}
// char getch(void);
// int readNum();
/*const char* readChar()
{
    char num[10];
    char ch;
    int count=0;

    while(1){
        if(count>=0 && count<10){
            ch=getch();
            //printf("%d",ch);
            if(ch==127 && count>0){
                printf("\b \b");
                count--;
            }
            else if(ch==10)
                break;
            else;
            if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')){
                num[count++]=ch;
                printf("*");
            }
        }
        else
            break;
    }
    // num[count]='\0';

    // int number=atoi(num);
    // char name[10]=atoll(num);

    // return number;
    return num;
}*/
int readChar(char *alpha)
{
    char ch;
    int count = 0;

    while (1)
    {
        if (count >= 0 && count < 10)
        {
            ch = getch();
            if (ch == 127 && count > 0)
            {
                printf("\b \b");
                count--;
            }
            else if (ch == 10)
            {
                break;
            }
            else if (isalpha(ch))
            {
                alpha[count++] = ch;
                printf("*"); // Print the entered character
            }
        }
        else
        {
            break;
        }
    }

    // alpha[count] = '\0'; // Null-terminate the string

    return 0; // You might want to return something meaningful or modify the function signature based on your needs
}


/*int main()
{
    int num;
    printf("\n Enter a number : ");
    num=readNum();
    printf("\n Entered number is %d done\n",num);

    return 0;
}*/

void Delay(double r)
{
    int i=1;
    while(i<r)
    {
        i++;
    }
}
int main()
{
    system("clear");
    // int num;
    char name[10];
    printf("\n Enter your friend's Name : ");
    readChar(name);
    // char name[]=readChar();
    // char *name=readChar(); //Not works properly
    // name=readChar();
    // num=readNum();
    printf("\n Entered Name is %s done\n",name);


    // char a[]={'A','N','K','I','T'};
    int i=1;
    int R[]={95,96,94,93,92};
    
    // system("clear");
    
    printf("\033[103:96:3m \t\t\v\v\v\v\v\v\vHappy Birthday\033[0m  ");
    // while(10)
    while(i<6)
    {
        // printf("\033[%dm %3d\033[m", R[i-1],R[i-1]);
        printf("\033[05m");
        printf("\033[%dm", R[i-1]);
        // printf("%c",a[i-1]);
        printf("%c",name[i-1]);
        i++;
        // system.Sleep(10000);
        // Delay(99887799543);
    }
    printf("\033[91m!\n");
    Delay(99887799543);

    return 0;
}
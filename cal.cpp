#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h>
int cal; void call(int);
int main()
{
     long int cur_yr,day,month,d; char ch;
     reset: system("cls");
     month: system("color 64"); printf("Enter month :: ");
     scanf("%d",&month); if(month<1||month>12){printf("Enter the Month within Limits 1-12\n");fflush(stdin);goto month;}
     year:  printf("Enter year :: ");
     scanf("%d",&cur_yr); if(cur_yr<1||cur_yr>994000000){printf("Enter the Year within Limits 1-994000000\n");fflush(stdin);goto year;}
     start: system("cls"); system("color 84");
     printf("Instructions:-\n");//Instructions
     printf("Press Space to Reset or Esc/q/Q to Exit or Enter to change the Year.\n");
     printf("Month: Press a/A/Lt_arrow key to decrease or d/D/Rt_arrow key to increase.\n");
     printf("Year: Press w/W/Up_arrow key to increase or s/S/Dn_arrow key to decrease.\n");
     printf("\n\n\nMonth :: %d\nYear :: %d\n\n",month,cur_yr);
     d=(cur_yr-1)*365; d+=cur_yr%4-cur_yr%100+cur_yr%400;//Finding Number of Days till 1/1.
     if(month==1){cal=31; goto end;}//Days in Months.
     if(month==2){if(cur_yr%400==0) cal=29;
                 else if(cur_yr%100==0) cal=28;
                 else if(cur_yr%4==0) cal=29;
                 else cal=28; goto a;}
     if(month==3){cal=31; goto b;} if(month==4){cal=30; goto c;} if(month==5){cal=31; goto d;}
     if(month==6){cal=30; goto e;} if(month==7){cal=31; goto f;} if(month==8){cal=31; goto g;}
     if(month==9){cal=30; goto h;} if(month==10){cal=31; goto i;} if(month==11){cal=30; goto j;}
     if(month==12){cal=31; goto k;}
     k:d+=30; j:d+=31; i:d+=30; h:d+=31; g:d+=31; f:d+=30; e:d+=31; d:d+=30; c:d+=31;//Adding days of Previous Months
     b:if(cur_yr%400==0) d+=29;
       else if(cur_yr%100==0) d+=28;
       else if(cur_yr%4==0) d+=29;
       else d+=28;
     a:d+=31;
     end: d=d%7;/*//Taking Modulus so that d be a no. b/w 0-6//*/ printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun");//Acquiring Table
     switch(d)
     {
              
              case 0:                   //Friday
                   printf("\n\t\t\t\t"); printf("1\t2\t3"); call(4); break;
              case 1:                 //Saturday
                   printf("\n\t\t\t\t\t"); printf("1\t2"); call(3); break;
              case 2:                 //Sunday
                   printf("\n\t\t\t\t\t\t"); printf("1"); call(2); break;
              case 3:                 //Monday
                   call(1); break;
              case 4:                 //Tuesday
                   printf("\n\t"); printf("1\t2\t3\t4\t5\t6"); call(7); break;
              case 5:                 //Wednesday
                   printf("\n\t\t"); printf("1\t2\t3\t4\t5"); call(6); break;
              case 6:                //Thursday
                   printf("\n\t\t\t"); printf("1\t2\t3\t4"); call(5); break;
     } fflush(stdin);
     get: ch=getch();
     if(ch==27||ch=='q'||ch=='Q') goto endofprogram;//Exit
     else if(ch=='a'||ch==75||ch=='A'){if(month>1){month-=1;goto start;}else goto get;}//--Month;
     else if(ch=='d'||ch==77||ch=='D'){if(month<12){month+=1;goto start;}else goto get;}//++Month;
     else if(ch=='w'||ch==72||ch=='W'){if(cur_yr<994000000){cur_yr+=1; goto start;}else goto get;}//++Year;
     else if(ch=='s'||ch==80||ch=='S'){if(cur_yr>1){cur_yr-=1;goto start;}else goto get;}//--Year;
     else if(ch=='\r')goto year;/*//Change Year//*/ else if(ch==32)goto reset;/*//Reset//*/ else goto get;//Do Nothing
     endofprogram: return 0;
}
void call(int t)
{
     printf("\n");
     for(;t<=cal;)
     {
                  for(int i=0;i<=6&&t<=cal;i++,t++)
                  {
                          printf("%d\t",t);
                  }
                  printf("\n");
     }
}

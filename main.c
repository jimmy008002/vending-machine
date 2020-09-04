// Paste your project code here
// Remember you also need to submit again on Blackboard
// Include also your academic honesty declaration with your personal particulars

/**
 * ENGG1110 Problem Solving by Programming 
 *
 * I declare that the assignment here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   http://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name : chow chun yeung <fill in yourself>
 * Student ID   : 1155131406 <fill in yourself>
 * Class/Section: f <fill in yourself>
 * Date         : 13-12-19 <fill in yourself>
 */
 
 #include <stdio.h>
#include <stdbool.h>
int revenue;

void inteface(int sum,int price[],char bottom[],char bought){
   printf("\n");
    
    printf("*---------------------------*\n");
     printf("|      Vending Machine      |\n");
      printf("*---------------------------*\n");
       printf("|   A    B    C    D    E   |\n");
        printf("|  $%d  $ %d  $ %d  $ %d  $ %d  |\n",price[0],price[1],price[2],price[3],price[4]);
      printf("|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n",bottom[0],bottom[1],bottom[2],bottom[3],bottom[4]);
       printf("*---------------------------*\n");
       printf("|                    [$ %d]  |\n",sum);
         printf("|           [=%c=]           |\n",bought);
           printf("*---------------------------*\n");
           printf("\n");


}


int insertcoin(int sum , int drinkprice[],char bottom[],int stock[]){
    int option ;
    
  do {
  
  printf("\n");  
    printf("(2) Which coin would you like to insert?\n");
    printf("1. $1\n");
    printf("2. $2\n");
    printf("3. $5\n");
    printf("4. $10\n");
    printf("0. Go back\n");
    printf("Your choice:");
    scanf("%d",&option);
    
    switch(option){
        case 1:
        sum+=1;
        printf("You have inserted $%d\n",sum);
        break;
        case 2:
        sum+=2;
        printf("You have inserted $%d\n",sum);
        break;
        case 3:
        sum+=5;
        printf("You have inserted $%d\n",sum);
        break;
        case 4:
        sum+=10;
        printf("You have inserted $%d\n",sum);
        break;
       case 0:
       printf("Going back! \n");
        break;
    }
    
   


    if (sum>=5) 
    bottom[2]='O';
    if (sum>=6)
     bottom[1]='O';
     if (sum>=7)
      bottom[4]='O';
      if (sum>=8)
      bottom[3]='O';
        if (sum>=10)
 bottom[0]='O';
 
for (int i=0;i<5;i++)  {
   if (stock[i]==0)
   bottom[i]='X';
 }

 
    inteface(sum,drinkprice,bottom,'=');
    
 
}while (option!=0);

return sum;
}

int Press( int sum ,int drinkprice[],char bottom[],int stock[]){

int option;
char bought;
printf("1. A\n");
printf("2. B\n");
printf("3. C\n");
printf("4. D\n");
printf("5. E\n");
printf("0. Go back\n");
printf("Your choice:");
scanf("%d",&option);


printf("You have pressed button");
if (option==1){
printf(" A.\n");
sum-=drinkprice[0];
stock[0]-=1;
bought='A';
revenue+=drinkprice[0];
}
else if (option==2){
printf(" B.\n");
sum-=drinkprice[1];
stock[1]-=1;
bought='B';
revenue+=drinkprice[1];

}
else if (option==3){
printf(" C.\n");
sum-=5;
stock[2]-=drinkprice[2];
bought='C';
revenue+=drinkprice[2];
}
else if (option==4){
printf(" D.\n");
sum-=drinkprice[3];
stock[3]-=1;
bought='D';
revenue+=drinkprice[3];
}
else if (option==5){
printf(" E.\n");
sum-=drinkprice[4];
stock[4]-=1;
bought='E';
revenue+=drinkprice[4];
}
  


for (int i=0;i<5;i++)  {
   if (stock[i]==0)
   bottom[i]='X';
else if (sum>=drinkprice[i])
bottom[i]='O';
else bottom[i]=' ';}

inteface(sum,drinkprice,bottom,bought); 


return sum;
}


void productinfo(char drinkname[][20],int price[]){


printf("\n");
printf("(1) The displayed products are:\n");
printf("A. %s ($%d)\n",drinkname[0],price[0]);
printf("B. %s ($%d)\n",drinkname[1],price[1]);
printf("C. %s ($%d)\n",drinkname[2],price[2]);
printf("D. %s ($%d)\n",drinkname[3],price[3]);
printf("E. %s ($%d)\n",drinkname[4],price[4]);
printf("\n");

    
}

int returnmoney(int sum){
printf("(4) Return button is pressed.\n");
printf("$%d has been returned.\n\n",sum);

sum-=sum;
return sum;

}

bool codecheck(){
int code;

printf("(9) Opening service menu. Access code is required.\n");
printf("Enter access code:");
scanf("%d",&code);
if (code==1110||code==001110){
printf("correct code!\n");
printf("\n");
return true;
}
else {printf("Incorrect code!\n") ;
printf("\n");
return false;
}

}


int servicemeun(){
int option;

  

printf("(9) What would you like to do?\n");
printf("1. Inspect machine status\n");
printf("2. Withdraw all money\n");
printf("3. Refill product\n");
printf("4. Change product\n");
printf("0. Go back\n");
printf("Your choice:");


scanf("%d",&option);
 printf("\n");        
return option; 

}

void checkstatus(char drinkname[][20],int price[],int stock[],int sum){

printf("(9-1) Machine status\n");
printf("Amount of revenue: %d\n",revenue);
printf("Amount of inserted coins: %d\n",sum);
printf("Product information:\n");

for (int i=0;i<5;i++){
if (stock[i]<=0)
printf("%c. %s ($%d) (sold out) \n",'A'+i,drinkname[i],price[i]);
else printf("%c. %s ($%d) (%d left) \n",'A'+i,drinkname[i],price[i],stock[i]);


};
printf("\n");
}

void withdraw(int sum){
int money ;
money =revenue+sum;
revenue=0;
sum=0;

printf("(9-2) All money is being withdrawn.\n");
printf("$%d is withdrawn.",money);
printf("\n");


}


void refill(int stock[]){


 int inneroption;
        char choice[5]={'A','B','C','D','E'};
  
     

                  
        printf("1. A\n");
printf("2. B\n");
printf("3. C\n");
printf("4. D\n");
printf("5. E\n");
printf("0. Go back\n");
printf("Your choice:");
scanf("%d",&inneroption);
        
   if (inneroption>=1&&inneroption<=5)
      while ( stock[inneroption-1]!=10)
      { stock[inneroption-1]+=1;}
           else return;
     printf("You have refilled product %C to full.\n",choice[inneroption-1]);

        
}

void changeproduct(char name[][20],int price[],int stock[]){
 int inneroption;
char choice[5]={'A','B','C','D','E'};


printf("(9-4) Which product would you like to change?\n");
    printf("1. A\n");
printf("2. B\n");
printf("3. C\n");
printf("4. D\n");
printf("5. E\n");
printf("0. Go back\n");
printf("Your choice:");
scanf("%d",&inneroption);


 printf("You are changing product %C.\n",choice[inneroption-1]);

 printf("Enter new product name: ");
 scanf("%s",&name[inneroption-2][20]);
 printf("Enter new product price:");
 scanf("%d",&price[inneroption-1]);
 
      while ( stock[inneroption-1]!=10)
      { stock[inneroption-1]+=1;}
 printf("The new product %c has been filled to full.\n",choice[inneroption-1]);
printf("\n");

}

int main()
{
   
    bool check;
    int option;
    int coins=0;
    
    int drinkprice[5]={10,6,5,8,7};
    char bottom[5]={' ',' ',' ',' ',' '};
    char drinkname[5][20]={"Juice","Cola","Tea","Water","Coffee"};
    int stock[5]={5,1,2,1,9};
    
  inteface(coins,drinkprice,bottom,'='); 
            do{
           printf("What would you like to do?\n");
           printf("1. Read product information\n");
            printf("2. Insert coin\n");
             printf("3. Press product button\n");
              printf("4. Press return button\n");
               printf("9. Open service menu (code required)\n");
                printf("0. Quit\n");
                
                 printf("Your choice:");
                 scanf("%d",&option);
         
       
       switch(option){
          case 0:
          break;
           case 1:
            productinfo(drinkname,drinkprice);
        break;
            case 2:
            coins=insertcoin(coins,drinkprice,bottom,stock);
             break;
           case 3:
           coins=Press(coins,drinkprice,bottom,stock);
           break;
           case 4:
           coins=returnmoney(coins);
           for (int i=0;i<5;i++)  {
           if (stock[i]==0)
           bottom[i]='X';
          else bottom[i]=' ';}
           inteface(coins,drinkprice,bottom,'=');
           break;
           case 9:
           check=codecheck();
           if (check==false)
           break;
           else {
             
             int inneroption;
           do {

            
            inneroption=servicemeun();
             switch(inneroption){
               case 0:
               break;
               case 1:
               checkstatus(drinkname,drinkprice,stock,coins);
               break;
               case 2:
               withdraw(coins);
               break;
             case 3:
             refill(stock);
             break;
             case 4:
             changeproduct(drinkname, drinkprice,stock);
             break;

        
             
             }
           printf("\n");
           }while(inneroption!=0);

           }
           


           break;
           default:
           printf("Invalid choice!\n");
           
           
       };
       
    }while (option!=0);
           
           
           
           
    
    
    return 0;
}



 

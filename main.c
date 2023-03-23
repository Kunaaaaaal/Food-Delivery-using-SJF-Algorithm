#include <stdio.h>

typedef struct dish {
    char dish[50];
    int price[10];
    int dcount;
}dish;

int main()
{
    //declaration of each dish

    dish d1;
    strcpy(d1.dish,"Chicken Tikka Fried Rice");
    d1.price[0]=269;
    d1.dcount=1;

    dish d2;
    strcpy(d2.dish,"Hunters Chicken Rice Bowl");
    d2.price[1]=299;
    d2.dcount=2;

    dish d3;
    strcpy(d3.dish,"Black Gold Dumpling Noodles");
    d3.price[2]=299;
    d3.dcount=3;

    dish d4;
    strcpy(d4.dish,"Jeera Rice Chicken Manchurian");
    d4.price[3]=275;
    d4.dcount=4;

    dish d5;
    strcpy(d5.dish,"Crispy Paneer Hakka noodles");
    d5.price[4]=265;
    d5.dcount=5;

    dish d6;
    strcpy(d6.dish,"Tantanmen soupy noodle bowl");
    d6.price[5]=299;
    d6.dcount=6;

    dish d7;
    strcpy(d7.dish,"Pulled Chicken Ranch Bagelwich");
    d7.price[6]=199;
    d7.dcount=7;

    dish d8;
    strcpy(d8.dish,"Cheesy Chicken Sliders");
    d8.price[7]=179;
    d8.dcount=8;

    dish d9;
    strcpy(d9.dish,"Chicken Tikka Fried Rice");
    d9.price[8]=269;
    d9.dcount=9;

    dish d10;
    strcpy(d10.dish,"Coffee Vanilla Ripple Cake Slice");
    d10.price[9]=99;
    d10.dcount=10;

	int A[100][4];
	int i, j, n, total = 0, index, temp, mode, amt[40], delivery[100],del;
	float avg_wt, avg_tat;
	printf("Enter number of users ordering: ");
	scanf("%d", &n);
    //Start selecting menu from here
    for(int k=0;k<n;k++){
        next: printf("\nEnter for User %d\n",k+1);
        user:
        printf("What we serve:\n 1.%s \n 2.%s \n 3.%s \n 4.%s \n 5.%s\n 6.%s\n 7.%s\n 8.%s\n 9.%s\n 10.%s\n",d1.dish,d2.dish,d3.dish,d4.dish,d5.dish,d6.dish,d7.dish,d8.dish,d9.dish,d10.dish);
        //Print what has been selected and print total
        printf("\nselect item:");
        scanf("%d", &index);
           switch(index){
            case 1:
            printf("You chose \"%s\" \n", d1.dish);
            printf("price of dish: %d \n",d1.price[0]);
            printf("Your current total: %d",total=total+d1.price[0]);
            break;

            case 2:
            printf("You chose \"%s\" \n", d2.dish);
            printf("price of dish: %d \n",d2.price[1]);
            printf("Your current total: %d",total=total+d2.price[1]);
            break;

            case 3:
            printf("You chose \"%s\" \n", d3.dish);
            printf("price of dish: %d \n",d3.price[2]);
            printf("Your current total: %d",total=total+d3.price[2]);
            break;

            case 4:
            printf("You chose \"%s\" \n", d4.dish);
            printf("price of dish: %d \n",d4.price[3]);
            printf("Your current total: %d",total=total+d4.price[3]);
            break;

            case 5:
            printf("You chose \"%s\" \n", d5.dish);
            printf("price of dish: %d \n",d5.price[4]);
            printf("Your current total: %d",total=total+d5.price[4]);
            break;

            case 6:
            printf("You chose \"%s\" \n", d6.dish);
            printf("price of dish: %d \n",d6.price[5]);
            printf("Your current total: %d",total=total+d6.price[5]);
            break;

            case 7:
            printf("You chose \"%s\" \n", d7.dish);
            printf("price of dish: %d \n",d7.price[6]);
            printf("Your current total: %d",total=total+d7.price[6]);
            break;

            case 8:
            printf("You chose \"%s\" \n", d8.dish);
            printf("price of dish: %d \n",d8.price[7]);
            printf("Your current total: %d",total=total+d8.price[7]);
            break;

            case 9:
            printf("You chose \"%s\" \n", d9.dish);
            printf("price of dish: %d \n",d9.price[8]);
            printf("Your current total: %d",total=total+d9.price[8]);
            break;

            case 10:
            printf("You chose \"%s\" \n", d10.dish);
            printf("price of dish: %d \n",d10.price[9]);
            printf("Your current total:%d",total=total+d10.price[9]);
            break;

            default:
            printf("We do not have the dish ready yet.");
            break;
        }
        amt[k]=total;
        printf("\nDo you want to order more dishes(1=yes, 2=no): ");
        scanf("%d",&j);
          if(j==1){
            goto user;
          } else{
              total=0;
              continue;
          }
    }
    printf("\n\n");
    for(int k=0;k<n;k++){
        printf("Amount to be paid by user%d: %d\n\n", k+1, amt[k]);
    }
    printf("\n\n");
	total=0, j=0;
	printf("Enter delivery distance of all users(in kms):\n");

	for (i = 0; i < n; i++) {
		printf("User %d: ", i + 1);
		scanf("%d", &A[i][1]);
		A[i][0] = i + 1;
	}
	for (i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++)
			if (A[j][1] < A[index][1])
				index = j;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;
		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
	}
	A[0][2] = 0;
	for (i = 1; i < n; i++) {
		A[i][2] = 0;
		for (j = 0; j < i; j++)
			A[i][2] += A[j][1];
		total += A[i][2];
	}
	avg_wt = (float)total / n;
	total = 0;
	printf("\nUser: U, Delivery time: DT, Waiting time:WT, Turnaround time: TAT\n\n");
	printf("Users	 DT	 WT	 TAT\n");
	for (i = 0; i < n; i++) {
		A[i][3] = A[i][1] + A[i][2];
		total += A[i][3];
		printf("User%d	 %d	 %d	 %d\n", A[i][0],
			A[i][1], A[i][2], A[i][3]);
	}
	printf("\n\nFood delivered in the order of: \n");
	for(i=0;i<n;i++){
        printf("user%d, ", A[i][0]);
	}
     printf("\n\n");
	avg_tat = (float)total / n;
	printf("Average Waiting Time= %f", avg_wt);
	printf("\nAverage Turnaround Time= %f", avg_tat);
}

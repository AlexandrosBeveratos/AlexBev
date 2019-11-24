#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	float pap = 0.1;
	float gla = 0.2;
	float alu = 0.15;
	float pla = 0.05;
	float clo = 0.5;
	char agreement[10];
	int quant = 0;
	int glassquant = 0;
	int paperquant = 0;
	int aluquant = 0;
	int plasticquant = 0;
	int clothquant = 0;
	char type[20]; 
	int	type1 = 0;
	int type2 = 0;
	int type3 = 0;
	int type4 = 0;
	int type5 = 0;
	float sum = 0;
	float papersum = 0; 
	float glasssum = 0;
	float alusum = 0;
	float plasticsum = 0;
	float clothsum = 0;
	char method[6];
	float amount;
	int i = 0;
	long long cardnumber;
	int digitsum;
	int digit, digitcount;
	long long card;
	float bonus;
	int bonusresult = 0;
	do
	{
		quant = 0;
		glassquant = 0;
		paperquant = 0;
		aluquant = 0;
		plasticquant = 0;
		clothquant = 0;
		type[20]; 
		type1 = 0;
		type2 = 0;
		type3 = 0;
		type4 = 0;
		type5 = 0;
		sum = 0;
		papersum = 0; 
		glasssum = 0;
		alusum = 0;
		plasticsum = 0;
		clothsum = 0;
		char more[10];
		
		do{
		system("cls");
	    printf("Write the type of item you want to recycle (paper, glass, aluminium, plastic, cloth):\n");
		scanf("%s",&type);
		do {
			quant = 0;
			printf("Type in the quantity of the %s items you want to recycle (1-10) and insert them:\n", type);
			scanf("%d", &quant);
		}
		while(quant<=0 || quant>10);

		if (strcmp(type, "paper")==0){
			paperquant = quant;
			papersum = pap * quant;
			sum = sum + papersum;
			printf("Paper quantity: %d, Money in return: %.2f Euro\n", quant, papersum);
			printf("Whole sum: %.2f Euro\n", sum);
			type1 = 1;
		}	
		else if(strcmp(type, "glass")==0){
			glassquant = quant;
			glasssum = gla * quant;
			sum = sum + glasssum;
			printf("Glass quantity: %d, Money in return: %.2f Euro\n", quant, glasssum);
			printf("Whole sum: %.2f Euro\n", sum);
			type2 = 1;
		}
		else if(strcmp(type, "aluminium")==0){
			aluquant = quant;
			alusum = alu * quant;
			sum = sum + alusum;
			printf("Aluminium quantity: %d, Money in return: %.2f Euro\n", quant, alusum);
			printf("Whole sum: %.2f Euro\n", sum);
			type3 = 1;
		}
		else if(strcmp(type, "plastic")==0){
			plasticquant = quant;
			plasticsum = pla * quant;
			sum = sum + plasticsum;
			printf("Plastic quantity: %d, Money in return: %.2f Euro\n", quant, plasticsum);
			printf("Whole sum: %.2f Euro\n", sum);
			type4 = 1;
		}
	    else if(strcmp(type, "cloth")==0){
	    	clothquant = quant;
			clothsum = clo * quant;
			sum = sum + clothsum;
			printf("Cloth quantity: %d, Money in return: %.2f Euro\n", quant, clothsum);
			printf("Whole sum: %.2f Euro\n", sum);
			type5 = 1;
	    }
	    else return 0;
		int check1 = 0;
		do{
			printf("________________________________________________________________________\n\n");
			printf("Type in \"add\" if you want to recycle a different item aswell or \"end\" if you are done:\n");
			scanf("%s", more);
			if (strcmp(more, "add")==0){
				check1 = 1;
		    }
			else if(strcmp(more, "end")==0)
			{
				check1 = 1;
				}	
 	    }while(check1 !=1);
 		
 	}while(strcmp(more, "add")==0); 
 		
		printf("Type in \"asap\" for cash or \"card\" for bank transfer:\n");   
		scanf("%s", method);
		amount = 0;
		i = 0;
		cardnumber = 0;
		digitsum = 0;
		digit = 0;
	 	bonusresult = 0;
		if(strcmp(method,"asap")==0)
		{
			do{
		
				printf("Type in the amount you want to get in return:\n");
				scanf("%f",&amount);
				i++;
	  		}
			while(amount>sum && i<=3);
		if(i>3) 
		{
			printf("Recycling process cancelled...");
			return 0;
		}
		}
		else if(strcmp(method,"card")==0)
		{
			bonus = sum * 0.1;
			do
			{
				digitcount = 0;
				printf("Type in your card number:\n");
				scanf("%lld",&cardnumber);
				card = cardnumber;
				while(card>0)
				{
					digit = card % 10;
					digitsum = digitsum + digit;
					card = card / 10;
					digitcount++;
				}
			}
			while(digitcount!=16);
		int inputsum;
		printf("Calculate the sum of the digits of your card and type it in:\n");
		scanf("%d", &inputsum);
		if(inputsum == digitsum)
		{
			amount = sum  + bonus;
			bonusresult = 1;
		}
		else
		{
			amount = sum - bonus;
			bonusresult = 2;
		}
		}
		system("cls");
		printf(		"Money Method: %s\n\n\n", method);
		if(type1=1)
		{
			printf("		Paper items: %d\n", paperquant);
			printf("		Price: %.2f Euros\n\n", papersum);
		}
		if(type2==1)
		{
			printf("		Glass items: %d\n", glassquant);
			printf("		Price: %.2f Euros\n\n", glasssum);
		}
		if(type3==1)
		{
			printf("		Aluminium items: %d\n", aluquant);
			printf("		Price: %.2f Euros\n\n", alusum);
		}
		if(type4==1)
		{
			printf("		Plastic items: %d\n", plasticquant);
			printf("		Price: %.2f Euros\n\n", plasticsum);
		}
		if(type5==1)
		{
			printf("		Cloth items: %d\n", clothquant);
			printf("		Price: %.2f Euros\n\n", clothsum);
		}	
	
		printf(		"TOTAL PRICE: %.2f Euros\n\n", sum);
		printf(		"Enter \"ok\" if everything is right or whatever else if not:\n");
		scanf("%s", agreement);
	}
	while(strcmp(agreement,"ok")!=0);
	system("cls");
	printf("Thanks for being eco-friendly. Here is your recycling receipt:\n");
	printf("**********************************************************************************\n");
	printf("		Money Method: %s\n\n\n", method);
		if(type1=1)
		{
			printf("		Product type recycled:Paper - Quantity: %d\n", paperquant);
			printf("		Price: %.2f Euros\n\n", papersum);
		}
		if(type2==1)
		{
			printf("		Product type recycled:Glass - Quantity: %d\n", glassquant);
			printf("		Price: %.2f Euros\n\n", glasssum);
		}
		if(type3==1)
		{
			printf("		Product type recycled:Aluminium - Quantity: %d\n", aluquant);
			printf("		Price: %.2f Euros\n\n", alusum);
		}
		if(type4==1)
		{
			printf("		Product type recycled: Plastic - Quantity: %d\n", plasticquant);
			printf("		Price: %.2f Euros\n\n", plasticsum);
		}
		if(type5==1)
		{
			printf("		Product type recycled: Cloth - Quantity: %d\n", clothquant);
			printf("		Price: %.2f Euros\n\n", clothsum);
		}	
		if(bonusresult==1) 
		{
			printf("		TOTAL PRICE: %.2f + %.2f Euros \n", sum, bonus);
			printf("		REFUNDED PRICE: %.2f\n", amount);
		}
		else if(bonusresult==2)
		{
			printf("		TOTAL PRICE: %.2f - %.2f Euros\n", sum, bonus);
			printf("		REFUNDED PRICE: %.2f\n", amount);
		}
		else
		{
			printf("		TOTAL PRICE: %.2f Euros\n", sum);
			printf("		REFUNDED PRICE: %.2f Euros\n", amount);
		}
		printf("**********************************************************************************\n");
		return 0;
				
	}

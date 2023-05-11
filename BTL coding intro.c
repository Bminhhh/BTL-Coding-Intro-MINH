#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define size 100

//declare global variable
int baseHP1, baseHP2, wp1, wp2, ground;
float realHP1,realHP2;
float result;

//input Data
int input(){
//	printf("Input baseHP1: ");
	scanf("%d", &baseHP1);
//	printf("Input wp1: ");
	scanf("%d", &wp1);
//	printf("Input baseHP2: ");
	scanf("%d", &baseHP2);
//	printf("Input wp2: ");
	scanf("%d", &wp2);	
//	printf("Input groud: ");
	scanf("%d", &ground);	
	
	//Conditions
	if (baseHP1 < 99 || baseHP1 > 999)
		return 1;
	if (wp1 < 0 || wp1 > 3)
		return 1;
	if (baseHP2 < 1 || baseHP2 > 888)
		return 1;
	if (wp2 < 0 || wp2 > 3)
		return 1;
	if (ground < 1 || ground > 999)
		return 1;	
}

int primeCheck(int n){
	int count = 0;
	if( n < 2 ) return 0;
	for(int i = 2; i <= sqrt(n); i++){
		if( n % i == 0) count++;
	}
	
	if(count > 0) return 0;
	
	return 1;
}

	
//find closest fabonaci
int find_nearest_fibonacci(int n) {
      int a = 1, b = 1, c;
      //a<b -> stop when n is between 2 nearest fibonacci number a and b
      while (b < n) {
          c = a + b;
          a = b;
          b = c;
      }
      if (abs(n - a) < abs(n - b)) {
          return a;
      } else {
          return b;
      }
  }


//Check fibonaci or not
int isFibonacci(int n) {
    int a = 0, b = 1, c = 1;
    while (c < n) {
        c = a + b;
        a = b;
        b = c;
    }
    if (c == n) {
        return 1;
    } else {
        return 0;
    }
}


//Check perfect number
int isPerfectNumber(int n){
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    if (n == sum) {
        return 1;
    } else {
        return 0;
    }
}

//find max in array
int maxArray(int a[], int n){
	int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}



//count so luong ki tu in string
int countCharacter(char a[]){
	int countCharacter = 0;
	for (int i = 0; a[i] != '\0'; i++){
		countCharacter++;
	}
	return countCharacter;
}



//so sanh 2 chuoi ki tu 
int isEqualString(char a[], const char *b[]){
	if(strstr(a,*b) != NULL) return 1;
	return 0;
}



//find max element in arrray
int maxElementPosition(int a[], int n){
	int max = a[0];
	int position = 0;
	for(int i = 0; i < n; i++){
		if(max < a[i]){
			max = a[i];
			position = i;
		}		
	}
	
	return position;
}



//find max element in total array 
int maxElement(int a[], int n){
	int max = a[0];
	int position = 0;
	for(int i = 0; i < n; i++){
		if(max < a[i]){
			max = a[i];
		}		
	}
	
	return max;
}


//wp1 machine
void wp1Machine(){
	if(wp1 >= 0){
		//machine 1 circle table knight
		switch(wp1)
		{
			case 0:
				realHP1 = baseHP1/10;
				if(ground == baseHP1)
				{
					realHP1 = 1.1*realHP1;
				}
				if(realHP1 > 999) realHP1 = 999;
				break;
			case 1:
				realHP1 = baseHP1;
				if(ground == baseHP1)
				{
					realHP1 = 1.1*realHP1;
				}
				if(realHP1 > 999) realHP1 = 999;
				break;
			case 2:
				realHP1 = baseHP1;
				if(ground == baseHP1)
				{
					realHP1 = 1.1*realHP1;
				}
				if(realHP1 > 999) realHP1 = 999;
				break;
			case 3:
				realHP1 = 2*baseHP1;
				if(ground == baseHP1)
				{
					realHP1 = 2*1.1*baseHP1;
				}
				if(realHP1 > 999) realHP1 = 999;
				break;
			default:
				break;
		}
	}
}



void wp2Machine()
{
	if(wp2 >= 0)
	{
		switch(wp2)
		{
			case 0:
				realHP2 = baseHP2/10;
				if(ground == baseHP2)
				{
					realHP2 = 1.1*realHP2;
				}
				if(realHP2 > 999) realHP2 = 999;
				break;	
			case 1:
				realHP2 = baseHP2;
				if(ground == baseHP2)
				{
					realHP2 = 1.1*realHP2;
				}
				if(realHP2 > 999) realHP2 = 999;
				break;
			case 2:
				realHP2 = baseHP2;
				if(ground == baseHP2)
				{
					realHP2 = 1.1*realHP2;
				}
				if(realHP2 > 999) realHP2 = 999;
				break;
			case 3:
				realHP2 = baseHP2;
				if(ground == baseHP2)
				{
					realHP2 = 1.1*realHP2;
				}
				if(realHP2 > 999) realHP2 = 999;
				break;
			default:
				break;
		}
	}
}



//Mostimportant Condition
void baseCondition(){
	//Condition 6
	if(baseHP1 == 999) result = 1;
	
	//Condition 7
	if(baseHP2 == 888 && baseHP1 != 999) result = 0; 
	
	//Condition 8
	if( (baseHP2 != 888 && primeCheck(baseHP1) && primeCheck(baseHP2) != 1) || (primeCheck(baseHP1) && primeCheck(baseHP2) && baseHP1 > baseHP2)) result = 0.99;
	if( (baseHP1 != 999 && primeCheck(baseHP2) && primeCheck(baseHP1) != 1) || (primeCheck(baseHP1) && primeCheck(baseHP2) && baseHP1 < baseHP2)) result = 0.01;
	if( primeCheck(baseHP1) && primeCheck(baseHP2) && baseHP1 == baseHP2) result = 0.5;

	

	
}


//Both weapon machine
void weaponMachine(){

			//machine 1 circle table knight
			wp1Machine();
				
			//machine 2 Saxor
			wp2Machine();
		
		// Machine dk 4 && 5
		if(wp1 == 2 && realHP1 <= realHP2) result = 0.5; 
		else if(wp2 == 2 && realHP2 <= realHP1 && wp1 != 3) result = 0.5;	
	
	//Machine dk 1,2,3
		else result = (realHP1-realHP2+999)/2000;
}


//Ground conditions

void groundMachine(){
	weaponMachine();
	switch(ground)
	{
		case 666:    //Condition 9
			if(isFibonacci(baseHP1) == 1 && isFibonacci(baseHP2) == 1 )
			{
				realHP1 = baseHP1;
				realHP2 = baseHP2;	
			}	
			if(isFibonacci(baseHP1) == 1 && isFibonacci(baseHP2) != 1 )
			{
				realHP1 = baseHP1;
				realHP2 = find_nearest_fibonacci(baseHP2);	
			}
			if(isFibonacci(baseHP1) != 1 && isFibonacci(baseHP2) == 1 )
			{
				realHP1 = find_nearest_fibonacci(baseHP1);
				realHP2 = baseHP2;	
			}
			if(isFibonacci(baseHP1) != 1 && isFibonacci(baseHP2) != 1 )
			{
				realHP1 = find_nearest_fibonacci(baseHP1);
				realHP2 = find_nearest_fibonacci(baseHP2);	
			}
			
			
			if(ground == baseHP1)
					{
						realHP1 = 1.1*realHP1;
					}
					if(realHP1 > 999) realHP1 = 999;
			
			if(ground == baseHP2)
					{
						realHP2 = 1.1*realHP2;
					}
					if(realHP2 > 999) realHP2 = 999;
			
			break;
		
		//Condition 10
		case 777:;					// ; here to fix error a label can only be part of a statement( la loi kh ddc declare sau label nnghia la sau xxx:
			int godWeapon[size], total[size], compatipleWeapon[size], maxCompatipleWeapon, n;
			int countCompatipleAmount = 0;
			scanf("%d", &n);
			
			//input power of each godweapon
			for(int i = 0; i < n; i++){
				scanf("%d", &godWeapon[i]);
			}
			
			
			//find total power 
			for(int i = 0; i < n; i++){
				total[i] = baseHP2 + godWeapon[i];
			}
			
			//find compatible weapon 
			for(int i = 0; i < n; i++){
				if(isPerfectNumber(total[i]))
				{
					countCompatipleAmount++;
					int temp = 0;
					compatipleWeapon[temp] = total[i];
					temp++;
				}
			}
			
			//chia case cua compatible weapon
			if(countCompatipleAmount == 1) 
			{
				realHP2 = compatipleWeapon[0];
				wp1Machine();
			}else if(countCompatipleAmount >= 2){
				realHP2 = maxArray(compatipleWeapon, countCompatipleAmount);
				wp1Machine();
			}else{
				weaponMachine();
			}			
			break;
			
		case 888:;  //condition 11
			int knightPower[size][size];
			int sumCol[size];
			int sumRow[size];
			int zeusPower = 5000;
			int row;
			scanf("%d", &row); 
//			scanf("%d", &col);
			
			for(int i = 0; i < row; i++){
				for(int j = 0;  j< row; j++){
//					printf("Phan tu knightPower[%d][%d] cua mang la: ", i,j);
					scanf("%d", &knightPower[i][j]);
				}
			}

			//khoi tao gia tri cho sumCol = 0
			for(int i = 0; i < row; i++){
				sumCol[i] = 0;
			}
			
			
			//Tinh tong trong 1 cot voi n hang
			for(int j = 0; j < row; j++){
				for(int i = 0;  i < row; i++){
					sumCol[j] += knightPower[i][j];
				}
			}
			
			
			
			//khoi tao gia tri cho sumRow = 0 
			for(int i = 0; i < row; i++){
				sumRow[i] = 0;
			}
	
			//Tinh tong trong 1 hang voi n cot
			for(int i = 0; i < row; i++){
				for(int j = 0;  j < row; j++){
					sumRow[i] += knightPower[i][j];
				}
			}
			
			
			int maxColPosition = maxElementPosition(sumCol, row);
			int maxRowPosition = maxElementPosition(sumRow, row);
			
			
			int maxCol = maxElement(sumCol, row);
			int maxRow = maxElement(sumRow ,row);
			
			
			//Tong succ manh minus repeated element
			int finalTotalPower = maxCol + maxRow - knightPower[maxRowPosition][maxColPosition];
			
			if(wp1 == 0){
				baseHP1 /= 10;
			}
			//Zeus lose
			if(finalTotalPower > zeusPower){
				 realHP1 = 2*baseHP1;
				if(ground == baseHP1)
				{
					realHP1 = 2*1.1*baseHP1;
				}
				if(realHP1 > 999) realHP1 = 999;
				wp2Machine();	
			}else{
				weaponMachine();
			}
			break;
	
			
		case 999:;   //condition 12
//			weaponMachine();
		wp1Machine();
		wp2Machine();
			char thanchu[size]; 
			const char *example[] = {"Arthur", "arthur"};
			char saxon[] = {'s','a','x','o','n'};
			
			//Morgana doc than chu
			scanf("%s", thanchu);
		
			int countEqual = 0;
			for(int i = 0; i < 2; i++){
				if(isEqualString(thanchu,example)){
					countEqual++;
				}
			}
			if(countEqual > 0){ //&& wp1 == 3){
				wp1 = 0;
				wp1Machine();

			
			//second request in condtion 12
			if(countCharacter(thanchu) > 8){
//				wp1Machine();
				realHP1 -= 50;
				if(realHP1 < 1) realHP1 = 1;	
			}
			
			//third request in condition 12
			int countRepeat = 0;
			for(int i = 0; thanchu[i] != '\0'; i++){
				for(int j = 0; saxon[j] != '\0'; j++){
					if(thanchu[i] == saxon[j]){
						countRepeat++;
					}
				}
			}
					
			
			if(countRepeat > 3){
//				wp2Machine();
				realHP2 += 50;
				if(realHP2 > 888) realHP2 = 888;
			}

			
			
			//Fourth request in condition 12
			
			break;
		
		default:
			break;
	}
	result = (realHP1-realHP2+999)/2000;
}


//weapon Case Machine
void conditionMachine()
{
	
	//Condition 6,7,8
	if(baseHP1 == 999 || baseHP2 == 888 || primeCheck(baseHP1) || primeCheck(baseHP2)){
		baseCondition();
	}
	
	
	else if((ground == 666 || ground == 777 || ground == 888 || ground == 999)){//&&(baseHP1 != 999 || baseHP2 != 888 || primeCheck(baseHP1) != 1 || primeCheck(baseHP2) != 1)){
		groundMachine();
	}
	
	
	//Condition 1 -> 5
	else //if(baseHP1 != 999 && baseHP2 != 888 && primeCheck(baseHP1) != 1 && primeCheck(baseHP2) != 1 )
	{
		weaponMachine();
	}
}


//P(r) Winning ability of the Circle table knight
float winPossibility(){		
	
	//Call the machine
	conditionMachine();
	
//	groundMachine();
	
	
	return result;
}


//display value of fOut in format of 0.XX
void display(int wp1, int wp2, int baseHP1, int baseHP2, int ground)
{	
	
	//Gan' Kq vào Out variable
	float out = winPossibility();
	
	
	//display kq
	if (out == 1){
		printf("1");
	}
	else{
		printf("%.2f",out);
	}
}



int main(void)
{
	//read data from input to corresponding variables
	input();


	//write your code here	
	display(wp1,wp2,baseHP1,baseHP2,ground);
	

	
	return 0;
}

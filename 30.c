#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int My_Turn(int Number);

int main()
{
	int i, Number = 0, Turn = 20, flag;  //Turn 이 1 이면 내 차례 2 면 컴퓨터 차례

printf("30을 먼저 부르는 사람이 패배하게 됩니다.\n");
printf("먼저 숫자를 부를 사람을 정하시오.\n1을 입력하면Gamer가 먼저 합니다.\n2를 입력하면Computer가 먼저 합니다.\n차례를 설정해주세요:");

scanf("%d",&Turn);

srand((long)time(NULL));

while (Turn != 1 && Turn != 2) 
{

	printf("설정된 숫자가 아닙니다. 다시 입력해주세요.\n1을 입력하면 Gamer가 먼저 합니다.\n2를 입력하면 Computer가 먼저 합니다.\n차례 입력:");
	scanf("%d", &Turn);
}


while (1)
{
	if (Turn == 1)  //내 차례
	{
		Number = My_Turn(Number);
		printf("입력하신 숫자는 %d입니다.\n", Number);
		if (Number == 30) 
		{ 
			flag = 1; 
			break; 
		}
		Turn = 2;

	}
	
	if (Turn == 2)// 컴퓨터 차례
	{
		if (Number >= 26 && Number <29) Number = 29;
		else if (Number == 29) Number = 30;
		else Number += rand()%3+1;
		
		printf("컴퓨터의 숫자는 %d입니다.\n", Number);
		if (Number == 30) 
		{
			flag = 2; 
			break;
		}

		Turn = 1;

	}
}


if (flag == 1) printf("컴퓨터의 승리! 당신은 패배하였습니다.");
if (flag == 2) printf("게이머의 승리! 당신은 승리하였습니다.");


return 0;
}



int My_Turn(int Number)
{
	int i;
	i = Number;
	
	printf("숫자를 입력해주세요:");
	scanf("%d", &Number);
	while (1)
	{
		if (i >= Number)
		{
			printf("숫자 %d 에서 더 큰 숫자를 입력해주세요:", i);
			scanf("%d", &Number);
		}

		else if (Number > (i + 3))
		{
			printf("숫자 %d 에서 1~3까지 더한 숫자를 입력해주세요:", i);
			scanf("%d", &Number);
		}
		
		else if (Number > 30)
		{
			printf("숫자 %d 에서 1~3까지 더한 숫자를 입력해주세요:", i);
			scanf("%d", &Number);
		}
		else if (Number <= (i + 3) && i < Number) return Number;
	}

}
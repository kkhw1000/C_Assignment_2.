#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int My_Turn(int Number);

int main()
{
	int i, Number = 0, Turn = 20, flag;  //Turn �� 1 �̸� �� ���� 2 �� ��ǻ�� ����

printf("30�� ���� �θ��� ����� �й��ϰ� �˴ϴ�.\n");
printf("���� ���ڸ� �θ� ����� ���Ͻÿ�.\n1�� �Է��ϸ�Gamer�� ���� �մϴ�.\n2�� �Է��ϸ�Computer�� ���� �մϴ�.\n���ʸ� �������ּ���:");

scanf("%d",&Turn);

srand((long)time(NULL));

while (Turn != 1 && Turn != 2) 
{

	printf("������ ���ڰ� �ƴմϴ�. �ٽ� �Է����ּ���.\n1�� �Է��ϸ� Gamer�� ���� �մϴ�.\n2�� �Է��ϸ� Computer�� ���� �մϴ�.\n���� �Է�:");
	scanf("%d", &Turn);
}


while (1)
{
	if (Turn == 1)  //�� ����
	{
		Number = My_Turn(Number);
		printf("�Է��Ͻ� ���ڴ� %d�Դϴ�.\n", Number);
		if (Number == 30) 
		{ 
			flag = 1; 
			break; 
		}
		Turn = 2;

	}
	
	if (Turn == 2)// ��ǻ�� ����
	{
		if (Number >= 26 && Number <29) Number = 29;
		else if (Number == 29) Number = 30;
		else Number += rand()%3+1;
		
		printf("��ǻ���� ���ڴ� %d�Դϴ�.\n", Number);
		if (Number == 30) 
		{
			flag = 2; 
			break;
		}

		Turn = 1;

	}
}


if (flag == 1) printf("��ǻ���� �¸�! ����� �й��Ͽ����ϴ�.");
if (flag == 2) printf("���̸��� �¸�! ����� �¸��Ͽ����ϴ�.");


return 0;
}



int My_Turn(int Number)
{
	int i;
	i = Number;
	
	printf("���ڸ� �Է����ּ���:");
	scanf("%d", &Number);
	while (1)
	{
		if (i >= Number)
		{
			printf("���� %d ���� �� ū ���ڸ� �Է����ּ���:", i);
			scanf("%d", &Number);
		}

		else if (Number > (i + 3))
		{
			printf("���� %d ���� 1~3���� ���� ���ڸ� �Է����ּ���:", i);
			scanf("%d", &Number);
		}
		
		else if (Number > 30)
		{
			printf("���� %d ���� 1~3���� ���� ���ڸ� �Է����ּ���:", i);
			scanf("%d", &Number);
		}
		else if (Number <= (i + 3) && i < Number) return Number;
	}

}
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int lever;   //�ܸ�
	int zhang;   //�������� ��bitgetƽ̨1��Ϊ0.1ETH 
	int direction;  //���򣬶໹�ǿ� 
	float pr[6];   //��¼ӯ��10%��20%��30%��40%��50%��60%ʱ�Ľ�� 
	float po[6];   //��¼ӯ��10%��20%��30%��40%��50%��60%ʱ��ƽ�ּ۸�
	float principal;  //ȫ�ֱ��� 
	float position;  // ��֤�𣻱�֤�� = ���ɽ����� * ���� * ÿ�ż۸�/ �ܸ� 
	float position_1,position_2;   //�ֱ�Ϊ���ֺ�ƽ�ּ۸� �������� = ��ǰ�۸� * ���� * ʮ���֮4 
	                               //ƽ��������ĿǰΪʮ���֮6 
//�ֲֳɱ�������һ������۸���ֲ��������Ӳ�ʱ�۸���Ӳֵ�������������һ�γֲ��������Ӳ�������

	printf("��������������ֹ���λ\n\n");
	printf("�����뷽��(1Ϊ�࣬0Ϊ��) ��");
	scanf("%d",&direction);
	printf("������ܸˣ�");
	scanf("%d",&lever); 
	printf("�����뿪�ּ۸� ��");
	scanf("%f",&position_1);
	printf("������������");
	scanf("%d",&zhang);
	printf("�����뱾��");
	scanf("%f",&principal);
	
    if (direction == 1) //��ͷ 
	{
		pr[0] = -principal * 0.1;  //ӯ��Ϊ�����10%ʱ�Ľ�� 
	    pr[1] = -principal * 0.2;
        pr[2] = -principal * 0.3;
	    pr[3] = -principal * 0.4;
	    pr[4] = -principal * 0.5;
	    pr[5] = -principal * 0.6;
	}
	
	if (direction == 0) //��ͷ 
	{
		pr[0] = principal * 0.1;  //ӯ��Ϊ�����10%ʱ�Ľ�� 
	    pr[1] = principal * 0.2;
        pr[2] = principal * 0.3;
	    pr[3] = principal * 0.4;
	    pr[4] = principal * 0.5;
	    pr[5] = principal * 0.6;
	}	
		
	po[0] = pr[0] / (zhang * 0.1) + position_1; //ӯ��Ϊ�����10%ʱ��ƽ�ּ۸� 
	po[1] = pr[1] / (zhang * 0.1) + position_1;
	po[2] = pr[2] / (zhang * 0.1) + position_1;
	po[3] = pr[3] / (zhang * 0.1) + position_1;
	po[4] = pr[4] / (zhang * 0.1) + position_1;
	po[5] = pr[5] / (zhang * 0.1) + position_1; 
	//Դ��ʽΪ��ӯ�� = ��ȫƽ�� - ���ּۣ�* ���� * ÿ�ż� 

    position = (position_1 * zhang * 0.1) / lever; 

    int i;
    printf("\n");
    printf("��ǰ��֤��Ϊ��%0.8f\n",position);
	if (direction == 1)
	{	
		for (i=0;i<6;i++)
		  printf("�����𱾽��%d0%%ʱ��ƽ�ּ۸�Ϊ��%7.2f����ʱӯ����%12.8f�������ʣ�%7.2f%%\n",i+1,po[i],pr[i],(pr[i] / position) * 100);
	}
	if (direction == 0)
	{
		for (i=0;i<6;i++)
	 	  printf("�����𱾽��%d0%%ʱ��ƽ�ּ۸�Ϊ��%7.2f����ʱӯ����%12.8f�������ʣ�%7.2f%%\n",i+1,po[i],-pr[i],(-pr[i] / position) * 100);
	}
	 
    printf("\n������ؿ�����30%%���ڣ���\n\n");
	system("pause");
	return 0; 
}

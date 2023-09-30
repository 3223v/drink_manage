#include"sdu.h"
void userlogin()
{
	cleanscreen();
	char name[20],password[15];
	printf("�������û���(����0�˳�)\n");
	scanf("%s",name);getchar();
	sef* p=userp->next;
	bool flag=false;
	while(1)
	{
		if (strcmp(name, "0") == 0) welcome();
		p = userp->next;
		for(int i=0;i<usernum;i++)
		{
			if(strcmp(p->usname,name)==0)
			{
				flag=true;
				break;
			}
			p=p->next;
		}
		if(flag) break;
		else {
			printf("�����ڴ��û���������������(����0�˳�)\n");
			scanf("%s",name);getchar();
		}
	}
	printf("����������(����0�˳�)\n");
	scanf("%s",password);getchar();
	if (strcmp(name, "0") == 0) welcome();
	while(strcmp(p->password1,password)!=0)
	{
		printf("�����������������(����0�˳�)\n");
		scanf("%s",password);getchar();
		if (strcmp(password, "0") == 0) welcome();
	}
	printf("��¼�ɹ�\n");
	if(p->ordernum==0) p->ordernum=1;
	Sleep(1000);
	usermeue(p);
}
void userregesiter()
{
	cleanscreen();
	sef* p = userp;
	while (p->next) p = p->next;
	p->next = (sef*)malloc(sizeof(sef));//�����û�������
	p = p->next;
	p->next = 0;
	char name[20];
	printf("�������û�����������Ӣ�ĺ����֣�\n");
	scanf("%s", name); getchar();
	while (1)
	{
		bool flag = false;              //�ж��û����Ƿ�淶
		while (!flag)
		{
			int k = strlen(name);
			for (int i = 0; i < k; i++)
			{
				if (!isalnum(name[i]))
				{
					printf("�û������淶������������\n");
					break;
				}
				if (i == k - 1)flag = true;
			}
			if (flag == true) break;
			else scanf("%s", name); getchar();
		}
		sef* p0 = userp->next;
		int i;
		for (i = 0; i < usernum; i++)
		{
			if (strcmp(p0->usname, name) == 0)//�ж��û����Ƿ��ظ�
			{
				printf("�û����ظ�������������\n");
				scanf("%s", name); getchar();
				break;
			}
			p0 = p0->next;
		}
		if (i >= usernum) break;
	}
	strcpy(p->usname, name);
	char password[15];
	printf("����������\n");
	scanf("%s", password); getchar();
	strcpy(p->password1, password);
	printf("���ٴ�������ȷ������\n");
	scanf("%s", password); getchar();
	while (strcmp(password, p->password1) != 0)
	{
		printf("�������벻һ�£����ٴ�����\n");
		scanf("%s", password); getchar();
	}
	printf("���ѳɹ�ע��\n");
	//��ʼ���û���Ϣ
	p->vip = 0; usernum++; p->bill = 0; p->ordernum = 1;
	for (int i = 0; i < 100; i++)
	{
		p->orders[i].sumsell = 0;
		for (int j = 0; j < 20; j++)
		{
			p->orders[i].beer[j] = 0;
			p->orders[i].liquor[j] = 0;
			p->orders[i].drinks[j] = 0;
		}
	}
	Sleep(1000);
	filesave();
	welcome();
}

void changepassword(sef* head)
{
	cleanscreen();
	printf("������ԭ����(����0�˳�)\n");
	char password[15];
	scanf("%s", password); getchar();
	while (strcmp(password, head->password1) != 0)//�ж������Ƿ���ȷ
	{
		if (strcmp(password, "0") == 0) usermeue(head);
		printf("�����������������(����0�˳�)\n");
		scanf("%s", password); getchar();
	}
	printf("������������(����0�˳�)\n");
	scanf("%s", head->password1); getchar();
	if (strcmp(password, "0") == 0) usermeue(head);
	printf("�޸�����ɹ�");
	filesave();
	Sleep(1000);
	usermeue(head);
}

void usermeue(sef* head)
{
	cleanscreen();
	int num;
	printf("*************************************************\n");
	if (head->vip == 0)
		printf("*\t\t�𾴵��û�%s\t\t\t*\n", head->usname);
	else if (head->vip == 1)
		printf("*\t\t�𾴵Ļ�Ա%s\t\t*\n", head->usname);
	else printf("*\t\t�𾴵������Ա%s\t\t*\n", head->usname);
	printf("*************************************************\n");
	printf("*\t\t��ѡ�����б�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.��ˮ����\t\t\t*\n");
	printf("*\t\t2.��ѯ����\t\t\t*\n");
	printf("*\t\t3.�˻�����\t\t\t*\n");
	printf("*\t\t4.�޸�����\t\t\t*\n");
	printf("*\t\t5.�˳�ϵͳ\t\t\t*\n");
	printf("*\t\t6.ע���˺�\t\t\t*\n");
	printf("*************************************************\n");
	printf("\n");
	while (1)
	{
		scanf("%d", &num);
		getchar();
		switch (num)
		{
		case 1:
			userbuy(head);
			break;
		case 2:
			usercheck(head);
			break;
		case 3:
			userchange(head);
			break;
		case 4:
			changepassword(head);
			break;
		case 5:
			welcome();
		case 6:
			deleteuser(head);
			break;
		}
	}
}

void userbuy(sef* head)
{
	cleanscreen();
	printf("*************************************************\n");
	printf("*\t\t��ˮ�����˵�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t��ѡ���б�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.ơ��    \t\t\t*\n");
	printf("*\t\t2.�׾�    \t\t\t*\n");
	printf("*\t\t3.��Ʒ    \t\t\t*\n");
	printf("*\t\t4.�ύ����\t\t\t*\n");
	printf("*************************************************\n");
	printf("���ζ�������%dԪ\n", head->orders[head->ordernum].sumsell);
	int num;
	scanf("%d", &num); getchar();
	while (num > 4)
	{
		scanf("%d", &num); getchar();
	}
	if (num == 1)//ơ�ƹ������
	{
		bef* p = beerp->next;
		printf("********************************************************************************************\n");
		printf(" **\t\t\t\t\t\tơ��\t\t\t\t\t**\n");
		printf("********************************************************************************************\n");
		printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "�ƾ���(%Vol)", "���(ƿ)", "�۸�");
		for (int i = 0; i < beernum; i++)
		{
			printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p->name, p->capacity, p->alcohol, p->specs, p->value);
			p = p->next;
		}
		printf("\n\n");
		while (1)
		{
			printf("��������Ҫ����ľ�ˮ���(����0�˳�)\n");
			int num;
			scanf("%d", &num); getchar();
			while (num > beernum)
			{
				scanf("%d", &num); getchar();
			}
			bef* p1 = beerp;
			if (num == 0) userbuy(head);
			printf("�����빺������\n");
			int n;
			scanf("%d", &n); getchar();
			for (int i = 0; i < num; i++) p1 = p1->next;
			while (p1->num < n)
			{
				printf("��治�㣬����������\n");
				scanf("%d", &n), getchar();
			}
			p1->num = p1->num - n;//��ˮ������Ӧ����
			p1->soldout += n;//��ˮ������
			head->orders[head->ordernum].beer[num] += n;//��¼��ˮ����
			if (head->vip == 0)
				head->orders[head->ordernum].sumsell += p1->value * n;//��¼�������
			else if (head->vip == 1)
				head->orders[head->ordernum].sumsell += p1->value * n * 0.9;
			else head->orders[head->ordernum].sumsell += p1->value * n * 0.8;
			filesave();
		}
	}
	if (num == 2)//�׾ƹ������
	{
		lef* p = liquorp->next;
		printf("********************************************************************************************\n");
		printf(" **\t\t\t\t\t\t�׾�\t\t\t\t\t**\n");
		printf("********************************************************************************************\n");
		printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "�ƾ���(%Vol)", "���(ƿ)", "�۸�");
		for (int i = 0; i < liquornum; i++)
		{
			printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p->name, p->capacity, p->alcohol, p->specs, p->value);
			p = p->next;
		}
		printf("\n\n");
		while (1)
		{
			printf("��������Ҫ����ľ�ˮ���(����0�˳�)\n");
			int num;
			scanf("%d", &num); getchar();
			while (num > liquornum)
			{
				scanf("%d", &num); getchar();
			}
			lef* p1 = liquorp;
			if (num == 0) userbuy(head);
			printf("�����빺������\n");
			int n;
			scanf("%d", &n); getchar();
			for (int i = 0; i < num; i++) p1 = p1->next;
			while (p1->num < n)
			{
				printf("��治�㣬����������\n");
				scanf("%d", &n), getchar();
			}
			p1->num = p1->num - n;
			p1->soldout += n;
			head->orders[head->ordernum].liquor[num] += n;
			if (head->vip == 0)
				head->orders[head->ordernum].sumsell += p1->value * n;
			else if (head->vip == 1)
				head->orders[head->ordernum].sumsell += p1->value * n * 0.9;
			else head->orders[head->ordernum].sumsell += p1->value * n * 0.8;
			filesave();
		}
	}
	if (num == 3)
	{
		def* p = drinksp->next;
		printf("********************************************************************************************\n");
		printf(" **\t\t\t\t\t\t��Ʒ\t\t\t\t\t**\n");
		printf("********************************************************************************************\n");
		printf("%-20s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "���(ƿ)", "�۸�");
		for (int i = 0; i < drinksnum; i++)
		{
			printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t\n", i + 1, p->name, p->capacity, p->specs, p->value);
			p = p->next;
		}
		printf("\n\n");
		while (1)
		{
			printf("��������Ҫ����ľ�ˮ���(����0�˳�)\n");
			int num;
			scanf("%d", &num); getchar();
			while (num > drinksnum)
			{
				scanf("%d", &num); getchar();
			}
			def* p1 = drinksp;
			if (num == 0) userbuy(head);
			printf("�����빺������\n");
			int n;
			scanf("%d", &n); getchar();
			for (int i = 0; i < num; i++) p1 = p1->next;
			while (p1->num < n)
			{
				printf("��治�㣬����������\n");
				scanf("%d", &n), getchar();
			}
			p1->num = p1->num - n;
			p1->soldout += n;
			head->orders[head->ordernum].drinks[num] += n;
			if (head->vip == 0)
				head->orders[head->ordernum].sumsell += p1->value * n;
			else if (head->vip == 1)
				head->orders[head->ordernum].sumsell += p1->value * n * 0.9;
			else head->orders[head->ordernum].sumsell += p1->value * n * 0.8;
			filesave();
		}
	}
	if (num == 4)
	{
		head->bill += head->orders[head->ordernum].sumsell;//�û������ܽ��
		head->orders[head->ordernum].flag = 1;//��ʼ����δ�鿴
		head->ordernum++;//�û�������1
		ordersnum++;//�¶�����1
		if (head->bill >= 1000000) head->vip = 1;//�ж��û��ȼ�
		if (head->bill >= 10000000) head->vip = 2;
		filesave();
		usermeue(head);
	}
}

void usercheck(sef* head)
{
	cleanscreen();
	printf("*************************************************\n");
	printf("*\t\t����%d�ʶ���\t\t\t*\n", head->ordernum - 1);
	printf("*************************************************\n");
	printf("*\t\t��ѡ�����鿴�Ķ������\t\t*\n");
	printf("*************************************************\n");
	for (int i = 1; i < head->ordernum; i++)
	{
		int beernum = 0, liquornum = 0, drinksnum = 0;
		for (int j = 0; j < 20; j++)
		{
			if (head->orders[i].beer[j]) beernum++;
			if (head->orders[i].liquor[j]) liquornum++;
			if (head->orders[i].drinks[j]) drinksnum++;
		}
		printf("%d.��������%d��ơ��%d�ְ׾�%d����Ʒ\t���ƽ��%dԪ\n", i, beernum, liquornum, drinksnum, head->orders[i].sumsell);
	}
	printf("*\t\t����0�˳�\t\t\t*\n");
	printf("*************************************************\n");
	int num;
	scanf("%d", &num); getchar();
	if (num == 0) usermeue(head);
	while (num > head->ordernum)
	{
		scanf("%d", &num); getchar();
	}
	int i, number = 0;
	printf("***********************************************************\n");
	//������嶩��
	for (i = 0; i < 20; i++)
	{
		bef* p = beerp->next;
		if (head->orders[num].beer[i])
		{
			number++;
			for (int j = 0; j < i - 1; j++) p = p->next;
			printf("%d.%-20s\t%dml\t%d��\t%dƿ\t%d��\t%dԪ\t\n", number, p->name, p->capacity, p->alcohol, p->specs, head->orders[num].beer[i], head->orders[num].beer[i] * p->value);
		}
	}
	for (i = 0; i < 20; i++)
	{
		lef* p1 = liquorp->next;
		if (head->orders[num].liquor[i])
		{
			number++;
			for (int j = 0; j < i - 1; j++) p1 = p1->next;
			printf("%d.%-20s\t%dml\t%d��\t%dƿ\t%d��\t%dԪ\t\n", number, p1->name, p1->capacity, p1->alcohol, p1->specs, head->orders[num].liquor[i], head->orders[num].liquor[i] * p1->value);
		}
	}
	for (i = 0; i < 20; i++)
	{
		def* p2 = drinksp->next;
		if (head->orders[num].drinks[i])
		{
			number++;
			for (int j = 0; j < i - 1; j++) p2 = p2->next;
			printf("%d.%-20s\t%dml\t%dƿ\t%d��\t%dԪ\t\n", number, p2->name, p2->capacity, p2->specs, head->orders[num].drinks[i], head->orders[num].drinks[i] * p2->value);
		}
	}
	printf("\n1.�����鿴       2.�˳�");
	int n; scanf("%d", &n); getchar();
	while (n != 1 && n != 2) { scanf("%d", &n); getchar(); }
	if (n == 1) usercheck(head);
	else usermeue(head);
}

void userchange(sef* head)
{
	cleanscreen();
	printf("��������Ҫ�˻���������(����0�˳�)\n");
	char name[30];
	bool flag = false;
	scanf("%s", name); getchar();
	if (strcmp(name, "0") == 0) usermeue(head);
	for (int i = 1; i < head->ordernum; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			if (head->orders[i].beer[j])
			{
				bef* p = beerp->next;
				for (int k = 1; k < j; k++) p = p->next;
				if (strcmp(name, p->name) == 0)
				{
					flag = true;
					printf("�������˻�������\n");
					int num;
					scanf("%d", &num); getchar();
					while (num > head->orders[i].beer[j])
					{
						printf("���������������������������\n");
						scanf("%d", &num); getchar();
					}
					head->orders[i].beer[j] -= num;
					filesave();
					printf("�˻����ɹ�");
					Sleep(1000);
					usermeue(head);
				}
			}
			if (head->orders[i].liquor[j])
			{
				lef* p = liquorp->next;
				for (int k = 1; k < j; k++) p = p->next;
				if (strcmp(name, p->name) == 0)
				{
					flag = true;
					printf("�������˻�������\n");
					int num;
					scanf("%d", &num); getchar();
					while (num > head->orders[i].liquor[j])
					{
						printf("���������������������������\n");
						scanf("%d", &num); getchar();
					}
					head->orders[i].liquor[j] -= num;
					filesave();
					printf("�˻����ɹ�");
					Sleep(1000);
					usermeue(head);
				}
			}
			if (head->orders[i].drinks[j])
			{
				def* p = drinksp->next;
				for (int k = 1; k < j; k++) p = p->next;
				if (strcmp(name, p->name) == 0)
				{
					flag = true;
					printf("�������˻�������\n");
					int num;
					scanf("%d", &num); getchar();
					while (num > head->orders[i].drinks[j])
					{
						printf("���������������������������\n");
						scanf("%d", &num); getchar();
					}
					head->orders[i].drinks[j] -= num;
					filesave();
					printf("�˻����ɹ�");
					Sleep(1000);
					usermeue(head);
				}
			}
		}
		if (!flag) printf("δ�ҵ�����Ʒ");
		Sleep(1000);
		usermeue(head);
	}
}

void deleteuser(sef* head)
{
	printf("����������(����0�˳�)\n");
	char password[30];
	scanf("%s", password); getchar();
	while (strcmp(password, head->password1) != 0)
	{
		if (strcmp(password, "0") == 0) usermeue(head);
		printf("�����������������(����0�˳�)\n");
		scanf("%s", password); getchar();
	}
	sef* p = userp;
	while (p->next != head) p = p->next;
	p->next = p->next->next;
	delete(head);
	filesave();
	printf("ע���ɹ�");
	Sleep(1000);
	welcome();
}
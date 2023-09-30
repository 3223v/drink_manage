#include"sdu.h"
void adminmeue()
{
	cleanscreen();
	int num;
	printf("*************************************************\n");
	printf("*\t\t��ˮ��̨����ϵͳ\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t��ѡ�����б�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.�鿴���\t\t\t*\n");
	printf("*\t\t2.��ѯ�û���Ϣ\t\t\t*\n");
	printf("*\t\t3.����%d����������\t\t*\n", ordersnum);
	printf("*\t\t4.�鿴������Ϣ\t\t\t*\n");
	printf("*\t\t5.�˳�ϵͳ\t\t\t*\n");
	printf("*************************************************\n");
	printf("\n");
	while (1)
	{
		scanf("%d", &num);
		getchar();
		switch (num)
		{
		case 1:
			inventory();
			break;
		case 2:
			usermation();
			break;
		case 3:
			checkorder();
			break;
		case 4:
			checksold();
			break;
		case 5:
			welcome();
		}
	}
}

void inventory()
{
	cleanscreen();
	printf("*************************************************\n");
	printf("*\t\t��ˮ������\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t��ѡ���б�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.ơ��\t\t\t*\n");
	printf("*\t\t2.�׾�\t\t\t*\n");
	printf("*\t\t3.��Ʒ\t\t\t*\n");
	printf("*************************************************\n");
	int num;
	scanf("%d", &num); getchar();
	while (num != 1 && num != 2 && num != 3)
	{
		scanf("%d", &num); getchar();
	}
	if (num == 1)//ơ�ƿ��
	{
		bef* p = beerp->next;
		printf("********************************************************************************************\n");
		printf(" **\t\t\t\t\t\tơ��\t\t\t\t\t**\n");
		printf("********************************************************************************************\n");
		printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "�ƾ���(%Vol)", "���(ƿ)", "����(��)", "�۸�");
		for (int i = 0; i < beernum; i++)
		{
			printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p->name, p->capacity, p->alcohol, p->specs, p->num, p->value);
			p = p->next;
		}
		printf("\n\n");
		printf("\t1.��Ӿ�ˮ\t\t2.�޸�\t\t3.ɾ��\t\t4.�˳�\n");
		int n;
		while (1)
		{
			scanf("%d", &n);
			getchar();
			switch (n)
			{
			case 1:
				addbeer();
				break;
			case 2:
				changebeer();
				break;
			case 3:
				delbeer();
				break;
			case 4:
				adminmeue();
				break;
			}
		}
	}
	if (num == 2)//�׾ƿ��
	{
		lef* p = liquorp->next;
		printf("********************************************************************************************\n");
		printf(" **\t\t\t\t\t\t�׾�\t\t\t\t\t**\n");
		printf("********************************************************************************************\n");
		printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "�ƾ���(%Vol)", "���(ƿ)", "����(��)", "�۸�");
		for (int i = 0; i < liquornum; i++)
		{
			printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p->name, p->capacity, p->alcohol, p->specs, p->num, p->value);
			p = p->next;
		}
		printf("\n\n");
		printf("\t1.��Ӿ�ˮ\t\t2.�޸�\t\t3.ɾ��\t\t4.�˳�\n");
		int n;
		while (1)
		{
			scanf("%d", &n);
			getchar();
			switch (n)
			{
			case 1:
				addliquor();
				break;
			case 2:
				changeliquor();
				break;
			case 3:
				delliquor();
				break;
			case 4:
				adminmeue();
				break;
			}
		}
	}
	if (num == 3)//��Ʒ���
	{

		def* p = drinksp->next;
		printf("********************************************************************************************\n");
		printf(" **\t\t\t\t\t\t��Ʒ\t\t\t\t\t**\n");
		printf("********************************************************************************************\n");
		printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "���(ƿ)", "����(��)", "�۸�");
		for (int i = 0; i < drinksnum; i++)
		{
			printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p->name, p->capacity, p->specs, p->num, p->value);
			p = p->next;
		}
		printf("\n\n");
		printf("\t1.��Ӿ�ˮ\t\t2.�޸�\t\t3.ɾ��\t\t4.�˳�\n");
		int n;
		while (1)
		{
			scanf("%d", &n);
			getchar();
			switch (n)
			{
			case 1:
				adddrinks();
				break;
			case 2:
				changedrinks();
				break;
			case 3:
				deldrinks();
				break;
			case 4:
				adminmeue();
				break;
			}
		}
	}
}

void addbeer()//���ơ����Ϣ
{
	bef* p = beerp;
	while (p->next) p = p->next;
	p->next = (bef*)malloc(sizeof(bef)); p = p->next; p->next = 0;
	printf("�������������     ����     �ƾ���     ���     ����    �۸�\n");
	scanf("%s%d%d%d%d%d", p->name, &p->capacity, &p->alcohol, &p->specs, &p->num, &p->value); getchar();
	printf("��ӳɹ�\n"); beernum++;
	p->soldout = 0;
	filesave();
	printf("1.�������          2.����");
	int num;
	while (1)
	{
		scanf("%d", &num);
		getchar();
		switch (num)
		{
		case 1:
			addbeer();
			break;
		case 2:
			adminmeue();
			break;
		}
	}
}

void addliquor()//��Ӱ׾���Ϣ
{
	lef* p = liquorp;
	while (p->next) p = p->next;
	p->next = (lef*)malloc(sizeof(lef)); p = p->next; p->next = 0;
	printf("�������������     ����     �ƾ���     ���     ����    �۸�\n");
	scanf("%s%d%d%d%d%d", p->name, &p->capacity, &p->alcohol, &p->specs, &p->num, &p->value); getchar();
	printf("��ӳɹ�\n"); liquornum++;
	p->soldout = 0;
	filesave();
	printf("1.�������          2.����");
	int num;
	while (1)
	{
		scanf("%d", &num);
		getchar();
		switch (num)
		{
		case 1:
			addliquor();
			break;
		case 2:
			adminmeue();
			break;
		}
	}
}

void adddrinks()//�����Ʒ��Ϣ
{
	def* p = drinksp;
	while (p->next) p = p->next;
	p->next = (def*)malloc(sizeof(def)); p = p->next; p->next = 0;
	printf("�������������     ����       ���     ����    �۸�\n");
	scanf("%s%d%d%d%d", p->name, &p->capacity, &p->specs, &p->num, &p->value); getchar();
	printf("��ӳɹ�\n"); drinksnum++;
	p->soldout = 0;
	filesave();
	printf("1.�������          2.����");
	int num;
	while (1)
	{
		scanf("%d", &num);
		getchar();
		switch (num)
		{
		case 1:
			adddrinks();
			break;
		case 2:
			adminmeue();
			break;
		}
	}
}

void changebeer()//�޸�ơ����Ϣ
{
	printf("��������Ҫ�޸ĵľ�ˮ���");
	int num;
	scanf("%d", &num); getchar();
	bef* p = beerp;
	while (num--) p = p->next;
	printf("�������޸ĺ������");
	scanf("%d", &p->num);
	printf("�������޸ĺ�ļ۸�");
	scanf("%d", &p->value);
	printf("�޸ĳɹ�");
	filesave();
	Sleep(1000);
	inventory();
}

void changeliquor()//�޸İ׾���Ϣ
{
	printf("��������Ҫ�޸ĵľ�ˮ���");
	int num;
	scanf("%d", &num); getchar();
	lef* p = liquorp;
	while (num--) p = p->next;
	printf("�������޸ĺ������");
	scanf("%d", &p->num);
	printf("�������޸ĺ�ļ۸�");
	scanf("%d", &p->value);
	printf("�޸ĳɹ�");
	filesave();
	Sleep(1000);
	inventory();
}

void changedrinks()//�޸���Ʒ��Ϣ
{
	printf("��������Ҫ�޸ĵľ�ˮ���");
	int num;
	scanf("%d", &num); getchar();
	def* p = drinksp;
	while (num--) p = p->next;
	printf("�������޸ĺ������");
	scanf("%d", &p->num);
	printf("�������޸ĺ�ļ۸�");
	scanf("%d", &p->value);
	printf("�޸ĳɹ�");
	filesave();
	Sleep(1000);
	inventory();
}

void delbeer()//ɾ��ơ��
{
	printf("��������Ҫɾ���ľ�ˮ���");
	int num;
	scanf("%d", &num); getchar();
	bef* p = beerp;
	while (num > beernum);
	{
		printf("����������\n");
		scanf("%d", &num); getchar();
	}
	for (int i = 0; i < num - 1; i++)
		p = p->next;
	p->next = p->next->next;
	printf("ɾ���ɹ�");
	beernum--;
	filesave();
	Sleep(1000);
	inventory();
}

void delliquor()
{
	printf("��������Ҫɾ���ľ�ˮ���");
	int num;
	scanf("%d", &num); getchar();
	lef* p = liquorp;
	while (num > liquornum);
	{
		printf("����������\n");
		scanf("%d", &num); getchar();
	}
	for (int i = 0; i < num - 1; i++)
		p = p->next;
	p->next = p->next->next;
	printf("ɾ���ɹ�");
	liquornum--;
	filesave();
	Sleep(1000);
	inventory();
}

void deldrinks()
{
	printf("��������Ҫɾ���ľ�ˮ���");
	int num;
	scanf("%d", &num); getchar();
	def* p = drinksp;
	while (num > drinksnum);
	{
		printf("����������\n");
		scanf("%d", &num); getchar();
	}
	for (int i = 0; i < num - 1; i++)
		p = p->next;
	p->next = p->next->next;
	printf("ɾ���ɹ�");
	drinksnum--;
	filesave();
	Sleep(1000);
	inventory();
}

void usermation()//�û���Ϣ�鿴
{
	cleanscreen();
	sef* p = userp;
	printf("*************************************************\n");
	printf("*\t\t�û���Ϣ����\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t��ѡ���û�\t\t\t*\n");
	printf("*************************************************\n");
	printf("�û���\t\t\t���ѽ��\n");
	for (int i = 0, number = 0; i < usernum; i++)//�鿴�û�
	{
		p = p->next; number++;
		if (p->vip == 0)
			printf("%d.��ͨ�û�%s\t\t%d\n", number, p->usname, p->bill);
		else if (p->vip == 1) printf("%d.��Ա�û�%s\t\t%d\n", number, p->usname, p->bill);
		else printf("%d.�����Ա�û�%s\t%d\n", number, p->usname, p->bill);
	}
	int num;
	scanf("%d", &num); getchar();
	while (num > usernum)
	{
		scanf("%d", &num); getchar();
	}
	sef* p0 = userp->next;
	for (int i = 1; i < num; i++) p0 = p0->next;
	printf("****************************************************\n");
	for (int i = 1; i < p0->ordernum; i++)//�鿴�û�����
	{
		int beernum = 0, liquornum = 0, drinksnum = 0;
		for (int j = 0; j < 20; j++)
		{
			if (p0->orders[i].beer[j]) beernum++;
			if (p0->orders[i].liquor[j]) liquornum++;
			if (p0->orders[i].drinks[j]) drinksnum++;
		}
		printf("%d.%s�û�������%d��ơ��%d�ְ׾�%d����Ʒ\t���ƽ��%dԪ\n", i, p0->usname, beernum, liquornum, drinksnum, p0->orders[i].sumsell);
	}
	printf("������Ҫ��ѯ�Ķ������\n");
	int n; scanf("%d", &n); getchar();
	while (n > p0->ordernum)
	{
		scanf("%d", &n); getchar();
	}
	int i, number = 0;
	printf("***************************************************************\n");
	for (i = 0; i < 20; i++)//�鿴�û����嶩��
	{
		bef* p = beerp->next;
		if (p0->orders[n].beer[i])
		{
			number++;
			for (int j = 0; j < i - 1; j++) p = p->next;
			printf("%d.%-20s\t%dml\t%d��\t%d\t%d��\t%dԪ\t\n", number, p->name, p->capacity, p->alcohol, p->specs, p0->orders[n].beer[i], p0->orders[n].beer[i] * p->value);
		}
	}
	for (i = 0; i < 20; i++)
	{
		lef* p1 = liquorp->next;
		if (p0->orders[n].liquor[i])
		{
			number++;
			for (int j = 0; j < i - 1; j++) p1 = p1->next;
			printf("%d.%-20s\t%dml\t%d��\t%d\t%d��\t%dԪ\t\n", number, p1->name, p1->capacity, p1->alcohol, p1->specs, p0->orders[n].liquor[i], p0->orders[n].liquor[i] * p1->value);
		}
	}
	for (i = 0; i < 20; i++)
	{
		def* p2 = drinksp->next;
		if (p0->orders[n].drinks[i])
		{
			number++;
			for (int j = 0; j < i - 1; j++) p2 = p2->next;
			printf("%d.%-20s\t%dml\t%d\t%d��\t%dԪ\t\n", number, p2->name, p2->capacity, p2->specs, p0->orders[n].drinks[i], p0->orders[n].drinks[i] * p2->value);
		}
	}
	printf("\n1.�����鿴       2.�˳�");
	int nm; scanf("%d", &nm); getchar();
	while (nm != 1 && nm != 2) { scanf("%d", &nm); getchar(); }
	if (nm == 1) usermation();
	else adminmeue();
}

void checkorder()//�鿴�¶���
{
	cleanscreen();
	printf("*************************************************\n");
	printf("*\t\t����%d����������\t\t*\n", ordersnum);
	printf("*************************************************\n");
	sef* p = userp->next;
	int n = 1;
	for (int i = 0; i < usernum; i++)
	{
		for (int num = 1; num < p->ordernum; num++)
		{
			int beernum = 0, liquornum = 0, drinksnum = 0;
			if (p->orders[num].flag == 1)
			{
				p->orders[num].flag = 0;
				for (int j = 1; j < 20; j++)
				{
					if (p->orders[num].beer[j]) beernum++;
					if (p->orders[num].liquor[j]) liquornum++;
					if (p->orders[num].drinks[j]) drinksnum++;
				}
				printf("%d.%s�û�������%d��ơ��%d�ְ׾�%d����Ʒ\t���ƽ��%dԪ\n", n++, p->usname, beernum, liquornum, drinksnum, p->orders[num].sumsell);
				printf("***************************************************************\n");
				sef* pp = p;
				int number = 0;
				int i;
				for (i = 0; i < 20; i++)
				{
					bef* p = beerp->next;
					if (pp->orders[num].beer[i])
					{
						number++;
						for (int j = 0; j < i - 1; j++) p = p->next;
						printf("%d.%-20s\t%dml\t%d��\t%d\t%d��\t%dԪ\t\n", number, p->name, p->capacity, p->alcohol, p->specs, pp->orders[num].beer[i], pp->orders[num].beer[i] * p->value);
					}
				}
				for (i = 0; i < 20; i++)
				{
					lef* p1 = liquorp->next;
					if (pp->orders[num].liquor[i])
					{
						number++;
						for (int j = 0; j < i - 1; j++) p1 = p1->next;
						printf("%d.%-20s\t%dml\t%d��\t%d\t%d��\t%dԪ\t\n", number, p1->name, p1->capacity, p1->alcohol, p1->specs, pp->orders[num].liquor[i], pp->orders[num].liquor[i] * p1->value);
					}
				}
				for (i = 0; i < 20; i++)
				{
					def* p2 = drinksp->next;
					if (pp->orders[num].drinks[i])
					{
						number++;
						for (int j = 0; j < i - 1; j++) p2 = p2->next;
						printf("%d.%-20s\t%dml\t%d\t%d��\t%dԪ\t\n", number, p2->name, p2->capacity, p2->specs, pp->orders[num].drinks[i], pp->orders[num].drinks[i] * p2->value);
					}
				}
				printf("***************************************************************\n\n");
			}
		}
		p = p->next;
	}
	ordersnum=0;
	printf("����0�˳�\n");
	int num;
	scanf("%d", &num); getchar();
	while(num!=0)
	{
		scanf("%d", &num); getchar;
	}
	if(num==0) adminmeue();
		
}

void checksold()
{
	cleanscreen();
	printf("*************************************************\n");
	printf("*\t\t��ѡ��鿴ģʽ\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.����������\t\t\t*\n");
	printf("*\t\t2.�����۶�����\t\t\t*\n");
	printf("*************************************************\n");
	int num;
	scanf("%d", &num); getchar();
	while (num != 1 && num != 2)
	{
		scanf("%d", &num); getchar();
	}
	if (num == 1)
	{
		if (beernum)
		{
			bef* p = beerp->next;
			bef* p1[20];
			int n = 0;
			while (p)
			{
				if (p->soldout)
					p1[n] = p, n++;
				p = p->next;
			}
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - i - 1; j++)
					if (p1[j]->soldout < p1[j + 1]->soldout)
					{
						bef* t = p1[j];
						p1[j] = p1[j + 1];
						p1[j + 1] = t;
					}
			printf("********************************************************************************************\n");
			printf(" **\t\t\t\t\tơ��\t\t\t\t\t**\n");
			printf("********************************************************************************************\n");
			printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "���(ƿ)", "�۳�����(��)", "�۸�");
			for (int i = 0; i < n; i++)
				printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p1[i]->name, p1[i]->capacity, p1[i]->specs, p1[i]->soldout, p1[i]->value);
		}
		if (liquornum)
		{
			lef* p = liquorp->next;
			lef* p1[20];
			int n = 0;
			while (p)
			{
				if (p->soldout)
					p1[n] = p, n++;
				p = p->next;
			}
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - i - 1; j++)
					if (p1[j]->soldout < p1[j + 1]->soldout)
					{
						lef* t = p1[j];
						p1[j] = p1[j + 1];
						p1[j + 1] = t;
					}
			printf("********************************************************************************************\n");
			printf(" **\t\t\t\t\t�׾�\t\t\t\t\t**\n");
			printf("********************************************************************************************\n");
			printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "���(ƿ)", "�۳�����(��)", "�۸�");
			for (int i = 0; i < n; i++)
				printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p1[i]->name, p1[i]->capacity, p1[i]->specs, p1[i]->soldout, p1[i]->value);
		}
		if (drinksnum)
		{
			def* p = drinksp->next;
			def* p1[20];
			int n = 0;
			while (p)
			{
				if (p->soldout)
					p1[n] = p, n++;
				p = p->next;
			}
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - i - 1; j++)
					if (p1[j]->soldout < p1[j + 1]->soldout)
					{
						def* t = p1[j];
						p1[j] = p1[j + 1];
						p1[j + 1] = t;
					}
			printf("********************************************************************************************\n");
			printf(" **\t\t\t\t\t��Ʒ\t\t\t\t\t**\n");
			printf("********************************************************************************************\n");
			printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "���(ƿ)", "�۳�����(��)", "�۸�");
			for (int i = 0; i < n; i++)
				printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p1[i]->name, p1[i]->capacity, p1[i]->specs, p1[i]->soldout, p1[i]->value);
		}
	}
	if (num == 2)
	{
		if (beernum)
		{
			bef* p = beerp->next;
			bef* p1[20];
			int n = 0;
			while (p)
			{
				if (p->soldout)
					p1[n] = p, n++;
				p = p->next;
			}
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - i - 1; j++)
					if (p1[j]->soldout * p1[j]->value < p1[j + 1]->soldout * p1[j+1]->value)
					{
						bef* t = p1[j];
						p1[j] = p1[j + 1];
						p1[j + 1] = t;
					}
			printf("********************************************************************************************\n");
			printf(" **\t\t\t\t\tơ��\t\t\t\t\t**\n");
			printf("********************************************************************************************\n");
			printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "���(ƿ)", "�۳�����(��)", "���۶�");
			for (int i = 0; i < n; i++)
				printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p1[i]->name, p1[i]->capacity, p1[i]->specs, p1[i]->soldout, p1[i]->soldout * p1[i]->value);
		}
		if (liquornum)
		{
			lef* p = liquorp->next;
			lef* p1[20];
			int n = 0;
			while (p)
			{
				if (p->soldout)
					p1[n] = p, n++;
				p = p->next;
			}
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - i - 1; j++)
					if (p1[j]->soldout * p1[j]->value < p1[j + 1]->soldout * p1[j+1]->value)
					{
						lef* t = p1[j];
						p1[j] = p1[j + 1];
						p1[j + 1] = t;
					}
			printf("********************************************************************************************\n");
			printf(" **\t\t\t\t\t�׾�\t\t\t\t\t**\n");
			printf("********************************************************************************************\n");
			printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "���(ƿ)", "�۳�����(��)", "���۶�");
			for (int i = 0; i < n; i++)
				printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p1[i]->name, p1[i]->capacity, p1[i]->specs, p1[i]->soldout, p1[i]->soldout * p1[i]->value);
		}
		if (drinksnum)
		{
			def* p = drinksp->next;
			def* p1[20];
			int n = 0;
			while (p)
			{
				if (p->soldout)
					p1[n] = p, n++;
				p = p->next;
			}
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - i - 1; j++)
					if (p1[j]->soldout * p1[j]->value < p1[j + 1]->soldout * p1[j+1]->value)
					{
						def* t = p1[j];
						p1[j] = p1[j + 1];
						p1[j + 1] = t;
					}
			printf("********************************************************************************************\n");
			printf(" **\t\t\t\t\t��Ʒ\t\t\t\t\t**\n");
			printf("********************************************************************************************\n");
			printf("%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "��Ʒ����", "����(ml)", "���(ƿ)", "�۳�����(��)", "���۶�");
			for (int i = 0; i < n; i++)
				printf("%d.%-20s\t%-10d\t%-10d\t%-10d\t%-10d\t\n", i + 1, p1[i]->name, p1[i]->capacity, p1[i]->specs, p1[i]->soldout, p1[i]->soldout * p1[i]->value);
		}
	}
	filesave();
	printf("\n����0�˳�");
	scanf("%d", &num); getchar();
	if (num == 0) adminmeue();
}
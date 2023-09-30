#include"sdu.h"
int usernum;
int beernum;
int liquornum;
int drinksnum;
int ordersnum;
char adminpassword[5] = { 'd','l','s' };//����Ա����
sef user;
sef* userp = &user;
bef beer;
bef* beerp = &beer;
lef liquor;
lef* liquorp = &liquor;
def drinks;
def* drinksp = &drinks;
void welcome() {
	cleanscreen();
	printf("*************************************************\n");
	printf("*\t\t��ӭʹ�þ�ˮ����ϵͳ\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t��ѡ�����б�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.�û���¼\t\t\t*\n");
	printf("*\t\t2.�û�ע��\t\t\t*\n");
	printf("*\t\t3.��̨����\t\t\t*\n");
	printf("*************************************************\n");
	printf("\n");
	int num;
	while (1) {
		scanf("%d", &num);
		getchar();
		switch (num) {
		case 1:
			userlogin();
			break;
		case 2:
			userregesiter();
			break;
		case 3:
			printf("���������Ա����(����0�˳�)\n");
			char password[20];
			scanf("%s", password); getchar();
			while (strcmp(adminpassword, password) != 0)
			{
				if (strcmp(password, "0")==0) welcome();
				printf("�����������������(����0�˳�)\n");
				scanf("%s", password); getchar();
			}
			adminmeue();
			break;
		}
	}
}
void cleanscreen() {
	system("cls");
}
void filesave()
{
	FILE* fp;
	fopen_s(&fp, "data.txt", "wb");
	fwrite(&usernum, 4, 1, fp);//д���û�����
	fwrite(&beernum, 4, 1, fp);//д��ơ������
	fwrite(&liquornum, 4, 1, fp);//д��׾�����
	fwrite(&drinksnum, 4, 1, fp);//д����Ʒ����
	fwrite(&ordersnum, 4, 1, fp);//д�붩������
	sef* p = userp->next;
	while (p)
		fwrite(p, sizeof(sef), 1, fp), p = p->next;//д���û���Ϣ
	bef* p1 = beerp->next;
	while (p1)
		fwrite(p1, sizeof(bef), 1, fp), p1 = p1->next;//д��ơ����Ϣ
	lef* p2 = liquorp->next;
	while (p2)
		fwrite(p2, sizeof(lef), 1, fp), p2 = p2->next;//д��׾���Ϣ
	def* p3 = drinksp->next;
	while (p3)
		fwrite(p3, sizeof(def), 1, fp), p3 = p3->next;//д����Ʒ��Ϣ
	fclose(fp);
}
int main()
{
	FILE* fp;
	fopen_s(&fp, "data.txt", "rb");
	fread(&usernum, 4, 1, fp);//�����û�����
	fread(&beernum, 4, 1, fp);//����ơ������
	fread(&liquornum, 4, 1, fp);//����׾�����
	fread(&drinksnum, 4, 1, fp);//������Ʒ����
	fread(&ordersnum, 4, 1, fp);//�����¶�������
	sef* p = userp;
	for (int i = 0; i < usernum; i++)
	{
		p->next = (sef*)malloc(sizeof(sef));
		p = p->next;
		fread(p, sizeof(sef), 1, fp);//�����û���Ϣ
	}
	p->next = 0;
	bef* p1 = beerp;
	for (int i = 0; i < beernum; i++)
	{
		p1->next = (bef*)malloc(sizeof(bef));
		p1 = p1->next;
		fread(p1, sizeof(bef), 1, fp);//����ơ����Ϣ
	}
	p1->next = 0;
	lef* p2 = liquorp;
	for (int i = 0; i < liquornum; i++)
	{
		p2->next = (lef*)malloc(sizeof(lef));
		p2 = p2->next;
		fread(p2, sizeof(lef), 1, fp);//����׾���Ϣ
	}
	p2->next = 0;
	def* p3 = drinksp;
	for (int i = 0; i < drinksnum; i++)
	{
		p3->next = (def*)malloc(sizeof(def));
		p3 = p3->next;
		fread(p3, sizeof(def), 1, fp);//������Ʒ��Ϣ
	}
	p3->next = 0;
	fclose(fp);
	welcome();
	return 0;
}
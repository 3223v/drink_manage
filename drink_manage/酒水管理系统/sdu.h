#ifndef _SDU_H_
#define _SDU_H_
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<ctype.h>
extern int usernum;//�����û����
extern int beernum;//����ơ�Ʊ��
extern int liquornum;//����׾Ʊ��
extern int drinksnum;//������Ʒ���
extern int ordersnum;//���嶩�����
//�����û��ṹ������
typedef struct User
{
	int vip;//�����û��ȼ���0Ϊ��ͨ��1ΪVIP��2Ϊ����VIP
	char usname[20];//�����û���
	char password1[15];//�����û�����
	int ordernum;//���嶩�����
	struct
	{
		int flag;//���嶩���鿴״̬
		int beer[20];
		int liquor[20];
		int drinks[20];
		int sumsell;
	}orders[100];//�ṹ�������ʾ����
	int bill;
	struct User* next;
}sef;
extern sef user;
extern sef* userp;
//����ơ�ƽṹ������
typedef struct Beer
{
	char name[30];//����
	int capacity;//����
	int alcohol;//�ƾ���
	int specs;//���
	int num;//����
	int value;//�۸�
	struct Beer* next;
	int soldout;//����
}bef;
extern bef beer;
extern bef* beerp;
//����׾ƽṹ������
typedef struct Liquor
{
	char name[30];
	int capacity;
	int alcohol;
	int specs;
	int  num;
	int value;
	int soldout;
	struct Liquor* next;
}lef;
extern lef liquor;
extern lef* liquorp;
//������Ʒ�ṹ������
typedef struct Drinks
{
	char name[30];
	int capacity;
	int specs;
	int  num;
	int value;
	int soldout;
	struct Drinks* next;
}def;
extern def drinks;
extern def* drinksp;

void welcome();//��ʼ����
void filesave();//�ļ�����
void cleanscreen();//����
void userlogin();//�û���¼
void userregesiter();//�û�ע��
void changepassword(sef* head);//�û��޸�����
void usermeue(sef* head);//�û��˵�
void userbuy(sef* head);//�û�����
void usercheck(sef* head);//�û��鿴����
void userchange(sef* head);//�û��˻�����
void deleteuser(sef* head);//ע���˻�
void adminmeue();//����Ա�˵�
void inventory();//����Ա�鿴���
void addbeer();//��Ӿ�ˮ��Ϣ
void addliquor();
void adddrinks();
void changebeer();//�޸ľ�ˮ��Ϣ
void changeliquor();
void changedrinks();
void delbeer();//ɾ����ˮ
void delliquor();
void deldrinks();
void usermation();//����Ա�鿴�û���Ϣ
void checkorder();//����Ա�鿴����
void checksold();//����Ա�鿴������Ϣ
#endif
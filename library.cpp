#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
struct book{
	int id;//�鼮���
	char name[20];//����
	char writer[20];//����
	double price;//�۸�
	char intime[50];//���ʱ��
	char borrow[5];//�Ƿ���
	char pname[20];//���������
	char puttime[50];//���ʱ��
};
int N;//ͼ������
book B[100];
void kuang();//�߿� 
void insert();//�������
void del();//ͼ���¼� 
void bro();//ͼ����� 
void ret();//ͼ��黹 
void show();//����ͼ��չʾ 
int main (){
	int k;
	while(1)
	{
		system( "cls" );
		printf("\t\t\tͼ��ݹ���ϵͳ\n");
		kuang();
		printf( "\t\t��1���½�ͼ�鼰������Ϣ����\n\t\t��2������ͼ��չʾ\n\t\t��3��ͼ���¼�\n\t\t��4�������������\n\t\t��5������������\n\t\t��0���˳�\n" );
		kuang();
		scanf( "%d",&k );
		system( "cls" );
		kuang();
		switch(k){
			case 1:
				insert();
				break;
			case 2:
				show();
				break;
			case 3:
				del();
				break;
			case 4:
				bro();
				break;
			case 5:
				ret();
				break;
			case 0:return 0;break;
			default:printf("���������룡\n");break;
		}
	}
	return 0;
}
void insert(){
	int n,i;
	time_t rawtime;
	struct tm * timeinfo;
	char bookname[20];
	printf("�������鼮��ţ�");
	scanf("%d",&n);
	for(i=0;i<N;i++){
		if(n==B[i].id){
			printf("��ͼ���Ѵ��ڣ��������Ƿ���ȷ��\n");
			Sleep(1500);
			return;
		}
	}
	B[N].id=n;
	printf("������������");
	scanf("%s",bookname);
	for(i=0;i<N;i++){
		if(strcmp(bookname,B[i].name)==0){
			printf("��ͼ���Ѵ��ڣ����������Ƿ���ȷ��\n");
			Sleep(1500);
			return;
		}
	}
	strcpy(B[N].name,bookname);
	printf("��������������");
	scanf("%s",B[N].writer);
	printf("������۸�");
	scanf("%lf",&B[N].price);
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	strcpy(B[N].intime,asctime (timeinfo));
	strcpy(B[N].borrow,"NO");
	strcpy(B[N].pname,"NO");
	strcpy(B[N].puttime,"NO");
	N++;
}
void del(){
	int n,i,j;
	printf("�������鼮��ţ�");
	scanf("%d",&n);
	for(i=0;i<N;i++){
		if(i==B[N].id){
			for(j=i+1;j<N;j++)
				B[j-1]=B[j];
			N--;
			return;
		}
	}
	printf("�鼮�����ڣ����ʵ���ڲ�����"); 
	Sleep(1500);
}
void bro(){
	int n,i;
	time_t rawtime;
	struct tm * timeinfo;
	printf("�����������ͼ���ţ�");
	scanf("%d",&n);
	for(i=0;i<N;i++){
		if(B[i].id==n){
			if(strcmp(B[i].borrow,"YES")==0){
				printf("�����Ѿ������");
				Sleep(1500);
				return;
			}
			printf("�����������������");
			scanf("%s",B[i].pname); 
			strcpy(B[i].borrow,"YES"); 
			time ( &rawtime );
			timeinfo = localtime ( &rawtime );
			strcpy(B[i].puttime,asctime (timeinfo));
			return;
		}
	}
	printf("�鼮�����ڣ����ʵ���ڲ�����");
	Sleep(1500); 
}
void ret(){
	int n,i; 
	printf("������Ҫ����ͼ����:");
	scanf("%d",&n);
	for(i=0;i<N;i++){
		if(B[i].id==n){
			if(strcmp(B[i].borrow,"NO")==0){
				printf("���黹��ͼ��ݣ����ʵ���ٲ�����");
				Sleep(1500);
				return;
			}
		}
		strcpy(B[i].borrow,"NO");
		strcpy(B[i].pname,"NO");
		strcpy(B[i].puttime,"NO");	
		return;
	} 
	printf("�鼮�����ڣ����ʵ���ڲ�����");
	Sleep(1500); 
}
void show(){
	int i,j=1,n=1;
	while(n){
		printf("�鼮���\t����\t����\t�۸�\t���ʱ��\n\t�Ƿ���\t������\t����ʱ��\n");
		for(i=0;i<5;i++){
			if(N-(i+(j-1)*5)==0)break;
			printf("%d\t%s\t%s\t%.2lf\t%s\t%s\t%s\t%s\n",B[i+(j-1)*5].id,B[i+(j-1)*5].name,
				B[i+(j-1)*5].writer,B[i+(j-1)*5].price,B[i+(j-1)*5].intime,B[i+(j-1)*5].borrow,B[i+(j-1)*5].pname,B[i+(j-1)*5].puttime);
		}
		printf("\t\t��һҳ��1��/��һҳ��3��\t��ǰ��%dҳ\t�˳���0��\n",j);
		kuang();
		scanf("%d",&n);
		system( "cls" );
		kuang();
		if(n==1&&j!=1)j--;
		else if(n==3&&j*5<N)j++;
	}
	
} 
void kuang(){
	printf("===============================================\n");
}

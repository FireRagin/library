#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
struct book{
	int id;//书籍编号
	char name[20];//书名
	char writer[20];//作者
	double price;//价格
	char intime[50];//入库时间
	char borrow[5];//是否借出
	char pname[20];//借出人姓名
	char puttime[50];//借出时间
};
int N;//图书总量
book B[100];
void kuang();//边框 
void insert();//新书入库
void del();//图书下架 
void bro();//图书出借 
void ret();//图书归还 
void show();//现有图书展示 
int main (){
	int k;
	while(1)
	{
		system( "cls" );
		printf("\t\t\t图书馆管理系统\n");
		kuang();
		printf( "\t\t【1】新进图书及基本信息输入\n\t\t【2】现有图书展示\n\t\t【3】图书下架\n\t\t【4】办理借书手续\n\t\t【5】办理还书手续\n\t\t【0】退出\n" );
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
			default:printf("请重新输入！\n");break;
		}
	}
	return 0;
}
void insert(){
	int n,i;
	time_t rawtime;
	struct tm * timeinfo;
	char bookname[20];
	printf("请输入书籍编号：");
	scanf("%d",&n);
	for(i=0;i<N;i++){
		if(n==B[i].id){
			printf("该图书已存在，请检查编号是否正确！\n");
			Sleep(1500);
			return;
		}
	}
	B[N].id=n;
	printf("请输入书名：");
	scanf("%s",bookname);
	for(i=0;i<N;i++){
		if(strcmp(bookname,B[i].name)==0){
			printf("该图书已存在，请检查书名是否正确！\n");
			Sleep(1500);
			return;
		}
	}
	strcpy(B[N].name,bookname);
	printf("请输入作者名：");
	scanf("%s",B[N].writer);
	printf("请输入价格：");
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
	printf("请输入书籍编号：");
	scanf("%d",&n);
	for(i=0;i<N;i++){
		if(i==B[N].id){
			for(j=i+1;j<N;j++)
				B[j-1]=B[j];
			N--;
			return;
		}
	}
	printf("书籍不存在，请核实后在操作！"); 
	Sleep(1500);
}
void bro(){
	int n,i;
	time_t rawtime;
	struct tm * timeinfo;
	printf("请输入欲借的图书编号：");
	scanf("%d",&n);
	for(i=0;i<N;i++){
		if(B[i].id==n){
			if(strcmp(B[i].borrow,"YES")==0){
				printf("该书已经借出！");
				Sleep(1500);
				return;
			}
			printf("请输入借书人姓名：");
			scanf("%s",B[i].pname); 
			strcpy(B[i].borrow,"YES"); 
			time ( &rawtime );
			timeinfo = localtime ( &rawtime );
			strcpy(B[i].puttime,asctime (timeinfo));
			return;
		}
	}
	printf("书籍不存在，请核实后在操作！");
	Sleep(1500); 
}
void ret(){
	int n,i; 
	printf("请输入要还的图书编号:");
	scanf("%d",&n);
	for(i=0;i<N;i++){
		if(B[i].id==n){
			if(strcmp(B[i].borrow,"NO")==0){
				printf("该书还在图书馆，请核实后再操作！");
				Sleep(1500);
				return;
			}
		}
		strcpy(B[i].borrow,"NO");
		strcpy(B[i].pname,"NO");
		strcpy(B[i].puttime,"NO");	
		return;
	} 
	printf("书籍不存在，请核实后在操作！");
	Sleep(1500); 
}
void show(){
	int i,j=1,n=1;
	while(n){
		printf("书籍编号\t书名\t作者\t价格\t入库时间\n\t是否借出\t借书人\t借书时间\n");
		for(i=0;i<5;i++){
			if(N-(i+(j-1)*5)==0)break;
			printf("%d\t%s\t%s\t%.2lf\t%s\t%s\t%s\t%s\n",B[i+(j-1)*5].id,B[i+(j-1)*5].name,
				B[i+(j-1)*5].writer,B[i+(j-1)*5].price,B[i+(j-1)*5].intime,B[i+(j-1)*5].borrow,B[i+(j-1)*5].pname,B[i+(j-1)*5].puttime);
		}
		printf("\t\t上一页【1】/下一页【3】\t当前第%d页\t退出【0】\n",j);
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

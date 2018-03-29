#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int denglu();
int jianyan(FILE *fp);
typedef struct list
{
	char name[100];
	char work[100];
	char telephone[100];						
	char address[100];
	struct list*next;
}list;
list *shifang(list *phead);
void print(list *phead);
void baocun(list *phead);
list *creat(void);  
list *tianjia(list *phead);  
list *chazhao(list *phead);
list *suoyou(void);
list *shanchu(list *phead); 
int main(void)
{
	list *phead=NULL;
	char a[100];
	int d;
	d=denglu();
	if(d==0)
	{
		printf("\n\t\t\t\t欢迎使用本程序\n");
		printf("\t\t\t使用程序过后，记得选择保存哦\n");
		printf("\t\t\t\t祝您使用愉快\n\n\n");
		while(1)	
		{
			printf("\t\t\t\t(1)创建新通讯录\n");
			printf("\t\t\t\t(2)添加新联系人\n");
			printf("\t\t\t\t(3)删除联系人\n");
			printf("\t\t\t\t(4)查找联系人\n");
			printf("\t\t\t\t(5)保存\n");
			printf("\t\t\t\t(6)读出文件联系人\n");
			printf("\t\t\t\t(7)安全退出\n");
			printf("当输入多个字符时，取第一位输入~~!\n");
			printf("请输入《1--6》号操作:");
			scanf("%s",a);
			switch(*a)
			{
				case '1':
					{ 
						if(phead==NULL) 
						{ 
							phead=creat();          
							print(phead);  
							break; 
						} 
						else 
						{ 
							phead=shifang(phead);
							phead=creat();               
							print(phead);
							break; 
						} 
					} 
				
				case '2':
					{
						phead=tianjia(phead);           
						print(phead); 
						break;
					}
				case '3':
					{
						phead=shanchu(phead);             
						print(phead); 
						break;
					}
				case '4':
					{
						chazhao(phead);
						break;
					}
				case '5':
					{
						baocun(phead);
						break;
					}
				case '6':
					{
						phead=suoyou(); 
						print(phead);
						break;
					}
				case '7':
					{
						phead=shifang(phead);
						break;
					}
				default: 
					{	
						printf("操作错误，此项不存在~~!\n");
						break;
					}	
			} 
			if(strcmp(a,"7")==0) 
				break; 
		}
	}
	
	
}
list *creat(void)
{
	list *phead,*pnew,*p;
	int n=1;
	char name[100];
	pnew=(list *)malloc(sizeof(list)); 
	phead=pnew;
	p=phead;  
	printf("请输入通讯录的内容!\n姓名输入为0时表示创建完毕!\n"); 
	printf("请输入姓名:"); 
	gets(name);
	gets(name);
	if(strcmp(name,"0")!=0)
	{
		strcpy(p->name,name); 
		printf("请输入职业:");
		gets(p->work);
		printf("请输入手机:");   
		gets(p->telephone); 
		printf("请输入通讯地址:"); 
		gets(p->address);
	}
	else
	{	
		return 0;
	}
	while(strcmp(name,"0")!=0) 
    { 
		printf("请输入姓名:"); 
		gets(name); 
		if(strcmp(name,"0")==0) 
		{ 
			p->next=NULL;
			break; 
		} 
		else 
		{	pnew=(list *)malloc(sizeof(list)); 
			p->next=pnew;
			p=pnew;
			strcpy(p->name,name); 
			printf("请输入职业:"); 
			gets(p->work); 
			printf("请输入手机:"); 
			gets(p->telephone); 
			printf("请输入通讯地址:"); 
			gets(p->address); 

		} 
		p->next=NULL;
	}
	
    return phead; 
} 	
list *shifang(list *phead)
{
	list *p1; 
	while(phead!=NULL) 
	{ 
		p1=phead; 
		phead=phead->next; 
		free(p1); 
	} 
	return(phead); 
}
void print(list *phead)   
{
	int n=0;
	list *p;
	if(phead==NULL)
	{
		return;
	}
	p=phead;
	do
	{	
		printf("\n姓名:%s  职业:%s  电话号码:%s  通讯地址:%s\n",p->name,p->work,p->telephone,p->address);
        p=p->next;
		n++;
	}while(p!=NULL);
	
	printf("通讯录共%d人\n",n);
	
}
int denglu()
{   
	FILE *fp;
	int x,a;
	char s,b[10],p[10];
	if((fp=fopen("E:\\kai.txt","r+"))==NULL)
	{
		printf("error");
		exit(0);
	}
	x=jianyan(fp);
	if(x==0)
	{
		while (a!=1&&a!=2)
		{
			printf("您是否需要设置密码(需要输入1,不需要输入2)");
			scanf("%d",&a);
		}
		if(a==1)
		{	printf("（密码长度请不要超过10位）");
			printf("请设置您的密码:");
			printf("输入0时视为结束设置您的密码:");
			s=getchar();
			while(s!='0')
			{
				fputc(s,fp);
				s=getchar();
			}
			fclose(fp);
			printf("设置成功\n");	
			return 0;
		}
		else if(a==2)
			return 0;
	}
	else 
		while(1)
		{	printf("请输入密码:");
			fscanf(fp,"%s",b);
			gets(p);
			if(strcmp(b,p)==0)
				return 0;
			else
				printf("您的密码出现错误~~!\n");
		}
}
int jianyan(FILE *fp)
{

	int ch;
	ch=fgetc(fp);
	if(ch!=EOF)
		return 1;
	else
		return 0;
}
void baocun(list *phead)
{
	FILE*fp;
	list *q;
	if(phead==NULL)
	{	
		printf("您的通讯录为空，无法保存~~!\n");
		return ;
	}
	if((fp=fopen("E:\\demo.txt","w"))==NULL)
	{	
		printf("error");
		exit(0);
	}
	q=phead; 
	for(;q!=NULL;)  
	{ 
		fprintf(fp,"%s  %s  %s  %s\n",q->name,q->work,q->telephone,q->address); 
		q=q->next; 
	}
	printf("保存完毕!\n"); 
	fclose(fp); 

}
list *tianjia(list *phead)  
{ 
	list *p0,*p1; 
	char name[20]; 
	p1=phead; 
	printf("请输入增加的内容:\n"); 
	printf("请输入姓名:"); 
	gets(name); 
	gets(name);
	if(strcmp(name,"0")==0) 
	{ 
		printf("姓名不能为0,增加失败~~!\n"); 
		return(phead); 
	} 
	else 
	{ 
		p0=(list *)malloc(sizeof(list)); 
		strcpy(p0->name,name); 
		printf("请输入职业:"); 
		gets(p0->work); 
		printf("请输入手机:"); 
		gets(p0->telephone); 
		printf("请输入通讯地址:"); 
		gets(p0->address); 
		if(phead==NULL) 
		{ 
			phead=p0; 
			p0->next=NULL; 
			return (phead); 
		} 
		else 
		{ 
			while(1)
			{
				if(p1->next==NULL)
				{	
					p0->next=p1->next;
					p1->next=p0;
					break;
				}
				else
					p1=p1->next;
			}
			return phead;
		} 
	} 
}
list *chazhao(list *phead)
{
	list *p;
	char name[100];
	int a;
	if(phead==NULL)
	{
		printf("通讯录为空，无法查找~~!\n");
		return(phead);
	}
	p=phead;
	printf("************************\n");
	printf("*请您输入你要查找的姓名*:\n");
	gets(name);
	gets(name);
	while(p!=NULL)	
	{	if(strcmp(p->name,name)==0) 
		{	
			a++;
			printf("你查找的内容是:\n"); 
			printf("****************************************\n"); 
			printf("*** 姓名:%s    职业:%s    电话:%s    地址:%s\n",p->name,p->work,p->telephone,p->address); 
		}	 
		p=p->next;
	}
	if(a==0)
	{
		printf("该内容不存在~~!\n");
	}
	return phead;

}
list *suoyou()
{
	FILE *fp;
	list *phead;
	phead=(list *)malloc(sizeof(list));
	phead->next=NULL;
	if((fp=fopen("E:\\demo.txt","r"))==NULL) 
	{ 
		printf("此通讯录名不存在,无法输出!\n"); 
		exit(1); 
	}
	while(!feof(fp))
	{
		list *p;
		p=(list *)malloc(sizeof(list));
		fscanf(fp,"%s%s%s%s",p->name,p->work,p->telephone,p->address); 
		p->next=phead->next;
		phead->next=p;
	}
	fclose(fp);
	phead=phead->next->next;
	return	phead;

}
list *shanchu(list *phead) 
{ 
	list *p,*q; 
	char name[30]; 
	if(phead==NULL) 
	{ 
		printf("通讯录为空,无法删除~~!\n"); 
		return phead; 
	} 
	p=phead; 
	printf("请输入需要删除的人的姓名:"); 
	gets(name); 
	gets(name);
	if(strcmp(phead->name,name)==0) 
	{ 
		phead=phead->next; 
		free(p); 
		printf("删除操作成功~~!\n"); 
		return phead; 
	} 
	else 
	{ 
		q=phead,p=phead->next; 
		while(p!=NULL) 
		{ 
			if(strcmp(p->name,name)==0) 
			{ 
				q->next=p->next; 
				free(p); 
				printf("删除操作成功~~!\n"); 
				return phead; 
			} 
			p=p->next; 
			q=q->next; 
		} 
	} 
} 

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h> // thu vien lam viec voi chuoi ki tu
#define max 100
#define max_length 12
struct khachhang
{
    char mhd[max],name[max],scm[max],gioitinh[max],sophong[max],loaiphong[max];// ma hoa don, ten, so chung minh , gioi tinh , so phong
    int dongia,tienphong,ngayden,ngaydi; // ngay den , ngay di
};
struct Node
{
	struct khachhang data;
	struct Node *next;
	
};

struct Node *tao(struct khachhang data) // dua du lieu vao newNode
{
	struct Node *newNode = malloc(sizeof(struct Node));
	if(newNode !=NULL)
	{
		newNode->data=data;
		newNode->next=NULL;
	}
	return newNode;
}


void chenc(struct Node **head_ref, struct khachhang data)// them vao cuoi danh sach
{
	struct Node *newNode=tao(data); // khoi tao du lieu cho newNode
	if(*head_ref == NULL) 
	{
		// danh sach rong, newNode them vao dau danh sach
		*head_ref=newNode;
		newNode->next=*head_ref;
	}else
	{
		struct Node *last=*head_ref;
		while(last->next!=*head_ref) // tim du lieu cuoi cung 
		{
			last=last->next;
		}
		last->next=newNode;
		newNode->next=*head_ref; // quay lai node dau
	}
}
int ktten(char *s)
{
	while(*s)
	{
		if(isdigit(*s))
		{
			return 1;
		}
		s++;
	}
	return 0;
}
int ktscm(char *s1)
{	
	int i;
	for(i=0;i<strlen(s1);i++)
	{
		if(!isdigit(s1[i]))
			{
			return 0; // neu khong co ky tu so, tra ve 0
			}
	}
	return 1; //neu co ki tu so tra ve 1
}
int ktlengthscm(char *s2)
{
	return strlen(s2)==max_length;
}
int ktlengthgioitinh(char *s4)
{
	if(strcmp(s4,"Nam")==0||strcmp(s4,"Nu")==0)
	{
		return 1;
	} else return 0;
}
int ktsophong(char *st)
{	
	int i;
	for(i=0;i<strlen(st);i++)
	{
		if(!isalpha(st[0]))
			{
			return 0;
			}
	}
	return 1;
}
void kt(struct Node *head)
{
	struct Node *temp=head;
	do 
	{	
	if(temp->data.ngaydi<temp->data.ngayden||temp->data.ngaydi>30||temp->data.ngayden>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
	}else
	if(ktten(temp->data.name))
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
	}else
	if(ktsophong(temp->data.sophong)==0)
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
	}else
	if(ktscm(temp->data.scm)==0)
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
	}else
	if(!ktlengthscm(temp->data.scm))
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);		
	}else
	if(ktten(temp->data.gioitinh))
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
	}else
	if(!ktlengthgioitinh(temp->data.gioitinh))
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);		
	}
		temp=temp->next;
	}while(temp!=head);
}
void rong(struct Node *head)
{
	if(head == NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
}
void in(struct Node *head) // in ra man hinh
{
	if(head == NULL || head->next==NULL)
	{
		printf("rong.\n");
		return;
	}
	struct Node *temp=head;
	
	// kiem tra thong tin khach hang
	kt(temp);
	// in ra thong tin khach hang
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	do 
	{	
	if(temp->data.ngaydi>=temp->data.ngayden&&temp->data.ngaydi<=30&&temp->data.ngayden<=30&&ktten(temp->data.name)==0&&ktsophong(temp->data.sophong)==1&&ktscm(temp->data.scm)==1&&ktlengthscm(temp->data.scm)&&ktten(temp->data.gioitinh)==0&&ktlengthgioitinh(temp->data.gioitinh))
	{
	int s=0;
	temp->data.loaiphong[0]=temp->data.sophong[0];
	if(temp->data.loaiphong[0]=='A')
	{
		s=400;
		temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
	}else if(temp->data.loaiphong[0]=='B')
	{
		s=300;
		temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
	} else
	{
		s=200;
		temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
	}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",temp->data.mhd,temp->data.name,temp->data.gioitinh,temp->data.scm,temp->data.sophong,temp->data.loaiphong,temp->data.ngayden,temp->data.ngaydi,temp->data.tienphong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	temp=temp->next;
	}while(temp!=head);
}
void chend(struct Node **head_ref, struct khachhang data) // them vao dau danh sach
{
	struct Node *newNode = tao(data);
	struct Node *tam=*head_ref;
	 if (newNode == NULL) {
        printf("rong.\n");
        return;
    }
    if(*head_ref == NULL) 
	{
		// danh sach rong, newNode them vao dau danh sach
		*head_ref=newNode;
		newNode->next=*head_ref;
	}else
	{
	newNode->data=data;
	newNode->next=*head_ref;
	while(tam->next!=*head_ref) // tim du lieu cuoi cung 
		{
			tam=tam->next;
		}
		tam->next=newNode;
	*head_ref=newNode;
	}

	
}
void inhoa(char *st) // in hoa ho va ten
{
	int d=strlen(st);
	int tu=0;
	int i;
	// isalpha kiem tra co ky tu co phai chu cai hay khong
	for(i=0;i<d;i++)
	{
		if(!tu && isalpha(st[i]))
		{
			st[i]=toupper(st[i]);// chuyen doi ki tu thanh chu hoa
			tu=1;
		// isspace kiem tra ky tu co phai la khoang trang khong
		}else if(isspace(st[i]))
		{
			tu=0;
		}else
		{
			st[i]==tolower(st[i]);// chuyen doi ki tu thanh chu thuong (neu ky tu dang la chu hoa)
		}
	}
}

void layten(char *s,char *name) // lay ten tu ho va ten
{
	char temp[100];
	// tao mot ban sao cua ho va ten
	strncpy(temp,s,sizeof(temp)-1);
	temp[sizeof(temp)-1]='\0'; 
	// dung strtok de tach chuoi thanh cac tu
	char *t=strtok(temp," ");
	char *n=t;
	
	while(t!=NULL)
	{
		n=t;
		t=strtok(NULL," "); // tach tiep tuc chuoi ban dau
	}
	// copy ten (t cuoi cung) vao name 
	strncpy(name,n,50);
	name[49] = '\0'; // dam bao chuoi da ket thuc
}

void layho(char *s,char *name) // lay ho tu ho va ten
{
	char temp[100];
	// tao mot ban sao cua ho va ten
	strncpy(temp,s,sizeof(temp)-1);
	temp[sizeof(temp)-1]='\0'; 
	// dung strtok de tach chuoi thanh cac tu
	char *t=strtok(temp, " ");
	strncpy(name, t, 50);
	name[49] = '\0'; // dam bao chuoi da ket thuc
}

void findten( struct Node *head, char *ten)// in ra khach hang co cung ten
{
	char name[50];
	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
		if(head == NULL)
	{
		printf("rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{	
	layten(temp->data.name,name);
	if(strcmp(name,ten)==0)
	{
		d=1;
	if(temp->data.ngaydi<temp->data.ngayden||temp->data.ngaydi>30||temp->data.ngayden>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
		
	}
	// in ra thong tin khach hang
	
	if(temp->data.ngaydi>temp->data.ngayden&&temp->data.ngaydi<=30&&temp->data.ngayden<=30)
	{
		int s=0;
		temp->data.loaiphong[0]=temp->data.sophong[0];
			if(temp->data.loaiphong[0]=='A')
				{
					s=400;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
				}else if(temp->data.loaiphong[0]=='B')
					{
					s=300;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
					} else
					{
					s=200;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
				}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",temp->data.mhd,temp->data.name,temp->data.gioitinh,temp->data.scm,temp->data.sophong,temp->data.loaiphong,temp->data.ngayden,temp->data.ngaydi,temp->data.tienphong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	
	}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}

void findho( struct Node *head, char *ten)// in ra khach hang co cung ho
{
	char name[50];
	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
		if(head == NULL)
	{
		printf("rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{	
	layho(temp->data.name,name);
	
	if(strcmp(name,ten)==0)
	{
		d=1;
	if(temp->data.ngaydi<temp->data.ngayden||temp->data.ngaydi>30||temp->data.ngayden>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
		
	}
	// in ra thong tin khach hang
	
	if(temp->data.ngaydi>temp->data.ngayden&&temp->data.ngaydi<=30&&temp->data.ngayden<=30)
	{
		int s=0;
		temp->data.loaiphong[0]=temp->data.sophong[0];
			if(temp->data.loaiphong[0]=='A')
				{
					s=400;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
				}else if(temp->data.loaiphong[0]=='B')
					{
					s=300;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
					} else
					{
					s=200;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
				}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",temp->data.mhd,temp->data.name,temp->data.gioitinh,temp->data.scm,temp->data.sophong,temp->data.loaiphong,temp->data.ngayden,temp->data.ngaydi,temp->data.tienphong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	
	}
		temp=temp->next;
	}while(temp!=head);
	if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!%s",name);
	}
}
//Tao doc file
void read(const char *filename,struct Node **head)
{
	FILE *f;
	struct khachhang data;
	f=fopen(filename,"r");
	if (f==NULL)
	{
		printf("Khong the mo tep %s \n",filename);
		return ;
	}
	char tmp[100]; 
    while (fgets(tmp, sizeof(tmp), f) != NULL)
	 	{	
        struct Node *newNode = tao(data);
        if (newNode == NULL) 
		{
            printf("Khong du bo nho .\n");
            fclose(f);
            return ;
        }
        
	char *token =strtok(tmp, ",");	
		if(token!=NULL)
			{
			int i = 0;
  		while (isspace((unsigned char)token[i])) 
		  	{
                i++;
            }
            strncpy(newNode->data.mhd, token + i, 5);
            newNode->data.mhd[5] = '\0';
        }

		token=strtok(NULL,",");
		if(token!=NULL)
		{
				int i = 0;
  		while (isspace((unsigned char)token[i])) 
		  	{
                i++;
            }
			strncpy(newNode->data.name,token,25);
			newNode->data.name[25] = '\0';
			inhoa(newNode->data.name); 
		}
		
		token=strtok(NULL,",");
		if(token!=NULL)
		{
				int i = 0;
  		while (isspace((unsigned char)token[i])) 
		  	{
                i++;
            }
			strncpy(newNode->data.scm,token,15);
			 newNode->data.scm[15] = '\0';
		}
		token=strtok(NULL,",");
		if(token!=NULL)
		{
				int i = 0;
  		while (isspace((unsigned char)token[i])) 
		  	{
                i++;
            }
			strncpy(newNode->data.gioitinh,token,50);
			newNode->data.gioitinh[4] = '\0';
			inhoa(newNode->data.gioitinh); 
		}
		token=strtok(NULL,",");
		if(token!=NULL)
		{
				int i = 0;
  		while (isspace((unsigned char)token[i])) 
		  	{
                i++;
            }
			strncpy(newNode->data.sophong,token,50);
			 newNode->data.sophong[50] = '\0';
			 	inhoa(newNode->data.sophong); 
		}
		
		token=strtok(NULL,",");
		if(token!=NULL)
		{
				int i = 0;
  		while (isspace((unsigned char)token[i])) 
		  	{
                i++;
            }
	    newNode->data.ngayden=strtoul(token,NULL,10);
	    
		}
		token=strtok(NULL,",");
		if(token!=NULL)
		{
				int i = 0;
  		while (isspace((unsigned char)token[i])) 
		  	{
                i++;
            }
	    newNode->data.ngaydi=strtoul(token,NULL,10);
	    
		}
		newNode->next=NULL;
		chenc(head,newNode->data);
   }
	fclose(f);
}
void write(const char *filename,struct Node *head)
{
	FILE *f;
	f=fopen(filename,"w");
	if (f==NULL){
		printf("Khong the mo tep %s \n",filename);
		return ;
	}
	
	struct Node *temp=head;
	do 
	{	
		fprintf(f,"%s,%s,%s,%s,%s,%d,%d\n",temp->data.mhd,temp->data.name,temp->data.scm,temp->data.gioitinh,temp->data.sophong,temp->data.ngayden,temp->data.ngaydi);
	temp=temp->next;
	}while(temp!=head);
	fclose(f);
}
struct khachhang nhap() // nhap du lieu vao 
{
	struct khachhang k;
	
	printf("thong tin khach hang\n");
	
    printf("ma hoa don :");
    fgets(k.mhd,sizeof(k.mhd),stdin);
    k.mhd[strcspn(k.mhd, "\n")] = '\0';        
	 
    printf("ten khach hang : "); 
     fgets(k.name,sizeof(k.name),stdin);
      k.name[strcspn(k.name, "\n")] = '\0';
      inhoa(k.name);
      
	while(ktten(k.name))
	{
		printf("loi nhap!!!\nxin vui long nhap lai!!!\n");
		printf("ten khach hang : "); 
    	fgets(k.name,sizeof(k.name),stdin);
        k.name[strcspn(k.name, "\n")] = '\0';
        inhoa(k.name);
	}
	
    printf("so chung minh : ");
     fgets(k.scm,sizeof(k.scm),stdin);
      k.scm[strcspn(k.scm, "\n")] = '\0';
     
     while(ktscm(k.scm)==0||!ktlengthscm(k.scm))
     {
     	printf("loi nhap!!!\nxin vui long nhap lai!!!\n");
     	printf("so chung minh : ");
     	fgets(k.scm,sizeof(k.scm),stdin);
       k.scm[strcspn(k.scm, "\n")] = '\0';
	 }
	 
       printf("gioi tinh : ");
       fgets(k.gioitinh,sizeof(k.gioitinh),stdin);
       k.gioitinh[strcspn(k.gioitinh, "\n")] = '\0';
       inhoa(k.gioitinh);
    while(ktten(k.gioitinh)||!ktlengthgioitinh(k.gioitinh))
    {
    	printf("loi nhap!!!\nxin vui long nhap lai!!!\n");	
    	printf("gioi tinh : ");
       fgets(k.gioitinh,sizeof(k.gioitinh),stdin);
       k.gioitinh[strcspn(k.gioitinh, "\n")] = '\0';
       inhoa(k.gioitinh);
	}
	
        printf("so phong : ");
        fgets(k.sophong,sizeof(k.sophong),stdin);
        k.sophong[strcspn(k.sophong, "\n")] = '\0';
        inhoa(k.sophong);
    while(ktsophong(k.sophong)==0)    
    {
    	printf("loi nhap!!!\nxin vui long nhap lai!!!\n");	
   	    printf("so phong : ");
        fgets(k.sophong,sizeof(k.sophong),stdin);
        k.sophong[strcspn(k.sophong, "\n")] = '\0';
        inhoa(k.sophong);	
	}
    printf("ngay den : ");
   	scanf("%d",&k.ngayden);
    getchar();
    printf("ngay di : ");
   	scanf("%d",&k.ngaydi);
   	getchar();
   	while(k.ngaydi<k.ngayden||k.ngaydi>30||k.ngayden>30)
   	{
   		printf("loi nhap!!!\nxin vui long nhap lai!!!\n");
		printf("ngay den : ");
   		scanf("%d",&k.ngayden);
    	getchar();
    	printf("ngay di : ");
   		scanf("%d",&k.ngaydi);
   		getchar();  	
	}
        return k;
}
struct khachhang nhap1() // nhap sua thong tin khach hang ngay den or ngay di
{
	struct khachhang k;
	printf("thong tin can sua lai.\n");
	printf("\nngay den : ");
   	scanf("%d",&k.ngayden);
    getchar();
    printf("ngay di : ");
   	scanf("%d",&k.ngaydi);
   	getchar();
   	while(k.ngaydi<k.ngayden||k.ngaydi>30||k.ngayden>30)
   	{
   		printf("loi nhap!!!\nxin vui long nhap lai!!!\n");
		printf("ngay den : ");
   		scanf("%d",&k.ngayden);
    	getchar();
    	printf("ngay di : ");
   		scanf("%d",&k.ngaydi);
   		getchar();  	
	}
        return k;
}
struct khachhang nhap2() // nhap sua ten khach hang
{
	struct khachhang k;
	printf("thong tin can sua lai.\n");
	 printf("ten khach hang : "); 
     fgets(k.name,sizeof(k.name),stdin);
     k.name[strcspn(k.name, "\n")] = '\0';
      inhoa(k.name);
    	while(ktten(k.name))
	{
		printf("loi nhap!!!\nxin vui long nhap lai!!!\n");
		printf("ten khach hang : "); 
    	fgets(k.name,sizeof(k.name),stdin);
        k.name[strcspn(k.name, "\n")] = '\0';
        inhoa(k.name);
	}
      return k;
}
struct khachhang nhap3() // nhap sua so chung minh cua khach hang
{
	struct khachhang k;
	printf("thong tin can sua lai.\n");
	printf("so chung minh : ");
    fgets(k.scm,sizeof(k.scm),stdin);
    k.scm[strcspn(k.scm, "\n")] = '\0';
     while(ktscm(k.scm)==0||!ktlengthscm(k.scm))
     {
     	printf("loi nhap!!!\nxin vui long nhap lai!!!\n");
     	printf("so chung minh : ");
     	fgets(k.scm,sizeof(k.scm),stdin);
       k.scm[strcspn(k.scm, "\n")] = '\0';
	 }
    return k;
}
struct khachhang nhap4()// nhap sua gioi tinh cua khach hang
{
	struct khachhang k;
	printf("thong tin can sua lai.\n");
	printf("gioi tinh : ");
    fgets(k.gioitinh,sizeof(k.gioitinh),stdin);
    k.gioitinh[strcspn(k.gioitinh, "\n")] = '\0';
    inhoa(k.gioitinh);
    while(ktten(k.gioitinh)||!ktlengthgioitinh(k.gioitinh))
    {
    	printf("loi nhap!!!\nxin vui long nhap lai!!!\n");	
    	printf("gioi tinh : ");
       fgets(k.gioitinh,sizeof(k.gioitinh),stdin);
       k.gioitinh[strcspn(k.gioitinh, "\n")] = '\0';
       inhoa(k.gioitinh);
	}
    return k;
}
struct khachhang nhap5()// nhap sua so phong cua khach hang
{
	struct khachhang k;
	printf("thong tin can sua lai.\n");
	printf("so phong : ");
    fgets(k.sophong,sizeof(k.sophong),stdin);
    k.sophong[strcspn(k.sophong, "\n")] = '\0';
    inhoa(k.sophong);
     while(ktsophong(k.sophong)==0)    
    {
    	printf("loi nhap!!!\nxin vui long nhap lai!!!\n");	
   	    printf("so phong : ");
        fgets(k.sophong,sizeof(k.sophong),stdin);
        k.sophong[strcspn(k.sophong, "\n")] = '\0';
        inhoa(k.sophong);	
	}
    return k;
}
void menu() // menu chinh
{
	 	printf("\033[0;31m1. In danh sach cac thong tin cua tat ca cac khach hang.\n");
        printf("\033[0;36m2. Them 1 khach hang vao cuoi danh sach.\n");
        printf("\033[0;36m3. Them 1 khach hang vao dau danh sach.\n");
        printf("\033[0;33m4. Tim va hien thi thong tin khach hang.\n");
        printf("\033[0;95m5. kiem tra va sua thong tin khach hang.\n");
        printf("\033[0;93m6. Sap xep thu tu giam dan theo cac tieu chi khac nhau.\n");
        printf("\033[0;36m7. Chen khach hang tai 1 vi tri bat ki.\n");
        printf("\033[0;95m8. Xoa thong tin khach hang.\n");
        printf("\033[0;31m9. In ra bang thong ke.\n");
		printf("\033[0;91m10. ket thuc chuong trinh.\n");
}
void menu1()// menu tim kiem thong tin khach hang 
{
		printf("\033[0;31m1.ho va ten.\n");
        printf("\033[0;36m2.gioi tinh.\n");
        printf("3.ngay den.\n");
        printf("4.ngay di.\n");
        printf("\033[0;36m5.quay tro lai menu.\n");
}
void menu2() // chon gioi tinh
{
	printf("\n\033[0;31m1.Nam.\n");
    printf("\033[0;36m2.Nu.\n");	
    printf("\033[0;36m3.quay tro lai menu tim kiem thong tin khach hang.\n");
}
void menu3()// tim kiem theo ho va ta
{
	printf("\n\033[0;31m1.ho.\n");
    printf("\033[0;36m2.ten.\n");	
    printf("\033[0;36m3.ho va ten.\n");
 	printf("\033[0;36m4.quay tro lai menu tim kiem thong tin khach hang.\n");
}
void menu4() // sua thong tin khach hang
{
	printf("\n\033[0;31m1.ten.\n");
    printf("\033[0;36m2.so chung minh.\n");	
    printf("\033[0;36m3.gioi tinh.\n");
 	printf("\033[0;36m4.so phong.\n");
 	printf("5.ngay den va ngay di.\n");
 	printf("6.quay tro lai menu.\n");
}
void menu5()
{
	printf("\033[0;31m1.ho va ten.\n");
    printf("\033[0;36m2.ma hoa don.\n");	
    printf("\033[0;36m3.quay tro lai menu.\n");
}
void menu6()
{
	printf("\n\033[0;31m1.tang dan a->z.\n");
    printf("\033[0;36m2.giam dan z->a.\n");	
    printf("\033[0;36m3.quay tro lai menu sap xep khach hang.\n");
}

void menu7()
{
	printf("\n\033[0;31m1.tang dan.\n");
    printf("\033[0;36m2.giam dan.\n");	
    printf("\033[0;36m3.quay tro lai menu sap xep khach hang.\n");
}

void menu8()
{
	printf("\n\033[0;31m1.tiep tuc sua thong tin khach hang.\n");
    printf("\033[0;36m2.quay tro lai.\n");
}
void menu9()
{
	printf("\n\033[0;31m1.sua tung thong tin theo lua chon.\n");
    printf("\033[0;36m2.sua tat ca thong tin bi loi.\n");	
    printf("\033[0;36m3.quay tro lai menu chinh.\n");
}
void menu10()
{
	printf("\n\033[0;31m1.co.\n");
    printf("\033[0;36m2.khong.\n");	
}
void menux()
{
	printf("\nxoa theo:");
	printf("\n\033[0;31m1.ma hoa don.\n");
    printf("\033[0;36m2.ho va ten.\n");	
    printf("\033[0;36m3.gioi tinh.\n");
    printf("4.loai phong.\n");
    printf("5.ngay den.\n");
    printf("6.ngay di.\n"); 
    printf("\033[0;36m7.quay tro lai menu chinh.\n");
}
void enter()// enter de tiep tuc
{
	while(getchar() != '\n');
}
void swap(struct khachhang *a,struct khachhang *b)
{
	struct khachhang temp=*a;
	*a=*b;
	*b=temp;
}
void sapxeptheoten(struct Node *head) // sap xep ten theo thu tu tang dan tu a->z
{
	if(head==NULL || head->next==NULL)
	{
		return;
	}
	struct Node *c=malloc(sizeof(struct Node));
	struct Node *e=malloc(sizeof(struct Node));
	int d;
		do
		{
			d=0;
			c=head;
			while(c->next!=head)
			{
				e=c->next;
				// strcmp dung de so sanh 2 chuoi s1 va s2 strcmp(s1,s2)
			if(strcmp(c->data.name,e->data.name)>0)
			{
				swap(&c->data,&e->data);
				d=1; // da hoan doi vi tri
			}
			c=c->next;
			}
		}while(d);
}
void sapxeptheoten1(struct Node *head) // sap xep ten theo thu tu giam dan tu z->a
{
	if(head==NULL || head->next==NULL)
	{
		return;
	}
	struct Node *c=malloc(sizeof(struct Node));
	struct Node *e=malloc(sizeof(struct Node));
	int d;
		do
		{
			d=0;
			c=head;
			while(c->next!=head)
			{
				e=c->next;
				// strcmp dung de so sanh 2 chuoi s1 va s2 strcmp(s1,s2)
			if(strcmp(c->data.name,e->data.name)<0)
			{
				swap(&c->data,&e->data);
				d=1; // da hoan doi vi tri
			}
			c=c->next;
			}
		}while(d);
}
void sapxeptheomhd(struct Node *head) // sap xep mhd theo thu tu tang dan
{
	if(head==NULL || head->next==NULL)
	{
		return;
	}
	struct Node *c=malloc(sizeof(struct Node));
	struct Node *e=malloc(sizeof(struct Node));
	int d;
		do
		{
			d=0;
			c=head;
			int a=atoi(c->data.mhd);
			while(c->next!=head)
			{
				e=c->next;
				int b=atoi(e->data.mhd);
			if(a>b)
			{
				swap(&c->data,&e->data);
				d=1; // da hoan doi vi tri
			}
			c=c->next;
			}
		}while(d);
}
void sapxeptheomhd1(struct Node *head) // sap xep mhd theo thu tu giam dan
{
	if(head==NULL || head->next==NULL)
	{
		return;
	}
	struct Node *c=malloc(sizeof(struct Node));
	struct Node *e=malloc(sizeof(struct Node));
	int d;
		do
		{
			d=0;
			c=head;
			int a=atoi(c->data.mhd);
			while(c->next!=head)
			{
				e=c->next;
				int b=atoi(e->data.mhd);
			if(a<b)
			{
				swap(&c->data,&e->data);
				d=1; // da hoan doi vi tri
			}
			c=c->next;
			}
		}while(d);
}
void findname( struct Node *head, char *ten)// tim kiem khach hang theo ten
{

	
		if(head == NULL)
	{
		printf("rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{	
		if(strcmp(temp->data.name,ten)==0)
			{
			d=1;
			if(temp->data.ngaydi<temp->data.ngayden||temp->data.ngaydi>30||temp->data.ngayden>30)
			{
		
			printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
				
			}		
	// in ra thong tin khach hang
	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");

	if(temp->data.ngaydi>=temp->data.ngayden&&temp->data.ngaydi<=30&&temp->data.ngayden<=30)
	{
	int s=0;
	temp->data.loaiphong[0]=temp->data.sophong[0];
	if(temp->data.loaiphong[0]=='A')
	{
		s=400;
		temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
	}else if(temp->data.loaiphong[0]=='B')
	{
		s=300;
		temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
	} else
	{
		s=200;
		temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
	}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",temp->data.mhd,temp->data.name,temp->data.gioitinh,temp->data.scm,temp->data.sophong,temp->data.loaiphong,temp->data.ngayden,temp->data.ngaydi,temp->data.tienphong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	}
	temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}

void findgioitinh( struct Node *head, char *ten)// in ra khach hang co cung gioi tinh
{

	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
		if(head == NULL)
	{
		printf("rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{	
	if(strcmp(temp->data.gioitinh,ten)==0)
	{
		d=1;
	if(temp->data.ngaydi<temp->data.ngayden||temp->data.ngaydi>30||temp->data.ngayden>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
		
	}
	// in ra thong tin khach hang
	
	if(temp->data.ngaydi>temp->data.ngayden&&temp->data.ngaydi<=30&&temp->data.ngayden<=30)
	{
		int s=0;
		temp->data.loaiphong[0]=temp->data.sophong[0];
			if(temp->data.loaiphong[0]=='A')
				{
					s=400;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
				}else if(temp->data.loaiphong[0]=='B')
					{
					s=300;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
					} else
					{
					s=200;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
				}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",temp->data.mhd,temp->data.name,temp->data.gioitinh,temp->data.scm,temp->data.sophong,temp->data.loaiphong,temp->data.ngayden,temp->data.ngaydi,temp->data.tienphong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	
	}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}
void findngayden( struct Node *head, int ten)// in ra khach hang co cung ngay den
{

	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	{
		printf("rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{	
	if(temp->data.ngayden==ten)
	{
		d=1;
	if(temp->data.ngaydi<temp->data.ngayden||temp->data.ngaydi>30||temp->data.ngayden>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
		
	}
	// in ra thong tin khach hang
	
	if(temp->data.ngaydi>temp->data.ngayden&&temp->data.ngaydi<=30&&temp->data.ngayden<=30)
	{
		int s=0;
		temp->data.loaiphong[0]=temp->data.sophong[0];
			if(temp->data.loaiphong[0]=='A')
				{
					s=400;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
				}else if(temp->data.loaiphong[0]=='B')
					{
					s=300;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
					} else
					{
					s=200;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
				}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",temp->data.mhd,temp->data.name,temp->data.gioitinh,temp->data.scm,temp->data.sophong,temp->data.loaiphong,temp->data.ngayden,temp->data.ngaydi,temp->data.tienphong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	
	}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}

void findngaydi( struct Node *head, int ten)// in ra khach hang co cung ngay di
{

	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
		if(head == NULL)
	{
		printf("rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{	
	if(temp->data.ngaydi==ten)
	{
		d=1;
	if(temp->data.ngaydi<temp->data.ngayden||temp->data.ngaydi>30||temp->data.ngayden>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",temp->data.mhd);
		
	}
	// in ra thong tin khach hang
	
	if(temp->data.ngaydi>temp->data.ngayden&&temp->data.ngaydi<=30&&temp->data.ngayden<=30)
	{
		int s=0;
		temp->data.loaiphong[0]=temp->data.sophong[0];
			if(temp->data.loaiphong[0]=='A')
				{
					s=400;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
				}else if(temp->data.loaiphong[0]=='B')
					{
					s=300;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
					} else
					{
					s=200;
					temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
				}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",temp->data.mhd,temp->data.name,temp->data.gioitinh,temp->data.scm,temp->data.sophong,temp->data.loaiphong,temp->data.ngayden,temp->data.ngaydi,temp->data.tienphong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	
	}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}

void finds(struct Node *head,char *mhd)// sua thong tin khach hang dua tren ma hoa don 
{
	if(head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{
		if(strcmp(temp->data.mhd,mhd)==0)
		{
			d=1;
		int s=0;
	temp->data.loaiphong[0]=temp->data.sophong[0];
	if(temp->data.loaiphong[0]=='A')
	{
		s=400;
		temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
	}else if(temp->data.loaiphong[0]=='B')
	{
		s=300;
		temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
	} else
	{
		s=200;
		temp->data.tienphong=s*(temp->data.ngaydi - temp->data.ngayden+1);
	}
	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",temp->data.mhd,temp->data.name,temp->data.gioitinh,temp->data.scm,temp->data.sophong,temp->data.loaiphong,temp->data.ngayden,temp->data.ngaydi,temp->data.tienphong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	printf("%132s\033[1A","                                                             ");
    printf("\033[1A");
	enter();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
//	strcpy(temp->data.mhd,newkh.mhd);
//	strcpy(temp->data.name,newkh.name);
//	strcpy(temp->data.scm,newkh.scm);
//	strcpy(temp->data.gioitinh,newkh.gioitinh);
//	strcpy(temp->data.sophong,newkh.sophong);
	break;	
		}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
void ktrieng(struct Node *head,char *name)
{
	struct Node *temp=head;
	int d=0;
	printf("\nkhach hang ma hoa don la %-3s bi loi thong tin gom:\n",name);
	do 
	{	
		if(strcmp(temp->data.mhd,name)==0)
		{
	if(ktten(temp->data.name))
	{
		printf("ten khach hang: %-25s\n",temp->data.name);
		d=1;
	}
	if(ktsophong(temp->data.sophong)==0)
	{
		printf("so phong:%-4s\n",temp->data.sophong);
		d=1;
	}
	if(ktscm(temp->data.scm)==0||!ktlengthscm(temp->data.scm))
	{
		printf("so chung minh:%-12s\n",temp->data.scm);
		d=1;
	}
	if(ktten(temp->data.gioitinh)||!ktlengthgioitinh(temp->data.gioitinh))
	{
		d=1;
		printf("gioi tinh:%-3s\n",temp->data.gioitinh);
	}
	}
		temp=temp->next;
	}while(temp!=head);
	if(d==0)
	{
	system("cls"); 
	finds(temp,name);
	printf("\nthong tin khach hang hop le!!");
	}
}
void suaal(struct Node *head, char *mhd)// sua thong khach hang bang al
{
		if(head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{
		if(strcmp(temp->data.mhd,mhd)==0)
		{
			d=1;
			struct khachhang newkh;
	if(ktten(temp->data.name)) // sua ten
	{
		newkh=nhap2();
	strcpy(temp->data.name,newkh.name);
		d=1;
	}
	if(ktten(temp->data.gioitinh)||!ktlengthgioitinh(temp->data.gioitinh)) // sua gioi tinh
	{
		d=1;
		newkh=nhap4();
	strcpy(temp->data.gioitinh,newkh.gioitinh);
	}
	if(ktscm(temp->data.scm)==0||!ktlengthscm(temp->data.scm)) // sua scm
	{
		newkh=nhap3();
		strcpy(temp->data.scm,newkh.scm);
		d=1;
	}
	if(ktsophong(temp->data.sophong)==0) // sua so phong
	{
		newkh=nhap5();
		strcpy(temp->data.sophong,newkh.sophong);
		d=1;
	}
	if(temp->data.ngaydi<temp->data.ngayden||temp->data.ngaydi>30||temp->data.ngayden>30) // sua ngay den va ngay di
	{	
	d=1;
	newkh=nhap1();
	temp->data.ngayden=newkh.ngayden;
	temp->data.ngaydi=newkh.ngaydi;
	}
	
	break;	
		}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}
void suangaydenngaydi(struct Node *head, char *mhd)
{
		if(head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{
		if(strcmp(temp->data.mhd,mhd)==0)
		{
			d=1;
	struct khachhang newkh;
	newkh=nhap1();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
	temp->data.ngayden=newkh.ngayden;
	temp->data.ngaydi=newkh.ngaydi;
	break;	
		}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
void suaten(struct Node *head,char *mhd)// sua ten khach hang bi loi
{
	if(head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{
		if(strcmp(temp->data.mhd,mhd)==0)
		{
			d=1;
	struct khachhang newkh;
	newkh=nhap2();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
	strcpy(temp->data.name,newkh.name);
	break;	
		}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
void suascm(struct Node *head,char *mhd)// sua so chung minh cua khach hang bi loi
{
	if(head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{
		if(strcmp(temp->data.mhd,mhd)==0)
		{
			d=1;
	struct khachhang newkh;
	newkh=nhap3();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
	strcpy(temp->data.scm,newkh.scm);
	break;	
		}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
void suagioitinh(struct Node *head,char *mhd)// sua gioi tinh cua khach hang bi loi
{
	if(head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{
		if(strcmp(temp->data.mhd,mhd)==0)
		{
			d=1;
	struct khachhang newkh;
	newkh=nhap4();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
	strcpy(temp->data.gioitinh,newkh.gioitinh);
	break;	
		}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
void suasophong(struct Node *head,char *mhd)// sua so phong cua khach hang bi loi
{
	if(head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=head;
	int d=0;
	do
	{
		if(strcmp(temp->data.mhd,mhd)==0)
		{
			d=1;
	struct khachhang newkh;
	newkh=nhap5();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
	strcpy(temp->data.sophong,newkh.sophong);
	break;	
		}
		temp=temp->next;
	}while(temp!=head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
void xoamhd(struct Node **head, char *mhd)// xoa khach hang theo mhd
{
	if(*head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=*head;
	struct Node *prev=NULL;
	struct Node *t=*head;

	// tim head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *head);
     if (strcmp(temp->data.mhd,mhd) == 0) 
	 {
        if (temp->next == *head)
		 {

            free(temp);
            *head = NULL;
            return;
        }
        t->next = temp->next;
        *head = temp->next;
  
        free(temp);
        return;
    	}
		 do {
        prev =temp;
        temp = temp->next;
        if (strcmp(temp->data.mhd, mhd) == 0) {
        
            prev->next = temp->next;
            free(temp);
            return;
        }
    } while (temp != *head);


		 system("cls");
		printf("khong tim thay khach hang!!!");
}
void xoahvt(struct Node **head, char *name)// xoa khach hang theo ho va ten
{
	if(*head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=*head;
	struct Node *prev=NULL;
	struct Node *t=*head;

	// tim head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *head);
     if (strcmp(temp->data.name,name) == 0) 
	 {
        if (temp->next == *head)
		 {

            free(temp);
            *head = NULL;
            return;
        }
        t->next = temp->next;
        *head = temp->next;
  
        free(temp);
        return;
    	}
		 do {
        prev =temp;
        temp = temp->next;
        if (strcmp(temp->data.name, name) == 0) {
        
            prev->next = temp->next;
            free(temp);
            return;
        }
    } while (temp != *head);


		 system("cls");
		printf("khong tim thay khach hang!!!");
}
void xoaten(struct Node **head, char *ten)// xoa nhung khach hang co cung ho
{
	char name[50];
	if(*head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=*head;
	struct Node *prev=NULL;
	struct Node *t=*head;
	int d=0;
	// tim head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *head); 
    		
    // xoa nhung phan tu o dau danh sach neu cung ho
    layten(temp->data.name,name);
     while(temp!=t&&strcmp(name,ten) == 0) 
	 {
      struct Node *v =temp;
    	t->next=temp->next;
    	temp=temp->next;
    	*head=temp;
    	free(temp);
    	d++;
    	layten(temp->data.name,name);
  	}
  	// xoa o giua danh sach
		while(temp!=t)
		{
			layten(temp->data.name,name);
			if(strcmp(name,ten) == 0)
			{
				struct Node *v =temp;
    			prev->next=temp->next;
    			temp=temp->next;
    			free(temp);
    			d++;
			}else
			{
				prev=temp;
				temp=temp->next;
			}
		}
		// xoa o cuoi danh sach neu co
	layten(temp->data.name,name);
	if(strcmp(name,ten) == 0)
	{
		if(t==*head)
		{
			*head=NULL;
		}else
		{
			prev->next=t->next;
		}
		free(t);
		d++;
	}		
	if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}
void xoaho(struct Node **head, char *ten)// xoa nhung khach hang co cung ho
{
	char name[50];
	if(*head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=*head;
	struct Node *prev=NULL;
	struct Node *t=*head;
	int d=0;
	// tim head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *head); 
    		
    // xoa nhung phan tu o dau danh sach neu cung ho
    layho(temp->data.name,name);
     while(temp!=t&&strcmp(name,ten) == 0) 
	 {
      struct Node *v =temp;
    	t->next=temp->next;
    	temp=temp->next;
    	*head=temp;
    	free(temp);
    	d++;
    	layho(temp->data.name,name);
  	}
  	// xoa o giua danh sach
		while(temp!=t)
		{
			layho(temp->data.name,name);
			if(strcmp(name,ten) == 0)
			{
				struct Node *v =temp;
    			prev->next=temp->next;
    			temp=temp->next;
    			free(temp);
    			d++;
			}else
			{
				prev=temp;
				temp=temp->next;
			}
		}
	layho(temp->data.name,name);
	if(strcmp(name,ten) == 0)
	{
		if(t==*head)
		{
			*head=NULL;
		}else
		{
			prev->next=t->next;
		}
		free(t);
		d++;
	}		
	if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}
void xoagioitinh(struct Node **head, char *ten)// xoa nhung khach hang co cung gioitinh
{
	if(*head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=*head;
	struct Node *prev=NULL;
	struct Node *t=*head;
	
	// tim head cuoi cung
	while(t->next!=*head)
	{
		t=t->next;
	}
    // xoa nhung phan tu o dau danh sach neu cung ho
   int d=0;
     while(temp!=t&&strcmp(temp->data.gioitinh,ten) == 0) 
	 {
      	struct Node *v =temp;
    	t->next=temp->next;
    	temp=temp->next;
    	free(temp);
    	d=1;
    	*head=temp;
  	}	
		prev = temp;
    	temp = temp->next;
  	// xoa o giua danh sach
		while(temp!=t)
		{
			if(strcmp(temp->data.gioitinh,ten) == 0)
			{
				struct Node *v =temp;
    			prev->next=temp->next;
    			temp=temp->next;
    			free(v);
    			d=1;
			}else
			{
				prev=temp;
				temp=temp->next;
			}
		}
			
	if(strcmp(t->data.gioitinh,ten) == 0)
		{
		if(t==*head)
			{
		//	free(t);
			*head=NULL;
			}else
				{
				prev->next=t->next;
				}
			//	free(t);
		d=1;
		}		
	if (*head == NULL) {
    printf("Danh sach rong.\n");
} else {
    if (d == 0) {
        system("cls");
        printf("Khong tim thay khach hang!!!\n");
    }
}
}
void xoangayden(struct Node **head, int ten)// xoa nhung khach hang co cung ngayden
{
	char name[50];
	if(*head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=*head;
	struct Node *prev=NULL;
	struct Node *t=*head;
	int d=0;
	// tim head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *head); 
    		
    // xoa nhung phan tu o dau danh sach neu cung ho
     while(temp!=t&&(temp->data.ngayden==ten)) 
	 {
      struct Node *v =temp;
    	t->next=temp->next;
    	temp=temp->next;
    	*head=temp;
    	free(temp);
    	d++;
  	}
  	// xoa o giua danh sach
		while(temp!=t)
		{
			if((temp->data.ngayden==ten))
			{
				struct Node *v =temp;
    			prev->next=temp->next;
    			temp=temp->next;
    			free(temp);
    			d++;
			}else
			{
				prev=temp;
				temp=temp->next;
			}
		}
	if((temp->data.ngayden==ten))
	{
		if(t==*head)
		{
			*head=NULL;
		}else
		{
			prev->next=t->next;
		}
		free(t);
		d++;
	}		
	if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}
void xoangaydi(struct Node **head, int ten)// xoa nhung khach hang co cung ngaydi
{
	char name[50];
	if(*head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *temp=*head;
	struct Node *prev=NULL;
	struct Node *t=*head;
	int d=0;
	// tim head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *head); 
    		
    // xoa nhung phan tu o dau danh sach neu cung ho
     while(temp!=t&&(temp->data.ngaydi==ten)) 
	 {
      struct Node *v =temp;
    	t->next=temp->next;
    	temp=temp->next;
    	*head=temp;
    	free(temp);
    	d++;
  	}
  	// xoa o giua danh sach
		while(temp!=t)
		{
			if((temp->data.ngaydi==ten))
			{
				struct Node *v =temp;
    			prev->next=temp->next;
    			temp=temp->next;
    			free(temp);
    			d++;
			}else
			{
				prev=temp;
				temp=temp->next;
			}
		}
	if((temp->data.ngaydi==ten))
	{
		if(t==*head)
		{
			*head=NULL;
		}else
		{
			prev->next=t->next;
		}
		free(t);
		d++;
	}		
	if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}
void ktnhap(int sl,char *temp)
{
	int a=0,x;
	char b[50];
	int num=0;
	menu();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 10) {
            	
                printf("\n");
                break;
            } else {
                do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menu();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}

void ktnhap1(int sl,char *temp)
{
	int a=0,x;
	char b[50];
	int num=0;
	menu1();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 5) {
            	
                printf("\n");
                break;
            } else {
                do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menu1();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}

void ktnhap2(int sl,char *temp) // nhap theo gioi tinh
{
	int a=0,x;
	char b[50];
	int num=0;
	menu2();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } else {
            	do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                
                system("cls");
                menu2();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}

void ktnhap3(int sl,char *temp) // nhap theo ho va ten
{
	int a=0,x;
	char b[50];
	int num=0;
	menu3();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 4) {
            	
                printf("\n");
                break;
            } else {
                do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menu3();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}
void ktnhap4(int sl,char *temp) // nhap theo ho va ten
{
	int a=0,x;
	char b[50];
	int num=0;
	menu4();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 6) {
            	
                printf("\n");
                break;
            } else {
                do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menu4();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}
void ktnhap5(int sl,char *temp) // nhap menu sap xep theo hoa va ten
{
	int a=0,x;
	char b[50];
	int num=0;
	menu5();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } else {
                do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menu5();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}

void ktnhap6(int sl,char *temp) // nhap menu sap xep theo hoa va ten tang dan hoac giam dan
{
	int a=0,x;
	char b[50];
	int num=0;
	menu6();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } else {
                do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menu6();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}

void ktnhap7(int sl,char *temp) // nhap menu sap xep theo ma hoa don tang dan hoac giam dan
{
	int a=0,x;
	char b[50];
	int num=0;
	menu7();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } else {
               	do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menu7();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}
void ktnhap8(int sl,char *temp) // nhap menu sap xep theo ma hoa don tang dan hoac giam dan
{
	int a=0,x;
	char b[50];
	int num=0;
	menu8();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 2) {
            	
                printf("\n");
                break;
            } else {
               	do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menu8();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}
void ktnhap9(int sl,char *temp) // nhap menu sap xep theo ma hoa don tang dan hoac giam dan
{
	int a=0,x;
	char b[50];
	int num=0;
	menu9();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } else {
               	do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menu9();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}
void ktnhapx(int sl,char *temp) // nhap menu xoa khach hang
{
	int a=0,x;
	char b[50];
	int num=0;
	menux();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 7) {
            	
                printf("\n");
                break;
            } else {
               	do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menux();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}
void ktnhap10(int sl,char *temp) // nhap menu sap xep theo ma hoa don tang dan hoac giam dan
{
	int a=0,x;
	char b[50];
	int num=0;
	menu10();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        temp[a] = getch();
	
        if (temp[a] == '\r' || temp[a] == '\n') {
            
            temp[a] = '\0'; 
            num = atoi(temp);
            if (num >= 1 && num <= 2) {
            	
                printf("\n");
                break;
            } else {
               	do{
               	system("cls");
                printf("\nchuc nang ban chon khong co trong menu\nnhan 1 de quay lai: ");
    			fgets(b,sizeof(b),stdin);
    			b[strcspn(b, "\n")] = '\0';        
    			x=atoi(b);
            	}while(x!=1);
                system("cls");
                menu10();
				printf("\033[0mNhap lua chon: "); 
                a = 0;
                continue;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(temp[a]) && a < sl - 1) {
            putchar(temp[a]);
            a++;
        } else if (temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    temp[a] = '\0'; 
}
int main()
{
	
    struct Node *List = NULL;
    char x[3],y[2],z[2],t[3],h[2],a[2],b[2],c1[2],b1[2],v[2];
    int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
    int ngayden,ngaydi;
     system("cls");
    	read("quanlikhachsan2.txt",&List);
    	in(List);
    	printf("  %6s\033[1A","          ");
    	enter();
    struct khachhang k1;	

    int c,c2,c3,c4,c5,c6,c7,c8,c9,c10;
	char name[50];
    do {
     //  menu();
     ktnhap(3,x);
		x1=atoi(x);
        struct Node *List = NULL;
		read("quanlikhachsan2.txt",&List);
       system("cls");
		c=x1;
        switch(x1) // switch chinh
			{
        	 	case 1: // in ra thong tin khach hang
                  	in(List);
                    printf("%132s\033[1A","                                                     ");
                    enter();
               		break;
         	    case 2: // chen khach hang vao dau danh sach
                	k1=nhap();
                	chenc(&List, k1);
              		write("quanlikhachsan2.txt",List);   
                	printf("\033[1A");
                	enter();
               		break;
            	case 3:// chen khach hang vao cuoi danh sach
                	k1=nhap();
                	chend(&List, k1);
                	printf("\033[1A");
                	enter();
                	break;
           		case 4: // tim kiem va hien thi thong tin khach hang
            		do
            		{
            		printf("tim kiem theo : \n");
            		ktnhap1(2,y);
					x2=atoi(y);
					system("cls");
					c2=x2; 
            			switch(x2) // tim kiem va hien thi thong tin khach hang theo cac tieu chi khach nhau
            				{
            				case 1:
            					do
            					{
            						ktnhap3(2,t);
									x4=atoi(t);
									system("cls");
									c4=x4; 
									switch(x4) // tim kiem theo ho va ten
										{
										case 1:
												printf("ho khach hang :");
      											fgets(name,sizeof(name),stdin);
		       									name[strcspn(name,"\n")] ='\0';
		       									inhoa(name);
		       									findho(List,name);  
       			printf("%132s\033[1A","                                                        ");
       											printf("\033[1A");
       											enter();					
       											break;
										case 2:
												printf("ten khach hang :");
      											fgets(name,sizeof(name),stdin);
		       									name[strcspn(name,"\n")] ='\0';
		       									inhoa(name);
		       									findten(List,name);  
       		printf("%132s\033[1A","                                                        ");
       											printf("\033[1A");
       											enter();					
       											break;
										case 3:	
           										printf("ho va ten khach hang :");
      											fgets(name,sizeof(name),stdin);
		       									name[strcspn(name,"\n")] ='\0';
		       									inhoa(name);
		       									findname(List,name);  
       		printf("%132s\033[1A","                                                        ");
       		       								printf("\033[1A");
												enter();
												break;		
										default:	
												printf("");	
										}
								}while((0<c4)&&(c4<4));
								break;
							case 2:
							 	do
								{
							 	ktnhap2(2,z);
								x3=atoi(z);
								system("cls");
								c3=x3; 
									switch(x3)
									{
										case 1:
										findgioitinh(List,"Nam");
				printf("%132s\033[1A","                                                                       ");
				       					printf("\033[1A");
										enter();
										break;	
										case 2:
										findgioitinh(List,"Nu");
				printf("%132s\033[1A","                                                                      ");
		       							printf("\033[1A");
										enter();
										break;	
										default: 
										printf("");
									}
							 	}while((0<c3)&&(c3<3));
							 	break;
						    case 3:
								printf("ngay den: ");
								scanf("%d",&ngayden);
								getchar();
								findngayden(List,ngayden);
			printf("%132s\033[1A","                                                              ");
		       					printf("\033[1A");
								enter();
								break;	
							case 4:
								 printf("ngay di: ");
								 scanf("%d",&ngaydi);
								 getchar();
								 findngaydi(List,ngaydi);
			printf("%132s\033[1A","                                                             ");
		       					 printf("\033[1A");
								 enter();
								 break;
							default:
							printf("");
							}
        			}while((0<c2)&&(c2<5));
        			break;
				case 5: // kiem tra va sua thong tin khach hang
					do
					{	
					kt(List);
					printf("ma hoa don : ");
					fgets(name,sizeof(name),stdin);
       				name[strcspn(name, "\n")] = '\0';
       				finds(List,name);
       				ktrieng(List,name);
       				ktnhap9(2,b1);
					x9=atoi(b1);
					system("cls");
					c9=x9;
					switch(x9)
							{
       						case 1:
       							do
       							{
       							ktnhap4(2,c1);
								x8=atoi(c1);
								system("cls");
								c8=x8;
								switch(x8) // ten , scm, gioitinh,so phong,ngay den va ngay di
										{
										case 1:// ten
											ktrieng(List,name);
	       									suaten(List,name);
											write("quanlikhachsan2.txt",List);  
	       									printf("\033[1A");
											enter();
											do
											{
											ktnhap9(2,b1);
											x8=atoi(b1);
											system("cls");
											c8=x8;
											switch(x8)
													{
													case 1:
														c8=1;
														break;
													case 2:
														c8=6;
														break;
													default:
														printf("");
													}
											}while(c8!=6&&c8!=1);
										break;
										case 2:// scm
											ktrieng(List,name);
											suascm(List,name);
											write("quanlikhachsan2.txt",List);  
							       			printf("\033[1A");
											enter();
											do
											{
											ktnhap8(2,b1);
											x8=atoi(b1);
											system("cls");
											c8=x8;
											switch(x8)
													{
													case 1:
														c8=1;
														break;
													case 2:
														c8=6;
														break;
													default:
														printf("");
													}
											}while(c8!=6&&c8!=1);
										break;
										case 3:
											ktrieng(List,name);
											suagioitinh(List,name);
											write("quanlikhachsan2.txt",List);  
							       			printf("\033[1A");
											enter();
											do
											{
											ktnhap8(2,b1);
											x8=atoi(b1);
											system("cls");
											c8=x8;
											switch(x8)
													{
													case 1:
														c8=1;
														break;
													case 2:
														c8=6;
														break;
													default:
														printf("");
													}
											}while(c8!=6&&c8!=1);
										break;
										case 4:
											ktrieng(List,name);
											suasophong(List,name);
											write("quanlikhachsan2.txt",List);  
							       			printf("\033[1A");
											enter();
											do
											{
											ktnhap8(2,b1);
											x8=atoi(b1);
											system("cls");
											c8=x8;
											switch(x8)
													{
													case 1:
														c8=1;
														break;
													case 2:
														c8=6;
														break;
													default:
														printf("");
													}
											}while(c8!=6&&c8!=1);
										break;
										case 5:
										ktrieng(List,name);
										suangaydenngaydi(List,name);
										write("quanlikhachsan2.txt",List);  
						       			printf("\033[1A");
										enter();
										do
										{
										ktnhap8(2,b1);
										x8=atoi(b1);
										system("cls");
										c8=x8;
										switch(x8)
												{
												case 1:
													c8=1;
													break;
												case 2:
													c8=6;
													break;
												default:
													printf("");
												}
										}while(c8!=6&&c8!=1);
										break;
										default:
										printf("");
										}
								}while((0<c8)&&(c8<6));
								break;
							case 2:
							ktrieng(List,name);
							suaal(List,name);
							write("quanlikhachsan2.txt",List);  
				       		printf("\033[1A");
							enter();
							do
							{
							ktnhap8(2,b1);
							x8=atoi(b1);
							system("cls");
							c8=x8;
							switch(x8)
									{
									case 1:
										c8=2;
										break;
									case 2:
										c8=3;
										break;
									default:
										printf("");
									}
							}while(c8!=2&&c8!=3);
							break;
							default:
								printf("");
							} 
					}while((0<c9)&&(c9<3));
				break;
				case 6: // sao xep khach hang theo cac tieu chi khach nhau...
					do
					{
					printf("sap xep theo :\n");
	            	ktnhap5(2,h);
					x5=atoi(h);
					system("cls");
					c5=x5; 
					switch(x5)
							{
							case 1:	
								do
								{
								ktnhap6(2,a);
								x6=atoi(a);
								system("cls");
								c6=x6; 
								switch(x6)
										{
										case 1:
											sapxeptheoten(List);
											write("quanlikhachsan2.txt",List);   
											in(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											enter();
											break;
										case 2:
											sapxeptheoten1(List);
											write("quanlikhachsan2.txt",List);   
											in(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											enter();
											break;
										default:
											printf("");
										}
								}while((0<c6)&&(c6<3));
							break;
							case 2:
								do
								{
								ktnhap7(2,b);
								x7=atoi(b);
								system("cls");
								c7=x7; 
								switch(x7)
										{
										case 1:
											sapxeptheomhd(List);
											write("quanlikhachsan2.txt",List);   
											in(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											enter();
											break;
										case 2:
											sapxeptheomhd1(List);
											write("quanlikhachsan2.txt",List);   
											in(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											enter();
											break;	
										default:
											printf("");
										}
								}while((0<c7)&&(c7<3));	
							break;
							default:
								printf("");
							}
					}while((0<c5)&&(c5<3));
					break;
				case 7:
				printf("chuc nang them sau");
				break; 
				case 8: // chuc nang xoa khach hang theo cac tieu chi khach nhau.......
					do
            		{
            		ktnhapx(2,v);
					x10=atoi(v);
					system("cls");
					c10=x10; 
            			switch(x10) 
            				{
            			 	case 1:// xoa theo ma hoa don
	                			printf("ban co muon hien thi danh sach khach hang khong?");
	                			ktnhap10(2,v);
	                			x10=atoi(v);
	                			system("cls");
	                			if(x10==1) 
	                			{
								system("cls");
								in(List);
								}
	            			 	printf("\nma hoa don : ");
								fgets(name,sizeof(name),stdin);
	       						name[strcspn(name, "\n")] = '\0';		
	       						xoamhd(&List,name);
	       						write("quanlikhachsan2.txt",List);   
								in(List);
	       						printf("\033[1A");
								enter();
	       						break;
            				case 2:// xoa theo ho va ten chua xoa tren file luc gan nop roi go vao sau
            					do
            					{
            						ktnhap3(2,t);
									x4=atoi(t);
									system("cls");
									c4=x4; 
									switch(x4) 
											{
											case 1:
												printf("ban co muon hien thi danh sach khach hang khong?");
					                			ktnhap10(2,v);
					                			x10=atoi(v);
					                			system("cls");
					                			if(x10==1) 
					                			{
												system("cls");
												in(List);
												}
												printf("ho khach hang can xoa:");
      											fgets(name,sizeof(name),stdin);
		       									name[strcspn(name,"\n")] ='\0';
		       									inhoa(name);
		       									xoaho(&List,name);
		       									printf("ban co muon hien thi danh sach khach hang sau khi xoa khong?");
					                			ktnhap10(2,v);
					                			x10=atoi(v);
					                			system("cls");
					                			if(x10==1) 
					                			{
												system("cls");
												in(List);
												}
       			printf("%132s\033[1A","                                                        ");
       											printf("\033[1A");
       											enter();					
       											break;
											case 2:
												printf("ban co muon hien thi danh sach khach hang khong?");
					                			ktnhap10(2,v);
					                			x10=atoi(v);
					                			system("cls");
					                			if(x10==1) 
					                			{
												system("cls");
												in(List);
												}
												printf("ten khach hang can xoa:");
      											fgets(name,sizeof(name),stdin);
		       									name[strcspn(name,"\n")] ='\0';
		       									inhoa(name);
		       									xoaten(&List,name);
		       									printf("ban co muon hien thi danh sach khach hang sau khi xoa khong?");
					                			ktnhap10(2,v);
					                			x10=atoi(v);
					                			system("cls");
					                			if(x10==1) 
					                			{
												system("cls");
												in(List);
												}
       		printf("%132s\033[1A","                                                        ");
       											printf("\033[1A");
       											enter();					
       											break;
											case 3:	
												printf("ban co muon hien thi danh sach khach hang khong?");
					                			ktnhap10(2,v);
					                			x10=atoi(v);
					                			system("cls");
					                			if(x10==1) 
					                			{
												system("cls");
												in(List);
												}
           										printf("ho va ten khach hang can xoa:");
      											fgets(name,sizeof(name),stdin);
		       									name[strcspn(name,"\n")] ='\0';
		       									inhoa(name);
		       									xoahvt(&List,name);  
		       									printf("ban co muon hien thi danh sach khach hang sau khi xoa khong?");
					                			ktnhap10(2,v);
					                			x10=atoi(v);
					                			system("cls");
					                			if(x10==1) 
					                			{
												system("cls");
												in(List);
												}	
       		printf("%132s\033[1A","                                                        ");
       		       								printf("\033[1A");
												enter();
												break;		
											default:	
												printf("");	
											}
								}while((0<c4)&&(c4<4));
								break;
							case 3:
							 	do
								{
								printf("ban co muon hien thi danh sach khach hang khong?");
					            ktnhap10(2,v);
					            x10=atoi(v);
					            system("cls");
					            if(x10==1) 
					            {
								system("cls");
								in(List);
								}
							 	ktnhap2(2,z);
								x3=atoi(z);
								system("cls");
								c3=x3; 
									switch(x3)
									{
										case 1:// xoa gioi tinh Nam	
										xoagioitinh(&List,"Nam");
										printf("ban co muon hien thi danh sach khach hang sau khi xoa khong?");
					                	ktnhap10(2,v);
					                	x10=atoi(v);
					                	system("cls");
					                	if(x10==1) 
					                	{
									//	system("cls");
										in(List);
										}	
				printf("%132s\033[1A","                                                                       ");
				       					printf("\033[1A");
										enter();
										system("cls");
										break;	
										case 2:// xoa gioi tinh Nu
										xoagioitinh(&List,"Nu");
										printf("ban co muon hien thi danh sach khach hang sau khi xoa khong?");
					                	ktnhap10(2,v);
					                	x10=atoi(v);
					                	system("cls");
					                	if(x10==1) 
					                	{
									//	system("cls");
										in(List);
										}
				printf("%132s\033[1A","                                                                      ");
		       							printf("\033[1A");
										enter();
										system("cls");
										break;	
										default: 
										printf("");
									}
							 	}while((0<c3)&&(c3<3));
							 	break;
							case 4:
							break;
						    case 5:
								printf("ban co muon hien thi danh sach khach hang khong?");
					            ktnhap10(2,v);
					        	x10=atoi(v);
					            system("cls");
					            if(x10==1) 
					            {
								system("cls");
								in(List);
								}
								printf("ngay den: ");
								scanf("%d",&ngayden);
								getchar();
								xoangayden(&List,ngayden);
								printf("ban co muon hien thi danh sach khach hang sau khi xoa khong?");
					            ktnhap10(2,v);
					            x10=atoi(v);
					            system("cls");
					            if(x10==1) 
					            {
								system("cls");
								in(List);
								}
			printf("%132s\033[1A","                                                              ");
		       					printf("\033[1A");
								enter();
								break;	
							case 6:
								printf("ban co muon hien thi danh sach khach hang khong?");
					            ktnhap10(2,v);
					        	x10=atoi(v);
					            system("cls");
					            if(x10==1) 
					            {
								system("cls");
								in(List);
								}
								printf("ngay di: ");
								scanf("%d",&ngaydi);
								getchar();
								xoangaydi(&List,ngaydi);
								printf("ban co muon hien thi danh sach khach hang sau khi xoa khong?");
					            ktnhap10(2,v);
					            x10=atoi(v);
					            system("cls");
					            if(x10==1) 
					            {
								system("cls");
								in(List);
								}
			printf("%132s\033[1A","                                                             ");
		       					printf("\033[1A");
								enter();
								break;
							default:
							printf("");
							}
        			}while((0<c10)&&(c10<7));
        			break;
            	default:
                	printf("Ket thuc\n");
        	}
        
    } while ((0<c)&&(c<10));
    return 0;
	}
// hàm xóa khách hàng theo nhieu tieu chi khac nhau
// lam lai cai menu cho hoan thien hon
// sap xep theo tieu chi loai phong
// tim kiem theo tieu chi loai phong

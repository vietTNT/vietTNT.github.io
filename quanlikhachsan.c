#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h> // thu vien lam viec voi chuoi ki tu
#define MAX 100
#define MAX_LENGTH 12
#define MAX_LENGTH_1 3
#define MAX_LENGTH_2 4
struct Khach_Hang
{
    char MHD[MAX],Name[MAX],SCM[MAX],Gioi_Tinh[MAX],So_Phong[MAX],Loai_Phong[MAX];// ma hoa don, ten, so chung minh , gioi tinh , so phong
    int Tien_Phong,Ngay_Den,Ngay_Di; // ngay den , ngay di
};

struct Node
{
	struct Khach_Hang Data;
	struct Node *next;
	
};
// tao 
struct Node *Tao(struct Khach_Hang Data) // dua du lieu vao newNode
{
	struct Node *NewNode = malloc(sizeof(struct Node));
	if(NewNode !=NULL)
	{
		NewNode->Data=Data;
		NewNode->next=NULL;
	}
	return NewNode;
}
// chen vao danh sach khach hang
void Chen_Dau(struct Node **Head_Ref, struct Khach_Hang Data) // them vao dau danh sach
{
	struct Node *NewNode =Tao(Data);
	struct Node *tam=*Head_Ref;
	 if (NewNode == NULL) {
        printf("rong.\n");
        return;
    }
    if(*Head_Ref == NULL) 
	{
		// danh sach rong, NewNode them vao dau danh sach
		*Head_Ref=NewNode;
		NewNode->next=*Head_Ref;
	}else
	{
	NewNode->Data=Data;
	NewNode->next=*Head_Ref;
	while(tam->next!=*Head_Ref) // tim du lieu cuoi cung 
		{
			tam=tam->next;
		}
		tam->next=NewNode;
	*Head_Ref=NewNode;
	}

	
}

void Chen_Cuoi(struct Node **Head_Ref, struct Khach_Hang Data)// them vao cuoi danh sach
{
	struct Node *NewNode=Tao(Data); // khoi tao du lieu cho NewNode
	if(*Head_Ref == NULL) 
	{
		// danh sach rong, NewNode them vao dau danh sach
		*Head_Ref=NewNode;
		NewNode->next=*Head_Ref;
	}else
	{
		struct Node *last=*Head_Ref;
		while(last->next!=*Head_Ref) // tim du lieu cuoi cung 
		{
			last=last->next;
		}
		last->next=NewNode;
		NewNode->next=*Head_Ref; // quay lai node dau
	}
}

void Chen_Bat_Ki(struct Node **Head, struct Khach_Hang Data, int P) // chen vao vi tri bat ki
{
    struct Node *NewNode =Tao(Data);
    
    if (*Head == NULL)
	 	{
        NewNode->next = NewNode;
        *Head = NewNode;
    	} else 
			{
        	struct Node *Temp = *Head;
        	int i;
        
        if (P == 0) 
		{
            
            while (Temp->next != *Head) {
                Temp = Temp->next;
            }
            NewNode->next = *Head;
            Temp->next = NewNode;
            *Head = NewNode;
        } else 
			{
            for (i = 0; i < P - 1 && Temp->next != *Head; i++) 
			{
                Temp = Temp->next;
            }
            NewNode->next = Temp->next;
            Temp->next = NewNode;
        	}
    		}
}
// ham chuc nang
void Enter()// Enter de tiep tuc
{
	while(getchar() != '\n');
}
int KtSCM(char *s1)
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

void Xoa_ki_Tu(char *str)
{
    char *st, *s;
	// st la dau, s la cuoi
    if (str == NULL || *str == '\0') {
        return;
    }

   
    st= str;
    while (isspace((unsigned char)*st)) {
        st++;
    }

   if (*st == '\0') 
   {
        str[0] = '\0';
        return;
    }
    s = st + strlen(st) - 1;
    while (s > st && isspace((unsigned char)*s)) 
	{
        s--;
    }

   
    s[1] = '\0';

    
    if (st > str) {
        memmove(str, st, s - st + 2);  
    }
}
// xac minh hoc le thong tin khach hang va kiem tra
int Ktten(char *s)
{
	int len = strlen(s);
    
	if (len == 0) 
	{
        return 0; 
    }
	
    if (isspace(s[0]) || isspace(s[len - 1])) 
	{
        return 0; 
    }
	int i;
    for (i = 0; i < len; i++)
	{       
        if (!isalpha(s[i]) && !isspace(s[i])) 
		{
            return 0; 
        }
        
        if (i > 0 && isspace(s[i]) && isspace(s[i - 1])) 
		{
            return 0; 
        }
    }

    return 1; 
}

int KtlengthSCM(char *s2)
{
	return strlen(s2)==MAX_LENGTH;
}

int Xac_Minh_Hop_Le_MHD(char *s2)
{
	return strlen(s2)==MAX_LENGTH_1;
}

int Xac_Minh_Hop_le_So_Phong(char *s2)
{
	return strlen(s2)==MAX_LENGTH_2;
}

int KtlengthGioi_Tinh(char *s4)
{
	if(strcmp(s4,"Nam")==0||strcmp(s4,"Nu")==0)
	{
		return 1;
	} else return 0;
}

int KtSo_Phong(char *st)
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

void Kt(struct Node *Head)
{
	struct Node *Temp=Head;
	do 
	{	
	Xoa_ki_Tu(Temp->Data.MHD);
	Xoa_ki_Tu(Temp->Data.Name);
	Xoa_ki_Tu(Temp->Data.Gioi_Tinh);
	Xoa_ki_Tu(Temp->Data.SCM);
	Xoa_ki_Tu(Temp->Data.So_Phong);
	if(!Xac_Minh_Hop_Le_MHD(Temp->Data.MHD)||!(KtSCM(Temp->Data.MHD)))
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);	
	}else
	if(Temp->Data.Ngay_Di<Temp->Data.Ngay_Den||Temp->Data.Ngay_Di>30||Temp->Data.Ngay_Den>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
	}else
	if(Ktten(Temp->Data.Name)==0)
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
	}else
	if(KtSo_Phong(Temp->Data.So_Phong)==0||!Xac_Minh_Hop_le_So_Phong(Temp->Data.So_Phong))
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
	}else
	if(KtSCM(Temp->Data.SCM)==0)
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
	}else
	if(!KtlengthSCM(Temp->Data.SCM))
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);		
	}else
	if(Ktten(Temp->Data.Gioi_Tinh)==0)
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
	}else
	if(!KtlengthGioi_Tinh(Temp->Data.Gioi_Tinh))
	{
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);		
	}
		Temp=Temp->next;
	}while(Temp!=Head);
}		

int Xac_Minh_Hop_Le_Input(struct Node *Head, char *MHS)
{
		if(Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=Head;
	do
	{
		if(strcmp(Temp->Data.MHD,MHS)==0)
		{
			printf("ma hoa don khach hang da ton tai!!!");
			return 0;
		}else
		if(strcmp(Temp->Data.Name,MHS)==0)
		{
			printf("Ten khach hang da ton tai!!!");	
			return 0;
		}else
		if(strcmp(Temp->Data.SCM,MHS)==0)
		{
			printf("So Chung Minh khach hang da ton tai!!!");	
			return 0;
		}else
		if(strcmp(Temp->Data.So_Phong,MHS)==0)
		{
			printf("So Phong %d da co Khach Hang!!!",MHS);	
			return 0;
		};
	Temp=Temp->next;
	}while(Temp!=Head);
		return 1;
}

// xuat ra man hinh
void Output(struct Node *Head) // Output ra man hinh
{
	if(Head == NULL || Head->next==NULL)

	{
		printf("rong.\n");
		return;
	}
	struct Node *Temp=Head;
	
	// kiem tra thong tin khach hang
	Kt(Temp);
	// in ra thong tin khach hang
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	do 
	{
	Xoa_ki_Tu(Temp->Data.MHD);
	Xoa_ki_Tu(Temp->Data.Name);
	Xoa_ki_Tu(Temp->Data.Gioi_Tinh);
	Xoa_ki_Tu(Temp->Data.SCM);
	Xoa_ki_Tu(Temp->Data.So_Phong);	
	if(Temp->Data.Ngay_Di>=Temp->Data.Ngay_Den&&Temp->Data.Ngay_Di<=30&&Temp->Data.Ngay_Den<=30&&Ktten(Temp->Data.Name)==1&&KtSo_Phong(Temp->Data.So_Phong)==1&&KtSCM(Temp->Data.SCM)==1&&KtlengthSCM(Temp->Data.SCM)&&Ktten(Temp->Data.Gioi_Tinh)==1&&KtlengthGioi_Tinh(Temp->Data.Gioi_Tinh)&&Xac_Minh_Hop_Le_MHD(Temp->Data.MHD)&&KtSCM(Temp->Data.MHD))
	{
	int s=0;
	Temp->Data.Loai_Phong[0]=Temp->Data.So_Phong[0];
	if(Temp->Data.Loai_Phong[0]=='A')
	{
		s=400;
		Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
	}else if(Temp->Data.Loai_Phong[0]=='B')
	{
		s=300;
		Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
	} else
	{
		s=200;
		Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
	}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",Temp->Data.MHD,Temp->Data.Name,Temp->Data.Gioi_Tinh,Temp->Data.SCM,Temp->Data.So_Phong,Temp->Data.Loai_Phong,Temp->Data.Ngay_Den,Temp->Data.Ngay_Di,Temp->Data.Tien_Phong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	Temp=Temp->next;
	}while(Temp!=Head);
}
// lay ten va ho
void Lay_Ten(char *s,char *Name) // lay ten tu ho va ten
{
	char Temp[100];
	// tao mot ban sao cua ho va ten
	strncpy(Temp,s,sizeof(Temp)-1);
	Temp[sizeof(Temp)-1]='\0'; 
	// dung strtok de tach chuoi thanh cac tu
	char *t=strtok(Temp," ");
	char *n=t;
	
	while(t!=NULL)
	{
		n=t;
		t=strtok(NULL," "); // tach tiep tuc chuoi ban dau
	}
	// copy ten (t cuoi cung) vao Name 
	strncpy(Name,n,50);
	Name[49] = '\0'; // dam bao chuoi da ket thuc
}

void Lay_Ho(char *s,char *Name) // lay ho tu ho va ten
{
	char Temp[100];
	// tao mot ban sao cua ho va ten
	strncpy(Temp,s,sizeof(Temp)-1);
	Temp[sizeof(Temp)-1]='\0'; 
	// dung strtok de tach chuoi thanh cac tu
	char *t=strtok(Temp, " ");
	strncpy(Name, t, 50);
	Name[49] = '\0'; // dam bao chuoi da ket thuc
}
// tim kiem khach hang 
void Find_Ten( struct Node *Head, char *ten)// in ra khach hang co cung ten
{
	char Name[50];
	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
		if(Head == NULL)
	{
		printf("rong.\n");
		return;
	}
	struct Node *Temp=Head;
	int d=0;
	do
	{	
	Lay_Ten(Temp->Data.Name,Name);
	if(strcmp(Name,ten)==0)
	{
		d=1;
	if(Temp->Data.Ngay_Di<Temp->Data.Ngay_Den||Temp->Data.Ngay_Di>30||Temp->Data.Ngay_Den>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
		
	}
	// in ra thong tin khach hang
	
	if(Temp->Data.Ngay_Di>Temp->Data.Ngay_Den&&Temp->Data.Ngay_Di<=30&&Temp->Data.Ngay_Den<=30)
	{
		int s=0;
		Temp->Data.Loai_Phong[0]=Temp->Data.So_Phong[0];
			if(Temp->Data.Loai_Phong[0]=='A')
				{
					s=400;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}else if(Temp->Data.Loai_Phong[0]=='B')
					{
					s=300;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
					} else
					{
					s=200;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",Temp->Data.MHD,Temp->Data.Name,Temp->Data.Gioi_Tinh,Temp->Data.SCM,Temp->Data.So_Phong,Temp->Data.Loai_Phong,Temp->Data.Ngay_Den,Temp->Data.Ngay_Di,Temp->Data.Tien_Phong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	
	}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}

void Find_Ho( struct Node *Head, char *ten)// in ra khach hang co cung ho
{
	char Name[50];
	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
		if(Head == NULL)
	{
		printf("rong.\n");
		return;
	}
	struct Node *Temp=Head;
	int d=0;
	do
	{	
	Lay_Ho(Temp->Data.Name,Name);
	
	if(strcmp(Name,ten)==0)
	{
		d=1;
	if(Temp->Data.Ngay_Di<Temp->Data.Ngay_Den||Temp->Data.Ngay_Di>30||Temp->Data.Ngay_Den>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
		
	}
	// in ra thong tin khach hang
	
	if(Temp->Data.Ngay_Di>Temp->Data.Ngay_Den&&Temp->Data.Ngay_Di<=30&&Temp->Data.Ngay_Den<=30)
	{
		int s=0;
		Temp->Data.Loai_Phong[0]=Temp->Data.So_Phong[0];
			if(Temp->Data.Loai_Phong[0]=='A')
				{
					s=400;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}else if(Temp->Data.Loai_Phong[0]=='B')
					{
					s=300;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
					} else
					{
					s=200;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",Temp->Data.MHD,Temp->Data.Name,Temp->Data.Gioi_Tinh,Temp->Data.SCM,Temp->Data.So_Phong,Temp->Data.Loai_Phong,Temp->Data.Ngay_Den,Temp->Data.Ngay_Di,Temp->Data.Tien_Phong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	
	}
		Temp=Temp->next;
	}while(Temp!=Head);
	if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!%s",Name);
	}
}
//Tao doc file
void read(const char *fileName,struct Node **Head)
{
	FILE *f;
	struct Khach_Hang Data;
	f=fopen(fileName,"r");
	if (f==NULL)
		{
		printf("Khong the mo tep %s \n",fileName);
		return ;
		}
	char tmp[100]; 
    while (fgets(tmp, sizeof(tmp), f) != NULL)
	 		{	
        	struct Node *NewNode =Tao(Data);
       	 	if (NewNode == NULL) 
				{
            	printf("Khong du bo nho.\n");
            	fclose(f);
            	return ;
        		}
        
	char *token =strtok(tmp,",");	
		if(token!=NULL)
			{
			int i = 0;
  			while (isspace((unsigned char)token[i])) 
		  			{
                	i++;
            		}
            strncpy(NewNode->Data.MHD, token + i, 5);
            NewNode->Data.MHD[5] ='\0';
			}
		
		token=strtok(NULL,",");
		if(token!=NULL)
			{
				int i = 0;
  				while (isspace((unsigned char)token[i])) 
		  			{
                		i++;
            		}
				strncpy(NewNode->Data.Name,token,25);
				NewNode->Data.Name[25] = '\0';
				inhoa(NewNode->Data.Name); 
			}
		
		token=strtok(NULL,",");
		if(token!=NULL)
		{
			int i = 0;
  			while (isspace((unsigned char)token[i])) 
		  	{
                i++;
            }
			strncpy(NewNode->Data.SCM,token,15);
			NewNode->Data.SCM[15] = '\0';
		}
		token=strtok(NULL,",");
		if(token!=NULL)
			{
			int i = 0;
  			while (isspace((unsigned char)token[i])) 
		  		{
                i++;
            	}
			strncpy(NewNode->Data.Gioi_Tinh,token,50);
			NewNode->Data.Gioi_Tinh[4] = '\0';
			inhoa(NewNode->Data.Gioi_Tinh); 
		}
		token=strtok(NULL,",");
		if(token!=NULL)
			{
			int i = 0;
  			while (isspace((unsigned char)token[i])) 
		  		{
                i++;
            	}
			strncpy(NewNode->Data.So_Phong,token,50);
			NewNode->Data.So_Phong[50] = '\0';
			inhoa(NewNode->Data.So_Phong); 
			}
		
		token=strtok(NULL,",");
		if(token!=NULL)
			{
			int i = 0;
  			while (isspace((unsigned char)token[i])) 
		  		{
                i++;
            	}
	    	NewNode->Data.Ngay_Den=strtoul(token,NULL,10);
			}
			
		token=strtok(NULL,",");
		if(token!=NULL)
			{
			int i = 0;
  			while (isspace((unsigned char)token[i])) 
		  	{
                i++;
            }
	    NewNode->Data.Ngay_Di=strtoul(token,NULL,10);
	    
		}
		NewNode->next=NULL;
		Chen_Cuoi(Head,NewNode->Data);
   }
	fclose(f);
}
// ghi vao file
void write(const char *fileName,struct Node *Head)
{
	FILE *f;
	f=fopen(fileName,"w");
	if (f==NULL){
		printf("Khong the mo tep %s \n",fileName);
		return ;
	}
	
	struct Node *Temp=Head;
	do 
	{	
		fprintf(f,"%s,%s,%s,%s,%s,%d,%d\n",Temp->Data.MHD,Temp->Data.Name,Temp->Data.SCM,Temp->Data.Gioi_Tinh,Temp->Data.So_Phong,Temp->Data.Ngay_Den,Temp->Data.Ngay_Di);
	Temp=Temp->next;
	}while(Temp!=Head);
	fclose(f);
}


struct Khach_Hang Input() // Nhap du lieu vao 
{
	struct Khach_Hang k;
	struct Node *List = NULL;
	read("quanlikhachsan2.txt",&List);
	char T[20];
	printf("thong tin khach hang\n");
	// ma hoa don
    printf("ma hoa don :");
    fgets(k.MHD,sizeof(k.MHD),stdin);
    Xoa_ki_Tu(k.MHD);
    k.MHD[strcspn(k.MHD, "\n")] = '\0';        
	while((!Xac_Minh_Hop_Le_MHD(k.MHD))||KtSCM(k.MHD)==0)
		{
		printf("loi Nhap!!!\nxin vui long Nhap lai!!!");
		Enter();
		system("cls");
		printf("thong tin khach hang\n");	
		printf("ma hoa don :");
   		fgets(k.MHD,sizeof(k.MHD),stdin);
    	Xoa_ki_Tu(k.MHD);
    	k.MHD[strcspn(k.MHD, "\n")] = '\0';        
		}
		
	while(Xac_Minh_Hop_Le_Input(List,k.MHD)==0)
		{
		printf("\nxin vui long Nhap lai!!!");
		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :");
   		fgets(k.MHD,sizeof(k.MHD),stdin);
    	Xoa_ki_Tu(k.MHD);
    	k.MHD[strcspn(k.MHD, "\n")] = '\0';        
		}
	// ten khach hang
    printf("ten khach hang : "); 
    fgets(k.Name,sizeof(k.Name),stdin);
    Xoa_ki_Tu(k.Name);
    k.Name[strcspn(k.Name, "\n")] = '\0';
    inhoa(k.Name);
      
	while(Ktten(k.Name)==0)
		{
		printf("loi Nhap!!!\nxin vui long Nhap lai!!!");
		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s",k.MHD);
		printf("ten khach hang : "); 
    	fgets(k.Name,sizeof(k.Name),stdin);
        k.Name[strcspn(k.Name, "\n")] = '\0';
        inhoa(k.Name);
		}

	while(Xac_Minh_Hop_Le_Input(List,k.Name)==0)
		{
		printf("\nxin vui long Nhap lai!!!");	
		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s\n",k.MHD);
		printf("ten khach hang : "); 
    	fgets(k.Name,sizeof(k.Name),stdin);
        k.Name[strcspn(k.Name, "\n")] = '\0';
        inhoa(k.Name);       
		}
  	// so chung minh
    printf("so chung minh : ");
    fgets(k.SCM,sizeof(k.SCM),stdin);
    Xoa_ki_Tu(k.SCM);
    k.SCM[strcspn(k.SCM, "\n")] = '\0';
    Xoa_ki_Tu(k.SCM); 
    while(KtSCM(k.SCM)==0||!KtlengthSCM(k.SCM))
     	{
     	printf("loi Nhap!!!\nxin vui long Nhap lai!!!");
     	Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s\n",k.MHD);
		printf("ten khach hang :%s\n",k.Name); 
     	printf("so chung minh : ");
     	fgets(k.SCM,sizeof(k.SCM),stdin);
       	k.SCM[strcspn(k.SCM, "\n")] = '\0';
	 	}
	 	
	while(Xac_Minh_Hop_Le_Input(List,k.SCM)==0)
		{
		printf("\nxin vui long Nhap lai!!!");
		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s\n",k.MHD);
		printf("ten khach hang :%s\n",k.Name); 	
		printf("so chung minh : ");
     	fgets(k.SCM,sizeof(k.SCM),stdin);
       	k.SCM[strcspn(k.SCM, "\n")] = '\0';    
		}
		
    printf("gioi tinh : ");
    fgets(k.Gioi_Tinh,sizeof(k.Gioi_Tinh),stdin);
    Xoa_ki_Tu(k.Gioi_Tinh);
    k.Gioi_Tinh[strcspn(k.Gioi_Tinh, "\n")] = '\0';
    inhoa(k.Gioi_Tinh);
    Xoa_ki_Tu(k.Gioi_Tinh);
    while(Ktten(k.Gioi_Tinh)==0||!KtlengthGioi_Tinh(k.Gioi_Tinh))
    	{
    	printf("loi Nhap!!!\nxin vui long Nhap lai!!!");
		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s\n",k.MHD);
		printf("ten khach hang :%s\n",k.Name); 
		printf("so chung minh :%s\n",k.SCM);	
    	printf("gioi tinh : ");
      	fgets(k.Gioi_Tinh,sizeof(k.Gioi_Tinh),stdin);
      	k.Gioi_Tinh[strcspn(k.Gioi_Tinh, "\n")] = '\0';
       	inhoa(k.Gioi_Tinh);
		}
	
    printf("so phong : ");
    fgets(k.So_Phong,sizeof(k.So_Phong),stdin);
    k.So_Phong[strcspn(k.So_Phong, "\n")] = '\0';
    inhoa(k.So_Phong);
    Xoa_ki_Tu(k.So_Phong);
    while(KtSo_Phong(k.So_Phong)==0||!(Xac_Minh_Hop_le_So_Phong(k.So_Phong)))   
    {
    	printf("loi Nhap!!!\nxin vui long Nhap lai!!!");
		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s\n",k.MHD);
		printf("ten khach hang :%s\n",k.Name); 
		printf("so chung minh :%s\n",k.SCM);	
    	printf("gioi tinh :%s\n",k.Gioi_Tinh);	
   	    printf("so phong : ");
        fgets(k.So_Phong,sizeof(k.So_Phong),stdin);
        k.So_Phong[strcspn(k.So_Phong, "\n")] = '\0';
        inhoa(k.So_Phong);	
	}
	
	while(Xac_Minh_Hop_Le_Input(List,k.So_Phong)==0)
		{
		printf("\nxin vui long Nhap lai!!!");	
		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s\n",k.MHD);
		printf("ten khach hang :%s\n",k.Name); 
		printf("so chung minh :%s\n",k.SCM);	
    	printf("gioi tinh :%s\n",k.Gioi_Tinh);	
		printf("so phong : ");
        fgets(k.So_Phong,sizeof(k.So_Phong),stdin);
        k.So_Phong[strcspn(k.So_Phong, "\n")] = '\0';
        inhoa(k.So_Phong);   
		}
		
    printf("ngay den : ");
   	scanf("%d",&k.Ngay_Den);
    getchar();
    
    while(k.Ngay_Den>30||k.Ngay_Den<1)
   		{
   		printf("loi Nhap!!!\nxin vui long Nhap lai!!!");
   		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s\n",k.MHD);
		printf("ten khach hang :%s\n",k.Name); 
		printf("so chung minh :%s\n",k.SCM);	
    	printf("gioi tinh :%s\n",k.Gioi_Tinh);	
		printf("so phong :%s\n",k.So_Phong);
		printf("ngay den : ");
   		scanf("%d",&k.Ngay_Den);
    	getchar();	
		}
		
    printf("ngay di : ");
   	scanf("%d",&k.Ngay_Di);
   	getchar();
   	
   	while(k.Ngay_Di<k.Ngay_Den||k.Ngay_Di>30||k.Ngay_Di<1)
   		{
   		printf("loi Nhap!!!\nxin vui long Nhap lai!!!");
   		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s\n",k.MHD);
		printf("ten khach hang :%s\n",k.Name); 
		printf("so chung minh :%s\n",k.SCM);	
    	printf("gioi tinh :%s\n",k.Gioi_Tinh);	
		printf("so phong :%s\n",k.So_Phong);
		printf("ngay den :%d\n",k.Ngay_Den);
    	printf("ngay di : ");
   		scanf("%d",&k.Ngay_Di);
   		getchar();  	
		}
		
    return k;
}
struct Khach_Hang Nhap_Moi_MHD() // Nhap du lieu vao 
{
	struct Khach_Hang k;
	struct Node *List = NULL;
	read("quanlikhachsan2.txt",&List);
	char T[20];
	printf("thong tin khach hang\n");
	
    printf("ma hoa don :");
    fgets(k.MHD,sizeof(k.MHD),stdin);
    Xoa_ki_Tu(k.MHD);
    k.MHD[strcspn(k.MHD, "\n")] = '\0';        
	while((!Xac_Minh_Hop_Le_MHD(k.MHD))||KtSCM(k.MHD)==0)
		{
		printf("loi Nhap!!!\nxin vui long Nhap lai!!!");
		Enter();
		system("cls");
		printf("thong tin khach hang\n");	
		printf("ma hoa don :");
   		fgets(k.MHD,sizeof(k.MHD),stdin);
    	Xoa_ki_Tu(k.MHD);
    	k.MHD[strcspn(k.MHD, "\n")] = '\0';        
		}
		
	while(Xac_Minh_Hop_Le_Input(List,k.MHD)==0)
		{
		printf("\nxin vui long Nhap lai!!!");
		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :");
   		fgets(k.MHD,sizeof(k.MHD),stdin);
    	Xoa_ki_Tu(k.MHD);
    	k.MHD[strcspn(k.MHD, "\n")] = '\0';        
		}
}
struct Khach_Hang Nhap_Moi_Name() // Nhap sua ten khach hang
{
	struct Khach_Hang k;
	struct Node *List = NULL;
	read("quanlikhachsan2.txt",&List);
	char T[20];
	printf("thong tin khach hang\n");
	printf("ten khach hang : "); 
    fgets(k.Name,sizeof(k.Name),stdin);
    Xoa_ki_Tu(k.Name);
    k.Name[strcspn(k.Name, "\n")] = '\0';
    inhoa(k.Name);
      
	while(Ktten(k.Name)==0)
		{
		printf("loi Nhap!!!\nxin vui long Nhap lai!!!");
		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s",k.MHD);
		printf("ten khach hang : "); 
    	fgets(k.Name,sizeof(k.Name),stdin);
        k.Name[strcspn(k.Name, "\n")] = '\0';
        inhoa(k.Name);
		}

	while(Xac_Minh_Hop_Le_Input(List,k.Name)==0)
		{
		printf("\nxin vui long Nhap lai!!!");	
		Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ten khach hang : "); 
    	fgets(k.Name,sizeof(k.Name),stdin);
        k.Name[strcspn(k.Name, "\n")] = '\0';
        inhoa(k.Name);       
		}
      return k;
}
struct Khach_Hang Nhap_Moi_SCM() // Nhap sua so chung minh cua khach hang
{
	struct Khach_Hang k;
     printf("so chung minh : ");
    fgets(k.SCM,sizeof(k.SCM),stdin);
    Xoa_ki_Tu(k.SCM);
    k.SCM[strcspn(k.SCM, "\n")] = '\0';
    Xoa_ki_Tu(k.SCM); 
    while(KtSCM(k.SCM)==0||!KtlengthSCM(k.SCM))
     	{
     	printf("loi Nhap!!!\nxin vui long Nhap lai!!!");
     	Enter();
		system("cls");
		printf("thong tin khach hang\n");		
		printf("ma hoa don :%s\n",k.MHD);
		printf("ten khach hang :%s\n",k.Name); 
     	printf("so chung minh : ");
     	fgets(k.SCM,sizeof(k.SCM),stdin);
       	k.SCM[strcspn(k.SCM, "\n")] = '\0';
	 	}
    return k;
}
struct Khach_Hang Nhap_Moi_Gioi_Tinh()// Nhap sua gioi tinh cua khach hang
{
	struct Khach_Hang k;
	printf("thong tin can sua lai.\n");
	printf("gioi tinh : ");
    fgets(k.Gioi_Tinh,sizeof(k.Gioi_Tinh),stdin);
    k.Gioi_Tinh[strcspn(k.Gioi_Tinh, "\n")] = '\0';
    inhoa(k.Gioi_Tinh);
    while(Ktten(k.Gioi_Tinh)==0||!KtlengthGioi_Tinh(k.Gioi_Tinh))
    {
    	printf("loi Nhap!!!\nxin vui long Nhap lai!!!\n");	
    	printf("gioi tinh : ");
       fgets(k.Gioi_Tinh,sizeof(k.Gioi_Tinh),stdin);
       k.Gioi_Tinh[strcspn(k.Gioi_Tinh, "\n")] = '\0';
       inhoa(k.Gioi_Tinh);
	}
    return k;
}
struct Khach_Hang Nhap_Moi_Ngay_Den_Va_Ngay_Di() // Nhap sua thong tin khach hang ngay den or ngay di
{
	struct Khach_Hang k;
	printf("thong tin can sua lai.\n");
	printf("\nngay den : ");
   	scanf("%d",&k.Ngay_Den);
    getchar();
    while(k.Ngay_Di<k.Ngay_Den||k.Ngay_Di>30||k.Ngay_Den>30)
   	{
   		printf("loi Nhap!!!\nxin vui long Nhap lai!!!\n");
		printf("ngay den : ");
   		scanf("%d",&k.Ngay_Den);
    	getchar();	
	}
    printf("ngay di : ");
   	scanf("%d",&k.Ngay_Di);
   	getchar();
   	while(k.Ngay_Di<k.Ngay_Den||k.Ngay_Di>30||k.Ngay_Den>30)
   	{
   		printf("loi Nhap!!!\nxin vui long Nhap lai!!!\n");
    	printf("ngay di : ");
   		scanf("%d",&k.Ngay_Di);
   		getchar();  	
	}
        return k;
}
struct Khach_Hang Nhap5()// Nhap sua so phong cua khach hang
{
	struct Khach_Hang k;
	printf("thong tin can sua lai.\n");
	printf("so phong : ");
    fgets(k.So_Phong,sizeof(k.So_Phong),stdin);
    k.So_Phong[strcspn(k.So_Phong, "\n")] = '\0';
    inhoa(k.So_Phong);
     while(KtSo_Phong(k.So_Phong)==0)    
    {
    	printf("loi Nhap!!!\nxin vui long Nhap lai!!!\n");	
   	    printf("so phong : ");
        fgets(k.So_Phong,sizeof(k.So_Phong),stdin);
        k.So_Phong[strcspn(k.So_Phong, "\n")] = '\0';
        inhoa(k.So_Phong);	
	}
    return k;
}
// bang Menu
void  Menu() //  Menu chinh
{
	 	printf("\033[0;31m1. In danh sach cac thong tin cua tat ca cac khach hang.\n");
        printf("\033[0;36m2. Them 1 khach hang vao cuoi danh sach.\n");
        printf("\033[0;36m3. Them 1 khach hang vao dau danh sach.\n");
        printf("\033[0;36m4. Them khach hang tai 1 vi tri bat ki.\n");
        printf("\033[0;33m5. Tim va hien thi thong tin khach hang.\n");
        printf("\033[0;95m6. kiem tra va sua thong tin khach hang.\n");
        printf("\033[0;93m7. Sap xep thu tugiam dan theo cac tieu chi khac nhau.\n");
        printf("\033[0;95m8. Xoa thong tin khach hang.\n");
        printf("\033[0;31m9. Nhap vao file moi va thao tac tren file do.\n");
		printf("\033[0;91m10. ket thuc chuong trinh.\n");
}

void  Menu_File_Bat_Ki() //  Menu file bat ki
{
	 	printf("\033[0;31m1. In danh sach cac thong tin cua tat ca cac khach hang.\n");
        printf("\033[0;36m2. Them 1 khach hang vao cuoi danh sach.\n");
        printf("\033[0;36m3. Them 1 khach hang vao dau danh sach.\n");
        printf("\033[0;36m4. Them khach hang tai 1 vi tri bat ki.\n");
        printf("\033[0;33m5. Tim va hien thi thong tin khach hang.\n");
        printf("\033[0;95m6. kiem tra va sua thong tin khach hang.\n");
        printf("\033[0;93m7. Sap xep thu tu giam dan theo cac tieu chi khac nhau.\n");
        printf("\033[0;95m8. Xoa thong tin khach hang.\n");
		printf("\033[0;91m9. Quay lai Menu.\n");
}

void  Menu_Tim_Kiem()//  Menu tim kiem thong tin khach hang 
{
		printf("\033[0;31m1.ho va ten.\n");
        printf("\033[0;36m2.gioi tinh.\n");
        printf("3.ngay den.\n");
        printf("4.ngay di.\n");
        printf("\033[0;36m5.quay tro lai Menu.\n");
}

void  Menu_Gioi_Tinh() // chon gioi tinh
{
	printf("\n\033[0;31m1.Nam.\n");
    printf("\033[0;36m2.Nu.\n");	
    printf("\033[0;36m3.quay tro lai  Menu tim kiem thong tin khach hang.\n");
}

void  Menu_Tim_Kiem_Ho_Va_Ten()// tim kiem theo ho va ta
{
	printf("\n\033[0;31m1.ho.\n");
    printf("\033[0;36m2.ten.\n");	
    printf("\033[0;36m3.ho va ten.\n");
 	printf("\033[0;36m4.quay tro lai  Menu tim kiem thong tin khach hang.\n");
}

void  Menu_Sua_Thong_Tin() // sua thong tin khach hang
{
	printf("\n\033[0;31m1.ten.\n");
    printf("\033[0;36m2.so chung minh.\n");	
    printf("\033[0;36m3.gioi tinh.\n");
 	printf("\033[0;36m4.so phong.\n");
 	printf("5.ngay den va ngay di.\n");
 	printf("6.quay tro lai Menu.\n");
}
void  Menu5()
{
	printf("\033[0;31m1.ho va ten.\n");
    printf("\033[0;36m2.ma hoa don.\n");	
    printf("\033[0;36m3.quay tro lai Menu.\n");
}
void  Menu6()
{
	printf("\n\033[0;31m1.tang dan a->z.\n");
    printf("\033[0;36m2.giam dan z->a.\n");	
    printf("\033[0;36m3.quay tro lai  Menu sap xep khach hang.\n");
}

void  Menu7()
{
	printf("\n\033[0;31m1.tang dan.\n");
    printf("\033[0;36m2.giam dan.\n");	
    printf("\033[0;36m3.quay tro lai  Menu sap xep khach hang.\n");
}

void  Menu8()
{
	printf("\n\033[0;31m1.tiep tuc sua thong tin khach hang.\n");
    printf("\033[0;36m2.quay tro lai Menu sua thong tin khach hang.\n");
    printf("3.quay lai Menu chinh.\n");
}
void  Menu9()
{
	printf("\n\033[0;31m1.sua tung thong tin theo lua chon.\n");
    printf("\033[0;36m2.sua tat ca thong tin bi loi.\n");	
    printf("\033[0;36m3.quay tro lai Menu chinh.\n");
}
void  Menu10()
{
	printf("\n\033[0;31m1.co.\n");
    printf("\033[0;36m2.khong.\n");	
}
void  Menux()
{
	printf("\nxoa theo:");
	printf("\n\033[0;31m1.ma hoa don.\n");
    printf("\033[0;36m2.ho va ten.\n");	
    printf("\033[0;36m3.gioi tinh.\n");
    printf("4.loai phong.\n");
    printf("5.ngay den.\n");
    printf("6.ngay di.\n"); 
    printf("\033[0;36m7.quay tro lai Menu chinh.\n");
}
void swap(struct Khach_Hang *a,struct Khach_Hang *b)
{
	struct Khach_Hang Temp=*a;
	*a=*b;
	*b=Temp;
}
void sapxeptheoten(struct Node *Head) // sap xep ten theo thu tu tang dan tu a->z
{
	if(Head==NULL || Head->next==NULL)
	{
		return;
	}
	struct Node *c=malloc(sizeof(struct Node));
	struct Node *e=malloc(sizeof(struct Node));
	int d;
		do
		{
			d=0;
			c=Head;
			while(c->next!=Head)
			{
				e=c->next;
				// strcmp dung de so sanh 2 chuoi s1 va s2 strcmp(s1,s2)
			if(strcmp(c->Data.Name,e->Data.Name)>0)
			{
				swap(&c->Data,&e->Data);
				d=1; // da hoan doi vi tri
			}
			c=c->next;
			}
		}while(d);
}
void sapxeptheoten1(struct Node *Head) // sap xep ten theo thu tu giam dan tu z->a
{
	if(Head==NULL || Head->next==NULL)
	{
		return;
	}
	struct Node *c=malloc(sizeof(struct Node));
	struct Node *e=malloc(sizeof(struct Node));
	int d;
		do
		{
			d=0;
			c=Head;
			while(c->next!=Head)
			{
				e=c->next;
				// strcmp dung de so sanh 2 chuoi s1 va s2 strcmp(s1,s2)
			if(strcmp(c->Data.Name,e->Data.Name)<0)
			{
				swap(&c->Data,&e->Data);
				d=1; // da hoan doi vi tri
			}
			c=c->next;
			}
		}while(d);
}
void sapxeptheoMHD(struct Node *Head) // sap xep MHD theo thu tu tang dan
{
	if(Head==NULL || Head->next==NULL)
	{
		return;
	}
	struct Node *c;
	struct Node *e;
	int d;
		do
		{
			d=0;
			c=Head;
			do
			{
			e=c->next;
			int a=atoi(c->Data.MHD);
			int b=atoi(e->Data.MHD);
			if(a>b)
			{
				swap(&c->Data,&e->Data);
				d=1; // da hoan doi vi tri
			}
			c=c->next;
			}while(c->next!=Head);
		}while(d);
}
void sapxeptheoMHD1(struct Node *Head) // sap xep MHD theo thu tu giam dan
{
	if(Head==NULL || Head->next==NULL)
	{
		return;
	}
	struct Node *c;
	struct Node *e;
	int d;
		do
		{
			d=0;
			c=Head;
			do
			{
			e=c->next;
			int a=atoi(c->Data.MHD);
			int b=atoi(e->Data.MHD);
			if(a<b)
			{
				swap(&c->Data,&e->Data);
				d=1; // da hoan doi vi tri
			}
			c=c->next;
			}while(c->next!=Head);
		}while(d);
}
void Find_Name( struct Node *Head, char *ten)// tim kiem khach hang theo ten
{

	
		if(Head == NULL)
	{
		printf("rong.\n");
		return;
	}
	struct Node *Temp=Head;
	int d=0;
	do
	{	
		if(strcmp(Temp->Data.Name,ten)==0)
			{
			d=1;
			if(Temp->Data.Ngay_Di<Temp->Data.Ngay_Den||Temp->Data.Ngay_Di>30||Temp->Data.Ngay_Den>30)
			{
		
			printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
				
			}		
	// in ra thong tin khach hang
	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");

	if(Temp->Data.Ngay_Di>=Temp->Data.Ngay_Den&&Temp->Data.Ngay_Di<=30&&Temp->Data.Ngay_Den<=30)
	{
	int s=0;
	Temp->Data.Loai_Phong[0]=Temp->Data.So_Phong[0];
	if(Temp->Data.Loai_Phong[0]=='A')
	{
		s=400;
		Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
	}else if(Temp->Data.Loai_Phong[0]=='B')
	{
		s=300;
		Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
	} else
	{
		s=200;
		Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
	}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",Temp->Data.MHD,Temp->Data.Name,Temp->Data.Gioi_Tinh,Temp->Data.SCM,Temp->Data.So_Phong,Temp->Data.Loai_Phong,Temp->Data.Ngay_Den,Temp->Data.Ngay_Di,Temp->Data.Tien_Phong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	}
	Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}

void Find_Gioi_Tinh( struct Node *Head, char *ten)// in ra khach hang co cung gioi tinh
{

	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
		if(Head == NULL)
	{
		printf("rong.\n");
		return;
	}
	struct Node *Temp=Head;
	int d=0;
	do
	{	
	if(strcmp(Temp->Data.Gioi_Tinh,ten)==0)
	{
		d=1;
	if(Temp->Data.Ngay_Di<Temp->Data.Ngay_Den||Temp->Data.Ngay_Di>30||Temp->Data.Ngay_Den>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
		
	}
	// in ra thong tin khach hang
	
	if(Temp->Data.Ngay_Di>Temp->Data.Ngay_Den&&Temp->Data.Ngay_Di<=30&&Temp->Data.Ngay_Den<=30)
	{
		int s=0;
		Temp->Data.Loai_Phong[0]=Temp->Data.So_Phong[0];
			if(Temp->Data.Loai_Phong[0]=='A')
				{
					s=400;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}else if(Temp->Data.Loai_Phong[0]=='B')
					{
					s=300;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
					} else
					{
					s=200;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",Temp->Data.MHD,Temp->Data.Name,Temp->Data.Gioi_Tinh,Temp->Data.SCM,Temp->Data.So_Phong,Temp->Data.Loai_Phong,Temp->Data.Ngay_Den,Temp->Data.Ngay_Di,Temp->Data.Tien_Phong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	
	}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}
void Find_Ngay_Den( struct Node *Head, int Ngay_Den)// in ra khach hang co cung ngay den
{

	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
		if(Head == NULL)
		{
		printf("danh sach rong.\n");
		return;
		}
	struct Node *Temp=Head;
	int d=0;
	do
	{	
	if(Temp->Data.Ngay_Den==Ngay_Den)
	{
		d=1;
	if(Temp->Data.Ngay_Di<Temp->Data.Ngay_Den||Temp->Data.Ngay_Di>30||Temp->Data.Ngay_Den>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
		
	}
	// in ra thong tin khach hang
	
	if(Temp->Data.Ngay_Di>Temp->Data.Ngay_Den&&Temp->Data.Ngay_Di<=30&&Temp->Data.Ngay_Den<=30)
	{
		int s=0;
		Temp->Data.Loai_Phong[0]=Temp->Data.So_Phong[0];
			if(Temp->Data.Loai_Phong[0]=='A')
				{
					s=400;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}else if(Temp->Data.Loai_Phong[0]=='B')
					{
					s=300;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
					} else
					{
					s=200;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",Temp->Data.MHD,Temp->Data.Name,Temp->Data.Gioi_Tinh,Temp->Data.SCM,Temp->Data.So_Phong,Temp->Data.Loai_Phong,Temp->Data.Ngay_Den,Temp->Data.Ngay_Di,Temp->Data.Tien_Phong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	
	}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}

void Find_Ngay_Di(struct Node *Head, int ten)// in ra khach hang co cung ngay di
{

	printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
		if(Head == NULL)
		{
		printf("danh sach rong.\n");
		return;
		}
	struct Node *Temp=Head;
	int d=0;
	do
	{	
	if(Temp->Data.Ngay_Di==ten)
	{
		d=1;
	if(Temp->Data.Ngay_Di<Temp->Data.Ngay_Den||Temp->Data.Ngay_Di>30||Temp->Data.Ngay_Den>30)
	{
		
		printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
		
	}
	// in ra thong tin khach hang
	
	if(Temp->Data.Ngay_Di>Temp->Data.Ngay_Den&&Temp->Data.Ngay_Di<=30&&Temp->Data.Ngay_Den<=30)
	{
		int s=0;
		Temp->Data.Loai_Phong[0]=Temp->Data.So_Phong[0];
			if(Temp->Data.Loai_Phong[0]=='A')
				{
					s=400;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}else if(Temp->Data.Loai_Phong[0]=='B')
					{
					s=300;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
					} else
					{
					s=200;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",Temp->Data.MHD,Temp->Data.Name,Temp->Data.Gioi_Tinh,Temp->Data.SCM,Temp->Data.So_Phong,Temp->Data.Loai_Phong,Temp->Data.Ngay_Den,Temp->Data.Ngay_Di,Temp->Data.Tien_Phong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	
	}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
}

void Find_MHD(struct Node *Head,char *MHD)// sua thong tin khach hang dua tren ma hoa don 
{
	if(Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=Head;
	int d=0;
	do
	{
		if(strcmp(Temp->Data.MHD,MHD)==0)
			{
			d=1;
			if(Temp->Data.Ngay_Di<Temp->Data.Ngay_Den||Temp->Data.Ngay_Di>30||Temp->Data.Ngay_Den>30)
				{
				printf("khach hang ma hoa don la %-3s bi loi thong tin\n",Temp->Data.MHD);
				}
				if(Temp->Data.Ngay_Di>Temp->Data.Ngay_Den&&Temp->Data.Ngay_Di<=30&&Temp->Data.Ngay_Den<=30)
				 	{
					int s=0;
					Temp->Data.Loai_Phong[0]=Temp->Data.So_Phong[0];
					if(Temp->Data.Loai_Phong[0]=='A')
					{
						s=400;
						Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
					}else if(Temp->Data.Loai_Phong[0]=='B')
					{
						s=300;
						Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
					} else
					{
						s=200;
						Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
					}
					printf("\033[0;33m------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
				    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
					printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",Temp->Data.MHD,Temp->Data.Name,Temp->Data.Gioi_Tinh,Temp->Data.SCM,Temp->Data.So_Phong,Temp->Data.Loai_Phong,Temp->Data.Ngay_Den,Temp->Data.Ngay_Di,Temp->Data.Tien_Phong);
					printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
					printf("%132s\033[1A","                                                             ");
				    printf("\033[1A");
					Enter();
					break;	
						}
			}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
void Ktrieng(struct Node *Head,char *Name)
{
	struct Node *Temp=Head;
	int d=0;
	printf("\nkhach hang ma hoa don la %-3s bi loi thong tin gom:\n",Name);
	do 
	{	
		if(strcmp(Temp->Data.MHD,Name)==0)
		{
	if(!Xac_Minh_Hop_Le_MHD(Temp->Data.MHD)||!(KtSCM(Temp->Data.MHD)))
	{
		printf("ma hoa don: %s\n",Temp->Data.MHD);	
	}
	if(Ktten(Temp->Data.Name)==0)
	{
		printf("ten khach hang: %s\n",Temp->Data.Name);
		d=1;
	}
	if(KtSo_Phong(Temp->Data.So_Phong)==0)
	{
		printf("so phong:%s\n",Temp->Data.So_Phong);
		d=1;
	}
	if(KtSCM(Temp->Data.SCM)==0||!KtlengthSCM(Temp->Data.SCM))
	{
		printf("so chung minh:%s\n",Temp->Data.SCM);
		d=1;
	}
	if(Ktten(Temp->Data.Gioi_Tinh)==0||!KtlengthGioi_Tinh(Temp->Data.Gioi_Tinh))
	{
		d=1;
		printf("gioi tinh:%s\n",Temp->Data.Gioi_Tinh);
	}
	}
		Temp=Temp->next;
	}while(Temp!=Head);
	if(d==0)
	{
	system("cls"); 
	Find_MHD(Temp,Name);
	printf("\nthong tin khach hang hop le!!");
	}
	Find_MHD(Temp,Name);
}
// cac ham sua thong tin khach hang
void Sua_AI(struct Node *Head, char *AI)// sua thong khach hang bang al
{
		if(Head==NULL)
		{
			printf("danh sach rong.\n");
			return;
		}	
	struct Node *Temp=Head;
	int d=0;
	do
	{
		if(strcmp(Temp->Data.MHD,AI)==0)
		{
			d=1;
			struct Khach_Hang newkh;
		if(!Xac_Minh_Hop_Le_MHD(Temp->Data.MHD)||!(KtSCM(Temp->Data.MHD)))
			{
				newkh=Nhap_Moi_MHD();
				strcpy(Temp->Data.MHD,newkh.MHD);
				d=1;
			}
		if(Ktten(Temp->Data.Name)==0) // sua ten
			{
				newkh=Nhap_Moi_Name();
				strcpy(Temp->Data.Name,newkh.Name);
				d=1;
			}
		if(Ktten(Temp->Data.Gioi_Tinh)==0||!KtlengthGioi_Tinh(Temp->Data.Gioi_Tinh)) // sua gioi tinh
			{
				d=1;
				newkh=Nhap_Moi_Gioi_Tinh();
				strcpy(Temp->Data.Gioi_Tinh,newkh.Gioi_Tinh);
			}
		if(KtSCM(Temp->Data.SCM)==0||!KtlengthSCM(Temp->Data.SCM)) // sua SCM
			{
				newkh=Nhap_Moi_SCM();
				strcpy(Temp->Data.SCM,newkh.SCM);
				d=1;
			}
		if(KtSo_Phong(Temp->Data.So_Phong)==0) // sua so phong
			{
				newkh=Nhap5();
				strcpy(Temp->Data.So_Phong,newkh.So_Phong);
				d=1;
			}
		if(Temp->Data.Ngay_Di<Temp->Data.Ngay_Den||Temp->Data.Ngay_Di>30||Temp->Data.Ngay_Den>30) // sua ngay den va ngay di
			{	
				d=1;
				newkh=Nhap_Moi_Ngay_Den_Va_Ngay_Di();
				Temp->Data.Ngay_Den=newkh.Ngay_Den;
				Temp->Data.Ngay_Di=newkh.Ngay_Di;
			}
		break;	
		}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
			{
		 		system("cls");
				printf("khong tim thay khach hang!!!");
			}
}
void Sua_Ngay_Den_Va_Ngay_Di(struct Node *Head, char *MHD)
{
		if(Head==NULL)
			{
				printf("danh sach rong.\n");
				return;
			}
	struct Node *Temp=Head;
	int d=0;
	do
	{
		if(strcmp(Temp->Data.MHD,MHD)==0)
		{
			d=1;
			struct Khach_Hang newkh;
			newkh=Nhap_Moi_Ngay_Den_Va_Ngay_Di();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
			Temp->Data.Ngay_Den=newkh.Ngay_Den;
			Temp->Data.Ngay_Di=newkh.Ngay_Di;
		break;	
		}
	Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
			{
				system("cls");
				printf("khong tim thay khach hang!!!");
			}
	
}

void Sua_MHD(struct Node *Head,char *MHD)// sua ten khach hang bi loi
{
	if(Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=Head;
	int d=0;
	do
	{
		if(strcmp(Temp->Data.MHD,MHD)==0)
		{
			d=1;
	struct Khach_Hang newkh;
	newkh=Nhap_Moi_MHD();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
	strcpy(Temp->Data.MHD,newkh.MHD);
	break;	
		}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
void suaten(struct Node *Head,char *MHD)// sua ten khach hang bi loi
{
	if(Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=Head;
	int d=0;
	do
	{
		if(strcmp(Temp->Data.MHD,MHD)==0)
		{
		d=1;
	struct Khach_Hang newkh;
	newkh=Nhap_Moi_Name();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
	strcpy(Temp->Data.Name,newkh.Name);
	break;	
		}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
		{
	    system("cls");
		printf("khong tim thay khach hang!!!");
	    }
	
}
void suaSCM(struct Node *Head,char *MHD)// sua so chung minh cua khach hang bi loi
{
	if(Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=Head;
	int d=0;
	do
	{
		if(strcmp(Temp->Data.MHD,MHD)==0)
		{
			d=1;
	struct Khach_Hang newkh;
	newkh=Nhap_Moi_SCM();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
	strcpy(Temp->Data.SCM,newkh.SCM);
	break;	
		}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
void suaGioi_Tinh(struct Node *Head,char *MHD)// sua gioi tinh cua khach hang bi loi
{
	if(Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=Head;
	int d=0;
	do
	{
		if(strcmp(Temp->Data.MHD,MHD)==0)
		{
			d=1;
	struct Khach_Hang newkh;
	newkh=Nhap_Moi_Gioi_Tinh();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
	strcpy(Temp->Data.Gioi_Tinh,newkh.Gioi_Tinh);
	break;	
		}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
void suaSo_Phong(struct Node *Head,char *MHD)// sua so phong cua khach hang bi loi
{
	if(Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=Head;
	int d=0;
	do
	{
		if(strcmp(Temp->Data.MHD,MHD)==0)
		{
			d=1;
	struct Khach_Hang newkh;
	newkh=Nhap5();
	// sua truc tiep vao vi tri khong lam thay doi vi tri trong danh sach
	strcpy(Temp->Data.So_Phong,newkh.So_Phong);
	break;	
		}
		Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
	{
		 system("cls");
		printf("khong tim thay khach hang!!!");
	}
	
}
// khôi phuc thong tin khach hang
struct Node *Khoi_Phuc = NULL;
// cac ham xoa khach hang 
void xoaMHD(struct Node **Head, char *MHD)// xoa khach hang theo MHD
{
	if(*Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=*Head;
	struct Node *prev=NULL;
	struct Node *t=*Head;

	// tim Head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *Head);
    
     if (strcmp(Temp->Data.MHD,MHD) == 0) 
	 	{	
        if (Temp->next == *Head)
		 {

            free(Temp);
            *Head = NULL;
            return;
        }
        t->next = Temp->next;
        *Head = Temp->next;
  
        free(Temp);
        return;
    	}
	do 
	{
        prev =Temp;
        Temp = Temp->next;
        if (strcmp(Temp->Data.MHD, MHD) == 0) 
		{
            prev->next = Temp->next;
            free(Temp);
            return;
        }
    } while (Temp != *Head);


		 system("cls");
		printf("khong tim thay khach hang!!!");
}
void xoahvt(struct Node **Head, char *Name)// xoa khach hang theo ho va ten
{
	if(*Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=*Head;
	struct Node *prev=NULL;
	struct Node *t=*Head;

	// tim Head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *Head);
     if (strcmp(Temp->Data.Name,Name) == 0) 
	 {
        if (Temp->next == *Head)
		 {

            free(Temp);
            *Head = NULL;
            return;
        }
        t->next = Temp->next;
        *Head = Temp->next;
  
        free(Temp);
        return;
    	}
		 do {
        prev =Temp;
        Temp = Temp->next;
        if (strcmp(Temp->Data.Name, Name) == 0) {
        
            prev->next = Temp->next;
            free(Temp);
            return;
        }
    } while (Temp != *Head);


		 system("cls");
		printf("khong tim thay khach hang!!!");
}
void xoaten(struct Node **Head, char *ten)// xoa nhung khach hang co cung ho
{
	char Name[50];
	if(*Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=*Head;
	struct Node *prev=NULL;
	struct Node *t=*Head;
	int d=0;
	// tim Head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *Head); 
    		
    // xoa nhung phan tu o dau danh sach neu cung ho
    Lay_Ten(Temp->Data.Name,Name);
     while(Temp!=t&&strcmp(Name,ten) == 0) 
	 {
      struct Node *v =Temp;
    	t->next=Temp->next;
    	Temp=Temp->next;
    	*Head=Temp;
    	free(Temp);
    	d++;
    	Lay_Ten(Temp->Data.Name,Name);
  	}
  	// xoa o giua danh sach
		while(Temp!=t)
		{
			Lay_Ten(Temp->Data.Name,Name);
			if(strcmp(Name,ten) == 0)
			{
				struct Node *v =Temp;
    			prev->next=Temp->next;
    			Temp=Temp->next;
    			free(Temp);
    			d++;
			}else
			{
				prev=Temp;
				Temp=Temp->next;
			}
		}
		// xoa o cuoi danh sach neu co
	Lay_Ten(Temp->Data.Name,Name);
	if(strcmp(Name,ten) == 0)
	{
		if(t==*Head)
		{
			*Head=NULL;
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
void xoaho(struct Node **Head, char *ten)// xoa nhung khach hang co cung ho
{
	char Name[50];
	if(*Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=*Head;
	struct Node *prev=NULL;
	struct Node *t=*Head;
	int d=0;
	// tim Head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *Head); 
    		
    // xoa nhung phan tu o dau danh sach neu cung ho
    Lay_Ho(Temp->Data.Name,Name);
     while(Temp!=t&&strcmp(Name,ten) == 0) 
	 {
      struct Node *v =Temp;
    	t->next=Temp->next;
    	Temp=Temp->next;
    	*Head=Temp;
    	free(Temp);
    	d++;
    	Lay_Ho(Temp->Data.Name,Name);
  	}
  	// xoa o giua danh sach
		while(Temp!=t)
		{
			Lay_Ho(Temp->Data.Name,Name);
			if(strcmp(Name,ten) == 0)
			{
				struct Node *v =Temp;
    			prev->next=Temp->next;
    			Temp=Temp->next;
    			free(Temp);
    			d++;
			}else
			{
				prev=Temp;
				Temp=Temp->next;
			}
		}
	Lay_Ho(Temp->Data.Name,Name);
	if(strcmp(Name,ten) == 0)
	{
		if(t==*Head)
		{
			*Head=NULL;
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

void xoaGioi_Tinh(struct Node **Head, char *ten)// xoa nhung khach hang co cung Gioi_Tinh
{
	if(*Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=*Head;
	struct Node *prev=NULL;
	struct Node *t=*Head;
	
	// tim Head cuoi cung
	while(t->next!=*Head)
	{
		t=t->next;
	}
    // xoa nhung phan tu o dau danh sach neu cung ho
   int d=0;
     while(Temp!=t&&strcmp(Temp->Data.Gioi_Tinh,ten) == 0) 
	 {
      	struct Node *v =Temp;
    	t->next=Temp->next;
    	Temp=Temp->next;
    	free(Temp);
    	d=1;
    	*Head=Temp;
  	}	
		prev = Temp;
    	Temp = Temp->next;
  	// xoa o giua danh sach
		while(Temp!=t)
		{
			if(strcmp(Temp->Data.Gioi_Tinh,ten) == 0)
			{
				struct Node *v =Temp;
    			prev->next=Temp->next;
    			Temp=Temp->next;
    			free(v);
    			d=1;
			}else
			{
				prev=Temp;
				Temp=Temp->next;
			}
		}
			
	if(strcmp(t->Data.Gioi_Tinh,ten) == 0)
		{
		if(t==*Head)
			{
		//	free(t);
			*Head=NULL;
			}else
				{
				prev->next=t->next;
				}
			//	free(t);
		d=1;
		}		
	if (*Head == NULL)
	 {
    printf("Danh sach rong.\n");
	} else 
		{		
   		 if (d == 0) 
			{	
        	system("cls");
        	printf("Khong tim thay khach hang!!!\n");
    		}
		}
}

void xoaNgay_Den(struct Node **Head, int ten)// xoa nhung khach hang co cung Ngay_Den
{
	char Name[50];
	if(*Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=*Head;
	struct Node *prev=NULL;
	struct Node *t=*Head;
	int d=0;
	// tim Head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *Head); 
    		
    // xoa nhung phan tu o dau danh sach neu cung ho
     while(Temp!=t&&(Temp->Data.Ngay_Den==ten)) 
	 {
      struct Node *v =Temp;
    	t->next=Temp->next;
    	Temp=Temp->next;
    	*Head=Temp;
    	free(Temp);
    	d++;
  	}
  	// xoa o giua danh sach
		while(Temp!=t)
		{
			if((Temp->Data.Ngay_Den==ten))
			{
				struct Node *v =Temp;
    			prev->next=Temp->next;
    			Temp=Temp->next;
    			free(Temp);
    			d++;
			}else
			{
				prev=Temp;
				Temp=Temp->next;
			}
		}
	if((Temp->Data.Ngay_Den==ten))
	{
		if(t==*Head)
		{
			*Head=NULL;
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

void xoaNgay_Di(struct Node **Head, int ten)// xoa nhung khach hang co cung Ngay_Di
{
	char Name[50];
	if(*Head==NULL)
	{
		printf("danh sach rong.\n");
		return;
	}
	struct Node *Temp=*Head;
	struct Node *prev=NULL;
	struct Node *t=*Head;
	int d=0;
	// tim Head cuoi cung
	do 
	{
        t = t->next;
    } while (t->next != *Head); 
    		
    // xoa nhung phan tu o dau danh sach neu cung ho
     while(Temp!=t&&(Temp->Data.Ngay_Di==ten)) 
	 {
      struct Node *v =Temp;
    	t->next=Temp->next;
    	Temp=Temp->next;
    	*Head=Temp;
    	free(Temp);
    	d++;
  	}
  	// xoa o giua danh sach
		while(Temp!=t)
		{
			if((Temp->Data.Ngay_Di==ten))
			{
				struct Node *v =Temp;
    			prev->next=Temp->next;
    			Temp=Temp->next;
    			free(Temp);
    			d++;
			}else
			{
				prev=Temp;
				Temp=Temp->next;
			}
		}
	if((Temp->Data.Ngay_Di==ten))
	{
		if(t==*Head)
		{
			*Head=NULL;
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
// cac ham kiem tra khi lua chon Menu
void Xac_Minh_Hop_Le_Nhap_Menu(int sl,char *Temp)
{
	int a=0,x;
	char b[50];
	int num=0;
	Menu();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 10) 
			{
            	
                printf("\n");
                break;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}

void Xac_Minh_Hop_Le_Nhap_File_Bat_ki(int sl,char *Temp)
{
	int a=0,x;
	char b[50];
	int num=0;
	Menu_File_Bat_Ki();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 9) 
			{
                printf("\n");
                break;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }
    Temp[a] = '\0'; 
}

void Xac_Minh_Hop_Le_Nhap_Menu1(int sl,char *Temp)
{
	int a=0,x;
	char b[50];
	int num=0;
	Menu_Tim_Kiem();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 5)
			{
            	
                printf("\n");
                break;
            } 
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}

void Xac_Minh_Hop_Le_Nhap_Menu2(int sl,char *Temp) // Nhap theo gioi tinh
{
	int a=0,x;
	char b[50];
	int num=0;
	Menu_Gioi_Tinh();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } 
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}

void Xac_Minh_Hop_Le_Nhap_Menu3(int sl,char *Temp) // Nhap theo ho va ten
{
	int a=0,x;
	char b[50];
	int num=0;
	Menu_Tim_Kiem_Ho_Va_Ten();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 4) {
            	
                printf("\n");
                break;
            } 
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}
void Xac_Minh_Hop_Le_Nhap_Menu4(int sl,char *Temp) // Nhap theo ho va ten
{
	int a=0,x;
	char b[50];
	int num=0;
	Menu_Sua_Thong_Tin();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 6) {
            	
                printf("\n");
                break;
            }
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}
void Xac_Minh_Hop_Le_Nhap_Menu5(int sl,char *Temp) // Nhap  Menu sap xep theo hoa va ten
{
	int a=0,x;
	char b[50];
	int num=0;
	 Menu5();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } 
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}

void Xac_Minh_Hop_Le_Nhap_Menu6(int sl,char *Temp) // Nhap  Menu sap xep theo hoa va ten tang dan hoac giam dan
{
	int a=0,x;
	char b[50];
	int num=0;
	 Menu6();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } 
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}

void Xac_Minh_Hop_Le_Nhap_Menu7(int sl,char *Temp) // Nhap  Menu sap xep theo ma hoa don tang dan hoac giam dan
{
	int a=0,x;
	char b[50];
	int num=0;
	 Menu7();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } 
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}
void Xac_Minh_Hop_Le_Nhap_Menu8(int sl,char *Temp) // Nhap  Menu sap xep theo ma hoa don tang dan hoac giam dan
{
	int a=0,x;
	char b[50];
	int num=0;
	 Menu8();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } 
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}
void Xac_Minh_Hop_Le_Nhap_Menu9(int sl,char *Temp) // Nhap  Menu sap xep theo ma hoa don tang dan hoac giam dan
{
	int a=0,x;
	char b[50];
	int num=0;
	 Menu9();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 3) {
            	
                printf("\n");
                break;
            } 
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}
void Xac_Minh_Hop_Le_Nhap_Menux(int sl,char *Temp) // Nhap  Menu xoa khach hang
{
	int a=0,x;
	char b[50];
	int num=0;
	 Menux();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 7) {
            	
                printf("\n");
                break;
            } 
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}
void Xac_Minh_Hop_Le_Nhap_Menu10(int sl,char *Temp) // Nhap  Menu sap xep theo ma hoa don tang dan hoac giam dan
{
	int a=0,x;
	char b[50];
	int num=0;
	 Menu10();
	printf("\033[0mNhap lua chon: "); 
	 while (1) {
	 
        Temp[a] = getch();
	
        if (Temp[a] == '\r' || Temp[a] == '\n') {
            
            Temp[a] = '\0'; 
            num = atoi(Temp);
            if (num >= 1 && num <= 2) {
            	
                printf("\n");
                break;
            } 
        }
		// Kiem tra ky tu co phai la chu so tu 0-9 không
        if (isdigit(Temp[a]) && a < sl - 1) {
            putchar(Temp[a]);
            a++;
        } else if (Temp[a] == '\b' && a > 0) {
            printf("\b \b");
            a--;
        }
    }

    Temp[a] = '\0'; 
}
void Hien_Thi_Danh_Sach_Truoc_Khi_Xoa()
{
	struct Node *List = NULL;
	read("quanlikhachsan2.txt",&List);
	char v[2];
	int x10;
	printf("ban co muon hien thi danh sach khach hang khong?");
	   	Xac_Minh_Hop_Le_Nhap_Menu10(2,v);
		x10=atoi(v);
	    system("cls");
	    if(x10==1) 
	    {
		system("cls");
		Output(List);
	printf("%132s\033[1A","                                                     ");
		printf("\033[1A");
		Enter();	
		}
}
void Hien_Thi_Danh_Sach_Sau_Khi_Xoa()
{
	struct Node *List = NULL;
	read("quanlikhachsan2.txt",&List);
	char v[2];
	int x10;
	printf("ban co muon hien thi danh sach sau khi xoa khong?");
	   	Xac_Minh_Hop_Le_Nhap_Menu10(2,v);
		x10=atoi(v);
	    system("cls");
	    if(x10==1) 
	    {
		system("cls");
		Output(List);
	printf("%132s\033[1A","                                                     ");
		printf("\033[1A");
		Enter();	
		}	
}
void Hien_Thi_Khach_Hang_Khong_Hop_le(struct Node *Head)
{
	if(Head == NULL || Head->next==NULL)

	{
		printf("rong.\n");
		return;
	}
	struct Node *Temp=Head;
	struct Node *List = NULL;
	read("quanlikhachsan2.txt",&List);
	char v[2];
	int x10,d=0;
	printf("ban co muon hien thi danh sach khach hang khong hop le de chinh sua thong tin de dang hon khong?");
	Xac_Minh_Hop_Le_Nhap_Menu10(2,v);
	x10=atoi(v);
	system("cls");
	if(x10==1) 
	{
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%-14s%-25s%-12s%-17s%-12s%-12s%-1s%-12s%-12s%-12s%-1s\n", "| ma hoa don |","    ten khach hang     ","| gioi tinh |"," so chung minh ","| so phong |"," loai phong ","|","  ngay den  ","|  ngay di  |"," tien phong ","|");
    printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	do 
	{	
		if(!(Temp->Data.Ngay_Di>=Temp->Data.Ngay_Den&&Temp->Data.Ngay_Di<=30&&Temp->Data.Ngay_Den<=30&&Ktten(Temp->Data.Name)==1&&KtSo_Phong(Temp->Data.So_Phong)==1&&KtSCM(Temp->Data.SCM)==1&&KtlengthSCM(Temp->Data.SCM)&&Ktten(Temp->Data.Gioi_Tinh)==1&&KtlengthGioi_Tinh(Temp->Data.Gioi_Tinh)&&Xac_Minh_Hop_Le_MHD(Temp->Data.MHD)&&KtSCM(Temp->Data.MHD)))
			{
			d=1;
			int s=0;
			Temp->Data.Loai_Phong[0]=Temp->Data.So_Phong[0];
			if(Temp->Data.Loai_Phong[0]=='A')
				{
				s=400;
				Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
				}else 
				if(Temp->Data.Loai_Phong[0]=='B')
					{
					s=300;
					Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
					} else
						{
						s=200;
						Temp->Data.Tien_Phong=s*(Temp->Data.Ngay_Di - Temp->Data.Ngay_Den+1);
						}
	printf("\033[0;33m|    %-3s     |  %-21s  |    %-3s    |  %-12s   |   %-4s   |     %-2s     |     %-2d     |    %-2d     |   %-5d    |\n",Temp->Data.MHD,Temp->Data.Name,Temp->Data.Gioi_Tinh,Temp->Data.SCM,Temp->Data.So_Phong,Temp->Data.Loai_Phong,Temp->Data.Ngay_Den,Temp->Data.Ngay_Di,Temp->Data.Tien_Phong);
	printf("------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
	}
	Temp=Temp->next;
	}while(Temp!=Head);
		if(d==0)
		{
		system("cls");
		printf("thong tin khach hang tren dach sach hop le\n");
		}else
		{
			printf("%132s\033[1A","                                                     ");
	printf("\033[1A");
	Enter();
			}	
	}

}
void Thao_Tac_Tren_File_Bat_Ki(char *name)
{
	struct Node *List = NULL;
    char x[2],y[2],z[2],t[3],h[2],a[2],b[2],c1[2],b1[2],v[2];
    int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
    int p;
    int Ngay_Den,Ngay_Di;
    system("cls");
    read(name,&List);
    Output(List);
    printf("  %6s\033[1A","          ");
    Enter();
    struct Khach_Hang k1;	

    int c,c2,c3,c4,c5,c6,c7,c8,c9,c10;
	char Name[50];
	do
	{
     	Xac_Minh_Hop_Le_Nhap_File_Bat_ki(2,x);
		x1=atoi(x);
        struct Node *List = NULL;
		read(name,&List);
        system("cls");
		c=x1;
        switch(x1) // switch chinh
			{
        	 	case 1: // in ra thong tin khach hang
                  	Output(List);
                    printf("%132s\033[1A","                                                     ");
                    Enter();
               		break;
         	    case 2: // chen khach hang vao dau danh sach
         	    	Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
         	    	printf("\n");
                	k1=Input();
                	Chen_Cuoi(&List, k1);
              		write("quanlikhachsan2.txt",List);   
                	printf("\033[1A");
                	Enter();
               		break;
            	case 3:// chen khach hang vao cuoi danh sach
            		Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
            		printf("\n");
                	k1=Input();
                	Chen_Dau(&List, k1);
                	printf("\033[1A");
                	Enter();
                	break;
                case 4:
                	Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
         	    	printf("\n");
         	    	printf("vi tri can chen: ");
					scanf("%d",&p);
					getchar();
                	k1=Input();
                	Chen_Bat_Ki(&List, k1,p);
              		write("quanlikhachsan2.txt",List);   
                	printf("\033[1A");
                	Enter();
               		break;
           		case 5: // tim kiem va hien thi thong tin khach hang
            		do
            		{
            		printf("\ntim kiem theo : \n");
            		Xac_Minh_Hop_Le_Nhap_Menu1(2,y);
					x2=atoi(y);
					system("cls");
					c2=x2; 
            			switch(x2) // tim kiem va hien thi thong tin khach hang theo cac tieu chi khach nhau
            				{
            				case 1:
            					do
            					{
            						Xac_Minh_Hop_Le_Nhap_Menu3(2,t);
									x4=atoi(t);
									system("cls");
									c4=x4; 
									switch(x4) // tim kiem theo ho va ten
										{
										case 1:
												printf("ho khach hang :");
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									Find_Ho(List,Name);  
       			printf("%132s\033[1A","                                                        ");
       											printf("\033[1A");
       											Enter();					
       											break;
										case 2:
												printf("ten khach hang :");
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									Find_Ten(List,Name);  
       		printf("%132s\033[1A","                                                        ");
       											printf("\033[1A");
       											Enter();					
       											break;
										case 3:	
           										printf("ho va ten khach hang :");
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									Find_Name(List,Name);  
       		printf("%132s\033[1A","                                                        ");
       		       								printf("\033[1A");
												Enter();
												break;		
										default:	
												printf("");	
										}
								}while((0<c4)&&(c4<4));
								break;
							case 2:
							 	do
								{
							 	Xac_Minh_Hop_Le_Nhap_Menu2(2,z);
								x3=atoi(z);
								system("cls");
								c3=x3; 
									switch(x3)
									{
										case 1:
										Find_Gioi_Tinh(List,"Nam");
				printf("%132s\033[1A","                                                                       ");
				       					printf("\033[1A");
										Enter();
										break;	
										case 2:
										Find_Gioi_Tinh(List,"Nu");
				printf("%132s\033[1A","                                                                      ");
		       							printf("\033[1A");
										Enter();
										break;	
										default: 
										printf("");
									}
							 	}while((0<c3)&&(c3<3));
							 	break;
						    case 3:
								printf("ngay den: ");
								scanf("%d",&Ngay_Den);
								getchar();
								Find_Ngay_Den(List,Ngay_Den);
			printf("%132s\033[1A","                                                              ");
		       					printf("\033[1A");
								Enter();
								break;	
							case 4:
								 printf("ngay di: ");
								 scanf("%d",&Ngay_Di);
								 getchar();
								 Find_Ngay_Di(List,Ngay_Di);
			printf("%132s\033[1A","                                                             ");
		       					 printf("\033[1A");
								 Enter();
								 break;
							default:
							printf("");
							}
        			}while((0<c2)&&(c2<5));
        			break;
				case 6: // kiem tra va sua thong tin khach hang
					do
					{	
					Kt(List);
					Hien_Thi_Khach_Hang_Khong_Hop_le(List);
					printf("\nma hoa don : ");
					fgets(Name,sizeof(Name),stdin);
       				Name[strcspn(Name, "\n")] = '\0';
       				Xoa_ki_Tu(Name);
       				Find_MHD(List,Name);
       				Ktrieng(List,Name);
       				Xac_Minh_Hop_Le_Nhap_Menu9(2,b1);
					x9=atoi(b1);
					system("cls");
					c9=x9;
					switch(x9)
							{
       						case 1:
       							do
       							{
       							Xac_Minh_Hop_Le_Nhap_Menu4(2,c1);
								x8=atoi(c1);
								system("cls");
								c8=x8;
								switch(x8) // ten , SCM, Gioi_Tinh,so phong,ngay den va ngay di
										{
										case 1:// ten
											Ktrieng(List,Name);
	       									suaten(List,Name);
											write("quanlikhachsan2.txt",List);  
	       									printf("\033[1A");
											Enter();
											do
											{
											Xac_Minh_Hop_Le_Nhap_Menu9(2,b1);
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
										case 2:// SCM
											Ktrieng(List,Name);
											suaSCM(List,Name);
											write("quanlikhachsan2.txt",List);  
							       			printf("\033[1A");
											Enter();
											do
											{
											Xac_Minh_Hop_Le_Nhap_Menu8(2,b1);
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
											Ktrieng(List,Name);
											suaGioi_Tinh(List,Name);
											write("quanlikhachsan2.txt",List);  
							       			printf("\033[1A");
											Enter();
											do
											{
											Xac_Minh_Hop_Le_Nhap_Menu8(2,b1);
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
											Ktrieng(List,Name);
											suaSo_Phong(List,Name);
											write("quanlikhachsan2.txt",List);  
							       			printf("\033[1A");
											Enter();
											do
											{
											Xac_Minh_Hop_Le_Nhap_Menu8(2,b1);
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
										Ktrieng(List,Name);
										Sua_Ngay_Den_Va_Ngay_Di(List,Name);
										write("quanlikhachsan2.txt",List);  
						       			printf("\033[1A");
										Enter();
										do
										{
										Xac_Minh_Hop_Le_Nhap_Menu8(2,b1);
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
							Ktrieng(List,Name);
							Sua_AI(List,Name);
							write("quanlikhachsan2.txt",List);  
				       		printf("\033[1A");
							Enter();
							do
							{
							Xac_Minh_Hop_Le_Nhap_Menu8(2,b1);
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
				case 7: // sao xep khach hang theo cac tieu chi khach nhau...
					do
					{
					printf("sap xep theo :\n");
	            	Xac_Minh_Hop_Le_Nhap_Menu5(2,h);
					x5=atoi(h);
					system("cls");
					c5=x5; 
					switch(x5)
							{
							case 1:	
								do
								{
								Xac_Minh_Hop_Le_Nhap_Menu6(2,a);
								x6=atoi(a);
								system("cls");
								c6=x6; 
								switch(x6)
										{
										case 1:
											sapxeptheoten(List);
											write("quanlikhachsan2.txt",List);   
											Output(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											Enter();
											break;
										case 2:
											sapxeptheoten1(List);
											write("quanlikhachsan2.txt",List);   
											Output(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											Enter();
											break;
										default:
											printf("");
										}
								}while((0<c6)&&(c6<3));
							break;
							case 2:
								do
								{
								Xac_Minh_Hop_Le_Nhap_Menu7(2,b);
								x7=atoi(b);
								system("cls");
								c7=x7; 
								switch(x7)
										{
										case 1:
											sapxeptheoMHD(List);
											write("quanlikhachsan2.txt",List);   
											Output(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											Enter();
											break;
										case 2:
											sapxeptheoMHD1(List);
											write("quanlikhachsan2.txt",List);   
											Output(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											Enter();
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
				case 8: // chuc nang xoa khach hang theo cac tieu chi khach nhau.......
					do
            		{
            		Xac_Minh_Hop_Le_Nhap_Menux(2,v);
					x10=atoi(v);
					system("cls");
					c10=x10; 
            			switch(x10) 
            				{
            			 	case 1:// xoa theo ma hoa don
	                			Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
	            			 	printf("\nma hoa don : ");
								fgets(Name,sizeof(Name),stdin);
	       						Name[strcspn(Name, "\n")] = '\0';	
								Xoa_ki_Tu(Name);	
	       						xoaMHD(&List,Name);
	       						write("quanlikhachsan2.txt",List);   
								Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
	       						break;
            				case 2:// xoa theo ho va ten chua xoa tren file luc gan nop roi go vao sau
            					do
            					{
            						Xac_Minh_Hop_Le_Nhap_Menu3(2,t);
									x4=atoi(t);
									system("cls");
									c4=x4; 
									switch(x4) 
											{
											case 1:
												Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
												printf("ho khach hang can xoa:");
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									xoaho(&List,Name);
		       									write("quanlikhachsan2.txt",List); 
		       									Hien_Thi_Danh_Sach_Sau_Khi_Xoa();			
       											break;
											case 2:
												Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
												printf("ten khach hang can xoa:");
												
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									xoaten(&List,Name);
		       									write("quanlikhachsan2.txt",List); 
		       									
		       									Hien_Thi_Danh_Sach_Sau_Khi_Xoa();		
       											break;
											case 3:	
												Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
												
           										printf("ho va ten khach hang can xoa:");
           										
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									xoahvt(&List,Name);  
		       									write("quanlikhachsan2.txt",List); 
		       									Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
												break;		
											default:	
												printf("");	
											}
								}while((0<c4)&&(c4<4));
								break;
							case 3:
							 	do
								{
								Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
							 	Xac_Minh_Hop_Le_Nhap_Menu2(2,z);
								x3=atoi(z);
								system("cls");
								c3=x3; 
									switch(x3)
									{
										case 1:// xoa gioi tinh Nam	
										xoaGioi_Tinh(&List,"Nam");
										write("quanlikhachsan2.txt",List); 
										Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
										system("cls");
										break;	
										case 2:// xoa gioi tinh Nu
										xoaGioi_Tinh(&List,"Nu");
										write("quanlikhachsan2.txt",List); 
										Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
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
								Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
								printf("ngay den: ");
								scanf("%d",&Ngay_Den);
								getchar();
								xoaNgay_Den(&List,Ngay_Den);
								write("quanlikhachsan2.txt",List); 
								Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
								break;	
							case 6:
								Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
								printf("ngay di: ");
								scanf("%d",&Ngay_Di);
								getchar();
								xoaNgay_Di(&List,Ngay_Di);
								write("quanlikhachsan2.txt",List); 
								Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
								break;
							default:
							printf("");
							}
        			}while((0<c10)&&(c10<7));
        			break;
        		case 9:
        		system("cls");
        		return;
            	default:
                printf("");
        	}
    }while ((0<c)&&(c<9));
}
// chuong trinh chinh
int main()
{
	
    struct Node *List = NULL;
    char x[3],y[2],z[2],t[3],h[2],a[2],b[2],c1[2],b1[2],v[2];
    int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
    int p;
    int Ngay_Den,Ngay_Di;
     system("cls");
    read("quanlikhachsan2.txt",&List);
    Output(List);
    printf("  %6s\033[1A","          ");
    Enter();
    struct Khach_Hang k1;	

    int c,c2,c3,c4,c5,c6,c7,c8,c9,c10;
	char Name[50];
	do
	{
     //   Menu();
     	Xac_Minh_Hop_Le_Nhap_Menu(3,x);
		x1=atoi(x);
        struct Node *List = NULL;
		read("quanlikhachsan2.txt",&List);
        system("cls");
		c=x1;
        switch(x1) // switch chinh
			{
        	 	case 1: // in ra thong tin khach hang
                  	Output(List);
                    printf("%132s\033[1A","                                                     ");
                    Enter();
               		break;
         	    case 2: // chen khach hang vao dau danh sach
         	    	Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
         	    	printf("\n");
                	k1=Input();
                	Chen_Cuoi(&List, k1);
              		write("quanlikhachsan2.txt",List);   
                	printf("\033[1A");
                	Enter();
               		break;
            	case 3:// chen khach hang vao cuoi danh sach
            		Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
            		printf("\n");
                	k1=Input();
                	Chen_Dau(&List, k1);
                	printf("\033[1A");
                	Enter();
                	break;
                case 4:
                	Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
         	    	printf("\n");
         	    	printf("vi tri can chen: ");
					scanf("%d",&p);
					getchar();
                	k1=Input();
                	Chen_Bat_Ki(&List, k1,p);
              		write("quanlikhachsan2.txt",List);   
                	printf("\033[1A");
                	Enter();
               		break;
           		case 5: // tim kiem va hien thi thong tin khach hang
            		do
            		{
            		printf("\ntim kiem theo : \n");
            		Xac_Minh_Hop_Le_Nhap_Menu1(2,y);
					x2=atoi(y);
					system("cls");
					c2=x2; 
            			switch(x2) // tim kiem va hien thi thong tin khach hang theo cac tieu chi khach nhau
            				{
            				case 1:
            					do
            					{
            						Xac_Minh_Hop_Le_Nhap_Menu3(2,t);
									x4=atoi(t);
									system("cls");
									c4=x4; 
									switch(x4) // tim kiem theo ho va ten
										{
										case 1:
												printf("ho khach hang :");
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									Find_Ho(List,Name);  
       			printf("%132s\033[1A","                                                        ");
       											printf("\033[1A");
       											Enter();					
       											break;
										case 2:
												printf("ten khach hang :");
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									Find_Ten(List,Name);  
       		printf("%132s\033[1A","                                                        ");
       											printf("\033[1A");
       											Enter();					
       											break;
										case 3:	
           										printf("ho va ten khach hang :");
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									Find_Name(List,Name);  
       		printf("%132s\033[1A","                                                        ");
       		       								printf("\033[1A");
												Enter();
												break;		
										default:	
												printf("");	
										}
								}while((0<c4)&&(c4<4));
								break;
							case 2:
							 	do
								{
							 	Xac_Minh_Hop_Le_Nhap_Menu2(2,z);
								x3=atoi(z);
								system("cls");
								c3=x3; 
									switch(x3)
									{
										case 1:
										Find_Gioi_Tinh(List,"Nam");
				printf("%132s\033[1A","                                                                       ");
				       					printf("\033[1A");
										Enter();
										break;	
										case 2:
										Find_Gioi_Tinh(List,"Nu");
				printf("%132s\033[1A","                                                                      ");
		       							printf("\033[1A");
										Enter();
										break;	
										default: 
										printf("");
									}
							 	}while((0<c3)&&(c3<3));
							 	break;
						    case 3:
								printf("ngay den: ");
								scanf("%d",&Ngay_Den);
								getchar();
								Find_Ngay_Den(List,Ngay_Den);
			printf("%132s\033[1A","                                                              ");
		       					printf("\033[1A");
								Enter();
								break;	
							case 4:
								 printf("ngay di: ");
								 scanf("%d",&Ngay_Di);
								 getchar();
								 Find_Ngay_Di(List,Ngay_Di);
			printf("%132s\033[1A","                                                             ");
		       					 printf("\033[1A");
								 Enter();
								 break;
							default:
							printf("");
							}
        			}while((0<c2)&&(c2<5));
        			break;
				case 6: // kiem tra va sua thong tin khach hang
					do
					{	
					Kt(List);
					Hien_Thi_Khach_Hang_Khong_Hop_le(List);
					printf("\nma hoa don : ");
					fgets(Name,sizeof(Name),stdin);
       				Name[strcspn(Name, "\n")] = '\0';
       				Xoa_ki_Tu(Name);
       				Find_MHD(List,Name);
       				Ktrieng(List,Name);
       				Xac_Minh_Hop_Le_Nhap_Menu9(2,b1);
					x9=atoi(b1);
					system("cls");
					c9=x9;
					switch(x9)
							{
       						case 1:
       							do
       							{
       							Xac_Minh_Hop_Le_Nhap_Menu4(2,c1);
								x8=atoi(c1);
								system("cls");
								c8=x8;
								switch(x8) // ten , SCM, Gioi_Tinh,so phong,ngay den va ngay di
										{
										case 1:// ten
											Ktrieng(List,Name);
	       									suaten(List,Name);
											write("quanlikhachsan2.txt",List);  
	       									printf("\033[1A");
											Enter();
											do
											{
											Xac_Minh_Hop_Le_Nhap_Menu9(2,b1);
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
										case 2:// SCM
											Ktrieng(List,Name);
											suaSCM(List,Name);
											write("quanlikhachsan2.txt",List);  
							       			printf("\033[1A");
											Enter();
											do
											{
											Xac_Minh_Hop_Le_Nhap_Menu8(2,b1);
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
											Ktrieng(List,Name);
											suaGioi_Tinh(List,Name);
											write("quanlikhachsan2.txt",List);  
							       			printf("\033[1A");
											Enter();
											do
											{
											Xac_Minh_Hop_Le_Nhap_Menu8(2,b1);
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
											Ktrieng(List,Name);
											suaSo_Phong(List,Name);
											write("quanlikhachsan2.txt",List);  
							       			printf("\033[1A");
											Enter();
											do
											{
											Xac_Minh_Hop_Le_Nhap_Menu8(2,b1);
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
										Ktrieng(List,Name);
										Sua_Ngay_Den_Va_Ngay_Di(List,Name);
										write("quanlikhachsan2.txt",List);  
						       			printf("\033[1A");
										Enter();
										do
										{
										Xac_Minh_Hop_Le_Nhap_Menu8(2,b1);
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
							Ktrieng(List,Name);
							Sua_AI(List,Name);
							write("quanlikhachsan2.txt",List);  
				       		printf("\033[1A");
							Enter();
							do
							{
							Xac_Minh_Hop_Le_Nhap_Menu8(2,b1);
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
									case 3:
										c9=3;
										break;
									default:
										printf("");
									}
							}while(c9!=2&&c9!=3);
							break;
							default:
								printf("");
							} 
					}while((0<c9)&&(c9<3));
				break;
				case 7: // sao xep khach hang theo cac tieu chi khach nhau...
					do
					{
					printf("sap xep theo :\n");
	            	Xac_Minh_Hop_Le_Nhap_Menu5(2,h);
					x5=atoi(h);
					system("cls");
					c5=x5; 
					switch(x5)
							{
							case 1:	
								do
								{
								Xac_Minh_Hop_Le_Nhap_Menu6(2,a);
								x6=atoi(a);
								system("cls");
								c6=x6; 
								switch(x6)
										{
										case 1:
											sapxeptheoten(List);
											write("quanlikhachsan2.txt",List);   
											Output(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											Enter();
											break;
										case 2:
											sapxeptheoten1(List);
											write("quanlikhachsan2.txt",List);   
											Output(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											Enter();
											break;
										default:
											printf("");
										}
								}while((0<c6)&&(c6<3));
							break;
							case 2:
								do
								{
								Xac_Minh_Hop_Le_Nhap_Menu7(2,b);
								x7=atoi(b);
								system("cls");
								c7=x7; 
								switch(x7)
										{
										case 1:
											sapxeptheoMHD(List);
											write("quanlikhachsan2.txt",List);   
											Output(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											Enter();
											break;
										case 2:
											sapxeptheoMHD1(List);
											write("quanlikhachsan2.txt",List);   
											Output(List);
				printf("%132s\033[1A","                                                     ");
											printf("\033[1A");
											Enter();
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
				case 8: // chuc nang xoa khach hang theo cac tieu chi khach nhau.......
					do
            		{
            		Xac_Minh_Hop_Le_Nhap_Menux(2,v);
					x10=atoi(v);
					system("cls");
					c10=x10; 
            			switch(x10) 
            				{
            			 	case 1:// xoa theo ma hoa don
	                			Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
	            			 	printf("\nma hoa don : ");
								fgets(Name,sizeof(Name),stdin);
	       						Name[strcspn(Name, "\n")] = '\0';	
								Xoa_ki_Tu(Name);	
	       						xoaMHD(&List,Name);
	       						write("quanlikhachsan2.txt",List);   
								Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
	       						break;
            				case 2:// xoa theo ho va ten chua xoa tren file luc gan nop roi go vao sau
            					do
            					{
            						Xac_Minh_Hop_Le_Nhap_Menu3(2,t);
									x4=atoi(t);
									system("cls");
									c4=x4; 
									switch(x4) 
											{
											case 1:
												Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
												printf("ho khach hang can xoa:");
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									xoaho(&List,Name);
		       									write("quanlikhachsan2.txt",List); 
		       									Hien_Thi_Danh_Sach_Sau_Khi_Xoa();			
       											break;
											case 2:
												Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
												printf("ten khach hang can xoa:");
												
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									xoaten(&List,Name);
		       									write("quanlikhachsan2.txt",List); 
		       									
		       									Hien_Thi_Danh_Sach_Sau_Khi_Xoa();		
       											break;
											case 3:	
												Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
												
           										printf("ho va ten khach hang can xoa:");
           										
      											fgets(Name,sizeof(Name),stdin);
		       									Name[strcspn(Name,"\n")] ='\0';
		       									inhoa(Name);
		       									Xoa_ki_Tu(Name);
		       									xoahvt(&List,Name);  
		       									write("quanlikhachsan2.txt",List); 
		       									Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
												break;		
											default:	
												printf("");	
											}
								}while((0<c4)&&(c4<4));
								break;
							case 3:
							 	do
								{
								Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
							 	Xac_Minh_Hop_Le_Nhap_Menu2(2,z);
								x3=atoi(z);
								system("cls");
								c3=x3; 
									switch(x3)
									{
										case 1:// xoa gioi tinh Nam	
										xoaGioi_Tinh(&List,"Nam");
										write("quanlikhachsan2.txt",List); 
										Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
										system("cls");
										break;	
										case 2:// xoa gioi tinh Nu
										xoaGioi_Tinh(&List,"Nu");
										write("quanlikhachsan2.txt",List); 
										Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
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
								Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
								printf("ngay den: ");
								scanf("%d",&Ngay_Den);
								getchar();
								xoaNgay_Den(&List,Ngay_Den);
								write("quanlikhachsan2.txt",List); 
								Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
								break;	
							case 6:
								Hien_Thi_Danh_Sach_Truoc_Khi_Xoa();
								printf("ngay di: ");
								scanf("%d",&Ngay_Di);
								getchar();
								xoaNgay_Di(&List,Ngay_Di);
								write("quanlikhachsan2.txt",List); 
								Hien_Thi_Danh_Sach_Sau_Khi_Xoa();
								break;
							default:
							printf("");
							}
        			}while((0<c10)&&(c10<7));
        			break;
        		case 9:
        		printf("ten file can mo : ");
        		fgets(Name,sizeof(Name),stdin);
		       	Name[strcspn(Name,"\n")] ='\0';
		       	Thao_Tac_Tren_File_Bat_Ki(Name);
		       	break;
        		case 10:
        		system("cls");
        		return;
            	default:
                printf("");
        	}
        
    }while ((0<c)&&(c<10));
    return 0;
	}
// lam lai cai  Menu cho hoan thien hon 

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct criminal		//structure for criminal records
{
	char name[100];
	char address[100];
	char sex[100];
	int height;
	int weight;
	int age;
	char eyecolor[100];
	char haircolor[100];
	char crime[100];
	int fir_no;
	double contact;
}c;


int main()
{
	char username[50],password[50];
	int login_attemp=0;
	top: //label for wrong username and password
	printf("\n\t===========================\n");
	printf("\t\tLOGIN PANEL\n");
	printf("\t===========================\n\n");
	printf("\tUsername: ");
	scanf("%s",&username);
	printf("\tPassword: ");
	scanf("%s",&password);

	if(strcmp(username,"user")==0 && strcmp(password,"pass")==0)
	{
		printf("\n\n\tYour LogIn is successfull");
		printf("\n\n\tPress any key to continue!!");
		getch();
		system("cls");
		
		//username: user and password: pass
		//Main Menu
		menu:		
		system("cls");
		printf("\n\n\t==============================================================\n");
		printf("\t==============================================================");
		printf("\n\t\t   WELCOME TO POLICE FIR RECORD MANAGEMENT\n");
		printf("\t==============================================================\n");
		printf("\t==============================================================\n\n");
	
		printf("\n\n\n\t\t\t\tMAIN MENU:\n\n");
		printf("\t\t\tCREATE RECORDS    [ENTER 1]\n");
		printf("\t\t\tMODIFY RECORDS    [ENTER 2]\n");
		printf("\t\t\tLIST   RECORDS    [ENTER 3]\n");
		printf("\t\t\tDELETE RECORDS    [ENTER 4]\n");
		printf("\t\t\tSEARCH RECORDS    [ENTER 5]\n");
		printf("\t\t\tTEAM   MEMBERS    [ENTER 6]\n");
		printf("\t\t\tEXIT              [ENTER 7]\n");
		//for choice
		int choice;
		printf("\n\t\t\tENTER YOUR CHOICE: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:		//for create records
				{
					char yesno;
					createtop:
					system("cls");
					printf("\n\t===========================\n");
					printf("\t\tCREATE RECORDS\n");
					printf("\t===========================\n");
					
					FILE *fp;
					fp=fopen("Criminal.txt","a");
					
					fflush(stdin);
					printf("\tName: ");
					gets(c.name);
					
					fflush(stdin);
					printf("\tAddress: ");
					gets(c.address);
					
					fflush(stdin);
					printf("\tSex: ");
					gets(c.sex);
					
					printf("\tAge: ");
					scanf("%d",&c.age);
					
					printf("\tContact Number: ");
					scanf("%d",&c.contact);
					
					printf("\tHeight(FT): ");
					scanf("%d",&c.height);
					
					printf("\tWight(KG): ");
					scanf("%d",&c.weight);
					
					fflush(stdin);
					printf("\tHaircolor: ");
					gets(c.haircolor);
					
					fflush(stdin);
					printf("\tEyecolor: ");
					gets(c.eyecolor);
					
					printf("\tFIR No: ");
					scanf("%d",&c.fir_no);
					
					fflush(stdin);
					printf("\tCrime: ");
					gets(c.crime);
					
					fwrite(&c,sizeof(c),1,fp);
					fclose(fp);					
					if(fwrite!=0)
					{
						printf("\n\n\tData Saved Successfully!!");
						printf("\n\n\tDo you Want to add more Data? Press 'Y' for YES.\n\t>");
						yesno=getche();
						if(yesno == 'y' || yesno == 'Y')
						{
							goto createtop;
						}
						else
						{
							goto menu;
						}
					}
					else
					{
						printf("Could Not Saved Data!!");
					}
					

					
					break;
				}
				
			case 2:
				{
					modifytop:
					system("cls");
					printf("\n\t===========================\n");
					printf("\t\tMODIFY RECORDS\n");
					printf("\t===========================\n\n");
					int fir;
					printf("\tEnter Fir Number: ");
					scanf("%d",&fir);
					FILE *m;
					
					m=fopen("Criminal.txt","rb+");
					
					while(fread((&c),sizeof(c),1,m)==1)
					{
					
					if(fir==c.fir_no)
					{
						printf("\n\t----------");
						printf("\n\tOLD RECORD");
						printf("\n\t----------\n\n");
						printf("\n\n\tName: %s\n",c.name);
						printf("\tAddress: %s\n",c.address);
						printf("\tSex: %s\n",c.sex);
						printf("\tAge: %d\n",c.age);
						printf("\tContact No.: %d\n",c.contact);
						printf("\tHeight: %d ft\n",c.height);
						printf("\tWight: %d kg\n",c.weight);
						printf("\tHaircolor: %s\n",c.haircolor);
						printf("\tEyecolor: %s\n",c.eyecolor);
						printf("\tFIR No.: %d\n",c.fir_no);
						printf("\tCrime: %s\n",c.crime);
						

						printf("\n\n\n\t--------------------");
						printf("\n\tData for New Records");
						printf("\n\t--------------------\n\n");						
						fflush(stdin);
						printf("\n\tName: ");
						gets(c.name);
						
						fflush(stdin);
						printf("\tAddress: ");
						gets(c.address);
						
						fflush(stdin);
						printf("\tSex: ");
						gets(c.sex);
					
						printf("\tAge: ");
						scanf("%d",&c.age);
					
						printf("\tContact Number: ");
						scanf("%d",&c.contact);
					
						printf("\tHeight(FT): ");
						scanf("%d",&c.height);
					
						printf("\tWight(KG): ");
						scanf("%d",&c.weight);
					
						fflush(stdin);
						printf("\tHaircolor: ");
						gets(c.haircolor);
					
						fflush(stdin);
						printf("\tEyecolor: ");
						gets(c.eyecolor);
					
						printf("\tFIR No: ");
						scanf("%d",&c.fir_no);
					
						fflush(stdin);
						printf("\tCrime: ");
						gets(c.crime);
	
						fseek(m, -sizeof(m), SEEK_CUR);
						fwrite((&c),sizeof(c),1,m);			
						
						fclose(m);
					}
				}
					printf("\n\tYour record has been modified!!\n\n");
					printf("\n\nDo you want to modify another records? (Y for YES & N for NO\n)");
					char yyno;
					yyno=getche();
					if(yyno=='Y'||yyno=='y')
					{
						goto modifytop;
					}
					else if(yyno=='N'||yyno=='n')
					{
						goto menu;
					}
					
					break;
				}
				
			case 3:
				{
					char yes_no;
					system("cls");
					printf("\n\t===========================\n");
					printf("\t\tLIST RECORDS\n");
					printf("\t===========================\n");
					
					FILE *fpt;
					
					fpt=fopen("Criminal.txt","r");
					
					while(fread((&c),sizeof(c),1,fpt))
					{
						printf("\n\n\tName: %s\n",c.name);
						printf("\tAddress: %s\n",c.address);
						printf("\tSex: %s\n",c.sex);
						printf("\tContact No.: %d\n",c.contact);
						printf("\tHeight: %d ft\n",c.height);
						printf("\tWight: %d kg\n",c.weight);
						printf("\tHaircolor: %s\n",c.haircolor);
						printf("\tEyecolor: %s\n",c.eyecolor);
						printf("\tFIR No.: %d\n",c.fir_no);
						printf("\tCrime: %s\n",c.crime);
						
					}
					fclose(fpt);
					
					printf("\n\n\tPress (*) to go back to Main Menu!!!!");
					list_records_buttom:
					yes_no=getch();
					
					if(yes_no == '*')
					{
						goto menu;
					}
					else
					{
						printf("\n\n\tInvalid click... Please press (*) to go back to Main Menu!!");
						goto list_records_buttom;
					}
					break;
				}
				
			case 4:
				{
					system("cls");
					printf("\n\t===========================\n");
					printf("\t\tDELETE RECORDS\n");
					printf("\t===========================\n");
																				
					FILE *fpt,*temp;
					int cfirno;				
								
					fpt=fopen("Criminal.txt","r");
					temp=fopen("temp.txt","a");
					printf("\n\tEnter FIR No: ");
					scanf("%d",&cfirno);
					while(fread((&c),sizeof(c),1,fpt))
					{
						if(cfirno!=c.fir_no)
						{
							fwrite((&c),sizeof(c),1,temp);					
						}
					}
					fclose(fpt);
					fclose(temp);
					remove("Criminal.txt");
					rename("temp.txt","Criminal.txt");
					
					char delback;
					printf("\n\n\tYour Data is successfully Deleted!!");
					printf("\n\n\tPress (*) to go back\n");
					delback=getche();
					if(delback=='*')
					{
						goto menu;
					}
					break;
				}
				
			case 5:
				{
					FILE *f;
					char yes_no;
					system("cls");
					printf("\n\t===========================\n");
					printf("\t\tSEARCH RECORDS\n");
					printf("\t===========================\n");
					int firNo;
					printf("\tEnter the FIR no.: ");
					scanf("%d",&firNo);
					f=fopen("Criminal.txt","r");
					
					while(fread((&c),sizeof(c),1,f))
					
					if(firNo==c.fir_no)
					{
						printf("\n\n\tThe Record is: \n");
						printf("\n\n\tName: %s\n",c.name);
						printf("\tAddress: %s\n",c.address);
						printf("\tSex: %s\n",c.sex);
						printf("\tContact No.: %d\n",c.contact);
						printf("\tHeight: %d ft\n",c.height);
						printf("\tWight: %d kg\n",c.weight);
						printf("\tHaircolor: %s\n",c.haircolor);
						printf("\tEyecolor: %s\n",c.eyecolor);
						printf("\tFIR No.: %d\n",c.fir_no);
						printf("\tCrime: %s\n",c.crime);
					}
					fclose(f);
					
					char YESno;
					printf("\n\n\t Press (*) to go back: ");
					YESno=getche();
					if(YESno=='*')
					{
						goto menu;
					}
					
					break;
				}
				
			case 6:				//for team members
				{
					char yno;
					system("cls");
					printf("\t\t\t===================================================\n");
					printf("\t\t\t\t  TEAM MEMBERS OF THE PROJECTS\n");
					printf("\t\t\t===================================================\n");
					printf("\n\n\t\t\t\t ______________________________");
					printf("\n\t\t\t\t|  __________________________  |");
					printf("\n\t\t\t\t| |                          | |");
					printf("\n\t\t\t\t| |                          | |");
					printf("\n\t\t\t\t| |  	    UMAIR AHMAD        | |");
					printf("\n\t\t\t\t| |                          | |");
					printf("\n\t\t\t\t| |                          | |");
					printf("\n\t\t\t\t| |__________________________| |");
					printf("\n\t\t\t\t|______________________________|");
					printf("\n\n\n\t\t\t\tPress (*) to go back!!!!!!....");
					team_member_buttom:
					yno=getche();
					if(yno == '*')
					{
						goto menu;
					}
					else
					{
						printf("\n\n\t\t\t\tInvalid Click....Please press (*) to go back!!");
						goto team_member_buttom;
					}
					break;
				}
				
			case 7:
				{
					exit(1);
					break;
				}
			default:
				{
					printf("\n\n\t\t\t\t\tInvalid Click!! \n\n\t\t\t\t  Press Any key to continue.");
					getch();
					goto menu;
				}
		}
		
	}	
	else
	{
		printf("\n\tLogin Denied");
		login_attemp=login_attemp+1;
		printf("\n\n\t%d times,You attemped wrong username or password.\n\tYou only have %d attemps left.\n",login_attemp,3-login_attemp);
		printf("\n\n\tPress any key to continue....");
		getch();
		system("cls");
		if(login_attemp>2)
		{
			printf("\n You have already attempted for 3 times.Please contact Administrator!!");
			exit(0);
		}
	
		goto top;
	}
	
	
	
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

	void addNewData();
	void displayData();
	void facultydisplay();
	void deleteData();
	void input();
	void output();
	void division1();
	void division2();
	void division3();
	void division4();

FILE *ECE;   //FILE NAMES FOR DIFFERENT BRANCH FILES
FILE *CSE;
FILE *IT;
typedef struct data		//STRUCTURE TO STORE DATA OF STUDENT BY INSTITUTION
{
	char firstname[50];
	char lastname[50];
	char fathername[100];
    char mothername[100];
	char address[150];
	char phone_no[15];
	char bloodgroup[5];
	char batchname[5];
	char fees[5];

	int roll;
	float marks[6];
	float obt_marks;
	float avg_marks;
	float total_marks[6];
	float percent;
}student;

student st;

int main()
{
	   int choice;
	   do
	   {
	    system("cls");

        printf("\t\t====== STUDENT DATA MANAGEMENT SYSTEM ======");
        printf("\n\n                                          ");
        printf( "Welcome");
        printf( "\n\n");
        printf( "\n \t\t\t 1. Add New Student's Record");
   	    printf( "\n \t\t\t 2. Display Student's Records");
        printf( "\n \t\t\t 3. Show Student's Faculty ");
        printf( "\n \t\t\t 4. Delete Student's Records");
        printf( "\n \t\t\t 5. Exit Student's Program");
        printf( "\n\n");
        printf("\t\t\t Please Select Your Choice :=> ");

        scanf("%d",&choice);

        switch(choice)              //MENU-DRIVEN BASED ON CHOICE
        {
        case 1:
            addNewData();
            break;

        case 2:
            displayData();
            break;

        case 3:
            facultydisplay();
             break;

        case 4:
            deleteData();
            break;

        case 5:
            printf( "\n\n");
            printf("\t\t     THANK YOU FOR USING THIS SOFTWARE");
            printf( "\n\n");
            getch();
            exit(0);
            printf("\n\n");
             break;

         default :
             printf("\n\t\tInvalid choice--Please enter the valid choice again:");
             break;
             }
        }while(choice<1||choice>=5);
	return 0;
}


void addNewData()				//USED TO ADD NEW RECORD IN THE SELECTED FILE ON BASIS OF THE BRANCH
{
	system("cls");
	int choice;
	char ans;
	  printf("\n\n");
	  printf( "\n \t\t 1. Add the record in CSE");
      printf( "\n \t\t 2. Add the record in IT");
      printf( "\n \t\t 3. Add the record in ECE");
      printf( "\n \t\t 4. return to main menu");
      printf( "\n");
      printf("\t\t Enter Your Choice :=> ");
	  top:scanf("%d",&choice);
	  switch(choice)
	  {
		case 1:
			system("cls");
			CSE=fopen("cse.txt","a");
			if(CSE==NULL)
			{
				printf("Error in opening CSE file");
				getch();
				exit(0);
			}

			do
			{
				input();
				fwrite(&st,sizeof(st),1,CSE);
				printf("Do you want to add another record (y for yes)(any key for no)");
				fflush(stdin);
				scanf("%c",&ans);
			}while(tolower(ans)=='y');
			fclose(CSE);
			break;

		case 2:
			system("cls");
			IT=fopen("it.txt","a");
			if(IT==NULL)
			{
				printf("Error in opening IT file");
				getch();
				exit(0);
			}
			do
			{
				input();
				fwrite(&st,sizeof(st),1,IT);
				printf("Do you want to add another record (y for yes)(any key for no)");
				fflush(stdin);
				scanf("%c",&ans);
			}while(tolower(ans)=='y');
			fclose(IT);
			break;

		case 3:
			system("cls");
			ECE=fopen("ece.txt","a");
			if(ECE==NULL)
			{
				printf("Error in opening ECE file");
				getch();
				exit(0);
			}
			do
			{
				input();
				fwrite(&st,sizeof(st),1,ECE);
				printf("do you want to add another record (y for yes)(any key for no)");
				fflush(stdin);
				scanf("%c",&ans);
			}while(tolower(ans)=='y');

			fclose(ECE);
			break;

		case 4:
			break;

			default :
			printf("\t\tInvalid choice");
			goto top;
			break;

	}
}


void input()				//TAKES INPUT THE DATA IN STRUCTURE TO STORE IN FILE
{
	int z;
	for(z=0;z<6;z++)
	{
		st.total_marks[z]=0;
		st.marks[z]=0;
	}
	int i;
	float sum=0;
	float total=0;
	char ans;
	printf("\tEnter the roll number of the Student:>");
	scanf("%d",&st.roll);
	fflush(stdin);
	printf("\tEnter the first name of the Student:>");
	fflush(stdin);
	gets(st.firstname);
	printf("\tEnter the last name of the Student:>");
	fflush(stdin);
	gets(st.lastname);
	printf("\tEnter the Batch of the Student:>");
	fflush(stdin);
	gets(st.batchname);
	printf("\tEnter Father's name:>");
	fflush(stdin);
	gets(st.fathername);
	printf("\tEnter Mother's name:>");
	fflush(stdin);
	gets(st.mothername);
	printf("\tEnter the Phone number:>");
	fflush(stdin);
	gets(st.phone_no);
	printf("\tEnter the Address:>");
	fflush(stdin);
	gets(st.address);
	printf("\tEnter the Blood Group:>");
	fflush(stdin);
    gets(st.bloodgroup);
    printf("\tHas he paid the fees????\n\t(y for yes)(any key for no):>");
	fflush(stdin);
	gets(st.fees);
	printf("\nDo u want to add marks(y for yes)(any key for no)");
	fflush(stdin);
	scanf("%c",&ans);
	for(i=0;i<1;i++)
	{
		if(tolower(ans)!='y')
		break;
		printf("Enter the total marks & marks obtained in SDF:>");
		scanf("%f%f",&st.total_marks[i],&st.marks[i]);
		i=i+1;
		printf("Enter the total marks & marks obtained in Physics:>");
		scanf("%f%f",&st.total_marks[i],&st.marks[i]);
		i=i+1;
		printf("Enter the total marks & marks obtained in English:>");
		scanf("%f%f",&st.total_marks[i],&st.marks[i]);
		i=i+1;
		printf("Enter the total marks & marks obtained in Mathematics:>");
		scanf("%f%f",&st.total_marks[i],&st.marks[i]);
		i=i+1;
		printf("Enter the total marks & marks obtained in SDF Laboratory:>");
		scanf("%f%f",&st.total_marks[i],&st.marks[i]);
		i=i+1;
		printf("Enter the total marks & marks obtained in Engineering Drawing:>");
		scanf("%f%f",&st.total_marks[i],&st.marks[i]);
		i=i+1;
	    }
		if(i!=0)
	    {
		    for(i=0;i<6;i++)
		    {
			    sum+=st.marks[i];
	            total+=st.total_marks[i];
	        }
		   st.obt_marks=sum;
		   st.avg_marks=sum/6.0;
		   st.percent=(sum/total)*100;
		}

}
int dist,frist,sec,pass;


void displayData()						//DISPLAYS DATA BY READING FILE AND CALLING OTHER PRINT FUNCTIONS
{
	int choice,fail,ch;
    system("cls");
    reverse:	printf("\n\n\n\n");
	printf("\n\t\t\t1.Display all");
	printf("\n\t\t\t2.Display CSE Students");
	printf("\n\t\t\t3.Display IT Students");
	printf("\n\t\t\t4.Display ECE Students");
	printf("\n\t\t\t5.Display passed student");
	printf("\n\t\t\t6.Display failed student");
	printf("\n\t\t\t7.Return to main menu");
	printf("\n\n\t\t\tEnter your choice from=>");
    upper: scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			system("cls");
			CSE=fopen("cse.txt","r");
			if(CSE==NULL)
			{
				printf("\n\n\t\tError in opening CSE Student's file\n");
			}
		    else
		    {
		    	while(fread(&st,sizeof(st),1,CSE)==1)
		    	{
		    		output();
		    	}
		    }
			IT=fopen("it.txt","r");
			if(IT==NULL)
			{
				printf("\n\n\t\tError in opening IT Student's file\n");
			}
		    else
		    {
		    	while(fread(&st,sizeof(st),1,IT)==1)
		    	{
		    		output();
		    	}
		    }
			ECE=fopen("ece.txt","r");
			if(ECE==NULL)
			{
				printf("\n\n\t\tError in opening ECE Student's file");
				getch();
				break;
			}
			while(fread(&st,sizeof(st),1,ECE)==1)
			{
				output();
			}
			getch();
			fclose(CSE);
			fclose(IT);
			fclose(ECE);
			break;
		case 2:
			system("cls");
			CSE=fopen("cse.txt","r");
			if(CSE==NULL)
			{
				printf("\n\n\t\tError in opening CSE Student's file");
				getch();
				break;
			}
			while(fread(&st,sizeof(st),1,CSE)==1)
			{
				output();
			}
			getch();
			fclose(CSE);
			break;
		case 3:
			system("cls");
			IT=fopen("it.txt","r");
			if(IT==NULL)
			{
				printf("\n\n\t\tError in opening IT Student's file");
				getch();
				break;
			}
			while(fread(&st,sizeof(st),1,IT)==1)
			{
				output();
			}
			getch();
			fclose(IT);
			break;
		case 4:
			system("cls");
			ECE=fopen("ece.txt","r");
			if(ECE==NULL)
			{
				printf("\n\n\t\tError in opening ECE Student's file");
				getch();
				break;
			}
			while(fread(&st,sizeof(st),1,ECE)==1)
			{
				output();
			}
			getch();
			fclose(ECE);
			break;
		case 5:
			system("cls");
			printf("Enter the Distiction percent=");
			scanf("%d",&dist);
			printf("Enter the Frist division percent=");
			scanf("%d",&frist);
			printf("Enter the Second division percent=");
			scanf("%d",&sec);
			printf("Enter the Passed division percent=");
			scanf("%d",&pass);
			system("cls");
			printf("\n\n");
			printf("\n\t\t1.All student");
			printf("\n\t\t2.CSE student");
			printf("\n\t\t3.IT student");
			printf("\n\t\t4.ECE student");
			printf("\n\t\t5.Return to menu");
			printf("\n\n\t\t\tEnter the choices=>");
		    above:	scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					system("cls");
					CSE=fopen("cse.txt","r");

					if(CSE==NULL)
					{
						printf("\n\n\t\tError in CSE Student's opening file\n\n");
					}
					else
					{
						while(fread(&st,sizeof(st),1,CSE)==1)
						{
							division1();
						}
						rewind(CSE);
						while(fread(&st,sizeof(st),1,CSE)==1)
						{
							division2();

						}
						rewind(CSE);
						while(fread(&st,sizeof(st),1,CSE)==1)
						{
							division3();

						}
						rewind(CSE);
						while(fread(&st,sizeof(st),1,CSE)==1)
						{
							division4();

						}
						fclose(CSE);
					}
					IT=fopen("it.txt","r");

					if(IT==NULL)
					{
					    printf("\n\n\t\tError in opening IT Student's file\n\n");
					}
					else
					{
						while(fread(&st,sizeof(st),1,IT)==1)
						{
							division1();
						}
						rewind(IT);
						while(fread(&st,sizeof(st),1,IT)==1)
						{
							division2();
						}
						rewind(IT);
		                while(fread(&st,sizeof(st),1,IT)==1)
						{
							division3();
						}
						rewind(IT);
						while(fread(&st,sizeof(st),1,IT)==1)
						{
							division4();
						}

						fclose(IT);
					}
					ECE=fopen("ece.txt","r");
					if(ECE==NULL)
					{
						printf("\n\n\t\terror in opening ECE Student's file");
						getch();
						break;
					}
					while(fread(&st,sizeof(st),1,ECE)==1)
					    division1();
				    rewind(ECE);
					while(fread(&st,sizeof(st),1,ECE)==1)
					    division2();
				    rewind(ECE);
					while(fread(&st,sizeof(st),1,ECE)==1)
					    division3();
		            rewind(ECE);
					while(fread(&st,sizeof(st),1,ECE)==1)
					    division4();
					getch();
					fclose(ECE);
				    break;

					case 2:
						system("cls");
						CSE=fopen("cse.txt","r");
						if(CSE==NULL)
						{
							printf("\n\n\t\tError in opening CSE Student's file");
							getch();
							break;
						}
						while(fread(&st,sizeof(st),1,CSE)==1)
						division1();
							rewind(CSE);
						while(fread(&st,sizeof(st),1,CSE)==1)
						division2();
							rewind(CSE);
						while(fread(&st,sizeof(st),1,CSE)==1)
						division3();
							rewind(CSE);
						while(fread(&st,sizeof(st),1,CSE)==1)
						division4();
						getch();
					    fclose(CSE);
						break;

					case 3:
						system("cls");
						IT=fopen("it.txt","r");
						if(IT==NULL)
						{
						printf("\n\n\t\tError in opening IT Student's file");
						getch();
						break;
						}
						while(fread(&st,sizeof(st),1,IT)==1)
						{
							division1();
						}
						rewind(IT);
						while(fread(&st,sizeof(st),1,IT)==1)
						{
							division2();
						}
						rewind(IT);
						while(fread(&st,sizeof(st),1,IT)==1)
						{
						division3();
						}
							rewind(IT);
						while(fread(&st,sizeof(st),1,IT)==1)
						{
							division4();
						}
						getch();
						fclose(IT);
						break;

					case 4:
						system("cls");
						ECE=fopen("ece.txt","r");
						if(ECE==NULL)
						{
							printf("\n\n\t\tError in opening ECE Student's file");
							getch();
							break;
						}
						while(fread(&st,sizeof(st),1,ECE)==1)
						division1();
							rewind(ECE);
						while(fread(&st,sizeof(st),1,ECE)==1)
						division2();
							rewind(ECE);
						while(fread(&st,sizeof(st),1,ECE)==1)
						division3();
							rewind(ECE);
						while(fread(&st,sizeof(st),1,ECE)==1)
						division4();
						getch();
					    fclose(ECE);
						break;

					case 5:
						system("cls");
						goto reverse;
						break;

					default :
					printf("Enter the valid choice");
					goto above;
					break;
			}
			break;

		case 6:
			system("cls");
			printf("Enter the fail percent");
			scanf("%d",&fail);
			CSE=fopen("cse.txt","r");
			if(CSE==NULL)
			{
				printf("\n\t\t\tError in opening CSE Student's file");
				getch();
				break;
			}
			while(fread(&st,sizeof(st),1,CSE)==1)
			{

			if(st.percent<=fail)
				{
					printf("\nRoll number=%d",st.roll);
					printf("\nName=%s %s",st.firstname,st.lastname);
					printf("\nFather's Name=%s",st.fathername);
					printf("\nMother's Name=%s",st.mothername);
					printf("\nBatch=%s",st.batchname);
					printf("\nBlood group=%s",st.bloodgroup);
					printf("\nPhone no=%s",st.phone_no);
					printf("\nAddress=%s",st.address);
					if(strcmp(st.fees,"y")==0||strcmp(st.fees,"Y")==0)
						printf("\nFees is Paid");
					else
						printf("\nFees is not Paid");
					printf("\n\n    \t\tMarks obtained in each subject are:>\n");
					printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
					printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
					printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
					printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
					printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
					printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
					printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
					printf("\n\ntotal obtained marks=%f",st.obt_marks);
					printf("\nAverage marks=%f",st.avg_marks);
					printf("\nPercentage=%f\n",st.percent);
					printf("\n\t------------------------------\n\n\n\n");
				}
			}
		    IT=fopen("it.txt","r");
			if(IT==NULL)
			{
			printf("\n\n\t\tError in opening IT Student's file");
			getch();
				break;
			}
				while(fread(&st,sizeof(st),1,IT)==1)
			{

		        if(st.percent<=fail)
			    {
			    	printf("\nRoll number=%d",st.roll);
			    	printf("\nName=%s %s",st.firstname,st.lastname);
			    	printf("\nFather's Name=%s",st.fathername);
			    	printf("\nMother's Name=%s",st.mothername);
			    	printf("\nBatch=%s",st.batchname);
			    	printf("\nBlood group=%s",st.bloodgroup);
			    	printf("\nPhone no=%s",st.phone_no);
			    	printf("\nAddress=%s",st.address);
			    	if(strcmp(st.fees,"y")==0||strcmp(st.fees,"Y")==0)
						printf("\nFees is Paid");
					else
						printf("\nFees is not Paid");
			    	printf("\n\n    \t\tMarks obtained in each subject are:>\n");
			    	printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
			    	printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
			    	printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
			    	printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
			    	printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
			    	printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
			    	printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
			    	printf("\n\ntotal obtained marks=%f",st.obt_marks);
			    	printf("\nAverage marks=%f",st.avg_marks);
			    	printf("\nPercentage=%f",st.percent);
			    	printf("\n\t------------------------------\n\n\n\n");
			    }
		    }
		    ECE=fopen("ece.txt","r");
		    if(ECE==NULL)
			{
				printf("\n\n\t\tError in opening ECE Student's file");
				getch();
				break;
			}
			while(fread(&st,sizeof(st),1,ECE)==1)
			{

			if(st.percent<=fail)
				{
					printf("\nRoll number=%d",st.roll);
					printf("\nName=%s %s",st.firstname,st.lastname);
					printf("\nFather's Name=%s",st.fathername);
					printf("\nMother's Name=%s",st.mothername);
					printf("\nBatch=%s",st.batchname);
					printf("\nBlood group=%s",st.bloodgroup);
					printf("\nPhone no=%s",st.phone_no);
					printf("\nAddress=%s",st.address);
					if(strcmp(st.fees,"y")==0||strcmp(st.fees,"Y")==0)
						printf("\nFees is Paid");
					else
						printf("\nFees is not Paid");
					printf("\n\n    \t\tMarks obtained in each subject are:>\n");
					printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
					printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
					printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
					printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
					printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
					printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
					printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
					printf("\n\ntotal obtained marks=%f",st.obt_marks);
					printf("\nAverage marks=%f",st.avg_marks);
					printf("\nPercentage=%f",st.percent);
					printf("\n\t------------------------------\n\n\n\n");
				}
			}
			getch();
			fclose(CSE);
			fclose(IT);
			fclose(ECE);
			break;

		case 7:
			fclose(CSE);
			fclose(IT);
			fclose(ECE);
			system("cls");
			break;

		default :
			printf("Enter the valid choice");
			goto upper;
			break;
	}
}


void output()                     //PRINTS THE DATA FROM STRUCTURE
{
	printf("\nRoll number=%d",st.roll);
	printf("\nName=%s %s",st.firstname,st.lastname);
	printf("\nFather's Name=%s",st.fathername);
	printf("\nMother's Name=%s",st.mothername);
	printf("\nBatch=%s",st.batchname);
	printf("\nBlood group=%s",st.bloodgroup);
	printf("\nPhone no=%s",st.phone_no);
	printf("\nAddress=%s",st.address);
	if(strcmp(st.fees,"y")==0||strcmp(st.fees,"Y")==0)
		printf("\nFees is Paid");
	else
		printf("\nFees is not Paid");
	printf("\n\n    \t\tMarks obtained in each subject are:>\n");
	printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
	printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
	printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
	printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
	printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
	printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
	printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
	printf("\n\ntotal obtained marks=%.2f",st.obt_marks);
	printf("\nAverage marks=%.2f",st.avg_marks);
	printf("\nPercentage=%.2f",st.percent);
	printf("\n\t------------------------------\n\n\n\n");
}


void division1()                //PRINTS DATA FOR DISTINCTION PERCENT STUDENTS
{
	if(st.percent>=dist)
	{
	    printf("\nRoll number=%d",st.roll);
		printf("\nName=%s %s",st.firstname,st.lastname);
		printf("\nFather's Name=%s",st.fathername);
	    printf("\nMother's Name=%s",st.mothername);
		printf("\nBatch=%s",st.batchname);
		printf("\nBlood group=%s",st.bloodgroup);
		printf("\nPhone no=%s",st.phone_no);
		printf("\nAddress=%s",st.address);
		if(strcmp(st.fees,"y")==0||strcmp(st.fees,"Y")==0)
		    printf("\nFees is Paid");
	    else
		    printf("\nFees is not Paid");
		printf("\n\n    \t\tMarks obtained in each subject are:>\n");
		printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
		printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
		printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
		printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
		printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
		printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
		printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
		printf("\n\ntotal obtained marks=%f",st.obt_marks);
		printf("\nAverage marks=%f",st.avg_marks);
		printf("\nPercentage=%f",st.percent);
		printf("\n\t------------------------------\n\n\n\n");
    }

}

void division2()                  //PRINTS DATA FOR STUDENTS BETWEEN DISTINCTION AND FIRST DIVISION STUDENTS
{
	if(st.percent>=frist && st.percent<dist)
	{
		printf("\nRoll number=%d",st.roll);
		printf("\nName=%s %s",st.firstname,st.lastname);
		printf("\nFather's Name=%s",st.fathername);
		printf("\nMother's Name=%s",st.mothername);
		printf("\nBatch=%s",st.batchname);
		printf("\nBlood group=%s",st.bloodgroup);
		printf("\nPhone no=%s",st.phone_no);
		printf("\nAddress=%s",st.address);
		if(strcmp(st.fees,"y")==0||strcmp(st.fees,"Y")==0)
		    printf("\nFees is Paid");
	    else
		    printf("\nFees is not Paid");
		printf("\n\n    \t\tMarks obtained in each subject are:>\n");
		printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
		printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
		printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
		printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
		printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
		printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
		printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
		printf("\n\ntotal obtained marks=%f",st.obt_marks);
		printf("\nAverage marks=%f",st.avg_marks);
		printf("\nPercentage=%f",st.percent);
		printf("\n\t------------------------------\n\n\n\n");
	}
}
void division3()                   //PRINTS DATA FOR STUDENTS BETWEEN SECOND AND FIRST DIVISION  STUDENTS
{
	if(st.percent>=sec && st.percent<frist)
	{
		printf("\nRoll number=%d",st.roll);
		printf("\nName=%s %s",st.firstname,st.lastname);
		printf("\nFather's Name=%s",st.fathername);
		printf("\nMother's Name=%s",st.mothername);
		printf("\nBatch=%s",st.batchname);
		printf("\nBlood group=%s",st.bloodgroup);
		printf("\nPhone no=%s",st.phone_no);
		printf("\nAddress=%s",st.address);
		if(strcmp(st.fees,"y")==0||strcmp(st.fees,"Y")==0)
		    printf("\nFees is Paid");
	    else
		    printf("\nFees is not Paid");
		printf("\n\n    \t\tMarks obtained in each subject are:>\n");
		printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
		printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
		printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
		printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
		printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
		printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
		printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
		printf("\n\ntotal obtained marks=%f",st.obt_marks);
		printf("\nAverage marks=%f",st.avg_marks);
		printf("\nPercentage=%f",st.percent);
		printf("\n\t------------------------------\n\n\n\n");
	}
}
void division4()                //PRINTS DATA FOR STUDENTS BETWEEN PASSED PERCENT TO SECOND DIVISION STUDENTS
{
	if(st.percent>=pass && st.percent<sec)
	{
		printf("\nRoll number=%d",st.roll);
		printf("\nName=%s %s",st.firstname,st.lastname);
		printf("\nFather's Name=%s",st.fathername);
		printf("\nMother's Name=%s",st.mothername);
		printf("\nBatch=%s",st.batchname);
		printf("\nBlood group=%s",st.bloodgroup);
		printf("\nPhone no=%s",st.phone_no);
		printf("\nAddress=%s",st.address);
		if(strcmp(st.fees,"y")==0||strcmp(st.fees,"Y")==0)
		    printf("\nFees is Paid");
	    else
		    printf("\nFees is not Paid");
		printf("\n\n    \t\tMarks obtained in each subject are:>\n");
		printf("Subject  \t\ttotal marks\tobt marks\t\n\n");
		printf("Computer= \t\t%.2f\t\t%.2f\n",st.total_marks[0],st.marks[0]);
		printf("physics=  \t\t%.2f\t\t%.2f\n",st.total_marks[1],st.marks[1]);
		printf("Mechanics= \t\t%.2f\t\t%.2f\n",st.total_marks[2],st.marks[2]);
		printf("Mathematics=\t\t%.2f\t\t%.2f\n",st.total_marks[3],st.marks[3]);
		printf("Electrical=  \t\t%.2f\t\t%.2f\n",st.total_marks[4],st.marks[4]);
		printf("Drawing=      \t\t%.2f\t\t%.2f\n",st.total_marks[5],st.marks[5]);
		printf("\n\ntotal obtained marks=%f",st.obt_marks);
		printf("\nAverage marks=%f",st.avg_marks);
		printf("\nPercentage=%f",st.percent);
		printf("\n\t------------------------------\n\n\n\n");
	}
}

void facultydisplay(){                //DISPLAYS NAME OF FACULTY BASED ON BRANCH

	system("cls");
	printf("\n\n\n\n");
	printf("\n\t\tEnter the Student's Branch for Faculty (1 for CSE, 2 for IT OR 3 for ECE) :\n");
	int choice;
    scanf("%d", &choice);
    switch(choice)
    {
    	case 1:
    	printf("\nSDF by : Archana Gandhi");
		printf("\nEnglish by : Radha Mishra");
		printf("\nPhysics by : Devendra Pandey");
		printf("\nMathematics by : Rahul Tiwari");
		printf("\nSDF Laboratory by : Neeta Kumari");
		printf("\nEngineering Drawing by : Madhu Jharia");
		break;

		case 2:
		printf("\nSDF by : Bhaskar Singhi");
		printf("\nEnglish by : Rina Tiwari");
		printf("\nPhysics by : Ravi Joshi");
		printf("\nMathematics by : Pankaj Singh");
		printf("\nSDF Laboratory by : Ajeta Kumari");
		printf("\nEngineering Drawing by : Ankit Saxena");
		break;

		case 3:
		printf("\nSDF by : Priyank Singh");
		printf("\nEnglish by : Radha Mishra");
		printf("\nPhysics by : Abhishek Yadav");
		printf("\nMathematics by : Ritesh Verma");
		printf("\nSDF Laboratory by : Rima Khan");
		printf("\nEngineering Drawing by : Katrina Kaif");
		break;

		default:
		printf("Invalid Branch of student");
    }
}
void deleteData(){            //DELETES DATA BASED ON BRANCH AND ROLL NUMBER OF THE STUDENT

	system("cls");
    char *b="";
    int choice;
    printf("\n\t\tEnter the Student's Branch whom you want to delete(1 for CSE, 2 for IT OR 3 for ECE) :\n");
    scanf("%d", &choice);
    int check=0;
       do{
            switch(choice){
    	    case 1: b="cse.txt";
    	    break;
    	    case 2: b="it.txt";
    	    break;
    	    case 3: b="ece.txt";
 	        break;
 	        default:printf("Invalid Branch selected!!!\n\n");
 	        exit(0);
 	        check=1;
            }
         }while(check!=0);
    int recno;
    printf("\n\t\tEnter the Student's Roll Number to delete : ");
    scanf("%d", &recno);
    char ch;
    FILE *fp, *ft;
    fp=fopen(b, "r");
    ft=fopen("Temp.txt", "w");
    while((fread((char *)&st, sizeof(st), 1, fp))==1){
        if(st.roll==recno){
        printf("\n\n\t\tStudent Roll Number : %d", st.roll);
        printf("\n\t\tStudent Name : %s",st.firstname);
        printf("\n");
        printf("\n\t\tDo you want to delete this record : ? (Y/N)");
        fflush(stdin);
        scanf("%c", &ch);
        }
    }
    if(ch=='y'||ch=='Y'){
        rewind(fp);
        while((fread((char *)&st, sizeof(st), 1, fp))==1)
        {
            if(recno!=st.roll)
            {
            fwrite((char *)&st, sizeof(st), 1, ft);
            }
        }
        printf("\n\t\t Record deleted");
    }
    else{
        printf("\n\t\tNo Record was deleted");
    }
    fclose(fp);
    fclose(ft);
    remove(b);
    rename("Temp.txt", b);
}

#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
class NB
{
	string db[14][6];
	float age1,income1,student1,credit1,tyes,tno;
		
	public:
		NB();
		float yespro(string age,string income,string student,string credit);
		float nopro(string age, string income, string student, string credit);
		
};

NB::NB()
{
	age1=income1=student1=credit1=tyes=tno=0;

	db[0][0]="youth";	db[0][1]="high";	db[0][2]="no";		db[0][3]="fair";		db[0][4]="no";
	db[1][0]="youth";	db[1][1]="high";	db[1][2]="no";		db[1][3]="excellent";		db[1][4]="no";
	db[2][0]="middle";	db[2][1]="high";	db[2][2]="no";		db[2][3]="fair";		db[2][4]="yes";
	db[3][0]="senior";	db[3][1]="medium";	db[3][2]="no";		db[3][3]="fair";		db[3][4]="yes";
	db[4][0]="senior";	db[4][1]="low";		db[4][2]="yes";		db[4][3]="fair";		db[4][4]="yes";
	db[5][0]="senior";	db[5][1]="low";		db[5][2]="yes";		db[5][3]="excellent";		db[5][4]="no";
	db[6][0]="middle";	db[6][1]="low";		db[6][2]="yes";		db[6][3]="excellent";		db[6][4]="yes";
	db[7][0]="youth";	db[7][1]="medium";	db[7][2]="no";		db[7][3]="fair";		db[7][4]="no";
	db[8][0]="youth";	db[8][1]="low";		db[8][2]="yes";		db[8][3]="fair";		db[8][4]="yes";
	db[9][0]="senior";	db[9][1]="medium";	db[9][2]="yes";		db[9][3]="fair";		db[9][4]="yes";
	db[10][0]="youth";	db[10][1]="medium";	db[10][2]="yes";	db[10][3]="excellent";		db[10][4]="yes";
	db[11][0]="middle";	db[11][1]="medium";	db[11][2]="no";		db[11][3]="excellent";		db[11][4]="yes";
	db[12][0]="middle";	db[12][1]="high";	db[12][2]="yes";	db[12][3]="fair";		db[12][4]="yes";
	db[13][0]="senior";	db[13][1]="medium";	db[13][2]="no";		db[13][3]="excellent";		db[13][4]="no";

}

float NB :: yespro(string age, string income, string student, string credit)
{
	for(int i=0;i<14;i++)
	{
		if(db[i][4]=="yes")
		{
			tyes++;
		}
		if(db[i][0]== age && db[i][4]== "yes")
		{
			age1++;
		}
		if(db[i][1]==income && db[i][4]== "yes")
		{
			income1++;		
		}
		if(db[i][2]==student && db[i][4]=="yes")
		{
			student1++;
		}
		if(db[i][3]==credit && db[i][4]=="yes")
		{
			credit1++;
		}
	}
	return(((age1*income1*student1*credit1)/(tyes*tyes*tyes*tyes))*(tyes/14));
}
float NB :: nopro(string age, string income, string student, string credit)
{
	for(int i=0;i<14;i++)
	{
		if(db[i][4]=="no")
		{
			tno++;
		}
		if(db[i][0]== age && db[i][4]== "no")
		{
			age1++;
		}
		if(db[i][1]==income && db[i][4]== "no")
		{
			income1++;		
		}
		if(db[i][2]==student && db[i][4]=="no")
		{
			student1++;
		}
		if(db[i][3]==credit && db[i][4]=="no")
		{
			credit1++;
		}
	}
	return(((age1*income1*student1*credit1)/(tno*tno*tno*tno))*(tno/14));
}
int main()
{
	NB nb;
	nb = NB();
	float yes,no;
	string age, income, student, credit;
	cout<<"\nEnter the age (youth/medium/senior): ";
	cin>>age;
	cout<<"\nEnter the income (high/medium/low): ";
	cin>>income;
	cout<<"\nEnter the is student? (yes/no): ";
	cin>>student;
	cout<<"\nEnter the credit (fair/excellent): ";
	cin>>credit;
	
	yes = nb.yespro(age,income,student,credit);
	no = nb.nopro(age,income,student,credit);


	cout<<endl<<"\nProbability of buying the computer: "<<yes<<endl;
	cout<<endl<<"\nProbability of not buying the computer: "<<no<<endl;
	
	if(yes>no)
	{
		cout<<"\nPerson buys the computer..."<<endl;
	}
	else
	{
		cout<<"\nPerson does not buy the computer..."<<endl;
	}

	cout<<endl;	
		
	return 0;
}

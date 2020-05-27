/*
	email id -  jyoti.18190@lpu.co.in
	FileName-  K18XC_AyushKumarAgrawal_RK18XCA09

*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>


using namespace std;



/************************************************************************************************************/
/*                                                                                                          */
/*											CLASS DECLARATION												*/
/*                                                                                                          */
/************************************************************************************************************/
class Weather
{
	private:
		char Location[50];
		float humidity;
		float temperature;
		float rainfall;
	public:
			void input();
			void input1();
			void display();
			void readFile();
			void writeFile();
			void appendFile();
			void Search();
			void Delete();
			void forecast();
};

/************************************************************************************************************/
/*                                                                                                          */
/*										    	MAIN FUNCTION 												*/
/*                                                                                                          */
/************************************************************************************************************/

int main()
{  
	char ch;
	do
	{
		cout<<"\n\n\t\t旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커";
		cout<<"\n\t\t|                                                                  |";
		cout<<"\n\t\t|                           Weather Report                         |";
		cout<<"\n\t\t|__________________________________________________________________|";
		cout<<"\n\t\t|                                                                  |";
		cout<<"\n\t\t|                           1. Add Record                          |";
		cout<<"\n\t\t|                           2. Display Record                      |";
		cout<<"\n\t\t|                           3. Append Record                       |";
		cout<<"\n\t\t|                           4. Search Record                       |";
		cout<<"\n\t\t|                           5. Delete Record                       |";
		cout<<"\n\t\t|                           6. Weather Forecast                    |";
		cout<<"\n\t\t|                           7. Exit                                |";
		cout<<"\n\t\t읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸";
		int choice;
		Weather W;
  		cout<<"\n\n\t\tENTER YOUR CHOICE (1-7):";
  		cin>>choice;
		switch(choice)
		{
    		case 1: W.writeFile();
    	    	    break;
    		case 2: W.readFile();
      				break;
    		case 3: W.appendFile();
        		    break;
        	case 4: W.Search();
        			break;
        	case 5: W.Delete();
        			break;
        	case 6: W.forecast();
        			break;
    		case 7: exit(0);
    		default: cout<<"\n\nINVALID CHOICE !!!!";
		}
		cout<<"\n\nDo you want to continue(Y/N):";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}

/************************************************************************************************************/
/*                                                                                                          */
/*										CLASS FUNCTION DEFINITION											*/
/*                                                                                                          */
/************************************************************************************************************/

/************************************************************************************************************/
/*                                        INPUT FUNCTION                                                    */
/************************************************************************************************************/
void Weather::input()
{	
 		cout<<"Enter the location: ";
 		//fflush(stdin);
 		//getline(cin,Location);
		cin>>Location;
		cout<<"Enter the humidity(in %): ";
		cin>>humidity;
		cout<<"Enter the temperature(in Celsius): ";
	 	cin>>temperature;
		cout<<"Enter the rainfall amount(in mm): ";
		cin>>rainfall;
}

void Weather::input1()
{	
		cout<<"Enter the humidity(in %): ";
		cin>>humidity;
		cout<<"Enter the temperature(in Celsius): ";
	 	cin>>temperature;
		cout<<"Enter the rainfall amount(in mm): ";
		cin>>rainfall;
}

/************************************************************************************************************/
/*                                        DISPLAY FUNCTION                                                  */
/************************************************************************************************************/

void Weather::display()
{
	cout<<"\n\n\t\tLocation : "<<Location;
	cout<<"\n\n\t\tHumidity : "<<humidity<<"%";
	cout<<"\n\n\t\tTemperature : "<<temperature<<" C";
	cout<<"\n\n\t\tRainfall : "<<rainfall<<"mm";
}

/************************************************************************************************************/
/*                                        WRITE IN FILE FUNCTION                                            */
/************************************************************************************************************/
void Weather::writeFile()
{
 	fstream file;
	char choice;
	file.open("Weather Forecast.dat",ios::out|ios::binary);
	do
 	{
		(*this).input();
		file.write((char*)this,sizeof(Weather));
		cout<<"\n\nDo you want to enter more data(Y/N): ";
		cin>>choice;
	}while(choice=='y'||choice=='Y');
	file.close();
}

/************************************************************************************************************/
/*                                        READ FROM FILE FUNCTION                                           */
/************************************************************************************************************/
void Weather::readFile()
{
    fstream file;
    int i=1;
	file.open("Weather Forecast.dat",ios::in|ios::binary);
	cout<<"\nRecord "<<i<<":";
	file.read((char*)this,sizeof(Weather));
	(*this).display();
	while(file.read((char*)this,sizeof(Weather)))
    {
		i++;
		cout<<"\nRecord "<<i<<":";
		(*this).display();
	}
	file.close();
}

/************************************************************************************************************/
/*                                        APPEND IN FILE FUNCTION                                           */
/************************************************************************************************************/

void Weather::appendFile()
{
	fstream file;
	file.open("Weather Forecast.dat",ios::app|ios::binary);
	char choice;
	do
 	{
		(*this).input();
		file.write((char*)this,sizeof(Weather));
		cout<<"\n\nDo you want to enter more data(Y/N): ";
		cin>>choice;
	}while(choice=='y'||choice=='Y');
	file.close();
}

/************************************************************************************************************/
/*                                        SEARCH RECORD FUNCTION                                            */
/************************************************************************************************************/

void Weather::Search()
{
    int flag=0;
    char strtemp[50];
    cout<<"\n\nEnter Location to be search::";
    cin>>strtemp;
    fstream file;
    file.open("Weather Forecast.dat",ios::in|ios::binary);
    while(file.read((char*)this,sizeof(Weather)))
    {
		//file.read((char*)this,sizeof(Weather));
		if(strcmpi(Location,strtemp)==0)
		{
	    	cout<<"\n\nRecord Found.";
			(*this).display();
	    	flag=1;
	    	break;
		}
    }
    file.close();
    if(flag!=1)
		cout<<"\n\nRecord NOT FOUND!!!";
}

/************************************************************************************************************/
/*                                        DELETE RECORD FUNCTION                                            */
/************************************************************************************************************/

void Weather::Delete()
{
  	int flag=0;
  	char strtemp[50];
    cout<<"Enter Location to be deleted:";
    cin>>strtemp;
  	fstream file;
  	file.open("Weather Forecast.dat",ios::in|ios::binary);
  	ofstream fout("Temp.dat",ios::out|ios::binary);
  	while(file.read((char*)this,sizeof(Weather)))
  	{
  		if(strcmpi(Location,strtemp)!=0)
  		{
  			flag=1;
  			file.seekg((-1)*sizeof(Weather),ios::cur);
     		file.read((char*)this,sizeof(Weather));
     		fout.write((char*)this,sizeof(Weather));
  		}
  	}
  fout.close();
  file.close();
  remove("Weather Forecast.dat");
  rename("Temp.dat","Weather Forecast.dat");
  if(flag==1)
  	cout<<"\n\nRecord deleted Successfully.";
  else
  	cout<<"\n\nRecord can not be deleted.";
}


/************************************************************************************************************/
/*                                     WEATHER FORECAST FUNCTION                                            */
/************************************************************************************************************/

void Weather::forecast()
{
	float humidity,temperature,windspeed;
	cout<<"\n\n\t\t旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커";
	cout<<"\n\t\t|                                                                  |";
	cout<<"\n\t\t|                    Weather Forecast Channel                      |";
	cout<<"\n\t\t|                                                                  |";
	cout<<"\n\t\t읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸";
	cout<<"\n\n\t\t  Enter the humidity(in %): ";
	cin>>humidity;
	cout<<"\n\n\t\t  Enter the approximate temperature(in Celsius): ";
	cin>>temperature;
	cout<<"\n\n\t\t  Enter the wind speed(in kmph): ";
	cin>>windspeed;
	if(humidity>50 && temperature<=30)
		 cout<<"\n\n\t\t  There may be a little rainfall...";
	else if(humidity>50 && temperature>30)
		cout<<"\n\n\t\t  Very humid weather expected today...";
	else if(humidity<50 && temperature<=30)
		cout<<"\n\n\t\t  Very pleasant weather expected today...";
	else if(humidity<50 && temperature>30)
		cout<<"\n\n\t\t  Very hot weather expected today...";
	else if(windspeed>25)
		cout<<"\n\n\t\t  There may be storms...";
}

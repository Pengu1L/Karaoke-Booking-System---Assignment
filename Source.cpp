#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <windows.h>  //decoration purpose
using namespace std;

//array use to store login data
string Username[10];
string Password[10];
//array use to store booking details
int Room[10];
double Hours[10];
string Session_time[10];
double Payment[10];

const double rate = 8.50;
//prepare
void create();
void form();
void assign();
//choosing 
void menu();
//login 
bool login(string user_name, string user_password, bool& condition);
void booking();
bool check_room(int roomnum, bool& condition);
void updateroom1(int roomnum);
void roomlistupdate();
void payment(double hours, double& total);
//storing 
void keep(string user_name, int roomnum, double hours, int session_time, double payment);
//registration
bool check_username(string username, bool& condition);
void Save_account(string username, string password);
//lookup for booking and cancel
void search(string term);
void create2();
void remove(string username, int& roomnum);
void update();
void updateroom2(int roomnum);

int main(void)
{
	system("Color 0C");

	Beep(1000, 200);                                                             // causes the computer to beep
	char l = 219;                                                                 //for loading bar
	cout << "Please wait while system is analyzing the data\n";
	for (int i = 0; i < 10; i++)
	{
		Beep(1000, 200);
		cout << l;
	}


	cout << R"( 
    _____     _____   ______         __    __   ______   _______    ______    ______   __    __  ________ 
   /     |   /     | /      \       /  |  /  | /      \ /       \  /      \  /      \ /  |  /  |/        |
   $$$$$ |   $$$$$ |/$$$$$$  |      $$ | /$$/ /$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |$$ | /$$/ $$$$$$$$/ 
      $$ |      $$ |$$ \__$$/       $$ |/$$/  $$ |__$$ |$$ |__$$ |$$ |__$$ |$$ |  $$ |$$ |/$$/  $$ |__    
 __   $$ | __   $$ |$$      \       $$  $$<   $$    $$ |$$    $$< $$    $$ |$$ |  $$ |$$  $$<   $$    |   
/  |  $$ |/  |  $$ | $$$$$$  |      $$$$$  \  $$$$$$$$ |$$$$$$$  |$$$$$$$$ |$$ |  $$ |$$$$$  \  $$$$$/    
$$ \__$$ |$$ \__$$ |/  \__$$ |      $$ |$$  \ $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ \__$$ |$$ |$$  \ $$ |_____ 
$$    $$/ $$    $$/ $$    $$/       $$ | $$  |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$    $$/ $$ | $$  |$$       |
 $$$$$$/   $$$$$$/   $$$$$$/        $$/   $$/ $$/   $$/ $$/   $$/ $$/   $$/  $$$$$$/  $$/   $$/ $$$$$$$$/ 
                                                                                                          
                                                                                                          
                                                                                                          
)" << endl;//Graphic logo
	cout << R"(                    ___                                          ___
 __________________/  /                       __________________/  /
| _    _______    /  /                       | _    _______    /  /
|(_) .d########b. //)| _____________________ |(_) .d########b. //)|
|  .d############//  ||        _____        ||  .d############//  |
| .d######""####//b. ||() ||  [JAY C]  || ()|| .d######""####//b. |
| 9######(  )#_//##P ||()|__|  | = |  |__|()|| 9######(  )#_//##P |
| 'b######++#/_/##d' ||() ||   | = |   || ()|| 'b######++#/_/##d' |
|  "9############P"  ||   ||   |___|   ||   ||  "9############P"  |
|  _"9a#######aP"    ||  _   _____..__   _  ||  _"9a#######aP"    |
| |_|  `""""''       || (_) |_____||__| (_) || |_|  `""""''       |
|  ___..___________  ||_____________________||  ___..___________  |
| |___||___________| |                       | |___||___________| |
|____________________|  LETS HAVE FUN !!!!!  |____________________|
     
)" << endl;//graphic 


	create();
	form();
	create2();
	char  desire, cont1, cont2, cont3, decision_proceed;
	bool condition = true;
	string user_name, user_password, searching_term;
	int menu_decision, roomnum, hours, session_time;
	double total;
	do
	{
		menu();
		cin >> menu_decision;
		system("CLS");
		{
			if (menu_decision == 1)//log in 
			{
				do
				{
					cout << "Welcome to the user log in page.\n";
					cout << "Please key in your username.\n";
					cin.ignore();
					getline(cin, user_name);
					cout << "Please key in your password.\n";
					getline(cin, user_password);
					login(user_name, user_password, condition);
					if (condition == true)
					{
						system("Color 0A");
						cout << "Login successfully. \n";
						cin.get();
						system("CLS");
						system("Color 0C");
						cout << "You are in the booking page. \n";
						do
						{
							booking();
							cout << "Room: ";
							cin >> roomnum;
							while (roomnum < 0 || roomnum > 10)
							{
								cout << "Room: ";
								cin >> roomnum;
							}
							if (roomnum > 0 && roomnum < 11)
							{
								check_room(roomnum, condition);
								if (condition == true)
								{
									cout << "How long do you want to book for the session? \n";
									cout << "Hours: ";
									cin >> hours;
									cout << "What time you want to have your session? IN 2400 format. \n";
									cout << "The booking will start sharply. \n";
									cout << "Time: ";
									cin >> session_time;
									while (session_time < 1100 || session_time>2200)
									{
										cout << "Time slot unvailable. \n";
										cin >> session_time;
									}
									payment(hours, total);
									cout << "The payment for your session is RM: " << fixed << setprecision(2) << total << "\n";
									cout << "Please proceed to the counter for payment. \n";
									updateroom1(roomnum);
									roomlistupdate();
									keep(user_name, roomnum, hours, session_time, total);
									cin.get();
									system("Color 0A");
									cout << "Booking is completed.\n";
									cin.get();
									system("Color 0C");
									cout << "Do you wish to continue with another booking? Y/N \n";
									cin >> cont2;
									if ((toupper)(cont2) == 'N')
									{
										cout << "Do you wan to go back to the main menu? Y/N \n";
										cin >> cont1;
										cont3 = 'n';
										system("CLS");
									}

								}
								else
								{
									system("Color 0C");
									cout << "Room chosen is invalid. \n";
									cout << "Do you wish to continue? Y/N \n";
									cin >> cont3;
									if ((toupper)(cont3) == 'N')
									{
										cout << "Do you wan to go back to the main menu? Y/N \n";
										cin >> cont1;
										cont2 = 'n';
										system("CLS");
									}
								}
							}
							else
							{
								system("Color 0A");
								cout << "Room out of limit. \n";
								cout << "Do you wish to continue? Y/N \n";
								cin >> cont3;
								if ((toupper)(cont3) == 'N')
								{
									cout << "Do you wan to go back to the main menu? Y/N \n";
									cin >> cont1;
									cont2 = 'n';
									system("CLS");
								}
							}

						} while ((toupper)(cont3) == 'Y');

					}
					else
					{
						system("Color 0C");
						cout << "User doesn't exist / Wrong password.. \n";
						cout << "Do you wish to continue? Y/N \n";
						cin >> cont2;
						if ((toupper)(cont2) == 'N')
						{
							cout << "Do you wan to go back to the main menu? Y/N \n";
							cin >> cont1;
							system("CLS");
						}
					}

				} while ((toupper)(cont2) == 'Y');
			}

			else if (menu_decision == 2)//registration
			{
				do
				{
					system("Color 0C");
					cout << "Please key in your prefer username. \n";
					cin >> user_name;
					check_username(user_name, condition);
					if (condition == true)
					{
						cout << "Please key in your password. Any format u like. \n";
						cin >> user_password;
						Save_account(user_name, user_password);
						system("Color 0A");
						cout << "Registration completed. \n";
						cin.get();
						cin.get();
						system("Color 0C");
						cout << "Do you want to log in now? Y/N. \n";
						cin >> decision_proceed;
						if ((toupper)(decision_proceed) == 'Y')
						{
							system("CLS");
							cout << "You are in the booking page. \n";
							booking();
							do
							{
								cout << "Room: ";
								cin >> roomnum;
								if (roomnum > 0 && roomnum < 11)
								{
									check_room(roomnum, condition);
									if (condition == true)
									{
										cout << "How long do you want to book for the session? \n";
										cout << "Hours: ";
										cin >> hours;
										cout << "What time you want to have your session? IN 2400 format. \n";
										cout << "The booking will start sharply. \n";
										cout << "Time: ";
										cin >> session_time;
										while (session_time < 1100 || session_time>2200)
										{
											cout << "Time slot unvailable. \n";
											cin >> session_time;
										}
										payment(hours, total);
										cout << "The payment for your session is RM: " << fixed << setprecision(2) << total << "\n";
										cout << "Please proceed to the counter for payment. \n";
										updateroom1(roomnum);
										roomlistupdate();
										keep(user_name, roomnum, hours, session_time, total);
										system("Color 0A");
										cout << "Booking is completed.\n";
										cin.get();
										system("Color 0C");
										cout << "Do you wish to continue? Y/N \n";
										cin >> cont2;
										if ((toupper)(cont2) == 'N')
										{
											cout << "Do you wan to go back to the main menu? Y/N \n";
											cin >> cont1;
											cont3 = 'n';
											system("CLS");
											break;
										}

									}
									else
									{
										system("Color 0C");
										cout << "Room chosen is invalid. \n";
										cout << "Do you wish to continue? Y/N \n";
										cin >> cont3;
										if ((toupper)(cont3) == 'N')
										{
											cout << "Do you wan to go back to the main menu? Y/N \n";
											cin >> cont1;
											cont2 = 'n';
											system("CLS");
											break;
										}
									}
								}
								else
								{
									system("Color 0C");
									cout << "Room out of limit. \n";
									cout << "Do you wish to continue? Y/N \n";
									cin >> cont3;
									if ((toupper)(cont3) == 'N')
									{
										cout << "Do you wan to go back to the main menu? Y/N \n";
										cin >> cont1;
										cont2 = 'n';
										system("CLS");
										break;
									}

								}
							} while ((toupper)(cont3) == 'Y');

						}
						else
						{
							system("Color 0C");
							cout << "Thank you for registring with us. \n";
							cout << "Do you wish to continue to register a new account? Y/N \n";
							cin >> cont2;
							if ((toupper)(cont2) == 'N')
							{
								cout << "Do you wan to go back to the main menu? Y/N \n";
								cin >> cont1;
								cont2 = 'n';
								system("CLS");
							}
							system("CLS");
						}

					}
					else
					{
						system("Color 0C");
						cout << "Name is taken. \n";
						cout << "Please run the program again to register the account. \n";
						cont2 = 'y';
						system("CLS");
					}
				} while ((toupper)(cont2) == 'Y');
			}

			else if (menu_decision == 3)//look up for booking and proceed to delete
			{
				do
				{
					cout << "Please key in your username to do the searching. \n";
					cin >> searching_term;
					system("CLS");
					search(searching_term);
					cout << "Do you wish to delete the session booked? Y/N \n";
					cin >> desire;
					if ((toupper)(desire) == 'Y')
					{
						create2();
						remove(searching_term, roomnum);
						update();
						updateroom2(roomnum);
						roomlistupdate();
						cout << "Do you wish to continue? Y/N \n";
						cin >> cont2;
						if ((toupper)(cont2) == 'N')
						{
							cout << "Do you wan to go back to the main menu? Y/N \n";
							cin >> cont1;
							system("CLS");
						}
					}
					else
					{
						cout << "Wish you have a whale of time. \n";
						cout << "Do you wish to continue? Y/N \n";
						cin >> cont2;
						if ((toupper)(cont2) == 'N')
						{
							cout << "Do you wan to go back to the main menu? Y/N \n";
							cont2 = 'n';
							cin >> cont1;
							system("CLS");
						}
					}
				} while ((toupper)(cont2) == 'Y');
			}

			else if (menu_decision == 4)//lookup for personal profile, any details related will be cout
			{
				do
				{
					system("Color 0C");
					cout << "Please key in your username to do the searching. \n";
					cin >> searching_term;
					system("CLS");
					system("Color 0A");
					search(searching_term);
					system("Color 0C");
					cout << "Do you wish to continue? Y/N \n";
					cin >> cont2;
					if ((toupper)(cont2) == 'N')
					{
						cout << "Do you wish to go to the main menu? Y/N \n";
						cin >> cont1;
						cont2 = 'n';
						system("cls");
					}
				} while ((toupper)(cont2) == 'Y');

			}

			else
			{
				system("Color 0C");
				cout << "Invalid input. \n";
				cout << "Do you wish to continue? Y/N \n";
				cin >> cont1;
				system("CLS");
			}

		}
	} while ((toupper)(cont1) == 'Y');
	system("Color 0A");
	cout << "Thank you for visiting the system. \n";
	cout << "See you next time. \n";
	system("pause");
	return 0;
}

//the main menu of the system
void menu()
{
	cout << "Welcomed to JJS Karaoke.\n";
	cout << "The smallest Karaoke based in Kampar.\n";
	cout << "1. Log in.\n";
	cout << "2. Registration. \n";
	cout << "3. Check booking. \n";
	cout << "4. Check profile. \n";
	cout << "Make your decision. \n";
}

//use to check useer login status
bool login(string user_name, string user_password, bool& condition)
{
	int i = 0;
	ifstream Existed;
	Existed.open("Name and password.txt");
	if (Existed.is_open())
	{
		while (!Existed.eof())
		{
			if (i == 10 || i > 10)
				break;
			getline(Existed, Username[i]);
			getline(Existed, Password[i]);
			if (Username[i] == user_name)
			{
				if (user_password == Password[i])
				{
					condition = true;
					return condition;
					break;
				}
			}

			i++;
		}
		Existed.close();
	}
	condition = false;
	return condition;
}

void booking()
{
	cout << "Welcome again. \n";
	cout << "There is 10 rooms for you to choose from. \n";
	cout << "Please key in the room you want. \n";
}

//check room availability 
bool check_room(int roomnum, bool& condition)
{
	int i = 0;
	ifstream room;
	room.open("Room.txt");
	if (room.is_open())
	{
		while (!room.eof())
		{
			if (i == 10 || i > 10)
				break;
			room >> Room[i];
			if (i == (roomnum - 1))
			{
				if (Room[i] == 0)
				{
					condition = true;
					return condition;
					break;
				}
				else
				{
					condition = false;
					return condition;
				}

			}
			i++;
		}
		room.close();
	}
}

void create2()
{
	ifstream templist;
	templist.open("Temp n booking.txt");
	if (templist.is_open())
	{
	}
	else
	{
		ofstream myfile;
		myfile.open("Temp n booking.txt");
		myfile.close();
	}
	templist.close();
}

void updateroom1(int roomnum)
{
	int i = 0;
	ifstream currentroom;
	ofstream updatedroom;
	currentroom.open("Room.txt");
	updatedroom.open("Temp.room.txt", ios::ate);
	if (currentroom.is_open())
	{
		while (!currentroom.eof())
		{
			i++;
			if (i > 10)
				break;
			currentroom >> Room[i];
			if (i == roomnum)
			{
				Room[i] = { 1 };
				updatedroom << Room[i] << endl;
				continue;
			}
			updatedroom << Room[i] << endl;

		}
		currentroom.close();
		updatedroom.close();
	}
}

void roomlistupdate()
{
	ifstream latest;
	ofstream current;
	latest.open("Temp.room.txt");
	current.open("Room.txt");
	if (latest.is_open())
	{
		int i = 0;
		while (!latest.eof())
		{
			latest >> Room[i];
			current << Room[i] << endl;
			i++;
		}
		latest.close();
		current.close();
	}

}

void payment(double hours, double& total)
{
	double sum = hours * rate;
	total = sum;
}

//save the booking details
void keep(string user_name, int roomnum, double hours, int session_time, double payment)
{
	ofstream completed;
	completed.open("Booking.txt", ios::app);
	if (completed.is_open())
	{
		completed << user_name << "\n";
		completed << roomnum << "\n";
		completed << hours << "\n";
		completed << session_time << "\n";
		completed << payment << "\n";
	}
	else
		cout << "Unable to open file. \n";

}

bool check_username(string username, bool& condition)
{
	ifstream name;
	name.open("Name and password.txt");
	if (name.is_open())
	{
		int i = 0;
		while (!name.eof())
		{
			if (i == 10 || i > 10)
				break;
			getline(name, Username[i]);
			getline(name, Password[i]);
			if (username == Username[i])
			{
				condition = false;
				return condition;
				break;

			}
			else
			{
				condition = true;
				return condition;
			}
			i++;

		}
		name.close();
	}
}

//save the customer's account after success registration
void Save_account(string username, string password)
{
	ofstream account;
	account.open("Name and password.txt", ios::app);
	if (account.is_open())
	{
		account << username << "\n";
		account << password << "\n";
	}
	else
		cout << "Unable to open the file. \n";

}

void search(string term)
{
	ifstream completed_booking;
	completed_booking.open("Booking.txt");
	if (completed_booking.is_open())
	{
		int i = 0;
		while (!completed_booking.eof())
		{

			completed_booking >> Username[i];
			completed_booking >> Room[i];
			completed_booking >> Hours[i];
			completed_booking >> Session_time[i];
			completed_booking >> Payment[i];

			if (Username[i] == term)
			{
				cout << "The booking is made by: " << Username[i] << "\n";
				cout << "The room booked is: " << Room[i] << "\n";
				cout << "The hours booked: " << Hours[i] << "\n";
				cout << "Session booked: " << Session_time[i] << "\n";
				cout << "Payment: " << Payment[i] << "\n";
				break;
			}
			else
			{
			}

			i++;
		}
	}
	else
		cout << "Unable to open the file. \n";
}

void remove(string username, int& roomnum)
{
	ifstream existed_booking;
	existed_booking.open("Booking.txt");
	if (existed_booking.is_open())
	{
		int i = 0;
		while (!existed_booking.eof())
		{

			existed_booking >> Username[i];
			existed_booking >> Room[i];
			existed_booking >> Hours[i];
			existed_booking >> Session_time[i];
			existed_booking >> Payment[i];
			i++;
		}
		existed_booking.close();
	}
	else
		cout << "Unable to open the file. \n";

	ofstream Temp_booking;
	Temp_booking.open("Temp n booking.txt");
	for (int i = 0; i < 10; i++)
	{
		if (Username[i] == username)
		{
			roomnum = (i + 1);
		}
		else
		{
			Temp_booking << Username[i] << endl;
			Temp_booking << Room[i] << endl;
			Temp_booking << Hours[i] << endl;
			Temp_booking << Session_time[i] << endl;
			Temp_booking << Payment[i] << endl;
		}
	}
	Temp_booking.close();

}

void update()
{
	int i = 0;
	ifstream Temp;
	Temp.open("Temp n booking.txt");
	ofstream update_booking;
	update_booking.open("Booking.txt");
	if (Temp.is_open())
	{
		while (!Temp.eof())
		{
			Temp >> Username[i];
			update_booking << Username[i] << endl;
			Temp >> Room[i];
			update_booking << Room[i] << endl;
			Temp >> Hours[i];
			update_booking << Hours[i] << endl;
			Temp >> Session_time[i];
			update_booking << Session_time[i] << endl;
			Temp >> Payment[i];
			update_booking << Payment[i] << endl;
			i++;
		}
		Temp.close();
		update_booking.close();
	}
	else
		cout << "Unable to open the file. \n";

}

void updateroom2(int roomnum)
{
	int i = 0;
	ifstream currentroom;
	ofstream updatedroom;
	currentroom.open("Room.txt");
	updatedroom.open("Temp.room.txt");
	if (currentroom.is_open())
	{
		while (!currentroom.eof())
		{
			currentroom >> Room[i];
			if (i == (roomnum - 1))
			{
				Room[i] = { 0 };
				updatedroom << Room[i] << endl;
				continue;
			}
			updatedroom << Room[i] << endl;
			i++;
		}
		currentroom.close();
		updatedroom.close();
	}
}

void create()
{
	ifstream mylist;
	mylist.open("Room.txt");
	if (mylist.is_open())
	{
	}
	else
	{
		ofstream myfile;
		myfile.open("Room.txt");
		myfile.close();
	}
}

void form()
{

	ifstream form;
	form.open("Room.txt");
	if (form.is_open())
	{
		int i = 0;
		while (!form.eof())
		{
			form >> Room[i];
			i++;
		}
		form.close();
		if (i < 2)
			assign();

	}
	else
		cout << "Unable to open file.\n";
}

void assign()
{
	ofstream list;
	list.open("Room.txt");
	for (int n = 0; n < 10; n++)
	{
		Room[n] = { 0 };
		list << Room[n] << endl;
	}
	list.close();
}
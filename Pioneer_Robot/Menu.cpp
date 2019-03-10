#include "Menu.h"



Menu::Menu()
{
	this->position = new Position();
	this->sensor = new SonarSensor();
	this->robotInterface = new PioneerRobotInterface(this->sensor,this->position);
	this->robotControl = new RobotControl(robotInterface, this->position, this->sensor);
	this->connectionStatus = false;
	mainMenu();
}

int  Menu::controlInput(int menuRange,string input)
{
	if(menuRange < 10)
	{
		if (input.length() > 1)
		{
			return 0;
		}
		else if (isdigit(input.at(0)))
		{
			int choice = atoi(input.c_str());
			if (choice > 0 && choice <= menuRange)
			{
				return choice;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		int choice;
		try
		{
			choice = atoi(input.c_str());
		}
		catch (const std::exception&)
		{
			return 0;
		}
		return choice;
	}
	return 0;
}

void Menu::mainMenu()
{
	while (true)
	{
		string input;
		cout << "Main Menu" << endl;
		cout << "1. Connection" << endl;
		cout << "2. Motion" << endl;
		cout << "3. Sensor" << endl;
		cout << "4. Quit" << endl;
		cout << "Choose one : ";
		cin >> input;
		int choice = controlInput(4, input);
		switch (choice)
		{
		case 1:
			system("cls");
			cout << " Main Menu -> ";
			connectionMenu();
			break;
		case 2:
			system("cls");
			cout << "Main Menu -> ";
			motionMenu();
			break;
		case 3:
			system("cls");
			cout << "Main Menu -> ";
			sensorMenu();
			break;
		case 4:
			cout << "Quitting the program " << endl;
			Sleep(200);
			return;
		default:
			cout << "Please enter input between 1 and 4" << endl;
			system("cls");
			break;
		}
	}
}
//Tamamlandý
void Menu::connectionMenu()
{
	while (true)
	{
		string input;
		cout << "Connection Menu" << endl;
		cout << "1. Connect Robot" << endl;
		cout << "2. Disconnect Robot" << endl;
		cout << "3. Back" << endl;
		cout << "Choose one : ";
		cin >> input;
		int choice = controlInput(3, input);
		switch (choice)
		{
		case 1:

			if (!connectionStatus)
			{
				if (!robotInterface->open()) {
					cout << "Could not connect..." << endl;
					cout << "Please open mobile sim if mobile sim opened that means unknown error" << endl;
					Sleep(200);
					system("cls");
					return;
				}
				else
				{
					cout << "Robot Connection Established" << endl;
					Sleep(200);
					system("cls");
					connectionStatus = true;
				}
			}
			else
			{
				cout << "Robot Connection Already Established" << endl;
				Sleep(200);
				system("cls");
			}
			break;
		case 2:
			if (connectionStatus)
			{
				if (!robotInterface->close())
				{
					cout << "Robot connection could not closed.Seems have Mobile Sim has a problem" << endl;
					Sleep(200);
					system("cls");
				}
				else
				{
					cout << "Robot connection closed" << endl;
					connectionStatus = false;
					Sleep(200);
					system("cls");
				}
			}
			else
			{
				cout << "Robot connection already closed" << endl;
				Sleep(200);
				system("cls");
			}
			break;
		case 3:
			system("cls");
			return;
		default:
			cout << "Please enter input between 1 and 3" << endl;
			Sleep(200);
			system("cls");
			break;
		}
	}
}

void Menu::motionMenu()
{
	while (true)
	{
		if (connectionStatus)
		{
			string input;
			cout << "Motion Menu" << endl;
			cout << "1. Move Robot" << endl;
			cout << "2. Safe Move Robot" << endl;
			cout << "3. Turn Left" << endl;
			cout << "4. Turn Right" << endl;
			cout << "5. Forward" << endl;
			cout << "6. Move Distance" << endl;
			cout << "7. Close Wall" << endl;
			cout << "8. Stop Robot" << endl;
			cout << "9. Print Data" << endl;
			cout << "10. Back" << endl;
			cout << "Choose one : ";
			cin >> input;
			int choice = controlInput(10, input);
			float speedFloat = 0;
			int speedInteger = 0;
			float distance = 0;
			switch (choice)
			{
			case 1:
				//Move Menu ask Speed
				speedFloat = askSpeed();
				if ((int)speedFloat == 0)
				{
					cout << "You have entered wrong input don't enter 0 or char value" << endl;
					system("cls");
					Sleep(1000);
				}
				else
				{
					robotInterface->move(speedFloat);
					system("cls");
				}
				break;
			case 2:
				speedInteger = askSafeMoveSpeed();
				if (speedInteger == 0)
				{
					cout << "You have entered wrong input don't enter 0 or char value" << endl;
					Sleep(1000);
					system("cls");
				}
				else
				{
					robotControl->safeMove(speedInteger);
					system("cls");
				}
				break;
			case 3:
				robotControl->turnLeft();
				cout << "Turning Left" << endl;
				Sleep(1000);
				system("cls");
				break;
			case 4:
				robotControl->turnRight();
				cout << "Turning Right" << endl;
				Sleep(1000);
				system("cls");
				break;
			case 5:
				robotControl->forward();
				cout << "Moving Forward" << endl;
				Sleep(1000);
				system("cls");
				break;
			case 6:
				distance = askDistance();
				if ((int)distance == 0)
				{
					cout << "You have entered wrong input don't enter 0 or char value" << endl;
					system("cls");
					Sleep(1000);
				}
				else
				{
					robotControl->moveDistance(distance);
					cout << "Distance moved" << endl;
					system("cls");
					Sleep(1000);
				}
				break;
			case 7:
				robotControl->closeWall();
				cout << "Closing front wall completed succesfully" << endl;
				Sleep(1000);
				system("cls");
				break;
			case 8:
				robotInterface->stop();
				cout << "Robot stopped" << endl;
				Sleep(1000);
				system("cls");
				break;
			case 9:
				robotControl->print();
				Sleep(2000);
				system("cls");
				break;
			case 10:
				system("cls");
				return;
			default:
				cout << "Please enter input between 1 and 10" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
		}
		else
		{
			system("cls");
			cout << "Robot connection closed please open connection first" << endl;
			Sleep(1000);
			system("cls");
			return;
		}
	}
}

void Menu::sensorMenu()
{
	if (connectionStatus)
	{
		while (true)
		{
			string input;
			cout << "Sensor Menu" << endl;
			cout << "1. Get Type" << endl;
			cout << "2. Set Type" << endl;
			cout << "3. Get Min" << endl;
			cout << "4. Get Max" << endl;
			cout << "5. Back" << endl;
			cout << "Choose : ";
			cin >> input;
			string type;
			int choice = controlInput(5, input);
			switch (choice)
			{
			case 1:
				cout << sensor->getType() << endl;
				Sleep(1000);
				system("cls");
				break;
			case 2:
				cout << "Please enter type of sensor" << endl;
				cin >> type;
				sensor->setType(type);
				cout << "Sensor type changed" << endl;
				Sleep(1000);
				system("cls");
				break;
			case 3:
				cout << sensor->getMin() << endl;
				Sleep(1000);
				system("cls");
				break;
			case 4:
				cout << sensor->getMax() << endl;
				Sleep(1000);
				system("cls");
				break;
			case 5:
				system("cls");
				return;
			default:
				cout << "Please enter input between 1 and 5" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
		}
	}
	else
	{
		system("cls");
		cout << "Robot connection closed please open connection first" << endl;
		Sleep(1000);
		system("cls");
		return;
	}
}

float Menu::askDistance()
{
	string input;
	float distance;
	cout << "Enter distance :" << endl;
	cin >> input;
	distance = controlFloat(input);
	return distance;
}

int Menu::askSafeMoveSpeed()
{
	string input;
	int speed;
	cout << "Enter speed :" << endl;
	cin >> input;
	speed = controlInteger(input);
	return speed;
}

float Menu::askSpeed()
{
	string input;
	float speed;
	cout << "Enter speed :" << endl;
	cin >> input;
	speed = controlFloat(input);
	return speed;
}

float Menu::controlFloat(string input)
{
	float data;
	try
	{
		 data = stof(input);
	}
	catch (const std::exception&)
	{
		return 0;
	}
	return data;
}

int Menu::controlInteger(string input)
{
	int data;
	try
	{
		data = stoi(input);
	}
	catch (const std::exception&)
	{
		return 0;
	}
	return data;
}




Menu::~Menu()
{
}

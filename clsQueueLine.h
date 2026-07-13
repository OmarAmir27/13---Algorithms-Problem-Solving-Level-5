#pragma once
#include <iostream>
#include <queue>
#include <iomanip>
#include"clsDate.h"
using namespace std;

class clsQueueLine
{
private:
	string _Prefix = "";
	int _TotalTickets = 0;
	short _AverageServeTime = 0;

	class clsTicket
	{
	private:
		short  _Number = 0;
		string _Prefix = "";
		string _TicketTime = "";
		short  _WaitingClients = 0;
		short  _AverageServeTime = 0;
		short  _ExpectedServeTime = 0;

	public:
		clsTicket(string Prefix, short Number ,short WaitingClients ,short AverageServeTime)
		{
			_Prefix = Prefix;
			_Number = Number;
			_TicketTime = clsDate::GetDateAndTime();
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
			_ExpectedServeTime = AverageServeTime * WaitingClients;
		}

		string Prefix()
		{
			return _Prefix;
		}

		short Number()
		{
			return _Number;
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		short WaitingClients()
		{
			return _WaitingClients;
		}

		short AverageServeTime()
		{
			return _AverageServeTime;
		}
		
		short ExpectedServeTime()
		{
			return _ExpectedServeTime;
		}

		string FullNumber()
		{
			return _Prefix + to_string(_Number);
		}

		void PrintTicket()
		{
			cout << "\t\t\t\t\t-------------------------------------------\n";
			cout << "\t\t\t\t\t\t\t      " << FullNumber() << "\n";
			cout << "\t\t\t\t\t\t" << _TicketTime << "\n";
			cout << "\t\t\t\t\t\tWaiting Clients : " << _WaitingClients << "\n";
			cout << "\t\t\t\t\t\tServed Time In \n";
			cout << "\t\t\t\t\t\t" << _ExpectedServeTime << " Minutes.\n";
			cout << "\t\t\t\t\t-------------------------------------------\n\n";
		}
	};

public:
	queue<clsTicket> QueueLine;

	clsQueueLine(string Prefix, short AverageServeTime)
	{
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
	}

	int WaitingClients()
	{
		return QueueLine.size();
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;

		QueueLine.pop();
		return true;
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
			return "No Clients Left.";
		else
			return QueueLine.front().FullNumber();
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
		QueueLine.push(Ticket);

	}

	void PrintTicketsLineQueueRTL()
	{
		if (QueueLine.empty())
			cout << "\n\nNo Client NOW ...! \n\n";
		cout << "Tickets : ";

		queue<clsTicket> TempQueueLine = QueueLine;

		while (!TempQueueLine.empty())
		{
			cout << TempQueueLine.front().FullNumber() << " <-- ";
			TempQueueLine.pop();
		}
		cout << "\n\n";
	}

	void PrintTicketsLineQueueLTR()
	{
		if (QueueLine.empty())
			cout << "\n\nNo Client NOW ...! \n\n";
		cout << "Tickets : ";

		queue<clsTicket> TempQueueLine = QueueLine;
		stack<clsTicket> TempStack;

		while (!TempQueueLine.empty())
		{
			TempStack.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStack.empty())
		{
			cout << TempStack.top().FullNumber() << " --> ";
			TempStack.pop();
		}


		cout << "\n\n";
	}

	void PrintInfo()
	{
		cout << "\t\t\t\t\t-------------------------------------------\n";
		cout << "\t\t\t\t\t\t\tQueue Info \n";
		cout << "\t\t\t\t\t-------------------------------------------\n";
		cout << "\t\t\t\t\t    Prefix          : " << _Prefix << "\n";
		cout << "\t\t\t\t\t    Total Tickets   : " << _TotalTickets << "\n";
		cout << "\t\t\t\t\t    Served Clients  : " << ServedClients() << "\n";
		cout << "\t\t\t\t\t    Waiting Clients : " << WaitingClients() << "\n";
		cout << "\t\t\t\t\t-------------------------------------------\n";
	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t\t\t\t\t--- Tickets --- \n";

		if (QueueLine.empty())
			cout << "\n\nNo Tickets At NOW ...! \n\n";

		queue<clsTicket> TempQueueLine = QueueLine;

		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().PrintTicket();
			TempQueueLine.pop();
		}
		cout << "\n\n";
	}
};
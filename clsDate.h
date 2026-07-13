
#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip> 
#include "clsString.h";

using namespace std;

class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;
public:


	clsDate()
	{
		*this = GetSystemDate();
	}

	clsDate(string DateFormat)
	{
		*this = StringToDate(DateFormat);
	}

	clsDate(short Day, short Month, short Year)
	{
		this->_Day = Day;
		this->_Month = Month;
		this->_Year = Year;
	}

	clsDate(short DayOrderInYear, short Year)
	{
		*this = GetDateFromDayOrderInAYear(DayOrderInYear, Year);
	}

	short GetDay()
	{
		return _Day;
	}
	void SetDay(short Day)
	{
		_Day = Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	short GetMonth()
	{
		return _Month;
	}
	void SetMonth(short Month)
	{
		_Month = Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	short GetYear()
	{
		return _Year;
	}
	void SetYear(short Year)
	{
		_Year = Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;



	clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		this->_Year = now->tm_year + 1900;
		this->_Month = now->tm_mon + 1;
		this->_Day = now->tm_mday;

		return *this;
	}

	static string GetSystemTime()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		return to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
	}

	static string GetDateAndTime()
	{
		return clsDate::FormatDate(clsDate(), "dd/mm/yyyy") + " - " + clsDate::GetSystemTime();
	}
	static enum class enLeapYearOrNot { NotLeap = 0, Leap = 1 };

	static enum class enDaysOfWeek { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

	static enum class enMonthsOfYear { January = 1, February, March, April, May, June, July, August, September, October, November, December };

	void Print()
	{
		cout << DateToString() << "\n";
	}

	// =================================================== From Course 8 Problem Solving and Algorithm. ===================================================

	static string DayName(enDaysOfWeek DayOfWeek)
	{
		switch (DayOfWeek)
		{
		case enDaysOfWeek::Sunday:
			return "Sunday";

		case enDaysOfWeek::Monday:
			return "Monday";

		case enDaysOfWeek::Tuesday:
			return "Tuesday";

		case enDaysOfWeek::Wednesday:
			return "Wednesday";

		case enDaysOfWeek::Thursday:
			return "Thursday";

		case enDaysOfWeek::Friday:
			return "Friday";

		case enDaysOfWeek::Saturday:
			return "Saturday";

		default:
			return "Sunday";
		}
	}

	static string DayName(short DayOrder)
	{
		string DaysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		return DaysOfWeek[DayOrder];
	}

	static string MonthName(enMonthsOfYear MonthsOfYear)
	{
		switch (MonthsOfYear)
		{
		case enMonthsOfYear::January:
			return "Sunday";
		case enMonthsOfYear::February:
			return "February";
		case enMonthsOfYear::March:
			return "March";
		case enMonthsOfYear::April:
			return "April";
		case enMonthsOfYear::May:
			return "May";
		case enMonthsOfYear::June:
			return "June";
		case enMonthsOfYear::July:
			return "July";
		case enMonthsOfYear::August:
			return "August";
		case enMonthsOfYear::September:
			return "September";
		case enMonthsOfYear::October:
			return "October";
		case enMonthsOfYear::November:
			return "November";
		case enMonthsOfYear::December:
			return "December";

		default:
			return "January";
		}
	}

	static string MonthName(short Month)
	{
		string MonthsOfYear[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		return MonthsOfYear[Month - 1];
	}

	static enLeapYearOrNot CheckIsLeapYear(short Year)
	{
		if (Year % 400 == 0)
			return enLeapYearOrNot::Leap;

		if (Year % 4 == 0 && Year % 100 != 0)
			return enLeapYearOrNot::Leap;

		return enLeapYearOrNot::NotLeap;
	}

	static clsDate StringToDate(string DateInString)
	{
		clsDate Date;

		vector<string> vDate = clsString::Split(DateInString, "/");
		Date._Day = stoi(vDate[0]);
		Date._Month = stoi(vDate[1]);
		Date._Year = stoi(vDate[2]);

		return Date;
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}
	// **************************************************************************************************

	static short DaysInAYear(short Year)
	{
		return (CheckIsLeapYear(Year) == enLeapYearOrNot::Leap) ? 366 : 365;
	}

	static short DayOfWeekOrder(short Year, short Month, short Day)
	{
		short a = (14 - Month) / 12;
		short y = Year - a;
		short m = Month + 12 * a - 2;
		short d = (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

		return d;
	}

	static short DayOfWeekOrder(const clsDate& Date)
	{
		return DayOfWeekOrder(Date._Year, Date._Month, Date._Day);
	}

	static short DaysInMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12)
			return 0;

		short DaysOfMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? ((CheckIsLeapYear(Year) == enLeapYearOrNot::Leap) ? 29 : 28) : DaysOfMonth[Month - 1];
	}

	static void PrintMonthCalender_AnotherSolution(short Year, short Month)
	{
		cout << "__________________________________________________" << MonthName(Month) << "__________________________________________________\n";

		cout << right << setw(10) << "Sun";
		cout << right << setw(10) << "Mon";
		cout << right << setw(10) << "Tue";
		cout << right << setw(10) << "Wed";
		cout << right << setw(10) << "Thu";
		cout << right << setw(10) << "Fri";
		cout << right << setw(10) << "       Sat\n";

		short OrderOfTheDay = DayOfWeekOrder(Year, Month, 1);
		short DaysOfMonth = DaysInMonth(Year, Month);

		cout << right << setw(OrderOfTheDay * 10) << "";

		for (short i = 1; i <= DaysOfMonth; i++)
		{
			cout << right << setw(10) << i;
			if (DayName(DayOfWeekOrder(Year, Month, i)) == "Saturday")
			{
				cout << "\n";
			}
		}
		cout << "\n______________________________________________________________________________________________________________\n\n";
	}
	static void PrintMonthCalendar(short Year, short Month)
	{
		printf("__________________________________________________%s__________________________________________________\n", MonthName(Month).c_str());

		printf("       Sun       Mon       Tue       Wed       Thu       Fri       Sat       \n");

		short OrderOfTheDay = DayOfWeekOrder(Year, Month, 1);
		short DaysOfMonth = DaysInMonth(Year, Month);

		int i;
		for (i = 0; i < OrderOfTheDay; i++)
			printf("          ");
		for (int j = 1; j <= DaysOfMonth; j++)
		{
			printf("%10d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		cout << "\n______________________________________________________________________________________________________________\n\n";
	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(this->_Year, this->_Month);
	}

	static void PrintYearCalendar(short Year)
	{
		printf("\n\n\t\t\t  -----------------------------------------------------------------\n");
		printf("\t\t\t\t\t\t Calendar - %d \n", Year);
		printf("\t\t\t  -----------------------------------------------------------------\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(Year, i);
		}
	}
	void PrintYearCalendar()
	{
		PrintYearCalendar(this->_Year);
	}

	static short NumberOfDaysFromTheBeginingOftheYear(short Year, short Month, short Day)
	{
		short TotalDays = 0;
		for (short i = 1; i < Month; i++)
		{
			TotalDays += DaysInMonth(Year, i);
		}
		TotalDays += Day;
		return TotalDays;
	}
	short NumberOfDaysFromTheBeginingOftheYear()
	{
		return NumberOfDaysFromTheBeginingOftheYear(this->_Year, this->_Month, this->_Day);
	}

	static string GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
	{
		short Flag = DayOrderInYear;
		for (short i = 1; i <= 12; i++)
		{
			short Days = DaysInMonth(Year, i);
			Flag -= Days;
			if (Flag < 0)
			{
				Flag += Days;
				return to_string(Flag) + "/" + to_string(i) + "/" + to_string(Year);
			}
		}
		return "";
	}
	string GetDateFromDayOrderInYear(short DayOrderInYear)
	{
		return GetDateFromDayOrderInYear(DayOrderInYear, this->_Year);
	}

	static clsDate GetDateFromDayOrderInAYear_AnotherSolution(short DayOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DayOrderInYear;
		Date._Year = Year;
		short DaysInAMonth = 0;
		for (short i = 1; i <= 12; i++)
		{
			DaysInAMonth = DaysInMonth(Year, i);
			RemainingDays -= DaysInAMonth;
			if (RemainingDays < 0)
			{
				RemainingDays += DaysInAMonth;
				Date._Day = RemainingDays;
				Date._Month = i;
				return Date;
			}
		}
		return Date;
	}
	clsDate GetDateFromDayOrderInAYear_AnotherSolution(short DayOrderInYear)
	{
		return GetDateFromDayOrderInAYear_AnotherSolution(DayOrderInYear, this->_Year);
	}

	static clsDate GetDateFromDayOrderInAYear(short DayOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DayOrderInYear;
		Date._Year = Year;
		Date._Month = 1;
		short MonthDays = 0;

		while (true)
		{
			MonthDays = DaysInMonth(Year, Date._Month);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}

		return Date;
	}
	clsDate GetDateFromDayOrderInAYear(short DayOrderInYear)
	{
		return GetDateFromDayOrderInAYear(DayOrderInYear, this->_Year);
	}

	static clsDate DateAddDays(short DaysAdded, clsDate Date) // 120
	{
		short RemainingDays = DaysAdded + NumberOfDaysFromTheBeginingOftheYear(Date._Year, Date._Month, Date._Day);
		Date._Month = 1;

		while (true)
		{
			short MonthDays = DaysInMonth(Date._Year, Date._Month);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}

		return Date;
	}
	clsDate DateAddDays(short DaysAdded)
	{
		return DateAddDays(DaysAdded, *this);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		if (Date1._Year < Date2._Year)
			return true;
		else if (Date1._Year == Date2._Year)
		{
			(NumberOfDaysFromTheBeginingOftheYear(Date1._Year, Date1._Month, Date1._Day) < NumberOfDaysFromTheBeginingOftheYear(Date2._Year, Date2._Month, Date2._Day)) ? true : false;
		}
		else
			return false;
	}
	bool IsDate1BeforeDate2(clsDate Date2) {
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1BeforeDate2_AnotherSolution(const clsDate& Date1, const clsDate& Date2)
	{
		return (Date1._Year < Date2._Year) ? true : (Date1._Year == Date2._Year ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}
	bool IsDateBeforeDate2_AnotherSolution(const clsDate& Date2)
	{
		return IsDate1BeforeDate2_AnotherSolution(*this, Date2);
	}

	static bool IsDate1BeforeDate2_AnotherSolution1(const clsDate& Date1, const clsDate& Date2)
	{
		if (Date1._Year < Date2._Year)
			return true;

		else if (Date1._Year == Date2._Year)
		{
			if (Date1._Month < Date2._Month)
				return true;
			else if (Date1._Month == Date2._Month)
			{
				if (Date1._Day < Date2._Day)
					return true;
				else
					return false;
			}
			else
				return false;
		}

		else
			return false;
	}
	bool IsDateBeforeDate2_AnotherSolution1(const clsDate& Date2)
	{
		return IsDate1BeforeDate2_AnotherSolution1(*this, Date2);
	}

	static bool IsDate1EqualDate2(const clsDate& Date1, const clsDate& Date2)
	{
		return (Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day == Date2._Day) ? true : false;
	}
	bool IsDateEqualDate2(const clsDate& Date2) {
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2_AnotherSolution2(const clsDate& Date1, const clsDate& Date2)
	{
		if (Date1._Year != Date2._Year)
			return false;
		else if (Date1._Month != Date2._Month)
			return false;
		else if (Date1._Day != Date2._Day)
			return false;
		else
			return true;
	}
	bool IsDateEqualDate2_AnotherSolution2(const clsDate& Date2)
	{
		return IsDate1EqualDate2_AnotherSolution2(*this, Date2);
	}

	static bool IsDate1EqualDate2_AnotherSolution3(const clsDate& Date1, const clsDate& Date2)
	{
		return (Date1._Year != Date2._Year) ? false : (Date1._Month != Date2._Month ? false : (Date1._Day != Date2._Day ? false : true));
	}
	bool IsDateEqualDate2_AnotherSolution3(const clsDate& Date2)
	{
		return IsDate1EqualDate2_AnotherSolution3(*this, Date2);
	}

	static bool IsLastDayInMonth(const clsDate& Date1)
	{
		return (DaysInMonth(Date1._Year, Date1._Month) == Date1._Day);
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(const short& Month)
	{
		return (Month == 12);
	}

	static clsDate IncreaseDateByOneDay(const clsDate& Date1)
	{
		clsDate NewDate = Date1;

		if (IsLastDayInMonth(Date1))
		{
			if (IsLastMonthInYear(Date1._Month))
			{
				NewDate._Year++;
				NewDate._Month = 1;
			}
			else
			{
				NewDate._Month++;
			}
			NewDate._Day = 1;
		}
		else
			NewDate._Day++;

		return NewDate;

	}
	clsDate IncreaseDateByOneDay()
	{
		return IncreaseDateByOneDay(*this);
	}

	static clsDate IncreaseDateByOneDay_AnotherSolution(const clsDate& Date1)
	{
		clsDate NewDate = Date1;

		if (IsLastDayInMonth(Date1))
		{
			if (IsLastMonthInYear(Date1._Month))
			{
				NewDate._Year++;
				NewDate._Month = 1;
			}
			else
			{
				NewDate._Month++;
			}
			NewDate._Day = 1;
		}
		else
			NewDate._Day++;

		return NewDate;

	}
	clsDate IncreaseDateByOneDay_AnotherSolution()
	{
		return IncreaseDateByOneDay_AnotherSolution(*this);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDate = false)
	{
		short Date1_DaysFromBeginingAYear = NumberOfDaysFromTheBeginingOftheYear(Date1._Year, Date1._Month, Date1._Day);

		short Date2_DaysFromBeginingAYear = NumberOfDaysFromTheBeginingOftheYear(Date2._Year, Date2._Month, Date2._Day);

		short Diff = 0;

		if (IsDate1BeforeDate2(Date1, Date2))
		{
			if (IncludeEndDate)
			{
				if (Date1._Year == Date2._Year)
					return Date2_DaysFromBeginingAYear - Date1_DaysFromBeginingAYear + 1;
				else if (Date1._Year < Date2._Year)
				{
					Diff = (DaysInAYear(Date1._Year) - Date1_DaysFromBeginingAYear);

					for (short i = Date1._Year + 1; i < Date2._Year; i++)
					{
						Diff += DaysInAYear(i);
					}
					Diff += Date2_DaysFromBeginingAYear;
					return Diff + 1;
				}
			}
			else
			{
				if (Date1._Year == Date2._Year)
					return Date2_DaysFromBeginingAYear - Date1_DaysFromBeginingAYear;
				else if (Date1._Year < Date2._Year)
				{
					Diff = (DaysInAYear(Date1._Year) - Date1_DaysFromBeginingAYear);

					for (short i = Date1._Year + 1; i < Date2._Year; i++)
					{
						Diff += DaysInAYear(i);
					}
					Diff += Date2_DaysFromBeginingAYear;
					return Diff;
				}
			}
		}
		else
			return 0;
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDate = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDate);
	}

	static int GetDifferenceInDays_AnotherSolution(clsDate Date1, clsDate Date2, bool IncludeEndDate = false)
	{
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDate ? ++Days : Days;
	}
	int GetDifferenceInDays_AnotherSolution(clsDate Date2, bool IncludeEndDate = false)
	{

		return GetDifferenceInDays_AnotherSolution(*this, Date2, IncludeEndDate);
	}

	static clsDate IncreaseDateByXDays(short Days, clsDate Date)
	{
		for (short Counter = 1; Counter <= Days; Counter++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDays(short Days)
	{
		IncreaseDateByXDays(Days, *this);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		return IncreaseDateByXDays(7, Date);
	}
	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short Counter = 1; Counter <= Weeks; Counter++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		if (IsLastMonthInYear(Date._Month))
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
			Date._Month++;


		short DaysInCurrentMonth = DaysInMonth(Date._Year, Date._Month);
		if (Date._Day > DaysInCurrentMonth)
		{
			Date._Day = DaysInCurrentMonth;
		}

		return Date;
	}
	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short Counter = 1; Counter <= Months; Counter++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date._Year++;
		short DaysInCurrentMonth = DaysInMonth(Date._Year, Date._Month);
		if (Date._Day > DaysInCurrentMonth)
			Date._Day = DaysInCurrentMonth;

		return Date;
	}
	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate Date)
	{
		for (short Counter = 1; Counter <= Years; Counter++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years, *this);
	}

	static clsDate IncreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		Date._Year += Years;
		return Date;
	}
	void IncreaseDateByXYearsFaster(short Years)
	{
		IncreaseDateByXYearsFaster(Years, *this);
	}

	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{
		Date._Year += 10;
		return Date;
	}
	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short Decades, clsDate Date)
	{
		for (short Counter = 1; Counter <= Decades * 10; Counter++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXDecades(short Decades)
	{
		IncreaseDateByXDecades(Decades, *this);
	}

	static clsDate IncreaseDateByXDecadesFaster(short Decades, clsDate Date)
	{
		Date._Year += Decades * 10;
		return Date;
	}
	void IncreaseDateByXDecadesFaster(short Decades)
	{
		IncreaseDateByXDecadesFaster(Decades, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		Date._Year += 100;
		return Date;
	}
	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennuim(clsDate Date)
	{
		Date._Year += 1000;
		return Date;
	}
	void IncreaseDateByOneMillennuim()
	{
		IncreaseDateByOneMillennuim(*this);
	}

	static bool IsFirstDayInMonth(const clsDate& Date)
	{
		return Date._Day == 1;
	}

	static bool IsFirstMonthInYear(const short& Month)
	{
		return Month == 1;
	}

	static clsDate DecreaseDateByOneDay(const clsDate& Date1)
	{
		clsDate NewDate = Date1;

		if (IsFirstDayInMonth(Date1))
		{
			if (IsFirstMonthInYear(Date1._Month))
			{
				NewDate._Year--;
				NewDate._Month = 12;
			}
			else
			{
				NewDate._Month--;
			}
			NewDate._Day = DaysInMonth(NewDate._Year, NewDate._Month);
		}
		else
			NewDate._Day--;

		return NewDate;

	}
	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate Date)
	{
		for (short Counter = Days; Counter >= 1; Counter--)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		return DecreaseDateByXDays(7, Date);
	}
	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);

	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short Counter = Weeks; Counter >= 1; Counter--)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		if (IsFirstMonthInYear(Date._Month))
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
			Date._Month--;


		short DaysInCurrentMonth = DaysInMonth(Date._Year, Date._Month);
		if (Date._Day > DaysInCurrentMonth)
			Date._Day = DaysInCurrentMonth;


		return Date;
	}
	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short Counter = Months; Counter >= 1; Counter--)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths(Months, *this);

	}

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date._Year--;
		short DaysInCurrentMonth = DaysInMonth(Date._Year, Date._Month);
		if (Date._Day > DaysInCurrentMonth)
			Date._Day = DaysInCurrentMonth;

		return Date;
	}
	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);

	}

	static clsDate DecreaseDateByXYears(short Years, clsDate Date)
	{
		for (short Counter = Years; Counter >= 1; Counter--)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years, *this);

	}

	static clsDate DecreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		Date._Year -= Years;
		return Date;
	}
	void DecreaseDateByXYearsFaster(short Years)
	{
		DecreaseDateByXYearsFaster(Years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date._Year -= 10;
		return Date;
	}
	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decades, clsDate Date)
	{
		for (short Counter = Decades * 10; Counter >= 1; Counter--)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	}

	static clsDate DecreaseDateByXDecadesFaster(short Decades, clsDate Date)
	{
		Date._Year -= Decades * 10;
		return Date;
	}
	clsDate DecreaseDateByXDecadesFaster(short Decades)
	{
		return DecreaseDateByXDecadesFaster(Decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date._Year -= 100;
		return Date;
	}
	clsDate DecreaseDateByOneCentury()
	{
		return DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennuim(clsDate Date)
	{
		Date._Year -= 1000;
		return Date;
	}
	clsDate DecreaseDateByOneMillennuim()
	{
		return DecreaseDateByOneMillennuim(*this);
	}

	static bool IsEndOfWeek(const clsDate& Date)
	{
		return ((DayOfWeekOrder(Date) + 1) == 7);
	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(const clsDate& Date)
	{
		short DayOrder = DayOfWeekOrder(Date) + 1;
		return (DayOrder == 6 || DayOrder == 7);
	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(const clsDate& Date)
	{
		short DayOrder = DayOfWeekOrder(Date) + 1;
		return (DayOrder != 6 && DayOrder != 7);
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static bool IsBusinessDay_Faster(const clsDate& Date)
	{
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay_Faster()
	{
		return IsBusinessDay_Faster(*this);
	}

	static short DaysUntilTheEndOfWeek(const clsDate& Date)
	{
		return 7 - (DayOfWeekOrder(Date) + 1);
	}
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(const clsDate& Date)
	{
		return DaysInMonth(Date._Year, Date._Month) - Date._Day + 1;
	}
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(const clsDate& Date)
	{
		return DaysInAYear(Date._Year) - NumberOfDaysFromTheBeginingOftheYear(Date._Year, Date._Month, Date._Day) + 1;
	}
	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	static short DaysUntilTheEndOfMonth_AnotherSolution(const clsDate& Date)
	{
		clsDate NewDate;
		NewDate._Day = DaysInMonth(Date._Year, Date._Month);
		NewDate._Month = Date._Month;
		NewDate._Year = Date._Year;
		return GetDifferenceInDays(Date, NewDate, true);
	}
	short DaysUntilTheEndOfMonth_AnotherSolution()
	{
		return DaysUntilTheEndOfMonth_AnotherSolution(*this);
	}

	static short DaysUntilTheEndOfYear_AnotherSolution(const clsDate& Date)
	{
		clsDate NewDate;
		NewDate._Day = 31;
		NewDate._Month = 12;
		NewDate._Year = Date._Year;

		return GetDifferenceInDays(Date, NewDate, true);
	}
	short DaysUntilTheEndOfYear_AnotherSolution()
	{
		return DaysUntilTheEndOfYear_AnotherSolution(*this);
	}

	static short CalculateVactionDays(clsDate& DateFrom, const clsDate& DateTo)
	{
		//short Differnece = GetDifferenceInDays(Date1, Date2, true);

		short VactionDays = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				VactionDays++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return VactionDays;
	}
	short VactionDays(const clsDate& DateTo)
	{
		return CalculateVactionDays(*this, DateTo);
	}

	static clsDate VactionReturn(clsDate DateFrom, short VactionDays)
	{

		for (short Day = 1; Day <= VactionDays; Day++)
		{
			if (IsWeekEnd(DateFrom))
			{
				VactionDays++;
			}
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
	clsDate VactionReturn(short VactionDays)
	{
		return VactionReturn(*this, VactionDays);
	}

	static bool IsDate1AfterDate2(const clsDate& Date1, const clsDate& Date2)
	{
		if (Date1._Year > Date2._Year)
			return true;
		else if (Date1._Year == Date2._Year)
		{
			if (Date1._Month > Date2._Month)
				return true;
			else if (Date1._Month == Date2._Month)
			{
				if (Date1._Day > Date2._Day)
					return true;
			}
		}
		return false;
	}
	bool IsDateAfterDate2(const clsDate& Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2_Faster(const clsDate& Date1, const clsDate& Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDateAfterDate2_Faster(const clsDate& Date2)
	{
		return IsDate1AfterDate2_Faster(*this, Date2);
	}

	static bool IsValidDate(const clsDate& Date)
	{
		if (Date._Month < 1 || Date._Month > 12)
			return false;

		if (Date._Day < 1)
			return false;

		if (Date._Day > DaysInMonth(Date._Year, Date._Month))
			return false;

		return true;
	}
	bool IsValid()
	{
		return IsValidDate(*this);
	}

	enum  enCompareDate { Before = -1, Equal = 0, After = 1 };

	static enCompareDate CompareDates(const clsDate& Date1, const clsDate& Date2)
	{
		return IsDate1BeforeDate2(Date1, Date2) ? enCompareDate::Before : (IsDate1EqualDate2(Date1, Date2) ? enCompareDate::Equal : enCompareDate::After);
	}
	enCompareDate CompareDates(const clsDate& Date2)
	{
		return CompareDates(*this, Date2);
	}

	static string FormatDate(const clsDate& Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormatedString = clsString::ReplaceString(DateFormat, "dd", to_string(Date._Day));
		FormatedString = clsString::ReplaceString(FormatedString, "mm", to_string(Date._Month));
		FormatedString = clsString::ReplaceString(FormatedString, "yyyy", to_string(Date._Year));


		return FormatedString;
	}
	string FormatDate(string DateFormat = "dd/mm/yyyy")
	{
		return FormatDate(*this, DateFormat);
	}

};
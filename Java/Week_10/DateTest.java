//	Ex11

class Date

{

	private int month;

	private int day;

	private int year;



	public Date( int month, int day, int year )

	{

		this.month = checkMonth( month);

		this.year = year;

		this.day = checkDay( day );

	}



	private int checkMonth( int testMonth )

	{

		if ( testMonth >= 1 && testMonth <= 12 )

			return testMonth;

		else

			return 1; // for invalid testMonth

	}



	public void increase()

	{

			day++;

			if ((day > 28) && (month == 2) && (year == 2020))

			{

				System.out.println("2/29/2020");

				day = 1;

				month++;

			}

			if (day > 31 && month == 12 && year == 2020)

			{

				day = 1;

				month = 1;

				year++;

			}

			if (day > 31 && month == 12 && year == 2021)

			{

				day = 1;

				month = 1;

				year++;

			}

			if ((day == 29) && (month == 2) && (year == 2021))

	        {

		        System.out.println("2/28/2021");

				month++;

				day = 1;

			}

			else if (( day == 29) && (month == 2) && (year == 2022))

			{

//				System.out.println("2/28/2022");

				month++;

				day = 1;

			}



			if (day > 30)

			{

				if (month == 4 || month == 6 || month == 9 || month == 11)

				{

					month++;

					day = 1;

				}

			}

			if (day > 31)

			{

				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)

				{

					month++;

					day = 1;

				}

			}

}



private int checkDay( int testDay )

{

	int[] daysPerMonth =

	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };



	if ( testDay > 0 && testDay <= daysPerMonth[ month ] )

		return testDay;

	if ( month==2 && testDay==29 &&

		(year%400 == 0 || (year%4 == 0 && year%100 != 0)) )

		return testDay;

	return 1; // for invalid testDay

}



	public String toString()

	{

		return month + "/" + day + "/" + year;

	}

}

public class DateTest

{

	public static void main( String[] args )

	{

		Date date2 = new Date( 1, 1, 2020 );

		System.out.println( "date2: " + date2 );

		for( int i = 0; i < 800; i++)

		{

			date2.increase();

			System.out.println( date2 );

		}

	}
}

//	Ex10

import java.util.Scanner;



public class AlarmTime {

	private int hour;

	private int minute;

	private boolean active =false;

	private boolean[] repeat = new boolean[7];

	private char[] day = {'일','월','화','수','목','금','토'};

	

 	public AlarmTime() 

	{

		this(0,0,null,false);

	}



 	public AlarmTime(int hour, int minute) 

	{

		this(hour,minute,null,false);

	}

	public AlarmTime(int hour, int minute,boolean[] repeat, boolean active)

	{

		this.hour = hour;

		this.minute = minute;

		this.repeat = repeat;

		this.active = active;

	}



	public boolean isActive()

	{

		if(active == true)

		{

			System.out.println("알람이 켜져있는 상태.");

			return true;	

		}

		else

		{

			System.out.println("알람이 꺼져있는 상태.");

			return false;

		}

	}



	public int getHour() 

	{

		return hour;

	}



	public int getMinute()

	{

		return minute;

	}



	



	public boolean[] getRepeat()

	{		 

		return repeat;

	}



	



	public void setAlarmTime(int hour, int minute, boolean[] repeat, boolean active)

	{

		this.hour = hour;

		this.minute = minute;

		this.repeat = repeat;

		this.active = active;

		if(active == true) 

		{

			if(0<hour && hour<24 && 0<=minute && minute<60)

			{	

				System.out.println("설정 시간은"+getHour()+"시"+getMinute()+"분");

				System.out.printf("반복요일은 ");

				for(int i=0;i<repeat.length;i++)

				{

					if(repeat[i] == true)

						System.out.printf("%c ",day[i]);

				}

				System.out.printf("입니다.");

				System.out.println();

			}

			else {

				System.out.println("시 혹은 분이 잘못 입력됨");	

			}

		}

		else {

			isActive();

		}

	}



	public static void main( String[] args )

	{

		Scanner scanner = new Scanner(System.in);

		boolean[] krepeat = new boolean[7];  

		boolean active;

		boolean t,d;

		int khour;

		int kminute;

		int p=0;

		AlarmTime[] k = new AlarmTime[50];

		do

		{

			p++;

			System.out.printf("알람을 켜시겠습니까?");

			active = scanner.nextBoolean();

			if(active == true)

			{

				System.out.printf("알람 시간과 분을 설정하시오:");

				khour = scanner.nextInt();

				kminute = scanner.nextInt();



				System.out.printf("반복 요일을 설정하시오 :");

				for(int i=0;i<krepeat.length;i++)

				{

					t = scanner.nextBoolean();

						krepeat[i] = t;

				}

				k[p] = new AlarmTime(khour, kminute, krepeat, active);

				k[p].setAlarmTime(khour, kminute, krepeat, active);

			}

			else

			{

				k[p] = new AlarmTime();

				k[p].isActive();

			}

			System.out.println();

			System.out.printf("재가동 ?:");

			d = scanner.nextBoolean();

			System.out.println();

		}while(d == true);

		System.out.printf("프로그램 종료");



	}



}

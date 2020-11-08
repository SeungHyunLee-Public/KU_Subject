//	Ex04_4

import java.util.Scanner;

public class Ex04_4

{

    public static void main( String[] args )

    {

        Scanner sc = new Scanner(System.in);



        int i = sc.nextInt();

        int fiveman = i / 50000;

        int oneman = (i % 50000) / 10000;

        int fivchun = (i % 10000) / 5000;

        int onechun = (i % 5000) / 1000;

        int obaek = (i % 1000) / 500;

        int baek = (i % 500) / 100;

        int ohsip = (i % 100) / 50;

        int ship = (i % 50) / 10;



        System.out.println("Amount : " + i);

        System.out.println("50,000-won banknote : " + fiveman);

        System.out.println("10,000-won banknote : " + oneman);

        System.out.println("5,000-won banknote : " + fivchun);

        System.out.println("1,000-won banknote : " + onechun);

        System.out.println("500-won banknote : " + obaek);

        System.out.println("100-won banknote : " + baek);

        System.out.println("50-won banknote : " + ohsip);

        System.out.println("10-won banknote : " + ship);



    }

}

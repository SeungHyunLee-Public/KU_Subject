//	Ex05_2

import java.util.Scanner;

public class Ex05_2

{

        public static void main(String[] args)

        {

                System.out.print("Enter x1 and y1: ");

                Scanner s=new Scanner(System.in);

                int x1=s.nextInt();

                int y1=s.nextInt();

                System.out.print("\n");



                System.out.print("Enter x2 and y2: ");

                Scanner a = new Scanner (System.in);

                int x2=a.nextInt();

                int y2=a.nextInt();

                System.out.print("\n");

                if ((x1>=100 & x1<=200) && (y1>=100 && y1<=200))

                {

                        System.out.println("overlapped");

                }

                else if((x2>=100 && x2<200) && (y2>=100 && y2<=200))

                {

                        System.out.println("overlapped");

                }

                else if(x1<=100 && x2>=200 && y1<=100 && y2>=200)

                {

                        System.out.println("ovelapped");

                }

                else

                        System.out.println("Not overlapper");

                s.close();

                }

}



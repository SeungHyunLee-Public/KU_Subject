//	Ex06_1

public class Ex06_1

{

        public static void main(String[] args)

        {

                int [] x = {87, 68, 94, 100, 83, 78, 85, 91, 76, 87, 55, 60, 99, 63, 80};

                int max = 0, min = 100, sum = 0;



                for(int i = 0; i < x.length; i++)

                {

                        if (x[i] > max ) max = x[i];

                        if (x[i] < min ) min = x[i];

                        sum += x[i];

                }

        System.out.printf("max=%d, min=%d, sum=%d\n", max, min, sum);

                double m = (double)sum / x.length;



                System.out.println("m=" + m);



                double v = 0.0;

                for (int i = 0; i <x.length; i++)

                        v+= Math.pow(x[i]-m,2);

                v /= x.length;

                System.out.println("v=" + v);



                double sigma = 0.0;

                sigma = Math.sqrt(v);

                System.out.println("sigma= " + (Math.round(sigma * 100)/100.0));

        }

}



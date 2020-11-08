import java.util.Scanner;

public class doublecha
{
	public static void main(String[] args)
	{

		double a,b,c;
		double determinant;
		double root;
		double x1,x2;
	
		Scanner Sc =new Scanner(System.in);
		System.out.printf("a의 값을 작성하시오 : ");
		a=Sc.nextInt();
		System.out.printf("b의 값을 작성하시오 : ");
		b=Sc.nextInt();
		System.out.print("c의 값을 작성하시오 : ");
		c=Sc.nextInt();
		determinant=(b*b)-(4*a*c);
		root = Math.sqrt(determinant);
	
		if(determinant>0)
		{
			x1=(-b+root)/(2*a);
			x2=(-b-root)/(2*a);
			System.out.printf("Answer : %.2f %.2f\n", x1, x2);
		}
	
	
		if(determinant==0)
		{
			x1=(-b+root)/(2*a);
			System.out.printf("Answer : %.2f\n", x1);
		}
		
	
		if(determinant<0)
		{
			System.out.printf("no answer.\n");
		}
	}
}

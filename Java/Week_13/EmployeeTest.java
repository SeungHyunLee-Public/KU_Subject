abstract class Employee
{
	private String name;
	private String id;
	static private int count = 0;

	public Employee(String name, String id)
	{
		this.name = name;
		this.id = id;
		count++;
	}
	public abstract double earnings();
	public String toString()
	{
		return name + "(" + id + ")";
	}
	public static int getCount()
	{
		return count;
	}
}

class SalariedEmployee extends Employee
{
	private double monthlySalary;
	public SalariedEmployee(String name, String id, double salary)
	{
		super(name, id);
		monthlySalary = salary;
	}
	public double earnings()
	{
		return monthlySalary;
	}
//	@onverride
	public String toString()
	{
		return super.toString() + "\n" + "monthly salary: " + monthlySalary;
	}
}

class HourlyEmployee extends Employee
{
	private double wage;
	private double hours;
	public HourlyEmployee(String name, String id, double wage, double hours)
	{
		super(name, id);
		this.wage = wage;
		this.hours = hours;
	}
	public double earnings()
	{
		return wage * hours;
	}
	public String toString()
	{
		return super.toString() + "\n" + "wage: " + wage + "\n" + "hours: " + hours;
	}
}

class CommissionEmployee extends Employee
{
	private double grossSales;
	private double commissionRate;
	public CommissionEmployee(String name, String id, double sales, double rate)
	{
		super(name, id);
		grossSales = sales;
		commissionRate = rate;
	}
	public double earnings()
	{
		return commissionRate * grossSales;
	}
	public String toString()
	{
        return super.toString() + "\n" + "gross sales: " + grossSales + "\n" + "commission rate: " + commissionRate;

	}
}

class BasePlusCommissionEmployee extends CommissionEmployee
{
	private double baseSalary;
	public BasePlusCommissionEmployee(String name, String id, double sales, double rate, double salary)
	{
		super(name, id, sales, rate);
		baseSalary = salary;
	}
	public double earnings()
	{
		return baseSalary + super.earnings();
	}
	public String toString()
	{
        return super.toString() + "\n" + "base salary: " + baseSalary;
	}
}

public class EmployeeTest
{
	public static void main(String[] args)
	{
		Employee[] arr = new Employee[4];
		arr[0] = new SalariedEmployee("Smith", "s1111", 300);
		arr[1] = new HourlyEmployee("Karen", "h2222", 1, 160);
		arr[2] = new CommissionEmployee("Jones", "c3333", 2000, 0.1);
		arr[3] = new BasePlusCommissionEmployee("Lewis", "b4444", 2000, 0.06, 100);
		double sum = 0.0;
		for( Employee e : arr )
		{
			System.out.println( e );
			System.out.println( "payment: " + e.earnings() );
			System.out.println();
			sum += e.earnings();
		}
		System.out.println("Total employees: " + Employee.getCount() );
		System.out.println("Total payment: " + sum );
	}
}

class Convertible
{
	String color;
	int speed;
	public Convertible(String color)
	{
		this.color = color;
		speed = 0;
	}
	public void engineStart()
	{
		System.out.println("engine start");
	}
	public void engineStop()
	{
		System.out.println("engine stop");
	}
	public void speedUp()
	{
		speed++;
		System.out.println(
		"speed up(" + speed + ")");
	}
	public void speedDown()
	{
		if (speed > 0)
		speed--;
		System.out.println(
		"speed down(" + speed + ")");
	}
	public void openRoof()
	{
		System.out.println("open roof");
	}
	public void closeRoof()
	{
		System.out.println("close roof");
	}
}

class DumpTruck
{
	String color;
	int speed;
	int cargoSize;
	public DumpTruck(String color,
	int cargoSize)
	{
		this.color = color;
		speed = 0;
		this.cargoSize = cargoSize;
	}
	public void engineStart()
	{
	System.out.println("engine start");
}

	public void engineStop()
	{
		System.out.println("engine stop");
	}
	public void speedUp()
	{
		speed++;
		System.out.println(
		"speed up(" + speed + ")");
	}
	public void speedDown()
	{
		if (speed > 0)
		speed--;
		System.out.println(
		"speed down(" + speed + ")");
	}
	public void dump()
	{
		System.out.println("dump");
	}
}

class FreezerTruck
{
	String color;
	int speed;
	int cargoSize;
	int temperature;
	public FreezerTruck(String color,
	int cargoSize, int temp)
	{
		this.color = color;
		speed = 0;
		this.cargoSize = cargoSize;
		temperature = temp;
	}
	public void engineStart()
	{
		System.out.println("engine start");
	}
	public void engineStop()
	{
		System.out.println("engine stop");
	}
	public void speedUp()
	{
		speed++;
		System.out.println(
		"speed up(" + speed + ")");
	}
	public void speedDown()
	{
		if (speed > 0)
		speed--;
		System.out.println(
		"speed down(" + speed + ")");
	}
	public void setTemperature(int temp)
	{
		temperature = temp;
		System.out.println(
		"set temperature(" + temperature + ")");
	}
}

public class CarExTest
{
	public static void main(String[] args)
	{
		Convertible c = new Convertible("red");
		System.out.println("Convertible: ");
		c.engineStart();
		c.speedUp();
		c.openRoof();
		c.closeRoof();
		c.speedDown();
		c.engineStop();
		System.out.println();
		DumpTruck d = new DumpTruck("blue", 10);
		System.out.println("Dump truck: ");
		d.engineStart();
		d.speedUp();
		d.speedDown();
		d.dump();
		d.engineStop();
		System.out.println();
		FreezerTruck f = new FreezerTruck("blue", 10, 0);
		System.out.println("Freezer truck: ");
		f.engineStart();
		f.setTemperature(-20);
		f.speedUp();
		f.speedDown();
		f.engineStop();
		System.out.println();
	}
}

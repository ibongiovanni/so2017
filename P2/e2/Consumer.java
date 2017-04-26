public class Consumer extends Thread {
	private int n;
	private Buffer b;

	public Consumer(int n, Buffer b){
		this.n=n;
		this.b=b;
	}

	@Override
	public void run(){

	}

	public void consume(){
		Thread.sleep(randomWithRange(1000,5000)); //wait randomly
		b.put();
		System.out.println("i'm consumer n° "+n+", i'd just take something from the buffer");		
	}

	private int randomWithRange(int min, int max)
	{
	   int range = Math.abs(max - min) + 1;     
	   return (int)(Math.random() * range) + (min <= max ? min : max);
	}

}
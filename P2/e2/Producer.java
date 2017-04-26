public class Producer extends Thread {
	private int n;
	private Buffer b;

	public Producer(int n, Buffer b){
		this.n=n;
		this.b=b;
	}

	@Override
	public void run(){

	}

	public void produce(){
		Thread.sleep(3000); //wait 3s
		b.put();
		System.out.println("i'm prod n° "+n+", i'd just put something in the buffer");		
	}

}
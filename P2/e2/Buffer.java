public class Buffer {
	private int MAX = 5; //maximun capacity
	private int c;     //actual capacity

	public Buffer(){
		c=0;
	}

	public synchronized void put(){
		while(c>=MAX) wait(); 
		c++; 
		notify();
	}

	public void take(){
		while(c<=0) wait(); 
		c--; 
		notify();
	}

	public boolean full(){
		return c>MAX;
	}
}
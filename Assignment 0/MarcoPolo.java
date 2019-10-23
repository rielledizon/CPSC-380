"""
 Assignment 0: Marco Polo Program
 Two thread program that loops through 'Marco Polo' 10 times and
 finishes with 'That's all folks.'

 Author: Rielle Dizon
 Email: dizon110@mail.chapman.edu
 Date: 10/02/19

"""
class MarcoPolo extends Thread
{
	public static void main(String args[]) {

		try {
			Marco marco = new Marco();
			marco.start();
			Polo polo = new Polo();
			polo.start();
			marco.join();
			polo.join();
		}
		catch (Exception e) {

		}

		System.out.println("That's all folks");
	}
}
class Marco extends Thread {
    public void run()
    {
        for(int i = 0; i < 10; ++i) {
			System.out.print("Marco ");
			try {
				Thread.sleep(1000);
			}
			catch (Exception e) {

			}
		}
    }
}

class Polo extends Thread {
    public void run()
    {
        for(int i = 0; i < 10; ++i) {
			System.out.print("Polo" + "\n");
			try {
				Thread.sleep(1000);
			}
			catch (Exception e) {

			}
		}
    }
}

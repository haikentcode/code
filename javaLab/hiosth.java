class hios1 implements Runnable{


	Thread t;

	hios1()
	{

		t=new Thread(this,"HIOS1");
		System.out.println("hios 1 start:");
		t.start();
	}


	public void run()
	{



		for(int i=0;i<10;i++)
		{

           try{
			System.out.println("HIOS1->"+i);
			t.sleep(1200);
			}
	     	catch (InterruptedException e) {

                             System.out.println(" interrupted OCure");
                          }
		}

	}
}


class hios2 implements Runnable{


	Thread t;


	hios2()
	{

		t=new Thread(this,"HIOS2");
		System.out.println("hios 2 start:");
		t.start();
	}


	public void run()
	{



		for(int i=10;i<20;i++)
		{
            try
            {
			System.out.println("HIOS2->"+i);

			t.sleep(1000);
			
			 

	     	}
	     	catch (InterruptedException e) {

                             System.out.println(" interrupted OCure");
                          

		}
	}


}

}


class hiosth
{


 
 public static void main(String arg[])
 {

   new hios1();
   new hios2();

 }




}
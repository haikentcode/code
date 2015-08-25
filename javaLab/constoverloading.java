//WAP const overloading




class foo
{
	 foo(){System.out.println("foo is without argument");}	
     foo(int a){System.out.println("foo is with argument ="+a);}

	
}


class constoverloadig
{
  
     
	public static void main(String arg[])
	{
       foo obj=new foo();
       foo obj2=new foo(4);
         
	}
}
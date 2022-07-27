

fun factorial(n:Int):Int{
  return if(n==1) n else n*factorial(n-1)
}


tailrec fun fact(n:Int,run:Int=1):Long{
  return if(n==1) run.toLong() else fact(n-1,run*n)
}


fun print(a:Array<String>){
  for(x in a){
    println(x)
  }
}
fun main(args:Array<String>){

  val n=10
  println(factorial(n))
  val x = arrayOf("haiku","simi")
  print(x)
}

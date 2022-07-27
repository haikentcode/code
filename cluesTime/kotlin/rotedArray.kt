

fun rotedArray(arr:Array<Int>,d:Int,n:Int):Array<Int>{
  val tarr = Array(n,{i->(i*0)})

    for(x in arr.indices){

      if(x+1<=d){
        tarr[n-d+x]=arr[x]
      }else{
        tarr[x-d]=arr[x]
      }
    }
   return tarr
}


fun print(arr:Array<Int>){
  for(x in arr){
    println(x)
  }
}


fun main(args:Array<String>){

   val arraySize = 5

   val arr = Array(5,{i->(i+3)})
   val d = 3
   println("before")
   print(arr)

   println("afete")
   val rarr = rotedArray(arr,d,arraySize)
   print(rarr)
}

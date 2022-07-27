import java.util.Scanner

fun decimalDigitValue(c: Char): Int {
    if (c !in '0'..'9')
        throw IllegalArgumentException("Out of range")
    return c.toInt() - '0'.toInt() // Explicit conversions to numbers
}


fun main(args:Array<String>){

  println(decimalDigitValue('4'))

  val asc = Array(5,{i->(i*i).toString()})

  println(asc[0])


  val x:IntArray = intArrayOf(1,2,3)

  x[0] = x[1] + x[2]

  for (c in "hai"){

    println(c)
  }

  val text = """
    |Tell me and I forget.
     |Teach me and I remember.
    |Involve me and I learn.
     |(Benjamin Franklin)
    """.trimMargin()

    println(text)

    val i = 10

    println("i=$i")


    /* val reader = Scanner(System.`in`)
    print("Enter a number: ")
    var integer:Int = reader.nextInt()
    println("You entered: $integer") */


    val number = -10

    if(number > 0){
      println("Positive number!")
    }else{
      println("Negative numnber!")
    }


    var a = -9
    var b = -11

    val max = if (a > b) {
        println("$a is larger than $b.")
        println("max variable holds value of a.")
        a
      } else {
        println("$b is larger than $a.")
        println("max variable holds value of b.")
        b
      }
    println("max = $max")



    val num = 0

    val result = if (num > 0)
        "positive number"
    else if (num < 0)
        "negative number"
    else
        "zero"

    println("number is $result")



     val n1 = 3
     val n2 = 5
     val n3 = -2

     val maxt = if (n1 > n2) {
        if (n1 > n3) n1
          else n3
        } else {
         if (n2 > n3)
                  n2
        else
              n3
        }

    println("max = $maxt")

     a = 10
     b = 20

    println("Enter operator either +,-,* or /")
    val operator = "*" //readLine()

    when( operator ){
      "+" -> println("$a + $b = ${a + b}")
      "-" -> println("$a - $b = ${a - b}")
      "*" -> println("$a * $b = ${a * b}")
      "/" -> println("$a / $b = ${a / b}")
      else -> println("$operator is invalid")
    }


    val xn = 100

    when(xn){
        in 1..10 -> println("A positive less than 11.")
        in 10..100 -> println("A positive number between 10 and 100 (inclusive)")
      }

    val eleven = 11
    val nn = "11"

    when(nn){
      "cat" -> println("Cat? Really?")
      12.toString() -> println("Close but not close enough.")
      eleven.toString() -> println("Bingo! It's eleven")
    }

    // while loop


    var ith = 1

    while(ith < 10){
      println("ith->$ith")
      ++ith
    }


    for(i in 1..5) println(i)

    val ar = Array(4,{i->(i*i).toString()})

    for(x in ar) println(x)

    var language = arrayOf("Ruby", "Koltin", "Python","Java")

    for(item in language) println(item)

    for(item in language.indices){
      if(item%2 == 0) println(language[item])
    }

}

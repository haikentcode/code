package main
import "fmt"


type Node struct{
      data string;
      next *Node;
}

type LinkList struct{
     length int;
     head *Node;
}

func (l * LinkList) append(newNode *Node){
        if l.length == 0{
		 l.head = newNode
	}
	else{
              cp := f.head
	      for cp.next !=nil {
	                   cp = cp.next
	       }
	       cp.next = newNode
	}
	l.length++
}



func main(){
	  fmt.Print(" hello go ");
	  a :=  Node{data:"hello",}
	  list := LinkList{}
	  list.append(a)
	  b : = Node{data:"hi",}
	  list.append(b)

}

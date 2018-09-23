import java.util.Scanner;

class list
{
    static class node
    {
        int value;
        node next;
        public node(int _value)
        {
            next=null;
            value=_value;
        }
    }

    static node first,last;
    list()
    {
        first=null;
        last=null;
    }

    public static boolean empty()
    {
        if(first==null)
        return true;
        return false;
    }

    public static void append(int value)
    {
        node x=new node(value);
        if(first!=null) last.next=x;
        else first=x; last=x;
    }

    public static void forward()
    {
        node ptr=first;
        while(ptr!=null)
        {
            System.out.print(ptr.value+", ");
            ptr=ptr.next;
        }
    }

    public static void backward()
    {
        node temp,ptr;
        node mark=last;
        while(mark!=first)
        {
            temp=first;
            ptr=temp.next;
            while(ptr!=mark)
            {
                temp=temp.next;
                ptr=temp.next;
            }
            mark=temp;
            System.out.print(ptr.value+", ");
        }
        System.out.print(first.value);
    }

    static Scanner read=new Scanner(System.in);
    public static void main(String[] args)
    {
        int ch,value;
        do
        {
            System.out.print("\n 1. Append ");
            System.out.print("\n 2. Forward ");
            System.out.print("\n 3. Backward ");
            System.out.print("\n 4. End Program ");
            System.out.print("\n\n Enter>>");
            ch=read.nextInt(); switch(ch)
            {
                case 1 :
                System.out.print("\n Enter a value : ");
                value=read.nextInt(); append(value);
                break;

                case 2 :
                System.out.print("\n List is : ");
                if(empty()!=true) forward();
                else System.out.print("empty!");
                break;

                case 3 :
                System.out.print("\n List is : ");
                if(empty()!=true) backward();
                else System.out.print("empty!");
                break;
            }
            System.out.println();
        }while(ch!=4);
    }
}

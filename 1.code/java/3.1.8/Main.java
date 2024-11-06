// static field
public class Main {
    public static void main(String[] args) {
        Person p1 = new Person();
        Person p2 = new Person();
    
        Person p3 = new Person();
        System.out.println("count:" + Person.getCount());
    
    }
}

class Person {
    private static int count = 0;

    public Person() {
        count++;
    }

    public static int getCount() {
        return count;
    }
}
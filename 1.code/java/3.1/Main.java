// 引用类型参数绑定
public class Main {
    public static void main(String[] args) {
        Person ming = new Person();
        ming.setName("xiaoming");
        ming.setAge("12");
        System.out.println(ming.getAge());
        System.out.println(ming.getName());
    }
}

class Person {
    private String name;
    private String age;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(String age) {
        this.age = age;
    }

    public String getAge() {
        return age;
    }


}
import java.util.*;

class Singleton {
    private static final Singleton instance = new Singleton();

    private Singleton() {

    }

    public static Singleton getInstance() {
        return instance; 
    }
}

class Main{
    public static void main(String[] args) {
        Singleton obj1 = Singleton.getInstance();
        System.out.println(obj1);
        Singleton obj2 = Singleton.getInstance();
        System.out.println(obj2);
        if(obj1 == obj2){
            System.out.println("Both instances are the same");
        }else{
            System.out.println("Both instances are different");
        }
    }
}
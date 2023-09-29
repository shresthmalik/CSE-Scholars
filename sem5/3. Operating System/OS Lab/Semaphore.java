class Semaphore{
    int value;
    
    public Semaphore(){
      value = 1;    
    }
    
    public void wait1(){
        while(value<=0);
        
        value--;
    }
    
    public void signal(){
        value++;
    }
}

class SharedSemaphore{
    public static Semaphore s = new Semaphore();
    
}

class Shared{
    static int x=10;
    
    public static void inc(){
        x++;
    }
    
    public static void dec(){
        x--;
    }
}


class Process1 extends Thread{
    Shared s = new Shared();
    SharedSemaphore sema = new SharedSemaphore();    
    
    public void run(){
       sema.s.wait1();    
       Shared.inc();  
       sema.s.signal();
    }
}

class Process2 extends Thread{
    Shared s = new Shared();
    SharedSemaphore sema = new SharedSemaphore();
    
    public void run(){
       sema.s.wait1();    
       Shared.dec(); 
       sema.s.signal();
    }
}


class HelloWorld {
    public static void main(String[] args) {
        Process1 p1 = new Process1();
        Process2 p2 = new Process2();
        Shared s = new Shared();
        
        System.out.println(Shared.x);
        
        p1.start();
        p2.start();
        
        System.out.println(Shared.x);
    }
}
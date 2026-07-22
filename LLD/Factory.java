import java.util.*;

interface Notification{
  void send(String message);
}

class EmailNotification implements Notification{
  public void send(String message){
    System.out.println("Sending email: " + message);
  }
}

class SMSNotification implements Notification{
  public void send(String message){
    System.out.println("Sending SMS: " + message);
  }
}

class NotificationFactory{
  public static Notification create(String type){
    if(type.equals("email")){
      return new EmailNotification();
    }else if(type.equals("sms")){
      return new SMSNotification();
    }
    throw new IllegalArgumentException("Invalid notification type");
  }
}

class Main{
  public static void main(String[] args){
    Notification email = NotificationFactory.create("email");
    email.send("Hello, this is an email notification");
    Notification sms = NotificationFactory.create("sms");
    sms.send("Hello, this is an SMS notification");
  }
}
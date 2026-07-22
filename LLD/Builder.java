import java.util.*;
//builder pattern is a creational design pattern that is used to create complex objects step by step.
//it is used to create a complex object by using a builder class.
//the builder class is used to create the object step by step.
//in real world, we use builder pattern to create complex objects like HttpRequest, Response, etc.
//it is used to create a complex object by using a builder class.
//the builder class is used to create the object step by step.
//in real world, we use builder pattern to create complex objects like HttpRequest, Response, etc.
//it is used to create a complex object by using a builder class.
//the builder class is used to create the object step by step.
//in real world, we use builder pattern to create complex objects like HttpRequest, Response, etc.
//it is used to create a complex object by using a builder class.
class HttpRequest{
  private String url;
  private String method;
  private Map<String, String> headers;
  private String body;

  private HttpRequest(){}

  public static class Builder{
    private HttpRequest request = new HttpRequest();

    public Builder url(String url){
      request.url = url;
      return this;
    }

    public Builder method(String method){
      request.method = method;
      return this;
    }
    
    public Builder header(String key, String value){
      if(request.headers == null){
        request.headers = new HashMap<>();
      }
      request.headers.put(key, value);
      return this;
    }

    public Builder body(String body){
      request.body = body;
      return this;
    }

    public HttpRequest build(){
      return request;
    }
  }

}

class Main{
  public static void main(String[] args){
    HttpRequest request = new HttpRequest.Builder()
      .url("https://www.google.com")
      .method("GET")
      .header("Content-Type", "application/json")
      .body("{\"name\":\"John\", \"age\":30}")
      .build();
   
  }
}
import java.util.*;

interface DataSource {
  void writeData(String data);

  String readData();
}

class FileDataSource implements DataSource {
  private String filename;

  public FileDataSource(String filename) {
    this.filename = filename;
  }

  public void writeData(String data) {
    // Write to file
  }

  public String readData() {
    // Read from file
    return "data from file";
  }
}

class EncryptionDecorator implements DataSource {
  private DataSource wrapped;

  public EncryptionDecorator(DataSource source) {
    this.wrapped = source;
  }

  public void writeData(String data) {
    String encrypted = encrypt(data);
    wrapped.writeData(encrypted); // Delegate to wrapped object
  }

  public String readData() {
    String data = wrapped.readData();
    return decrypt(data);
  }

  private String encrypt(String data) {
    return "encrypted:" + data;
  }

  private String decrypt(String data) {
    return data.replace("encrypted:", "");
  }
}

class CompressionDecorator implements DataSource {

  private DataSource wrapped;

  public CompressionDecorator(DataSource source) {
    this.wrapped = source;
  }

  public void writeData(String data) {
    String compressed = compress(data);
    wrapped.writeData(compressed); // Delegate to wrapped object
  }

  public String readData() {
    String data = wrapped.readData();
    return decompress(data);
  }

  private String compress(String data) {
    return "compressed:" + data;
  }

  private String decompress(String data) {
    return data.replace("compressed:", "");
  }
}

class Main{
  public static void main(String[] args){
    DataSource file = new FileDataSource("data.txt");
    DataSource encrypted = new EncryptionDecorator(file);
    DataSource compressed = new CompressionDecorator(encrypted);
    compressed.writeData("Hello, world!");
    System.out.println(compressed.readData());
  }
}
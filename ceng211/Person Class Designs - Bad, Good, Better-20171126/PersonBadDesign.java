package week3;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileOutputStream;

public class PersonBadDesign {

	private String name;
	private int age;
	
	public PersonBadDesign(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public String getName() {
		return name;
	}
	
	public int getAge() {
		return age;
	}
	
	public String toString() {
		return name + "," + age;
	}
	
	public void toScreen() {
		System.out.println(toString());
	}

	public void toFile(String fileName) throws IOException {
		PrintWriter outputStream = new PrintWriter(new FileOutputStream(fileName));
		outputStream.println(toString());
		outputStream.close();
	}
}

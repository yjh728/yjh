package cn.eight.Map;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Properties;

public class PropertiesTest {
    public static void main(String[] args) {
        Properties p = new Properties();
        p.setProperty("username", "04173174");
        p.setProperty("password", "yjh728.");
        //Properties集合的key和value都只能是String类型
        //p.setProperty("asf", 123);
        //p.setProperty(123, "asd");
        /*System.out.println(p);
        p.store(new FileOutputStream("a.ini"), "comment line");
        Properties p2 = new Properties();
        p2.setProperty("asd", "xzc");
        p2.load(new FileInputStream("a.ini"));
        System.out.println(p2);*/
    }
}

package cn.eight.Map;

import java.util.EnumMap;
import java.util.EnumSet;

enum Seasom {
    SPRING, SUMMER, FALL, WINTER
}

public class EnumMapTest {
    public static void main(String[] args) {
        EnumMap es = new EnumMap(Seasom.class);
        es.put(Seasom.SPRING, "柳树复苏");
        es.put(Seasom.SUMMER, "酷暑难耐");
        //NullPointerException,EnumMap集合不允许的key不允许是null，但value可以
        //es.put(null, null);
        es.put(Seasom.FALL, null);
        System.out.println(es);
    }
}

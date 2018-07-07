package cn.eight.Set;

import java.util.EnumSet;

enum Season {
    SPRING, SUMMER, FALL, WINTER
}

public class EnumSetTest {
    public static void main(String[] args) {
        //创建一个枚举集合，集合元素为Season枚举类所有元素
        EnumSet es = EnumSet.allOf(Season.class);
        System.out.println(es);
        //创建一个空枚举集合，集合元素类型为Season
        EnumSet es2 = EnumSet.noneOf(Season.class);
        System.out.println(es2);
        es2.add(Season.SPRING);
        es2.add(Season.WINTER);
        System.out.println(es2);
        //以指定枚举值创建一个枚举集合
        EnumSet es3 = EnumSet.of(Season.SPRING, Season.FALL);
        System.out.println(es3);
        //创建一个枚举集合，元素是枚举类中的一个范围中的元素
        EnumSet es4 = EnumSet.range(Season.SPRING, Season.WINTER);
        System.out.println(es4);
        //创建一个枚举集合，集合中的元素与集合es4是补集关系
        EnumSet es5 = EnumSet.complementOf(es4);
        System.out.println(es5);
    }
}
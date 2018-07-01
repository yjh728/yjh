package cn.seven;

import java.math.BigDecimal;
import java.util.Calendar;

public class BigDecimalTest {
    public static void main(String[] args) {
        BigDecimal bd = new BigDecimal("0.1");
        BigDecimal bd2 = BigDecimal.valueOf(0.5);
        BigDecimal bd3 = new BigDecimal(0.1);
        System.out.println("使用Srring作为BigDecimal构造器参数:");
        System.out.println("0.1+0.5:" + bd.add(bd2));
        System.out.println("0.1-0.5:" + bd.subtract(bd2));
        System.out.println("0.1*0.5:" + bd.multiply(bd2));
        System.out.println("0.1/0.5:" + bd.divide(bd2));
        System.out.println("使用double作为BigDecimal构造器参数:");
        System.out.println("0.1+0.5:" + bd3.add(bd2));
        System.out.println("0.1-0.5:" + bd3.subtract(bd2));
        System.out.println("0.1*0.5:" + bd3.multiply(bd2));
        System.out.println("0.1/0.5:" + bd3.divide(bd2));
//        Calendar
    }
}

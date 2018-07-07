package cn.eight.Set;

import java.util.Collection;
import java.util.HashSet;
import java.util.function.Predicate;

public class PredicateTest {
    public static void main(String[] args) {
        Collection c = new HashSet();
        c.add("轻量级java ee企业应用实战");
        c.add("疯狂java讲义");
        c.add("疯狂ios讲义");
        c.add("疯狂Android讲义");
        System.out.println("c:" + c);
        c.removeIf(obj -> ((String) obj).length() < 10);
        System.out.println("c:" + c);
        c.add("疯狂java讲义");
        c.add("疯狂ios讲义");
        //使用java8提供的Stream流来操作集合
        System.out.println("含\"疯狂\"：" + calAll(c, ele -> ((String) ele).contains("疯狂")));
        System.out.println("含\"java\"：" + calAll(c, ele -> ((String) ele).contains("java")));
        System.out.println("长度大于10：" + calAll(c, ele -> ((String) ele).length() > 10));
        System.out.println("含\"疯狂\"：" + c.stream().filter(ele->((String)ele).contains("疯狂"))
                .count());
        System.out.println("含\"java\"：" + c.stream().filter(ele->((String)ele).contains("java"))
                .count());
        System.out.println("长度大于10：" + c.stream().filter(ele->((String )ele).length()>10)
                .count());
    }

    public static int calAll(Collection books, Predicate p) {
        int total = 0;
        for (Object obj : books) {
            if (p.test(obj)) {
                total++;
            }
        }
        return total;
    }
}


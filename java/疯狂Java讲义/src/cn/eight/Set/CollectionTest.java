package cn.eight.Set;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;

public class CollectionTest {
    public static void main(String[] args) {
        Collection c = new ArrayList();
        c.add("yjh");
        c.add(6);
        System.out.println("c集合的个数为：" + c.size());
        c.remove(6);
        System.out.println("c集合的个数为：" + c.size());
        System.out.println("c集合是否包含\"yjh\"字符串:" + c.contains("yjh"));
        c.add("728");
        System.out.println("c集合的元素：" + c);
        Collection books = new HashSet();
        books.add("cpp");
        books.add("疯狂java讲义");
        System.out.println("c集合是否包含books集合的所有元素：" + c.containsAll(books));
        c.removeAll(books);
        System.out.println("c集合的元素：" + c);
        c.clear();
        System.out.println("c集合的元素：" + c);
        books.retainAll(c);
        System.out.println("books集合的元素：" + books);
    }
}

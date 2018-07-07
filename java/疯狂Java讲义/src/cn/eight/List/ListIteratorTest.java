package cn.eight.List;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class ListIteratorTest {
    public static void main(String[] args) {
        List l = new ArrayList();
        l.add("yjh");
        l.add("728");
        l.add("YJH728");
        ListIterator lt = l.listIterator();
        // ConcurrentModificationException异常
        // 使用ListIterator或Iterator迭代器后不能对集合列表直接进行操作，只能通过迭代器来进行列表的修改
        // l.add("99");
        while (lt.hasNext()) {
            System.out.println((String) (lt.next()));
            lt.add("========================");
        }
        System.out.println("下面开始反迭代");
        while (lt.hasPrevious()) {
            System.out.println((String) (lt.previous()));
        }
        System.out.println(l);
    }
    /*
    yjh
    728
    YJH728
    下面开始反迭代
    ========================
    YJH728
    ========================
    728
    ========================
    yjh
    [yjh, ========================, 728, ========================, YJH728, ========================]
    */
}
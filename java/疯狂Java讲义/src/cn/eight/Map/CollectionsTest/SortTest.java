package cn.eight.Map.CollectionsTest;

import java.util.ArrayList;
import java.util.Collections;

public class SortTest {
    public static void main(String[] args) {
        ArrayList al = new ArrayList();
        al.add(2);
        al.add(4);
        al.add(-3);
        al.add(6);
        System.out.println(al);
        //反转List集合中元素的顺序
        Collections.reverse(al);
        System.out.println(al);
        //对List集合中的元素进行随机排序
        Collections.shuffle(al);
        System.out.println(al);
    }
}

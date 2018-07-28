package cn.eight.Map.CollectionsTest;

import java.util.ArrayList;
import java.util.Collections;

public class SearchTest {
    public static void main(String[] args) {
        ArrayList al = new ArrayList();
        al.add(2);
        al.add(3);
        al.add(-3);
        al.add(-9);
        System.out.println(al);
        //获取集合最大值
        System.out.println(Collections.max(al));
        //获取集合最小值
        System.out.println(Collections.min(al));
        //替换集合中元素
        System.out.println(Collections.replaceAll(al, 2, -3));
        //返回集合中某特定元素出现次数
        System.out.println(Collections.frequency(al, -3));
        Collections.sort(al);
        //返回特定元素从索引
        System.out.println(Collections.binarySearch(al, -3));
    }
}

package cn.eight.Queue;

/*
 *  LinkedList既实现了List接口，又实现了Deque接口
 *  可以通过索引来访问集合元素
 *  又可以当作双端队列来使用
 *  也可以被当作栈来使用
 */

import java.util.LinkedList;
import java.util.TreeMap;

public class LinkedListTest {
    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        //将指定元素添加至队列尾部
        ll.offer("yjh");
        //将指定元素压入栈顶
        ll.push("728");
        //将指定元素添加至队列头部
        ll.offerFirst("YJH");
        //将指定元素添加至队列头部
        ll.offerFirst("yjh728");
        for (int i = 0; i < ll.size(); i++) {
            System.out.println("遍历：" + ll.get(i));
        }
        //返回队列的第一个元素，但不删除
        System.out.println("peekFirst:" + ll.peekFirst());
        System.out.println(ll);
        //返回队列的最后一个元素，但不删除
        System.out.println("peekLast:" + ll.peekLast());
        System.out.println(ll);
        //弹出队列的栈顶元素
        System.out.println("pop:" + ll.pop());
        System.out.println(ll);
        //获取并删除队列的最后一个元素，若队列为空，则返回null
        System.out.println("pollLast:" + ll.pollLast());
        System.out.println(ll);
    }
}

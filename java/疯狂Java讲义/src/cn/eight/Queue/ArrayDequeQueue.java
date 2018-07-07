package cn.eight.Queue;

/*
 *  Deque是queue接口的一个子接口，他代表一个双端队列，并且还具有栈的功能(pop(),push())
 *  ArrayDeque是Deque的一个实现类，它是一个基于数组实现的双端队列
 *  创建Deque时可以指定参数numElements，该参数用于指定Objects[]数组的长度
 *  若不指定参数，则默认长度16
 */

import java.util.ArrayDeque;

public class ArrayDequeQueue {
    public static void main(String[] args) {
        ArrayDeque stack = new ArrayDeque();
        stack.push("yjh");
        stack.push("728");
        stack.push("yjh728");
        System.out.println(stack);
        stack.pop();
        System.out.println(stack);
        stack.pop();
        System.out.println(stack);
        stack.pop();
        System.out.println(stack);
        /*
            [yjh728, 728, yjh]
            [728, yjh]
            [yjh]
            []
        */
        ArrayDeque ad = new ArrayDeque();
        //若队列为空，会报错
        //System.out.println(ad.getFirst());
        //若队列为空，返回null
        System.out.println(ad.peek());
        //null
        //将元素直接添加至队列末尾，类似于offerLast()方法，addLast()方法
        ad.offer("yjh");
        ad.offer("728");
        ad.offer("yjh728");
        System.out.println(ad);
        ad.offerFirst("YJH");
        System.out.println(ad);
        //获取队列第一个元素，但不删除
        System.out.println(ad.peek());
        System.out.println(ad);
        //获取队列第一个元素并删除
        System.out.println(ad.poll());
        System.out.println(ad);
        //获取队列最后一个元素，但不删除
        System.out.println(ad.peekLast());
        System.out.println(ad);
        //获取队列最后一个元素并删除
        System.out.println(ad.pollLast());
        System.out.println(ad);
        /*
            [yjh, 728, yjh728]
            [YJH, yjh, 728, yjh728]
            YJH
            [YJH, yjh, 728, yjh728]
            YJH
            [yjh, 728, yjh728]
            yjh728
            [yjh, 728, yjh728]
            yjh728
            [yjh, 728]
         */
    }
}

package cn.eight.Queue;

/*
 *  PriorityQueue是一个比较标准的队列
 *  他保存元素的顺序是按队列元素的大小重新排列
 *  当调用peek()函数或poll()函数时是取出最小的元素
 *  PriorityQueue不允许加入null元素
 *  PriorityQueue有两种排序方式：
 *      1：自然排序：
 *          要求所有队列元素必须实现Comparable接口，并且必须是同一个类的实例，否则会引发ClassCastException异常
 *          这和TreeSet要求一样
 *      2：定制排序：
 *          创建PriorityQueue队列时需要传入一个Comparator对象作为参数
 *          相对于TreeSet的一个优势是不要求队列元素实现Comparable接口
 */

import java.math.BigInteger;
import java.util.PriorityQueue;

public class PriorityQueueTest {
    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue();
        pq.add("yjh");
        pq.add("728");
        pq.add("YJH");
        pq.add("yjh728");
        pq.add("YJH728");
        pq.add(new BigInteger("728"));
        System.out.println(pq);
    }
}

package cn.eight.Set;

import java.util.stream.IntStream;

public class StreamTest {
    public static void main(String[] args) {
        IntStream is = IntStream.builder()
                .add(20)
                .add(10)
                .add(-5)
                .add(10)
                .add(20)
                .add(18)
                .build();
        is.distinct()//去除相同元素
                .sorted()//排序流中元素
                .limit(3)//限制访问元素个数
                .forEach(ele -> System.out.println(ele));//遍历流中的元素
        /*
         * 中间方法：中间操作允许流保持打开状态，并允许直接调用后续方法。
         * 末端方法：末端方法就是对流的最终操作。当对某个Stream执行末端方法后，该流会被关闭，不可再用
         */
        /*System.out.println("is所有元素最大值："+is.max().getAsInt());
        System.out.println("is所有元素最小值："+is.min().getAsInt());
        System.out.println("is所有元素之和："+is.sum());
        System.out.println("is所有元素个数："+is.count());
        System.out.println("is所有元素平均值："+is.average());
        System.out.println("is所有元素的平方是否都大于20"+is.allMatch(ele->ele*ele>20));
        System.out.println("is是否有元素的平方大于20："+is.anyMatch(ele->ele*ele>20));
        IntStream newIs = is.map(ele->ele*2+1);
        newIs.forEach(ele->System.out.println(ele));
        newIs.forEach(System.out::println);*/
    }
}


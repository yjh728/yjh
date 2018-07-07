package cn.eight.List;

import java.util.ArrayList;
import java.util.List;

public class ListTest {
    public static void main(String[] args) {
        /* ArrayList是线程不安全的
         Vector也是List的实现类，但是出现比较早，不建议使用
         他还有一个Stack子类，模拟“栈”，同样不建议使用
         若想实现“栈”，可以使用ArrayDeque、
         ArrayList()：
              构造一个初始容量为10的空列表
         ArrayList(int initialCapacity)：
              构造一个具有指定容量的空列表
         ArrayList(Collection<? extends E> c)：
              构造一个包含指定集合的元素的列表，这些元素是按照该集合的迭代器返回他们的顺序排列的*/
        List l = new ArrayList();
        l.add("yjh728");
        l.add("YJH");
        l.add("728");
        l.add("728");
        System.out.println(l);
        //remove()函数只会删除第一个相同的元素，不会删除所有相同的元素
        l.remove("728");
        System.out.println(l);
        //List新增的一种遍历方式
        for (Object obj : l) {
            System.out.println((String) obj);
        }
        System.out.println(l);
        l.add(1, "728");
        System.out.println(l);
        //输出某索引处元素
        System.out.println(l.get(2));
        //输出某元素第一次出现的索引值
        System.out.println(l.indexOf("728"));
        //输出某元素最后一次出现的索引值
        System.out.println(l.lastIndexOf("728"));
        //对指定索引出元素进行替换
        l.set(1, "0728");
        System.out.println(l);
        //两个元素相等(equals返回true)即删除
        l.remove("0728");
        System.out.println(l);
        //截取一个List集合，从第一个参数开始(包括)， 第二个参数截至(不包括)
        System.out.println(l.subList(0, 2));
        System.out.println("-------------------------");
        System.out.println(l);
        //为List集合设置排序方法，参数为Compator，是一个函数式接口，Java8新增的方法
        l.sort((o1, o2) -> ((String) o1).length() - ((String) o2).length());
        System.out.println(l);
        //替换全部元素，参数是UnaryOperator，也是一个函数式接口，以Lambda表达式作为替换规则
        //Java8新增的方法
        l.replaceAll(ele -> ((String) ele).length());
        System.out.println(l);
    }
    /*
    yjh728
    YJH
    728
    [yjh728, YJH, 728]
    [yjh728, 728, YJH, 728]
    YJH
    1
    3
    [yjh728, 0728, YJH, 728]
    [yjh728, YJH, 728]
    [yjh728, YJH]
    [YJH, 728, yjh728]
    [3, 3, 6]
    */
}

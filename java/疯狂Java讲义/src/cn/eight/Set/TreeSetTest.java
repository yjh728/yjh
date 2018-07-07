package cn.eight.Set;

import javax.xml.crypto.Data;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.sql.Time;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;

class Err{
}

public class TreeSetTest {
    public static void main(String[] args) {
        TreeSet ts = new TreeSet();
        ts.add("y");
        ts.add("j");
        ts.add("h");
        ts.add("yjh");
        ts.add("hjy");
        //TreeSet集合要求自然排序的集合必须都实现该接口，
        // 添加未实现Comparable接口的类时抛出ClassCastException异常
        //实现该接口的常用类有：
        //       BigDecimal,BigInteger,Character,Boolean,String,Date, Time
        //ts.add(new Err());
        //向TreeSet集合中添加不同类时会引发ClassCastException异常
        //ts.add(new Scanner(System.in));
        System.out.println(ts);
        //返回该集合的第一个元素
        System.out.println(ts.first());
        //返回该集合的最后一个元素
        System.out.println(ts.last());
        //返回该集合在参数之前的所有元素(不包括参数本身)，参数不一定是该集合中的元素
        System.out.println(ts.headSet("j"));
        //返回该集合在参数之后的所有元素(包括参数本身)，参数不一定是该集合中的元素
        System.out.println(ts.tailSet("j"));
        //返回该集合的一个大于第一个参数且小于第二个参数的元素子集合，参数不一定是该集合中的元素
        System.out.println(ts.subSet("hjy", "yjh"));
        System.out.println(ts.subSet("a", "yjh"));
        System.out.println(ts.subSet("a", "z"));
        //返回集合中比参数小的最大元素，参数不一定是该集合中的元素
        System.out.println(ts.lower("l"));
        //返回集合中比参数大的最小元素，参数不一定是该集合中的元素
        System.out.println(ts.higher("l"));
    }
}


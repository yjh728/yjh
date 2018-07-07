package cn.eight.Set;

import java.math.BigInteger;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;

public class CollectionEach {
    public static void main(String[] args) {
        Collection c = new HashSet();
        c.add("yjh");
        c.add("728");
        //hashSet不能添加相同的元素，若元素内容相同，但hashCode()的返回值不同也可添加成功
        System.out.println(c.add("yjh"));
        c.add("YJH");
        c.add("616");
        //使用Lambda表达式遍历集合
        c.forEach(obj -> System.out.println("迭代元素集合：" + obj));
        //使用Iterator遍历集合
        Iterator it = c.iterator();
        while (it.hasNext()) {
            String s = (String) it.next();
            System.out.println(s);
            if (s == "YJH") {
                //在迭代器中删除集合元素会引发ConcurrentModificationException异常
                //c.remove(s);
                it.remove();
            }
            //迭代变量对集合本身没有影响，相当于将集合中的元素复制了一份给迭代变量
            s = "yjh728";
        }
        System.out.println("c:" + c);
        c.add("YJH");
        System.out.println("c:" + c);
        //使用Lambda表达式遍历Iterator
        //Iterator的对象只能被使用一次，下次使用时须重新进行赋值
        it = c.iterator();
        it.forEachRemaining(obj -> System.out.println("迭代元素：" + obj));
        //使用ForEach遍历集合
        for (Object obj : c) {
            String s = (String) obj;
            System.out.println(s);
            if (s.equals("YJH")) {
                //引发ConcurrentModificationException异常
                //c.remove(s);
            }
        }
        System.out.println("c:" + c);
    }
}


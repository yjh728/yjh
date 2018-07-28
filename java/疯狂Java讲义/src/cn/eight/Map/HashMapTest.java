package cn.eight.Map;

import java.util.HashMap;
import java.util.Hashtable;
import java.util.Iterator;

import cn.eight.Map.HashtableTest;

public class HashMapTest {
    public static void main(String[] args) {
        HashMap hm = new HashMap();
        //HashMap集合可以添加key为null的对象，HashMap集合中key不能重复，因此第二次会将第一次添加的内容覆盖
        hm.put(null, null);
        hm.put(null, "yjh");
        //HashMap集合可以添加多个value为null的对象
        hm.put("yjh", null);
        System.out.println(hm);
        Hashtable ht = new Hashtable();
        //NullPointerException,Hashtable集合不能添加key为null的对象
        //ht.put(null, null);
        //NullPointerException,Hashtable集合不允许添加value为null的对象
        //ht.put("yjh", null);
        hm.clear();
        hm.put(new A(123), "yjh");
        hm.put(new A(234), "728");
        Iterator it = hm.keySet().iterator();
        A first = (A)it.next();
        first.count = 234;
        hm.remove(234);
        System.out.println("是否存在key为234："+hm.containsKey(234));
        System.out.println("是否存在key为123："+hm.containsKey(123));
    }
}

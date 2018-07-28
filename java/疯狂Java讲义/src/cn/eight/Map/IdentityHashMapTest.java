package cn.eight.Map;

import java.util.IdentityHashMap;

public class IdentityHashMapTest {
    public static void main(String[] args) {
        IdentityHashMap ihm = new IdentityHashMap();
        //IdentityHashMap判断两个元素相等的条件是：==
        //因此可以添加两个new出来的内容相同的对象
        ihm.put(new String("yjh"), "04173174");
        ihm.put(new String("yjh"), "728");
        ihm.put("zs", 123);
        ihm.put("zs", 234);
        System.out.println(ihm);
    }
}

package cn.eight.Map;

import java.util.WeakHashMap;

public class WeakHashMapTest {
    public static void main(String[] args) {
        WeakHashMap whm = new WeakHashMap();
        whm.put(new String("C"), "zhongdeng");
        whm.put(new String("C++"), "lianghao");
        whm.put("java", "youxiu");
        System.out.println(whm);
        System.gc();
        //WeakHashMap的key只保留对实际对象的弱引用，因此这些key所引用的对象可能被回收
        //前两个key都是匿名的字符串对象，WeakHashMap只保留对他们的弱引用，因此垃圾回收会被删除
        //最后一个key是字符串直接量，系统自动保持对他的强引用，因此不会被回收
        //若要使用WeakHashMap的key来保持对象的弱引用，则不要让该key所引用的对象具有强引用
        System.out.println(whm);
    }
}

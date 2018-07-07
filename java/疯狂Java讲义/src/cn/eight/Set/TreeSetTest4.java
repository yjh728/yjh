package cn.eight.Set;

import java.util.TreeSet;

class L {
    int count;

    public L(int count) {
        this.count = count;
    }

    @Override
    public String toString() {
        return "L{" + "count=" + count + '}';
    }
}

public class TreeSetTest4 {
    public static void main(String[] args) {
        //此处Lambda表达式的目标类型是Comparator
        TreeSet ts = new TreeSet((o1, o2)->{
            L l1 = (L)o1;
            L l2 = (L)o2;
            //根据L对象的count属性来决定大小，count越大，L对象反而越小
            return l1.count > l2.count ? -1 :
                    l1.count < l2.count ? 1 : 0;
        });
        ts.add(new L(3));
        ts.add(new L(1));
        ts.add(new L(-5));
        ts.add(new L(10));
        System.out.println(ts);
    }
}

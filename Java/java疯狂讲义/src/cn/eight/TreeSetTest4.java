package cn.eight;

import java.util.TreeSet;

class T {
    int count;

    public T(int count) {
        this.count = count;
    }

    @Override
    public String toString() {
        return "T{" + "count=" + count + '}';
    }
}

public class TreeSetTest4 {
    public static void main(String[] args) {
        //此处Lambda表达式的目标类型是Comparator
        TreeSet ts = new TreeSet((o1, o2)->{
            T t1 = (T)o1;
            T t2 = (T)o2;
            //根据T对象的count属性来决定大小，count越大，T对象反而越小
            return t1.count > t2.count ? -1 :
                    t1.count < t2.count ? 1 : 0;
        });
        ts.add(new T(3));
        ts.add(new T(1));
        ts.add(new T(-5));
        ts.add(new T(10));
        System.out.println(ts);
    }
}

package cn.eight.Map;

import java.math.BigInteger;
import java.util.Hashtable;
import java.util.Objects;

class A {
    int count;

    public A(int count) {
        this.count = count;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        A a = (A) o;
        return count == a.count;
    }

    @Override
    public int hashCode() {
        return this.count;
    }
}

class B{
    @Override
    public boolean equals(Object obj) {
        return true;
    }
}

public class HashtableTest {
    public static void main(String[] args) {
        Hashtable ht = new Hashtable();
        ht.put(new A(123), "yjh");
        ht.put(new A(234), "728");
        ht.put(new A(345), new B());
        System.out.println(ht);
        //只要两个value通过equals()返回true就认为两个value相等
        //由于B的对象与任何对象比较equals()都返回true，因此输出true
        System.out.println(ht.containsValue("YJH"));
        //因为两个对象内容相同，equals()方法返回true，且HashCode()返回值相等，即认为是同一个对象，因此输出true
        System.out.println(ht.containsKey(new A(345)));
        ht.remove(new A(345));
        System.out.println(ht);
    }
}

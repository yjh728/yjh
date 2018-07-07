package cn.eight.Set;

import java.util.Iterator;
import java.util.Objects;
import java.util.TreeSet;

class T implements Comparable{
    int count;

    public T(int count) {
        this.count = count;
    }

    @Override
    public String toString() {
        return "T{" + "count=" + count + '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        T t = (T) o;
        return count == t.count;
    }

    @Override
    public int compareTo(Object o) {
        T t = (T) o;
        return count > t.count ? 1 :
                count < t.count ? -1 : 0;
    }
}

public class TreeSetTest3 {
    public static void main(String[] args) {
        TreeSet ts = new TreeSet();
        ts.add(new T(3));
        ts.add(new T(1));
        ts.add(new T(-5));
        ts.add(new T(10));
        System.out.println(ts);
        ((T)(ts.first())).count = 7;
        ((T)(ts.last())).count = -3;
        System.out.println(ts);
    }
}

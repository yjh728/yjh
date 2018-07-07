package cn.eight.Set;

import java.util.Objects;
import java.util.TreeSet;

class Z implements Comparable {
    int count;

    public Z(int count) {
        this.count = count;
    }

    @Override
    public boolean equals(Object o) {
        return true;
    }

    @Override
    public String toString() {
        return "Z{" + "count=" + count + '}';
    }

    @Override
    public int compareTo(Object o) {
        return 1;
    }
}

public class TreeSetTest2 {
    public static void main(String[] args) {
        TreeSet ts = new TreeSet();
        Z z = new Z(7);
        ts.add(z);
        System.out.println(ts);
        ts.add(z);
        System.out.println(ts);
        ((Z) ts.first()).count = 9;
        System.out.println(((Z) ts.last()).count);
    }
}


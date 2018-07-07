package cn.eight.Set;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Objects;

class R {
    int count;

    public R(int count) {
        this.count = count;
    }

    @Override
    public String toString() {
        return "R[count:" + count + "]";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass())
            return false;
        R r = (R) o;
        return count == r.count;
    }

    @Override
    public int hashCode() {
        return this.count;
    }
}

public class HashSetTest {
    public static void main(String[] args) {
        HashSet hs = new HashSet();
        hs.add(new R(5));
        hs.add(new R(3));
        hs.add(new R(-2));
        hs.add(new R(20));
        System.out.println(hs);
        Iterator it = hs.iterator();
        R first = (R)it.next();
        first.count = 5;
        System.out.println(hs);
        hs.remove(new R(5));
        System.out.println("hs是否包含一个count值为-2的对象："+hs.contains(new R(-2)));
        System.out.println("hs是否包含一个count值为5的对象："+hs.contains(new R(5)));
        System.out.println(hs);
    }
}


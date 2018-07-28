package cn.eight.Map.CollectionsTest;

import java.util.*;

public class SynchronizedTest {
    public static void main(String[] args) {
        Collection c = Collections.synchronizedCollection(new HashSet<>());
        List l = Collections.synchronizedList(new ArrayList<>());
        Set s = Collections.synchronizedSet(new HashSet<>());
        Map m = Collections.synchronizedMap(new HashMap<>());
    }
}

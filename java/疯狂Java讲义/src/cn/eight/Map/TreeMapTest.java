package cn.eight.Map;

import java.util.TreeMap;

public class TreeMapTest {
    public static void main(String[] args) {
        TreeMap tm = new TreeMap();
        tm.put("04173174", "yjh");
        tm.put("04173175", "zs");
        tm.put("04173168", "lpd");
        System.out.println(tm);
        System.out.println(tm.firstEntry());
        System.out.println(tm.firstKey());
        System.out.println(tm.lastEntry());
        System.out.println(tm.lastKey());
        System.out.println(tm.lowerEntry("04173174"));
        System.out.println(tm.higherEntry("04173174"));
        System.out.println(tm.subMap("04173168", false, "04173175", true));
        System.out.println(tm.subMap("04173168", "04173175"));
    }
}

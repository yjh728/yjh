package cn.eight.List;

import java.util.Arrays;
import java.util.List;

public class FixedSizeList {
    public static void main(String[] args) {
        List fixedSize = Arrays.asList("yjh", "728", "yjh728");
        System.out.println(fixedSize);
        //UnsupportedOperationException异常，该集合不允许删除元素
        //fixedSize.remove(2);
        //UnsupportedOperationException异常，该集合不允许添加元素
        //fixedSize.add("990728");
    }
}

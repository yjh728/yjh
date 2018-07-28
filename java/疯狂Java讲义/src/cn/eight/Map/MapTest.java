package cn.eight.Map;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class MapTest {
    public static void main(String[] args) {
        Map hm = new HashMap();
        //添加key-value对
        //不允许key相同，但value可以相同
        hm.put("yjh", "04173174");
        hm.put("z", "04173175");
        hm.put("lpd", "04173168");
        System.out.println("hm:"+hm);
        HashMap hm2 = new HashMap();
        hm2.put("yjh", "728");
        //添加hm2集合中的所有元素，若key相同，则替换value(将hm2集合中所有元素put进hm集合)
        hm.putAll(hm2);
        System.out.println("hm:"+hm);
        //通过key删除key-value对
        hm.remove("yjh");
        System.out.println("hm:"+hm);
        hm.put("yjh", "04173174");
        //删除指定key-value对，若删除成功，返回true，否则返回false(java8新增方法)
        System.out.println(hm.remove("yjh", "04173174"));
        //判断集合中是否包含特定key，若包含，返回该key所对应的value，若不存在，返回null
        System.out.println("是否包含key值为“yjh”："+hm.containsKey("yjh"));
        hm.put("yjh", "04173174");
        System.out.println("是否包含key值为“yjh”："+hm.containsKey("yjh"));
        //判断集合中是否包含特定value
        System.out.println(hm.containsValue("是否包含value值为“04173174”："+"04173174"));
        System.out.println("hm"+hm);
        Set hs = hm.keySet();
        System.out.println("下面输出key集合:");
        hs.forEach(obj->System.out.println((String)obj));
        System.out.println("遍历hm集合:");
        for (Object obj : hm.keySet()) {
            System.out.println(obj + "-->" + hm.get(obj));
        }
    }
}

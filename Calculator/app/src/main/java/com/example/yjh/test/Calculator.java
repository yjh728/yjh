package com.example.yjh.test;

import java.math.BigDecimal;
import java.util.ArrayDeque;

public class Calculator {
    //计算表达式的值
    public String caculate(String string) {
        ArrayDeque<String> value = new ArrayDeque<>();
        ArrayDeque<String> operation = new ArrayDeque<>();
        StringBuilder stringBuilder = new StringBuilder();
        String[] expression = formatInput(string);
        for (String s : expression) {
            if (s.equals(" ") || s.length() == 0) {
                continue;
            } else if (isDigital(s.charAt(0))) {
                stringBuilder.append(s+" ");
            } else if (isOperater(s.charAt(0)) || s.charAt(0) == '(' || s.charAt(0) == ')') {
                if (s.equals("(")) {
                    operation.push(s);
                    continue;
                }
                if (s.equals(")")) {
                    while (!operation.getFirst().equals("(")) {
                        if (!operation.getFirst().equals("(")) {
                            stringBuilder.append(operation.poll());
                        }
                    }
                    if (operation.getFirst().equals("(")) {
                        operation.pop();
                        continue;
                    }
                }
                if (operation.isEmpty()) {
                    operation.push(s);
                    continue;
                } else if (priorityIsBiggerOrTheSame(s, operation.getFirst())) {
                    operation.push(s);
                    continue;
                } else {
                    while (!operation.isEmpty() && !priorityIsBiggerOrTheSame(s, operation.getFirst())) {
                        stringBuilder.append(operation.poll());
                    }
                    operation.push(s);
                    continue;
                }
            }
        }
        while (!operation.isEmpty()) {
            stringBuilder.append(operation.poll());
        }
        System.out.println(stringBuilder);
        expression = formatInput(stringBuilder.toString());
        stringBuilder.delete(0, stringBuilder.length());

        for (String s : expression) {
            if (s.equals(" ") || s.length() == 0) {
                continue;
            } else if (isDigital(s.charAt(0))) {
                value.push(s);
            } else if (isOperater(s.charAt(0))) {
                if (value.size() >= 2) {
                    BigDecimal last = new BigDecimal(value.poll());
                    BigDecimal last_p = new BigDecimal(value.poll());
                    if (s.equals("-")) {
                        value.push(last_p.subtract(last).toString());
                    } else if (s.equals("+")) {
                        value.push(last_p.add(last).toString());
                    } else if (s.equals("*")) {
                        value.push(last_p.multiply(last).toString());
                    } else if (s.equals("/")) {
                        value.push(last_p.divide(last).toString());
                    }
                }
            }
        }
        return value.poll();
    }
    // 提取出操作数栈的前2个数，操作符栈的栈顶操作符，运算
    public static void compute(ArrayDeque<Integer> value, ArrayDeque<Character> operation) {
        int v1 = value.pop();
        int v2 = value.pop();
        char op = operation.pop();
        switch (op) {
            case '+':
                value.push(v2 + v1);
                break;
            case '-':
                value.push(v2 - v1);
                break;
            case '*':
                value.push(v2 * v1);
                break;
            case '/':
                value.push(v2 / v1);
                break;
        }
    }

    public static boolean isOperater(int a) {
        if (a == '+' || a == '-' || a == '*' || a == '/')
            return true;
        return false;
    }

    public static boolean isDigital(int a) {
        if (a >= '0' && a <= '9')
            return true;
        return false;
    }

    // 格式化中缀表达式输入，即在符号前后添加空格，便于后面的分隔操作
    public static String[] formatInput(String s) {
        String temp = "";
        /*
         * 提取出表达式中有效的字符（非空格），然后在字符后面统一添上一个空格，方便后面使用静态方法String.split()来
         * 例如：1 *(2+ 3) /4     ----->     1 * ( 2 + 3 ) / 4
         * 你也可以直接使用List类来存储提取的有效字符 总之最后的目的就是返回一个数组，其中存储的是有效字符
         */
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (isOperater(c) || c == '(' || c == ')')
                temp += " " + c + " ";
            else
                temp += c;// 数字不用加空格
        }
        return temp.split(" ");// 分割
    }

    // 优先级判断，a是否大于b
    public static boolean priorityIsBiggerOrTheSame(String a, String b) {
        String s = " +- */";
        return s.indexOf(a) - s.indexOf(b) >= 2;
    }
}

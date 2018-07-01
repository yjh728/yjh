package com.five;

public class Header extends People{
    public Header() {
    }

    public Header(String name, int age) {
        super(name, age);
    }

    public void manage(){
        System.out.println("班主任管理学生");
    }
}

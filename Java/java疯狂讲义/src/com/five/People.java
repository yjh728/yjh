package com.five;

public class People {
    private String name;
    private int age;
    public People(){}

    public People(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void eat() {
        System.out.println("eat");
    }

    public void drink() {
        System.out.println("drink");
    }

    public void play() {
        System.out.println("play");
    }

    public void sleep() {
        System.out.println("sleep");
    }
}

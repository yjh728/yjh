package com.five;

public class Teacher extends People {
    private String project;

    public String getProject() {
        return project;
    }

    public void setProject(String project) {
        this.project = project;
    }

    public void teacher() {
        System.out.println("老师教学生");
    }

    public Teacher() {
    }

    public Teacher(String name, int age) {
        super(name, age);
    }
}

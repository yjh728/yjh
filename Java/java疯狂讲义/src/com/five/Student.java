package com.five;

public class Student extends People{
    private String gender;
    private String phone;
    private String address;
    private String email;
    private int grade;
    public Student() {}

    public Student(String name, int age, String gender, String phone, String address, String email) {
        super(name, age);
        this.gender = gender;
        this.phone = phone;
        this.address = address;
        this.email = email;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getGrade() {
        return grade;
    }

    public void setGrade(int grade) {
        this.grade = grade;
    }


    public void study(){
        System.out.println("学生学老师教的东西");
    }
}

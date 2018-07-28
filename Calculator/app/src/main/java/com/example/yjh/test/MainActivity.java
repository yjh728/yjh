package com.example.yjh.test;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private TextView textView;
    public StringBuilder results = new StringBuilder();
    private List<String> list = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button0 = (Button) findViewById(R.id.number_0);
        Button button1 = (Button) findViewById(R.id.number_1);
        Button button2 = (Button) findViewById(R.id.number_2);
        Button button3 = (Button) findViewById(R.id.number_3);
        Button button4 = (Button) findViewById(R.id.number_4);
        Button button5 = (Button) findViewById(R.id.number_5);
        Button button6 = (Button) findViewById(R.id.number_6);
        Button button7 = (Button) findViewById(R.id.number_7);
        Button button8 = (Button) findViewById(R.id.number_8);
        Button button9 = (Button) findViewById(R.id.number_9);

        Button button_add = (Button) findViewById(R.id.symbol_add);
        Button button_sub = (Button) findViewById(R.id.symbol_sub);
        Button button_mult = (Button) findViewById(R.id.symbol_mult);
        Button button_div = (Button) findViewById(R.id.symbol_div);
        Button button_del = (Button) findViewById(R.id.symbol_del);
        Button button_dian = (Button) findViewById(R.id.symbol_dian);
        Button button_equal = (Button) findViewById(R.id.symbol_equal);
        Button button_left = (Button) findViewById(R.id.symbol_left);
        Button button_right = (Button) findViewById(R.id.symbol_right);
        Button button_ac = (Button) findViewById(R.id.symbol_ac);
        this.textView = (TextView) findViewById(R.id.text_view);
        button0.setOnClickListener(this);
        button1.setOnClickListener(this);
        button2.setOnClickListener(this);
        button3.setOnClickListener(this);
        button4.setOnClickListener(this);
        button5.setOnClickListener(this);
        button6.setOnClickListener(this);
        button7.setOnClickListener(this);
        button8.setOnClickListener(this);
        button9.setOnClickListener(this);
        button_add.setOnClickListener(this);
        button_sub.setOnClickListener(this);
        button_mult.setOnClickListener(this);
        button_div.setOnClickListener(this);
        button_del.setOnClickListener(this);
        button_dian.setOnClickListener(this);
        button_left.setOnClickListener(this);
        button_ac.setOnClickListener(this);
        button_right.setOnClickListener(this);
        button_equal.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        int last = 0;
        int last_p = 0;
        if (results.length() != 0) {
            last = results.codePointAt(results.length() - 1);
            if (results.length() > 1)
                last_p = results.codePointBefore(results.length() - 1);
        }
        if (results.indexOf("=") > 0) {
            results.replace(0, results.length(), "");
        }

        switch (view.getId()) {
            case R.id.number_0:
                if (last == ')') {
                    results.append("*0");
                } else {
                    results.append('0');
                }
                textView.setText(results);
                break;
            case R.id.number_1:
                if (last == ')') {
                    results.append("*1");
                } else {
                    results.append('1');
                }
                textView.setText(results);
                break;
            case R.id.number_2:
                if (last == ')') {
                    results.append("*2");
                } else {
                    results.append('2');
                }
                textView.setText(results);
                break;
            case R.id.number_3:
                if (last == ')') {
                    results.append("*3");
                } else {
                    results.append('3');
                }
                textView.setText(results);
                break;
            case R.id.number_4:
                if (last == ')') {
                    results.append("*4");
                } else {
                    results.append('4');
                }
                textView.setText(results);
                break;
            case R.id.number_5:
                if (last == ')') {
                    results.append("*5");
                } else {
                    results.append('5');
                }
                textView.setText(results);
                break;
            case R.id.number_6:
                if (last == ')') {
                    results.append("*6");
                } else {
                    results.append('6');
                }
                textView.setText(results);
                break;
            case R.id.number_7:
                if (last == ')') {
                    results.append("*7");
                } else {
                    results.append('7');
                }
                textView.setText(results);
                break;
            case R.id.number_8:
                if (last == ')') {
                    results.append("*8");
                } else {
                    results.append('8');
                }
                textView.setText(results);
                break;
            case R.id.number_9:
                if (last == ')') {
                    results.append(" * 9");
                } else {
                    results.append('9');
                }
                textView.setText(results);
                break;
            case R.id.symbol_add:
                    /*if ((last >= '0' && last <= '9') || last == ')') {
                        results.append(" + ");
                    } else if (last == '(' || results.equals(".") || results.equals("")) {
                        Toast.makeText(MainActivity.this, "错误",
                                Toast.LENGTH_SHORT).show();
                    } else if (){
                        results.replace(results.length() - 1,results.length(),  " + ");
                    }
                    textView.setText(results);
                    break;*/
                if (isDigital(last) || last == ')' || last == '.') {
                    results.append('+');
                } else if (isOperater(last) && isOperater(last_p)) {
                    results.replace(results.length() - 2, results.length(), "+");
                } else if (isOperater(last)) {
                    results.setCharAt(results.length() - 1, '+');
                } else {
                    Toast.makeText(MainActivity.this, "错误",
                            Toast.LENGTH_SHORT).show();
                }
                textView.setText(results);
                break;
            case R.id.symbol_sub:
                    /*if (last == '+') {
                        results.replace(results.length()-1, results.length(),  " - ");
                    } else if (results.equals(".") || last == '-') {
                        Toast.makeText(MainActivity.this, "错误",
                                Toast.LENGTH_SHORT).show();
                    } else {
                        results.append(" - ");
                    }
                    textView.setText(results);
                    break;*/
                if (isDigital(last) || last == ')' || last == '(' || last == '.') {
                    results.append('-');
                } else if (last == '-' || last == '+') {
                    results.setCharAt(results.length() - 1, '-');
                } else if (last == '*' || last == '/') {
                    results.append('-');
                } else if (results.length() == 0) {
                    results.append('-');
                } else {
                    Toast.makeText(MainActivity.this, "错误",
                            Toast.LENGTH_SHORT).show();
                }
                textView.setText(results);
                break;
            case R.id.symbol_mult:
                    /*if (last == '(' || results.equals(".")) {
                        Toast.makeText(MainActivity.this, "错误",
                                Toast.LENGTH_SHORT).show();
                    } else if (last >= '0' && last <= '9' || last == ')') {
                        results.append(" * ");
                    } else {
                        results.replace(results.length() - 1, results.length(), " * ");
                    }*/
                if (isDigital(last) || last == ')' || last == '.') {
                    results.append('*');
                } else if (isOperater(last)) {
                    results.setCharAt(results.length() - 1, '*');
                } else if (isOperater(last) && isOperater(last_p)) {
                    results.replace(results.length() - 2, results.length(), "*");
                } else {
                    Toast.makeText(MainActivity.this, "错误",
                            Toast.LENGTH_SHORT).show();
                }
                textView.setText(results);
                break;
            case R.id.symbol_div:
                    /*if (last == '(' || results.equals(".")) {
                        Toast.makeText(MainActivity.this, "错误",
                                Toast.LENGTH_SHORT).show();
                    } else if (last >= '0' && last <= '9' || last == ')') {
                        results.append(" / ");
                    } else {
                        results.replace(results.length() - 1, results.length(), "/");
                    }*/
                if (isDigital(last) || last == ')' || last == '.') {
                    results.append('/');
                } else if (isOperater(last) && isOperater(last_p)) {
                    results.replace(results.length() - 2, results.length(), "/");
                } else if (isOperater(last)) {
                    results.setCharAt(results.length() - 1, '/');
                } else {
                    Toast.makeText(MainActivity.this, "错误",
                            Toast.LENGTH_SHORT).show();
                }
                textView.setText(results);
                break;
            case R.id.symbol_del:
                if (results.indexOf("=") > 0) {
                    results.replace(0, results.length(), "");
                } else if (results.length() > 0) {
                    results.deleteCharAt(results.length() - 1);
                }
                textView.setText(results);
                break;
            case R.id.symbol_ac:
                results.delete(0, results.length());
                textView.setText(results);
                break;
            case R.id.symbol_dian:
                if (isDigital(last)) {
                    results.append('.');
                } else {
                    Toast.makeText(MainActivity.this, "错误",
                            Toast.LENGTH_SHORT).show();
                }
                textView.setText(results);
                break;
            case R.id.symbol_left:
                if (isDigital(last)) {
                    results.append("*(");
                } else if (isOperater(last)) {
                    results.append('(');
                } else if (last == ')') {
                    results.append("*(");
                } else if (last == '(') {
                    results.append('(');
                } else if (results.length() == 0) {
                    results.append('(');
                } else {
                    Toast.makeText(MainActivity.this, "错误",
                            Toast.LENGTH_SHORT).show();
                }
                textView.setText(results);
                break;
            case R.id.symbol_right:
                if (isDigital(last) || last == ')') {
                    results.append(')');
                } else {
                    Toast.makeText(MainActivity.this, "错误",
                            Toast.LENGTH_SHORT).show();
                }
                textView.setText(results);
                break;
            case R.id.symbol_equal:
                try {
                    /*if ((results.toString().endsWith("错误")) && results.indexOf("=") > 0) {
                        results.replace(0, results.indexOf("="), "");
                    } else if ((results.length() > 1)) {
                        InfixInToDuffix inf = new InfixInToDuffix();
                        String jieguo;
                        try {
                            String a = inf.toSuffix(results);
                            jieguo = inf.dealEquation(a);

                        } catch (Exception ex) {
                            jieguo = "出错";
                        }
                        results.append("=" + jieguo);
                        //results = results.delete(0, results.length());
                        *//*if (Character.isDigit(jieguo.charAt(0))) {
                            results = results.append(jieguo);
                        }*//*
                    }
                    textView.setText(results);
                    break;*/
                   /* results.append("=");
                    Caculate caculate = new Caculate();
                    String s = caculate.equals1(results.toString());
                    results.replace(0, results.length(), s);
                    textView.setText(results);*/
                    /*if (isDigital(last) || last == ')') {
                        results.append("=");
                    } else {
                        results.append("=错误");
                        break;
                    }
                    if (op_legal() && kuohaopipei()) {
                        InfixInToDuffix infixInToDuffix = new InfixInToDuffix();
                        String s = infixInToDuffix.toSuffix(results);
                        String b = infixInToDuffix.dealEquation(s);
                        results.append(b);
                    } else {
                        results.append("错误");
                    }
                    break;*/
                    Calculator calculator = new Calculator();
                    results.replace(0, results.length(), calculator.caculate(results.toString()));
                    textView.setText(results);
                } catch (Exception e) {
                    textView.setText(e.getMessage());
                }
            default:
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

    private boolean op_legal() {
        int i = 0;
        while (i < results.length()) {
            char x = results.charAt(i);
            i++;
            if (isDigital(x)) {
                x = results.charAt(i);
                i++;
                StringBuilder stringBuilder = new StringBuilder();
                while (isDigital(x)) {
                    stringBuilder.append(x);
                    x = results.charAt(i);
                    i++;
                }
                int flag = 0;
                for (int j = 0; j < stringBuilder.length(); j++) {
                    if (stringBuilder.charAt(j) == '.')
                        flag++;
                    if (flag > 1)
                        return false;
                }
            }
        }
        return true;
    }

    private boolean kuohaopipei() {
        int flag = 0;
        for (int i = 0; i < results.length(); i++) {
            int x = results.charAt(i);
            if (x == '(') {
                flag++;
            } else if (x == ')') {
                flag--;
            }
        }
        if (flag >= 0) {
            return true;
        } else {
            return false;
        }
    }
}

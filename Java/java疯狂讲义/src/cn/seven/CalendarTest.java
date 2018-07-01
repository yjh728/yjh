package cn.seven;

import javafx.scene.chart.XYChart;

import java.time.LocalDate;
import java.util.Calendar;

public class CalendarTest {
    public static void main(String[] args) {
        Calendar c = Calendar.getInstance();
        c.set(1999, 9, 9);
        c.add(Calendar.DATE, 800);
        System.out.println(c.getTime());
    }
}

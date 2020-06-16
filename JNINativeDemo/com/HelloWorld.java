package com;
import java.util.ArrayList;
import java.lang.Object;
public class HelloWorld {

    private int ID = 0;
    private String job = "";
    private String name = "Mary";
    private static double happyScore = 80.0;

    public native void hello();
    public native void setRecordValue(int value);
    public native int getRecordValue();
    public native String queryJobViaName(String name);
    public native String setAges(int[] ages);

    public native void modifyDataViaName(String name);
    public native void modifyStaticHappyScore();
    public native void nativeCallBack();

    public native Integer getIntergerObject(int number);
    public native Double[] sumAndAverage(Integer[] numbers);

    private void callBack(String message){
        System.out.println("Java got the message: " + message);
    }

    static {
        //设置查找路径为当前项目路径
        System.setProperty("java.library.path", "../nativelib");
        //加载动态库的名称
        System.loadLibrary("hello");
    }

    public static void main(String[] args) {
        HelloWorld myWorld = new com.HelloWorld();
        myWorld.hello();
        myWorld.setRecordValue(100);
        System.out.println("In java, get record value is " + myWorld.getRecordValue());

        System.out.println("--------------query job--------------");
        String name = "Mary";
        System.out.println("In java, get " + name + "'s job is: "+ myWorld.queryJobViaName(name));

        System.out.println("--------------set age--------------");
        int[] ages = {23, 34, 54};
        String result = myWorld.setAges(ages);
        System.out.println(result);

        System.out.println("--------------modifyData--------------");
        System.out.println("before modify, name: " + myWorld.name + ", ID: " + myWorld.ID + ", Job: " + myWorld.job);
        myWorld.modifyDataViaName(myWorld.name);
        System.out.println("after modify, name: " + myWorld.name + ", ID: " + myWorld.ID + ", Job: " + myWorld.job);

        System.out.println("--------------be happier--------------");
        System.out.println("before modify, happy score: " + myWorld.happyScore);
        myWorld.modifyStaticHappyScore();
        System.out.println("after modify, happy score: " + myWorld.happyScore);

        System.out.println("--------------calling back--------------");
        myWorld.nativeCallBack();

        System.out.println("--------------get Interger object from native--------------");
        System.out.println("Get the integer: " + myWorld.getIntergerObject(666));

        System.out.println("--------------get Interger object from native--------------");
        Integer[] numbers = {11, 22, 33};
        Double[] results = myWorld.sumAndAverage(numbers);
        System.out.println("In java, the sum is " + results[0]);
        System.out.println("In java, the average is " + results[1]);
    }
}
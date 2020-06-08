package com;
public class HelloWorld {

    private int ID = 0;
    private String job = "";
    private String name = "Mary";

    public native void hello();
    public native void setRecordValue(int value);
    public native int getRecordValue();
    public native String queryJobViaName(String name);
    public native String setAges(int[] ages);

    public native void modifyDataViaName(String name);
    

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
    }
}
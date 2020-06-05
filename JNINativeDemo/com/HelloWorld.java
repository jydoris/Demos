package com;
public class HelloWorld {

    public native void hello();
    public native void setRecordValue(int value);
    public native int getRecordValue();
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
    }
}
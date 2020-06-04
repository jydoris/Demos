package com;
public class HelloWorld {

    public native void hello();

    static {
        //设置查找路径为当前项目路径
        System.setProperty("java.library.path", "../nativelib");
        //加载动态库的名称
        System.loadLibrary("hello");
    }

    public static void main(String[] args) {
        new com.HelloWorld().hello();
    }
}
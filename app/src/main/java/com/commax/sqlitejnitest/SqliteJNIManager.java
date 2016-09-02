package com.commax.sqlitejnitest;

import java.util.ArrayList;

/**
 * Created by bagjeong-gyu on 2016. 8. 23..
 */
public class SqliteJNIManager {

    static {
        System.loadLibrary("SqliteJNIManager");
    }

    public static native void readAllDevices();

    public static native void addDeviceToDB();

    public static native void removeDeviceOnDB();
}

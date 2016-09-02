package com.commax.sqlitejnitest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        makeDeviceList();

    }

    private void makeDeviceList() {
        //SqliteJNIManager.readAllDevices();
        SqliteJNIManager.addDeviceToDB();

    }

//    private void makeDeviceList() {
//        ArrayList<Device> devices = SqliteJNIManager.readAllDevices();
//        int RS485DeviceCount = devices.size();
//
//        ListView deviceList = (ListView) findViewById(R.id.deviceList);
//        DeviceListAdapter adapter = new DeviceListAdapter(this, R.layout.list_item_device, devices);
//        adapter.setRS485DeviceCount(RS485DeviceCount);
//
//
//        deviceList.setAdapter(adapter);
//    }

    public void addDeviceToDB(View view) {
        Log.d("SqliteJni", "addDeviceToDB 버튼 클릭");
        SqliteJNIManager.addDeviceToDB();

    }

    public void removeDeviceOnDB(View view) {
        Log.d("SqliteJni", "removeDeviceOnDB 버튼 클릭");
        SqliteJNIManager.removeDeviceOnDB();

    }
}

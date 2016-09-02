package com.commax.sqlitejnitest;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.TextView;



import java.util.List;

/**
 * Created by bagjeong-gyu on 2016. 8. 22..
 */
public class DeviceListAdapter extends ArrayAdapter<Device> {


    private final LayoutInflater mLayoutInflater;
    private final List<Device> mDatas;
    private int mRS485DeviceCount;

    public DeviceListAdapter(Context context, int resource, List<Device> devices) {
        super(context, resource, devices);
        mLayoutInflater = LayoutInflater.from(context);
        mDatas = devices;
    }

    @Override
    public View getView(final int position, View convertView, ViewGroup parent) {

        if (convertView == null) {
            convertView = mLayoutInflater.inflate(R.layout.list_item_device,
                    parent, false);
        }


        TextView deviceType = PlusViewHolder.get(convertView, R.id.deviceType);
        deviceType.setText(mDatas.get(position).getDeviceType());

        //RS485장치는 무조건 체크되고 변경이 불가능하게 처리
        CheckBox deviceCheckbox = PlusViewHolder.get(convertView, R.id.deviceCheckbox);
        if(position < mRS485DeviceCount) {
            deviceCheckbox.setChecked(true);
            deviceCheckbox.setEnabled(false);
            //deviceCheckbox.setBackgroundResource(R.drawable.check_03);
            deviceCheckbox.setButtonDrawable(R.drawable.check_03);
        } else {
            deviceCheckbox.setChecked(true);
            deviceCheckbox.setEnabled(true);
            //deviceCheckbox.setBackgroundResource(R.drawable.check_02);
            deviceCheckbox.setButtonDrawable(R.drawable.checkbox_selector2);
        }


        return convertView;
    }


    public void setRS485DeviceCount(int RS485DeviceCount) {
        mRS485DeviceCount = RS485DeviceCount;

    }
}

package com.jikexueyuan.interceptspammessages.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.jikexueyuan.interceptspammessages.R;
import com.jikexueyuan.interceptspammessages.domian.ContactInfo;

import java.util.List;


/**
 * Created by liupf on 2016/1/19.
 */
public class ContactAdapter extends BaseAdapter {
    private Context context;
    private List<ContactInfo> infos;
    public ContactAdapter(Context context, List<ContactInfo> infos) {
        this.infos = infos;
        this.context = context;
    }
    @Override
    public int getCount() {
        return infos.size();
    }

    @Override
    public Object getItem(int position) {
        return infos.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder=new ViewHolder();
        ContactInfo info = infos.get(position);
        if(convertView==null){
            LayoutInflater inflater= LayoutInflater.from(context);
            convertView=inflater.inflate(R.layout.item_activity,null);    //这里的null是一个ViewGroup形参，基本用不上
            viewHolder.tv_name = (TextView) convertView.findViewById(R.id.tv_name);
            viewHolder.tv_phone = (TextView) convertView.findViewById(R.id.tv_phone);
            convertView.setTag(viewHolder);
        }
        else{
            viewHolder=(ViewHolder)convertView.getTag();    //通过getTag()方法获得附加信息
        }
        viewHolder.tv_name.setText(info.getName());
        viewHolder.tv_phone.setText(info.getPhone());
        return convertView;
     }
    class ViewHolder {
        public TextView tv_name = null, tv_phone = null;
    }

    public void refrashData(List<ContactInfo> infos){
        this.infos=infos;
    }
}

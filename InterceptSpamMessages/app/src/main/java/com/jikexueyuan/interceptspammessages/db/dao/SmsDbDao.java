package com.jikexueyuan.interceptspammessages.db.dao;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import com.jikexueyuan.interceptspammessages.db.SmsDbHelper;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by liupf on 2016/1/20.
 */
public class SmsDbDao {
    private Context context;
    private SmsDbHelper dbHelper;
    public SmsDbDao(Context context) {
        this.context = context;
        dbHelper=new SmsDbHelper(context);
    }
    /**
     * 查询
     */
    public boolean find(String keyword) {
        boolean result=false;
        SQLiteDatabase db=dbHelper.getReadableDatabase();
        if(db.isOpen()){
            Cursor cursor=db.rawQuery("select keyword from keyword_table where keyword=?",new String[]{keyword});
            if (cursor.moveToNext()) {
                result = true;
            }
            cursor.close();
            db.close();
        }
        return result;
    }

public void add(String keyword){
    if(find(keyword)){//防止重复添加
        return;
    }
    SQLiteDatabase db=dbHelper.getWritableDatabase();
    if(db.isOpen()){
        db.execSQL("insert into keyword_table (keyword) values (?)", new Object[]{keyword});
        db.close();
    }
}
    /**
     * 删除
     */
    public void delete(String keyword){
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        if(db.isOpen()){
            db.execSQL("delete from keyword_table where keyword=?", new Object[]{keyword});
            db.close();
        }
    }

    /**
     * 更新操作
     * @param oldkeywordr 旧的
     * @param newkeyword 新的
     */
    public void  update(String oldkeywordr ,String newkeyword){
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        if(db.isOpen()){
            db.execSQL("update keyword_table set keyword=? where keyword=?  ", new Object[]{newkeyword,oldkeywordr});
            db.close();
        }
    }
    /**
     * 查找全部
     */
    public List<String> getAllNumbers(){
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        List<String> numbers = new ArrayList<String>();
        if (db.isOpen()) {
            Cursor cursor =	db.rawQuery("select number from keyword_table", null);
            while (cursor.moveToNext()) {
                String number = cursor.getString(0);
                numbers.add(number);
            }
            cursor.close();
            db.close();
        }
        return numbers;
    }
}

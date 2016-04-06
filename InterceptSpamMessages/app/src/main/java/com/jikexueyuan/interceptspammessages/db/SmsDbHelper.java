package com.jikexueyuan.interceptspammessages.db;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/**
 * Created by liupf on 2016/1/20.
 */
public class SmsDbHelper extends SQLiteOpenHelper {
    public SmsDbHelper(Context context) {
        super(context, "sms.db3", null, 1);
    }
    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL("CREATE TABLE keyword_table (_id integer primary key autoincrement, keyword varchar(30))");
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i2) {

    }
}

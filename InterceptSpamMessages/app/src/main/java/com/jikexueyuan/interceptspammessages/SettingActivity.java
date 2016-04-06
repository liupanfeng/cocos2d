package com.jikexueyuan.interceptspammessages;

import android.content.DialogInterface;
import android.content.Intent;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;

public class SettingActivity extends ActionBarActivity implements View.OnClickListener {
    private Button btn_edit_keyword;
    private Button btn_edit_contacts;
    private Intent intent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_setting);

        initView();
        intiListener();
        intent=new Intent();
    }
    private void initView() {
        btn_edit_keyword=(Button)findViewById(R.id.btn_edit_keyword);
        btn_edit_contacts=(Button)findViewById(R.id.btn_edit_contacts);
    }
    private void intiListener() {
        btn_edit_keyword.setOnClickListener(this);
        btn_edit_contacts.setOnClickListener(this);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_setting, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.btn_edit_keyword:
                intent.setClass(this,EditKeyWordActivity.class);
                startActivity(intent);
                break;
            case R.id.btn_edit_contacts:
                intent.setClass(this,EditContactsActivity.class);
                startActivity(intent);
                break;
        }
    }
}

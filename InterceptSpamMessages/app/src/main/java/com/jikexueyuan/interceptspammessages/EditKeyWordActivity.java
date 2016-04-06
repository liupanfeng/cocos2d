package com.jikexueyuan.interceptspammessages;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import com.jikexueyuan.interceptspammessages.dialog.ConfirmInputDialogTwo;
import com.jikexueyuan.interceptspammessages.dialog.CustomTwoButtonDialogOnClickListener;

/**
 * 编辑关键字界面
 */
public class EditKeyWordActivity extends ActionBarActivity  implements View.OnClickListener,AdapterView.OnItemLongClickListener {
    private Button btn_add_keyword;
    private ListView ll_keyword;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_key_word);
        initView();
        intiListener();
        initData();
    }
    private void initView() {
        btn_add_keyword=(Button)findViewById(R.id.btn_add_keyword);
        ll_keyword=(ListView)findViewById(R.id.ll_keyword);
    }
    private void intiListener() {
        btn_add_keyword.setOnClickListener(this);
        ll_keyword.setOnItemLongClickListener(this);
    }
    private void initData() {
//        service = new ContactInfoService(this);
//        infos = service.getContactInfos();
//        adapter=new ContactAdapter(MainActivity.this,infos);
//        ll_show_contact.setAdapter(adapter);
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
        showDialog();
    }
    private void showDialog(){
        ConfirmInputDialogTwo dialog=new ConfirmInputDialogTwo(this,R.style.dialog,new CustomTwoButtonDialogOnClickListener() {
            @Override
            public int onConfirmButtonClick(String name) {

                return 1;
            }

            @Override
            public void onCancelButtonClick() {

            }
        });
        dialog.show();
    }
    @Override
    public boolean onItemLongClick(AdapterView<?> adapterView, View view, int i, long l) {
        return false;
    }
}

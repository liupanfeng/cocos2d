package com.jikexueyuan.interceptspammessages.dialog;

import android.app.Dialog;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.text.TextUtils;
import android.view.Gravity;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.EditText;
import android.widget.TextView;

import com.jikexueyuan.interceptspammessages.R;


/**
 * Created by liupf on 2016/1/19.
 */
public class ConfirmInputDialogTwo extends Dialog implements View.OnClickListener {
    private TextView btn_cancel;
    private TextView btn_ok;

    private CustomTwoButtonDialogOnClickListener mListener;
    private Handler mDelayHandler = null;
    private Context mContext;
    private EditText et_content;

    public ConfirmInputDialogTwo(Context context,
                                 int theme, CustomTwoButtonDialogOnClickListener listener) {
        super(context, theme);
        mContext = context;
        mListener = listener;
        mDelayHandler = new Handler();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.dialog_one_input);

        // 设置占满全屏，否则有可能dialog无法占满屏幕
        Window dialogWindow = getWindow();
        WindowManager.LayoutParams lp = dialogWindow.getAttributes();
        dialogWindow.setGravity(Gravity.CENTER);
        lp.width = WindowManager.LayoutParams.FILL_PARENT;
        dialogWindow.setAttributes(lp);

          et_content=(EditText)findViewById(R.id.et_content);
          btn_cancel=(TextView)findViewById(R.id.btn_cancel);
          btn_ok=(TextView)findViewById(R.id.btn_ok);
          btn_cancel.setOnClickListener(this);
          btn_ok.setOnClickListener(this);
    }
    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_cancel: {
                dismiss();
                mListener.onCancelButtonClick();
                break;
            }
            case R.id.btn_ok: {
                String name=et_content.getText().toString().trim();
                int type= mListener.onConfirmButtonClick(name);
                if(type!=0){//信息完整
                    dismiss();
                }
                break;
            }
        }
    }
}

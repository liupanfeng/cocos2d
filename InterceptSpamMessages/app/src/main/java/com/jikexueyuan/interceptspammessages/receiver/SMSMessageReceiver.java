package com.jikexueyuan.interceptspammessages.receiver;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.telephony.SmsMessage;
import android.widget.Toast;
public class SMSMessageReceiver extends BroadcastReceiver {
    public SMSMessageReceiver() {
    }
    @Override
    public void onReceive(Context context, Intent intent) {
        Bundle extras = intent.getExtras();
        if (extras == null)
            return;
        Object[] pdus = (Object[]) extras.get("pdus");
        for (int i = 0; i < pdus.length; i++) {
            SmsMessage message = SmsMessage.createFromPdu((byte[]) pdus[i]);
            String fromAddress = message.getOriginatingAddress();
            String messages=message.getMessageBody();
            Toast.makeText(context,"fromAddress:"+fromAddress+"messages:"+messages, Toast.LENGTH_SHORT).show();
        }

    }
}

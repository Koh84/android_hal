package com.android.server;
import android.os.ILedService;

public class LedService extends ILedService.Stub
{
    	private static final String TAG = "LedService";
	/* call native c function to access hardware */
	public int ledCtrl(int which, int status) throws android.os.RemoteException
	{
		return native_ledCtrl(which, status);
	}

	public LedService()
	{
		native_ledOpen();
	}

	public int native_ledOpen();
	public void native_ledClose();
	public int native_ledCtrl(int which, int status);
}

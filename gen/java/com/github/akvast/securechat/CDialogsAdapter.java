// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from adapter_dialogs.djinni

package com.github.akvast.securechat;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class CDialogsAdapter {
    public abstract ArrayList<CDialogViewModel> getDialogs();

    public static native CDialogsAdapter instance();

    private static final class CppProxy extends CDialogsAdapter
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        @Override
        public ArrayList<CDialogViewModel> getDialogs()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getDialogs(this.nativeRef);
        }
        private native ArrayList<CDialogViewModel> native_getDialogs(long _nativeRef);
    }
}

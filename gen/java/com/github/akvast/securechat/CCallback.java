// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from common.djinni

package com.github.akvast.securechat;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class CCallback {
    public abstract void execute();

    private static final class CppProxy extends CCallback
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
        public void execute()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_execute(this.nativeRef);
        }
        private native void native_execute(long _nativeRef);
    }
}
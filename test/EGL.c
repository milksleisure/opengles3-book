#include <EGL/egl.h>

static EGLBoolean initDisplay(EGLDisplay *p_display)
{
    *p_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if(*p_display == EGL_NO_DISPLAY) {
        return EGL_FALSE;
    }

    EGLint major;
    EGLint minor;
    if(!eglInitialize(*p_display, &major, &minor)) {
        return EGL_FALSE;
    }

    return EGL_TRUE;
}

EGLBoolean initializeWindow(EGLNativeWindowType nativeWindow)
{
    // Get a display
    EGLDisplay display;
    if(initDisplay(&display) != EGL_TRUE)
        return EGL_FALSE;

    // Find workable config for display
    const EGLint configAttribs[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_DEPTH_SIZE, 24,
        EGL_NONE
    };

    EGLConfig config;
    EGLint numConfigs;
    if(!eglChooseConfig(display, configAttribs, &config, 1, &numConfigs)) {
        return EGL_FALSE;
    }

    // Create surface
    EGLSurface window = 
        eglCreateWindowSurface(display, config, nativeWindow, NULL);
    if(window == EGL_NO_SURFACE) { return EGL_FALSE; }

    // Create context
    const EGLint contextAttribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 3,
        EGL_NONE
    };
    EGLContext context = 
        eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs);
    if(context == EGL_NO_CONTEXT) { return EGL_FALSE; }
    if(!eglMakeCurrent(display, window, window, context)) { return EGL_FALSE; }

    return EGL_TRUE;
}

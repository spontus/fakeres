#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>

/* by: spontus */

void __attribute__ ((constructor)) load(void);

void load(void){
	printf(" -- libfakeres.so by spontus loaded --\n");
}

Status XGetGeometry(Display *display, Drawable d, Window *root_return, int *x_return, int *y_return, unsigned int *width_return, unsigned int *height_return, unsigned int *border_width_return, unsigned int *depth_return){
	typedef Status (*func)(Display *, Drawable, Window *, 	int *, int *, unsigned int *, unsigned int *, unsigned int *, 	unsigned int *);
	void *handle;
	Status s;
	handle = dlopen("libX11.so", RTLD_LAZY);
	func orig = dlsym(handle, "XGetGeometry");
	s = orig(display, d, root_return, x_return, y_return, width_return, height_return, border_width_return, depth_return);
	char* width = getenv("FAKE_RES_WIDTH");
	char* height = getenv("FAKE_RES_HEIGHT");
	unsigned int i_width = 800;
	unsigned int i_height = 600;	
        if(width != NULL){
                i_width = (unsigned int)atoi(width);
        }   
        if(height != NULL){
                i_height = (unsigned int)atoi(height);
        }   
	*width_return = i_width;
	*height_return = i_height;
	return s;
}



begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* x_.h */
end_comment

begin_comment
comment|/* Header for including X library calls in Ghostscript X11 driver */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/*   Names of external functions which contain upper case letters are  *   modified by the VMS GNU C compiler to prevent confusion between  *   names such as XOpen and xopen.  GNU C does this by translating a  *   name like XOpen into xopen_aaaaaaaax with "aaaaaaaa" a hexadecimal  *   string.  However, this causes problems when we link against the  *   X library which doesn't contain a routine named xopen_aaaaaaaax.  *   So, we use #define's to map all X routine names to lower case.  *   (Note that routines like BlackPixelOfScreen, which are [for VMS]  *   preprocessor macros, do not appear here.)  */
end_comment

begin_comment
comment|/*  * The names redefined here are those which the current Ghostscript X11  * driver happens to use: this list may grow in the future.  */
end_comment

begin_define
define|#
directive|define
name|XAllocColor
value|xalloccolor
end_define

begin_define
define|#
directive|define
name|XAllocNamedColor
value|xallocnamedcolor
end_define

begin_define
define|#
directive|define
name|XChangeProperty
value|xchangeproperty
end_define

begin_define
define|#
directive|define
name|XCloseDisplay
value|xclosedisplay
end_define

begin_define
define|#
directive|define
name|XCopyArea
value|xcopyarea
end_define

begin_define
define|#
directive|define
name|XCreateGC
value|xcreategc
end_define

begin_define
define|#
directive|define
name|XCreatePixmap
value|xcreatepixmap
end_define

begin_define
define|#
directive|define
name|XCreateWindow
value|xcreatewindow
end_define

begin_define
define|#
directive|define
name|XDisplayString
value|xdisplaystring
end_define

begin_define
define|#
directive|define
name|XDrawLine
value|xdrawline
end_define

begin_define
define|#
directive|define
name|XFillPolygon
value|xfillpolygon
end_define

begin_define
define|#
directive|define
name|XFillRectangle
value|xfillrectangle
end_define

begin_define
define|#
directive|define
name|XFillRectangles
value|xfillrectangles
end_define

begin_define
define|#
directive|define
name|XFlush
value|xflush
end_define

begin_define
define|#
directive|define
name|XFreeGC
value|xfreegc
end_define

begin_define
define|#
directive|define
name|XFreePixmap
value|xfreepixmap
end_define

begin_define
define|#
directive|define
name|XGeometry
value|xgeometry
end_define

begin_define
define|#
directive|define
name|XGetDefault
value|xgetdefault
end_define

begin_define
define|#
directive|define
name|XGetRGBColormaps
value|xgetrgbcolormaps
end_define

begin_define
define|#
directive|define
name|XGetVisualInfo
value|xgetvisualinfo
end_define

begin_define
define|#
directive|define
name|XGetWindowAttributes
value|xgetwindowattributes
end_define

begin_define
define|#
directive|define
name|XGetWindowProperty
value|xgetwindowproperty
end_define

begin_define
define|#
directive|define
name|XInternAtom
value|xinternatom
end_define

begin_define
define|#
directive|define
name|XMapWindow
value|xmapwindow
end_define

begin_define
define|#
directive|define
name|XNextEvent
value|xnextevent
end_define

begin_define
define|#
directive|define
name|XOpenDisplay
value|xopendisplay
end_define

begin_define
define|#
directive|define
name|XPutImage
value|xputimage
end_define

begin_define
define|#
directive|define
name|XSendEvent
value|xsendevent
end_define

begin_define
define|#
directive|define
name|XSetBackground
value|xsetbackground
end_define

begin_define
define|#
directive|define
name|XSetClipMask
value|xsetclipmask
end_define

begin_define
define|#
directive|define
name|XSetClipOrigin
value|xsetcliporigin
end_define

begin_define
define|#
directive|define
name|XSetFillStyle
value|xsetfillstyle
end_define

begin_define
define|#
directive|define
name|XSetForeground
value|xsetforeground
end_define

begin_define
define|#
directive|define
name|XSetFunction
value|xsetfunction
end_define

begin_define
define|#
directive|define
name|XSetLineAttributes
value|xsetlineattributes
end_define

begin_define
define|#
directive|define
name|XSetNormalHints
value|xsetnormalhints
end_define

begin_define
define|#
directive|define
name|XSetTile
value|xsettile
end_define

begin_define
define|#
directive|define
name|XSetWindowBackgroundPixmap
value|xsetwindowbackgroundpixmap
end_define

begin_define
define|#
directive|define
name|XSync
value|xsync
end_define

begin_define
define|#
directive|define
name|XVisualIDFromVisual
value|xvisualidfromvisual
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifdef __GNUC__ */
end_comment

begin_include
include|#
directive|include
file|<decw$include/Xlib.h>
end_include

begin_include
include|#
directive|include
file|<decw$include/Xatom.h>
end_include

begin_include
include|#
directive|include
file|<decw$include/Xutil.h>
end_include

begin_include
include|#
directive|include
file|<decw$include/Intrinsic.h>
end_include

begin_comment
comment|/* Include standard colormap stuff only for X11R4 and later. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XtSpecificationRelease
argument_list|)
operator|&&
operator|(
name|XtSpecificationRelease
operator|>=
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|HaveStdCMap
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !ifdef VMS */
end_comment

begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xatom.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include

begin_include
include|#
directive|include
file|<X11/Intrinsic.h>
end_include

begin_comment
comment|/* Include standard colormap stuff only for X11R4 and later. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XtSpecificationRelease
argument_list|)
operator|&&
operator|(
name|XtSpecificationRelease
operator|>=
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|HaveStdCMap
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HaveStdCMap
end_ifndef

begin_define
define|#
directive|define
name|HaveStdCMap
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit


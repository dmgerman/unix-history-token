begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Drawing.h,v 1.10 91/07/22 23:45:48 converse Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * The X Window System is a Trademark of MIT.  *  * The interfaces described by this header file are for miscellaneous utilities  * and are not part of the Xlib standard.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMU_DRAWING_H_
end_ifndef

begin_define
define|#
directive|define
name|_XMU_DRAWING_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_XtIntrinsic_h
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PIXEL_ALREADY_TYPEDEFED
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Pixel
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XmuDrawRoundedRectangle
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Drawable
comment|/* draw */
parameter_list|,
name|GC
comment|/* gc */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|int
comment|/* w */
parameter_list|,
name|int
comment|/* h */
parameter_list|,
name|int
comment|/* ew */
parameter_list|,
name|int
comment|/* eh */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmuFillRoundedRectangle
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Drawable
comment|/* draw */
parameter_list|,
name|GC
comment|/* gc */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|int
comment|/* w */
parameter_list|,
name|int
comment|/* h */
parameter_list|,
name|int
comment|/* ew */
parameter_list|,
name|int
comment|/* eh */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmuDrawLogo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|GC
comment|/* gcFore */
parameter_list|,
name|GC
comment|/* gcBack */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Pixmap
name|XmuCreatePixmapFromBitmap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|Pixmap
comment|/* bitmap */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
parameter_list|,
name|unsigned
name|long
comment|/* fore */
parameter_list|,
name|unsigned
name|long
comment|/* back */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Pixmap
name|XmuCreateStippledPixmap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
parameter_list|,
name|Pixel
comment|/* fore */
parameter_list|,
name|Pixel
comment|/* back */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmuReleaseStippledPixmap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
parameter_list|,
name|Pixmap
comment|/* pixmap */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Pixmap
name|XmuLocateBitmapFile
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* name */
parameter_list|,
name|char
modifier|*
comment|/* srcname_return */
parameter_list|,
name|int
comment|/* srcnamelen */
parameter_list|,
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|int
modifier|*
comment|/* height_return, */
parameter_list|,
name|int
modifier|*
comment|/* xhot_return */
parameter_list|,
name|int
modifier|*
comment|/* yhot_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Pixmap
name|XmuLocatePixmapFile
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* name */
parameter_list|,
name|unsigned
name|long
comment|/* fore */
parameter_list|,
name|unsigned
name|long
comment|/* back */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
parameter_list|,
name|char
modifier|*
comment|/* srcname_return */
parameter_list|,
name|int
comment|/* srcnamelen */
parameter_list|,
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|int
modifier|*
comment|/* height_return, */
parameter_list|,
name|int
modifier|*
comment|/* xhot_return */
parameter_list|,
name|int
modifier|*
comment|/* yhot_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XmuReadBitmapData
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|FILE
modifier|*
comment|/* fstream */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* height_return */
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
comment|/* datap_return */
parameter_list|,
name|int
modifier|*
comment|/* xhot_return */
parameter_list|,
name|int
modifier|*
comment|/* yhot_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XmuReadBitmapDataFromFile
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* filename */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* height_return */
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
comment|/* datap_return */
parameter_list|,
name|int
modifier|*
comment|/* xhot_return */
parameter_list|,
name|int
modifier|*
comment|/* yhot_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XMU_DRAWING_H_ */
end_comment

end_unit


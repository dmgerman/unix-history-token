begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: StdCmap.h,v 1.3 91/07/22 23:46:03 converse Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * The X Window System is a Trademark of MIT.  *  * The interfaces described by this header file are for miscellaneous utilities  * and are not part of the Xlib standard.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMU_STDCMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_XMU_STDCMAP_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_function_decl
name|_XFUNCPROTOBEGIN
name|Status
name|XmuAllStandardColormaps
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XmuCreateColormap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XStandardColormap
modifier|*
comment|/* colormap */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|XmuDeleteStandardColormap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
comment|/* screen */
parameter_list|,
name|Atom
comment|/* property */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XmuGetColormapAllocation
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XVisualInfo
modifier|*
comment|/* vinfo */
parameter_list|,
name|Atom
comment|/* property */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* red_max_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* green_max_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* blue_max_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XmuLookupStandardColormap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
comment|/* screen */
parameter_list|,
name|VisualID
comment|/* visualid */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
parameter_list|,
name|Atom
comment|/* property */
parameter_list|,
name|Bool
comment|/* replace */
parameter_list|,
name|Bool
comment|/* retain */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|XStandardColormap
modifier|*
name|XmuStandardColormap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
comment|/* screen */
parameter_list|,
name|VisualID
comment|/* visualid */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
parameter_list|,
name|Atom
comment|/* property */
parameter_list|,
name|Colormap
comment|/* cmap */
parameter_list|,
name|unsigned
name|long
comment|/* red_max */
parameter_list|,
name|unsigned
name|long
comment|/* green_max */
parameter_list|,
name|unsigned
name|long
comment|/* blue_max */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XmuVisualStandardColormaps
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
comment|/* screen */
parameter_list|,
name|VisualID
comment|/* visualid */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
parameter_list|,
name|Bool
comment|/* replace */
parameter_list|,
name|Bool
comment|/* retain */
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
comment|/* _XMU_STDCMAP_H_ */
end_comment

end_unit


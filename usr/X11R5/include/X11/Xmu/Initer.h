begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Initer.h,v 1.4 91/07/22 23:45:59 converse Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * The X Window System is a Trademark of MIT.  *  * The interfaces described by this header file are for miscellaneous utilities  * and are not part of the Xlib standard.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMU_INITER_H_
end_ifndef

begin_define
define|#
directive|define
name|_XMU_INITER_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XmuInitializerProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|caddr_t
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XmuCallInitializers
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmuAddInitializer
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XmuInitializerProc
comment|/* func */
parameter_list|,
name|caddr_t
comment|/* data */
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
comment|/* _XMU_INITER_H_ */
end_comment

end_unit


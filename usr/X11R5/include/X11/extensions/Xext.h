begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Xext.h,v 1.2 91/07/12 10:28:17 rws Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_XEXT_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_decl_stmt
name|_XFUNCPROTOBEGIN
specifier|extern
name|int
argument_list|(
operator|*
name|XSetExtensionErrorHandler
argument_list|()
argument_list|)
argument_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
argument_list|(
operator|*
name|handler
argument_list|)
argument_list|()
endif|#
directive|endif
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|XMissingExtension
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* ext_name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_define
define|#
directive|define
name|X_EXTENSION_UNKNOWN
value|"unknown"
end_define

begin_define
define|#
directive|define
name|X_EXTENSION_MISSING
value|"missing"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEXT_H_ */
end_comment

end_unit


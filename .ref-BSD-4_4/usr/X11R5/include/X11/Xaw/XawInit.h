begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XawInit.h,v 1.4 91/07/22 19:05:25 converse Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XawInitializeWidgetSet
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* called from ClassInit procs */
end_comment

begin_macro
name|_XFUNCPROTOEND
end_macro

end_unit


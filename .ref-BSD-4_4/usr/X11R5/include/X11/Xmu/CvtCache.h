begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: CvtCache.h,v 1.6 91/07/22 23:45:42 converse Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *   *			       Public Interfaces  *   * XmuCvtCache *XmuCvtCacheLookupDisplay (dpy)  *     Display *dpy;  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMU_CVTCACHE_H_
end_ifndef

begin_define
define|#
directive|define
name|_XMU_CVTCACHE_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xmu/DisplayQue.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_XmuCvtCache
block|{
struct|struct
block|{
name|char
modifier|*
modifier|*
name|bitmapFilePath
decl_stmt|;
block|}
name|string_to_bitmap
struct|;
comment|/* add other per-display data that needs to be cached */
block|}
name|XmuCvtCache
typedef|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|XmuCvtCache
modifier|*
name|_XmuCCLookupDisplay
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

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XMU_CVTCACHE_H_ */
end_comment

end_unit


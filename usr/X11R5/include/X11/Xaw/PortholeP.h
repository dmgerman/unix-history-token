begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: PortholeP.h,v 1.1 90/02/28 18:07:32 jim Exp $  *  * Copyright 1990 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author:  Jim Fulton, MIT X Consortium  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawPortholeP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawPortholeP_h
end_define

begin_include
include|#
directive|include
file|<X11/CompositeP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Porthole.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* new fields in widget class */
name|int
name|dummy
decl_stmt|;
block|}
name|PortholeClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PortholeClassRec
block|{
comment|/* Porthole widget class */
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|PortholeClassPart
name|porthole_class
decl_stmt|;
block|}
name|PortholeClassRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* new fields in widget */
comment|/* resources... */
name|XtCallbackList
name|report_callbacks
decl_stmt|;
comment|/* callback/Callback */
comment|/* private data... */
block|}
name|PortholePart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PortholeRec
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|PortholePart
name|porthole
decl_stmt|;
block|}
name|PortholeRec
typedef|;
end_typedef

begin_comment
comment|/*  * external declarations  */
end_comment

begin_decl_stmt
specifier|extern
name|PortholeClassRec
name|portholeClassRec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawPortholeP_h */
end_comment

end_unit


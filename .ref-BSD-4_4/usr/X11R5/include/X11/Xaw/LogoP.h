begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: LogoP.h,v 1.9 90/10/22 14:45:51 converse Exp $ */
end_comment

begin_comment
comment|/* Copyright 1988 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission. M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawLogoP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawLogoP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Logo.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleP.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pixel
name|fgpixel
decl_stmt|;
name|GC
name|foreGC
decl_stmt|;
name|GC
name|backGC
decl_stmt|;
name|Boolean
name|shape_window
decl_stmt|;
name|Boolean
name|need_shaping
decl_stmt|;
block|}
name|LogoPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_LogoRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|LogoPart
name|logo
decl_stmt|;
block|}
name|LogoRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|dummy
decl_stmt|;
block|}
name|LogoClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_LogoClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|LogoClassPart
name|logo_class
decl_stmt|;
block|}
name|LogoClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|LogoClassRec
name|logoClassRec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawLogoP_h */
end_comment

end_unit


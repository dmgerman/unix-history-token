begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Xmu.h,v 1.26 89/07/16 14:12:37 jim Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * The X Window System is a Trademark of MIT.  *  * The interfaces described by this header file are for miscellaneous utilities  * and are not part of the Xlib standard.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMU_H_
end_ifndef

begin_define
define|#
directive|define
name|_XMU_H_
end_define

begin_comment
comment|/*  * This include file is obsolete and is provided only for compatibility with  * MIT Release 3 clients.  Callers should use the appropriate include file.    *  * DO NOT ADD ANY NEW INCLUDES OR DEFINITIONS TO THIS FILE!  */
end_comment

begin_include
include|#
directive|include
file|<X11/Intrinsic.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xmu/Atoms.h>
end_include

begin_comment
comment|/* _XA_... */
end_comment

begin_include
include|#
directive|include
file|<X11/Xmu/CharSet.h>
end_include

begin_comment
comment|/* CopyISOLatin1Lowered */
end_comment

begin_include
include|#
directive|include
file|<X11/Xmu/Converters.h>
end_include

begin_comment
comment|/* CvtStringTo... */
end_comment

begin_include
include|#
directive|include
file|<X11/Xmu/Drawing.h>
end_include

begin_comment
comment|/* DrawRoundedRect, DrawLogo */
end_comment

begin_include
include|#
directive|include
file|<X11/Xmu/Error.h>
end_include

begin_comment
comment|/* PrintDefaultError */
end_comment

begin_include
include|#
directive|include
file|<X11/Xmu/StdSel.h>
end_include

begin_comment
comment|/* ConvertStandardSelection */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XMU_H_ */
end_comment

end_unit


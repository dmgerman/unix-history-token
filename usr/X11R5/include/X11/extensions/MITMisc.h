begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************ Copyright 1989 by The Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright no- tice appear in all copies and that both that copyright no- tice and this permission notice appear in supporting docu- mentation, and that the name of MIT not be used in advertising or publicity pertaining to distribution of the software without specific prior written permission. M.I.T. makes no representation about the suitability of this software for any purpose. It is provided "as is" without any express or implied warranty.  ********************************************************/
end_comment

begin_comment
comment|/* RANDOM CRUFT! THIS HAS NO OFFICIAL X CONSORTIUM BLESSING */
end_comment

begin_comment
comment|/* $XConsortium: MITMisc.h,v 1.4 91/07/12 10:06:43 rws Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMITMISC_H_
end_ifndef

begin_define
define|#
directive|define
name|_XMITMISC_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_define
define|#
directive|define
name|X_MITSetBugMode
value|0
end_define

begin_define
define|#
directive|define
name|X_MITGetBugMode
value|1
end_define

begin_define
define|#
directive|define
name|MITMiscNumberEvents
value|0
end_define

begin_define
define|#
directive|define
name|MITMiscNumberErrors
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_MITMISC_SERVER_
end_ifndef

begin_function_decl
name|_XFUNCPROTOBEGIN
name|Bool
name|XMITMiscQueryExtension
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
modifier|*
comment|/* event_basep */
parameter_list|,
name|int
modifier|*
comment|/* error_basep */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XMITMiscSetBugMode
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Bool
comment|/* onOff */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Bool
name|XMITMiscGetBugMode
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

begin_endif
endif|#
directive|endif
end_endif

end_unit


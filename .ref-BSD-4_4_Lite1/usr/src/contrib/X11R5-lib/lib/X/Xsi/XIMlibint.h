begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: XIMlibint.h,v 1.13 92/07/29 13:55:45 rws Exp $  */
end_comment

begin_comment
comment|/*  * Copyright 1990, 1991 by OMRON Corporation  * Copyright 1991 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the names of OMRON and MIT not be used in  * advertising or publicity pertaining to distribution of the software without  * specific, written prior permission.  OMRON and MIT make no representations  * about the suitability of this software for any purpose.  It is provided  * "as is" without express or implied warranty.  *  * OMRON AND MIT DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO  * EVENT SHALL OMRON OR MIT BE LIABLE FOR ANY SPECIAL, INDIRECT OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER  * TORTUOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.   *  *	Author:	Seiji Kuwari	OMRON Corporation  *				kuwa@omron.co.jp  *				kuwa%omron.co.jp@uunet.uu.net  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XIMLIBINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_XIMLIBINT_H_
end_define

begin_include
include|#
directive|include
file|"XIMproto.h"
end_include

begin_define
define|#
directive|define
name|XIM_INPUTMETHOD
value|"_XIM_INPUTMETHOD"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ESC
end_ifndef

begin_define
define|#
directive|define
name|ESC
value|0x1b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ESC */
end_comment

begin_define
define|#
directive|define
name|ASCII_DESIGNATE
value|"\033\050\102"
end_define

begin_define
define|#
directive|define
name|hname_size
value|128
end_define

begin_define
define|#
directive|define
name|offset_of_portnumber
value|hname_size
end_define

begin_define
define|#
directive|define
name|portnumber_size
value|2
end_define

begin_define
define|#
directive|define
name|offset_of_version
value|(offset_of_portnumber + portnumber_size)
end_define

begin_define
define|#
directive|define
name|version_size
value|4
end_define

begin_define
define|#
directive|define
name|offset_of_minor_version
value|(offset_of_version + version_size)
end_define

begin_define
define|#
directive|define
name|ipIMofIC
parameter_list|(
name|ic
parameter_list|)
value|((XipIM)ic->core.im)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_LOCAL_IM
end_ifndef

begin_define
define|#
directive|define
name|ipLocalIMofIC
parameter_list|(
name|ic
parameter_list|)
value|((XipLocalIM)ic->core.im)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|short
name|_XipTypeOfNextICQueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|KeySym
name|_XipKeySymOfNextICQueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|_XipStateOfNextICQueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_XipStringOfNextICQueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XipFreeNextICQueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XipPutICQueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XipGetNextICQueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XipFreeAllICQueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XipSaveOverflowICQueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XipGetOverflowICQueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XipWriteToIM
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XipReadFromIM
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XipFlushToIM
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XipSetCurSock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XipSetCurIM
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XipConnectIM
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XipDisconnectIM
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XipCallCallbacks
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XipBackEndFilter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|_XipReceiveICValues
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XipSendICValues
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XipCreateDefIC
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_XipICSetAttrValues
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_XipICSetValues
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_XipICGetValues
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NO_LOCAL_IM
end_ifndef

begin_function_decl
specifier|extern
name|Bool
name|_XipBackEndFilter
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XML
end_ifdef

begin_function_decl
specifier|extern
name|void
name|_XipChangeLocale
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XML */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XIMLIBINT_H_ */
end_comment

end_unit


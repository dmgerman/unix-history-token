begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// * This makes emacs happy -*-Mode: C++;-*-
end_comment

begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,2000 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author: Juergen Pfeifer<juergen.pfeifer@gmx.net> 1997                 *  ****************************************************************************/
end_comment

begin_comment
comment|// $Id: internal.h,v 1.6 2000/09/02 18:22:23 tom Exp $
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPLUS_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|_CPLUS_INTERNAL_H
value|1
end_define

begin_if
if|#
directive|if
name|USE_RCS_IDS
end_if

begin_define
define|#
directive|define
name|MODULE_ID
parameter_list|(
name|id
parameter_list|)
value|static const char Ident[] = id;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MODULE_ID
parameter_list|(
name|id
parameter_list|)
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1f)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit


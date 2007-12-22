begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2002,2003 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: eti.h,v 1.8 2003/10/25 15:24:29 tom Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NCURSES_ETI_H_incl
end_ifndef

begin_define
define|#
directive|define
name|NCURSES_ETI_H_incl
value|1
end_define

begin_define
define|#
directive|define
name|E_OK
value|(0)
end_define

begin_define
define|#
directive|define
name|E_SYSTEM_ERROR
value|(-1)
end_define

begin_define
define|#
directive|define
name|E_BAD_ARGUMENT
value|(-2)
end_define

begin_define
define|#
directive|define
name|E_POSTED
value|(-3)
end_define

begin_define
define|#
directive|define
name|E_CONNECTED
value|(-4)
end_define

begin_define
define|#
directive|define
name|E_BAD_STATE
value|(-5)
end_define

begin_define
define|#
directive|define
name|E_NO_ROOM
value|(-6)
end_define

begin_define
define|#
directive|define
name|E_NOT_POSTED
value|(-7)
end_define

begin_define
define|#
directive|define
name|E_UNKNOWN_COMMAND
value|(-8)
end_define

begin_define
define|#
directive|define
name|E_NO_MATCH
value|(-9)
end_define

begin_define
define|#
directive|define
name|E_NOT_SELECTABLE
value|(-10)
end_define

begin_define
define|#
directive|define
name|E_NOT_CONNECTED
value|(-11)
end_define

begin_define
define|#
directive|define
name|E_REQUEST_DENIED
value|(-12)
end_define

begin_define
define|#
directive|define
name|E_INVALID_FIELD
value|(-13)
end_define

begin_define
define|#
directive|define
name|E_CURRENT
value|(-14)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit


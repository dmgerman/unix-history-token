begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Common macros for lib_getch.c, lib_ungetch.c  *  * $Id: fifo_defs.h,v 1.2 1998/02/11 12:13:56 tom Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FIFO_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|FIFO_DEFS_H
value|1
end_define

begin_define
define|#
directive|define
name|head
value|SP->_fifohead
end_define

begin_define
define|#
directive|define
name|tail
value|SP->_fifotail
end_define

begin_comment
comment|/* peek points to next uninterpreted character */
end_comment

begin_define
define|#
directive|define
name|peek
value|SP->_fifopeek
end_define

begin_define
define|#
directive|define
name|h_inc
parameter_list|()
value|{ head == FIFO_SIZE-1 ? head = 0 : head++; if (head == tail) head = -1, tail = 0;}
end_define

begin_define
define|#
directive|define
name|h_dec
parameter_list|()
value|{ head == 0 ?  head = FIFO_SIZE-1 : head--; if (head == tail) tail = -1;}
end_define

begin_define
define|#
directive|define
name|t_inc
parameter_list|()
value|{ tail == FIFO_SIZE-1 ? tail = 0 : tail++; if (tail == head) tail = -1;}
end_define

begin_define
define|#
directive|define
name|t_dec
parameter_list|()
value|{ tail == 0 ?  tail = FIFO_SIZE-1 : tail--; if (head == tail) fifo_clear();}
end_define

begin_define
define|#
directive|define
name|p_inc
parameter_list|()
value|{ peek == FIFO_SIZE-1 ? peek = 0 : peek++;}
end_define

begin_define
define|#
directive|define
name|cooked_key_in_fifo
parameter_list|()
value|(head!=-1&& peek!=head)
end_define

begin_define
define|#
directive|define
name|raw_key_in_fifo
parameter_list|()
value|(head!=-1&& peek!=tail)
end_define

begin_undef
undef|#
directive|undef
name|HIDE_EINTR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIFO_DEFS_H */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Mark Nudleman  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)less.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NULL_POSITION
value|((off_t)(-1))
end_define

begin_define
define|#
directive|define
name|EOI
value|(0)
end_define

begin_define
define|#
directive|define
name|READ_INTR
value|(-2)
end_define

begin_define
define|#
directive|define
name|NO_HORIZ_OFF
value|(-1)
end_define

begin_comment
comment|/* Wrap lines like normal */
end_comment

begin_comment
comment|/* Special chars used to tell put_line() to do something special */
end_comment

begin_define
define|#
directive|define
name|UL_CHAR
value|'\201'
end_define

begin_comment
comment|/* Enter underline mode */
end_comment

begin_define
define|#
directive|define
name|UE_CHAR
value|'\202'
end_define

begin_comment
comment|/* Exit underline mode */
end_comment

begin_define
define|#
directive|define
name|BO_CHAR
value|'\203'
end_define

begin_comment
comment|/* Enter boldface mode */
end_comment

begin_define
define|#
directive|define
name|BE_CHAR
value|'\204'
end_define

begin_comment
comment|/* Exit boldface mode */
end_comment

begin_define
define|#
directive|define
name|CONTROL_CHAR
parameter_list|(
name|c
parameter_list|)
value|(!isprint(c))
end_define

begin_define
define|#
directive|define
name|CARAT_CHAR
parameter_list|(
name|c
parameter_list|)
value|((c == '\177') ? '?' : (c | 0100))
end_define

begin_define
define|#
directive|define
name|TOP
value|(0)
end_define

begin_define
define|#
directive|define
name|TOP_PLUS_ONE
value|(1)
end_define

begin_define
define|#
directive|define
name|BOTTOM
value|(-1)
end_define

begin_define
define|#
directive|define
name|BOTTOM_PLUS_ONE
value|(-2)
end_define

begin_define
define|#
directive|define
name|MIDDLE
value|(-3)
end_define

begin_define
define|#
directive|define
name|A_INVALID
value|-1
end_define

begin_define
define|#
directive|define
name|A_AGAIN_SEARCH
value|1
end_define

begin_define
define|#
directive|define
name|A_B_LINE
value|2
end_define

begin_define
define|#
directive|define
name|A_B_SCREEN
value|3
end_define

begin_define
define|#
directive|define
name|A_B_SCROLL
value|4
end_define

begin_define
define|#
directive|define
name|A_B_SEARCH
value|5
end_define

begin_define
define|#
directive|define
name|A_DIGIT
value|6
end_define

begin_define
define|#
directive|define
name|A_EXAMINE
value|7
end_define

begin_define
define|#
directive|define
name|A_FREPAINT
value|8
end_define

begin_define
define|#
directive|define
name|A_F_LINE
value|9
end_define

begin_define
define|#
directive|define
name|A_F_SCREEN
value|10
end_define

begin_define
define|#
directive|define
name|A_F_SCROLL
value|11
end_define

begin_define
define|#
directive|define
name|A_F_SEARCH
value|12
end_define

begin_define
define|#
directive|define
name|A_GOEND
value|13
end_define

begin_define
define|#
directive|define
name|A_GOLINE
value|14
end_define

begin_define
define|#
directive|define
name|A_GOMARK
value|15
end_define

begin_define
define|#
directive|define
name|A_HELP
value|16
end_define

begin_define
define|#
directive|define
name|A_NEXT_FILE
value|17
end_define

begin_define
define|#
directive|define
name|A_PERCENT
value|18
end_define

begin_define
define|#
directive|define
name|A_PREFIX
value|19
end_define

begin_define
define|#
directive|define
name|A_PREV_FILE
value|20
end_define

begin_define
define|#
directive|define
name|A_QUIT
value|21
end_define

begin_define
define|#
directive|define
name|A_REPAINT
value|22
end_define

begin_define
define|#
directive|define
name|A_SETMARK
value|23
end_define

begin_define
define|#
directive|define
name|A_STAT
value|24
end_define

begin_define
define|#
directive|define
name|A_VISUAL
value|25
end_define

begin_define
define|#
directive|define
name|A_TAGFILE
value|26
end_define

begin_define
define|#
directive|define
name|A_FILE_LIST
value|27
end_define

begin_define
define|#
directive|define
name|A_L_COL
value|28
end_define

begin_define
define|#
directive|define
name|A_R_COL
value|29
end_define

begin_define
define|#
directive|define
name|A_HOME
value|30
end_define

begin_define
define|#
directive|define
name|A_NEXTTAG
value|31
end_define

begin_define
define|#
directive|define
name|A_PREVTAG
value|32
end_define

end_unit


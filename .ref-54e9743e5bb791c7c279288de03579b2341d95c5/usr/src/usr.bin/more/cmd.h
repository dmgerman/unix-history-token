begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Mark Nudleman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Mark Nudleman and the University of California, Berkeley.  The  * name of Mark Nudleman or the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)cmd.h	5.3 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|MAX_USERCMD
value|200
end_define

begin_define
define|#
directive|define
name|MAX_CMDLEN
value|16
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
name|A_DISP_OPTION
value|7
end_define

begin_define
define|#
directive|define
name|A_DEBUG
value|8
end_define

begin_define
define|#
directive|define
name|A_EXAMINE
value|9
end_define

begin_define
define|#
directive|define
name|A_FIRSTCMD
value|10
end_define

begin_define
define|#
directive|define
name|A_FREPAINT
value|11
end_define

begin_define
define|#
directive|define
name|A_F_LINE
value|12
end_define

begin_define
define|#
directive|define
name|A_F_SCREEN
value|13
end_define

begin_define
define|#
directive|define
name|A_F_SCROLL
value|14
end_define

begin_define
define|#
directive|define
name|A_F_SEARCH
value|15
end_define

begin_define
define|#
directive|define
name|A_GOEND
value|16
end_define

begin_define
define|#
directive|define
name|A_GOLINE
value|17
end_define

begin_define
define|#
directive|define
name|A_GOMARK
value|18
end_define

begin_define
define|#
directive|define
name|A_HELP
value|19
end_define

begin_define
define|#
directive|define
name|A_NEXT_FILE
value|20
end_define

begin_define
define|#
directive|define
name|A_PERCENT
value|21
end_define

begin_define
define|#
directive|define
name|A_PREFIX
value|22
end_define

begin_define
define|#
directive|define
name|A_PREV_FILE
value|23
end_define

begin_define
define|#
directive|define
name|A_QUIT
value|24
end_define

begin_define
define|#
directive|define
name|A_REPAINT
value|25
end_define

begin_define
define|#
directive|define
name|A_SETMARK
value|26
end_define

begin_define
define|#
directive|define
name|A_SHELL
value|27
end_define

begin_define
define|#
directive|define
name|A_STAT
value|28
end_define

begin_define
define|#
directive|define
name|A_TOGGLE_OPTION
value|30
end_define

begin_define
define|#
directive|define
name|A_VISUAL
value|32
end_define

begin_define
define|#
directive|define
name|A_INVALID
value|100
end_define

begin_define
define|#
directive|define
name|A_NOACTION
value|101
end_define

end_unit


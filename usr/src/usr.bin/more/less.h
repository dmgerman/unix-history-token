begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Mark Nudleman  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)less.h	8.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|RECOMP
end_define

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
value|(iscntrl(c))
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

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)win_st.c	6.2 (Berkeley) 3/17/89  */
end_comment

begin_define
define|#
directive|define
name|WINDOW
value|struct _win_st
end_define

begin_struct
struct|struct
name|_win_st
block|{
name|short
name|_cury
decl_stmt|,
name|_curx
decl_stmt|;
name|short
name|_maxy
decl_stmt|,
name|_maxx
decl_stmt|;
name|short
name|_begy
decl_stmt|,
name|_begx
decl_stmt|;
name|short
name|_flags
decl_stmt|;
name|short
name|_ch_off
decl_stmt|;
name|bool
name|_clear
decl_stmt|;
name|bool
name|_leave
decl_stmt|;
name|bool
name|_scroll
decl_stmt|;
name|char
modifier|*
modifier|*
name|_y
decl_stmt|;
name|short
modifier|*
name|_firstch
decl_stmt|;
name|short
modifier|*
name|_lastch
decl_stmt|;
name|struct
name|_win_st
modifier|*
name|_nextp
decl_stmt|,
modifier|*
name|_orig
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_ENDLINE
value|001
end_define

begin_define
define|#
directive|define
name|_FULLWIN
value|002
end_define

begin_define
define|#
directive|define
name|_SCROLLWIN
value|004
end_define

begin_define
define|#
directive|define
name|_FLUSH
value|010
end_define

begin_define
define|#
directive|define
name|_FULLLINE
value|020
end_define

begin_define
define|#
directive|define
name|_IDLINE
value|040
end_define

begin_define
define|#
directive|define
name|_STANDOUT
value|0200
end_define

begin_define
define|#
directive|define
name|_NOCHANGE
value|-1
end_define

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)locate.h	5.3 (Berkeley) 6/1/90  */
end_comment

begin_comment
comment|/* Symbolic constants shared by locate.c and code.c */
end_comment

begin_define
define|#
directive|define
name|NBG
value|128
end_define

begin_comment
comment|/* number of bigrams considered */
end_comment

begin_define
define|#
directive|define
name|OFFSET
value|14
end_define

begin_comment
comment|/* abs value of max likely diff */
end_comment

begin_define
define|#
directive|define
name|PARITY
value|0200
end_define

begin_comment
comment|/* parity bit */
end_comment

begin_define
define|#
directive|define
name|SWITCH
value|30
end_define

begin_comment
comment|/* switch code */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)locate.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Symbolic constants shared by find.c and code.c */
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


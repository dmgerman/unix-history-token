begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ctype.h	5.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|_U
value|0x01
end_define

begin_define
define|#
directive|define
name|_L
value|0x02
end_define

begin_define
define|#
directive|define
name|_N
value|0x04
end_define

begin_define
define|#
directive|define
name|_S
value|0x08
end_define

begin_define
define|#
directive|define
name|_P
value|0x10
end_define

begin_define
define|#
directive|define
name|_C
value|0x20
end_define

begin_define
define|#
directive|define
name|_X
value|0x40
end_define

begin_define
define|#
directive|define
name|_B
value|0x80
end_define

begin_decl_stmt
specifier|extern
name|char
name|_ctype_
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& _N)
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& _L)
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& _S)
end_define

begin_define
define|#
directive|define
name|ispunct
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& _P)
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& _U)
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& (_U|_L))
end_define

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& (_N|_X))
end_define

begin_define
define|#
directive|define
name|isalnum
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& (_U|_L|_N))
end_define

begin_define
define|#
directive|define
name|isprint
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& (_P|_U|_L|_N|_B))
end_define

begin_define
define|#
directive|define
name|isgraph
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& (_P|_U|_L|_N))
end_define

begin_define
define|#
directive|define
name|iscntrl
parameter_list|(
name|c
parameter_list|)
value|((_ctype_ + 1)[c]& _C)
end_define

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|((unsigned)(c)<= 0177)
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|((c) - 'a' + 'A')
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|((c) - 'A' + 'a')
end_define

begin_define
define|#
directive|define
name|toascii
parameter_list|(
name|c
parameter_list|)
value|((c)& 0177)
end_define

end_unit


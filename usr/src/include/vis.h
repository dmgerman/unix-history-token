begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)vis.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * vis flags  */
end_comment

begin_comment
comment|/*  * to select alternate encoding format  */
end_comment

begin_define
define|#
directive|define
name|VIS_OCTAL
value|0x01
end_define

begin_comment
comment|/* use octal \ddd format */
end_comment

begin_define
define|#
directive|define
name|VIS_CSTYLE
value|0x02
end_define

begin_comment
comment|/* use \[nrft...] where appropiate */
end_comment

begin_comment
comment|/*  * to alter set of characters encoded  * (default is to encode all non-graphic except space, tab, and newline)  */
end_comment

begin_define
define|#
directive|define
name|VIS_TAB
value|0x04
end_define

begin_comment
comment|/* also encode tab */
end_comment

begin_define
define|#
directive|define
name|VIS_WHITE
value|0x08
end_define

begin_comment
comment|/* also encode space, tab, and newline */
end_comment

begin_define
define|#
directive|define
name|VIS_SAFE
value|0x10
end_define

begin_comment
comment|/* only encode "unsafe" characters */
end_comment

begin_comment
comment|/*  * other  */
end_comment

begin_define
define|#
directive|define
name|VIS_NOSLASH
value|0x20
end_define

begin_comment
comment|/* inhibit printing '\' */
end_comment

begin_define
define|#
directive|define
name|VIS_NEXTC
value|0x40
end_define

begin_comment
comment|/* nextc character is valid */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|cvis
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * unvis flags  */
end_comment

begin_define
define|#
directive|define
name|UNVIS_HAT
value|0x01
end_define

begin_comment
comment|/* treat ^ as special */
end_comment

begin_define
define|#
directive|define
name|UNVIS_END
value|0x02
end_define

begin_comment
comment|/* reset decode machine */
end_comment

begin_comment
comment|/*  * return codes  */
end_comment

begin_define
define|#
directive|define
name|UNVIS_NEEDMORE
value|0
end_define

begin_comment
comment|/* not done, feed another char */
end_comment

begin_define
define|#
directive|define
name|UNVIS_OK
value|1
end_define

begin_comment
comment|/* done, character ready */
end_comment

begin_define
define|#
directive|define
name|UNVIS_OKPUSH
value|2
end_define

begin_comment
comment|/* done, push back passed char */
end_comment

begin_define
define|#
directive|define
name|UNVIS_NOCHAR
value|3
end_define

begin_comment
comment|/* done, no character ready (hidden newline) */
end_comment

begin_define
define|#
directive|define
name|UNVIS_SYNBAD
value|-1
end_define

begin_comment
comment|/* unrecognized escape sequence */
end_comment

end_unit


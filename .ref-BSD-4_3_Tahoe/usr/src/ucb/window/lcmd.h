begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)lcmd.h	3.7 (Berkeley) 6/29/88  */
end_comment

begin_define
define|#
directive|define
name|LCMD_NARG
value|20
end_define

begin_comment
comment|/* maximum number of arguments */
end_comment

begin_struct
struct|struct
name|lcmd_tab
block|{
name|char
modifier|*
name|lc_name
decl_stmt|;
name|int
name|lc_minlen
decl_stmt|;
name|int
function_decl|(
modifier|*
name|lc_func
function_decl|)
parameter_list|()
function_decl|;
name|struct
name|lcmd_arg
modifier|*
name|lc_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lcmd_arg
block|{
name|char
modifier|*
name|arg_name
decl_stmt|;
name|int
name|arg_minlen
decl_stmt|;
name|int
name|arg_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* arg_flags bits */
end_comment

begin_define
define|#
directive|define
name|ARG_TYPE
value|0x0f
end_define

begin_comment
comment|/* type of arg */
end_comment

begin_define
define|#
directive|define
name|ARG_ANY
value|0x00
end_define

begin_comment
comment|/* any type */
end_comment

begin_define
define|#
directive|define
name|ARG_NUM
value|0x01
end_define

begin_comment
comment|/* must be a number */
end_comment

begin_define
define|#
directive|define
name|ARG_STR
value|0x02
end_define

begin_comment
comment|/* must be a string */
end_comment

begin_define
define|#
directive|define
name|ARG_LIST
value|0x10
end_define

begin_comment
comment|/* this arg can be a list */
end_comment

begin_function_decl
name|struct
name|lcmd_tab
modifier|*
name|lcmd_lookup
parameter_list|()
function_decl|;
end_function_decl

end_unit


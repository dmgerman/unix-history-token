begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)var.h	3.11 (Berkeley) 6/6/90  */
end_comment

begin_struct
struct|struct
name|var
block|{
name|struct
name|var
modifier|*
name|r_left
decl_stmt|;
name|struct
name|var
modifier|*
name|r_right
decl_stmt|;
name|char
modifier|*
name|r_name
decl_stmt|;
name|struct
name|value
name|r_val
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|var
modifier|*
name|var_set1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|var
modifier|*
name|var_setstr1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|var
modifier|*
name|var_setnum1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|var
modifier|*
modifier|*
name|var_lookup1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|var_set
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|var_set1(&var_head, n, v)
end_define

begin_define
define|#
directive|define
name|var_setstr
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|var_setstr1(&var_head, n, s)
end_define

begin_define
define|#
directive|define
name|var_setnum
parameter_list|(
name|n
parameter_list|,
name|i
parameter_list|)
value|var_setnum1(&var_head, n, i)
end_define

begin_define
define|#
directive|define
name|var_unset
parameter_list|(
name|n
parameter_list|)
value|var_unset1(&var_head, n)
end_define

begin_define
define|#
directive|define
name|var_lookup
parameter_list|(
name|n
parameter_list|)
value|(*var_lookup1(&var_head, n))
end_define

begin_define
define|#
directive|define
name|var_walk
parameter_list|(
name|f
parameter_list|,
name|a
parameter_list|)
value|var_walk1(var_head, f, a)
end_define

begin_decl_stmt
name|struct
name|var
modifier|*
name|var_head
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* secret, shhh */
end_comment

end_unit


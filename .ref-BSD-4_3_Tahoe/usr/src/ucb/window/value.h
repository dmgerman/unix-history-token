begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)value.h	3.7 (Berkeley) 6/29/88  */
end_comment

begin_struct
struct|struct
name|value
block|{
name|char
name|v_type
decl_stmt|;
union|union
block|{
name|int
name|V_num
decl_stmt|;
name|char
modifier|*
name|V_str
decl_stmt|;
block|}
name|v_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|v_num
value|v_un.V_num
end_define

begin_define
define|#
directive|define
name|v_str
value|v_un.V_str
end_define

begin_define
define|#
directive|define
name|V_NUM
value|1
end_define

begin_define
define|#
directive|define
name|V_STR
value|2
end_define

begin_define
define|#
directive|define
name|V_ERR
value|3
end_define

begin_define
define|#
directive|define
name|val_free
parameter_list|(
name|v
parameter_list|)
value|((v).v_type == V_STR ? str_free((v).v_str) : 0)
end_define

end_unit


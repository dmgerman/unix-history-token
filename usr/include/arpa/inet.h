begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)inet.h	5.2 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * External definitions for  * functions in inet(3N)  */
end_comment

begin_function_decl
name|unsigned
name|long
name|inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inet_ntoa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|inet_makeaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|inet_network
parameter_list|()
function_decl|;
end_function_decl

end_unit


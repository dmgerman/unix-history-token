begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)htable.h	5.3 (Berkeley) 6/18/88  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/*  * common definitions for htable  */
end_comment

begin_struct
struct|struct
name|addr
block|{
name|struct
name|in_addr
name|addr_val
decl_stmt|;
name|struct
name|addr
modifier|*
name|addr_link
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|name
block|{
name|char
modifier|*
name|name_val
decl_stmt|;
name|struct
name|name
modifier|*
name|name_link
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gateway
block|{
name|struct
name|gateway
modifier|*
name|g_link
decl_stmt|;
name|struct
name|gateway
modifier|*
name|g_dst
decl_stmt|;
comment|/* connected gateway if metric> 0 */
name|struct
name|gateway
modifier|*
name|g_firstent
decl_stmt|;
comment|/* first entry for this gateway */
name|struct
name|name
modifier|*
name|g_name
decl_stmt|;
name|int
name|g_net
decl_stmt|;
name|struct
name|in_addr
name|g_addr
decl_stmt|;
comment|/* address on g_net */
name|int
name|g_metric
decl_stmt|;
comment|/* hops to this net */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NOADDR
value|((struct addr *)0)
end_define

begin_define
define|#
directive|define
name|NONAME
value|((struct name *)0)
end_define

begin_define
define|#
directive|define
name|KW_NET
value|1
end_define

begin_define
define|#
directive|define
name|KW_GATEWAY
value|2
end_define

begin_define
define|#
directive|define
name|KW_HOST
value|3
end_define

begin_function_decl
name|struct
name|name
modifier|*
name|newname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|infile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input file name */
end_comment

end_unit


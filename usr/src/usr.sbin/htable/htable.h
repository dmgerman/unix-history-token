begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)htable.h	5.5 (Berkeley) 2/6/91  */
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


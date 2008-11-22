begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rt_msghdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|ROUTE_STATIC
value|0x0000
end_define

begin_define
define|#
directive|define
name|ROUTE_DSTMYADDR
value|0x0001
end_define

begin_define
define|#
directive|define
name|ROUTE_DSTMYADDR6
value|0x0002
end_define

begin_define
define|#
directive|define
name|ROUTE_DSTHISADDR
value|0x0004
end_define

begin_define
define|#
directive|define
name|ROUTE_DSTHISADDR6
value|0x0008
end_define

begin_define
define|#
directive|define
name|ROUTE_DSTDNS0
value|0x0010
end_define

begin_define
define|#
directive|define
name|ROUTE_DSTDNS1
value|0x0020
end_define

begin_define
define|#
directive|define
name|ROUTE_DSTANY
value|0x0040
end_define

begin_define
define|#
directive|define
name|ROUTE_GWHISADDR
value|0x0080
end_define

begin_comment
comment|/* May be ORd with DST_* */
end_comment

begin_define
define|#
directive|define
name|ROUTE_GWHISADDR6
value|0x0100
end_define

begin_comment
comment|/* May be ORd with DST_* */
end_comment

begin_struct
struct|struct
name|sticky_route
block|{
name|int
name|type
decl_stmt|;
comment|/* ROUTE_* value (not _STATIC) */
name|struct
name|sticky_route
modifier|*
name|next
decl_stmt|;
comment|/* next in list */
name|struct
name|ncprange
name|dst
decl_stmt|;
name|struct
name|ncpaddr
name|gw
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|GetIfIndex
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|route_Show
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|route_IfDelete
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|route_UpdateMTU
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|Index2Nam
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|route_Change
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|sticky_route
modifier|*
parameter_list|,
specifier|const
name|struct
name|ncpaddr
modifier|*
parameter_list|,
specifier|const
name|struct
name|ncpaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|route_Add
parameter_list|(
name|struct
name|sticky_route
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|ncprange
modifier|*
parameter_list|,
specifier|const
name|struct
name|ncpaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|route_Delete
parameter_list|(
name|struct
name|sticky_route
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|ncprange
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|route_DeleteAll
parameter_list|(
name|struct
name|sticky_route
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|route_Clean
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|sticky_route
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|route_ShowSticky
parameter_list|(
name|struct
name|prompt
modifier|*
parameter_list|,
name|struct
name|sticky_route
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|route_ParseHdr
parameter_list|(
name|struct
name|rt_msghdr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
type|[
function_decl|RTAX_MAX]
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|rt_Set
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|ncprange
modifier|*
parameter_list|,
specifier|const
name|struct
name|ncpaddr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rt_Update
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit


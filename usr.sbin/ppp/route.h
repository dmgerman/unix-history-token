begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *			User Process PPP  *  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan, Inc.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  */
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

begin_define
define|#
directive|define
name|ROUTE_STATIC
value|0
end_define

begin_define
define|#
directive|define
name|ROUTE_DSTMYADDR
value|1
end_define

begin_define
define|#
directive|define
name|ROUTE_DSTHISADDR
value|2
end_define

begin_define
define|#
directive|define
name|ROUTE_DSTANY
value|3
end_define

begin_define
define|#
directive|define
name|ROUTE_GWHISADDR
value|4
end_define

begin_comment
comment|/* May be ORd with DST_MYADDR */
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
name|in_addr
name|dst
decl_stmt|;
name|struct
name|in_addr
name|mask
decl_stmt|;
name|struct
name|in_addr
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
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
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
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
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
name|struct
name|in_addr
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
parameter_list|)
function_decl|;
end_function_decl

end_unit


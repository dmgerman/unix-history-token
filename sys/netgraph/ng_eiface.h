begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_eiface.h  *  * Copyright (c) 1999-2000, Vitaly V Belekhov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * 	$Id: ng_eiface.h,v 1.4 2000/03/06 09:46:14 vitaly Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_EIFACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_EIFACE_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_EIFACE_NODE_TYPE
value|"eiface"
end_define

begin_define
define|#
directive|define
name|NGM_EIFACE_COOKIE
value|948105892
end_define

begin_comment
comment|/* Interface base name */
end_comment

begin_define
define|#
directive|define
name|NG_EIFACE_EIFACE_NAME
value|"nge"
end_define

begin_define
define|#
directive|define
name|NG_EIFACE_EIFACE_NAME_MAX
value|15
end_define

begin_comment
comment|/* My hook names */
end_comment

begin_define
define|#
directive|define
name|NG_EIFACE_HOOK_ETHER
value|"ether"
end_define

begin_comment
comment|/* MTU bounds */
end_comment

begin_define
define|#
directive|define
name|NG_EIFACE_MTU_MIN
value|72
end_define

begin_define
define|#
directive|define
name|NG_EIFACE_MTU_MAX
value|2312
end_define

begin_define
define|#
directive|define
name|NG_EIFACE_MTU_DEFAULT
value|1500
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_EIFACE_GET_IFNAME
init|=
literal|1
block|,
comment|/* returns struct ng_eiface_ifname */
name|NGM_EIFACE_GET_IFADDRS
block|,
comment|/* returns list of addresses */
name|NGM_EIFACE_SET
block|,
comment|/* set ethernet address */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ng_eiface_ifname
block|{
name|char
name|ngif_name
index|[
name|NG_EIFACE_EIFACE_NAME_MAX
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ng_eiface_par
block|{
name|u_char
name|oct0
decl_stmt|;
name|u_char
name|oct1
decl_stmt|;
name|u_char
name|oct2
decl_stmt|;
name|u_char
name|oct3
decl_stmt|;
name|u_char
name|oct4
decl_stmt|;
name|u_char
name|oct5
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ng_parse_struct_info
name|ng_eiface_par_fields
init|=
block|{
block|{
block|{
literal|"oct0"
block|,
operator|&
name|ng_parse_int8_type
block|}
block|,
block|{
literal|"oct1"
block|,
operator|&
name|ng_parse_int8_type
block|}
block|,
block|{
literal|"oct2"
block|,
operator|&
name|ng_parse_int8_type
block|}
block|,
block|{
literal|"oct3"
block|,
operator|&
name|ng_parse_int8_type
block|}
block|,
block|{
literal|"oct4"
block|,
operator|&
name|ng_parse_int8_type
block|}
block|,
block|{
literal|"oct5"
block|,
operator|&
name|ng_parse_int8_type
block|}
block|,
block|{
name|NULL
block|}
block|,   }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ng_parse_type
name|ng_eiface_par_type
init|=
block|{
operator|&
name|ng_parse_struct_type
block|,
operator|&
name|ng_eiface_par_fields
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ng_cmdlist
name|ng_eiface_cmdlist
index|[]
init|=
block|{
block|{
name|NGM_EIFACE_COOKIE
block|,
name|NGM_EIFACE_SET
block|,
literal|"set"
block|,
operator|&
name|ng_eiface_par_type
block|,
name|NULL
block|}
block|,
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_EIFACE_H_ */
end_comment

end_unit


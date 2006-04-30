begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_h4_prse.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_h4_prse.h,v 1.1 2002/11/24 19:46:55 max Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/***************************************************************************  ***************************************************************************  **                  ng_parse definitions for the H4 node  ***************************************************************************  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_H4_PRSE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_H4_PRSE_H_
end_define

begin_comment
comment|/*   * H4 node command list  */
end_comment

begin_comment
comment|/* Stat info */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ng_parse_struct_field
name|ng_h4_stat_type_fields
index|[]
init|=
block|{
block|{
literal|"pckts_recv"
block|,
operator|&
name|ng_parse_uint32_type
block|, }
block|,
block|{
literal|"bytes_recv"
block|,
operator|&
name|ng_parse_uint32_type
block|, }
block|,
block|{
literal|"pckts_sent"
block|,
operator|&
name|ng_parse_uint32_type
block|, }
block|,
block|{
literal|"bytes_sent"
block|,
operator|&
name|ng_parse_uint32_type
block|, }
block|,
block|{
literal|"oerrors"
block|,
operator|&
name|ng_parse_uint32_type
block|, }
block|,
block|{
literal|"ierrors"
block|,
operator|&
name|ng_parse_uint32_type
block|, }
block|,
block|{
name|NULL
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ng_parse_type
name|ng_h4_stat_type
init|=
block|{
operator|&
name|ng_parse_struct_type
block|,
operator|&
name|ng_h4_stat_type_fields
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ng_cmdlist
name|ng_h4_cmdlist
index|[]
init|=
block|{
block|{
name|NGM_H4_COOKIE
block|,
name|NGM_H4_NODE_RESET
block|,
literal|"reset"
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
name|NGM_H4_COOKIE
block|,
name|NGM_H4_NODE_GET_STATE
block|,
literal|"get_state"
block|,
name|NULL
block|,
operator|&
name|ng_parse_uint16_type
block|}
block|,
block|{
name|NGM_H4_COOKIE
block|,
name|NGM_H4_NODE_GET_DEBUG
block|,
literal|"get_debug"
block|,
name|NULL
block|,
operator|&
name|ng_parse_uint16_type
block|}
block|,
block|{
name|NGM_H4_COOKIE
block|,
name|NGM_H4_NODE_SET_DEBUG
block|,
literal|"set_debug"
block|,
operator|&
name|ng_parse_uint16_type
block|,
name|NULL
block|}
block|,
block|{
name|NGM_H4_COOKIE
block|,
name|NGM_H4_NODE_GET_QLEN
block|,
literal|"get_qlen"
block|,
name|NULL
block|,
operator|&
name|ng_parse_int32_type
block|}
block|,
block|{
name|NGM_H4_COOKIE
block|,
name|NGM_H4_NODE_SET_QLEN
block|,
literal|"set_qlen"
block|,
operator|&
name|ng_parse_int32_type
block|,
name|NULL
block|}
block|,
block|{
name|NGM_H4_COOKIE
block|,
name|NGM_H4_NODE_GET_STAT
block|,
literal|"get_stat"
block|,
name|NULL
block|,
operator|&
name|ng_h4_stat_type
block|}
block|,
block|{
name|NGM_H4_COOKIE
block|,
name|NGM_H4_NODE_RESET_STAT
block|,
literal|"reset_stat"
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|0
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _NETGRAPH_H4_PRSE_H_ */
end_comment

end_unit


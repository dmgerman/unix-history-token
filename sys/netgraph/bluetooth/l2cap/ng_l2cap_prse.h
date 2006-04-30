begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_l2cap_prse.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_l2cap_prse.h,v 1.2 2003/04/28 21:44:59 max Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/***************************************************************************  ***************************************************************************  **                ng_parse definitions for the L2CAP node  ***************************************************************************  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_L2CAP_PRSE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_L2CAP_PRSE_H_
end_define

begin_comment
comment|/*   * L2CAP node command list  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ng_cmdlist
name|ng_l2cap_cmdlist
index|[]
init|=
block|{
block|{
name|NGM_L2CAP_COOKIE
block|,
name|NGM_L2CAP_NODE_GET_FLAGS
block|,
literal|"get_flags"
block|,
name|NULL
block|,
operator|&
name|ng_parse_uint16_type
block|}
block|,
block|{
name|NGM_L2CAP_COOKIE
block|,
name|NGM_L2CAP_NODE_GET_DEBUG
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
name|NGM_L2CAP_COOKIE
block|,
name|NGM_L2CAP_NODE_SET_DEBUG
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
name|NGM_L2CAP_COOKIE
block|,
name|NGM_L2CAP_NODE_GET_AUTO_DISCON_TIMO
block|,
literal|"get_disc_timo"
block|,
name|NULL
block|,
operator|&
name|ng_parse_uint16_type
block|}
block|,
block|{
name|NGM_L2CAP_COOKIE
block|,
name|NGM_L2CAP_NODE_SET_AUTO_DISCON_TIMO
block|,
literal|"set_disc_timo"
block|,
operator|&
name|ng_parse_uint16_type
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
comment|/* ndef _NETGRAPH_L2CAP_PRSE_H_ */
end_comment

end_unit


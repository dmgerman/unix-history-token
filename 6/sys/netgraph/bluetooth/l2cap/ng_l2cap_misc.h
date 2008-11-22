begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_l2cap_misc.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_l2cap_misc.h,v 1.3 2003/09/08 19:11:45 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_L2CAP_MISC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_L2CAP_MISC_H_
end_define

begin_function_decl
name|void
name|ng_l2cap_send_hook_info
parameter_list|(
name|node_p
parameter_list|,
name|hook_p
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ACL Connections  */
end_comment

begin_function_decl
name|ng_l2cap_con_p
name|ng_l2cap_new_con
parameter_list|(
name|ng_l2cap_p
parameter_list|,
name|bdaddr_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_l2cap_con_ref
parameter_list|(
name|ng_l2cap_con_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_l2cap_con_unref
parameter_list|(
name|ng_l2cap_con_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ng_l2cap_con_p
name|ng_l2cap_con_by_addr
parameter_list|(
name|ng_l2cap_p
parameter_list|,
name|bdaddr_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ng_l2cap_con_p
name|ng_l2cap_con_by_handle
parameter_list|(
name|ng_l2cap_p
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_l2cap_free_con
parameter_list|(
name|ng_l2cap_con_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * L2CAP channels  */
end_comment

begin_function_decl
name|ng_l2cap_chan_p
name|ng_l2cap_new_chan
parameter_list|(
name|ng_l2cap_p
parameter_list|,
name|ng_l2cap_con_p
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ng_l2cap_chan_p
name|ng_l2cap_chan_by_scid
parameter_list|(
name|ng_l2cap_p
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_l2cap_free_chan
parameter_list|(
name|ng_l2cap_chan_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * L2CAP command descriptors  */
end_comment

begin_define
define|#
directive|define
name|ng_l2cap_link_cmd
parameter_list|(
name|con
parameter_list|,
name|cmd
parameter_list|)
define|\
value|do { \ 	TAILQ_INSERT_TAIL(&(con)->cmd_list, (cmd), next); \ 	ng_l2cap_con_ref((con)); \ } while (0)
end_define

begin_define
define|#
directive|define
name|ng_l2cap_unlink_cmd
parameter_list|(
name|cmd
parameter_list|)
define|\
value|do { \ 	TAILQ_REMOVE(&((cmd)->con->cmd_list), (cmd), next); \ 	ng_l2cap_con_unref((cmd)->con); \ } while (0)
end_define

begin_define
define|#
directive|define
name|ng_l2cap_free_cmd
parameter_list|(
name|cmd
parameter_list|)
define|\
value|do { \ 	KASSERT(!callout_pending(&(cmd)->timo), ("Pending callout!")); \ 	NG_FREE_M((cmd)->aux); \ 	bzero((cmd), sizeof(*(cmd))); \ 	FREE((cmd), M_NETGRAPH_L2CAP); \ } while (0)
end_define

begin_function_decl
name|ng_l2cap_cmd_p
name|ng_l2cap_new_cmd
parameter_list|(
name|ng_l2cap_con_p
parameter_list|,
name|ng_l2cap_chan_p
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ng_l2cap_cmd_p
name|ng_l2cap_cmd_by_ident
parameter_list|(
name|ng_l2cap_con_p
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int8_t
name|ng_l2cap_get_ident
parameter_list|(
name|ng_l2cap_con_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Timeout  */
end_comment

begin_function_decl
name|int
name|ng_l2cap_discon_timeout
parameter_list|(
name|ng_l2cap_con_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_l2cap_discon_untimeout
parameter_list|(
name|ng_l2cap_con_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_l2cap_lp_timeout
parameter_list|(
name|ng_l2cap_con_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_l2cap_lp_untimeout
parameter_list|(
name|ng_l2cap_con_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_l2cap_command_timeout
parameter_list|(
name|ng_l2cap_cmd_p
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_l2cap_command_untimeout
parameter_list|(
name|ng_l2cap_cmd_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Other stuff  */
end_comment

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ng_l2cap_prepend
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ng_l2cap_flow_p
name|ng_l2cap_default_flow
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _NETGRAPH_L2CAP_MISC_H_ */
end_comment

end_unit


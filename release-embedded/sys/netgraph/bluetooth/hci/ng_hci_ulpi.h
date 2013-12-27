begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_hci_ulpi.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_hci_ulpi.h,v 1.2 2003/04/26 22:35:21 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_HCI_ULPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_HCI_ULPI_H_
end_define

begin_comment
comment|/*  * LP_xxx event handlers  */
end_comment

begin_function_decl
name|int
name|ng_hci_lp_con_req
parameter_list|(
name|ng_hci_unit_p
parameter_list|,
name|item_p
parameter_list|,
name|hook_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_hci_lp_discon_req
parameter_list|(
name|ng_hci_unit_p
parameter_list|,
name|item_p
parameter_list|,
name|hook_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_hci_lp_con_cfm
parameter_list|(
name|ng_hci_unit_con_p
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_hci_lp_con_ind
parameter_list|(
name|ng_hci_unit_con_p
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_hci_lp_con_rsp
parameter_list|(
name|ng_hci_unit_p
parameter_list|,
name|item_p
parameter_list|,
name|hook_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_hci_lp_discon_ind
parameter_list|(
name|ng_hci_unit_con_p
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_hci_lp_qos_req
parameter_list|(
name|ng_hci_unit_p
parameter_list|,
name|item_p
parameter_list|,
name|hook_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_hci_lp_qos_cfm
parameter_list|(
name|ng_hci_unit_con_p
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_hci_lp_qos_ind
parameter_list|(
name|ng_hci_unit_con_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_hci_process_con_timeout
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _NETGRAPH_HCI_ULPI_H_ */
end_comment

end_unit


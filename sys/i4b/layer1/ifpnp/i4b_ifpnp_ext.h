begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Gary Jennejohn. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *      i4b_ifpnp - Fritz!Card PnP for split layers  *      -------------------------------------------  *  *	$Id: i4b_ifpnp_ext.h,v 1.2 2000/06/02 16:14:36 hm Exp $  *	$Ust: src/i4b/layer1-nb/ifpnp/i4b_ifpnp_ext.h,v 1.4 2000/04/18 08:03:05 ust Exp $  *  * $FreeBSD$  *  *      last edit-date: [Fri Jun  2 14:54:57 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_IFPNP_EXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_IFPNP_EXT_H_
end_define

begin_include
include|#
directive|include
file|<i4b/include/i4b_l3l4.h>
end_include

begin_function_decl
name|void
name|ifpnp_set_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|,
name|drvr_link_t
modifier|*
name|dlt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isdn_link_t
modifier|*
name|ifpnp_ret_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifpnp_ph_data_req
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|freeflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifpnp_ph_activate_req
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifpnp_mph_command_req
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|command
parameter_list|,
name|void
modifier|*
name|parm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifpnp_isac_irq
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|ista
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifpnp_isac_l1_cmd
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifpnp_isac_init
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifpnp_recover
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ifpnp_printstate
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifpnp_next_state
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IFPNP_MAXUNIT
value|4
end_define

begin_decl_stmt
specifier|extern
name|struct
name|l1_softc
modifier|*
name|ifpnp_scp
index|[
name|IFPNP_MAXUNIT
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_IFPNP_EXT_H_ */
end_comment

end_unit


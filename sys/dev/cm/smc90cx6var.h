begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: smc90cx6var.h,v 1.5 2000/03/23 07:01:32 thorpej Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994, 1995, 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Ignatios Souvatzis.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * BAH (SMC 8bit ARCnet chipset) k/dpi  *  * The SMC 8bit ARCnet chip family uses a register and a memory window, which  * we get passed via bus_space_tags and bus_space_handles.  *  * As the reset functionality differs between the Amiga boards (using the  * 90c26 chip) and middle-aged ISA boards (using the 90c56 chip), we have  * a sc_reset callback function in the softc, which does a stop function  * (reset and leave dead) or a reset function depending on wether the 2nd  * parameter is 0 or 1.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMC90CX6VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMC90CX6VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_struct
struct|struct
name|cm_softc
block|{
name|struct
name|arccom
name|sc_arccom
decl_stmt|;
comment|/* Common arcnet structures */
name|int
name|port_rid
decl_stmt|;
comment|/* resource id for port range */
name|struct
name|resource
modifier|*
name|port_res
decl_stmt|;
comment|/* resource for port range */
name|int
name|port_used
decl_stmt|;
comment|/* ports used */
name|int
name|mem_rid
decl_stmt|;
comment|/* resource id for memory range */
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
comment|/* resource for memory range */
name|int
name|mem_used
decl_stmt|;
comment|/* memory used */
name|int
name|irq_rid
decl_stmt|;
comment|/* resource id for irq */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/* resource for irq */
name|void
modifier|*
name|irq_handle
decl_stmt|;
comment|/* handle for irq handler */
name|void
modifier|*
name|sc_rxcookie
decl_stmt|;
comment|/* softcallback cookies */
name|void
modifier|*
name|sc_txcookie
decl_stmt|;
name|struct
name|callout
name|sc_recon_ch
decl_stmt|;
name|u_long
name|sc_recontime
decl_stmt|;
comment|/* seconds only, I'm lazy */
name|u_long
name|sc_reconcount
decl_stmt|;
comment|/* for the above */
name|u_long
name|sc_reconcount_excessive
decl_stmt|;
comment|/* for the above */
define|#
directive|define
name|ARC_EXCESSIVE_RECONS
value|20
define|#
directive|define
name|ARC_EXCESSIVE_RECONS_REWARN
value|400
name|u_char
name|sc_intmask
decl_stmt|;
name|u_char
name|sc_rx_act
decl_stmt|;
comment|/* 2..3 */
name|u_char
name|sc_tx_act
decl_stmt|;
comment|/* 0..1 */
name|u_char
name|sc_rx_fillcount
decl_stmt|;
name|u_char
name|sc_tx_fillcount
decl_stmt|;
name|u_char
name|sc_broadcast
index|[
literal|2
index|]
decl_stmt|;
comment|/* is it a broadcast packet? */
name|u_char
name|sc_retransmits
index|[
literal|2
index|]
decl_stmt|;
comment|/* unused at the moment */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|cm_attach
parameter_list|(
name|struct
name|cm_softc
modifier|*
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cmintr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cm_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cm_stop
parameter_list|(
name|struct
name|cm_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cm_alloc_port
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|rid
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cm_alloc_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|rid
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cm_alloc_irq
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|rid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cm_release_resources
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|cm_devclass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


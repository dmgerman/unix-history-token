begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Bjoern A. Zeeb  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-11-C-0249  * ("MRC2"), as part of the DARPA MRC research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_IF_NF10BMACREG_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_IF_NF10BMACREG_H
end_define

begin_struct
struct|struct
name|nf10bmac_softc
block|{
name|struct
name|ifnet
modifier|*
name|nf10bmac_ifp
decl_stmt|;
name|struct
name|resource
modifier|*
name|nf10bmac_tx_mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|nf10bmac_rx_mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|nf10bmac_mem_res
decl_stmt|;
name|uint8_t
modifier|*
name|nf10bmac_tx_buf
decl_stmt|;
name|device_t
name|nf10bmac_dev
decl_stmt|;
name|int
name|nf10bmac_unit
decl_stmt|;
name|int
name|nf10bmac_tx_mem_rid
decl_stmt|;
name|int
name|nf10bmac_rx_mem_rid
decl_stmt|;
name|int
name|nf10bmac_mem_rid
decl_stmt|;
name|int
name|nf10bmac_if_flags
decl_stmt|;
name|uint32_t
name|nf10bmac_flags
decl_stmt|;
define|#
directive|define
name|NF10BMAC_FLAGS_LINK
value|0x00000001
name|uint8_t
name|nf10bmac_eth_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|ENABLE_WATCHDOG
name|uint16_t
name|nf10bmac_watchdog_timer
decl_stmt|;
name|struct
name|callout
name|nf10bmac_tick
decl_stmt|;
endif|#
directive|endif
name|struct
name|ifmedia
name|nf10bmac_media
decl_stmt|;
comment|/* to fake it. */
name|struct
name|mtx
name|nf10bmac_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|nf10bmac_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nf10bmac_detach_dev
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nf10bmac_detach_resources
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|nf10bmac_devclass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_IF_NF10BMACREG_H */
end_comment

begin_comment
comment|/* end */
end_comment

end_unit


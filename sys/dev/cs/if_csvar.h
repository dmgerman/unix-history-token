begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 M. Warner Losh<imp@village.org>   * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_CSVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_CSVAR_H
end_define

begin_comment
comment|/*  * cs_softc: per line info and status  */
end_comment

begin_struct
struct|struct
name|cs_softc
block|{
comment|/* Ethernet common code */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
comment|/* Configuration words from EEPROM */
name|int
name|auto_neg_cnf
decl_stmt|;
comment|/* AutoNegotitation configuration */
name|int
name|adapter_cnf
decl_stmt|;
comment|/* Adapter configuration */
name|int
name|isa_config
decl_stmt|;
comment|/* ISA configuration */
name|int
name|chip_type
decl_stmt|;
comment|/* Type of chip */
name|u_char
name|enaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
comment|/* Media information */
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
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|CS_NO_IRQ
value|0x1
name|int
name|send_cmd
decl_stmt|;
name|int
name|line_ctl
decl_stmt|;
comment|/* */
name|int
name|send_underrun
decl_stmt|;
name|void
modifier|*
name|recv_ring
decl_stmt|;
name|unsigned
name|char
modifier|*
name|buffer
decl_stmt|;
name|int
name|buf_len
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
name|struct
name|callout
name|timer
decl_stmt|;
name|int
name|tx_timeout
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CS_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->lock)
end_define

begin_define
define|#
directive|define
name|CS_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->lock)
end_define

begin_define
define|#
directive|define
name|CS_ASSERT_LOCKED
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->lock, MA_OWNED)
end_define

begin_function_decl
name|int
name|cs_alloc_port
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
name|cs_alloc_irq
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
name|int
name|cs_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cs_cs89x0_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cs_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cs_release_resources
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_CSVAR_H */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 M. Warner Losh<imp@village.org>   * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_comment
comment|/*  * cs_softc: per line info and status  */
end_comment

begin_struct
struct|struct
name|cs_softc
block|{
comment|/* Ethernet common code */
name|struct
name|arpcom
name|arpcom
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
name|struct
name|ifmedia
name|media
decl_stmt|;
comment|/* Media information */
name|int
name|port_rid
decl_stmt|;
comment|/* resource id for port range */
name|int
name|port_used
decl_stmt|;
comment|/* nonzero if ports used */
name|struct
name|resource
modifier|*
name|port_res
decl_stmt|;
comment|/* resource for port range */
name|int
name|mem_rid
decl_stmt|;
comment|/* resource id for memory range */
name|int
name|mem_used
decl_stmt|;
comment|/* nonzero if memory used */
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
comment|/* resource for memory range */
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
name|nic_addr
decl_stmt|;
comment|/* Base IO address of card */
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
block|}
struct|;
end_struct

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
name|cs_alloc_memory
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
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cs_attach
parameter_list|(
name|struct
name|cs_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
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
name|void
name|cs_release_resources
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|driver_intr_t
name|csintr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_CSVAR_H */
end_comment

end_unit


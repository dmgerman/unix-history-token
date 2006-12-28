begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994,1995 Stefan Esser, Wolfgang StanglMeier  * Copyright (c) 2000 Michael Smith<msmith@freebsd.org>  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCIB_PRIVATE_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCIB_PRIVATE_H__
end_define

begin_comment
comment|/*  * Export portions of generic PCI:PCI bridge support so that it can be  * used by subclasses.  */
end_comment

begin_comment
comment|/*  * Bridge-specific data.  */
end_comment

begin_struct
struct|struct
name|pcib_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* flags */
define|#
directive|define
name|PCIB_SUBTRACTIVE
value|0x1
name|uint16_t
name|command
decl_stmt|;
comment|/* command register */
name|uint8_t
name|secbus
decl_stmt|;
comment|/* secondary bus number */
name|uint8_t
name|subbus
decl_stmt|;
comment|/* subordinate bus number */
name|pci_addr_t
name|pmembase
decl_stmt|;
comment|/* base address of prefetchable memory */
name|pci_addr_t
name|pmemlimit
decl_stmt|;
comment|/* topmost address of prefetchable memory */
name|pci_addr_t
name|membase
decl_stmt|;
comment|/* base address of memory window */
name|pci_addr_t
name|memlimit
decl_stmt|;
comment|/* topmost address of memory window */
name|uint32_t
name|iobase
decl_stmt|;
comment|/* base address of port window */
name|uint32_t
name|iolimit
decl_stmt|;
comment|/* topmost address of port window */
name|uint16_t
name|secstat
decl_stmt|;
comment|/* secondary bus status register */
name|uint16_t
name|bridgectl
decl_stmt|;
comment|/* bridge control register */
name|uint8_t
name|seclat
decl_stmt|;
comment|/* secondary bus latency timer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|uint32_t
name|pci_read_config_fn
parameter_list|(
name|int
name|b
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|f
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|host_pcib_get_busno
parameter_list|(
name|pci_read_config_fn
name|read_config
parameter_list|,
name|int
name|bus
parameter_list|,
name|int
name|slot
parameter_list|,
name|int
name|func
parameter_list|,
name|uint8_t
modifier|*
name|busnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcib_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcib_attach_common
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcib_read_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|which
parameter_list|,
name|uintptr_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcib_write_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|which
parameter_list|,
name|uintptr_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|pcib_alloc_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|,
name|u_long
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcib_maxslots
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|pcib_read_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|f
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcib_write_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|f
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcib_route_interrupt
parameter_list|(
name|device_t
name|pcib
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIBA_PCIBVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIBA_PCIBVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_struct
struct|struct
name|siba_pcib_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* Device ID */
name|u_int
name|sc_bus
decl_stmt|;
comment|/* PCI bus number */
name|struct
name|resource
modifier|*
name|sc_mem
decl_stmt|;
comment|/* siba memory window */
name|struct
name|resource
modifier|*
name|sc_csr
decl_stmt|;
comment|/* config space */
name|bus_space_tag_t
name|sc_bt
decl_stmt|;
name|bus_space_handle_t
name|sc_bh
decl_stmt|;
if|#
directive|if
literal|0
block|bus_addr_t		 sc_maddr; 	bus_size_t		 sc_msize;  	struct bus_space	 sc_pci_memt; 	struct bus_space	 sc_pci_iot; 	bus_dma_tag_t		 sc_dmat;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIBA_PCIBVAR_H_ */
end_comment

end_unit


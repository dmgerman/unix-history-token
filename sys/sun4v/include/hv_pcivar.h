begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2006 John-Mark Gurney.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HV_PCIVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_HV_PCIVAR_H_
end_define

begin_struct
struct|struct
name|hvpci_softc
block|{
name|devhandle_t
name|hs_devhandle
decl_stmt|;
name|phandle_t
name|hs_node
decl_stmt|;
name|uint8_t
name|hs_busnum
decl_stmt|;
name|struct
name|ofw_bus_iinfo
name|hs_pci_iinfo
decl_stmt|;
name|struct
name|bus_dma_tag
name|hs_dmatag
decl_stmt|;
name|struct
name|rman
name|hs_pci_mem_rman
decl_stmt|;
name|bus_space_tag_t
name|hs_pci_memt
decl_stmt|;
name|bus_space_handle_t
name|hs_pci_memh
decl_stmt|;
name|struct
name|rman
name|hs_pci_io_rman
decl_stmt|;
name|bus_space_tag_t
name|hs_pci_iot
decl_stmt|;
name|bus_space_handle_t
name|hs_pci_ioh
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HV_PCIVAR_H_ */
end_comment

end_unit


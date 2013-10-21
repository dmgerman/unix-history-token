begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POWERPC_OFW_OFW_PCI_H
end_ifndef

begin_define
define|#
directive|define
name|POWERPC_OFW_OFW_PCI_H
end_define

begin_comment
comment|/*  * Export class definition for inheritance purposes  */
end_comment

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|ofw_pci_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ofw_pci_range
block|{
name|uint32_t
name|pci_hi
decl_stmt|;
name|uint64_t
name|pci
decl_stmt|;
name|uint64_t
name|host
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Quirks for some adapters  */
end_comment

begin_enum
enum|enum
block|{
name|OFW_PCI_QUIRK_RANGES_ON_CHILDREN
init|=
literal|1
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ofw_pci_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|phandle_t
name|sc_node
decl_stmt|;
name|int
name|sc_bus
decl_stmt|;
name|int
name|sc_initialized
decl_stmt|;
name|int
name|sc_quirks
decl_stmt|;
name|struct
name|ofw_pci_register
name|sc_pcir
decl_stmt|;
name|struct
name|ofw_pci_range
modifier|*
name|sc_range
decl_stmt|;
name|int
name|sc_nrange
decl_stmt|;
name|struct
name|rman
name|sc_io_rman
decl_stmt|;
name|struct
name|rman
name|sc_mem_rman
decl_stmt|;
name|bus_space_tag_t
name|sc_memt
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
name|struct
name|ofw_bus_iinfo
name|sc_pci_iinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ofw_pci_init
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_pci_attach
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
comment|// POWERPC_OFW_OFW_PCI_H
end_comment

end_unit


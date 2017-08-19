begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 Ruslan Bukin<br@bsdpad.com>  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCI_HOST_GENERIC_H_
end_ifndef

begin_define
define|#
directive|define
name|__PCI_HOST_GENERIC_H_
end_define

begin_include
include|#
directive|include
file|"pci_if.h"
end_include

begin_define
define|#
directive|define
name|MAX_RANGES_TUPLES
value|16
end_define

begin_define
define|#
directive|define
name|MIN_RANGES_TUPLES
value|2
end_define

begin_struct
struct|struct
name|pcie_range
block|{
name|uint64_t
name|pci_base
decl_stmt|;
name|uint64_t
name|phys_base
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
name|uint64_t
name|flags
decl_stmt|;
define|#
directive|define
name|FLAG_IO
value|(1<< 0)
define|#
directive|define
name|FLAG_MEM
value|(1<< 1)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|generic_pcie_core_softc
block|{
name|struct
name|pcie_range
name|ranges
index|[
name|MAX_RANGES_TUPLES
index|]
decl_stmt|;
name|int
name|nranges
decl_stmt|;
name|int
name|coherent
decl_stmt|;
name|struct
name|rman
name|mem_rman
decl_stmt|;
name|struct
name|rman
name|io_rman
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|struct
name|resource
modifier|*
name|res1
decl_stmt|;
name|int
name|ecam
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|bus_space_handle_t
name|ioh
decl_stmt|;
name|bus_dma_tag_t
name|dmat
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|generic_pcie_core_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|pci_host_generic_core_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|pci_host_generic_core_alloc_resource
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|rman_res_t
parameter_list|,
name|rman_res_t
parameter_list|,
name|rman_res_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_host_generic_core_release_resource
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PCI_HOST_GENERIC_H_ */
end_comment

end_unit


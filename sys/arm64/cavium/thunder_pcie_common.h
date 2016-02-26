begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAVIUM_THUNDER_PCIE_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_CAVIUM_THUNDER_PCIE_COMMON_H_
end_define

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|thunder_pcie_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|thunder_pem_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_THUNDER_PCIE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|uint32_t
name|range_addr_is_pci
parameter_list|(
name|struct
name|pcie_range
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|range_addr_is_phys
parameter_list|(
name|struct
name|pcie_range
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|range_addr_pci_to_phys
parameter_list|(
name|struct
name|pcie_range
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thunder_pcie_identify_ecam
parameter_list|(
name|device_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|THUNDERX_PASS_1_1_ERRATA
end_ifdef

begin_function_decl
name|struct
name|resource
modifier|*
name|thunder_pcie_alloc_resource
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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAVIUM_THUNDER_PCIE_COMMON_H_ */
end_comment

end_unit


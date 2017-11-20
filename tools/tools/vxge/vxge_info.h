begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VXGE_INFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_VXGE_INFO_H_
end_define

begin_include
include|#
directive|include
file|"vxge_cmn.h"
end_include

begin_comment
comment|/* Function declerations */
end_comment

begin_function_decl
name|void
name|vxge_get_registers_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_registers_toc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_registers_vpath
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_registers_vpmgmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_registers_legacy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_registers_srpcim
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_registers_mrpcim
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_registers_common
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_registers_pcicfgmgmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_stats_common
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_stats_mrpcim
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_stats_driver
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_get_stats_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_hw_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_pci_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_port_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_set_port_mode
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_get_bw_priority
parameter_list|(
name|int
parameter_list|,
name|vxge_query_device_info_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vxge_set_bw_priority
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|vxge_query_device_info_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_registers
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_registers_toc
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_registers_vpath
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_registers_vpmgmt
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_registers_legacy
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_registers_srpcim
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_registers_mrpcim
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_registers_pcicfgmgmt
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_hw_info
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_pci_config
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_stats
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_stats_drv
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_bw_priority
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vxge_print_port_mode
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|vxge_mem_alloc
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|vxge_pci_bar0_t
name|reginfo_toc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vxge_pci_bar0_t
name|reginfo_vpath
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vxge_pci_bar0_t
name|reginfo_legacy
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vxge_pci_bar0_t
name|reginfo_vpmgmt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vxge_pci_bar0_t
name|reginfo_mrpcim
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vxge_pci_bar0_t
name|reginfo_srpcim
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vxge_pci_bar0_t
name|reginfo_registers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vxge_pci_bar0_t
name|reginfo_pcicfgmgmt
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VXGE_INFO_H_ */
end_comment

end_unit


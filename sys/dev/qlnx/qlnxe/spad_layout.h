begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/****************************************************************************  * Name:        spad_layout.h  *  * Description: Global definitions  *  * Created:     01/09/2013  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *          Spad Layout                                NVM CFG                         MCP public  *==========================================================================================================  *     MCP_REG_SCRATCH                         REG_RD(MISC_REG_GEN_PURP_CR0)       REG_RD(MISC_REG_SHARED_MEM_ADDR)  *    +------------------+                      +-------------------------+        +-------------------+  *    |  Num Sections(4B)|Currently 4           |   Num Sections(4B)      |        |   Num Sections(4B)|Currently 6  *    +------------------+                      +-------------------------+        +-------------------+  *    | Offsize(Trace)   |4B -+             +-- | Offset(NVM_CFG1)        |        | Offsize(drv_mb)   |  *  +-| Offsize(NVM_CFG) |4B  |             |   | (Size is fixed)         |        | Offsize(mfw_mb)   |  *+-|-| Offsize(Public)  |4B  |             +-> +-------------------------+        | Offsize(global)   |  *| | | Offsize(Private) |4B  |                 |                         |        | Offsize(path)     |  *| | +------------------+<--+                 | nvm_cfg1_glob           |        | Offsize(port)     |  *| | |                  |                      +-------------------------+        | Offsize(func)     |  *| | |      Trace       |                      | nvm_cfg1_path 0         |        +-------------------+  *| +>+------------------+                      | nvm_cfg1_path 1         |        | drv_mb   PF0/2/4..|8 Funcs of engine0  *|   |                  |                      +-------------------------+        | drv_mb   PF1/3/5..|8 Funcs of engine1  *|   |     NVM_CFG      |                      | nvm_cfg1_port 0         |        +-------------------+  *+-> +------------------+                      |            ....         |        | mfw_mb   PF0/2/4..|8 Funcs of engine0  *    |                  |                      | nvm_cfg1_port 3         |        | mfw_mb   PF1/3/5..|8 Funcs of engine1  *    |   Public Data    |                      +-------------------------+        +-------------------+  *    +------------------+   8 Funcs of Engine 0| nvm_cfg1_func PF0/2/4/..|        |                   |  *    |                  |   8 Funcs of Engine 1| nvm_cfg1_func PF1/3/5/..|        | public_global     |  *    |   Private Data   |                      +-------------------------+        +-------------------+  *    +------------------+                                                         | public_path 0     |  *    |       Code       |                                                         | public_path 1     |  *    |   Static Area    |                                                         +-------------------+  *    +---            ---+                                                         | public_port 0     |  *    |       Code       |                                                         |        ....       |  *    |      PIM Area    |                                                         | public_port 3     |  *    +------------------+                                                         +-------------------+  *                                                                                 | public_func 0/2/4.|8 Funcs of engine0  *                                                                                 | public_func 1/3/5.|8 Funcs of engine1  *                                                                                 +-------------------+ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPAD_LAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|SPAD_LAYOUT_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MDUMP_PARSE_TOOL
end_ifndef

begin_define
define|#
directive|define
name|PORT_0
value|0
end_define

begin_define
define|#
directive|define
name|PORT_1
value|1
end_define

begin_define
define|#
directive|define
name|PORT_2
value|2
end_define

begin_define
define|#
directive|define
name|PORT_3
value|3
end_define

begin_include
include|#
directive|include
file|"mcp_public.h"
end_include

begin_include
include|#
directive|include
file|"mfw_hsi.h"
end_include

begin_include
include|#
directive|include
file|"nvm_cfg.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MFW
end_ifdef

begin_include
include|#
directive|include
file|"mcp_private.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|spad_layout
name|g_spad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TBD - Consider renaming to MCP_STATIC_SPAD_SIZE, since the real size includes another 64kb */
end_comment

begin_define
define|#
directive|define
name|MCP_SPAD_SIZE
value|0x00028000
end_define

begin_comment
comment|/* 160 KB */
end_comment

begin_define
define|#
directive|define
name|SPAD_OFFSET
parameter_list|(
name|addr
parameter_list|)
value|(((u32)addr - (u32)CPU_SPAD_BASE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MDUMP_PARSE_TOOL */
end_comment

begin_define
define|#
directive|define
name|TO_OFFSIZE
parameter_list|(
name|_offset
parameter_list|,
name|_size
parameter_list|)
define|\
value|(u32)((((u32)(_offset)>> 2)<< OFFSIZE_OFFSET_SHIFT) | \ 	  (((u32)(_size)>> 2)<< OFFSIZE_SIZE_SHIFT))
end_define

begin_enum
enum|enum
name|spad_sections
block|{
name|SPAD_SECTION_TRACE
block|,
name|SPAD_SECTION_NVM_CFG
block|,
name|SPAD_SECTION_PUBLIC
block|,
name|SPAD_SECTION_PRIVATE
block|,
name|SPAD_SECTION_MAX
block|}
enum|;
end_enum

begin_ifndef
ifndef|#
directive|ifndef
name|MDUMP_PARSE_TOOL
end_ifndef

begin_struct
struct|struct
name|spad_layout
block|{
name|struct
name|nvm_cfg
name|nvm_cfg
decl_stmt|;
name|struct
name|mcp_public_data
name|public_data
decl_stmt|;
ifdef|#
directive|ifdef
name|MFW
comment|/* Drivers will not be compiled with this flag. */
comment|/* Linux should remove this appearance at all. */
name|struct
name|mcp_private_data
name|private_data
decl_stmt|;
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
comment|/* MDUMP_PARSE_TOOL */
end_comment

begin_define
define|#
directive|define
name|MCP_TRACE_SIZE
value|2048
end_define

begin_comment
comment|/* 2kb */
end_comment

begin_define
define|#
directive|define
name|STRUCT_OFFSET
parameter_list|(
name|f
parameter_list|)
value|(STATIC_INIT_BASE + __builtin_offsetof(struct static_init, f))
end_define

begin_comment
comment|/* This section is located at a fixed location in the beginning of the scratchpad,  * to ensure that the MCP trace is not run over during MFW upgrade.  * All the rest of data has a floating location which differs from version to version,  * and is pointed by the mcp_meta_data below.  * Moreover, the spad_layout section is part of the MFW firmware, and is loaded with it  * from nvram in order to clear this portion.  */
end_comment

begin_struct
struct|struct
name|static_init
block|{
name|u32
name|num_sections
decl_stmt|;
comment|/* 0xe20000 */
name|offsize_t
name|sections
index|[
name|SPAD_SECTION_MAX
index|]
decl_stmt|;
comment|/* 0xe20004 */
define|#
directive|define
name|SECTION
parameter_list|(
name|_sec_
parameter_list|)
value|*((offsize_t*)(STRUCT_OFFSET(sections[_sec_])))
name|struct
name|mcp_trace
name|trace
decl_stmt|;
comment|/* 0xe20014 */
define|#
directive|define
name|MCP_TRACE_P
value|((struct mcp_trace*)(STRUCT_OFFSET(trace)))
name|u8
name|trace_buffer
index|[
name|MCP_TRACE_SIZE
index|]
decl_stmt|;
comment|/* 0xe20030 */
define|#
directive|define
name|MCP_TRACE_BUF
value|((u8*)(STRUCT_OFFSET(trace_buffer)))
comment|/* running_mfw has the same definition as in nvm_map.h. 	 * This bit indicate both the running dir, and the running bundle. 	 * It is set once when the LIM is loaded. 	 */
name|u32
name|running_mfw
decl_stmt|;
comment|/* 0xe20830 */
define|#
directive|define
name|RUNNING_MFW
value|*((u32*)(STRUCT_OFFSET(running_mfw)))
name|u32
name|build_time
decl_stmt|;
comment|/* 0xe20834 */
define|#
directive|define
name|MFW_BUILD_TIME
value|*((u32*)(STRUCT_OFFSET(build_time)))
name|u32
name|reset_type
decl_stmt|;
comment|/* 0xe20838 */
define|#
directive|define
name|RESET_TYPE
value|*((u32*)(STRUCT_OFFSET(reset_type)))
name|u32
name|mfw_secure_mode
decl_stmt|;
comment|/* 0xe2083c */
define|#
directive|define
name|MFW_SECURE_MODE
value|*((u32*)(STRUCT_OFFSET(mfw_secure_mode)))
name|u16
name|pme_status_pf_bitmap
decl_stmt|;
comment|/* 0xe20840 */
define|#
directive|define
name|PME_STATUS_PF_BITMAP
value|*((u16*)(STRUCT_OFFSET(pme_status_pf_bitmap)))
name|u16
name|pme_enable_pf_bitmap
decl_stmt|;
define|#
directive|define
name|PME_ENABLE_PF_BITMAP
value|*((u16*)(STRUCT_OFFSET(pme_enable_pf_bitmap)))
name|u32
name|mim_nvm_addr
decl_stmt|;
comment|/* 0xe20844 */
name|u32
name|mim_start_addr
decl_stmt|;
comment|/* 0xe20848 */
name|u32
name|ah_pcie_link_params
decl_stmt|;
comment|/* 0xe20850 Stores PCIe link configuration at start, so they can be used later also for Hot-Reset, without the need to re-reading them from nvm cfg. */
define|#
directive|define
name|AH_PCIE_LINK_PARAMS_LINK_SPEED_MASK
value|(0x000000ff)
define|#
directive|define
name|AH_PCIE_LINK_PARAMS_LINK_SPEED_SHIFT
value|(0)
define|#
directive|define
name|AH_PCIE_LINK_PARAMS_LINK_WIDTH_MASK
value|(0x0000ff00)
define|#
directive|define
name|AH_PCIE_LINK_PARAMS_LINK_WIDTH_SHIFT
value|(8)
define|#
directive|define
name|AH_PCIE_LINK_PARAMS_ASPM_MODE_MASK
value|(0x00ff0000)
define|#
directive|define
name|AH_PCIE_LINK_PARAMS_ASPM_MODE_SHIFT
value|(16)
define|#
directive|define
name|AH_PCIE_LINK_PARAMS_ASPM_CAP_MASK
value|(0xff000000)
define|#
directive|define
name|AH_PCIE_LINK_PARAMS_ASPM_CAP_SHIFT
value|(24)
define|#
directive|define
name|AH_PCIE_LINK_PARAMS
value|*((u32*)(STRUCT_OFFSET(ah_pcie_link_params)))
name|u32
name|flags
decl_stmt|;
comment|/* 0xe20850 */
define|#
directive|define
name|M_GLOB_FLAGS
value|*((u32*)(STRUCT_OFFSET(flags)))
define|#
directive|define
name|FLAGS_VAUX_REQUIRED
value|(1<< 0)
define|#
directive|define
name|FLAGS_WAIT_AVS_READY
value|(1<< 1)
define|#
directive|define
name|FLAGS_FAILURE_ISSUED
value|(1<< 2)
define|#
directive|define
name|FLAGS_FAILURE_DETECTED
value|(1<< 3)
define|#
directive|define
name|FLAGS_VAUX
value|(1<< 4)
define|#
directive|define
name|FLAGS_PERST_ASSERT_OCCURED
value|(1<< 5)
define|#
directive|define
name|FLAGS_HOT_RESET_STEP2
value|(1<< 6)
define|#
directive|define
name|FLAGS_MSIX_SYNC_ALLOWED
value|(1<< 7)
define|#
directive|define
name|FLAGS_PROGRAM_PCI_COMPLETED
value|(1<< 8)
define|#
directive|define
name|FLAGS_SMBUS_AUX_MODE
value|(1<< 9)
define|#
directive|define
name|FLAGS_PEND_SMBUS_VMAIN_TO_AUX
value|(1<< 10)
define|#
directive|define
name|FLAGS_NVM_CFG_EFUSE_FAILURE
value|(1<< 11)
define|#
directive|define
name|FLAGS_OS_DRV_LOADED
value|(1<< 29)
define|#
directive|define
name|FLAGS_OVER_TEMP_OCCUR
value|(1<< 30)
define|#
directive|define
name|FLAGS_FAN_FAIL_OCCUR
value|(1<< 31)
name|u32
name|rsrv_persist
index|[
literal|4
index|]
decl_stmt|;
comment|/* Persist reserved for MFW upgrades */
comment|/* 0xe20854 */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|MDUMP_PARSE_TOOL
end_ifndef

begin_define
define|#
directive|define
name|NVM_CFG1
parameter_list|(
name|x
parameter_list|)
value|g_spad.nvm_cfg.cfg1.x
end_define

begin_define
define|#
directive|define
name|NVM_GLOB
parameter_list|(
name|x
parameter_list|)
value|NVM_CFG1(glob).x
end_define

begin_define
define|#
directive|define
name|NVM_GLOB_VAL
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|,
name|o
parameter_list|)
value|((NVM_GLOB(n)& m)>> o)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MDUMP_PARSE_TOOL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPAD_LAYOUT_H */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for GDB, the GNU debugger.    Copyright 2000    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PPC_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|PPC_TDEP_H
end_define

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|value
struct_decl|;
end_struct_decl

begin_comment
comment|/* From ppc-linux-tdep.c... */
end_comment

begin_function_decl
name|CORE_ADDR
name|ppc_linux_frame_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ppc_linux_init_extra_frame_info
parameter_list|(
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ppc_linux_frameless_function_invocation
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ppc_linux_frame_init_saved_regs
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|ppc_linux_frame_chain
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|ppc_sysv_abi_push_arguments
parameter_list|(
name|int
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|int
parameter_list|,
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ppc_linux_memory_remove_breakpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|char
modifier|*
name|contents_cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|link_map_offsets
modifier|*
name|ppc_linux_svr4_fetch_link_map_offsets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From rs6000-tdep.c... */
end_comment

begin_function_decl
name|CORE_ADDR
name|rs6000_frame_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rs6000_init_extra_frame_info
parameter_list|(
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rs6000_frameless_function_invocation
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rs6000_frame_init_saved_regs
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|rs6000_frame_chain
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|altivec_register_p
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Private data that this module attaches to struct gdbarch. */
end_comment

begin_struct
struct|struct
name|gdbarch_tdep
block|{
name|int
name|wordsize
decl_stmt|;
comment|/* size in bytes of fixed-point word */
name|int
name|osabi
decl_stmt|;
comment|/* OS / ABI from ELF header */
name|int
modifier|*
name|regoff
decl_stmt|;
comment|/* byte offsets in register arrays */
specifier|const
name|struct
name|reg
modifier|*
name|regs
decl_stmt|;
comment|/* from current variant */
name|int
name|ppc_gp0_regnum
decl_stmt|;
comment|/* GPR register 0 */
name|int
name|ppc_gplast_regnum
decl_stmt|;
comment|/* GPR register 31 */
name|int
name|ppc_toc_regnum
decl_stmt|;
comment|/* TOC register */
name|int
name|ppc_ps_regnum
decl_stmt|;
comment|/* Processor (or machine) status (%msr) */
name|int
name|ppc_cr_regnum
decl_stmt|;
comment|/* Condition register */
name|int
name|ppc_lr_regnum
decl_stmt|;
comment|/* Link register */
name|int
name|ppc_ctr_regnum
decl_stmt|;
comment|/* Count register */
name|int
name|ppc_xer_regnum
decl_stmt|;
comment|/* Integer exception register */
name|int
name|ppc_mq_regnum
decl_stmt|;
comment|/* Multiply/Divide extension register */
name|int
name|ppc_vr0_regnum
decl_stmt|;
comment|/* First AltiVec register */
name|int
name|ppc_vrsave_regnum
decl_stmt|;
comment|/* Last AltiVec register */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit


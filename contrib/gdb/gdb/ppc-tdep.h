begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for GDB, the GNU debugger.    Copyright 2000, 2001, 2002, 2003    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
name|gdbarch
struct_decl|;
end_struct_decl

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

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|type
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
name|enum
name|return_value_convention
name|ppc_sysv_abi_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|valtype
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|void
modifier|*
name|readbuf
parameter_list|,
specifier|const
name|void
modifier|*
name|writebuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|return_value_convention
name|ppc_sysv_abi_broken_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|valtype
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|void
modifier|*
name|readbuf
parameter_list|,
specifier|const
name|void
modifier|*
name|writebuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|ppc_sysv_abi_push_dummy_call
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|func_addr
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|CORE_ADDR
name|bp_addr
parameter_list|,
name|int
name|nargs
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|int
name|struct_return
parameter_list|,
name|CORE_ADDR
name|struct_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|ppc64_sysv_abi_push_dummy_call
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|func_addr
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|CORE_ADDR
name|bp_addr
parameter_list|,
name|int
name|nargs
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|int
name|struct_return
parameter_list|,
name|CORE_ADDR
name|struct_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|ppc64_sysv_abi_adjust_breakpoint_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|bpaddr
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

begin_function_decl
name|void
name|ppc_linux_supply_gregset
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ppc_linux_supply_fpregset
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|return_value_convention
name|ppc64_sysv_abi_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|valtype
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|void
modifier|*
name|readbuf
parameter_list|,
specifier|const
name|void
modifier|*
name|writebuf
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
comment|/* Return non-zero when the architecture has an FPU (or at least when    the ABI is using the FPU).  */
end_comment

begin_function_decl
name|int
name|ppc_floating_point_unit_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
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
name|ppc_fpscr_regnum
decl_stmt|;
comment|/* Floating point status and condition     				   register */
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
name|int
name|ppc_ev0_regnum
decl_stmt|;
comment|/* First ev register */
name|int
name|ppc_ev31_regnum
decl_stmt|;
comment|/* Last ev register */
name|int
name|lr_frame_offset
decl_stmt|;
comment|/* Offset to ABI specific location where                                    link register is saved.  */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for SPARC.     Copyright 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPARC_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|SPARC_TDEP_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regset
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trad_frame_saved_reg
struct_decl|;
end_struct_decl

begin_comment
comment|/* Register offsets for the general-purpose register set.  */
end_comment

begin_struct
struct|struct
name|sparc_gregset
block|{
name|int
name|r_psr_offset
decl_stmt|;
name|int
name|r_pc_offset
decl_stmt|;
name|int
name|r_npc_offset
decl_stmt|;
name|int
name|r_y_offset
decl_stmt|;
name|int
name|r_wim_offset
decl_stmt|;
name|int
name|r_tbr_offset
decl_stmt|;
name|int
name|r_g1_offset
decl_stmt|;
name|int
name|r_l0_offset
decl_stmt|;
name|int
name|r_y_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SPARC architecture-specific information.  */
end_comment

begin_struct
struct|struct
name|gdbarch_tdep
block|{
comment|/* Register numbers for the PN and nPC registers.  The definitions      for (64-bit) UltraSPARC differ from the (32-bit) SPARC      definitions.  */
name|int
name|pc_regnum
decl_stmt|;
name|int
name|npc_regnum
decl_stmt|;
comment|/* Register sets.  */
name|struct
name|regset
modifier|*
name|gregset
decl_stmt|;
name|size_t
name|sizeof_gregset
decl_stmt|;
name|struct
name|regset
modifier|*
name|fpregset
decl_stmt|;
name|size_t
name|sizeof_fpregset
decl_stmt|;
comment|/* Offset of saved PC in jmp_buf.  */
name|int
name|jb_pc_offset
decl_stmt|;
comment|/* Size of an Procedure Linkage Table (PLT) entry, 0 if we shouldn't      treat the PLT special when doing prologue analysis.  */
name|size_t
name|plt_entry_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Register numbers of various important registers.  */
end_comment

begin_enum
enum|enum
name|sparc_regnum
block|{
name|SPARC_G0_REGNUM
block|,
comment|/* %g0 */
name|SPARC_G1_REGNUM
block|,
name|SPARC_G2_REGNUM
block|,
name|SPARC_G3_REGNUM
block|,
name|SPARC_G4_REGNUM
block|,
name|SPARC_G5_REGNUM
block|,
name|SPARC_G6_REGNUM
block|,
name|SPARC_G7_REGNUM
block|,
comment|/* %g7 */
name|SPARC_O0_REGNUM
block|,
comment|/* %o0 */
name|SPARC_O1_REGNUM
block|,
name|SPARC_O2_REGNUM
block|,
name|SPARC_O3_REGNUM
block|,
name|SPARC_O4_REGNUM
block|,
name|SPARC_O5_REGNUM
block|,
name|SPARC_SP_REGNUM
block|,
comment|/* %sp (%o6) */
name|SPARC_O7_REGNUM
block|,
comment|/* %o7 */
name|SPARC_L0_REGNUM
block|,
comment|/* %l0 */
name|SPARC_L1_REGNUM
block|,
name|SPARC_L2_REGNUM
block|,
name|SPARC_L3_REGNUM
block|,
name|SPARC_L4_REGNUM
block|,
name|SPARC_L5_REGNUM
block|,
name|SPARC_L6_REGNUM
block|,
name|SPARC_L7_REGNUM
block|,
comment|/* %l7 */
name|SPARC_I0_REGNUM
block|,
comment|/* %i0 */
name|SPARC_I1_REGNUM
block|,
name|SPARC_I2_REGNUM
block|,
name|SPARC_I3_REGNUM
block|,
name|SPARC_I4_REGNUM
block|,
name|SPARC_I5_REGNUM
block|,
name|SPARC_FP_REGNUM
block|,
comment|/* %fp (%i6) */
name|SPARC_I7_REGNUM
block|,
comment|/* %i7 */
name|SPARC_F0_REGNUM
block|,
comment|/* %f0 */
name|SPARC_F1_REGNUM
block|,
name|SPARC_F31_REGNUM
comment|/* %f31 */
init|=
name|SPARC_F0_REGNUM
operator|+
literal|31
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sparc32_regnum
block|{
name|SPARC32_Y_REGNUM
comment|/* %y */
init|=
name|SPARC_F31_REGNUM
operator|+
literal|1
block|,
name|SPARC32_PSR_REGNUM
block|,
comment|/* %psr */
name|SPARC32_WIM_REGNUM
block|,
comment|/* %wim */
name|SPARC32_TBR_REGNUM
block|,
comment|/* %tbr */
name|SPARC32_PC_REGNUM
block|,
comment|/* %pc */
name|SPARC32_NPC_REGNUM
block|,
comment|/* %npc */
name|SPARC32_FSR_REGNUM
block|,
comment|/* %fsr */
name|SPARC32_CSR_REGNUM
block|,
comment|/* %csr */
comment|/* Pseudo registers.  */
name|SPARC32_D0_REGNUM
block|,
comment|/* %d0 */
name|SPARC32_D30_REGNUM
comment|/* %d30 */
init|=
name|SPARC32_D0_REGNUM
operator|+
literal|15
block|}
enum|;
end_enum

begin_escape
end_escape

begin_struct
struct|struct
name|sparc_frame_cache
block|{
comment|/* Base address.  */
name|CORE_ADDR
name|base
decl_stmt|;
name|CORE_ADDR
name|pc
decl_stmt|;
comment|/* Do we have a frame?  */
name|int
name|frameless_p
decl_stmt|;
comment|/* Do we have a Structure, Union or Quad-Precision return value?.  */
name|int
name|struct_return_p
decl_stmt|;
comment|/* Table of saved registers.  */
name|struct
name|trad_frame_saved_reg
modifier|*
name|saved_regs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Fetch the instruction at PC.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|sparc_fetch_instruction
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fetch StackGhost Per-Process XOR cookie.  */
end_comment

begin_function_decl
specifier|extern
name|ULONGEST
name|sparc_fetch_wcookie
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc_analyze_prologue
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|current_pc
parameter_list|,
name|struct
name|sparc_frame_cache
modifier|*
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|sparc_frame_cache
modifier|*
name|sparc_frame_cache
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|,
name|void
modifier|*
modifier|*
name|this_cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|sparc_frame_cache
modifier|*
name|sparc32_frame_cache
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|,
name|void
modifier|*
modifier|*
name|this_cache
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_function_decl
specifier|extern
name|void
name|sparc_software_single_step
parameter_list|(
name|enum
name|target_signal
name|sig
parameter_list|,
name|int
name|insert_breakpoints_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sparc_supply_rwindow
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sparc_collect_rwindow
parameter_list|(
specifier|const
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register offsets for SunOS 4.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sparc_gregset
name|sparc32_sunos4_gregset
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|sparc32_supply_gregset
parameter_list|(
specifier|const
name|struct
name|sparc_gregset
modifier|*
name|gregset
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
specifier|const
name|void
modifier|*
name|gregs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sparc32_collect_gregset
parameter_list|(
specifier|const
name|struct
name|sparc_gregset
modifier|*
name|gregset
parameter_list|,
specifier|const
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|void
modifier|*
name|gregs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sparc32_supply_fpregset
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
specifier|const
name|void
modifier|*
name|fpregs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sparc32_collect_fpregset
parameter_list|(
specifier|const
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
name|void
modifier|*
name|fpregs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions and variables exported from sparc-sol2-tdep.c.  */
end_comment

begin_comment
comment|/* Register offsets for Solaris 2.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sparc_gregset
name|sparc32_sol2_gregset
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|sparc_sol2_pc_in_sigtramp
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sparc32_sol2_init_abi
parameter_list|(
name|struct
name|gdbarch_info
name|info
parameter_list|,
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions and variables exported from sparcnbsd-tdep.c.  */
end_comment

begin_comment
comment|/* Register offsets for NetBSD.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sparc_gregset
name|sparc32nbsd_gregset
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|trad_frame_saved_reg
modifier|*
name|sparc32nbsd_sigcontext_saved_regs
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc-tdep.h */
end_comment

end_unit


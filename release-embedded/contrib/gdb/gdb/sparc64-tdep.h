begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for UltraSPARC.     Copyright 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPARC64_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|SPARC64_TDEP_H
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
name|sparc_gregset
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trad_frame_saved_reg
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"sparc-tdep.h"
end_include

begin_comment
comment|/* The stack pointer is offset from the stack frame by a BIAS of 2047    (0x7ff) for 64-bit code.  BIAS is likely to be defined on SPARC    hosts, so undefine it first.  */
end_comment

begin_undef
undef|#
directive|undef
name|BIAS
end_undef

begin_define
define|#
directive|define
name|BIAS
value|2047
end_define

begin_comment
comment|/* Register offsets for the general-purpose register set.  */
end_comment

begin_comment
comment|/* UltraSPARC doesn't have %psr.  */
end_comment

begin_define
define|#
directive|define
name|r_tstate_offset
value|r_psr_offset
end_define

begin_comment
comment|/* UltraSPARC doesn't have %wim either.  */
end_comment

begin_define
define|#
directive|define
name|r_fprs_offset
value|r_wim_offset
end_define

begin_comment
comment|/* Register numbers of various important registers.  */
end_comment

begin_enum
enum|enum
name|sparc64_regnum
block|{
name|SPARC64_F32_REGNUM
comment|/* %f32 */
init|=
name|SPARC_F0_REGNUM
operator|+
literal|32
block|,
name|SPARC64_F62_REGNUM
comment|/* %f62 */
init|=
name|SPARC64_F32_REGNUM
operator|+
literal|15
block|,
name|SPARC64_PC_REGNUM
block|,
comment|/* %pc */
name|SPARC64_NPC_REGNUM
block|,
comment|/* %npc */
name|SPARC64_STATE_REGNUM
block|,
name|SPARC64_FSR_REGNUM
block|,
comment|/* %fsr */
name|SPARC64_FPRS_REGNUM
block|,
comment|/* %fprs */
name|SPARC64_Y_REGNUM
block|,
comment|/* %y */
comment|/* Pseudo registers.  */
name|SPARC64_CWP_REGNUM
block|,
comment|/* %cwp */
name|SPARC64_PSTATE_REGNUM
block|,
comment|/* %pstate */
name|SPARC64_ASI_REGNUM
block|,
comment|/* %asi */
name|SPARC64_CCR_REGNUM
block|,
comment|/* %ccr */
name|SPARC64_D0_REGNUM
block|,
comment|/* %d0 */
name|SPARC64_D10_REGNUM
comment|/* %d10 */
init|=
name|SPARC64_D0_REGNUM
operator|+
literal|5
block|,
name|SPARC64_D30_REGNUM
comment|/* %d30 */
init|=
name|SPARC64_D0_REGNUM
operator|+
literal|15
block|,
name|SPARC64_D32_REGNUM
comment|/* %d32 */
init|=
name|SPARC64_D0_REGNUM
operator|+
literal|16
block|,
name|SPARC64_D62_REGNUM
comment|/* %d62 */
init|=
name|SPARC64_D0_REGNUM
operator|+
literal|31
block|,
name|SPARC64_Q0_REGNUM
block|,
comment|/* %q0 */
name|SPARC64_Q8_REGNUM
comment|/* %q8 */
init|=
name|SPARC64_Q0_REGNUM
operator|+
literal|2
block|,
name|SPARC64_Q28_REGNUM
comment|/* %q28 */
init|=
name|SPARC64_Q0_REGNUM
operator|+
literal|7
block|,
name|SPARC64_Q32_REGNUM
comment|/* %q32 */
init|=
name|SPARC64_Q0_REGNUM
operator|+
literal|8
block|,
name|SPARC64_Q60_REGNUM
comment|/* %q60 */
init|=
name|SPARC64_Q0_REGNUM
operator|+
literal|15
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|void
name|sparc64_init_abi
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

begin_function_decl
specifier|extern
name|void
name|sparc64_supply_gregset
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
name|sparc64_collect_gregset
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
name|sparc64_supply_fpregset
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
name|sparc64_collect_fpregset
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
comment|/* Functions and variables exported from sparc64-sol2-tdep.c.  */
end_comment

begin_comment
comment|/* Register offsets for Solaris 2.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sparc_gregset
name|sparc64_sol2_gregset
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|sparc64_sol2_init_abi
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
comment|/* Variables exported from sparc64fbsd-tdep.c.  */
end_comment

begin_comment
comment|/* Register offsets for FreeBSD/sparc64.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sparc_gregset
name|sparc64fbsd_gregset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions and variables exported from sparc64nbsd-tdep.c.  */
end_comment

begin_comment
comment|/* Register offsets for NetBSD/sparc64.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sparc_gregset
name|sparc64nbsd_gregset
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|trad_frame_saved_reg
modifier|*
name|sparc64nbsd_sigcontext_saved_regs
parameter_list|(
name|CORE_ADDR
name|sigcontext_addr
parameter_list|,
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
comment|/* sparc64-tdep.h */
end_comment

end_unit


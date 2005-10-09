begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent definitions for AMD64.     Copyright 2001, 2003, 2004 Free Software Foundation, Inc.    Contributed by Jiri Smid, SuSE Labs.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMD64_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|AMD64_TDEP_H
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
name|regcache
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"i386-tdep.h"
end_include

begin_comment
comment|/* Register numbers of various important registers.  */
end_comment

begin_enum
enum|enum
name|amd64_regnum
block|{
name|AMD64_RAX_REGNUM
block|,
comment|/* %rax */
name|AMD64_RBX_REGNUM
block|,
comment|/* %rbx */
name|AMD64_RCX_REGNUM
block|,
comment|/* %rcx */
name|AMD64_RDX_REGNUM
block|,
comment|/* %rdx */
name|AMD64_RSI_REGNUM
block|,
comment|/* %rsi */
name|AMD64_RDI_REGNUM
block|,
comment|/* %rdi */
name|AMD64_RBP_REGNUM
block|,
comment|/* %rbp */
name|AMD64_RSP_REGNUM
block|,
comment|/* %rsp */
name|AMD64_R8_REGNUM
init|=
literal|8
block|,
comment|/* %r8 */
name|AMD64_R15_REGNUM
init|=
literal|15
block|,
comment|/* %r15 */
name|AMD64_RIP_REGNUM
block|,
comment|/* %rip */
name|AMD64_EFLAGS_REGNUM
block|,
comment|/* %eflags */
name|AMD64_ST0_REGNUM
init|=
literal|24
block|,
comment|/* %st0 */
name|AMD64_XMM0_REGNUM
init|=
literal|40
block|,
comment|/* %xmm0 */
name|AMD64_XMM1_REGNUM
comment|/* %xmm1 */
block|}
enum|;
end_enum

begin_comment
comment|/* Number of general purpose registers.  */
end_comment

begin_define
define|#
directive|define
name|AMD64_NUM_GREGS
value|24
end_define

begin_function_decl
specifier|extern
name|void
name|amd64_init_abi
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
comment|/* Fill register REGNUM in REGCACHE with the appropriate    floating-point or SSE register value from *FXSAVE.  If REGNUM is    -1, do this for all registers.  This function masks off any of the    reserved bits in *FXSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|amd64_supply_fxsave
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
name|fxsave
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill register REGNUM (if it is a floating-point or SSE register) in    *FXSAVE with the value from REGCACHE.  If REGNUM is -1, do this for    all registers.  This function doesn't touch any of the reserved    bits in *FXSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|amd64_collect_fxsave
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
name|fxsave
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill register REGNUM (if it is a floating-point or SSE register) in    *FXSAVE with the value in GDB's register cache.  If REGNUM is -1, do    this for all registers.  This function doesn't touch any of the    reserved bits in *FXSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|amd64_fill_fxsave
parameter_list|(
name|char
modifier|*
name|fxsave
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Variables exported from amd64nbsd-tdep.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|amd64nbsd_r_reg_offset
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables exported from amd64obsd-tdep.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|amd64obsd_r_reg_offset
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables exported from amd64fbsd-tdep.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|amd64fbsd_sigtramp_start_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|amd64fbsd_sigtramp_end_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|amd64fbsd_sc_reg_offset
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* amd64-tdep.h */
end_comment

end_unit


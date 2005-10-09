begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for the i386.     Copyright 2001, 2002, 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I386_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|I386_TDEP_H
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
name|reggroup
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regset
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_comment
comment|/* GDB's i386 target supports both the 32-bit Intel Architecture    (IA-32) and the 64-bit AMD x86-64 architecture.  Internally it uses    a similar register layout for both.     - General purpose registers    - FPU data registers    - FPU control registers    - SSE data registers    - SSE control register     The general purpose registers for the x86-64 architecture are quite    different from IA-32.  Therefore, the FP0_REGNUM target macro    determines the register number at which the FPU data registers    start.  The number of FPU data and control registers is the same    for both architectures.  The number of SSE registers however,    differs and is determined by the num_xmm_regs member of `struct    gdbarch_tdep'.  */
end_comment

begin_comment
comment|/* Convention for returning structures.  */
end_comment

begin_enum
enum|enum
name|struct_return
block|{
name|pcc_struct_return
block|,
comment|/* Return "short" structures in memory.  */
name|reg_struct_return
comment|/* Return "short" structures in registers.  */
block|}
enum|;
end_enum

begin_comment
comment|/* i386 architecture specific information.  */
end_comment

begin_struct
struct|struct
name|gdbarch_tdep
block|{
comment|/* General-purpose registers.  */
name|struct
name|regset
modifier|*
name|gregset
decl_stmt|;
name|int
modifier|*
name|gregset_reg_offset
decl_stmt|;
name|int
name|gregset_num_regs
decl_stmt|;
name|size_t
name|sizeof_gregset
decl_stmt|;
comment|/* Floating-point registers.  */
name|struct
name|regset
modifier|*
name|fpregset
decl_stmt|;
name|size_t
name|sizeof_fpregset
decl_stmt|;
comment|/* Register number for %st(0).  The register numbers for the other      registers follow from this one.  Set this to -1 to indicate the      absence of an FPU.  */
name|int
name|st0_regnum
decl_stmt|;
comment|/* Register number for %mm0.  Set this to -1 to indicate the absence      of MMX support.  */
name|int
name|mm0_regnum
decl_stmt|;
comment|/* Number of SSE registers.  */
name|int
name|num_xmm_regs
decl_stmt|;
comment|/* Offset of saved PC in jmp_buf.  */
name|int
name|jb_pc_offset
decl_stmt|;
comment|/* Convention for returning structures.  */
name|enum
name|struct_return
name|struct_return
decl_stmt|;
comment|/* Address range where sigtramp lives.  */
name|CORE_ADDR
name|sigtramp_start
decl_stmt|;
name|CORE_ADDR
name|sigtramp_end
decl_stmt|;
comment|/* Get address of sigcontext for sigtramp.  */
name|CORE_ADDR
function_decl|(
modifier|*
name|sigcontext_addr
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
comment|/* Offset of registers in `struct sigcontext'.  */
name|int
modifier|*
name|sc_reg_offset
decl_stmt|;
name|int
name|sc_num_regs
decl_stmt|;
comment|/* Offset of saved PC and SP in `struct sigcontext'.  Usage of these      is deprecated, please use `sc_reg_offset' instead.  */
name|int
name|sc_pc_offset
decl_stmt|;
name|int
name|sc_sp_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Floating-point registers.  */
end_comment

begin_comment
comment|/* All FPU control regusters (except for FIOFF and FOOFF) are 16-bit    (at most) in the FPU, but are zero-extended to 32 bits in GDB's    register cache.  */
end_comment

begin_comment
comment|/* "Generic" floating point control register.  */
end_comment

begin_define
define|#
directive|define
name|FPC_REGNUM
value|(FP0_REGNUM + 8)
end_define

begin_comment
comment|/* FPU control word.  */
end_comment

begin_define
define|#
directive|define
name|FCTRL_REGNUM
value|FPC_REGNUM
end_define

begin_comment
comment|/* FPU status word.  */
end_comment

begin_define
define|#
directive|define
name|FSTAT_REGNUM
value|(FPC_REGNUM + 1)
end_define

begin_comment
comment|/* FPU register tag word.  */
end_comment

begin_define
define|#
directive|define
name|FTAG_REGNUM
value|(FPC_REGNUM + 2)
end_define

begin_comment
comment|/* FPU instruction's code segment selector, called "FPU Instruction    Pointer Selector" in the IA-32 manuals.  */
end_comment

begin_define
define|#
directive|define
name|FISEG_REGNUM
value|(FPC_REGNUM + 3)
end_define

begin_comment
comment|/* FPU instruction's offset within segment.  */
end_comment

begin_define
define|#
directive|define
name|FIOFF_REGNUM
value|(FPC_REGNUM + 4)
end_define

begin_comment
comment|/* FPU operand's data segment.  */
end_comment

begin_define
define|#
directive|define
name|FOSEG_REGNUM
value|(FPC_REGNUM + 5)
end_define

begin_comment
comment|/* FPU operand's offset within segment */
end_comment

begin_define
define|#
directive|define
name|FOOFF_REGNUM
value|(FPC_REGNUM + 6)
end_define

begin_comment
comment|/* FPU opcode, bottom eleven bits.  */
end_comment

begin_define
define|#
directive|define
name|FOP_REGNUM
value|(FPC_REGNUM + 7)
end_define

begin_comment
comment|/* Return non-zero if REGNUM matches the FP register and the FP    register set is active.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|i386_fp_regnum_p
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i386_fpc_regnum_p
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* SSE registers.  */
end_comment

begin_comment
comment|/* First SSE data register.  */
end_comment

begin_define
define|#
directive|define
name|XMM0_REGNUM
value|(FPC_REGNUM + 8)
end_define

begin_comment
comment|/* SSE control/status register.  */
end_comment

begin_define
define|#
directive|define
name|MXCSR_REGNUM
define|\
value|(XMM0_REGNUM + gdbarch_tdep (current_gdbarch)->num_xmm_regs)
end_define

begin_comment
comment|/* Register numbers of various important registers.  */
end_comment

begin_enum
enum|enum
name|i386_regnum
block|{
name|I386_EAX_REGNUM
block|,
comment|/* %eax */
name|I386_ECX_REGNUM
block|,
comment|/* %ecx */
name|I386_EDX_REGNUM
block|,
comment|/* %edx */
name|I386_EBX_REGNUM
block|,
comment|/* %ebx */
name|I386_ESP_REGNUM
block|,
comment|/* %esp */
name|I386_EBP_REGNUM
block|,
comment|/* %ebp */
name|I386_ESI_REGNUM
block|,
comment|/* %esi */
name|I386_EDI_REGNUM
block|,
comment|/* %edi */
name|I386_EIP_REGNUM
block|,
comment|/* %eip */
name|I386_EFLAGS_REGNUM
block|,
comment|/* %eflags */
name|I386_CS_REGNUM
block|,
comment|/* %cs */
name|I386_SS_REGNUM
block|,
comment|/* %ss */
name|I386_DS_REGNUM
block|,
comment|/* %ds */
name|I386_ES_REGNUM
block|,
comment|/* %es */
name|I386_FS_REGNUM
block|,
comment|/* %fs */
name|I386_GS_REGNUM
block|,
comment|/* %gs */
name|I386_ST0_REGNUM
comment|/* %st(0) */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|I386_NUM_GREGS
value|16
end_define

begin_define
define|#
directive|define
name|I386_NUM_FREGS
value|16
end_define

begin_define
define|#
directive|define
name|I386_NUM_XREGS
value|9
end_define

begin_define
define|#
directive|define
name|I386_SSE_NUM_REGS
value|(I386_NUM_GREGS + I386_NUM_FREGS \ 				 + I386_NUM_XREGS)
end_define

begin_comment
comment|/* Size of the largest register.  */
end_comment

begin_define
define|#
directive|define
name|I386_MAX_REGISTER_SIZE
value|16
end_define

begin_comment
comment|/* Functions exported from i386-tdep.c.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_pe_skip_trampoline_code
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
name|int
name|i386_frameless_signal_p
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the name of register REG.  */
end_comment

begin_function_decl
specifier|extern
name|char
specifier|const
modifier|*
name|i386_register_name
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return non-zero if REGNUM is a member of the specified group.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|i386_register_reggroup_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|,
name|struct
name|reggroup
modifier|*
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Supply register REGNUM from the general-purpose register set REGSET    to register cache REGCACHE.  If REGNUM is -1, do this for all    registers in REGSET.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i386_supply_gregset
parameter_list|(
specifier|const
name|struct
name|regset
modifier|*
name|regset
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
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the appropriate register set for the core section identified    by SECT_NAME and SECT_SIZE.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|struct
name|regset
modifier|*
name|i386_regset_from_core_section
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|char
modifier|*
name|sect_name
parameter_list|,
name|size_t
name|sect_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize a basic ELF architecture variant.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i386_elf_init_abi
parameter_list|(
name|struct
name|gdbarch_info
parameter_list|,
name|struct
name|gdbarch
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize a SVR4 architecture variant.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i386_svr4_init_abi
parameter_list|(
name|struct
name|gdbarch_info
parameter_list|,
name|struct
name|gdbarch
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Functions and variables exported from i386bsd-tdep.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i386bsd_init_abi
parameter_list|(
name|struct
name|gdbarch_info
parameter_list|,
name|struct
name|gdbarch
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i386bsd_pc_in_sigtramp
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
name|CORE_ADDR
name|i386bsd_sigtramp_start
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386bsd_sigtramp_end
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|i386fbsd_sigtramp_start_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|i386fbsd_sigtramp_end_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|i386obsd_sigtramp_start_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|i386obsd_sigtramp_end_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i386fbsd4_sc_reg_offset
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i386fbsd_sc_reg_offset
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i386nbsd_sc_reg_offset
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i386obsd_sc_reg_offset
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i386bsd_sc_reg_offset
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i386-tdep.h */
end_comment

end_unit


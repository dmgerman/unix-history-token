begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common target dependent code for GDB on Alpha systems.    Copyright 1993, 1994, 1995, 1996, 1998, 1999, 2000, 2002, 2003 Free    Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALPHA_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|ALPHA_TDEP_H
end_define

begin_comment
comment|/* Say how long (ordinary) registers are.  This is a piece of bogosity    used in push_word and a few other places;    DEPRECATED_REGISTER_RAW_SIZE is the real way to know how big a    register is.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_REGISTER_SIZE
value|8
end_define

begin_comment
comment|/* Number of machine registers.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_NUM_REGS
value|67
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_REGISTER_BYTES
value|(ALPHA_NUM_REGS * 8)
end_define

begin_comment
comment|/* Register numbers of various important registers.  Note that most of    these values are "real" register numbers, and correspond to the    general registers of the machine.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_V0_REGNUM
value|0
end_define

begin_comment
comment|/* Function integer return value */
end_comment

begin_define
define|#
directive|define
name|ALPHA_T7_REGNUM
value|8
end_define

begin_comment
comment|/* Return address register for OSF/1 __add* */
end_comment

begin_define
define|#
directive|define
name|ALPHA_GCC_FP_REGNUM
value|15
end_define

begin_comment
comment|/* Used by gcc as frame register */
end_comment

begin_define
define|#
directive|define
name|ALPHA_A0_REGNUM
value|16
end_define

begin_comment
comment|/* Loc of first arg during a subr call */
end_comment

begin_define
define|#
directive|define
name|ALPHA_T9_REGNUM
value|23
end_define

begin_comment
comment|/* Return address register for OSF/1 __div* */
end_comment

begin_define
define|#
directive|define
name|ALPHA_RA_REGNUM
value|26
end_define

begin_comment
comment|/* Contains return address value */
end_comment

begin_define
define|#
directive|define
name|ALPHA_T12_REGNUM
value|27
end_define

begin_comment
comment|/* Contains start addr of current proc */
end_comment

begin_define
define|#
directive|define
name|ALPHA_GP_REGNUM
value|29
end_define

begin_comment
comment|/* Contains the global pointer */
end_comment

begin_define
define|#
directive|define
name|ALPHA_SP_REGNUM
value|30
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|ALPHA_ZERO_REGNUM
value|31
end_define

begin_comment
comment|/* Read-only register, always 0 */
end_comment

begin_define
define|#
directive|define
name|ALPHA_FP0_REGNUM
value|32
end_define

begin_comment
comment|/* Floating point register 0 */
end_comment

begin_define
define|#
directive|define
name|ALPHA_FPA0_REGNUM
value|48
end_define

begin_comment
comment|/* First float arg during a subr call */
end_comment

begin_define
define|#
directive|define
name|ALPHA_FPCR_REGNUM
value|63
end_define

begin_comment
comment|/* Floating point control register */
end_comment

begin_define
define|#
directive|define
name|ALPHA_PC_REGNUM
value|64
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|ALPHA_UNIQUE_REGNUM
value|66
end_define

begin_comment
comment|/* PAL_rduniq value */
end_comment

begin_comment
comment|/* The alpha has two different virtual pointers for arguments and locals.        The virtual argument pointer is pointing to the bottom of the argument    transfer area, which is located immediately below the virtual frame    pointer. Its size is fixed for the native compiler, it is either zero    (for the no arguments case) or large enough to hold all argument registers.    gcc uses a variable sized argument transfer area. As it has    to stay compatible with the native debugging tools it has to use the same    virtual argument pointer and adjust the argument offsets accordingly.        The virtual local pointer is localoff bytes below the virtual frame    pointer, the value of localoff is obtained from the PDR.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_NUM_ARG_REGS
value|6
end_define

begin_comment
comment|/* Target-dependent structure in gdbarch.  */
end_comment

begin_struct
struct|struct
name|gdbarch_tdep
block|{
name|CORE_ADDR
name|vm_min_address
decl_stmt|;
comment|/* Used by alpha_heuristic_proc_start.  */
comment|/* If PC is inside a dynamically-generated signal trampoline function      (i.e. one copied onto the user stack at run-time), return how many      bytes PC is beyond the start of that function.  Otherwise, return -1.  */
name|LONGEST
function_decl|(
modifier|*
name|dynamic_sigtramp_offset
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
comment|/* Translate a signal handler stack base address into the address of      the sigcontext structure for that signal handler.  */
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
name|sc_pc_offset
decl_stmt|;
name|int
name|sc_regs_offset
decl_stmt|;
name|int
name|sc_fpregs_offset
decl_stmt|;
name|int
name|jb_pc
decl_stmt|;
comment|/* Offset to PC value in jump buffer. 				   If htis is negative, longjmp support 				   will be disabled.  */
name|size_t
name|jb_elt_size
decl_stmt|;
comment|/* And the size of each entry in the buf. */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|unsigned
name|int
name|alpha_read_insn
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_software_single_step
parameter_list|(
name|enum
name|target_signal
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|alpha_after_prologue
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_mdebug_init_abi
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
name|void
name|alpha_dwarf2_init_abi
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
name|void
name|alpha_supply_int_regs
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_fill_int_regs
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_supply_fp_regs
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alpha_fill_fp_regs
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALPHA_TDEP_H */
end_comment

end_unit


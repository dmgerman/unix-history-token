begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common target dependent code for GDB on ARM systems.    Copyright 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Register numbers of various important registers.  Note that some of    these values are "real" register numbers, and correspond to the    general registers of the machine, and some are "phony" register    numbers which are too large to be actual register numbers as far as    the user is concerned but do serve to get the desired values when    passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|ARM_A1_REGNUM
value|0
end_define

begin_comment
comment|/* first integer-like argument */
end_comment

begin_define
define|#
directive|define
name|ARM_A4_REGNUM
value|3
end_define

begin_comment
comment|/* last integer-like argument */
end_comment

begin_define
define|#
directive|define
name|ARM_AP_REGNUM
value|11
end_define

begin_define
define|#
directive|define
name|ARM_SP_REGNUM
value|13
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|ARM_LR_REGNUM
value|14
end_define

begin_comment
comment|/* address to return to from a function call */
end_comment

begin_define
define|#
directive|define
name|ARM_PC_REGNUM
value|15
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|ARM_F0_REGNUM
value|16
end_define

begin_comment
comment|/* first floating point register */
end_comment

begin_define
define|#
directive|define
name|ARM_F3_REGNUM
value|19
end_define

begin_comment
comment|/* last floating point argument register */
end_comment

begin_define
define|#
directive|define
name|ARM_F7_REGNUM
value|23
end_define

begin_comment
comment|/* last floating point register */
end_comment

begin_define
define|#
directive|define
name|ARM_FPS_REGNUM
value|24
end_define

begin_comment
comment|/* floating point status register */
end_comment

begin_define
define|#
directive|define
name|ARM_PS_REGNUM
value|25
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|ARM_FP_REGNUM
value|11
end_define

begin_comment
comment|/* Frame register in ARM code, if used.  */
end_comment

begin_define
define|#
directive|define
name|THUMB_FP_REGNUM
value|7
end_define

begin_comment
comment|/* Frame register in Thumb code, if used.  */
end_comment

begin_define
define|#
directive|define
name|ARM_NUM_ARG_REGS
value|4
end_define

begin_define
define|#
directive|define
name|ARM_LAST_ARG_REGNUM
value|ARM_A4_REGNUM
end_define

begin_define
define|#
directive|define
name|ARM_NUM_FP_ARG_REGS
value|4
end_define

begin_define
define|#
directive|define
name|ARM_LAST_FP_ARG_REGNUM
value|ARM_F3_REGNUM
end_define

begin_comment
comment|/* Size of integer registers.  */
end_comment

begin_define
define|#
directive|define
name|INT_REGISTER_RAW_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|INT_REGISTER_VIRTUAL_SIZE
value|4
end_define

begin_comment
comment|/* Say how long FP registers are.  Used for documentation purposes and    code readability in this header.  IEEE extended doubles are 80    bits.  DWORD aligned they use 96 bits.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGISTER_RAW_SIZE
value|12
end_define

begin_comment
comment|/* GCC doesn't support long doubles (extended IEEE values).  The FP    register virtual size is therefore 64 bits.  Used for documentation    purposes and code readability in this header.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGISTER_VIRTUAL_SIZE
value|8
end_define

begin_comment
comment|/* Status registers are the same size as general purpose registers.    Used for documentation purposes and code readability in this    header.  */
end_comment

begin_define
define|#
directive|define
name|STATUS_REGISTER_SIZE
value|4
end_define

begin_comment
comment|/* Number of machine registers.  The only define actually required     is NUM_REGS.  The other definitions are used for documentation    purposes and code readability.  */
end_comment

begin_comment
comment|/* For 26 bit ARM code, a fake copy of the PC is placed in register 25 (PS)    (and called PS for processor status) so the status bits can be cleared    from the PC (register 15).  For 32 bit ARM code, a copy of CPSR is placed    in PS.  */
end_comment

begin_define
define|#
directive|define
name|NUM_FREGS
value|8
end_define

begin_comment
comment|/* Number of floating point registers.  */
end_comment

begin_define
define|#
directive|define
name|NUM_SREGS
value|2
end_define

begin_comment
comment|/* Number of status registers.  */
end_comment

begin_define
define|#
directive|define
name|NUM_GREGS
value|16
end_define

begin_comment
comment|/* Number of general purpose registers.  */
end_comment

begin_comment
comment|/* Instruction condition field values.  */
end_comment

begin_define
define|#
directive|define
name|INST_EQ
value|0x0
end_define

begin_define
define|#
directive|define
name|INST_NE
value|0x1
end_define

begin_define
define|#
directive|define
name|INST_CS
value|0x2
end_define

begin_define
define|#
directive|define
name|INST_CC
value|0x3
end_define

begin_define
define|#
directive|define
name|INST_MI
value|0x4
end_define

begin_define
define|#
directive|define
name|INST_PL
value|0x5
end_define

begin_define
define|#
directive|define
name|INST_VS
value|0x6
end_define

begin_define
define|#
directive|define
name|INST_VC
value|0x7
end_define

begin_define
define|#
directive|define
name|INST_HI
value|0x8
end_define

begin_define
define|#
directive|define
name|INST_LS
value|0x9
end_define

begin_define
define|#
directive|define
name|INST_GE
value|0xa
end_define

begin_define
define|#
directive|define
name|INST_LT
value|0xb
end_define

begin_define
define|#
directive|define
name|INST_GT
value|0xc
end_define

begin_define
define|#
directive|define
name|INST_LE
value|0xd
end_define

begin_define
define|#
directive|define
name|INST_AL
value|0xe
end_define

begin_define
define|#
directive|define
name|INST_NV
value|0xf
end_define

begin_define
define|#
directive|define
name|FLAG_N
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FLAG_Z
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FLAG_C
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FLAG_V
value|0x10000000
end_define

begin_comment
comment|/* ABI variants that we know about.  If you add to this enum, please     update the table of names in tm-arm.c.  */
end_comment

begin_enum
enum|enum
name|arm_abi
block|{
name|ARM_ABI_UNKNOWN
init|=
literal|0
block|,
name|ARM_ABI_EABI_V1
block|,
name|ARM_ABI_EABI_V2
block|,
name|ARM_ABI_LINUX
block|,
name|ARM_ABI_NETBSD_AOUT
block|,
name|ARM_ABI_NETBSD_ELF
block|,
name|ARM_ABI_APCS
block|,
name|ARM_ABI_FREEBSD
block|,
name|ARM_ABI_WINCE
block|,
name|ARM_ABI_INVALID
comment|/* Keep this last.  */
block|}
enum|;
end_enum

begin_comment
comment|/* Type of floating-point code in use by inferior.  There are really 3 models    that are traditionally supported (plus the endianness issue), but gcc can    only generate 2 of those.  The third is APCS_FLOAT, where arguments to    functions are passed in floating-point registers.       In addition to the traditional models, VFP adds two more.  */
end_comment

begin_enum
enum|enum
name|arm_float_model
block|{
name|ARM_FLOAT_SOFT
block|,
name|ARM_FLOAT_FPA
block|,
name|ARM_FLOAT_SOFT_VFP
block|,
name|ARM_FLOAT_VFP
block|}
enum|;
end_enum

begin_comment
comment|/* Target-dependent structure in gdbarch.  */
end_comment

begin_struct
struct|struct
name|gdbarch_tdep
block|{
name|enum
name|arm_abi
name|arm_abi
decl_stmt|;
comment|/* OS/ABI of inferior.  */
specifier|const
name|char
modifier|*
name|abi_name
decl_stmt|;
comment|/* Name of the above.  */
name|enum
name|arm_float_model
name|fp_model
decl_stmt|;
comment|/* Floating point calling conventions.  */
name|CORE_ADDR
name|lowest_pc
decl_stmt|;
comment|/* Lowest address at which instructions  				   will appear.  */
specifier|const
name|char
modifier|*
name|arm_breakpoint
decl_stmt|;
comment|/* Breakpoint pattern for an ARM insn.  */
name|int
name|arm_breakpoint_size
decl_stmt|;
comment|/* And its size.  */
specifier|const
name|char
modifier|*
name|thumb_breakpoint
decl_stmt|;
comment|/* Breakpoint pattern for an ARM insn.  */
name|int
name|thumb_breakpoint_size
decl_stmt|;
comment|/* And its size.  */
name|int
name|jb_pc
decl_stmt|;
comment|/* Offset to PC value in jump buffer.  				   If this is negative, longjmp support 				   will be disabled.  */
name|size_t
name|jb_elt_size
decl_stmt|;
comment|/* And the size of each entry in the buf.  */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|LOWEST_PC
end_ifndef

begin_define
define|#
directive|define
name|LOWEST_PC
value|(gdbarch_tdep (current_gdbarch)->lowest_pc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Prototypes for internal interfaces needed by more than one MD file.  */
end_comment

begin_function_decl
name|int
name|arm_pc_is_thumb_dummy
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_pc_is_thumb
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|thumb_get_next_pc
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|arm_get_next_pc
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* How a OS variant tells the ARM generic code that it can handle an ABI    type. */
end_comment

begin_function_decl
name|void
name|arm_gdbarch_register_os_abi
parameter_list|(
name|enum
name|arm_abi
name|abi
parameter_list|,
name|void
function_decl|(
modifier|*
name|init_abi
function_decl|)
parameter_list|(
name|struct
name|gdbarch_info
parameter_list|,
name|struct
name|gdbarch
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common target dependent code for GDB on ARM systems.    Copyright 2002, 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Register numbers of various important registers.  Note that some of    these values are "real" register numbers, and correspond to the    general registers of the machine, and some are "phony" register    numbers which are too large to be actual register numbers as far as    the user is concerned but do serve to get the desired values when    passed to read_register.  */
end_comment

begin_enum
enum|enum
name|gdb_regnum
block|{
name|ARM_A1_REGNUM
init|=
literal|0
block|,
comment|/* first integer-like argument */
name|ARM_A4_REGNUM
init|=
literal|3
block|,
comment|/* last integer-like argument */
name|ARM_AP_REGNUM
init|=
literal|11
block|,
name|ARM_SP_REGNUM
init|=
literal|13
block|,
comment|/* Contains address of top of stack */
name|ARM_LR_REGNUM
init|=
literal|14
block|,
comment|/* address to return to from a function call */
name|ARM_PC_REGNUM
init|=
literal|15
block|,
comment|/* Contains program counter */
name|ARM_F0_REGNUM
init|=
literal|16
block|,
comment|/* first floating point register */
name|ARM_F3_REGNUM
init|=
literal|19
block|,
comment|/* last floating point argument register */
name|ARM_F7_REGNUM
init|=
literal|23
block|,
comment|/* last floating point register */
name|ARM_FPS_REGNUM
init|=
literal|24
block|,
comment|/* floating point status register */
name|ARM_PS_REGNUM
init|=
literal|25
block|,
comment|/* Contains processor status */
name|ARM_FP_REGNUM
init|=
literal|11
block|,
comment|/* Frame register in ARM code, if used.  */
name|THUMB_FP_REGNUM
init|=
literal|7
block|,
comment|/* Frame register in Thumb code, if used.  */
name|ARM_NUM_ARG_REGS
init|=
literal|4
block|,
name|ARM_LAST_ARG_REGNUM
init|=
name|ARM_A4_REGNUM
block|,
name|ARM_NUM_FP_ARG_REGS
init|=
literal|4
block|,
name|ARM_LAST_FP_ARG_REGNUM
init|=
name|ARM_F3_REGNUM
block|}
enum|;
end_enum

begin_comment
comment|/* Size of integer registers.  */
end_comment

begin_define
define|#
directive|define
name|INT_REGISTER_SIZE
value|4
end_define

begin_comment
comment|/* Say how long FP registers are.  Used for documentation purposes and    code readability in this header.  IEEE extended doubles are 80    bits.  DWORD aligned they use 96 bits.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGISTER_SIZE
value|12
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
comment|/* Type of floating-point code in use by inferior.  There are really 3 models    that are traditionally supported (plus the endianness issue), but gcc can    only generate 2 of those.  The third is APCS_FLOAT, where arguments to    functions are passed in floating-point registers.       In addition to the traditional models, VFP adds two more.      If you update this enum, don't forget to update fp_model_strings in     arm-tdep.c.  */
end_comment

begin_enum
enum|enum
name|arm_float_model
block|{
name|ARM_FLOAT_AUTO
block|,
comment|/* Automatic detection.  Do not set in tdep.  */
name|ARM_FLOAT_SOFT_FPA
block|,
comment|/* Traditional soft-float (mixed-endian on LE ARM).  */
name|ARM_FLOAT_FPA
block|,
comment|/* FPA co-processor.  GCC calling convention.  */
name|ARM_FLOAT_SOFT_VFP
block|,
comment|/* Soft-float with pure-endian doubles.  */
name|ARM_FLOAT_VFP
block|,
comment|/* Full VFP calling convention.  */
name|ARM_FLOAT_LAST
comment|/* Keep at end.  */
block|}
enum|;
end_enum

begin_comment
comment|/* A method to the setting based on user's choice and ABI setting.  */
end_comment

begin_function_decl
name|enum
name|arm_float_model
name|arm_get_fp_model
parameter_list|(
name|struct
name|gdbarch
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Target-dependent structure in gdbarch.  */
end_comment

begin_struct
struct|struct
name|gdbarch_tdep
block|{
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

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for GDB, the GNU debugger.    Copyright 2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* GDB's i386 target supports both the 32-bit Intel Architecture    (IA-32) and the 64-bit AMD x86-64 architecture.  Internally it uses    a similar register layout for both.     - General purpose registers    - FPU data registers    - FPU control registers    - SSE data registers    - SSE control register     The general purpose registers for the x86-64 architecture are quite    different from IA-32.  Therefore, the FP0_REGNUM target macro    determines the register number at which the FPU data registers    start.  The number of FPU data and control registers is the same    for both architectures.  The number of SSE registers however,    differs and is determined by the num_xmm_regs member of `struct    gdbarch_tdep'.  */
end_comment

begin_comment
comment|/* i386 architecture specific information.  */
end_comment

begin_struct
struct|struct
name|gdbarch_tdep
block|{
comment|/* OS/ABI.  */
name|int
name|os_ident
decl_stmt|;
comment|/* Number of SSE registers.  */
name|int
name|num_xmm_regs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Floating-point registers.  */
end_comment

begin_define
define|#
directive|define
name|FPU_REG_RAW_SIZE
value|10
end_define

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
comment|/* Return non-zero if N corresponds to a FPU data registers.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM_P
parameter_list|(
name|n
parameter_list|)
value|(FP0_REGNUM<= (n)&& (n)< FPC_REGNUM)
end_define

begin_comment
comment|/* Return non-zero if N corresponds to a FPU control register.  */
end_comment

begin_define
define|#
directive|define
name|FPC_REGNUM_P
parameter_list|(
name|n
parameter_list|)
value|(FPC_REGNUM<= (n)&& (n)< XMM0_REGNUM)
end_define

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
comment|/* Return non-zero if N corresponds to a SSE data register.  */
end_comment

begin_define
define|#
directive|define
name|SSE_REGNUM_P
parameter_list|(
name|n
parameter_list|)
value|(XMM0_REGNUM<= (n)&& (n)< MXCSR_REGNUM)
end_define

begin_comment
comment|/* FIXME: kettenis/2001-11-24: Obsolete macro's.  */
end_comment

begin_define
define|#
directive|define
name|FCS_REGNUM
value|FISEG_REGNUM
end_define

begin_define
define|#
directive|define
name|FCOFF_REGNUM
value|FIOFF_REGNUM
end_define

begin_define
define|#
directive|define
name|FDS_REGNUM
value|FOSEG_REGNUM
end_define

begin_define
define|#
directive|define
name|FDOFF_REGNUM
value|FOOFF_REGNUM
end_define

begin_define
define|#
directive|define
name|IS_FP_REGNUM
parameter_list|(
name|n
parameter_list|)
value|FP_REGNUM_P (n)
end_define

begin_define
define|#
directive|define
name|IS_FPU_CTRL_REGNUM
parameter_list|(
name|n
parameter_list|)
value|FPC_REGNUM_P (n)
end_define

begin_define
define|#
directive|define
name|IS_SSE_REGNUM
parameter_list|(
name|n
parameter_list|)
value|SSE_REGNUM_P (n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i386-tdep.h */
end_comment

end_unit


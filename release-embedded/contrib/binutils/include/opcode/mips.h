begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mips.h.  Mips opcode list for GDB, the GNU debugger.    Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,    2003, 2004, 2005    Free Software Foundation, Inc.    Contributed by Ralph Campbell and OSF    Commented and modified by Ian Lance Taylor, Cygnus Support  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_H_
end_define

begin_comment
comment|/* These are bit masks and shift counts to use to access the various    fields of an instruction.  To retrieve the X field of an    instruction, use the expression 	(i>> OP_SH_X)& OP_MASK_X    To set the same field (to j), use 	i = (i&~ (OP_MASK_X<< OP_SH_X)) | (j<< OP_SH_X)     Make sure you use fields that are appropriate for the instruction,    of course.     The 'i' format uses OP, RS, RT and IMMEDIATE.     The 'j' format uses OP and TARGET.     The 'r' format uses OP, RS, RT, RD, SHAMT and FUNCT.     The 'b' format uses OP, RS, RT and DELTA.     The floating point 'i' format uses OP, RS, RT and IMMEDIATE.     The floating point 'r' format uses OP, FMT, FT, FS, FD and FUNCT.     A breakpoint instruction uses OP, CODE and SPEC (10 bits of the    breakpoint instruction are not defined; Kane says the breakpoint    code field in BREAK is 20 bits; yet MIPS assemblers and debuggers    only use ten bits).  An optional two-operand form of break/sdbbp    allows the lower ten bits to be set too, and MIPS32 and later    architectures allow 20 bits to be set with a signal operand    (using CODE20).     The syscall instruction uses CODE20.     The general coprocessor instructions use COPZ.  */
end_comment

begin_define
define|#
directive|define
name|OP_MASK_OP
value|0x3f
end_define

begin_define
define|#
directive|define
name|OP_SH_OP
value|26
end_define

begin_define
define|#
directive|define
name|OP_MASK_RS
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_RS
value|21
end_define

begin_define
define|#
directive|define
name|OP_MASK_FR
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_FR
value|21
end_define

begin_define
define|#
directive|define
name|OP_MASK_FMT
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_FMT
value|21
end_define

begin_define
define|#
directive|define
name|OP_MASK_BCC
value|0x7
end_define

begin_define
define|#
directive|define
name|OP_SH_BCC
value|18
end_define

begin_define
define|#
directive|define
name|OP_MASK_CODE
value|0x3ff
end_define

begin_define
define|#
directive|define
name|OP_SH_CODE
value|16
end_define

begin_define
define|#
directive|define
name|OP_MASK_CODE2
value|0x3ff
end_define

begin_define
define|#
directive|define
name|OP_SH_CODE2
value|6
end_define

begin_define
define|#
directive|define
name|OP_MASK_RT
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_RT
value|16
end_define

begin_define
define|#
directive|define
name|OP_MASK_FT
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_FT
value|16
end_define

begin_define
define|#
directive|define
name|OP_MASK_CACHE
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_CACHE
value|16
end_define

begin_define
define|#
directive|define
name|OP_MASK_RD
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_RD
value|11
end_define

begin_define
define|#
directive|define
name|OP_MASK_FS
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_FS
value|11
end_define

begin_define
define|#
directive|define
name|OP_MASK_PREFX
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_PREFX
value|11
end_define

begin_define
define|#
directive|define
name|OP_MASK_CCC
value|0x7
end_define

begin_define
define|#
directive|define
name|OP_SH_CCC
value|8
end_define

begin_define
define|#
directive|define
name|OP_MASK_CODE20
value|0xfffff
end_define

begin_comment
comment|/* 20 bit syscall/breakpoint code.  */
end_comment

begin_define
define|#
directive|define
name|OP_SH_CODE20
value|6
end_define

begin_define
define|#
directive|define
name|OP_MASK_SHAMT
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_SHAMT
value|6
end_define

begin_define
define|#
directive|define
name|OP_MASK_BITIND
value|OP_MASK_RT
end_define

begin_define
define|#
directive|define
name|OP_SH_BITIND
value|OP_SH_RT
end_define

begin_define
define|#
directive|define
name|OP_MASK_FD
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_FD
value|6
end_define

begin_define
define|#
directive|define
name|OP_MASK_TARGET
value|0x3ffffff
end_define

begin_define
define|#
directive|define
name|OP_SH_TARGET
value|0
end_define

begin_define
define|#
directive|define
name|OP_MASK_COPZ
value|0x1ffffff
end_define

begin_define
define|#
directive|define
name|OP_SH_COPZ
value|0
end_define

begin_define
define|#
directive|define
name|OP_MASK_IMMEDIATE
value|0xffff
end_define

begin_define
define|#
directive|define
name|OP_SH_IMMEDIATE
value|0
end_define

begin_define
define|#
directive|define
name|OP_MASK_DELTA
value|0xffff
end_define

begin_define
define|#
directive|define
name|OP_SH_DELTA
value|0
end_define

begin_define
define|#
directive|define
name|OP_MASK_FUNCT
value|0x3f
end_define

begin_define
define|#
directive|define
name|OP_SH_FUNCT
value|0
end_define

begin_define
define|#
directive|define
name|OP_MASK_SPEC
value|0x3f
end_define

begin_define
define|#
directive|define
name|OP_SH_SPEC
value|0
end_define

begin_define
define|#
directive|define
name|OP_SH_LOCC
value|8
end_define

begin_comment
comment|/* FP condition code.  */
end_comment

begin_define
define|#
directive|define
name|OP_SH_HICC
value|18
end_define

begin_comment
comment|/* FP condition code.  */
end_comment

begin_define
define|#
directive|define
name|OP_MASK_CC
value|0x7
end_define

begin_define
define|#
directive|define
name|OP_SH_COP1NORM
value|25
end_define

begin_comment
comment|/* Normal COP1 encoding.  */
end_comment

begin_define
define|#
directive|define
name|OP_MASK_COP1NORM
value|0x1
end_define

begin_comment
comment|/* a single bit.  */
end_comment

begin_define
define|#
directive|define
name|OP_SH_COP1SPEC
value|21
end_define

begin_comment
comment|/* COP1 encodings.  */
end_comment

begin_define
define|#
directive|define
name|OP_MASK_COP1SPEC
value|0xf
end_define

begin_define
define|#
directive|define
name|OP_MASK_COP1SCLR
value|0x4
end_define

begin_define
define|#
directive|define
name|OP_MASK_COP1CMP
value|0x3
end_define

begin_define
define|#
directive|define
name|OP_SH_COP1CMP
value|4
end_define

begin_define
define|#
directive|define
name|OP_SH_FORMAT
value|21
end_define

begin_comment
comment|/* FP short format field.  */
end_comment

begin_define
define|#
directive|define
name|OP_MASK_FORMAT
value|0x7
end_define

begin_define
define|#
directive|define
name|OP_SH_TRUE
value|16
end_define

begin_define
define|#
directive|define
name|OP_MASK_TRUE
value|0x1
end_define

begin_define
define|#
directive|define
name|OP_SH_GE
value|17
end_define

begin_define
define|#
directive|define
name|OP_MASK_GE
value|0x01
end_define

begin_define
define|#
directive|define
name|OP_SH_UNSIGNED
value|16
end_define

begin_define
define|#
directive|define
name|OP_MASK_UNSIGNED
value|0x1
end_define

begin_define
define|#
directive|define
name|OP_SH_HINT
value|16
end_define

begin_define
define|#
directive|define
name|OP_MASK_HINT
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_MMI
value|0
end_define

begin_comment
comment|/* Multimedia (parallel) op.  */
end_comment

begin_define
define|#
directive|define
name|OP_MASK_MMI
value|0x3f
end_define

begin_define
define|#
directive|define
name|OP_SH_MMISUB
value|6
end_define

begin_define
define|#
directive|define
name|OP_MASK_MMISUB
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_MASK_PERFREG
value|0x1f
end_define

begin_comment
comment|/* Performance monitoring.  */
end_comment

begin_define
define|#
directive|define
name|OP_SH_PERFREG
value|1
end_define

begin_define
define|#
directive|define
name|OP_SH_SEL
value|0
end_define

begin_comment
comment|/* Coprocessor select field.  */
end_comment

begin_define
define|#
directive|define
name|OP_MASK_SEL
value|0x7
end_define

begin_comment
comment|/* The sel field of mfcZ and mtcZ.  */
end_comment

begin_define
define|#
directive|define
name|OP_SH_CODE19
value|6
end_define

begin_comment
comment|/* 19 bit wait code.  */
end_comment

begin_define
define|#
directive|define
name|OP_MASK_CODE19
value|0x7ffff
end_define

begin_define
define|#
directive|define
name|OP_SH_ALN
value|21
end_define

begin_define
define|#
directive|define
name|OP_MASK_ALN
value|0x7
end_define

begin_define
define|#
directive|define
name|OP_SH_VSEL
value|21
end_define

begin_define
define|#
directive|define
name|OP_MASK_VSEL
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_MASK_VECBYTE
value|0x7
end_define

begin_comment
comment|/* Selector field is really 4 bits, 					   but 0x8-0xf don't select bytes.  */
end_comment

begin_define
define|#
directive|define
name|OP_SH_VECBYTE
value|22
end_define

begin_define
define|#
directive|define
name|OP_MASK_VECALIGN
value|0x7
end_define

begin_comment
comment|/* Vector byte-align (alni.ob) op.  */
end_comment

begin_define
define|#
directive|define
name|OP_SH_VECALIGN
value|21
end_define

begin_define
define|#
directive|define
name|OP_MASK_INSMSB
value|0x1f
end_define

begin_comment
comment|/* "ins" MSB.  */
end_comment

begin_define
define|#
directive|define
name|OP_SH_INSMSB
value|11
end_define

begin_define
define|#
directive|define
name|OP_MASK_EXTMSBD
value|0x1f
end_define

begin_comment
comment|/* "ext" MSBD.  */
end_comment

begin_define
define|#
directive|define
name|OP_SH_EXTMSBD
value|11
end_define

begin_comment
comment|/* MIPS DSP ASE */
end_comment

begin_define
define|#
directive|define
name|OP_SH_DSPACC
value|11
end_define

begin_define
define|#
directive|define
name|OP_MASK_DSPACC
value|0x3
end_define

begin_define
define|#
directive|define
name|OP_SH_DSPACC_S
value|21
end_define

begin_define
define|#
directive|define
name|OP_MASK_DSPACC_S
value|0x3
end_define

begin_define
define|#
directive|define
name|OP_SH_DSPSFT
value|20
end_define

begin_define
define|#
directive|define
name|OP_MASK_DSPSFT
value|0x3f
end_define

begin_define
define|#
directive|define
name|OP_SH_DSPSFT_7
value|19
end_define

begin_define
define|#
directive|define
name|OP_MASK_DSPSFT_7
value|0x7f
end_define

begin_define
define|#
directive|define
name|OP_SH_SA3
value|21
end_define

begin_define
define|#
directive|define
name|OP_MASK_SA3
value|0x7
end_define

begin_define
define|#
directive|define
name|OP_SH_SA4
value|21
end_define

begin_define
define|#
directive|define
name|OP_MASK_SA4
value|0xf
end_define

begin_define
define|#
directive|define
name|OP_SH_IMM8
value|16
end_define

begin_define
define|#
directive|define
name|OP_MASK_IMM8
value|0xff
end_define

begin_define
define|#
directive|define
name|OP_SH_IMM10
value|16
end_define

begin_define
define|#
directive|define
name|OP_MASK_IMM10
value|0x3ff
end_define

begin_define
define|#
directive|define
name|OP_SH_WRDSP
value|11
end_define

begin_define
define|#
directive|define
name|OP_MASK_WRDSP
value|0x3f
end_define

begin_define
define|#
directive|define
name|OP_SH_RDDSP
value|16
end_define

begin_define
define|#
directive|define
name|OP_MASK_RDDSP
value|0x3f
end_define

begin_define
define|#
directive|define
name|OP_SH_BP
value|11
end_define

begin_define
define|#
directive|define
name|OP_MASK_BP
value|0x3
end_define

begin_comment
comment|/* MIPS MT ASE */
end_comment

begin_define
define|#
directive|define
name|OP_SH_MT_U
value|5
end_define

begin_define
define|#
directive|define
name|OP_MASK_MT_U
value|0x1
end_define

begin_define
define|#
directive|define
name|OP_SH_MT_H
value|4
end_define

begin_define
define|#
directive|define
name|OP_MASK_MT_H
value|0x1
end_define

begin_define
define|#
directive|define
name|OP_SH_MTACC_T
value|18
end_define

begin_define
define|#
directive|define
name|OP_MASK_MTACC_T
value|0x3
end_define

begin_define
define|#
directive|define
name|OP_SH_MTACC_D
value|13
end_define

begin_define
define|#
directive|define
name|OP_MASK_MTACC_D
value|0x3
end_define

begin_define
define|#
directive|define
name|OP_OP_COP0
value|0x10
end_define

begin_define
define|#
directive|define
name|OP_OP_COP1
value|0x11
end_define

begin_define
define|#
directive|define
name|OP_OP_COP2
value|0x12
end_define

begin_define
define|#
directive|define
name|OP_OP_COP3
value|0x13
end_define

begin_define
define|#
directive|define
name|OP_OP_LWC1
value|0x31
end_define

begin_define
define|#
directive|define
name|OP_OP_LWC2
value|0x32
end_define

begin_define
define|#
directive|define
name|OP_OP_LWC3
value|0x33
end_define

begin_comment
comment|/* a.k.a. pref */
end_comment

begin_define
define|#
directive|define
name|OP_OP_LDC1
value|0x35
end_define

begin_define
define|#
directive|define
name|OP_OP_LDC2
value|0x36
end_define

begin_define
define|#
directive|define
name|OP_OP_LDC3
value|0x37
end_define

begin_comment
comment|/* a.k.a. ld */
end_comment

begin_define
define|#
directive|define
name|OP_OP_SWC1
value|0x39
end_define

begin_define
define|#
directive|define
name|OP_OP_SWC2
value|0x3a
end_define

begin_define
define|#
directive|define
name|OP_OP_SWC3
value|0x3b
end_define

begin_define
define|#
directive|define
name|OP_OP_SDC1
value|0x3d
end_define

begin_define
define|#
directive|define
name|OP_OP_SDC2
value|0x3e
end_define

begin_define
define|#
directive|define
name|OP_OP_SDC3
value|0x3f
end_define

begin_comment
comment|/* a.k.a. sd */
end_comment

begin_comment
comment|/* Values in the 'VSEL' field.  */
end_comment

begin_define
define|#
directive|define
name|MDMX_FMTSEL_IMM_QH
value|0x1d
end_define

begin_define
define|#
directive|define
name|MDMX_FMTSEL_IMM_OB
value|0x1e
end_define

begin_define
define|#
directive|define
name|MDMX_FMTSEL_VEC_QH
value|0x15
end_define

begin_define
define|#
directive|define
name|MDMX_FMTSEL_VEC_OB
value|0x16
end_define

begin_comment
comment|/* UDI */
end_comment

begin_define
define|#
directive|define
name|OP_SH_UDI1
value|6
end_define

begin_define
define|#
directive|define
name|OP_MASK_UDI1
value|0x1f
end_define

begin_define
define|#
directive|define
name|OP_SH_UDI2
value|6
end_define

begin_define
define|#
directive|define
name|OP_MASK_UDI2
value|0x3ff
end_define

begin_define
define|#
directive|define
name|OP_SH_UDI3
value|6
end_define

begin_define
define|#
directive|define
name|OP_MASK_UDI3
value|0x7fff
end_define

begin_define
define|#
directive|define
name|OP_SH_UDI4
value|6
end_define

begin_define
define|#
directive|define
name|OP_MASK_UDI4
value|0xfffff
end_define

begin_comment
comment|/* This structure holds information for a particular instruction.  */
end_comment

begin_struct
struct|struct
name|mips_opcode
block|{
comment|/* The name of the instruction.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* A string describing the arguments for this instruction.  */
specifier|const
name|char
modifier|*
name|args
decl_stmt|;
comment|/* The basic opcode for the instruction.  When assembling, this      opcode is modified by the arguments to produce the actual opcode      that is used.  If pinfo is INSN_MACRO, then this is 0.  */
name|unsigned
name|long
name|match
decl_stmt|;
comment|/* If pinfo is not INSN_MACRO, then this is a bit mask for the      relevant portions of the opcode when disassembling.  If the      actual opcode anded with the match field equals the opcode field,      then we have found the correct instruction.  If pinfo is      INSN_MACRO, then this field is the macro identifier.  */
name|unsigned
name|long
name|mask
decl_stmt|;
comment|/* For a macro, this is INSN_MACRO.  Otherwise, it is a collection      of bits describing the instruction, notably any relevant hazard      information.  */
name|unsigned
name|long
name|pinfo
decl_stmt|;
comment|/* A collection of additional bits describing the instruction. */
name|unsigned
name|long
name|pinfo2
decl_stmt|;
comment|/* A collection of bits describing the instruction sets of which this      instruction or macro is a member. */
name|unsigned
name|long
name|membership
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* These are the characters which may appear in the args field of an    instruction.  They appear in the order in which the fields appear    when the instruction is used.  Commas and parentheses in the args    string are ignored when assembling, and written into the output    when disassembling.     Each of these characters corresponds to a mask field defined above.     "<" 5 bit shift amount (OP_*_SHAMT)    ">" shift amount between 32 and 63, stored after subtracting 32 (OP_*_SHAMT)    "^" 5 bit bit index amount (OP_*_BITIND)    "~" bit index between 32 and 63, stored after subtracting 32 (OP_*_BITIND)    "a" 26 bit target address (OP_*_TARGET)    "b" 5 bit base register (OP_*_RS)    "c" 10 bit breakpoint code (OP_*_CODE)    "d" 5 bit destination register specifier (OP_*_RD)    "h" 5 bit prefx hint (OP_*_PREFX)    "i" 16 bit unsigned immediate (OP_*_IMMEDIATE)    "j" 16 bit signed immediate (OP_*_DELTA)    "k" 5 bit cache opcode in target register position (OP_*_CACHE)        Also used for immediate operands in vr5400 vector insns.    "o" 16 bit signed offset (OP_*_DELTA)    "p" 16 bit PC relative branch target address (OP_*_DELTA)    "q" 10 bit extra breakpoint code (OP_*_CODE2)    "r" 5 bit same register used as both source and target (OP_*_RS)    "s" 5 bit source register specifier (OP_*_RS)    "t" 5 bit target register (OP_*_RT)    "u" 16 bit upper 16 bits of address (OP_*_IMMEDIATE)    "v" 5 bit same register used as both source and destination (OP_*_RS)    "w" 5 bit same register used as both target and destination (OP_*_RT)    "U" 5 bit same destination register in both OP_*_RD and OP_*_RT        (used by clo and clz)    "C" 25 bit coprocessor function code (OP_*_COPZ)    "B" 20 bit syscall/breakpoint function code (OP_*_CODE20)    "J" 19 bit wait function code (OP_*_CODE19)    "x" accept and ignore register name    "y" 10 bit signed const (OP_*_CODE2)    "z" must be zero register    "K" 5 bit Hardware Register (rdhwr instruction) (OP_*_RD)    "+A" 5 bit ins/ext/dins/dext/dinsm/dextm position, which becomes         LSB (OP_*_SHAMT). 	Enforces: 0<= pos< 32.    "+B" 5 bit ins/dins size, which becomes MSB (OP_*_INSMSB). 	Requires that "+A" or "+E" occur first to set position. 	Enforces: 0< (pos+size)<= 32.    "+C" 5 bit ext/dext size, which becomes MSBD (OP_*_EXTMSBD). 	Requires that "+A" or "+E" occur first to set position. 	Enforces: 0< (pos+size)<= 32. 	(Also used by "dext" w/ different limits, but limits for 	that are checked by the M_DEXT macro.)    "+E" 5 bit dinsu/dextu position, which becomes LSB-32 (OP_*_SHAMT). 	Enforces: 32<= pos< 64.    "+F" 5 bit "dinsm/dinsu" size, which becomes MSB-32 (OP_*_INSMSB). 	Requires that "+A" or "+E" occur first to set position. 	Enforces: 32< (pos+size)<= 64.    "+G" 5 bit "dextm" size, which becomes MSBD-32 (OP_*_EXTMSBD). 	Requires that "+A" or "+E" occur first to set position. 	Enforces: 32< (pos+size)<= 64.    "+H" 5 bit "dextu" size, which becomes MSBD (OP_*_EXTMSBD). 	Requires that "+A" or "+E" occur first to set position. 	Enforces: 32< (pos+size)<= 64.     Floating point instructions:    "D" 5 bit destination register (OP_*_FD)    "M" 3 bit compare condition code (OP_*_CCC) (only used for mips4 and up)    "N" 3 bit branch condition code (OP_*_BCC) (only used for mips4 and up)    "S" 5 bit fs source 1 register (OP_*_FS)    "T" 5 bit ft source 2 register (OP_*_FT)    "R" 5 bit fr source 3 register (OP_*_FR)    "V" 5 bit same register used as floating source and destination (OP_*_FS)    "W" 5 bit same register used as floating target and destination (OP_*_FT)     Coprocessor instructions:    "E" 5 bit target register (OP_*_RT)    "G" 5 bit destination register (OP_*_RD)    "H" 3 bit sel field for (d)mtc* and (d)mfc* (OP_*_SEL)    "P" 5 bit performance-monitor register (OP_*_PERFREG)    "e" 5 bit vector register byte specifier (OP_*_VECBYTE)    "%" 3 bit immediate vr5400 vector alignment operand (OP_*_VECALIGN)    see also "k" above    "+D" Combined destination register ("G") and sel ("H") for CP0 ops, 	for pretty-printing in disassembly only.     Macro instructions:    "A" General 32 bit expression    "I" 32 bit immediate (value placed in imm_expr).    "+I" 32 bit immediate (value placed in imm2_expr).    "F" 64 bit floating point constant in .rdata    "L" 64 bit floating point constant in .lit8    "f" 32 bit floating point constant    "l" 32 bit floating point constant in .lit4     MDMX instruction operands (note that while these use the FP register    fields, they accept both $fN and $vN names for the registers):      "O"	MDMX alignment offset (OP_*_ALN)    "Q"	MDMX vector/scalar/immediate source (OP_*_VSEL and OP_*_FT)    "X"	MDMX destination register (OP_*_FD)     "Y"	MDMX source register (OP_*_FS)    "Z"	MDMX source register (OP_*_FT)     DSP ASE usage:    "2" 2 bit unsigned immediate for byte align (OP_*_BP)    "3" 3 bit unsigned immediate (OP_*_SA3)    "4" 4 bit unsigned immediate (OP_*_SA4)    "5" 8 bit unsigned immediate (OP_*_IMM8)    "6" 5 bit unsigned immediate (OP_*_RS)    "7" 2 bit dsp accumulator register (OP_*_DSPACC)    "8" 6 bit unsigned immediate (OP_*_WRDSP)    "9" 2 bit dsp accumulator register (OP_*_DSPACC_S)    "0" 6 bit signed immediate (OP_*_DSPSFT)    ":" 7 bit signed immediate (OP_*_DSPSFT_7)    "'" 6 bit unsigned immediate (OP_*_RDDSP)    "@" 10 bit signed immediate (OP_*_IMM10)     MT ASE usage:    "!" 1 bit usermode flag (OP_*_MT_U)    "$" 1 bit load high flag (OP_*_MT_H)    "*" 2 bit dsp/smartmips accumulator register (OP_*_MTACC_T)    "&" 2 bit dsp/smartmips accumulator register (OP_*_MTACC_D)    "g" 5 bit coprocessor 1 and 2 destination register (OP_*_RD)    "+t" 5 bit coprocessor 0 destination register (OP_*_RT)    "+T" 5 bit coprocessor 0 destination register (OP_*_RT) - disassembly only     UDI immediates:    "+1" UDI immediate bits 6-10    "+2" UDI immediate bits 6-15    "+3" UDI immediate bits 6-20    "+4" UDI immediate bits 6-25     Other:    "()" parens surrounding optional value    ","  separates operands    "[]" brackets around index for vector-op scalar operand specifier (vr5400)    "+"  Start of extension sequence.     Characters used so far, for quick reference when adding more:    "234567890"    "%[]<>(),+:'@!$*&^~"    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"    "abcdefghijklopqrstuvwxyz"     Extension character sequences used so far ("+" followed by the    following), for quick reference when adding more:    "1234"    "ABCDEFGHIT"    "t" */
end_comment

begin_comment
comment|/* These are the bits which may be set in the pinfo field of an    instructions, if it is not equal to INSN_MACRO.  */
end_comment

begin_comment
comment|/* Modifies the general purpose register in OP_*_RD.  */
end_comment

begin_define
define|#
directive|define
name|INSN_WRITE_GPR_D
value|0x00000001
end_define

begin_comment
comment|/* Modifies the general purpose register in OP_*_RT.  */
end_comment

begin_define
define|#
directive|define
name|INSN_WRITE_GPR_T
value|0x00000002
end_define

begin_comment
comment|/* Modifies general purpose register 31.  */
end_comment

begin_define
define|#
directive|define
name|INSN_WRITE_GPR_31
value|0x00000004
end_define

begin_comment
comment|/* Modifies the floating point register in OP_*_FD.  */
end_comment

begin_define
define|#
directive|define
name|INSN_WRITE_FPR_D
value|0x00000008
end_define

begin_comment
comment|/* Modifies the floating point register in OP_*_FS.  */
end_comment

begin_define
define|#
directive|define
name|INSN_WRITE_FPR_S
value|0x00000010
end_define

begin_comment
comment|/* Modifies the floating point register in OP_*_FT.  */
end_comment

begin_define
define|#
directive|define
name|INSN_WRITE_FPR_T
value|0x00000020
end_define

begin_comment
comment|/* Reads the general purpose register in OP_*_RS.  */
end_comment

begin_define
define|#
directive|define
name|INSN_READ_GPR_S
value|0x00000040
end_define

begin_comment
comment|/* Reads the general purpose register in OP_*_RT.  */
end_comment

begin_define
define|#
directive|define
name|INSN_READ_GPR_T
value|0x00000080
end_define

begin_comment
comment|/* Reads the floating point register in OP_*_FS.  */
end_comment

begin_define
define|#
directive|define
name|INSN_READ_FPR_S
value|0x00000100
end_define

begin_comment
comment|/* Reads the floating point register in OP_*_FT.  */
end_comment

begin_define
define|#
directive|define
name|INSN_READ_FPR_T
value|0x00000200
end_define

begin_comment
comment|/* Reads the floating point register in OP_*_FR.  */
end_comment

begin_define
define|#
directive|define
name|INSN_READ_FPR_R
value|0x00000400
end_define

begin_comment
comment|/* Modifies coprocessor condition code.  */
end_comment

begin_define
define|#
directive|define
name|INSN_WRITE_COND_CODE
value|0x00000800
end_define

begin_comment
comment|/* Reads coprocessor condition code.  */
end_comment

begin_define
define|#
directive|define
name|INSN_READ_COND_CODE
value|0x00001000
end_define

begin_comment
comment|/* TLB operation.  */
end_comment

begin_define
define|#
directive|define
name|INSN_TLB
value|0x00002000
end_define

begin_comment
comment|/* Reads coprocessor register other than floating point register.  */
end_comment

begin_define
define|#
directive|define
name|INSN_COP
value|0x00004000
end_define

begin_comment
comment|/* Instruction loads value from memory, requiring delay.  */
end_comment

begin_define
define|#
directive|define
name|INSN_LOAD_MEMORY_DELAY
value|0x00008000
end_define

begin_comment
comment|/* Instruction loads value from coprocessor, requiring delay.  */
end_comment

begin_define
define|#
directive|define
name|INSN_LOAD_COPROC_DELAY
value|0x00010000
end_define

begin_comment
comment|/* Instruction has unconditional branch delay slot.  */
end_comment

begin_define
define|#
directive|define
name|INSN_UNCOND_BRANCH_DELAY
value|0x00020000
end_define

begin_comment
comment|/* Instruction has conditional branch delay slot.  */
end_comment

begin_define
define|#
directive|define
name|INSN_COND_BRANCH_DELAY
value|0x00040000
end_define

begin_comment
comment|/* Conditional branch likely: if branch not taken, insn nullified.  */
end_comment

begin_define
define|#
directive|define
name|INSN_COND_BRANCH_LIKELY
value|0x00080000
end_define

begin_comment
comment|/* Moves to coprocessor register, requiring delay.  */
end_comment

begin_define
define|#
directive|define
name|INSN_COPROC_MOVE_DELAY
value|0x00100000
end_define

begin_comment
comment|/* Loads coprocessor register from memory, requiring delay.  */
end_comment

begin_define
define|#
directive|define
name|INSN_COPROC_MEMORY_DELAY
value|0x00200000
end_define

begin_comment
comment|/* Reads the HI register.  */
end_comment

begin_define
define|#
directive|define
name|INSN_READ_HI
value|0x00400000
end_define

begin_comment
comment|/* Reads the LO register.  */
end_comment

begin_define
define|#
directive|define
name|INSN_READ_LO
value|0x00800000
end_define

begin_comment
comment|/* Modifies the HI register.  */
end_comment

begin_define
define|#
directive|define
name|INSN_WRITE_HI
value|0x01000000
end_define

begin_comment
comment|/* Modifies the LO register.  */
end_comment

begin_define
define|#
directive|define
name|INSN_WRITE_LO
value|0x02000000
end_define

begin_comment
comment|/* Takes a trap (easier to keep out of delay slot).  */
end_comment

begin_define
define|#
directive|define
name|INSN_TRAP
value|0x04000000
end_define

begin_comment
comment|/* Instruction stores value into memory.  */
end_comment

begin_define
define|#
directive|define
name|INSN_STORE_MEMORY
value|0x08000000
end_define

begin_comment
comment|/* Instruction uses single precision floating point.  */
end_comment

begin_define
define|#
directive|define
name|FP_S
value|0x10000000
end_define

begin_comment
comment|/* Instruction uses double precision floating point.  */
end_comment

begin_define
define|#
directive|define
name|FP_D
value|0x20000000
end_define

begin_comment
comment|/* Instruction is part of the tx39's integer multiply family.    */
end_comment

begin_define
define|#
directive|define
name|INSN_MULT
value|0x40000000
end_define

begin_comment
comment|/* Instruction synchronize shared memory.  */
end_comment

begin_define
define|#
directive|define
name|INSN_SYNC
value|0x80000000
end_define

begin_comment
comment|/* These are the bits which may be set in the pinfo2 field of an    instruction. */
end_comment

begin_comment
comment|/* Instruction is a simple alias (I.E. "move" for daddu/addu/or) */
end_comment

begin_define
define|#
directive|define
name|INSN2_ALIAS
value|0x00000001
end_define

begin_comment
comment|/* Instruction reads MDMX accumulator. */
end_comment

begin_define
define|#
directive|define
name|INSN2_READ_MDMX_ACC
value|0x00000002
end_define

begin_comment
comment|/* Instruction writes MDMX accumulator. */
end_comment

begin_define
define|#
directive|define
name|INSN2_WRITE_MDMX_ACC
value|0x00000004
end_define

begin_comment
comment|/* Instruction is actually a macro.  It should be ignored by the    disassembler, and requires special treatment by the assembler.  */
end_comment

begin_define
define|#
directive|define
name|INSN_MACRO
value|0xffffffff
end_define

begin_comment
comment|/* Masks used to mark instructions to indicate which MIPS ISA level    they were introduced in.  ISAs, as defined below, are logical    ORs of these bits, indicating that they support the instructions    defined at the given level.  */
end_comment

begin_define
define|#
directive|define
name|INSN_ISA_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|INSN_ISA1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|INSN_ISA2
value|0x00000002
end_define

begin_define
define|#
directive|define
name|INSN_ISA3
value|0x00000004
end_define

begin_define
define|#
directive|define
name|INSN_ISA4
value|0x00000008
end_define

begin_define
define|#
directive|define
name|INSN_ISA5
value|0x00000010
end_define

begin_define
define|#
directive|define
name|INSN_ISA32
value|0x00000020
end_define

begin_define
define|#
directive|define
name|INSN_ISA64
value|0x00000040
end_define

begin_define
define|#
directive|define
name|INSN_ISA32R2
value|0x00000080
end_define

begin_define
define|#
directive|define
name|INSN_ISA64R2
value|0x00000100
end_define

begin_comment
comment|/* Masks used for MIPS-defined ASEs.  */
end_comment

begin_define
define|#
directive|define
name|INSN_ASE_MASK
value|0x3c00f000
end_define

begin_comment
comment|/* DSP ASE */
end_comment

begin_define
define|#
directive|define
name|INSN_DSP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|INSN_DSP64
value|0x00002000
end_define

begin_comment
comment|/* MIPS 16 ASE */
end_comment

begin_define
define|#
directive|define
name|INSN_MIPS16
value|0x00004000
end_define

begin_comment
comment|/* MIPS-3D ASE */
end_comment

begin_define
define|#
directive|define
name|INSN_MIPS3D
value|0x00008000
end_define

begin_comment
comment|/* Chip specific instructions.  These are bitmasks.  */
end_comment

begin_comment
comment|/* MIPS R4650 instruction.  */
end_comment

begin_define
define|#
directive|define
name|INSN_4650
value|0x00010000
end_define

begin_comment
comment|/* LSI R4010 instruction.  */
end_comment

begin_define
define|#
directive|define
name|INSN_4010
value|0x00020000
end_define

begin_comment
comment|/* NEC VR4100 instruction.  */
end_comment

begin_define
define|#
directive|define
name|INSN_4100
value|0x00040000
end_define

begin_comment
comment|/* Toshiba R3900 instruction.  */
end_comment

begin_define
define|#
directive|define
name|INSN_3900
value|0x00080000
end_define

begin_comment
comment|/* MIPS R10000 instruction.  */
end_comment

begin_define
define|#
directive|define
name|INSN_10000
value|0x00100000
end_define

begin_comment
comment|/* Broadcom SB-1 instruction.  */
end_comment

begin_define
define|#
directive|define
name|INSN_SB1
value|0x00200000
end_define

begin_comment
comment|/* NEC VR4111/VR4181 instruction.  */
end_comment

begin_define
define|#
directive|define
name|INSN_4111
value|0x00400000
end_define

begin_comment
comment|/* NEC VR4120 instruction.  */
end_comment

begin_define
define|#
directive|define
name|INSN_4120
value|0x00800000
end_define

begin_comment
comment|/* NEC VR5400 instruction.  */
end_comment

begin_define
define|#
directive|define
name|INSN_5400
value|0x01000000
end_define

begin_comment
comment|/* NEC VR5500 instruction.  */
end_comment

begin_define
define|#
directive|define
name|INSN_5500
value|0x02000000
end_define

begin_comment
comment|/* MDMX ASE */
end_comment

begin_define
define|#
directive|define
name|INSN_MDMX
value|0x04000000
end_define

begin_comment
comment|/* MT ASE */
end_comment

begin_define
define|#
directive|define
name|INSN_MT
value|0x08000000
end_define

begin_comment
comment|/* SmartMIPS ASE  */
end_comment

begin_define
define|#
directive|define
name|INSN_SMARTMIPS
value|0x10000000
end_define

begin_comment
comment|/* DSP R2 ASE  */
end_comment

begin_define
define|#
directive|define
name|INSN_DSPR2
value|0x20000000
end_define

begin_comment
comment|/* Cavium Networks Octeon instruction. */
end_comment

begin_define
define|#
directive|define
name|INSN_OCTEON
value|0x08000000
end_define

begin_comment
comment|/* MIPS ISA defines, use instead of hardcoding ISA level.  */
end_comment

begin_define
define|#
directive|define
name|ISA_UNKNOWN
value|0
end_define

begin_comment
comment|/* Gas internal use.  */
end_comment

begin_define
define|#
directive|define
name|ISA_MIPS1
value|(INSN_ISA1)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS2
value|(ISA_MIPS1 | INSN_ISA2)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS3
value|(ISA_MIPS2 | INSN_ISA3)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS4
value|(ISA_MIPS3 | INSN_ISA4)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS5
value|(ISA_MIPS4 | INSN_ISA5)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS32
value|(ISA_MIPS2 | INSN_ISA32)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS64
value|(ISA_MIPS5 | INSN_ISA32 | INSN_ISA64)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS32R2
value|(ISA_MIPS32 | INSN_ISA32R2)
end_define

begin_define
define|#
directive|define
name|ISA_MIPS64R2
value|(ISA_MIPS64 | INSN_ISA32R2 | INSN_ISA64R2)
end_define

begin_comment
comment|/* CPU defines, use instead of hardcoding processor number. Keep this    in sync with bfd/archures.c in order for machine selection to work.  */
end_comment

begin_define
define|#
directive|define
name|CPU_UNKNOWN
value|0
end_define

begin_comment
comment|/* Gas internal use.  */
end_comment

begin_define
define|#
directive|define
name|CPU_R3000
value|3000
end_define

begin_define
define|#
directive|define
name|CPU_R3900
value|3900
end_define

begin_define
define|#
directive|define
name|CPU_R4000
value|4000
end_define

begin_define
define|#
directive|define
name|CPU_R4010
value|4010
end_define

begin_define
define|#
directive|define
name|CPU_VR4100
value|4100
end_define

begin_define
define|#
directive|define
name|CPU_R4111
value|4111
end_define

begin_define
define|#
directive|define
name|CPU_VR4120
value|4120
end_define

begin_define
define|#
directive|define
name|CPU_R4300
value|4300
end_define

begin_define
define|#
directive|define
name|CPU_R4400
value|4400
end_define

begin_define
define|#
directive|define
name|CPU_R4600
value|4600
end_define

begin_define
define|#
directive|define
name|CPU_R4650
value|4650
end_define

begin_define
define|#
directive|define
name|CPU_R5000
value|5000
end_define

begin_define
define|#
directive|define
name|CPU_VR5400
value|5400
end_define

begin_define
define|#
directive|define
name|CPU_VR5500
value|5500
end_define

begin_define
define|#
directive|define
name|CPU_R6000
value|6000
end_define

begin_define
define|#
directive|define
name|CPU_RM7000
value|7000
end_define

begin_define
define|#
directive|define
name|CPU_R8000
value|8000
end_define

begin_define
define|#
directive|define
name|CPU_RM9000
value|9000
end_define

begin_define
define|#
directive|define
name|CPU_R10000
value|10000
end_define

begin_define
define|#
directive|define
name|CPU_R12000
value|12000
end_define

begin_define
define|#
directive|define
name|CPU_MIPS16
value|16
end_define

begin_define
define|#
directive|define
name|CPU_MIPS32
value|32
end_define

begin_define
define|#
directive|define
name|CPU_MIPS32R2
value|33
end_define

begin_define
define|#
directive|define
name|CPU_MIPS5
value|5
end_define

begin_define
define|#
directive|define
name|CPU_MIPS64
value|64
end_define

begin_define
define|#
directive|define
name|CPU_MIPS64R2
value|65
end_define

begin_define
define|#
directive|define
name|CPU_SB1
value|12310201
end_define

begin_comment
comment|/* octal 'SB', 01.  */
end_comment

begin_define
define|#
directive|define
name|CPU_OCTEON
value|6502
end_define

begin_comment
comment|/* Test for membership in an ISA including chip specific ISAs.  INSN    is pointer to an element of the opcode table; ISA is the specified    ISA/ASE bitmask to test against; and CPU is the CPU specific ISA to    test, or zero if no CPU specific ISA test is desired.  */
end_comment

begin_define
define|#
directive|define
name|OPCODE_IS_MEMBER
parameter_list|(
name|insn
parameter_list|,
name|isa
parameter_list|,
name|cpu
parameter_list|)
define|\
value|(((insn)->membership& isa) != 0					\      || (cpu == CPU_R4650&& ((insn)->membership& INSN_4650) != 0)	\      || (cpu == CPU_RM7000&& ((insn)->membership& INSN_4650) != 0)	\      || (cpu == CPU_RM9000&& ((insn)->membership& INSN_4650) != 0)	\      || (cpu == CPU_R4010&& ((insn)->membership& INSN_4010) != 0)	\      || (cpu == CPU_VR4100&& ((insn)->membership& INSN_4100) != 0)	\      || (cpu == CPU_R3900&& ((insn)->membership& INSN_3900) != 0)	\      || ((cpu == CPU_R10000 || cpu == CPU_R12000)			\&& ((insn)->membership& INSN_10000) != 0)			\      || (cpu == CPU_SB1&& ((insn)->membership& INSN_SB1) != 0)	\      || (cpu == CPU_OCTEON&& ((insn)->membership& INSN_OCTEON) != 0)  \      || (cpu == CPU_R4111&& ((insn)->membership& INSN_4111) != 0)	\      || (cpu == CPU_VR4120&& ((insn)->membership& INSN_4120) != 0)	\      || (cpu == CPU_VR5400&& ((insn)->membership& INSN_5400) != 0)	\      || (cpu == CPU_VR5500&& ((insn)->membership& INSN_5500) != 0)	\      || 0)
end_define

begin_comment
comment|/* Please keep this term for easier source merging.  */
end_comment

begin_comment
comment|/* This is a list of macro expanded instructions.     _I appended means immediate    _A appended means address    _AB appended means address with base register    _D appended means 64 bit floating point constant    _S appended means 32 bit floating point constant.  */
end_comment

begin_enum
enum|enum
block|{
name|M_ABS
block|,
name|M_ADD_I
block|,
name|M_ADDU_I
block|,
name|M_AND_I
block|,
name|M_BALIGN
block|,
name|M_BEQ
block|,
name|M_BEQ_I
block|,
name|M_BEQL_I
block|,
name|M_BGE
block|,
name|M_BGEL
block|,
name|M_BGE_I
block|,
name|M_BGEL_I
block|,
name|M_BGEU
block|,
name|M_BGEUL
block|,
name|M_BGEU_I
block|,
name|M_BGEUL_I
block|,
name|M_BGT
block|,
name|M_BGTL
block|,
name|M_BGT_I
block|,
name|M_BGTL_I
block|,
name|M_BGTU
block|,
name|M_BGTUL
block|,
name|M_BGTU_I
block|,
name|M_BGTUL_I
block|,
name|M_BLE
block|,
name|M_BLEL
block|,
name|M_BLE_I
block|,
name|M_BLEL_I
block|,
name|M_BLEU
block|,
name|M_BLEUL
block|,
name|M_BLEU_I
block|,
name|M_BLEUL_I
block|,
name|M_BLT
block|,
name|M_BLTL
block|,
name|M_BLT_I
block|,
name|M_BLTL_I
block|,
name|M_BLTU
block|,
name|M_BLTUL
block|,
name|M_BLTU_I
block|,
name|M_BLTUL_I
block|,
name|M_BNE
block|,
name|M_BNE_I
block|,
name|M_BNEL_I
block|,
name|M_CACHE_AB
block|,
name|M_DABS
block|,
name|M_DADD_I
block|,
name|M_DADDU_I
block|,
name|M_DDIV_3
block|,
name|M_DDIV_3I
block|,
name|M_DDIVU_3
block|,
name|M_DDIVU_3I
block|,
name|M_DEXT
block|,
name|M_DINS
block|,
name|M_DIV_3
block|,
name|M_DIV_3I
block|,
name|M_DIVU_3
block|,
name|M_DIVU_3I
block|,
name|M_DLA_AB
block|,
name|M_DLCA_AB
block|,
name|M_DLI
block|,
name|M_DMUL
block|,
name|M_DMUL_I
block|,
name|M_DMULO
block|,
name|M_DMULO_I
block|,
name|M_DMULOU
block|,
name|M_DMULOU_I
block|,
name|M_DREM_3
block|,
name|M_DREM_3I
block|,
name|M_DREMU_3
block|,
name|M_DREMU_3I
block|,
name|M_DSUB_I
block|,
name|M_DSUBU_I
block|,
name|M_DSUBU_I_2
block|,
name|M_J_A
block|,
name|M_JAL_1
block|,
name|M_JAL_2
block|,
name|M_JAL_A
block|,
name|M_L_DOB
block|,
name|M_L_DAB
block|,
name|M_LA_AB
block|,
name|M_LB_A
block|,
name|M_LB_AB
block|,
name|M_LBU_A
block|,
name|M_LBU_AB
block|,
name|M_LCA_AB
block|,
name|M_LD_A
block|,
name|M_LD_OB
block|,
name|M_LD_AB
block|,
name|M_LDC1_AB
block|,
name|M_LDC2_AB
block|,
name|M_LDC3_AB
block|,
name|M_LDL_AB
block|,
name|M_LDR_AB
block|,
name|M_LH_A
block|,
name|M_LH_AB
block|,
name|M_LHU_A
block|,
name|M_LHU_AB
block|,
name|M_LI
block|,
name|M_LI_D
block|,
name|M_LI_DD
block|,
name|M_LI_S
block|,
name|M_LI_SS
block|,
name|M_LL_AB
block|,
name|M_LLD_AB
block|,
name|M_LS_A
block|,
name|M_LW_A
block|,
name|M_LW_AB
block|,
name|M_LWC0_A
block|,
name|M_LWC0_AB
block|,
name|M_LWC1_A
block|,
name|M_LWC1_AB
block|,
name|M_LWC2_A
block|,
name|M_LWC2_AB
block|,
name|M_LWC3_A
block|,
name|M_LWC3_AB
block|,
name|M_LWL_A
block|,
name|M_LWL_AB
block|,
name|M_LWR_A
block|,
name|M_LWR_AB
block|,
name|M_LWU_AB
block|,
name|M_MOVE
block|,
name|M_MUL
block|,
name|M_MUL_I
block|,
name|M_MULO
block|,
name|M_MULO_I
block|,
name|M_MULOU
block|,
name|M_MULOU_I
block|,
name|M_NOR_I
block|,
name|M_OR_I
block|,
name|M_REM_3
block|,
name|M_REM_3I
block|,
name|M_REMU_3
block|,
name|M_REMU_3I
block|,
name|M_DROL
block|,
name|M_ROL
block|,
name|M_DROL_I
block|,
name|M_ROL_I
block|,
name|M_DROR
block|,
name|M_ROR
block|,
name|M_DROR_I
block|,
name|M_ROR_I
block|,
name|M_S_DA
block|,
name|M_S_DOB
block|,
name|M_S_DAB
block|,
name|M_S_S
block|,
name|M_SAA_AB
block|,
name|M_SAAD_AB
block|,
name|M_SC_AB
block|,
name|M_SCD_AB
block|,
name|M_SD_A
block|,
name|M_SD_OB
block|,
name|M_SD_AB
block|,
name|M_SDC1_AB
block|,
name|M_SDC2_AB
block|,
name|M_SDC3_AB
block|,
name|M_SDL_AB
block|,
name|M_SDR_AB
block|,
name|M_SEQ
block|,
name|M_SEQ_I
block|,
name|M_SGE
block|,
name|M_SGE_I
block|,
name|M_SGEU
block|,
name|M_SGEU_I
block|,
name|M_SGT
block|,
name|M_SGT_I
block|,
name|M_SGTU
block|,
name|M_SGTU_I
block|,
name|M_SLE
block|,
name|M_SLE_I
block|,
name|M_SLEU
block|,
name|M_SLEU_I
block|,
name|M_SLT_I
block|,
name|M_SLTU_I
block|,
name|M_SNE
block|,
name|M_SNE_I
block|,
name|M_SB_A
block|,
name|M_SB_AB
block|,
name|M_SH_A
block|,
name|M_SH_AB
block|,
name|M_SW_A
block|,
name|M_SW_AB
block|,
name|M_SWC0_A
block|,
name|M_SWC0_AB
block|,
name|M_SWC1_A
block|,
name|M_SWC1_AB
block|,
name|M_SWC2_A
block|,
name|M_SWC2_AB
block|,
name|M_SWC3_A
block|,
name|M_SWC3_AB
block|,
name|M_SWL_A
block|,
name|M_SWL_AB
block|,
name|M_SWR_A
block|,
name|M_SWR_AB
block|,
name|M_SUB_I
block|,
name|M_SUBU_I
block|,
name|M_SUBU_I_2
block|,
name|M_TEQ_I
block|,
name|M_TGE_I
block|,
name|M_TGEU_I
block|,
name|M_TLT_I
block|,
name|M_TLTU_I
block|,
name|M_TNE_I
block|,
name|M_TRUNCWD
block|,
name|M_TRUNCWS
block|,
name|M_ULD
block|,
name|M_ULD_A
block|,
name|M_ULH
block|,
name|M_ULH_A
block|,
name|M_ULHU
block|,
name|M_ULHU_A
block|,
name|M_ULW
block|,
name|M_ULW_A
block|,
name|M_USH
block|,
name|M_USH_A
block|,
name|M_USW
block|,
name|M_USW_A
block|,
name|M_USD
block|,
name|M_USD_A
block|,
name|M_XOR_I
block|,
name|M_COP0
block|,
name|M_COP1
block|,
name|M_COP2
block|,
name|M_COP3
block|,
name|M_NUM_MACROS
block|}
enum|;
end_enum

begin_comment
comment|/* The order of overloaded instructions matters.  Label arguments and    register arguments look the same. Instructions that can have either    for arguments must apear in the correct order in this table for the    assembler to pick the right one. In other words, entries with    immediate operands must apear after the same instruction with    registers.     Many instructions are short hand for other instructions (i.e., The    jal<register> instruction is short for jalr<register>).  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mips_opcode
name|mips_builtin_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|bfd_mips_num_builtin_opcodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mips_opcode
modifier|*
name|mips_opcodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bfd_mips_num_opcodes
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMOPCODES
value|bfd_mips_num_opcodes
end_define

begin_escape
end_escape

begin_comment
comment|/* The rest of this file adds definitions for the mips16 TinyRISC    processor.  */
end_comment

begin_comment
comment|/* These are the bitmasks and shift counts used for the different    fields in the instruction formats.  Other than OP, no masks are    provided for the fixed portions of an instruction, since they are    not needed.     The I format uses IMM11.     The RI format uses RX and IMM8.     The RR format uses RX, and RY.     The RRI format uses RX, RY, and IMM5.     The RRR format uses RX, RY, and RZ.     The RRI_A format uses RX, RY, and IMM4.     The SHIFT format uses RX, RY, and SHAMT.     The I8 format uses IMM8.     The I8_MOVR32 format uses RY and REGR32.     The IR_MOV32R format uses REG32R and MOV32Z.     The I64 format uses IMM8.     The RI64 format uses RY and IMM5.    */
end_comment

begin_define
define|#
directive|define
name|MIPS16OP_MASK_OP
value|0x1f
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_OP
value|11
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_IMM11
value|0x7ff
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_IMM11
value|0
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_RX
value|0x7
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_RX
value|8
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_IMM8
value|0xff
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_IMM8
value|0
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_RY
value|0x7
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_RY
value|5
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_IMM5
value|0x1f
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_IMM5
value|0
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_RZ
value|0x7
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_RZ
value|2
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_IMM4
value|0xf
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_IMM4
value|0
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_REGR32
value|0x1f
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_REGR32
value|0
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_REG32R
value|0x1f
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_REG32R
value|3
end_define

begin_define
define|#
directive|define
name|MIPS16OP_EXTRACT_REG32R
parameter_list|(
name|i
parameter_list|)
value|((((i)>> 5)& 7) | ((i)& 0x18))
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_MOVE32Z
value|0x7
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_MOVE32Z
value|0
end_define

begin_define
define|#
directive|define
name|MIPS16OP_MASK_IMM6
value|0x3f
end_define

begin_define
define|#
directive|define
name|MIPS16OP_SH_IMM6
value|5
end_define

begin_comment
comment|/* These are the characters which may appears in the args field of an    instruction.  They appear in the order in which the fields appear    when the instruction is used.  Commas and parentheses in the args    string are ignored when assembling, and written into the output    when disassembling.     "y" 3 bit register (MIPS16OP_*_RY)    "x" 3 bit register (MIPS16OP_*_RX)    "z" 3 bit register (MIPS16OP_*_RZ)    "Z" 3 bit register (MIPS16OP_*_MOVE32Z)    "v" 3 bit same register as source and destination (MIPS16OP_*_RX)    "w" 3 bit same register as source and destination (MIPS16OP_*_RY)    "0" zero register ($0)    "S" stack pointer ($sp or $29)    "P" program counter    "R" return address register ($ra or $31)    "X" 5 bit MIPS register (MIPS16OP_*_REGR32)    "Y" 5 bit MIPS register (MIPS16OP_*_REG32R)    "6" 6 bit unsigned break code (MIPS16OP_*_IMM6)    "a" 26 bit jump address    "e" 11 bit extension value    "l" register list for entry instruction    "L" register list for exit instruction     The remaining codes may be extended.  Except as otherwise noted,    the full extended operand is a 16 bit signed value.    "<" 3 bit unsigned shift count * 0 (MIPS16OP_*_RZ) (full 5 bit unsigned)    ">" 3 bit unsigned shift count * 0 (MIPS16OP_*_RX) (full 5 bit unsigned)    "[" 3 bit unsigned shift count * 0 (MIPS16OP_*_RZ) (full 6 bit unsigned)    "]" 3 bit unsigned shift count * 0 (MIPS16OP_*_RX) (full 6 bit unsigned)    "4" 4 bit signed immediate * 0 (MIPS16OP_*_IMM4) (full 15 bit signed)    "5" 5 bit unsigned immediate * 0 (MIPS16OP_*_IMM5)    "H" 5 bit unsigned immediate * 2 (MIPS16OP_*_IMM5)    "W" 5 bit unsigned immediate * 4 (MIPS16OP_*_IMM5)    "D" 5 bit unsigned immediate * 8 (MIPS16OP_*_IMM5)    "j" 5 bit signed immediate * 0 (MIPS16OP_*_IMM5)    "8" 8 bit unsigned immediate * 0 (MIPS16OP_*_IMM8)    "V" 8 bit unsigned immediate * 4 (MIPS16OP_*_IMM8)    "C" 8 bit unsigned immediate * 8 (MIPS16OP_*_IMM8)    "U" 8 bit unsigned immediate * 0 (MIPS16OP_*_IMM8) (full 16 bit unsigned)    "k" 8 bit signed immediate * 0 (MIPS16OP_*_IMM8)    "K" 8 bit signed immediate * 8 (MIPS16OP_*_IMM8)    "p" 8 bit conditional branch address (MIPS16OP_*_IMM8)    "q" 11 bit branch address (MIPS16OP_*_IMM11)    "A" 8 bit PC relative address * 4 (MIPS16OP_*_IMM8)    "B" 5 bit PC relative address * 8 (MIPS16OP_*_IMM5)    "E" 5 bit PC relative address * 4 (MIPS16OP_*_IMM5)    "m" 7 bit register list for save instruction (18 bit extended)    "M" 7 bit register list for restore instruction (18 bit extended)   */
end_comment

begin_comment
comment|/* Save/restore encoding for the args field when all 4 registers are    either saved as arguments or saved/restored as statics.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_ALL_ARGS
value|0xe
end_define

begin_define
define|#
directive|define
name|MIPS16_ALL_STATICS
value|0xb
end_define

begin_comment
comment|/* For the mips16, we use the same opcode table format and a few of    the same flags.  However, most of the flags are different.  */
end_comment

begin_comment
comment|/* Modifies the register in MIPS16OP_*_RX.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_WRITE_X
value|0x00000001
end_define

begin_comment
comment|/* Modifies the register in MIPS16OP_*_RY.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_WRITE_Y
value|0x00000002
end_define

begin_comment
comment|/* Modifies the register in MIPS16OP_*_RZ.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_WRITE_Z
value|0x00000004
end_define

begin_comment
comment|/* Modifies the T ($24) register.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_WRITE_T
value|0x00000008
end_define

begin_comment
comment|/* Modifies the SP ($29) register.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_WRITE_SP
value|0x00000010
end_define

begin_comment
comment|/* Modifies the RA ($31) register.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_WRITE_31
value|0x00000020
end_define

begin_comment
comment|/* Modifies the general purpose register in MIPS16OP_*_REG32R.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_WRITE_GPR_Y
value|0x00000040
end_define

begin_comment
comment|/* Reads the register in MIPS16OP_*_RX.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_READ_X
value|0x00000080
end_define

begin_comment
comment|/* Reads the register in MIPS16OP_*_RY.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_READ_Y
value|0x00000100
end_define

begin_comment
comment|/* Reads the register in MIPS16OP_*_MOVE32Z.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_READ_Z
value|0x00000200
end_define

begin_comment
comment|/* Reads the T ($24) register.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_READ_T
value|0x00000400
end_define

begin_comment
comment|/* Reads the SP ($29) register.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_READ_SP
value|0x00000800
end_define

begin_comment
comment|/* Reads the RA ($31) register.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_READ_31
value|0x00001000
end_define

begin_comment
comment|/* Reads the program counter.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_READ_PC
value|0x00002000
end_define

begin_comment
comment|/* Reads the general purpose register in MIPS16OP_*_REGR32.  */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_READ_GPR_X
value|0x00004000
end_define

begin_comment
comment|/* Is a branch insn. */
end_comment

begin_define
define|#
directive|define
name|MIPS16_INSN_BRANCH
value|0x00010000
end_define

begin_comment
comment|/* The following flags have the same value for the mips16 opcode    table:    INSN_UNCOND_BRANCH_DELAY    INSN_COND_BRANCH_DELAY    INSN_COND_BRANCH_LIKELY (never used)    INSN_READ_HI    INSN_READ_LO    INSN_WRITE_HI    INSN_WRITE_LO    INSN_TRAP    INSN_ISA3    */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mips_opcode
name|mips16_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|bfd_mips16_num_opcodes
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_H_ */
end_comment

end_unit


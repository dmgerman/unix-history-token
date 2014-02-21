begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for Intel 80386 opcode table    Copyright 2007    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"opcode/i386.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|template
block|{
comment|/* instruction name sans width suffix ("mov" for movl insns) */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* how many operands */
name|unsigned
name|int
name|operands
decl_stmt|;
comment|/* base_opcode is the fundamental opcode byte without optional      prefix(es).  */
name|unsigned
name|int
name|base_opcode
decl_stmt|;
define|#
directive|define
name|Opcode_D
value|0x2
comment|/* Direction bit: 			       set if Reg --> Regmem; 			       unset if Regmem --> Reg. */
define|#
directive|define
name|Opcode_FloatR
value|0x8
comment|/* Bit to swap src/dest for float insns. */
define|#
directive|define
name|Opcode_FloatD
value|0x400
comment|/* Direction bit for float insns. */
comment|/* extension_opcode is the 3 bit extension for group<n> insns.      This field is also used to store the 8-bit opcode suffix for the      AMD 3DNow! instructions.      If this template has no extension opcode (the usual case) use None */
name|unsigned
name|int
name|extension_opcode
decl_stmt|;
define|#
directive|define
name|None
value|0xffff
comment|/* If no extension_opcode is possible.  */
comment|/* cpu feature flags */
name|unsigned
name|int
name|cpu_flags
decl_stmt|;
define|#
directive|define
name|Cpu186
value|0x1
comment|/* i186 or better required */
define|#
directive|define
name|Cpu286
value|0x2
comment|/* i286 or better required */
define|#
directive|define
name|Cpu386
value|0x4
comment|/* i386 or better required */
define|#
directive|define
name|Cpu486
value|0x8
comment|/* i486 or better required */
define|#
directive|define
name|Cpu586
value|0x10
comment|/* i585 or better required */
define|#
directive|define
name|Cpu686
value|0x20
comment|/* i686 or better required */
define|#
directive|define
name|CpuP4
value|0x40
comment|/* Pentium4 or better required */
define|#
directive|define
name|CpuK6
value|0x80
comment|/* AMD K6 or better required*/
define|#
directive|define
name|CpuSledgehammer
value|0x100
comment|/* Sledgehammer or better required */
define|#
directive|define
name|CpuMMX
value|0x200
comment|/* MMX support required */
define|#
directive|define
name|CpuMMX2
value|0x400
comment|/* extended MMX support (with SSE or 3DNow!Ext) required */
define|#
directive|define
name|CpuSSE
value|0x800
comment|/* Streaming SIMD extensions required */
define|#
directive|define
name|CpuSSE2
value|0x1000
comment|/* Streaming SIMD extensions 2 required */
define|#
directive|define
name|Cpu3dnow
value|0x2000
comment|/* 3dnow! support required */
define|#
directive|define
name|Cpu3dnowA
value|0x4000
comment|/* 3dnow!Extensions support required */
define|#
directive|define
name|CpuSSE3
value|0x8000
comment|/* Streaming SIMD extensions 3 required */
define|#
directive|define
name|CpuPadLock
value|0x10000
comment|/* VIA PadLock required */
define|#
directive|define
name|CpuSVME
value|0x20000
comment|/* AMD Secure Virtual Machine Ext-s required */
define|#
directive|define
name|CpuVMX
value|0x40000
comment|/* VMX Instructions required */
define|#
directive|define
name|CpuSSSE3
value|0x80000
comment|/* Supplemental Streaming SIMD extensions 3 required */
define|#
directive|define
name|CpuSSE4a
value|0x100000
comment|/* SSE4a New Instuctions required */
define|#
directive|define
name|CpuABM
value|0x200000
comment|/* ABM New Instructions required */
define|#
directive|define
name|CpuSSE4_1
value|0x400000
comment|/* SSE4.1 Instructions required */
define|#
directive|define
name|CpuSSE4_2
value|0x800000
comment|/* SSE4.2 Instructions required */
define|#
directive|define
name|CpuXSAVE
value|0x1000000
comment|/* XSAVE Instructions required */
define|#
directive|define
name|CpuAES
value|0x2000000
comment|/* AES Instructions required */
comment|/* These flags are set by gas depending on the flag_code.  */
define|#
directive|define
name|Cpu64
value|0x4000000
comment|/* 64bit support required  */
define|#
directive|define
name|CpuNo64
value|0x8000000
comment|/* Not supported in the 64bit mode  */
define|#
directive|define
name|CpuPCLMUL
value|0x10000000
comment|/* Carry-less Multiplication extensions */
define|#
directive|define
name|CpuRdRnd
value|0x20000000
comment|/* Intel Random Number Generator extensions */
define|#
directive|define
name|CpuSMAP
value|0x40000000
comment|/* Intel Supervisor Mode Access Prevention */
comment|/* SSE4.1/4.2 Instructions required */
define|#
directive|define
name|CpuSSE4
value|(CpuSSE4_1|CpuSSE4_2)
comment|/* The default value for unknown CPUs - enable all features to avoid problems.  */
define|#
directive|define
name|CpuUnknownFlags
value|(Cpu186|Cpu286|Cpu386|Cpu486|Cpu586|Cpu686 \ 	|CpuP4|CpuSledgehammer|CpuMMX|CpuMMX2|CpuSSE|CpuSSE2|CpuSSE3|CpuVMX \ 	|Cpu3dnow|Cpu3dnowA|CpuK6|CpuPadLock|CpuSVME|CpuSSSE3|CpuSSE4_1 \ 	|CpuSSE4_2|CpuABM|CpuSSE4a|CpuXSAVE|CpuAES|CpuPCLMUL|CpuRdRnd|CpuSMAP)
comment|/* the bits in opcode_modifier are used to generate the final opcode from      the base_opcode.  These bits also are used to detect alternate forms of      the same instruction */
name|unsigned
name|int
name|opcode_modifier
decl_stmt|;
comment|/* opcode_modifier bits: */
define|#
directive|define
name|D
value|0x1
comment|/* has direction bit. */
define|#
directive|define
name|W
value|0x2
comment|/* set if operands can be words or dwords 				   encoded the canonical way */
define|#
directive|define
name|Modrm
value|0x4
comment|/* insn has a modrm byte. */
define|#
directive|define
name|ShortForm
value|0x8
comment|/* register is in low 3 bits of opcode */
define|#
directive|define
name|Jump
value|0x10
comment|/* special case for jump insns.  */
define|#
directive|define
name|JumpDword
value|0x20
comment|/* call and jump */
define|#
directive|define
name|JumpByte
value|0x40
comment|/* loop and jecxz */
define|#
directive|define
name|JumpInterSegment
value|0x80
comment|/* special case for intersegment leaps/calls */
define|#
directive|define
name|FloatMF
value|0x100
comment|/* FP insn memory format bit, sized by 0x4 */
define|#
directive|define
name|FloatR
value|0x200
comment|/* src/dest swap for floats. */
define|#
directive|define
name|FloatD
value|0x400
comment|/* has float insn direction bit. */
define|#
directive|define
name|Size16
value|0x800
comment|/* needs size prefix if in 32-bit mode */
define|#
directive|define
name|Size32
value|0x1000
comment|/* needs size prefix if in 16-bit mode */
define|#
directive|define
name|Size64
value|0x2000
comment|/* needs size prefix if in 64-bit mode */
define|#
directive|define
name|IgnoreSize
value|0x4000
comment|/* instruction ignores operand size prefix */
define|#
directive|define
name|DefaultSize
value|0x8000
comment|/* default insn size depends on mode */
define|#
directive|define
name|No_bSuf
value|0x10000
comment|/* b suffix on instruction illegal */
define|#
directive|define
name|No_wSuf
value|0x20000
comment|/* w suffix on instruction illegal */
define|#
directive|define
name|No_lSuf
value|0x40000
comment|/* l suffix on instruction illegal */
define|#
directive|define
name|No_sSuf
value|0x80000
comment|/* s suffix on instruction illegal */
define|#
directive|define
name|No_qSuf
value|0x100000
comment|/* q suffix on instruction illegal */
define|#
directive|define
name|No_xSuf
value|0x200000
comment|/* x suffix on instruction illegal */
define|#
directive|define
name|FWait
value|0x400000
comment|/* instruction needs FWAIT */
define|#
directive|define
name|IsString
value|0x800000
comment|/* quick test for string instructions */
define|#
directive|define
name|RegKludge
value|0x1000000
comment|/* fake an extra reg operand for clr, imul 				   and special register processing for 				   some instructions.  */
define|#
directive|define
name|IsPrefix
value|0x2000000
comment|/* opcode is a prefix */
define|#
directive|define
name|ImmExt
value|0x4000000
comment|/* instruction has extension in 8 bit imm */
define|#
directive|define
name|NoRex64
value|0x8000000
comment|/* instruction don't need Rex64 prefix.  */
define|#
directive|define
name|Rex64
value|0x10000000
comment|/* instruction require Rex64 prefix.  */
define|#
directive|define
name|Ugh
value|0x20000000
comment|/* deprecated fp insn, gets a warning */
define|#
directive|define
name|NoSuf
value|(No_bSuf|No_wSuf|No_lSuf|No_sSuf|No_qSuf|No_xSuf)
comment|/* operand_types[i] describes the type of operand i.  This is made      by OR'ing together all of the possible type masks.  (e.g.      'operand_types[i] = Reg|Imm' specifies that operand i can be      either a register or an immediate operand.  */
name|unsigned
name|int
name|operand_types
index|[
name|MAX_OPERANDS
index|]
decl_stmt|;
comment|/* operand_types[i] bits */
comment|/* register */
define|#
directive|define
name|Reg8
value|0x1
comment|/* 8 bit reg */
define|#
directive|define
name|Reg16
value|0x2
comment|/* 16 bit reg */
define|#
directive|define
name|Reg32
value|0x4
comment|/* 32 bit reg */
define|#
directive|define
name|Reg64
value|0x8
comment|/* 64 bit reg */
comment|/* immediate */
define|#
directive|define
name|Imm8
value|0x10
comment|/* 8 bit immediate */
define|#
directive|define
name|Imm8S
value|0x20
comment|/* 8 bit immediate sign extended */
define|#
directive|define
name|Imm16
value|0x40
comment|/* 16 bit immediate */
define|#
directive|define
name|Imm32
value|0x80
comment|/* 32 bit immediate */
define|#
directive|define
name|Imm32S
value|0x100
comment|/* 32 bit immediate sign extended */
define|#
directive|define
name|Imm64
value|0x200
comment|/* 64 bit immediate */
define|#
directive|define
name|Imm1
value|0x400
comment|/* 1 bit immediate */
comment|/* memory */
define|#
directive|define
name|BaseIndex
value|0x800
comment|/* Disp8,16,32 are used in different ways, depending on the      instruction.  For jumps, they specify the size of the PC relative      displacement, for baseindex type instructions, they specify the      size of the offset relative to the base register, and for memory      offset instructions such as `mov 1234,%al' they specify the size of      the offset relative to the segment base.  */
define|#
directive|define
name|Disp8
value|0x1000
comment|/* 8 bit displacement */
define|#
directive|define
name|Disp16
value|0x2000
comment|/* 16 bit displacement */
define|#
directive|define
name|Disp32
value|0x4000
comment|/* 32 bit displacement */
define|#
directive|define
name|Disp32S
value|0x8000
comment|/* 32 bit signed displacement */
define|#
directive|define
name|Disp64
value|0x10000
comment|/* 64 bit displacement */
comment|/* specials */
define|#
directive|define
name|InOutPortReg
value|0x20000
comment|/* register to hold in/out port addr = dx */
define|#
directive|define
name|ShiftCount
value|0x40000
comment|/* register to hold shift count = cl */
define|#
directive|define
name|Control
value|0x80000
comment|/* Control register */
define|#
directive|define
name|Debug
value|0x100000
comment|/* Debug register */
define|#
directive|define
name|Test
value|0x200000
comment|/* Test register */
define|#
directive|define
name|FloatReg
value|0x400000
comment|/* Float register */
define|#
directive|define
name|FloatAcc
value|0x800000
comment|/* Float stack top %st(0) */
define|#
directive|define
name|SReg2
value|0x1000000
comment|/* 2 bit segment register */
define|#
directive|define
name|SReg3
value|0x2000000
comment|/* 3 bit segment register */
define|#
directive|define
name|Acc
value|0x4000000
comment|/* Accumulator %al or %ax or %eax */
define|#
directive|define
name|JumpAbsolute
value|0x8000000
define|#
directive|define
name|RegMMX
value|0x10000000
comment|/* MMX register */
define|#
directive|define
name|RegXMM
value|0x20000000
comment|/* XMM registers in PIII */
define|#
directive|define
name|EsSeg
value|0x40000000
comment|/* String insn operand with fixed es segment */
comment|/* RegMem is for instructions with a modrm byte where the register      destination operand should be encoded in the mod and regmem fields.      Normally, it will be encoded in the reg field. We add a RegMem      flag to the destination register operand to indicate that it should      be encoded in the regmem field.  */
define|#
directive|define
name|RegMem
value|0x80000000
define|#
directive|define
name|Reg
value|(Reg8|Reg16|Reg32|Reg64)
comment|/* gen'l register */
define|#
directive|define
name|WordReg
value|(Reg16|Reg32|Reg64)
define|#
directive|define
name|ImplicitRegister
value|(InOutPortReg|ShiftCount|Acc|FloatAcc)
define|#
directive|define
name|Imm
value|(Imm8|Imm8S|Imm16|Imm32S|Imm32|Imm64)
comment|/* gen'l immediate */
define|#
directive|define
name|EncImm
value|(Imm8|Imm16|Imm32|Imm32S)
comment|/* Encodable gen'l immediate */
define|#
directive|define
name|Disp
value|(Disp8|Disp16|Disp32|Disp32S|Disp64)
comment|/* General displacement */
define|#
directive|define
name|AnyMem
value|(Disp8|Disp16|Disp32|Disp32S|BaseIndex)
comment|/* General memory */
comment|/* The following aliases are defined because the opcode table      carefully specifies the allowed memory types for each instruction.      At the moment we can only tell a memory reference size by the      instruction suffix, so there's not much point in defining Mem8,      Mem16, Mem32 and Mem64 opcode modifiers - We might as well just use      the suffix directly to check memory operands.  */
define|#
directive|define
name|LLongMem
value|AnyMem
comment|/* 64 bits (or more) */
define|#
directive|define
name|LongMem
value|AnyMem
comment|/* 32 bit memory ref */
define|#
directive|define
name|ShortMem
value|AnyMem
comment|/* 16 bit memory ref */
define|#
directive|define
name|WordMem
value|AnyMem
comment|/* 16, 32 or 64 bit memory ref */
define|#
directive|define
name|ByteMem
value|AnyMem
comment|/* 8 bit memory ref */
block|}
name|template
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|template
name|i386_optab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* these are for register name --> number& type hash lookup */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|reg_name
decl_stmt|;
name|unsigned
name|int
name|reg_type
decl_stmt|;
name|unsigned
name|int
name|reg_flags
decl_stmt|;
define|#
directive|define
name|RegRex
value|0x1
comment|/* Extended register.  */
define|#
directive|define
name|RegRex64
value|0x2
comment|/* Extended 8 bit register.  */
name|unsigned
name|int
name|reg_num
decl_stmt|;
block|}
name|reg_entry
typedef|;
end_typedef

begin_comment
comment|/* Entries in i386_regtab.  */
end_comment

begin_define
define|#
directive|define
name|REGNAM_AL
value|1
end_define

begin_define
define|#
directive|define
name|REGNAM_AX
value|25
end_define

begin_define
define|#
directive|define
name|REGNAM_EAX
value|41
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|reg_entry
name|i386_regtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|int
name|i386_regtab_size
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|seg_name
decl_stmt|;
name|unsigned
name|int
name|seg_prefix
decl_stmt|;
block|}
name|seg_entry
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|seg_entry
name|cs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|seg_entry
name|ds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|seg_entry
name|ss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|seg_entry
name|es
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|seg_entry
name|fs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|seg_entry
name|gs
decl_stmt|;
end_decl_stmt

end_unit


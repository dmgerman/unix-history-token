begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* i386.h -- Header file for i386.c    Copyright (C) 1989, Free Software Foundation.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|MAX_OPERANDS
value|3
end_define

begin_comment
comment|/* max operands per insn */
end_comment

begin_define
define|#
directive|define
name|MAX_PREFIXES
value|4
end_define

begin_comment
comment|/* max prefixes per opcode */
end_comment

begin_define
define|#
directive|define
name|MAX_IMMEDIATE_OPERANDS
value|2
end_define

begin_comment
comment|/* max immediates per insn */
end_comment

begin_define
define|#
directive|define
name|MAX_MEMORY_OPERANDS
value|2
end_define

begin_comment
comment|/* max memory ref per insn 				 * lcall uses 2 				 */
end_comment

begin_comment
comment|/* we define the syntax here (modulo base,index,scale syntax) */
end_comment

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|'%'
end_define

begin_define
define|#
directive|define
name|IMMEDIATE_PREFIX
value|'$'
end_define

begin_define
define|#
directive|define
name|ABSOLUTE_PREFIX
value|'*'
end_define

begin_define
define|#
directive|define
name|PREFIX_SEPERATOR
value|'/'
end_define

begin_define
define|#
directive|define
name|TWO_BYTE_OPCODE_ESCAPE
value|0x0f
end_define

begin_comment
comment|/* register numbers */
end_comment

begin_define
define|#
directive|define
name|EBP_REG_NUM
value|5
end_define

begin_define
define|#
directive|define
name|ESP_REG_NUM
value|4
end_define

begin_comment
comment|/* modrm_byte.regmem for twobyte escape */
end_comment

begin_define
define|#
directive|define
name|ESCAPE_TO_TWO_BYTE_ADDRESSING
value|ESP_REG_NUM
end_define

begin_comment
comment|/* index_base_byte.index for no index register addressing */
end_comment

begin_define
define|#
directive|define
name|NO_INDEX_REGISTER
value|ESP_REG_NUM
end_define

begin_comment
comment|/* index_base_byte.base for no base register addressing */
end_comment

begin_define
define|#
directive|define
name|NO_BASE_REGISTER
value|EBP_REG_NUM
end_define

begin_comment
comment|/* these are the att as opcode suffixes, making movl --> mov, for example */
end_comment

begin_define
define|#
directive|define
name|DWORD_OPCODE_SUFFIX
value|'l'
end_define

begin_define
define|#
directive|define
name|WORD_OPCODE_SUFFIX
value|'w'
end_define

begin_define
define|#
directive|define
name|BYTE_OPCODE_SUFFIX
value|'b'
end_define

begin_comment
comment|/* modrm.mode = REGMEM_FIELD_HAS_REG when a register is in there */
end_comment

begin_define
define|#
directive|define
name|REGMEM_FIELD_HAS_REG
value|0x3
end_define

begin_comment
comment|/* always = 0x3 */
end_comment

begin_define
define|#
directive|define
name|REGMEM_FIELD_HAS_MEM
value|(~REGMEM_FIELD_HAS_REG)
end_define

begin_define
define|#
directive|define
name|END_OF_INSN
value|'\0'
end_define

begin_comment
comment|/* When an operand is read in it is classified by its type.  This type includes all the possible ways an operand can be used.  Thus, '%eax' is both 'register # 0' and 'The Accumulator'.  In our language this is expressed by OR'ing 'Reg32' (any 32 bit register) and 'Acc' (the accumulator). Operands are classified so that we can match given operand types with the opcode table in i386-opcode.h.  */
end_comment

begin_define
define|#
directive|define
name|Unknown
value|0x0
end_define

begin_comment
comment|/* register */
end_comment

begin_define
define|#
directive|define
name|Reg8
value|0x1
end_define

begin_comment
comment|/* 8 bit reg */
end_comment

begin_define
define|#
directive|define
name|Reg16
value|0x2
end_define

begin_comment
comment|/* 16 bit reg */
end_comment

begin_define
define|#
directive|define
name|Reg32
value|0x4
end_define

begin_comment
comment|/* 32 bit reg */
end_comment

begin_define
define|#
directive|define
name|Reg
value|(Reg8|Reg16|Reg32)
end_define

begin_comment
comment|/* gen'l register */
end_comment

begin_define
define|#
directive|define
name|WordReg
value|(Reg16|Reg32)
end_define

begin_comment
comment|/* for push/pop operands */
end_comment

begin_comment
comment|/* immediate */
end_comment

begin_define
define|#
directive|define
name|Imm8
value|0x8
end_define

begin_comment
comment|/* 8 bit immediate */
end_comment

begin_define
define|#
directive|define
name|Imm8S
value|0x10
end_define

begin_comment
comment|/* 8 bit immediate sign extended */
end_comment

begin_define
define|#
directive|define
name|Imm16
value|0x20
end_define

begin_comment
comment|/* 16 bit immediate */
end_comment

begin_define
define|#
directive|define
name|Imm32
value|0x40
end_define

begin_comment
comment|/* 32 bit immediate */
end_comment

begin_define
define|#
directive|define
name|Imm1
value|0x80
end_define

begin_comment
comment|/* 1 bit immediate */
end_comment

begin_define
define|#
directive|define
name|ImmUnknown
value|Imm32
end_define

begin_comment
comment|/* for unknown expressions */
end_comment

begin_define
define|#
directive|define
name|Imm
value|(Imm8|Imm8S|Imm16|Imm32)
end_define

begin_comment
comment|/* gen'l immediate */
end_comment

begin_comment
comment|/* memory */
end_comment

begin_define
define|#
directive|define
name|Disp8
value|0x200
end_define

begin_comment
comment|/* 8 bit displacement (for jumps) */
end_comment

begin_define
define|#
directive|define
name|Disp16
value|0x400
end_define

begin_comment
comment|/* 16 bit displacement */
end_comment

begin_define
define|#
directive|define
name|Disp32
value|0x800
end_define

begin_comment
comment|/* 32 bit displacement */
end_comment

begin_define
define|#
directive|define
name|Disp
value|(Disp8|Disp16|Disp32)
end_define

begin_comment
comment|/* General displacement */
end_comment

begin_define
define|#
directive|define
name|DispUnknown
value|Disp32
end_define

begin_comment
comment|/* for unknown size displacements */
end_comment

begin_define
define|#
directive|define
name|Mem8
value|0x1000
end_define

begin_define
define|#
directive|define
name|Mem16
value|0x2000
end_define

begin_define
define|#
directive|define
name|Mem32
value|0x4000
end_define

begin_define
define|#
directive|define
name|BaseIndex
value|0x8000
end_define

begin_define
define|#
directive|define
name|Mem
value|(Disp|Mem8|Mem16|Mem32|BaseIndex)
end_define

begin_comment
comment|/* General memory */
end_comment

begin_define
define|#
directive|define
name|WordMem
value|(Mem16|Mem32|Disp|BaseIndex)
end_define

begin_define
define|#
directive|define
name|ByteMem
value|(Mem8|Disp|BaseIndex)
end_define

begin_comment
comment|/* specials */
end_comment

begin_define
define|#
directive|define
name|InOutPortReg
value|0x10000
end_define

begin_comment
comment|/* register to hold in/out port addr = dx */
end_comment

begin_define
define|#
directive|define
name|ShiftCount
value|0x20000
end_define

begin_comment
comment|/* register to hold shift cound = cl */
end_comment

begin_define
define|#
directive|define
name|Control
value|0x40000
end_define

begin_comment
comment|/* Control register */
end_comment

begin_define
define|#
directive|define
name|Debug
value|0x80000
end_define

begin_comment
comment|/* Debug register */
end_comment

begin_define
define|#
directive|define
name|Test
value|0x100000
end_define

begin_comment
comment|/* Test register */
end_comment

begin_define
define|#
directive|define
name|FloatReg
value|0x200000
end_define

begin_comment
comment|/* Float register */
end_comment

begin_define
define|#
directive|define
name|FloatAcc
value|0x400000
end_define

begin_comment
comment|/* Float stack top %st(0) */
end_comment

begin_define
define|#
directive|define
name|SReg2
value|0x800000
end_define

begin_comment
comment|/* 2 bit segment register */
end_comment

begin_define
define|#
directive|define
name|SReg3
value|0x1000000
end_define

begin_comment
comment|/* 3 bit segment register */
end_comment

begin_define
define|#
directive|define
name|Acc
value|0x2000000
end_define

begin_comment
comment|/* Accumulator %al or %ax or %eax */
end_comment

begin_define
define|#
directive|define
name|ImplicitRegister
value|(InOutPortReg|ShiftCount|Acc|FloatAcc)
end_define

begin_define
define|#
directive|define
name|JumpAbsolute
value|0x4000000
end_define

begin_define
define|#
directive|define
name|Abs8
value|0x08000000
end_define

begin_define
define|#
directive|define
name|Abs16
value|0x10000000
end_define

begin_define
define|#
directive|define
name|Abs32
value|0x20000000
end_define

begin_define
define|#
directive|define
name|Abs
value|(Abs8|Abs16|Abs32)
end_define

begin_define
define|#
directive|define
name|MODE_FROM_DISP_SIZE
parameter_list|(
name|t
parameter_list|)
define|\
value|((t&(Disp8)) ? 1 : \        ((t&(Disp32)) ? 2 : 0))
end_define

begin_define
define|#
directive|define
name|Byte
value|(Reg8|Imm8|Imm8S)
end_define

begin_define
define|#
directive|define
name|Word
value|(Reg16|Imm16)
end_define

begin_define
define|#
directive|define
name|DWord
value|(Reg32|Imm32)
end_define

begin_comment
comment|/* convert opcode suffix ('b' 'w' 'l' typically) into type specifyer */
end_comment

begin_define
define|#
directive|define
name|OPCODE_SUFFIX_TO_TYPE
parameter_list|(
name|s
parameter_list|)
define|\
value|(s == BYTE_OPCODE_SUFFIX ? Byte : \    (s == WORD_OPCODE_SUFFIX ? Word : DWord))
end_define

begin_define
define|#
directive|define
name|FITS_IN_SIGNED_BYTE
parameter_list|(
name|num
parameter_list|)
value|((num)>= -128&& (num)<= 127)
end_define

begin_define
define|#
directive|define
name|FITS_IN_UNSIGNED_BYTE
parameter_list|(
name|num
parameter_list|)
value|((num)>= 0&& (num)<= 255)
end_define

begin_define
define|#
directive|define
name|FITS_IN_UNSIGNED_WORD
parameter_list|(
name|num
parameter_list|)
value|((num)>= 0&& (num)<= 65535)
end_define

begin_define
define|#
directive|define
name|FITS_IN_SIGNED_WORD
parameter_list|(
name|num
parameter_list|)
value|((num)>= -32768&& (num)<= 32767)
end_define

begin_define
define|#
directive|define
name|SMALLEST_DISP_TYPE
parameter_list|(
name|num
parameter_list|)
define|\
value|FITS_IN_SIGNED_BYTE(num) ? (Disp8|Disp32|Abs8|Abs32) : (Disp32|Abs32)
end_define

begin_define
define|#
directive|define
name|SMALLEST_IMM_TYPE
parameter_list|(
name|num
parameter_list|)
define|\
value|(num == 1) ? (Imm1|Imm8|Imm8S|Imm16|Imm32): \   FITS_IN_SIGNED_BYTE(num) ? (Imm8S|Imm8|Imm16|Imm32) : \   FITS_IN_UNSIGNED_BYTE(num) ? (Imm8|Imm16|Imm32): \   (FITS_IN_SIGNED_WORD(num)||FITS_IN_UNSIGNED_WORD(num)) ? (Imm16|Imm32) : \   (Imm32)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uchar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* instruction name sans width suffix ("mov" for movl insns) */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* how many operands */
name|uint
name|operands
decl_stmt|;
comment|/* base_opcode is the fundamental opcode byte with a optional prefix(es). */
name|uint
name|base_opcode
decl_stmt|;
comment|/* extension_opcode is the 3 bit extension for group<n> insns.      If this template has no extension opcode (the usual case) use None */
name|uchar
name|extension_opcode
decl_stmt|;
define|#
directive|define
name|None
value|0xff
comment|/* If no extension_opcode is possible. */
comment|/* the bits in opcode_modifier are used to generate the final opcode from      the base_opcode.  These bits also are used to detect alternate forms of      the same instruction */
name|uint
name|opcode_modifier
decl_stmt|;
comment|/* opcode_modifier bits: */
define|#
directive|define
name|W
value|0x1
comment|/* set if operands are words or dwords */
define|#
directive|define
name|D
value|0x2
comment|/* D = 0 if Reg --> Regmem; D = 1 if Regmem --> Reg */
comment|/* direction flag for floating insns:  MUST BE 0x400 */
define|#
directive|define
name|FloatD
value|0x400
comment|/* shorthand */
define|#
directive|define
name|DW
value|(D|W)
define|#
directive|define
name|ShortForm
value|0x10
comment|/* register is in low 3 bits of opcode */
define|#
directive|define
name|ShortFormW
value|0x20
comment|/* ShortForm and W bit is 0x8 */
define|#
directive|define
name|Seg2ShortForm
value|0x40
comment|/* encoding of load segment reg insns */
define|#
directive|define
name|Seg3ShortForm
value|0x80
comment|/* fs/gs segment register insns. */
define|#
directive|define
name|Jump
value|0x100
comment|/* special case for jump insns. */
define|#
directive|define
name|JumpInterSegment
value|0x200
comment|/* special case for intersegment leaps/calls */
comment|/* 0x400 CANNOT BE USED since it's already used by FloatD above */
define|#
directive|define
name|DONT_USE
value|0x400
define|#
directive|define
name|NoModrm
value|0x800
define|#
directive|define
name|Modrm
value|0x1000
define|#
directive|define
name|imulKludge
value|0x2000
define|#
directive|define
name|JumpByte
value|0x4000
define|#
directive|define
name|JumpDword
value|0x8000
define|#
directive|define
name|ReverseRegRegmem
value|0x10000
comment|/* (opcode_modifier& COMES_IN_ALL_SIZES) is true if the      instuction comes in byte, word, and dword sizes and is encoded into      machine code in the canonical way. */
define|#
directive|define
name|COMES_IN_ALL_SIZES
value|(W)
comment|/* (opcode_modifier& COMES_IN_BOTH_DIRECTIONS) indicates that the      source and destination operands can be reversed by setting either      the D (for integer insns) or the FloatD (for floating insns) bit      in base_opcode. */
define|#
directive|define
name|COMES_IN_BOTH_DIRECTIONS
value|(D|FloatD)
comment|/* operand_types[i] describes the type of operand i.  This is made      by OR'ing together all of the possible type masks.  (e.g.      'operand_types[i] = Reg|Imm' specifies that operand i can be      either a register or an immediate operand */
name|uint
name|operand_types
index|[
literal|3
index|]
decl_stmt|;
block|}
name|template
typedef|;
end_typedef

begin_comment
comment|/*   'templates' is for grouping together 'template' structures for opcodes   of the same name.  This is only used for storing the insns in the grand   ole hash table of insns.   The templates themselves start at START and range up to (but not including)   END. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|template
modifier|*
name|start
decl_stmt|;
name|template
modifier|*
name|end
decl_stmt|;
block|}
name|templates
typedef|;
end_typedef

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
name|uint
name|reg_type
decl_stmt|;
name|uint
name|reg_num
decl_stmt|;
block|}
name|reg_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|seg_name
decl_stmt|;
name|uint
name|seg_prefix
decl_stmt|;
block|}
name|seg_entry
typedef|;
end_typedef

begin_comment
comment|/* these are for prefix name --> prefix code hash lookup */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|prefix_name
decl_stmt|;
name|uchar
name|prefix_code
decl_stmt|;
block|}
name|prefix_entry
typedef|;
end_typedef

begin_comment
comment|/* 386 operand encoding bytes:  see 386 book for details of this. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|regmem
range|:
literal|3
decl_stmt|;
comment|/* codes register or memory operand */
name|unsigned
name|reg
range|:
literal|3
decl_stmt|;
comment|/* codes register operand (or extended opcode) */
name|unsigned
name|mode
range|:
literal|2
decl_stmt|;
comment|/* how to interpret regmem& reg */
block|}
name|modrm_byte
typedef|;
end_typedef

begin_comment
comment|/* 386 opcode byte to code indirect addressing. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|base
range|:
literal|3
decl_stmt|;
name|unsigned
name|index
range|:
literal|3
decl_stmt|;
name|unsigned
name|scale
range|:
literal|2
decl_stmt|;
block|}
name|base_index_byte
typedef|;
end_typedef

begin_comment
comment|/* 'md_assemble ()' gathers together information and puts it into a    i386_insn. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* TM holds the template for the insn were currently assembling. */
name|template
name|tm
decl_stmt|;
comment|/* SUFFIX holds the opcode suffix (e.g. 'l' for 'movl') if given. */
name|char
name|suffix
decl_stmt|;
comment|/* Operands are coded with OPERANDS, TYPES, DISPS, IMMS, and REGS. */
comment|/* OPERANDS gives the number of given operands. */
name|uint
name|operands
decl_stmt|;
comment|/* REG_OPERANDS, DISP_OPERANDS, MEM_OPERANDS, IMM_OPERANDS give the number of      given register, displacement, memory operands and immediate operands. */
name|uint
name|reg_operands
decl_stmt|,
name|disp_operands
decl_stmt|,
name|mem_operands
decl_stmt|,
name|imm_operands
decl_stmt|;
comment|/* TYPES [i] is the type (see above #defines) which tells us how to      search through DISPS [i]& IMMS [i]& REGS [i] for the required      operand. */
name|uint
name|types
index|[
name|MAX_OPERANDS
index|]
decl_stmt|;
comment|/* Displacements (if given) for each operand. */
name|expressionS
modifier|*
name|disps
index|[
name|MAX_OPERANDS
index|]
decl_stmt|;
comment|/* Immediate operands (if given) for each operand. */
name|expressionS
modifier|*
name|imms
index|[
name|MAX_OPERANDS
index|]
decl_stmt|;
comment|/* Register operands (if given) for each operand. */
name|reg_entry
modifier|*
name|regs
index|[
name|MAX_OPERANDS
index|]
decl_stmt|;
comment|/* BASE_REG, INDEX_REG, and LOG2_SCALE_FACTOR are used to encode      the base index byte below.  */
name|reg_entry
modifier|*
name|base_reg
decl_stmt|;
name|reg_entry
modifier|*
name|index_reg
decl_stmt|;
name|uint
name|log2_scale_factor
decl_stmt|;
comment|/* SEG gives the seg_entry of this insn.  It is equal to zero unless      an explicit segment override is given. */
name|seg_entry
modifier|*
name|seg
decl_stmt|;
comment|/* segment for memory operands (if given) */
comment|/* PREFIX holds all the given prefix opcodes (usually null).      PREFIXES is the size of PREFIX. */
name|char
name|prefix
index|[
name|MAX_PREFIXES
index|]
decl_stmt|;
name|uint
name|prefixes
decl_stmt|;
comment|/* RM and IB are the modrm byte and the base index byte where the addressing      modes of this insn are encoded. */
name|modrm_byte
name|rm
decl_stmt|;
name|base_index_byte
name|bi
decl_stmt|;
block|}
name|i386_insn
typedef|;
end_typedef

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* s390.h -- Header file for S390 opcode table    Copyright 2000, 2001 Free Software Foundation, Inc.    Contributed by Martin Schwidefsky (schwidefsky@de.ibm.com).     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S390_H
end_ifndef

begin_define
define|#
directive|define
name|S390_H
end_define

begin_comment
comment|/* List of instruction sets variations. */
end_comment

begin_enum
enum|enum
name|s390_opcode_mode_val
block|{
name|S390_OPCODE_ESA
init|=
literal|0
block|,
name|S390_OPCODE_ZARCH
block|}
enum|;
end_enum

begin_enum
enum|enum
name|s390_opcode_cpu_val
block|{
name|S390_OPCODE_G5
init|=
literal|0
block|,
name|S390_OPCODE_G6
block|,
name|S390_OPCODE_Z900
block|,
name|S390_OPCODE_Z990
block|}
enum|;
end_enum

begin_comment
comment|/* The opcode table is an array of struct s390_opcode.  */
end_comment

begin_struct
struct|struct
name|s390_opcode
block|{
comment|/* The opcode name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The opcode itself.  Those bits which will be filled in with        operands are zeroes.  */
name|unsigned
name|char
name|opcode
index|[
literal|6
index|]
decl_stmt|;
comment|/* The opcode mask.  This is used by the disassembler.  This is a        mask containing ones indicating those bits which must match the        opcode field, and zeroes indicating those bits which need not        match (and are presumably filled in by operands).  */
name|unsigned
name|char
name|mask
index|[
literal|6
index|]
decl_stmt|;
comment|/* The opcode length in bytes. */
name|int
name|oplen
decl_stmt|;
comment|/* An array of operand codes.  Each code is an index into the        operand table.  They appear in the order which the operands must        appear in assembly code, and are terminated by a zero.  */
name|unsigned
name|char
name|operands
index|[
literal|6
index|]
decl_stmt|;
comment|/* Bitmask of execution modes this opcode is available for.  */
name|unsigned
name|int
name|modes
decl_stmt|;
comment|/* First cpu this opcode is available for.  */
name|enum
name|s390_opcode_cpu_val
name|min_cpu
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The table itself is sorted by major opcode number, and is otherwise    in the order in which the disassembler should consider    instructions.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|s390_opcode
name|s390_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|s390_num_opcodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A opcode format table for the .insn pseudo mnemonic.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|s390_opcode
name|s390_opformats
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|s390_num_opformats
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct powerpc_opcode.  */
end_comment

begin_comment
comment|/* The operands table is an array of struct s390_operand.  */
end_comment

begin_struct
struct|struct
name|s390_operand
block|{
comment|/* The number of bits in the operand.  */
name|int
name|bits
decl_stmt|;
comment|/* How far the operand is left shifted in the instruction.  */
name|int
name|shift
decl_stmt|;
comment|/* One bit syntax flags.  */
name|unsigned
name|long
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Elements in the table are retrieved by indexing with values from    the operands field of the powerpc_opcodes table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|s390_operand
name|s390_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct s390_operand.  */
end_comment

begin_comment
comment|/* This operand names a register.  The disassembler uses this to print    register names with a leading 'r'.  */
end_comment

begin_define
define|#
directive|define
name|S390_OPERAND_GPR
value|0x1
end_define

begin_comment
comment|/* This operand names a floating point register.  The disassembler    prints these with a leading 'f'. */
end_comment

begin_define
define|#
directive|define
name|S390_OPERAND_FPR
value|0x2
end_define

begin_comment
comment|/* This operand names an access register.  The disassembler    prints these with a leading 'a'.  */
end_comment

begin_define
define|#
directive|define
name|S390_OPERAND_AR
value|0x4
end_define

begin_comment
comment|/* This operand names a control register.  The disassembler    prints these with a leading 'c'.  */
end_comment

begin_define
define|#
directive|define
name|S390_OPERAND_CR
value|0x8
end_define

begin_comment
comment|/* This operand is a displacement.  */
end_comment

begin_define
define|#
directive|define
name|S390_OPERAND_DISP
value|0x10
end_define

begin_comment
comment|/* This operand names a base register.  */
end_comment

begin_define
define|#
directive|define
name|S390_OPERAND_BASE
value|0x20
end_define

begin_comment
comment|/* This operand names an index register, it can be skipped.  */
end_comment

begin_define
define|#
directive|define
name|S390_OPERAND_INDEX
value|0x40
end_define

begin_comment
comment|/* This operand is a relative branch displacement.  The disassembler    prints these symbolically if possible.  */
end_comment

begin_define
define|#
directive|define
name|S390_OPERAND_PCREL
value|0x80
end_define

begin_comment
comment|/* This operand takes signed values.  */
end_comment

begin_define
define|#
directive|define
name|S390_OPERAND_SIGNED
value|0x100
end_define

begin_comment
comment|/* This operand is a length.  */
end_comment

begin_define
define|#
directive|define
name|S390_OPERAND_LENGTH
value|0x200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S390_H */
end_comment

end_unit


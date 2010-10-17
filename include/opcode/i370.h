begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* i370.h -- Header file for S/390 opcode table    Copyright 1994, 1995, 1998, 1999, 2000, 2003 Free Software Foundation, Inc.    PowerPC version written by Ian Lance Taylor, Cygnus Support    Rewritten for i370 ESA/390 support, Linas Vepstas<linas@linas.org>  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I370_H
end_ifndef

begin_define
define|#
directive|define
name|I370_H
end_define

begin_comment
comment|/* The opcode table is an array of struct i370_opcode.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|unsigned
name|int
name|i
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|short
name|s
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|b
index|[
literal|8
index|]
decl_stmt|;
block|}
name|i370_insn_t
typedef|;
end_typedef

begin_struct
struct|struct
name|i370_opcode
block|{
comment|/* The opcode name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* the length of the instruction */
name|char
name|len
decl_stmt|;
comment|/* The opcode itself.  Those bits which will be filled in with      operands are zeroes.  */
name|i370_insn_t
name|opcode
decl_stmt|;
comment|/* The opcode mask.  This is used by the disassembler.  This is a      mask containing ones indicating those bits which must match the      opcode field, and zeroes indicating those bits which need not      match (and are presumably filled in by operands).  */
name|i370_insn_t
name|mask
decl_stmt|;
comment|/* One bit flags for the opcode.  These are used to indicate which      specific processors support the instructions.  The defined values      are listed below.  */
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* An array of operand codes.  Each code is an index into the      operand table.  They appear in the order which the operands must      appear in assembly code, and are terminated by a zero.  */
name|unsigned
name|char
name|operands
index|[
literal|8
index|]
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
name|i370_opcode
name|i370_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|i370_num_opcodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct i370_opcode.  */
end_comment

begin_comment
comment|/* Opcode is defined for the original 360 architecture.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_360
value|(0x01)
end_define

begin_comment
comment|/* Opcode is defined for the 370 architecture.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_370
value|(0x02)
end_define

begin_comment
comment|/* Opcode is defined for the 370-XA architecture.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_370_XA
value|(0x04)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/370 architecture.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA370
value|(0x08)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 architecture.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390
value|(0x10)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ BFP facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_BF
value|(0x20)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ branch& set authority facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_BS
value|(0x40)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ checksum facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_CK
value|(0x80)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ compare& move extended facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_CM
value|(0x100)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ flt.pt. support extensions facility. */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_FX
value|(0x200)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ HFP facility. */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_HX
value|(0x400)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ immediate& relative facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_IR
value|(0x800)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ move-inverse facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_MI
value|(0x1000)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ program-call-fast facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_PC
value|(0x2000)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ perform-locked-op facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_PL
value|(0x4000)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ square-root facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_QR
value|(0x8000)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ resume-program facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_RP
value|(0x10000)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ set-address-space-fast facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_SA
value|(0x20000)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ subspace group facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_SG
value|(0x40000)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ string facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_SR
value|(0x80000)
end_define

begin_comment
comment|/* Opcode is defined for the ESA/390 w/ trap facility.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_TR
value|(0x100000)
end_define

begin_define
define|#
directive|define
name|I370_OPCODE_ESA390_SUPERSET
value|(0x1fffff)
end_define

begin_escape
end_escape

begin_comment
comment|/* The operands table is an array of struct i370_operand.  */
end_comment

begin_struct
struct|struct
name|i370_operand
block|{
comment|/* The number of bits in the operand.  */
name|int
name|bits
decl_stmt|;
comment|/* How far the operand is left shifted in the instruction.  */
name|int
name|shift
decl_stmt|;
comment|/* Insertion function.  This is used by the assembler.  To insert an      operand value into an instruction, check this field.       If it is NULL, execute          i |= (op& ((1<< o->bits) - 1))<< o->shift;      (i is the instruction which we are filling in, o is a pointer to      this structure, and op is the opcode value; this assumes twos      complement arithmetic).       If this field is not NULL, then simply call it with the      instruction and the operand value.  It will return the new value      of the instruction.  If the ERRMSG argument is not NULL, then if      the operand value is illegal, *ERRMSG will be set to a warning      string (the operand will be inserted in any case).  If the      operand value is legal, *ERRMSG will be unchanged (most operands      can accept any value).  */
name|i370_insn_t
function_decl|(
modifier|*
name|insert
function_decl|)
parameter_list|(
name|i370_insn_t
name|instruction
parameter_list|,
name|long
name|op
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|errmsg
parameter_list|)
function_decl|;
comment|/* Extraction function.  This is used by the disassembler.  To      extract this operand type from an instruction, check this field.       If it is NULL, compute          op = ((i)>> o->shift)& ((1<< o->bits) - 1); 	 if ((o->flags& I370_OPERAND_SIGNED) != 0&& (op& (1<< (o->bits - 1))) != 0) 	   op -= 1<< o->bits;      (i is the instruction, o is a pointer to this structure, and op      is the result; this assumes twos complement arithmetic).       If this field is not NULL, then simply call it with the      instruction value.  It will return the value of the operand.  If      the INVALID argument is not NULL, *INVALID will be set to      non-zero if this operand type can not actually be extracted from      this operand (i.e., the instruction does not match).  If the      operand is valid, *INVALID will not be changed.  */
name|long
function_decl|(
modifier|*
name|extract
function_decl|)
parameter_list|(
name|i370_insn_t
name|instruction
parameter_list|,
name|int
modifier|*
name|invalid
parameter_list|)
function_decl|;
comment|/* One bit syntax flags.  */
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* name -- handy for debugging, otherwise pointless */
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Elements in the table are retrieved by indexing with values from    the operands field of the i370_opcodes table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|i370_operand
name|i370_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct i370_operand.  */
end_comment

begin_comment
comment|/* This operand should be wrapped in parentheses rather than    separated from the previous by a comma.  This is used for S, RS and    SS form instructions which want their operands to look like    reg,displacement(basereg) */
end_comment

begin_define
define|#
directive|define
name|I370_OPERAND_SBASE
value|(0x01)
end_define

begin_comment
comment|/* This operand is a base register.  It may or may not appear next    to an index register, i.e. either of the two forms    reg,displacement(basereg)    reg,displacement(index,basereg) */
end_comment

begin_define
define|#
directive|define
name|I370_OPERAND_BASE
value|(0x02)
end_define

begin_comment
comment|/* This pair of operands should be wrapped in parentheses rather than    separated from the last by a comma.  This is used for the RX form    instructions which want their operands to look like    reg,displacement(index,basereg) */
end_comment

begin_define
define|#
directive|define
name|I370_OPERAND_INDEX
value|(0x04)
end_define

begin_comment
comment|/* This operand names a register.  The disassembler uses this to print    register names with a leading 'r'.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPERAND_GPR
value|(0x08)
end_define

begin_comment
comment|/* This operand names a floating point register.  The disassembler    prints these with a leading 'f'.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPERAND_FPR
value|(0x10)
end_define

begin_comment
comment|/* This operand is a displacement.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPERAND_RELATIVE
value|(0x20)
end_define

begin_comment
comment|/* This operand is a length, such as that in SS form instructions.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPERAND_LENGTH
value|(0x40)
end_define

begin_comment
comment|/* This operand is optional, and is zero if omitted.  This is used for    the optional B2 field in the shift-left, shift-right instructions.  The    assembler must count the number of operands remaining on the line,    and the number of operands remaining for the opcode, and decide    whether this operand is present or not.  The disassembler should    print this operand out only if it is not zero.  */
end_comment

begin_define
define|#
directive|define
name|I370_OPERAND_OPTIONAL
value|(0x80)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define some misc macros.  We keep them with the operands table    for simplicity.  The macro table is an array of struct i370_macro.  */
end_comment

begin_struct
struct|struct
name|i370_macro
block|{
comment|/* The macro name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The number of operands the macro takes.  */
name|unsigned
name|int
name|operands
decl_stmt|;
comment|/* One bit flags for the opcode.  These are used to indicate which      specific processors support the instructions.  The values are the      same as those for the struct i370_opcode flags field.  */
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* A format string to turn the macro into a normal instruction.      Each %N in the string is replaced with operand number N (zero      based).  */
specifier|const
name|char
modifier|*
name|format
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|i370_macro
name|i370_macros
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|i370_num_macros
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I370_H */
end_comment

end_unit


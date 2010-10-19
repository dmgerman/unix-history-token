begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tic80.h -- Header file for TI TMS320C80 (MV) opcode table    Copyright 1996, 1997, 2003 Free Software Foundation, Inc.    Written by Fred Fish (fnf@cygnus.com), Cygnus Support  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIC80_H
end_ifndef

begin_define
define|#
directive|define
name|TIC80_H
end_define

begin_comment
comment|/* The opcode table is an array of struct tic80_opcode.  */
end_comment

begin_struct
struct|struct
name|tic80_opcode
block|{
comment|/* The opcode name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The opcode itself.  Those bits which will be filled in with operands      are zeroes.  */
name|unsigned
name|long
name|opcode
decl_stmt|;
comment|/* The opcode mask.  This is used by the disassembler.  This is a mask      containing ones indicating those bits which must match the opcode      field, and zeroes indicating those bits which need not match (and are      presumably filled in by operands).  */
name|unsigned
name|long
name|mask
decl_stmt|;
comment|/* Special purpose flags for this opcode. */
name|unsigned
name|char
name|flags
decl_stmt|;
comment|/* An array of operand codes.  Each code is an index into the operand      table.  They appear in the order which the operands must appear in      assembly code, and are terminated by a zero.  FIXME: Adjust size to      match actual requirements when TIc80 support is complete */
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
comment|/* The table itself is sorted by major opcode number, and is otherwise in    the order in which the disassembler should consider instructions.    FIXME: This isn't currently true. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tic80_opcode
name|tic80_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|tic80_num_opcodes
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The operands table is an array of struct tic80_operand.  */
end_comment

begin_struct
struct|struct
name|tic80_operand
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
name|unsigned
name|long
function_decl|(
modifier|*
name|insert
function_decl|)
parameter_list|(
name|unsigned
name|long
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
comment|/* Extraction function.  This is used by the disassembler.  To      extract this operand type from an instruction, check this field.       If it is NULL, compute          op = ((i)>> o->shift)& ((1<< o->bits) - 1); 	 if ((o->flags& TIC80_OPERAND_SIGNED) != 0&& (op& (1<< (o->bits - 1))) != 0) 	   op -= 1<< o->bits;      (i is the instruction, o is a pointer to this structure, and op      is the result; this assumes twos complement arithmetic).       If this field is not NULL, then simply call it with the      instruction value.  It will return the value of the operand.  If      the INVALID argument is not NULL, *INVALID will be set to      non-zero if this operand type can not actually be extracted from      this operand (i.e., the instruction does not match).  If the      operand is valid, *INVALID will not be changed.  */
name|long
function_decl|(
modifier|*
name|extract
function_decl|)
parameter_list|(
name|unsigned
name|long
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
block|}
struct|;
end_struct

begin_comment
comment|/* Elements in the table are retrieved by indexing with values from    the operands field of the tic80_opcodes table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tic80_operand
name|tic80_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Values defined for the flags field of a struct tic80_operand.     Note that flags for all predefined symbols, such as the general purpose    registers (ex: r10), control registers (ex: FPST), condition codes (ex:    eq0.b), bit numbers (ex: gt.b), etc are large enough that they can be    or'd into an int where the lower bits contain the actual numeric value    that correponds to this predefined symbol.  This way a single int can    contain both the value of the symbol and it's type.  */
end_comment

begin_comment
comment|/* This operand must be an even register number.  Floating point numbers    for example are stored in even/odd register pairs. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_EVEN
value|(1<< 0)
end_define

begin_comment
comment|/* This operand must be an odd register number and must be one greater than    the register number of the previous operand.  I.E. the second register in    an even/odd register pair. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_ODD
value|(1<< 1)
end_define

begin_comment
comment|/* This operand takes signed values.  */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_SIGNED
value|(1<< 2)
end_define

begin_comment
comment|/* This operand may be either a predefined constant name or a numeric value.    An example would be a condition code like "eq0.b" which has the numeric    value 0x2. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_NUM
value|(1<< 3)
end_define

begin_comment
comment|/* This operand should be wrapped in parentheses rather than separated    from the previous one by a comma.  This is used for various    instructions, like the load and store instructions, which want    their operands to look like "displacement(reg)" */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_PARENS
value|(1<< 4)
end_define

begin_comment
comment|/* This operand is a PC relative branch offset.  The disassembler prints    these symbolically if possible.  Note that the offsets are taken as word    offsets. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_PCREL
value|(1<< 5)
end_define

begin_comment
comment|/* This flag is a hint to the disassembler for using hex as the prefered    printing format, even for small positive or negative immediate values.    Normally values in the range -999 to 999 are printed as signed decimal    values and other values are printed in hex. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_BITFIELD
value|(1<< 6)
end_define

begin_comment
comment|/* This operand may have a ":m" modifier specified by bit 17 in a short    immediate form instruction. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_M_SI
value|(1<< 7)
end_define

begin_comment
comment|/* This operand may have a ":m" modifier specified by bit 15 in a long    immediate or register form instruction. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_M_LI
value|(1<< 8)
end_define

begin_comment
comment|/* This operand may have a ":s" modifier specified in bit 11 in a long    immediate or register form instruction. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_SCALED
value|(1<< 9)
end_define

begin_comment
comment|/* This operand is a floating point value */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_FLOAT
value|(1<< 10)
end_define

begin_comment
comment|/* This operand is an byte offset from a base relocation. The lower  two bits of the final relocated address are ignored when the value is  written to the program counter. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_BASEREL
value|(1<< 11)
end_define

begin_comment
comment|/* This operand is an "endmask" field for a shift instruction.    It is treated special in that it can have values of 0-32,    where 0 and 32 result in the same instruction.  The assembler    must be able to accept both endmask values.  This disassembler    has no way of knowing from the instruction which value was     given at assembly time, so it just uses '0'. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_ENDMASK
value|(1<< 12)
end_define

begin_comment
comment|/* This operand is one of the 32 general purpose registers.    The disassembler prints these with a leading 'r'. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_GPR
value|(1<< 27)
end_define

begin_comment
comment|/* This operand is a floating point accumulator register.    The disassembler prints these with a leading 'a'. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_FPA
value|( 1<< 28)
end_define

begin_comment
comment|/* This operand is a control register number, either numeric or    symbolic (like "EIF", "EPC", etc).    The disassembler prints these symbolically. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_CR
value|(1<< 29)
end_define

begin_comment
comment|/* This operand is a condition code, either numeric or    symbolic (like "eq0.b", "ne0.w", etc).    The disassembler prints these symbolically. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_CC
value|(1<< 30)
end_define

begin_comment
comment|/* This operand is a bit number, either numeric or    symbolic (like "eq.b", "or.f", etc).    The disassembler prints these symbolically.    Note that they appear in the instruction in 1's complement relative    to the values given in the manual. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_BITNUM
value|(1<< 31)
end_define

begin_comment
comment|/* This mask is used to strip operand bits from an int that contains    both operand bits and a numeric value in the lsbs. */
end_comment

begin_define
define|#
directive|define
name|TIC80_OPERAND_MASK
value|(TIC80_OPERAND_GPR | TIC80_OPERAND_FPA | TIC80_OPERAND_CR | TIC80_OPERAND_CC | TIC80_OPERAND_BITNUM)
end_define

begin_escape
end_escape

begin_comment
comment|/* Flag bits for the struct tic80_opcode flags field. */
end_comment

begin_define
define|#
directive|define
name|TIC80_VECTOR
value|01
end_define

begin_comment
comment|/* Is a vector instruction */
end_comment

begin_define
define|#
directive|define
name|TIC80_NO_R0_DEST
value|02
end_define

begin_comment
comment|/* Register r0 cannot be a destination register */
end_comment

begin_escape
end_escape

begin_comment
comment|/* The opcodes library contains a table that allows translation from predefined    symbol names to numeric values, and vice versa. */
end_comment

begin_comment
comment|/* Structure to hold information about predefined symbols.  */
end_comment

begin_struct
struct|struct
name|predefined_symbol
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name to recognize */
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PDS_NAME
parameter_list|(
name|pdsp
parameter_list|)
value|((pdsp) -> name)
end_define

begin_define
define|#
directive|define
name|PDS_VALUE
parameter_list|(
name|pdsp
parameter_list|)
value|((pdsp) -> value)
end_define

begin_comment
comment|/* Translation array.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|predefined_symbol
name|tic80_predefined_symbols
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* How many members in the array.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|tic80_num_predefined_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate value to symbolic name.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|tic80_value_to_symbol
parameter_list|(
name|int
name|val
parameter_list|,
name|int
name|class
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Translate symbolic name to value.  */
end_comment

begin_function_decl
name|int
name|tic80_symbol_to_value
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|predefined_symbol
modifier|*
name|tic80_next_predefined_symbol
parameter_list|(
specifier|const
name|struct
name|predefined_symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIC80_H */
end_comment

end_unit


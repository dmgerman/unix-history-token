begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ppc.h -- Header file for PowerPC opcode table    Copyright 1994, 1995, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Support  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PPC_H
end_ifndef

begin_define
define|#
directive|define
name|PPC_H
end_define

begin_comment
comment|/* The opcode table is an array of struct powerpc_opcode.  */
end_comment

begin_struct
struct|struct
name|powerpc_opcode
block|{
comment|/* The opcode name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The opcode itself.  Those bits which will be filled in with      operands are zeroes.  */
name|unsigned
name|long
name|opcode
decl_stmt|;
comment|/* The opcode mask.  This is used by the disassembler.  This is a      mask containing ones indicating those bits which must match the      opcode field, and zeroes indicating those bits which need not      match (and are presumably filled in by operands).  */
name|unsigned
name|long
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
name|powerpc_opcode
name|powerpc_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|powerpc_num_opcodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct powerpc_opcode.  */
end_comment

begin_comment
comment|/* Opcode is defined for the PowerPC architecture.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_PPC
value|(01)
end_define

begin_comment
comment|/* Opcode is defined for the POWER (RS/6000) architecture.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_POWER
value|(02)
end_define

begin_comment
comment|/* Opcode is defined for the POWER2 (Rios 2) architecture.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_POWER2
value|(04)
end_define

begin_comment
comment|/* Opcode is only defined on 32 bit architectures.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_32
value|(010)
end_define

begin_comment
comment|/* Opcode is only defined on 64 bit architectures.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_64
value|(020)
end_define

begin_comment
comment|/* Opcode is supported by the Motorola PowerPC 601 processor.  The 601    is assumed to support all PowerPC (PPC_OPCODE_PPC) instructions,    but it also supports many additional POWER instructions.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_601
value|(040)
end_define

begin_comment
comment|/* Opcode is supported in both the Power and PowerPC architectures    (ie, compiler's -mcpu=common or assembler's -mcom).  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_COMMON
value|(0100)
end_define

begin_comment
comment|/* Opcode is supported for any Power or PowerPC platform (this is    for the assembler's -many option, and it eliminates duplicates).  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_ANY
value|(0200)
end_define

begin_comment
comment|/* Opcode is supported as part of the 64-bit bridge.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_64_BRIDGE
value|(0400)
end_define

begin_comment
comment|/* Opcode is supported by Altivec Vector Unit */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_ALTIVEC
value|(01000)
end_define

begin_comment
comment|/* Opcode is supported by PowerPC 403 processor.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_403
value|(02000)
end_define

begin_comment
comment|/* Opcode is supported by PowerPC BookE processor.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_BOOKE
value|(04000)
end_define

begin_comment
comment|/* Opcode is only supported by 64-bit PowerPC BookE processor.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_BOOKE64
value|(010000)
end_define

begin_comment
comment|/* Opcode is only supported by Power4 architecture.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_POWER4
value|(020000)
end_define

begin_comment
comment|/* Opcode isn't supported by Power4 architecture.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPCODE_NOPOWER4
value|(040000)
end_define

begin_comment
comment|/* A macro to extract the major opcode from an instruction.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OP
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 26)& 0x3f)
end_define

begin_escape
end_escape

begin_comment
comment|/* The operands table is an array of struct powerpc_operand.  */
end_comment

begin_struct
struct|struct
name|powerpc_operand
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
argument_list|(
operator|*
name|insert
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|long
name|instruction
operator|,
name|long
name|op
operator|,
name|int
name|dialect
operator|,
specifier|const
name|char
operator|*
operator|*
name|errmsg
operator|)
argument_list|)
decl_stmt|;
comment|/* Extraction function.  This is used by the disassembler.  To      extract this operand type from an instruction, check this field.       If it is NULL, compute          op = ((i)>> o->shift)& ((1<< o->bits) - 1); 	 if ((o->flags& PPC_OPERAND_SIGNED) != 0&& (op& (1<< (o->bits - 1))) != 0) 	   op -= 1<< o->bits;      (i is the instruction, o is a pointer to this structure, and op      is the result; this assumes twos complement arithmetic).       If this field is not NULL, then simply call it with the      instruction value.  It will return the value of the operand.  If      the INVALID argument is not NULL, *INVALID will be set to      non-zero if this operand type can not actually be extracted from      this operand (i.e., the instruction does not match).  If the      operand is valid, *INVALID will not be changed.  */
name|long
argument_list|(
argument|*extract
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|long
name|instruction
operator|,
name|int
name|dialect
operator|,
name|int
operator|*
name|invalid
operator|)
argument_list|)
expr_stmt|;
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
name|powerpc_operand
name|powerpc_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct powerpc_operand.  */
end_comment

begin_comment
comment|/* This operand takes signed values.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_SIGNED
value|(01)
end_define

begin_comment
comment|/* This operand takes signed values, but also accepts a full positive    range of values when running in 32 bit mode.  That is, if bits is    16, it takes any value from -0x8000 to 0xffff.  In 64 bit mode,    this flag is ignored.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_SIGNOPT
value|(02)
end_define

begin_comment
comment|/* This operand does not actually exist in the assembler input.  This    is used to support extended mnemonics such as mr, for which two    operands fields are identical.  The assembler should call the    insert function with any op value.  The disassembler should call    the extract function, ignore the return value, and check the value    placed in the valid argument.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_FAKE
value|(04)
end_define

begin_comment
comment|/* The next operand should be wrapped in parentheses rather than    separated from this one by a comma.  This is used for the load and    store instructions which want their operands to look like        reg,displacement(reg)    */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_PARENS
value|(010)
end_define

begin_comment
comment|/* This operand may use the symbolic names for the CR fields, which    are        lt  0	gt  1	eq  2	so  3	un  3        cr0 0	cr1 1	cr2 2	cr3 3        cr4 4	cr5 5	cr6 6	cr7 7    These may be combined arithmetically, as in cr2*4+gt.  These are    only supported on the PowerPC, not the POWER.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_CR
value|(020)
end_define

begin_comment
comment|/* This operand names a register.  The disassembler uses this to print    register names with a leading 'r'.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_GPR
value|(040)
end_define

begin_comment
comment|/* This operand names a floating point register.  The disassembler    prints these with a leading 'f'.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_FPR
value|(0100)
end_define

begin_comment
comment|/* This operand is a relative branch displacement.  The disassembler    prints these symbolically if possible.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_RELATIVE
value|(0200)
end_define

begin_comment
comment|/* This operand is an absolute branch address.  The disassembler    prints these symbolically if possible.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_ABSOLUTE
value|(0400)
end_define

begin_comment
comment|/* This operand is optional, and is zero if omitted.  This is used for    the optional BF and L fields in the comparison instructions.  The    assembler must count the number of operands remaining on the line,    and the number of operands remaining for the opcode, and decide    whether this operand is present or not.  The disassembler should    print this operand out only if it is not zero.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_OPTIONAL
value|(01000)
end_define

begin_comment
comment|/* This flag is only used with PPC_OPERAND_OPTIONAL.  If this operand    is omitted, then for the next operand use this operand value plus    1, ignoring the next operand field for the opcode.  This wretched    hack is needed because the Power rotate instructions can take    either 4 or 5 operands.  The disassembler should print this operand    out regardless of the PPC_OPERAND_OPTIONAL field.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_NEXT
value|(02000)
end_define

begin_comment
comment|/* This operand should be regarded as a negative number for the    purposes of overflow checking (i.e., the normal most negative    number is disallowed and one more than the normal most positive    number is allowed).  This flag will only be set for a signed    operand.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_NEGATIVE
value|(04000)
end_define

begin_comment
comment|/* This operand names a vector unit register.  The disassembler    prints these with a leading 'v'.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_VR
value|(010000)
end_define

begin_comment
comment|/* This operand is for the DS field in a DS form instruction.  */
end_comment

begin_define
define|#
directive|define
name|PPC_OPERAND_DS
value|(020000)
end_define

begin_escape
end_escape

begin_comment
comment|/* The POWER and PowerPC assemblers use a few macros.  We keep them    with the operands table for simplicity.  The macro table is an    array of struct powerpc_macro.  */
end_comment

begin_struct
struct|struct
name|powerpc_macro
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
comment|/* One bit flags for the opcode.  These are used to indicate which      specific processors support the instructions.  The values are the      same as those for the struct powerpc_opcode flags field.  */
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
name|powerpc_macro
name|powerpc_macros
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|powerpc_num_macros
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PPC_H */
end_comment

end_unit


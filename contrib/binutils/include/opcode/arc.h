begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Opcode table for the ARC.    Copyright 1994, 1995, 1997 Free Software Foundation, Inc.    Contributed by Doug Evans (dje@cygnus.com).  This file is part of GAS, the GNU Assembler, GDB, the GNU debugger, and the GNU Binutils.  GAS/GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GAS/GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS or GDB; see the file COPYING.	If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* List of the various cpu types.    The tables currently use bit masks to say whether the instruction or    whatever is supported by a particular cpu.  This lets us have one entry    apply to several cpus.     This duplicates bfd_mach_arc_xxx.  For now I wish to isolate this from bfd    and bfd from this.  Also note that these numbers are bit values as we want    to allow for things available on more than one ARC (but not necessarily all    ARCs).  */
end_comment

begin_comment
comment|/* The `base' cpu must be 0 (table entries are omitted for the base cpu).    The cpu type is treated independently of endianness.    The complete `mach' number includes endianness.    These values are internal to opcodes/bfd/binutils/gas.  */
end_comment

begin_define
define|#
directive|define
name|ARC_MACH_BASE
value|0
end_define

begin_define
define|#
directive|define
name|ARC_MACH_UNUSED1
value|1
end_define

begin_define
define|#
directive|define
name|ARC_MACH_UNUSED2
value|2
end_define

begin_define
define|#
directive|define
name|ARC_MACH_UNUSED4
value|4
end_define

begin_comment
comment|/* Additional cpu values can be inserted here and ARC_MACH_BIG moved down.  */
end_comment

begin_define
define|#
directive|define
name|ARC_MACH_BIG
value|8
end_define

begin_comment
comment|/* Mask of number of bits necessary to record cpu type.  */
end_comment

begin_define
define|#
directive|define
name|ARC_MACH_CPU_MASK
value|7
end_define

begin_comment
comment|/* Mask of number of bits necessary to record cpu type + endianness.  */
end_comment

begin_define
define|#
directive|define
name|ARC_MACH_MASK
value|15
end_define

begin_comment
comment|/* Type to denote an ARC instruction (at least a 32 bit unsigned int).  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|arc_insn
typedef|;
end_typedef

begin_struct
struct|struct
name|arc_opcode
block|{
name|char
modifier|*
name|syntax
decl_stmt|;
comment|/* syntax of insn */
name|unsigned
name|long
name|mask
decl_stmt|,
name|value
decl_stmt|;
comment|/* recognize insn if (op&mask)==value */
name|int
name|flags
decl_stmt|;
comment|/* various flag bits */
comment|/* Values for `flags'.  */
comment|/* Return CPU number, given flag bits.  */
define|#
directive|define
name|ARC_OPCODE_CPU
parameter_list|(
name|bits
parameter_list|)
value|((bits)& ARC_MACH_CPU_MASK)
comment|/* Return MACH number, given flag bits.  */
define|#
directive|define
name|ARC_OPCODE_MACH
parameter_list|(
name|bits
parameter_list|)
value|((bits)& ARC_MACH_MASK)
comment|/* First opcode flag bit available after machine mask.  */
define|#
directive|define
name|ARC_OPCODE_FLAG_START
value|((ARC_MACH_MASK + 1)<< 0)
comment|/* This insn is a conditional branch.  */
define|#
directive|define
name|ARC_OPCODE_COND_BRANCH
value|(ARC_OPCODE_FLAG_START)
comment|/* These values are used to optimize assembly and disassembly.  Each insn is      on a list of related insns (same first letter for assembly, same insn code      for disassembly).  */
name|struct
name|arc_opcode
modifier|*
name|next_asm
decl_stmt|;
comment|/* Next instruction to try during assembly.  */
name|struct
name|arc_opcode
modifier|*
name|next_dis
decl_stmt|;
comment|/* Next instruction to try during disassembly.  */
comment|/* Macros to create the hash values for the lists.  */
define|#
directive|define
name|ARC_HASH_OPCODE
parameter_list|(
name|string
parameter_list|)
define|\
value|((string)[0]>= 'a'&& (string)[0]<= 'z' ? (string)[0] - 'a' : 26)
define|#
directive|define
name|ARC_HASH_ICODE
parameter_list|(
name|insn
parameter_list|)
define|\
value|((unsigned int) (insn)>> 27)
comment|/* Macros to access `next_asm', `next_dis' so users needn't care about the      underlying mechanism.  */
define|#
directive|define
name|ARC_OPCODE_NEXT_ASM
parameter_list|(
name|op
parameter_list|)
value|((op)->next_asm)
define|#
directive|define
name|ARC_OPCODE_NEXT_DIS
parameter_list|(
name|op
parameter_list|)
value|((op)->next_dis)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arc_operand_value
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* eg: "eq" */
name|short
name|value
decl_stmt|;
comment|/* eg: 1 */
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* index into `arc_operands' */
name|unsigned
name|char
name|flags
decl_stmt|;
comment|/* various flag bits */
comment|/* Values for `flags'.  */
comment|/* Return CPU number, given flag bits.  */
define|#
directive|define
name|ARC_OPVAL_CPU
parameter_list|(
name|bits
parameter_list|)
value|((bits)& ARC_MACH_CPU_MASK)
comment|/* Return MACH number, given flag bits.  */
define|#
directive|define
name|ARC_OPVAL_MACH
parameter_list|(
name|bits
parameter_list|)
value|((bits)& ARC_MACH_MASK)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arc_operand
block|{
comment|/* One of the insn format chars.  */
name|unsigned
name|char
name|fmt
decl_stmt|;
comment|/* The number of bits in the operand (may be unused for a modifier).  */
name|unsigned
name|char
name|bits
decl_stmt|;
comment|/* How far the operand is left shifted in the instruction, or      the modifier's flag bit (may be unused for a modifier.  */
name|unsigned
name|char
name|shift
decl_stmt|;
comment|/* Various flag bits.  */
name|int
name|flags
decl_stmt|;
comment|/* Values for `flags'.  */
comment|/* This operand is a suffix to the opcode.  */
define|#
directive|define
name|ARC_OPERAND_SUFFIX
value|1
comment|/* This operand is a relative branch displacement.  The disassembler    prints these symbolically if possible.  */
define|#
directive|define
name|ARC_OPERAND_RELATIVE_BRANCH
value|2
comment|/* This operand is an absolute branch address.  The disassembler    prints these symbolically if possible.  */
define|#
directive|define
name|ARC_OPERAND_ABSOLUTE_BRANCH
value|4
comment|/* This operand is an address.  The disassembler    prints these symbolically if possible.  */
define|#
directive|define
name|ARC_OPERAND_ADDRESS
value|8
comment|/* This operand is a long immediate value.  */
define|#
directive|define
name|ARC_OPERAND_LIMM
value|0x10
comment|/* This operand takes signed values.  */
define|#
directive|define
name|ARC_OPERAND_SIGNED
value|0x20
comment|/* This operand takes signed values, but also accepts a full positive    range of values.  That is, if bits is 16, it takes any value from    -0x8000 to 0xffff.  */
define|#
directive|define
name|ARC_OPERAND_SIGNOPT
value|0x40
comment|/* This operand should be regarded as a negative number for the    purposes of overflow checking (i.e., the normal most negative    number is disallowed and one more than the normal most positive    number is allowed).  This flag will only be set for a signed    operand.  */
define|#
directive|define
name|ARC_OPERAND_NEGATIVE
value|0x80
comment|/* This operand doesn't really exist.  The program uses these operands    in special ways.  */
define|#
directive|define
name|ARC_OPERAND_FAKE
value|0x100
comment|/* Modifier values.  */
comment|/* A dot is required before a suffix.  Eg: .le  */
define|#
directive|define
name|ARC_MOD_DOT
value|0x1000
comment|/* A normal register is allowed (not used, but here for completeness).  */
define|#
directive|define
name|ARC_MOD_REG
value|0x2000
comment|/* An auxiliary register name is expected.  */
define|#
directive|define
name|ARC_MOD_AUXREG
value|0x4000
comment|/* Sum of all ARC_MOD_XXX bits.  */
define|#
directive|define
name|ARC_MOD_BITS
value|0x7000
comment|/* Non-zero if the operand type is really a modifier.  */
define|#
directive|define
name|ARC_MOD_P
parameter_list|(
name|X
parameter_list|)
value|((X)& ARC_MOD_BITS)
comment|/* Insertion function.  This is used by the assembler.  To insert an      operand value into an instruction, check this field.       If it is NULL, execute          i |= (p& ((1<< o->bits) - 1))<< o->shift;      (I is the instruction which we are filling in, O is a pointer to      this structure, and OP is the opcode value; this assumes twos      complement arithmetic).       If this field is not NULL, then simply call it with the      instruction and the operand value.  It will return the new value      of the instruction.  If the ERRMSG argument is not NULL, then if      the operand value is illegal, *ERRMSG will be set to a warning      string (the operand will be inserted in any case).  If the      operand value is legal, *ERRMSG will be unchanged.       REG is non-NULL when inserting a register value.  */
name|arc_insn
argument_list|(
argument|*insert
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|arc_insn
name|insn
operator|,
specifier|const
expr|struct
name|arc_operand
operator|*
name|operand
operator|,
name|int
name|mods
operator|,
specifier|const
expr|struct
name|arc_operand_value
operator|*
name|reg
operator|,
name|long
name|value
operator|,
specifier|const
name|char
operator|*
operator|*
name|errmsg
operator|)
argument_list|)
expr_stmt|;
comment|/* Extraction function.  This is used by the disassembler.  To      extract this operand type from an instruction, check this field.       If it is NULL, compute          op = ((i)>> o->shift)& ((1<< o->bits) - 1); 	 if ((o->flags& ARC_OPERAND_SIGNED) != 0&& (op& (1<< (o->bits - 1))) != 0) 	   op -= 1<< o->bits;      (I is the instruction, O is a pointer to this structure, and OP      is the result; this assumes twos complement arithmetic).       If this field is not NULL, then simply call it with the      instruction value.  It will return the value of the operand.  If      the INVALID argument is not NULL, *INVALID will be set to      non-zero if this operand type can not actually be extracted from      this operand (i.e., the instruction does not match).  If the      operand is valid, *INVALID will not be changed.       INSN is a pointer to an array of two `arc_insn's.  The first element is      the insn, the second is the limm if present.       Operands that have a printable form like registers and suffixes have      their struct arc_operand_value pointer stored in OPVAL.  */
name|long
argument_list|(
argument|*extract
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|arc_insn
operator|*
name|insn
operator|,
specifier|const
expr|struct
name|arc_operand
operator|*
name|operand
operator|,
name|int
name|mods
operator|,
specifier|const
expr|struct
name|arc_operand_value
operator|*
operator|*
name|opval
operator|,
name|int
operator|*
name|invalid
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Bits that say what version of cpu we have.    These should be passed to arc_init_opcode_tables.    At present, all there is is the cpu type.  */
end_comment

begin_comment
comment|/* CPU number, given value passed to `arc_init_opcode_tables'.  */
end_comment

begin_define
define|#
directive|define
name|ARC_HAVE_CPU
parameter_list|(
name|bits
parameter_list|)
value|((bits)& ARC_MACH_CPU_MASK)
end_define

begin_comment
comment|/* MACH number, given value passed to `arc_init_opcode_tables'.  */
end_comment

begin_define
define|#
directive|define
name|ARC_HAVE_MACH
parameter_list|(
name|bits
parameter_list|)
value|((bits)& ARC_MACH_MASK)
end_define

begin_comment
comment|/* Special register values:  */
end_comment

begin_define
define|#
directive|define
name|ARC_REG_SHIMM_UPDATE
value|61
end_define

begin_define
define|#
directive|define
name|ARC_REG_SHIMM
value|63
end_define

begin_define
define|#
directive|define
name|ARC_REG_LIMM
value|62
end_define

begin_comment
comment|/* Non-zero if REG is a constant marker.  */
end_comment

begin_define
define|#
directive|define
name|ARC_REG_CONSTANT_P
parameter_list|(
name|REG
parameter_list|)
value|((REG)>= 61)
end_define

begin_comment
comment|/* Positions and masks of various fields:  */
end_comment

begin_define
define|#
directive|define
name|ARC_SHIFT_REGA
value|21
end_define

begin_define
define|#
directive|define
name|ARC_SHIFT_REGB
value|15
end_define

begin_define
define|#
directive|define
name|ARC_SHIFT_REGC
value|9
end_define

begin_define
define|#
directive|define
name|ARC_MASK_REG
value|63
end_define

begin_comment
comment|/* Delay slot types.  */
end_comment

begin_define
define|#
directive|define
name|ARC_DELAY_NONE
value|0
end_define

begin_comment
comment|/* no delay slot */
end_comment

begin_define
define|#
directive|define
name|ARC_DELAY_NORMAL
value|1
end_define

begin_comment
comment|/* delay slot in both cases */
end_comment

begin_define
define|#
directive|define
name|ARC_DELAY_JUMP
value|2
end_define

begin_comment
comment|/* delay slot only if branch taken */
end_comment

begin_comment
comment|/* Non-zero if X will fit in a signed 9 bit field.  */
end_comment

begin_define
define|#
directive|define
name|ARC_SHIMM_CONST_P
parameter_list|(
name|x
parameter_list|)
value|((long) (x)>= -256&& (long) (x)<= 255)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|arc_operand
name|arc_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|arc_operand_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
comment|/*const*/
name|struct
name|arc_opcode
name|arc_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|arc_opcodes_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|arc_operand_value
name|arc_suffixes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|arc_suffixes_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|arc_operand_value
name|arc_reg_names
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|arc_reg_names_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|arc_operand_map
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Utility fns in arc-opc.c.  */
end_comment

begin_decl_stmt
name|int
name|arc_get_opcode_mach
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* `arc_opcode_init_tables' must be called before `arc_xxx_supported'.  */
end_comment

begin_decl_stmt
name|void
name|arc_opcode_init_tables
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|arc_opcode_init_insert
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|arc_opcode_init_extract
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|arc_opcode
modifier|*
name|arc_opcode_lookup_asm
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|arc_opcode
modifier|*
name|arc_opcode_lookup_dis
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arc_opcode_limm_p
name|PARAMS
argument_list|(
operator|(
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|arc_operand_value
modifier|*
name|arc_opcode_lookup_suffix
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|arc_operand
operator|*
name|type
operator|,
name|int
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arc_opcode_supported
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|arc_opcode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arc_opval_supported
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|arc_operand_value
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit


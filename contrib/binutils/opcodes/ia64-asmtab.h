begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ia64-asmtab.h -- Header for compacted IA-64 opcode tables.    Copyright 1999, 2000 Free Software Foundation, Inc.    Contributed by Bob Manson of Cygnus Support<manson@cygnus.com>     This file is part of GDB, GAS, and the GNU binutils.     GDB, GAS, and the GNU binutils are free software; you can redistribute    them and/or modify them under the terms of the GNU General Public    License as published by the Free Software Foundation; either version    2, or (at your option) any later version.     GDB, GAS, and the GNU binutils are distributed in the hope that they    will be useful, but WITHOUT ANY WARRANTY; without even the implied    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this file; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IA64_ASMTAB_H
end_ifndef

begin_define
define|#
directive|define
name|IA64_ASMTAB_H
end_define

begin_include
include|#
directive|include
file|"opcode/ia64.h"
end_include

begin_comment
comment|/* The primary opcode table is made up of the following: */
end_comment

begin_struct
struct|struct
name|ia64_main_table
block|{
comment|/* The entry in the string table that corresponds to the name of this      opcode. */
name|unsigned
name|short
name|name_index
decl_stmt|;
comment|/* The type of opcode; corresponds to the TYPE field in       struct ia64_opcode. */
name|unsigned
name|char
name|opcode_type
decl_stmt|;
comment|/* The number of outputs for this opcode. */
name|unsigned
name|char
name|num_outputs
decl_stmt|;
comment|/* The base insn value for this opcode.  It may be modified by completers. */
name|ia64_insn
name|opcode
decl_stmt|;
comment|/* The mask of valid bits in OPCODE. Zeros indicate operand fields. */
name|ia64_insn
name|mask
decl_stmt|;
comment|/* The operands of this instruction.  Corresponds to the OPERANDS field      in struct ia64_opcode. */
name|unsigned
name|char
name|operands
index|[
literal|5
index|]
decl_stmt|;
comment|/* The flags for this instruction.  Corresponds to the FLAGS field in      struct ia64_opcode. */
name|short
name|flags
decl_stmt|;
comment|/* The tree of completers for this instruction; this is an offset into      completer_table. */
name|short
name|completers
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Each instruction has a set of possible "completers", or additional    suffixes that can alter the instruction's behavior, and which has    potentially different dependencies.     The completer entries modify certain bits in the instruction opcode.    Which bits are to be modified are marked by the BITS, MASK and    OFFSET fields.  The completer entry may also note dependencies for the    opcode.      These completers are arranged in a DAG; the pointers are indexes    into the completer_table array.  The completer DAG is searched by    find_completer () and ia64_find_matching_opcode ().     Note that each completer needs to be applied in turn, so that if we    have the instruction    	cmp.lt.unc    the completer entries for both "lt" and "unc" would need to be applied    to the opcode's value.     Some instructions do not require any completers; these contain an    empty completer entry.  Instructions that require a completer do    not contain an empty entry.     Terminal completers (those completers that validly complete an    instruction) are marked by having the TERMINAL_COMPLETER flag set.      Only dependencies listed in the terminal completer for an opcode are    considered to apply to that opcode instance. */
end_comment

begin_struct
struct|struct
name|ia64_completer_table
block|{
comment|/* The bit value that this completer sets. */
name|unsigned
name|int
name|bits
decl_stmt|;
comment|/* And its mask. 1s are bits that are to be modified in the       instruction. */
name|unsigned
name|int
name|mask
decl_stmt|;
comment|/* The entry in the string table that corresponds to the name of this      completer. */
name|unsigned
name|short
name|name_index
decl_stmt|;
comment|/* An alternative completer, or -1 if this is the end of the chain. */
name|short
name|alternative
decl_stmt|;
comment|/* A pointer to the DAG of completers that can potentially follow      this one, or -1. */
name|short
name|subentries
decl_stmt|;
comment|/* The bit offset in the instruction where BITS and MASK should be      applied. */
name|unsigned
name|char
name|offset
range|:
literal|7
decl_stmt|;
name|unsigned
name|char
name|terminal_completer
range|:
literal|1
decl_stmt|;
comment|/* Index into the dependency list table */
name|short
name|dependencies
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This contains sufficient information for the disassembler to resolve    the complete name of the original instruction.  */
end_comment

begin_struct
struct|struct
name|ia64_dis_names
block|{
comment|/* COMPLETER_INDEX represents the tree of completers that make up      the instruction.  The LSB represents the top of the tree for the      specified instruction.        A 0 bit indicates to go to the next alternate completer via the      alternative field; a 1 bit indicates that the current completer      is part of the instruction, and to go down the subentries index.      We know we've reached the final completer when we run out of 1      bits.       There is always at least one 1 bit. */
name|unsigned
name|int
name|completer_index
range|:
literal|20
decl_stmt|;
comment|/* The index in the main_table[] array for the instruction. */
name|unsigned
name|short
name|insn_index
range|:
literal|11
decl_stmt|;
comment|/* If set, the next entry in this table is an alternate possibility      for this instruction encoding.  Which one to use is determined by      the instruction type and other factors (see opcode_verify ()).  */
name|unsigned
name|int
name|next_flag
range|:
literal|1
decl_stmt|;
comment|/* The disassembly priority of this entry among instructions. */
name|unsigned
name|short
name|priority
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit


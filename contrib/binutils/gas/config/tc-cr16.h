begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-cr16.h -- Header file for tc-cr16.c, the CR16 GAS port.    Copyright 2007 Free Software Foundation, Inc.     Contributed by M R Swami Reddy<MR.Swami.Reddy@nsc.com>     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_CR16_H
end_ifndef

begin_define
define|#
directive|define
name|TC_CR16_H
end_define

begin_define
define|#
directive|define
name|TC_CR16
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-cr16"
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_cr16
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|'.'
end_define

begin_define
define|#
directive|define
name|md_undefined_symbol
parameter_list|(
name|s
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_comment
comment|/* We do relaxing in the assembler as well as the linker.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|relax_type
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_relax_table
end_define

begin_comment
comment|/* We do not want to adjust any relocations to make implementation of    linker relaxations easier.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|fixP
parameter_list|)
value|0
end_define

begin_comment
comment|/* We need to force out some relocations when relaxing.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIXP
parameter_list|)
value|cr16_force_relocation (FIXP)
end_define

begin_function_decl
specifier|extern
name|int
name|cr16_force_relocation
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fixup debug sections since we will never relax them.  */
end_comment

begin_define
define|#
directive|define
name|TC_LINKRELAX_FIXUP
parameter_list|(
name|seg
parameter_list|)
value|(seg->flags& SEC_ALLOC)
end_define

begin_comment
comment|/* CR16 instructions, with operands included, are a multiple    of two bytes long.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|2
end_define

begin_function_decl
specifier|extern
name|void
name|cr16_cons_fix_new
parameter_list|(
name|struct
name|frag
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is called by emit_expr when creating a reloc for a cons.    We could use the definition there, except that we want to handle     the CR16 reloc type specially, rather than the BFD_RELOC type.  */
end_comment

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
parameter_list|(
name|FRAG
parameter_list|,
name|OFF
parameter_list|,
name|LEN
parameter_list|,
name|EXP
parameter_list|)
define|\
value|cr16_cons_fix_new (FRAG, OFF, LEN, EXP)
end_define

begin_comment
comment|/* Give an error if a frag containing code is not aligned to a 2-byte     boundary.  */
end_comment

begin_define
define|#
directive|define
name|md_frag_check
parameter_list|(
name|FRAGP
parameter_list|)
define|\
value|if ((FRAGP)->has_code                                                \&& (((FRAGP)->fr_address + (FRAGP)->insn_addr)& 1) != 0)        \      as_bad_where ((FRAGP)->fr_file, (FRAGP)->fr_line,                 \                   _("instruction address is not a multiple of 2"));
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_CR16_H */
end_comment

end_unit


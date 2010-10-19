begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-pj.h    Copyright 1999, 2000, 2001, 2002, 2003, 2005 Free Software Foundation, Inc.     Contributed by Steve Chamberlain of Transmeta, sac@pobox.com     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Contributed by Steve Chamberlain, of Transmeta. sac@pobox.com.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|IGNORE_NONSTANDARD_ESCAPES
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_pj
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(target_big_endian ? "elf32-pj" : "elf32-pjl")
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
define|\
value|(target_big_endian                      				\    ? "Pico Java GAS Big Endian"           				\    : "Pico Java GAS Little Endian")
end_define

begin_function_decl
name|void
name|pj_cons_fix_new_pj
parameter_list|(
name|struct
name|frag
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|arelent
modifier|*
name|tc_gen_reloc
parameter_list|(
name|asection
modifier|*
parameter_list|,
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_section_align
parameter_list|(
name|SEGMENT
parameter_list|,
name|SIZE
parameter_list|)
value|(SIZE)
end_define

begin_define
define|#
directive|define
name|md_convert_frag
parameter_list|(
name|B
parameter_list|,
name|S
parameter_list|,
name|F
parameter_list|)
value|(as_fatal (_("convert_frag\n")), 0)
end_define

begin_define
define|#
directive|define
name|md_estimate_size_before_relax
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|(as_fatal (_("estimate size\n")),0)
end_define

begin_define
define|#
directive|define
name|md_undefined_symbol
parameter_list|(
name|NAME
parameter_list|)
value|0
end_define

begin_comment
comment|/* PC relative operands are relative to the start of the opcode, and    the operand is always one byte into the opcode.  */
end_comment

begin_define
define|#
directive|define
name|md_pcrel_from
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_where + (FIX)->fx_frag->fr_address - 1)
end_define

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
parameter_list|(
name|FRAG
parameter_list|,
name|WHERE
parameter_list|,
name|NBYTES
parameter_list|,
name|EXP
parameter_list|)
define|\
value|pj_cons_fix_new_pj (FRAG, WHERE, NBYTES, EXP)
end_define

begin_comment
comment|/* No shared lib support, so we don't need to ensure externally    visible symbols can be overridden.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|0
end_define

begin_comment
comment|/* Values passed to md_apply_fix don't include the symbol value.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(! ((FIX)->fx_r_type == BFD_RELOC_VTABLE_INHERIT     	\ 	   || (FIX)->fx_r_type == BFD_RELOC_VTABLE_ENTRY))
end_define

end_unit


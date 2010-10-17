begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-w65.h    Copyright 1995, 1997, 1998, 2000, 2002 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_W65
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_if
if|#
directive|if
name|ANSI_PROTOTYPES
end_if

begin_struct_decl
struct_decl|struct
name|internal_reloc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_comment
comment|/* This macro translates between an internal fix and a coff reloc type.  */
end_comment

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fixP
parameter_list|)
value|tc_coff_fix2rtype (fixP)
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_w65
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|0x6500
end_define

begin_define
define|#
directive|define
name|IGNORE_NONSTANDARD_ESCAPES
end_define

begin_define
define|#
directive|define
name|TC_RELOC_MANGLE
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tc_reloc_mangle (a,b,c)
end_define

begin_decl_stmt
specifier|extern
name|void
name|tc_reloc_mangle
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|,
expr|struct
name|internal_reloc
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DO_NOT_STRIP
value|0
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"W65816 GAS "
end_define

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|RELOC_32
value|1234
end_define

begin_define
define|#
directive|define
name|TC_COFF_SIZEMACHDEP
parameter_list|(
name|frag
parameter_list|)
value|tc_coff_sizemachdep (frag)
end_define

begin_decl_stmt
name|int
name|tc_coff_sizemachdep
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_PARSE_CONS_EXPRESSION
parameter_list|(
name|EXP
parameter_list|,
name|NBYTES
parameter_list|)
value|w65_expression (EXP)
end_define

begin_decl_stmt
name|void
name|w65_expression
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|TC_CONS_RELOC
value|tc_cons_reloc
end_define

begin_define
define|#
directive|define
name|DONT_OVERFLOW
end_define

begin_decl_stmt
name|int
name|tc_cons_reloc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_decl_stmt
specifier|extern
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

end_unit


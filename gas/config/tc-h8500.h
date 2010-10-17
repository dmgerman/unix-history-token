begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-h8500.h    Copyright 1993, 1995, 1997, 1998, 2000, 2003 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_H8500
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
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
value|tc_coff_fix2rtype(fixP)
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_h8500
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|0x8500
end_define

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|((x)->fx_addsy||(x)->fx_subsy)
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
value|tc_reloc_mangle(a,b,c)
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
value|"Renesas H8/500 GAS "
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
name|TC_START_LABEL
parameter_list|(
name|ch
parameter_list|,
name|ptr
parameter_list|)
value|(ch == ':'&& start_label(ptr))
end_define

begin_decl_stmt
name|int
name|start_label
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_COFF_SIZEMACHDEP
parameter_list|(
name|frag
parameter_list|)
value|tc_coff_sizemachdep(frag)
end_define

begin_decl_stmt
name|int
name|tc_coff_sizemachdep
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frag
operator|*
operator|)
argument_list|)
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


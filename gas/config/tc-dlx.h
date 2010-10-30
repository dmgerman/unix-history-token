begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-dlx.h -- Assemble for the DLX    Copyright 2002, 2003, 2005, 2006 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* Initially created by Kuang Hwa Lin, 3/20/2002.  */
end_comment

begin_define
define|#
directive|define
name|TC_DLX
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_dlx
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-dlx"
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|LEX_DOLLAR
value|1
end_define

begin_function_decl
specifier|extern
name|void
name|dlx_pop_insert
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_dlx_skip_hi16_flag
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dlx_unrecognized_line
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|md_dlx_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_pop_insert
parameter_list|()
value|dlx_pop_insert ()
end_define

begin_define
define|#
directive|define
name|md_convert_frag
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|as_fatal ("convert_frag called\n")
end_define

begin_define
define|#
directive|define
name|md_estimate_size_before_relax
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|(as_fatal ("estimate_size_before_relax called"),1)
end_define

begin_define
define|#
directive|define
name|tc_unrecognized_line
parameter_list|(
name|c
parameter_list|)
value|dlx_unrecognized_line (c)
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

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|md_dlx_fix_adjustable (FIX)
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

begin_comment
comment|/* Zero Based Segment?? sound very dangerous to me!     */
end_comment

begin_define
define|#
directive|define
name|ZERO_BASED_SEGMENTS
end_define

begin_comment
comment|/* Permit temporary numeric labels.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_undef
undef|#
directive|undef
name|LOCAL_LABELS_DOLLAR
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABELS_DOLLAR
value|0
end_define

begin_comment
comment|/* .-foo gets turned into PC relative relocs.  */
end_comment

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

end_unit


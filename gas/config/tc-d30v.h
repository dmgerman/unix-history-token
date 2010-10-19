begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-310v.h -- Header file for tc-d30v.c.    Copyright 1997, 1998, 2000, 2001, 2002, 2005    Free Software Foundation, Inc.    Written by Martin Hunt, Cygnus Support.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_D30V
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_d30v
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-d30v"
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
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* Call md_pcrel_from_section, not md_pcrel_from.  */
end_comment

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|long
name|md_pcrel_from_section
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|,
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|FIX
parameter_list|,
name|SEC
parameter_list|)
value|md_pcrel_from_section (FIX, SEC)
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

begin_comment
comment|/* .-foo gets turned into PC relative relocs.  */
end_comment

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* We don't need to handle .word strangely.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_bigendian
end_define

begin_function_decl
name|int
name|d30v_cleanup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_after_pass_hook
parameter_list|()
value|d30v_cleanup (FALSE)
end_define

begin_define
define|#
directive|define
name|md_cleanup
parameter_list|()
value|d30v_cleanup (FALSE)
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
value|(ch == ':'&& d30v_cleanup (FALSE))
end_define

begin_function_decl
name|void
name|d30v_start_line
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_start_line_hook
parameter_list|()
value|d30v_start_line ()
end_define

begin_function_decl
name|void
name|d30v_frob_label
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|d30v_frob_label (sym)
end_define

begin_function_decl
name|void
name|d30v_cons_align
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_cons_align
parameter_list|(
name|nbytes
parameter_list|)
value|d30v_cons_align (nbytes)
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
comment|/* No shared lib support, so we don't need to ensure externally    visible symbols can be overridden.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|0
end_define

end_unit


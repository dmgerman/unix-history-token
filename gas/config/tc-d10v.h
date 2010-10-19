begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-d10v.h -- Header file for tc-d10v.c.    Copyright 1996, 1997, 1998, 2000, 2001, 2002, 2003, 2005    Free Software Foundation, Inc.    Written by Martin Hunt, Cygnus Support.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_D10V
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_d10v
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-d10v"
end_define

begin_comment
comment|/* Call md_pcrel_from_section, not md_pcrel_from.  */
end_comment

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

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_function_decl
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
name|d10v_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_after_pass_hook
parameter_list|()
value|d10v_cleanup ()
end_define

begin_define
define|#
directive|define
name|md_cleanup
parameter_list|()
value|d10v_cleanup ()
end_define

begin_define
define|#
directive|define
name|md_do_align
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|d10v_cleanup ()
end_define

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
define|\
value|do							\     {							\       d10v_cleanup ();					\       symbol_set_frag (sym, frag_now);			\       S_SET_VALUE (sym, (valueT) frag_now_fix ());	\     }							\   while (0)
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|d10v_fix_adjustable(FIX)
end_define

begin_function_decl
name|bfd_boolean
name|d10v_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_define
define|#
directive|define
name|md_flush_pending_output
value|d10v_cleanup
end_define

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-i370.h -- Header file for tc-i370.c.    Copyright 1994, 1995, 1996, 1997, 1998, 2000, 2001, 2002, 2005    Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Support.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_I370
end_define

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_comment
comment|/* Set the endianness we are using.  Default to big endian.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BYTES_BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|(i370_arch ())
end_define

begin_function_decl
specifier|extern
name|enum
name|bfd_architecture
name|i370_arch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Whether or not the target is big endian.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_big_endian
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The target BFD format.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|("elf32-i370")
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
comment|/* $ is used to refer to the current location.  */
end_comment

begin_comment
comment|/* #define DOLLAR_DOT */
end_comment

begin_comment
comment|/* foo-. gets turned into PC relative relocs.  */
end_comment

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
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
comment|/* We don't need to handle .word strangely.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
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
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|tc_comment_chars
value|i370_comment_chars
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|i370_comment_chars
decl_stmt|;
end_decl_stmt

end_unit


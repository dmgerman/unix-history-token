begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* read.h - of read.c    Copyright (C) 1986, 90, 92, 93, 94, 95, 1996 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|input_line_pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -> char we are parsing now. */
end_comment

begin_define
define|#
directive|define
name|PERMIT_WHITESPACE
end_define

begin_comment
comment|/* Define to make whitespace be allowed in */
end_comment

begin_comment
comment|/* many syntactically unnecessary places. */
end_comment

begin_comment
comment|/* Normally undefined. For compatibility */
end_comment

begin_comment
comment|/* with ancient GNU cc. */
end_comment

begin_comment
comment|/* #undef PERMIT_WHITESPACE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PERMIT_WHITESPACE
end_ifdef

begin_define
define|#
directive|define
name|SKIP_WHITESPACE
parameter_list|()
value|{if (* input_line_pointer == ' ') ++ input_line_pointer;}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SKIP_WHITESPACE
parameter_list|()
value|know(*input_line_pointer != ' ' )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LEX_NAME
value|(1)
end_define

begin_comment
comment|/* may continue a name */
end_comment

begin_define
define|#
directive|define
name|LEX_BEGIN_NAME
value|(2)
end_define

begin_comment
comment|/* may begin a name */
end_comment

begin_define
define|#
directive|define
name|is_name_beginner
parameter_list|(
name|c
parameter_list|)
define|\
value|( lex_type[(unsigned char) (c)]& LEX_BEGIN_NAME )
end_define

begin_define
define|#
directive|define
name|is_part_of_name
parameter_list|(
name|c
parameter_list|)
define|\
value|( lex_type[(unsigned char) (c)]& LEX_NAME       )
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|is_a_char
end_ifndef

begin_define
define|#
directive|define
name|CHAR_MASK
value|(0xff)
end_define

begin_define
define|#
directive|define
name|NOT_A_CHAR
value|(CHAR_MASK+1)
end_define

begin_define
define|#
directive|define
name|is_a_char
parameter_list|(
name|c
parameter_list|)
value|(((unsigned)(c))<= CHAR_MASK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* is_a_char() */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|lex_type
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|is_end_of_line
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_it_end_of_statement
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|target_big_endian
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These are initialized by the CPU specific target files (tc-*.c).  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|comment_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|line_comment_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|line_separator_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This flag whether to generate line info for asm file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|generate_asm_lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The offset in the absolute section.  */
end_comment

begin_decl_stmt
specifier|extern
name|addressT
name|abs_section_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The label on a line, used by some of the pseudo-ops.  */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|line_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is used to support MRI common sections.  */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|mri_common_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Possible arguments to .linkonce.  */
end_comment

begin_enum
enum|enum
name|linkonce_type
block|{
name|LINKONCE_UNSET
init|=
literal|0
block|,
name|LINKONCE_DISCARD
block|,
name|LINKONCE_ONE_ONLY
block|,
name|LINKONCE_SAME_SIZE
block|,
name|LINKONCE_SAME_CONTENTS
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|void
name|pop_insert
name|PARAMS
argument_list|(
operator|(
specifier|const
name|pseudo_typeS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|get_stab_string_offset
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|string
operator|,
specifier|const
name|char
operator|*
name|stabstr_secname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|demand_copy_C_string
name|PARAMS
argument_list|(
operator|(
name|int
operator|*
name|len_pointer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|get_absolute_expression_and_terminator
name|PARAMS
argument_list|(
operator|(
name|long
operator|*
name|val_pointer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|offsetT
name|get_absolute_expression
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|next_char_of_string
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_mri_sect
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mri_comment_field
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mri_comment_end
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_include_dir
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cons
name|PARAMS
argument_list|(
operator|(
name|int
name|nbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|demand_empty_rest_of_line
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|emit_expr
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
name|exp
operator|,
name|unsigned
name|int
name|nbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|equals
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|sym_name
operator|,
name|int
name|reassign
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|float_cons
name|PARAMS
argument_list|(
operator|(
name|int
name|float_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ignore_rest_of_line
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pseudo_set
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
name|symbolP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|read_a_source_file
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|read_begin
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_abort
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_align_bytes
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_align_ptwo
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_app_file
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_app_line
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_comm
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_data
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_desc
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_else
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_end
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_endif
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_err
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_fail
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_fill
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_float_space
name|PARAMS
argument_list|(
operator|(
name|int
name|mult
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_globl
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_if
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_ifc
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_ifdef
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_ifeqs
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_ignore
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_include
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_irp
name|PARAMS
argument_list|(
operator|(
name|int
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_lcomm
name|PARAMS
argument_list|(
operator|(
name|int
name|needs_align
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_linkonce
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_lsym
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_macro
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_mexit
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_mri
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_mri_common
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_org
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_print
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_purgem
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_rept
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_set
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_space
name|PARAMS
argument_list|(
operator|(
name|int
name|mult
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_stab
name|PARAMS
argument_list|(
operator|(
name|int
name|what
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_struct
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_text
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|stringer
name|PARAMS
argument_list|(
operator|(
name|int
name|append_zero
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_xstab
name|PARAMS
argument_list|(
operator|(
name|int
name|what
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|s_rva
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|read_print_statistics
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of read.h */
end_comment

end_unit


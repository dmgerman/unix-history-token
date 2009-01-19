begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* read.h - of read.c    Copyright 1986, 1990, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,    2000, 2001, 2002, 2003    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|input_line_pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -> char we are parsing now.  */
end_comment

begin_comment
comment|/* Define to make whitespace be allowed in many syntactically    unnecessary places.  Normally undefined.  For compatibility with    ancient GNU cc.  */
end_comment

begin_comment
comment|/* #undef PERMIT_WHITESPACE */
end_comment

begin_define
define|#
directive|define
name|PERMIT_WHITESPACE
end_define

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
define|\
value|((*input_line_pointer == ' ') ? ++input_line_pointer : 0)
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
name|LEX_END_NAME
value|(4)
end_define

begin_comment
comment|/* ends a name */
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

begin_define
define|#
directive|define
name|is_name_ender
parameter_list|(
name|c
parameter_list|)
define|\
value|( lex_type[(unsigned char) (c)]& LEX_END_NAME   )
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
value|(((unsigned) (c))<= CHAR_MASK)
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

begin_function_decl
specifier|extern
name|int
name|is_it_end_of_statement
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* Table of -I directories.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|include_dirs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|include_dir_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|include_dir_maxlen
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
comment|/* True if a stabs line debug statement is currently being emitted.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|outputting_stabs_line_debug
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

begin_ifndef
ifndef|#
directive|ifndef
name|TC_CASE_SENSITIVE
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|original_case_string
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|pop_insert
parameter_list|(
specifier|const
name|pseudo_typeS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|get_stab_string_offset
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
specifier|const
name|char
modifier|*
name|stabstr_secname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aout_process_stab
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|demand_copy_string
parameter_list|(
name|int
modifier|*
name|lenP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|demand_copy_C_string
parameter_list|(
name|int
modifier|*
name|len_pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
name|get_absolute_expression_and_terminator
parameter_list|(
name|long
modifier|*
name|val_pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|offsetT
name|get_absolute_expr
parameter_list|(
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|offsetT
name|get_absolute_expression
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|next_char_of_string
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_mri_sect
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mri_comment_field
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mri_comment_end
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_include_dir
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cons
parameter_list|(
name|int
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|demand_empty_rest_of_line
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|emit_expr
parameter_list|(
name|expressionS
modifier|*
name|exp
parameter_list|,
name|unsigned
name|int
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|emit_leb128_expr
parameter_list|(
name|expressionS
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|equals
parameter_list|(
name|char
modifier|*
name|sym_name
parameter_list|,
name|int
name|reassign
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|float_cons
parameter_list|(
name|int
name|float_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ignore_rest_of_line
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|discard_rest_of_line
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|output_leb128
parameter_list|(
name|char
modifier|*
parameter_list|,
name|valueT
parameter_list|,
name|int
name|sign
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pseudo_set
parameter_list|(
name|symbolS
modifier|*
name|symbolP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_a_source_file
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_begin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_print_statistics
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sizeof_leb128
parameter_list|(
name|valueT
parameter_list|,
name|int
name|sign
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stabs_generate_asm_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stabs_generate_asm_lineno
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stabs_generate_asm_func
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stabs_generate_asm_endfunc
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_repeat
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|end_repeat
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_parse_cons_expression
parameter_list|(
name|expressionS
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generate_lineno_debug
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|s_abort
argument_list|(
name|int
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|s_align_bytes
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_align_ptwo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bss_alloc
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|addressT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|offsetT
name|parse_align
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|symbolS
modifier|*
name|s_comm_internal
parameter_list|(
name|int
parameter_list|,
name|symbolS
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|symbolS
modifier|*
parameter_list|,
name|addressT
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|symbolS
modifier|*
name|s_lcomm_internal
parameter_list|(
name|int
parameter_list|,
name|symbolS
modifier|*
parameter_list|,
name|addressT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_app_file_string
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_app_file
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_app_line
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_bad_endr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_comm
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_data
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_desc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_else
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_elseif
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_end
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_endif
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_err
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_fail
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_fill
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_float_space
parameter_list|(
name|int
name|mult
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_func
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_s_func
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_globl
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_if
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_ifc
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_ifdef
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_ifeqs
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_ignore
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_include
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_irp
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_lcomm
parameter_list|(
name|int
name|needs_align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_lcomm_bytes
parameter_list|(
name|int
name|needs_align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_leb128
parameter_list|(
name|int
name|sign
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_linkonce
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_lsym
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_macro
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_mexit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_mri
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_mri_common
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_org
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_print
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_purgem
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_rept
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_set
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_space
parameter_list|(
name|int
name|mult
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_stab
parameter_list|(
name|int
name|what
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_struct
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_text
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stringer
parameter_list|(
name|int
name|append_zero
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_xstab
parameter_list|(
name|int
name|what
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_rva
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|s_incbin
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit


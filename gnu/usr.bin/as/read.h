begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* read.h - of read.c     Copyright (C) 1986, 1990, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
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
value|( lex_type[c]& LEX_BEGIN_NAME )
end_define

begin_define
define|#
directive|define
name|is_part_of_name
parameter_list|(
name|c
parameter_list|)
value|( lex_type[c]& LEX_NAME       )
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

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_comment
comment|/* We change some of the entries in lex_type on some archs */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|lex_type
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|lex_type
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|is_end_of_line
index|[]
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

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

begin_function_decl
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
name|long
name|get_absolute_expression
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|big_cons
parameter_list|(
name|int
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cons
parameter_list|(
name|unsigned
name|int
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|demand_empty_rest_of_line
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|equals
parameter_list|(
name|char
modifier|*
name|sym_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|float_cons
parameter_list|(
name|int
name|float_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ignore_rest_of_line
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|read_begin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_align_bytes
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_align_ptwo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_app_file
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_app_line
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_comm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_else
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_end
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_endif
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_fill
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_globl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_if
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_ifdef
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_ifeqs
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_ignore
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_include
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_lcomm
parameter_list|(
name|int
name|needs_align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_lsym
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_org
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_set
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_space
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_text
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_weak
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|char
modifier|*
name|demand_copy_C_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|get_absolute_expression_and_terminator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|get_absolute_expression
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_include_dir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|big_cons
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cons
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|demand_empty_rest_of_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|equals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|float_cons
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ignore_rest_of_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pseudo_set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_a_source_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_abort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_align_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_align_ptwo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_app_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_app_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_comm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_else
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_endif
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_fill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_globl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_if
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_ifdef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_ifeqs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_ignore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_include
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_lcomm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_lsym
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_org
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_size
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_space
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_text
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s_weak
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of read.h */
end_comment

end_unit


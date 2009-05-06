begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* symbols.h -    Copyright 1987, 1990, 1992, 1993, 1994, 1995, 1997, 1999, 2000, 2001,    2002, 2003 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_comment
comment|/* The BFD code wants to walk the list in both directions.  */
end_comment

begin_undef
undef|#
directive|undef
name|SYMBOLS_NEED_BACKPOINTERS
end_undef

begin_define
define|#
directive|define
name|SYMBOLS_NEED_BACKPOINTERS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_comment
comment|/* The non-BFD code expects to be able to manipulate the symbol fields    directly.  */
end_comment

begin_include
include|#
directive|include
file|"struc-symbol.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|obstack
name|notes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* eg FixS live here.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|obstack
name|cond_obstack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this is where we track .ifdef/.endif 				       (if we do that at all).  */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|symbol_rootP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all the symbol nodes */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|symbol_lastP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last struct symbol we made, or NULL */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
name|abs_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symbol_table_frozen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is non-zero if symbols are case sensitive, which is the    default.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|symbols_case_sensitive
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|decode_local_label_name
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find_exact
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find_base
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|strip_underscore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find_or_make
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_make
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_new
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|segT
name|segment
parameter_list|,
name|valueT
name|value
parameter_list|,
name|fragS
modifier|*
name|frag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_create
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|segT
name|segment
parameter_list|,
name|valueT
name|value
parameter_list|,
name|fragS
modifier|*
name|frag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|local_symbol
modifier|*
name|local_symbol_make
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|segT
name|section
parameter_list|,
name|valueT
name|value
parameter_list|,
name|fragS
modifier|*
name|frag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_temp_new
parameter_list|(
name|segT
parameter_list|,
name|valueT
parameter_list|,
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_temp_new_now
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_temp_make
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|colon
parameter_list|(
specifier|const
name|char
modifier|*
name|sym_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|local_colon
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_begin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_print_statistics
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_table_insert
parameter_list|(
name|symbolS
modifier|*
name|symbolP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|valueT
name|resolve_symbol_value
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resolve_local_symbol_values
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_symbol_value
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_expr
parameter_list|(
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_expr_1
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_symbol_value_1
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dollar_label_defined
parameter_list|(
name|long
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dollar_label_clear
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|define_dollar_label
parameter_list|(
name|long
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|dollar_label_name
parameter_list|(
name|long
name|l
parameter_list|,
name|int
name|augend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb_label_instance_inc
parameter_list|(
name|long
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fb_label_name
parameter_list|(
name|long
name|n
parameter_list|,
name|long
name|augend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|copy_symbol_attributes
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get and set the values of symbols.  These used to be macros.  */
end_comment

begin_function_decl
specifier|extern
name|valueT
name|S_GET_VALUE
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|S_SET_VALUE
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|valueT
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_function_decl
specifier|extern
name|int
name|S_IS_FUNCTION
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|S_IS_EXTERNAL
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|S_IS_WEAK
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|S_IS_COMMON
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|S_IS_DEFINED
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|S_FORCE_RELOC
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|S_IS_DEBUG
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|S_IS_LOCAL
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|S_IS_EXTERN
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|S_IS_STABD
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|S_GET_NAME
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|segT
name|S_GET_SEGMENT
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|S_SET_SEGMENT
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|S_SET_EXTERNAL
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|S_SET_NAME
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|S_CLEAR_EXTERNAL
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|S_SET_WEAK
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|S_SET_THREAD_LOCAL
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WORKING_DOT_WORD
end_ifndef

begin_struct
struct|struct
name|broken_word
block|{
comment|/* Linked list -- one of these structures per ".word x-y+C"        expression.  */
name|struct
name|broken_word
modifier|*
name|next_broken_word
decl_stmt|;
comment|/* Segment and subsegment for broken word.  */
name|segT
name|seg
decl_stmt|;
name|subsegT
name|subseg
decl_stmt|;
comment|/* Which frag is this broken word in?  */
name|fragS
modifier|*
name|frag
decl_stmt|;
comment|/* Where in the frag is it?  */
name|char
modifier|*
name|word_goes_here
decl_stmt|;
comment|/* Where to add the break.  */
name|fragS
modifier|*
name|dispfrag
decl_stmt|;
comment|/* where to add the break */
comment|/* Operands of expression.  */
name|symbolS
modifier|*
name|add
decl_stmt|;
name|symbolS
modifier|*
name|sub
decl_stmt|;
name|offsetT
name|addnum
decl_stmt|;
name|int
name|added
decl_stmt|;
comment|/* nasty thing happened yet? */
comment|/* 1: added and has a long-jump */
comment|/* 2: added but uses someone elses long-jump */
comment|/* Pointer to broken_word with a similar long-jump.  */
name|struct
name|broken_word
modifier|*
name|use_jump
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|broken_word
modifier|*
name|broken_words
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef WORKING_DOT_WORD */
end_comment

begin_comment
comment|/*  * Current means for getting from symbols to segments and vice verse.  * This will change for infinite-segments support (e.g. COFF).  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|segT
name|N_TYPE_seg
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* subseg.c */
end_comment

begin_define
define|#
directive|define
name|SEGMENT_TO_SYMBOL_TYPE
parameter_list|(
name|seg
parameter_list|)
value|( seg_N_TYPE [(int) (seg)] )
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|short
name|seg_N_TYPE
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* subseg.c */
end_comment

begin_define
define|#
directive|define
name|N_REGISTER
value|30
end_define

begin_comment
comment|/* Fake N_TYPE value for SEG_REGISTER */
end_comment

begin_function_decl
name|void
name|symbol_clear_list_pointers
parameter_list|(
name|symbolS
modifier|*
name|symbolP
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SYMBOLS_NEED_BACKPOINTERS
end_ifdef

begin_function_decl
name|void
name|symbol_insert
parameter_list|(
name|symbolS
modifier|*
name|addme
parameter_list|,
name|symbolS
modifier|*
name|target
parameter_list|,
name|symbolS
modifier|*
modifier|*
name|rootP
parameter_list|,
name|symbolS
modifier|*
modifier|*
name|lastP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_remove
parameter_list|(
name|symbolS
modifier|*
name|symbolP
parameter_list|,
name|symbolS
modifier|*
modifier|*
name|rootP
parameter_list|,
name|symbolS
modifier|*
modifier|*
name|lastP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|symbolS
modifier|*
name|symbol_previous
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYMBOLS_NEED_BACKPOINTERS */
end_comment

begin_function_decl
name|void
name|verify_symbol_chain
parameter_list|(
name|symbolS
modifier|*
name|rootP
parameter_list|,
name|symbolS
modifier|*
name|lastP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|verify_symbol_chain_2
parameter_list|(
name|symbolS
modifier|*
name|symP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_append
parameter_list|(
name|symbolS
modifier|*
name|addme
parameter_list|,
name|symbolS
modifier|*
name|target
parameter_list|,
name|symbolS
modifier|*
modifier|*
name|rootP
parameter_list|,
name|symbolS
modifier|*
modifier|*
name|lastP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|symbolS
modifier|*
name|symbol_next
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|expressionS
modifier|*
name|symbol_get_value_expression
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_set_value_expression
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
specifier|const
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_set_value_now
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_set_frag
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fragS
modifier|*
name|symbol_get_frag
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_mark_used
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_clear_used
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbol_used_p
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_mark_used_in_reloc
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_clear_used_in_reloc
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbol_used_in_reloc_p
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_mark_mri_common
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_clear_mri_common
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbol_mri_common_p
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_mark_written
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_clear_written
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbol_written_p
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_mark_resolved
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbol_resolved_p
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbol_section_p
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbol_equated_p
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbol_equated_reloc_p
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symbol_constant_p
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_function_decl
specifier|extern
name|asymbol
modifier|*
name|symbol_get_bfdsym
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symbol_set_bfdsym
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_SYMFIELD_TYPE
end_ifdef

begin_function_decl
name|OBJ_SYMFIELD_TYPE
modifier|*
name|symbol_get_obj
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_set_obj
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|OBJ_SYMFIELD_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_SYMFIELD_TYPE
end_ifdef

begin_function_decl
name|TC_SYMFIELD_TYPE
modifier|*
name|symbol_get_tc
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_set_tc
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|TC_SYMFIELD_TYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit


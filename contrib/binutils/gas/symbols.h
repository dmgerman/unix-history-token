begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* symbols.h -    Copyright 1987, 1990, 1992, 1993, 1994, 1995, 1997, 1999, 2000, 2001    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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

begin_decl_stmt
name|char
modifier|*
name|decode_local_label_name
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|symbolS
modifier|*
name|symbol_find
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|symbolS
modifier|*
name|symbol_find_base
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|name
operator|,
name|int
name|strip_underscore
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|symbolS
modifier|*
name|symbol_find_or_make
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|symbolS
modifier|*
name|symbol_make
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|symbolS
modifier|*
name|symbol_new
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|name
operator|,
name|segT
name|segment
operator|,
name|valueT
name|value
operator|,
name|fragS
operator|*
name|frag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|symbolS
modifier|*
name|symbol_create
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|name
operator|,
name|segT
name|segment
operator|,
name|valueT
name|value
operator|,
name|fragS
operator|*
name|frag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|symbolS
modifier|*
name|colon
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|sym_name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|local_colon
name|PARAMS
argument_list|(
operator|(
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|symbol_begin
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|symbol_print_statistics
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|symbol_table_insert
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
name|valueT
name|resolve_symbol_value
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|resolve_local_symbol_values
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_symbol_value
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_expr
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_expr_1
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_symbol_value_1
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dollar_label_defined
name|PARAMS
argument_list|(
operator|(
name|long
name|l
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dollar_label_clear
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|define_dollar_label
name|PARAMS
argument_list|(
operator|(
name|long
name|l
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dollar_label_name
name|PARAMS
argument_list|(
operator|(
name|long
name|l
operator|,
name|int
name|augend
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fb_label_instance_inc
name|PARAMS
argument_list|(
operator|(
name|long
name|label
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fb_label_name
name|PARAMS
argument_list|(
operator|(
name|long
name|n
operator|,
name|long
name|augend
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|copy_symbol_attributes
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get and set the values of symbols.  These used to be macros.  */
end_comment

begin_decl_stmt
specifier|extern
name|valueT
name|S_GET_VALUE
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|S_SET_VALUE
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|valueT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|S_IS_FUNCTION
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|S_IS_EXTERNAL
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|S_IS_WEAK
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|S_IS_COMMON
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|S_IS_DEFINED
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|S_IS_DEBUG
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|S_IS_LOCAL
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|S_IS_EXTERN
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|S_IS_STABD
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CONST
name|char
modifier|*
name|S_GET_NAME
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|segT
name|S_GET_SEGMENT
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|S_SET_SEGMENT
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|S_SET_EXTERNAL
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|S_SET_NAME
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|S_CLEAR_EXTERNAL
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|S_SET_WEAK
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* nasty thing happend yet? */
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

begin_decl_stmt
name|void
name|symbol_clear_list_pointers
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

begin_ifdef
ifdef|#
directive|ifdef
name|SYMBOLS_NEED_BACKPOINTERS
end_ifdef

begin_decl_stmt
name|void
name|symbol_insert
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
name|addme
operator|,
name|symbolS
operator|*
name|target
operator|,
name|symbolS
operator|*
operator|*
name|rootP
operator|,
name|symbolS
operator|*
operator|*
name|lastP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|symbol_remove
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
name|symbolP
operator|,
name|symbolS
operator|*
operator|*
name|rootP
operator|,
name|symbolS
operator|*
operator|*
name|lastP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|symbol_previous
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYMBOLS_NEED_BACKPOINTERS */
end_comment

begin_decl_stmt
name|void
name|verify_symbol_chain
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
name|rootP
operator|,
name|symbolS
operator|*
name|lastP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|verify_symbol_chain_2
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
name|symP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|symbol_append
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
name|addme
operator|,
name|symbolS
operator|*
name|target
operator|,
name|symbolS
operator|*
operator|*
name|rootP
operator|,
name|symbolS
operator|*
operator|*
name|lastP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|symbol_next
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|expressionS
modifier|*
name|symbol_get_value_expression
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_set_value_expression
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
specifier|const
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_set_frag
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|fragS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fragS
modifier|*
name|symbol_get_frag
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_mark_used
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_clear_used
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symbol_used_p
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_mark_used_in_reloc
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_clear_used_in_reloc
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symbol_used_in_reloc_p
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_mark_mri_common
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_clear_mri_common
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symbol_mri_common_p
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_mark_written
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_clear_written
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symbol_written_p
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_mark_resolved
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symbol_resolved_p
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symbol_section_p
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symbol_equated_p
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symbol_constant_p
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_decl_stmt
specifier|extern
name|asymbol
modifier|*
name|symbol_get_bfdsym
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|symbol_set_bfdsym
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|asymbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_SYMFIELD_TYPE
end_ifdef

begin_decl_stmt
name|OBJ_SYMFIELD_TYPE
modifier|*
name|symbol_get_obj
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|symbol_set_obj
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|OBJ_SYMFIELD_TYPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TC_SYMFIELD_TYPE
end_ifdef

begin_decl_stmt
name|TC_SYMFIELD_TYPE
modifier|*
name|symbol_get_tc
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|symbol_set_tc
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|TC_SYMFIELD_TYPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit


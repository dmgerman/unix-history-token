begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* struct_symbol.h - Internal symbol structure    Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     oYou should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__struc_symbol_h__
end_ifndef

begin_define
define|#
directive|define
name|__struc_symbol_h__
end_define

begin_struct
struct|struct
name|symbol
comment|/* our version of an nlist node */
block|{
name|obj_symbol_type
name|sy_symbol
decl_stmt|;
comment|/* what we write in .o file (if permitted) */
name|unsigned
name|long
name|sy_name_offset
decl_stmt|;
comment|/* 4-origin position of sy_name in symbols */
comment|/* part of object file. */
comment|/* 0 for (nameless) .stabd symbols. */
comment|/* Not used until write_object_file() time. */
name|long
name|sy_number
decl_stmt|;
comment|/* 24 bit symbol number. */
comment|/* Symbol numbers start at 0 and are */
comment|/* unsigned. */
name|struct
name|symbol
modifier|*
name|sy_next
decl_stmt|;
comment|/* forward chain, or NULL */
ifdef|#
directive|ifdef
name|SYMBOLS_NEED_BACKPOINTERS
name|struct
name|symbol
modifier|*
name|sy_previous
decl_stmt|;
comment|/* backward chain, or NULL */
endif|#
directive|endif
comment|/* SYMBOLS_NEED_BACKPOINTERS */
name|struct
name|frag
modifier|*
name|sy_frag
decl_stmt|;
comment|/* NULL or -> frag this symbol attaches to. */
name|struct
name|symbol
modifier|*
name|sy_forward
decl_stmt|;
comment|/* value is really that of this other symbol */
comment|/* We will probably want to add a sy_segment here soon. */
ifdef|#
directive|ifdef
name|PIC
comment|/* Force symbol into symbol table, even if local */
name|int
name|sy_forceout
decl_stmt|;
endif|#
directive|endif
comment|/* Size of symbol as given by the .size directive */
name|void
modifier|*
name|sy_sizexp
decl_stmt|;
comment|/* (expressionS *) */
comment|/* Auxiliary type information as given by the .type directive */
name|unsigned
name|char
name|sy_aux
decl_stmt|;
define|#
directive|define
name|AUX_OBJECT
value|1
define|#
directive|define
name|AUX_FUNC
value|2
name|unsigned
name|char
name|sy_bind
decl_stmt|;
define|#
directive|define
name|BIND_LOCAL
value|0
comment|/* currently not used */
define|#
directive|define
name|BIND_GLOBAL
value|1
comment|/* currently not used */
define|#
directive|define
name|BIND_WEAK
value|2
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|symbol
name|symbolS
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_decl_stmt
name|symbolS
modifier|*
name|GOT_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pre-defined "__GLOBAL_OFFSET_TABLE" */
end_comment

begin_decl_stmt
name|int
name|got_referenced
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|valueT
typedef|;
end_typedef

begin_comment
comment|/* The type of n_value. Helps casting. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WORKING_DOT_WORD
end_ifndef

begin_struct
struct|struct
name|broken_word
block|{
name|struct
name|broken_word
modifier|*
name|next_broken_word
decl_stmt|;
comment|/* One of these strucs per .word x-y */
name|fragS
modifier|*
name|frag
decl_stmt|;
comment|/* Which frag its in */
name|char
modifier|*
name|word_goes_here
decl_stmt|;
comment|/* Where in the frag it is */
name|fragS
modifier|*
name|dispfrag
decl_stmt|;
comment|/* where to add the break */
name|symbolS
modifier|*
name|add
decl_stmt|;
comment|/* symbol_x */
name|symbolS
modifier|*
name|sub
decl_stmt|;
comment|/* - symbol_y */
name|long
name|addnum
decl_stmt|;
comment|/* + addnum */
name|int
name|added
decl_stmt|;
comment|/* nasty thing happend yet? */
comment|/* 1: added and has a long-jump */
comment|/* 2: added but uses someone elses long-jump */
name|struct
name|broken_word
modifier|*
name|use_jump
decl_stmt|;
comment|/* points to broken_word with a similar 					 long-jump */
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

begin_define
define|#
directive|define
name|SEGMENT_TO_SYMBOL_TYPE
parameter_list|(
name|seg
parameter_list|)
value|(seg_N_TYPE[(int) (seg)])
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

begin_ifdef
ifdef|#
directive|ifdef
name|SYMBOLS_NEED_BACKPOINTERS
end_ifdef

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|void
name|symbol_clear_list_pointers
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_insert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_remove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|verify_symbol_chain
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

begin_define
define|#
directive|define
name|symbol_previous
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_previous)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYMBOLS_NEED_BACKPOINTERS */
end_comment

begin_define
define|#
directive|define
name|symbol_clear_list_pointers
parameter_list|(
name|clearme
parameter_list|)
value|{clearme->sy_next = NULL;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYMBOLS_NEED_BACKPOINTERS */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|void
name|symbol_append
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

begin_define
define|#
directive|define
name|symbol_next
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_next)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __struc_symbol_h__ */
end_comment

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of struc-symbol.h */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* struct_symbol.h - Internal symbol structure    Copyright (C) 1987, 1992, 1993, 1994 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* our version of an nlist node */
end_comment

begin_struct
struct|struct
name|symbol
block|{
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
comment|/* The (4-origin) position of sy_name in the symbol table of the object      file.  This will be 0 for (nameless) .stabd symbols.       Not used until write_object_file() time. */
name|unsigned
name|long
name|sy_name_offset
decl_stmt|;
comment|/* What we write in .o file (if permitted).  */
name|obj_symbol_type
name|sy_symbol
decl_stmt|;
comment|/* The 24 bit symbol number.  Symbol numbers start at 0 and are unsigned. */
name|long
name|sy_number
decl_stmt|;
else|#
directive|else
comment|/* BFD symbol */
name|asymbol
modifier|*
name|bsym
decl_stmt|;
endif|#
directive|endif
comment|/* The value of the symbol.  */
name|expressionS
name|sy_value
decl_stmt|;
comment|/* Forwards and (optionally) backwards chain pointers.  */
name|struct
name|symbol
modifier|*
name|sy_next
decl_stmt|;
ifdef|#
directive|ifdef
name|SYMBOLS_NEED_BACKPOINTERS
name|struct
name|symbol
modifier|*
name|sy_previous
decl_stmt|;
endif|#
directive|endif
comment|/* SYMBOLS_NEED_BACKPOINTERS */
comment|/* Pointer to the frag this symbol is attached to, if any.      Otherwise, NULL.  */
name|struct
name|frag
modifier|*
name|sy_frag
decl_stmt|;
name|unsigned
name|int
name|written
range|:
literal|1
decl_stmt|;
comment|/* Whether symbol value has been completely resolved (used during      final pass over symbol table).  */
name|unsigned
name|int
name|sy_resolved
range|:
literal|1
decl_stmt|;
comment|/* Whether the symbol value is currently being resolved (used to      detect loops in symbol dependencies).  */
name|unsigned
name|int
name|sy_resolving
range|:
literal|1
decl_stmt|;
comment|/* Whether the symbol value is used in a reloc.  This is used to      ensure that symbols used in relocs are written out, even if they      are local and would otherwise not be.  */
name|unsigned
name|int
name|sy_used_in_reloc
range|:
literal|1
decl_stmt|;
comment|/* Whether the symbol is used as an operand or in an expression.        NOTE:  Not all the backends keep this information accurate;      backends which use this bit are responsible for setting it when      a symbol is used in backend routines.  */
name|unsigned
name|int
name|sy_used
range|:
literal|1
decl_stmt|;
comment|/* This is set if the symbol is defined in an MRI common section.      We handle such sections as single common symbols, so symbols      defined within them must be treated specially by the relocation      routines.  */
name|unsigned
name|int
name|sy_mri_common
range|:
literal|1
decl_stmt|;
ifdef|#
directive|ifdef
name|OBJ_SYMFIELD_TYPE
name|OBJ_SYMFIELD_TYPE
name|sy_obj
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TC_SYMFIELD_TYPE
name|TC_SYMFIELD_TYPE
name|sy_tc
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TARGET_SYMBOL_FIELDS
name|TARGET_SYMBOL_FIELDS
endif|#
directive|endif
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

begin_define
define|#
directive|define
name|symbol_previous
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_previous)
end_define

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
comment|/* end of struc-symbol.h */
end_comment

end_unit


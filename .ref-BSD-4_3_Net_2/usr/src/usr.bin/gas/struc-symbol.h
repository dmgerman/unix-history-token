begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* struct_symbol.h - Internal symbol structure    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_include
include|#
directive|include
file|"a.out.gnu.h"
end_include

begin_comment
comment|/* Needed to define struct nlist. Sigh. */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"a_out.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|symbol
comment|/* our version of an nlist node */
block|{
name|struct
name|nlist
name|sy_nlist
decl_stmt|;
comment|/* what we write in .o file (if permitted) */
name|long
name|unsigned
name|sy_name_offset
decl_stmt|;
comment|/* 4-origin position of sy_name in symbols */
comment|/* part of object file. */
comment|/* 0 for (nameless) .stabd symbols. */
comment|/* Not used until write_object_file() time. */
name|long
name|int
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

begin_define
define|#
directive|define
name|sy_name
value|sy_nlist .n_un. n_name
end_define

begin_comment
comment|/* Name field always points to a string. */
end_comment

begin_comment
comment|/* 0 means .stabd-like anonymous symbol. */
end_comment

begin_define
define|#
directive|define
name|sy_type
value|sy_nlist.	n_type
end_define

begin_define
define|#
directive|define
name|sy_other
value|sy_nlist.	n_other
end_define

begin_define
define|#
directive|define
name|sy_desc
value|sy_nlist.	n_desc
end_define

begin_define
define|#
directive|define
name|sy_value
value|sy_nlist.	n_value
end_define

begin_comment
comment|/* Value of symbol is this value + object */
end_comment

begin_comment
comment|/* file address of sy_frag. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|valueT
typedef|;
end_typedef

begin_comment
comment|/* The type of n_value. Helps casting. */
end_comment

begin_comment
comment|/* end: struct_symbol.h */
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

end_unit


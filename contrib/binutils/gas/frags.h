begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* frags.h - Header file for the frag concept.    Copyright (C) 1987, 92, 93, 94, 95, 1997 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_struct_decl
struct_decl|struct
name|obstack
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * A macro to speed up appending exactly 1 char  * to current frag.  */
end_comment

begin_comment
comment|/* JF changed< 1 to<= 1 to avoid a race conditon */
end_comment

begin_define
define|#
directive|define
name|FRAG_APPEND_1_CHAR
parameter_list|(
name|datum
parameter_list|)
define|\
value|{					\   if (obstack_room(&frags )<= 1) {\     frag_wane (frag_now);	\     frag_new (0);		\   }				\   obstack_1grow(&frags, datum );	\ }
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
name|frag_append_1_char
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FRAG_APPEND_1_CHAR
parameter_list|(
name|X
parameter_list|)
value|frag_append_1_char (X)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|frag_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fragS
modifier|*
name|frag_alloc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|obstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frag_grow
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|nchars
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|frag_more
name|PARAMS
argument_list|(
operator|(
name|int
name|nchars
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frag_align
name|PARAMS
argument_list|(
operator|(
name|int
name|alignment
operator|,
name|int
name|fill_character
operator|,
name|int
name|max
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frag_align_pattern
name|PARAMS
argument_list|(
operator|(
name|int
name|alignment
operator|,
specifier|const
name|char
operator|*
name|fill_pattern
operator|,
name|int
name|n_fill
operator|,
name|int
name|max
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frag_new
name|PARAMS
argument_list|(
operator|(
name|int
name|old_frags_var_max_size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frag_wane
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
name|fragP
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|frag_variant
name|PARAMS
argument_list|(
operator|(
name|relax_stateT
name|type
operator|,
name|int
name|max_chars
operator|,
name|int
name|var
operator|,
name|relax_substateT
name|subtype
operator|,
name|symbolS
operator|*
name|symbol
operator|,
name|offsetT
name|offset
operator|,
name|char
operator|*
name|opcode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|frag_var
name|PARAMS
argument_list|(
operator|(
name|relax_stateT
name|type
operator|,
name|int
name|max_chars
operator|,
name|int
name|var
operator|,
name|relax_substateT
name|subtype
operator|,
name|symbolS
operator|*
name|symbol
operator|,
name|offsetT
name|offset
operator|,
name|char
operator|*
name|opcode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of frags.h */
end_comment

end_unit


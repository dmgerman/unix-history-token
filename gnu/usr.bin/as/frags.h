begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* frags.h - Header file for the frag concept.     Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|obstack
name|frags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Frags ONLY live in this obstack. */
end_comment

begin_comment
comment|/* We use obstack_next_free() macro */
end_comment

begin_comment
comment|/* so please don't put any other objects */
end_comment

begin_comment
comment|/* on this stack! */
end_comment

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
value|{					\ 					    if (obstack_room(&frags )<= 1) {\ 										  frag_wane (frag_now);	\ 										      frag_new (0);		\ 										  }				\ 										      obstack_1grow(&frags, datum );	\ 										  }
end_define

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
name|frag_more
parameter_list|(
name|int
name|nchars
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|frag_align
parameter_list|(
name|int
name|alignment
parameter_list|,
name|int
name|fill_character
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|frag_new
parameter_list|(
name|int
name|old_frags_var_max_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|frag_wane
parameter_list|(
name|fragS
modifier|*
name|fragP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|frag_variant
parameter_list|(
name|relax_stateT
name|type
parameter_list|,
name|int
name|max_chars
parameter_list|,
name|int
name|var
parameter_list|,
name|relax_substateT
name|subtype
parameter_list|,
name|symbolS
modifier|*
name|symbol
parameter_list|,
name|long
name|offset
parameter_list|,
name|char
modifier|*
name|opcode
parameter_list|,
name|int
name|pcrel_adjust
parameter_list|,
name|int
name|bsr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|frag_var
parameter_list|(
name|relax_stateT
name|type
parameter_list|,
name|int
name|max_chars
parameter_list|,
name|int
name|var
parameter_list|,
name|relax_substateT
name|subtype
parameter_list|,
name|symbolS
modifier|*
name|symbol
parameter_list|,
name|long
name|offset
parameter_list|,
name|char
modifier|*
name|opcode
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
name|frag_more
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|frag_var
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|frag_variant
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|frag_align
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|frag_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|frag_wane
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
comment|/* end of frags.h */
end_comment

end_unit


begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* frags.c - manage frags -     Copyright (C) 1987, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"as.h"
end_include

begin_include
include|#
directive|include
file|"subsegs.h"
end_include

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_decl_stmt
name|struct
name|obstack
name|frags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* All, and only, frags live here. */
end_comment

begin_decl_stmt
name|fragS
name|zero_address_frag
init|=
block|{
literal|0
block|,
comment|/* fr_address */
name|NULL
block|,
comment|/* fr_next */
literal|0
block|,
comment|/* fr_fix */
literal|0
block|,
comment|/* fr_var */
literal|0
block|,
comment|/* fr_symbol */
literal|0
block|,
comment|/* fr_offset */
name|NULL
block|,
comment|/* fr_opcode */
name|rs_fill
block|,
comment|/* fr_type */
literal|0
block|,
comment|/* fr_subtype */
literal|0
block|,
comment|/* fr_pcrel_adjust */
literal|0
block|,
comment|/* fr_bsr */
literal|0
comment|/* fr_literal[0] */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fragS
name|bss_address_frag
init|=
block|{
literal|0
block|,
comment|/* fr_address. Gets filled in to make up 				   sy_value-s. */
name|NULL
block|,
comment|/* fr_next */
literal|0
block|,
comment|/* fr_fix */
literal|0
block|,
comment|/* fr_var */
literal|0
block|,
comment|/* fr_symbol */
literal|0
block|,
comment|/* fr_offset */
name|NULL
block|,
comment|/* fr_opcode */
name|rs_fill
block|,
comment|/* fr_type */
literal|0
block|,
comment|/* fr_subtype */
literal|0
block|,
comment|/* fr_pcrel_adjust */
literal|0
block|,
comment|/* fr_bsr */
literal|0
comment|/* fr_literal[0] */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  *			frag_grow()  *  * Internal.  * Try to augment current frag by nchars chars.  * If there is no room, close of the current frag with a ".fill 0"  * and begin a new frag. Unless the new frag has nchars chars available  * do not return. Do not set up any fields of *now_frag.  */
end_comment

begin_function
specifier|static
name|void
name|frag_grow
parameter_list|(
name|nchars
parameter_list|)
name|unsigned
name|int
name|nchars
decl_stmt|;
block|{
if|if
condition|(
name|obstack_room
argument_list|(
operator|&
name|frags
argument_list|)
operator|<
name|nchars
condition|)
block|{
name|unsigned
name|int
name|n
decl_stmt|,
name|oldn
decl_stmt|;
name|long
name|oldc
decl_stmt|;
name|frag_wane
argument_list|(
name|frag_now
argument_list|)
expr_stmt|;
name|frag_new
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|oldn
operator|=
operator|(
name|unsigned
operator|)
operator|-
literal|1
expr_stmt|;
name|oldc
operator|=
name|frags
operator|.
name|chunk_size
expr_stmt|;
name|frags
operator|.
name|chunk_size
operator|=
literal|2
operator|*
name|nchars
expr_stmt|;
while|while
condition|(
operator|(
name|n
operator|=
name|obstack_room
argument_list|(
operator|&
name|frags
argument_list|)
operator|)
operator|<
name|nchars
operator|&&
name|n
operator|<
name|oldn
condition|)
block|{
name|frag_wane
argument_list|(
name|frag_now
argument_list|)
expr_stmt|;
name|frag_new
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|oldn
operator|=
name|n
expr_stmt|;
block|}
name|frags
operator|.
name|chunk_size
operator|=
name|oldc
expr_stmt|;
block|}
if|if
condition|(
name|obstack_room
argument_list|(
operator|&
name|frags
argument_list|)
operator|<
name|nchars
condition|)
name|as_fatal
argument_list|(
literal|"Can't extend frag %d. chars"
argument_list|,
name|nchars
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* frag_grow() */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *			frag_new()  *  * Call this to close off a completed frag, and start up a new (empty)  * frag, in the same subsegment as the old frag.  * [frchain_now remains the same but frag_now is updated.]  * Because this calculates the correct value of fr_fix by  * looking at the obstack 'frags', it needs to know how many  * characters at the end of the old frag belong to (the maximal)  * fr_var: the rest must belong to fr_fix.  * It doesn't actually set up the old frag's fr_var: you may have  * set fr_var == 1, but allocated 10 chars to the end of the frag:  * in this case you pass old_frags_var_max_size == 10.  *  * Make a new frag, initialising some components. Link new frag at end  * of frchain_now.  */
end_comment

begin_function
name|void
name|frag_new
parameter_list|(
name|old_frags_var_max_size
parameter_list|)
name|int
name|old_frags_var_max_size
decl_stmt|;
comment|/* Number of chars (already allocated on 				   obstack frags) */
comment|/* in variable_length part of frag. */
block|{
specifier|register
name|fragS
modifier|*
name|former_last_fragP
decl_stmt|;
comment|/*    char   *throw_away_pointer; JF unused */
specifier|register
name|frchainS
modifier|*
name|frchP
decl_stmt|;
name|long
name|tmp
decl_stmt|;
comment|/* JF */
name|frag_now
operator|->
name|fr_fix
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
name|obstack_next_free
argument_list|(
operator|&
name|frags
argument_list|)
operator|)
operator|-
operator|(
name|frag_now
operator|->
name|fr_literal
operator|)
operator|-
name|old_frags_var_max_size
expr_stmt|;
comment|/* Fix up old frag's fr_fix. */
name|obstack_finish
argument_list|(
operator|&
name|frags
argument_list|)
expr_stmt|;
comment|/* This will align the obstack so the */
comment|/* next struct we allocate on it will */
comment|/* begin at a correct boundary. */
name|frchP
operator|=
name|frchain_now
expr_stmt|;
name|know
argument_list|(
name|frchP
argument_list|)
expr_stmt|;
name|former_last_fragP
operator|=
name|frchP
operator|->
name|frch_last
expr_stmt|;
name|know
argument_list|(
name|former_last_fragP
argument_list|)
expr_stmt|;
name|know
argument_list|(
name|former_last_fragP
operator|==
name|frag_now
argument_list|)
expr_stmt|;
name|obstack_blank
argument_list|(
operator|&
name|frags
argument_list|,
name|SIZEOF_STRUCT_FRAG
argument_list|)
expr_stmt|;
comment|/* We expect this will begin at a correct */
comment|/* boundary for a struct. */
name|tmp
operator|=
name|obstack_alignment_mask
argument_list|(
operator|&
name|frags
argument_list|)
expr_stmt|;
name|obstack_alignment_mask
argument_list|(
operator|&
name|frags
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/* Turn off alignment */
comment|/* If we ever hit a machine 	   where strings must be 	   aligned, we Lose Big */
name|frag_now
operator|=
operator|(
name|fragS
operator|*
operator|)
name|obstack_finish
argument_list|(
operator|&
name|frags
argument_list|)
expr_stmt|;
name|obstack_alignment_mask
argument_list|(
operator|&
name|frags
argument_list|)
operator|=
name|tmp
expr_stmt|;
comment|/* Restore alignment */
comment|/* Just in case we don't get zero'd bytes */
name|memset
argument_list|(
name|frag_now
argument_list|,
literal|'\0'
argument_list|,
name|SIZEOF_STRUCT_FRAG
argument_list|)
expr_stmt|;
comment|/*    obstack_unaligned_done (&frags,&frag_now); */
comment|/*    know (frags.obstack_c_next_free == frag_now->fr_literal); */
comment|/* Generally, frag_now->points to an */
comment|/* address rounded up to next alignment. */
comment|/* However, characters will add to obstack */
comment|/* frags IMMEDIATELY after the struct frag, */
comment|/* even if they are not starting at an */
comment|/* alignment address. */
name|former_last_fragP
operator|->
name|fr_next
operator|=
name|frag_now
expr_stmt|;
name|frchP
operator|->
name|frch_last
operator|=
name|frag_now
expr_stmt|;
ifndef|#
directive|ifndef
name|NO_LISTING
block|{
specifier|extern
name|struct
name|list_info_struct
modifier|*
name|listing_tail
decl_stmt|;
name|frag_now
operator|->
name|line
operator|=
name|listing_tail
expr_stmt|;
block|}
endif|#
directive|endif
name|frag_now
operator|->
name|fr_next
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/* frag_new() */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *			frag_more()  *  * Start a new frag unless we have n more chars of room in the current frag.  * Close off the old frag with a .fill 0.  *  * Return the address of the 1st char to write into. Advance  * frag_now_growth past the new chars.  */
end_comment

begin_function
name|char
modifier|*
name|frag_more
parameter_list|(
name|nchars
parameter_list|)
name|int
name|nchars
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|retval
decl_stmt|;
name|frag_grow
argument_list|(
name|nchars
argument_list|)
expr_stmt|;
name|retval
operator|=
name|obstack_next_free
argument_list|(
operator|&
name|frags
argument_list|)
expr_stmt|;
name|obstack_blank_fast
argument_list|(
operator|&
name|frags
argument_list|,
name|nchars
argument_list|)
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_comment
comment|/* frag_more() */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *			frag_var()  *  * Start a new frag unless we have max_chars more chars of room in the current frag.  * Close off the old frag with a .fill 0.  *  * Set up a machine_dependent relaxable frag, then start a new frag.  * Return the address of the 1st char of the var part of the old frag  * to write into.  */
end_comment

begin_function
name|char
modifier|*
name|frag_var
parameter_list|(
name|type
parameter_list|,
name|max_chars
parameter_list|,
name|var
parameter_list|,
name|subtype
parameter_list|,
name|symbol
parameter_list|,
name|offset
parameter_list|,
name|opcode
parameter_list|)
name|relax_stateT
name|type
decl_stmt|;
name|int
name|max_chars
decl_stmt|;
name|int
name|var
decl_stmt|;
name|relax_substateT
name|subtype
decl_stmt|;
name|symbolS
modifier|*
name|symbol
decl_stmt|;
name|long
name|offset
decl_stmt|;
name|char
modifier|*
name|opcode
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|retval
decl_stmt|;
name|frag_grow
argument_list|(
name|max_chars
argument_list|)
expr_stmt|;
name|retval
operator|=
name|obstack_next_free
argument_list|(
operator|&
name|frags
argument_list|)
expr_stmt|;
name|obstack_blank_fast
argument_list|(
operator|&
name|frags
argument_list|,
name|max_chars
argument_list|)
expr_stmt|;
name|frag_now
operator|->
name|fr_var
operator|=
name|var
expr_stmt|;
name|frag_now
operator|->
name|fr_type
operator|=
name|type
expr_stmt|;
name|frag_now
operator|->
name|fr_subtype
operator|=
name|subtype
expr_stmt|;
name|frag_now
operator|->
name|fr_symbol
operator|=
name|symbol
expr_stmt|;
name|frag_now
operator|->
name|fr_offset
operator|=
name|offset
expr_stmt|;
name|frag_now
operator|->
name|fr_opcode
operator|=
name|opcode
expr_stmt|;
comment|/* default these to zero. */
name|frag_now
operator|->
name|fr_pcrel_adjust
operator|=
literal|0
expr_stmt|;
name|frag_now
operator|->
name|fr_bsr
operator|=
literal|0
expr_stmt|;
name|frag_new
argument_list|(
name|max_chars
argument_list|)
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_comment
comment|/* frag_var() */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *			frag_variant()  *  * OVE: This variant of frag_var assumes that space for the tail has been  *      allocated by caller.  *      No call to frag_grow is done.  *      Two new arguments have been added.  */
end_comment

begin_function
name|char
modifier|*
name|frag_variant
parameter_list|(
name|type
parameter_list|,
name|max_chars
parameter_list|,
name|var
parameter_list|,
name|subtype
parameter_list|,
name|symbol
parameter_list|,
name|offset
parameter_list|,
name|opcode
parameter_list|,
name|pcrel_adjust
parameter_list|,
name|bsr
parameter_list|)
name|relax_stateT
name|type
decl_stmt|;
name|int
name|max_chars
decl_stmt|;
name|int
name|var
decl_stmt|;
name|relax_substateT
name|subtype
decl_stmt|;
name|symbolS
modifier|*
name|symbol
decl_stmt|;
name|long
name|offset
decl_stmt|;
name|char
modifier|*
name|opcode
decl_stmt|;
name|int
name|pcrel_adjust
decl_stmt|;
name|char
name|bsr
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|retval
decl_stmt|;
comment|/* frag_grow (max_chars); */
name|retval
operator|=
name|obstack_next_free
argument_list|(
operator|&
name|frags
argument_list|)
expr_stmt|;
comment|/*  obstack_blank_fast (&frags, max_chars); */
comment|/* OVE: so far the only diff */
name|frag_now
operator|->
name|fr_var
operator|=
name|var
expr_stmt|;
name|frag_now
operator|->
name|fr_type
operator|=
name|type
expr_stmt|;
name|frag_now
operator|->
name|fr_subtype
operator|=
name|subtype
expr_stmt|;
name|frag_now
operator|->
name|fr_symbol
operator|=
name|symbol
expr_stmt|;
name|frag_now
operator|->
name|fr_offset
operator|=
name|offset
expr_stmt|;
name|frag_now
operator|->
name|fr_opcode
operator|=
name|opcode
expr_stmt|;
name|frag_now
operator|->
name|fr_pcrel_adjust
operator|=
name|pcrel_adjust
expr_stmt|;
name|frag_now
operator|->
name|fr_bsr
operator|=
name|bsr
expr_stmt|;
name|frag_new
argument_list|(
name|max_chars
argument_list|)
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_comment
comment|/* frag_variant() */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *			frag_wane()  *  * Reduce the variable end of a frag to a harmless state.  */
end_comment

begin_function
name|void
name|frag_wane
parameter_list|(
name|fragP
parameter_list|)
specifier|register
name|fragS
modifier|*
name|fragP
decl_stmt|;
block|{
name|fragP
operator|->
name|fr_type
operator|=
name|rs_fill
expr_stmt|;
name|fragP
operator|->
name|fr_offset
operator|=
literal|0
expr_stmt|;
name|fragP
operator|->
name|fr_var
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *			frag_align()  *  * Make a frag for ".align foo,bar". Call is "frag_align (foo,bar);".  * Foo& bar are absolute integers.  *  * Call to close off the current frag with a ".align", then start a new  * (so far empty) frag, in the same subsegment as the last frag.  */
end_comment

begin_function
name|void
name|frag_align
parameter_list|(
name|alignment
parameter_list|,
name|fill_character
parameter_list|)
name|int
name|alignment
decl_stmt|;
name|int
name|fill_character
decl_stmt|;
block|{
operator|*
operator|(
name|frag_var
argument_list|(
name|rs_align
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
operator|(
name|relax_substateT
operator|)
literal|0
argument_list|,
operator|(
name|symbolS
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|long
operator|)
name|alignment
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
operator|)
operator|=
name|fill_character
expr_stmt|;
block|}
end_function

begin_comment
comment|/* frag_align() */
end_comment

begin_comment
comment|/* end of frags.c */
end_comment

end_unit


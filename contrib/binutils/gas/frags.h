begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* frags.h - Header file for the frag concept.    Copyright 1987, 1992, 1993, 1994, 1995, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FRAGS_H
end_ifndef

begin_define
define|#
directive|define
name|FRAGS_H
end_define

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

begin_comment
comment|/* A code fragment (frag) is some known number of chars, followed by some    unknown number of chars. Typically the unknown number of chars is an    instruction address whose size is yet unknown. We always know the greatest    possible size the unknown number of chars may become, and reserve that    much room at the end of the frag.    Once created, frags do not change address during assembly.    We chain the frags in (a) forward-linked list(s). The object-file address    of the 1st char of a frag is generally not known until after relax().    Many things at assembly time describe an address by {object-file-address    of a particular frag}+offset.     BUG: it may be smarter to have a single pointer off to various different    notes for different frag kinds.  See how code pans.   */
end_comment

begin_struct
struct|struct
name|frag
block|{
comment|/* Object file address (as an octet offset).  */
name|addressT
name|fr_address
decl_stmt|;
comment|/* Chain forward; ascending address order.  Rooted in frch_root.  */
name|struct
name|frag
modifier|*
name|fr_next
decl_stmt|;
comment|/* (Fixed) number of octets we know we have.  May be 0.  */
name|offsetT
name|fr_fix
decl_stmt|;
comment|/* May be used for (Variable) number of octets after above.      The generic frag handling code no longer makes any use of fr_var.  */
name|offsetT
name|fr_var
decl_stmt|;
comment|/* For variable-length tail.  */
name|symbolS
modifier|*
name|fr_symbol
decl_stmt|;
comment|/* For variable-length tail.  */
name|offsetT
name|fr_offset
decl_stmt|;
comment|/* Points to opcode low addr byte, for relaxation.  */
name|char
modifier|*
name|fr_opcode
decl_stmt|;
ifndef|#
directive|ifndef
name|NO_LISTING
name|struct
name|list_info_struct
modifier|*
name|line
decl_stmt|;
endif|#
directive|endif
comment|/* Flipped each relax pass so we can easily determine whether      fr_address has been adjusted.  */
name|unsigned
name|int
name|relax_marker
range|:
literal|1
decl_stmt|;
comment|/* What state is my tail in? */
name|relax_stateT
name|fr_type
decl_stmt|;
name|relax_substateT
name|fr_subtype
decl_stmt|;
ifdef|#
directive|ifdef
name|USING_CGEN
comment|/* Don't include this unless using CGEN to keep frag size down.  */
struct|struct
block|{
comment|/* CGEN_INSN entry for this instruction.  */
specifier|const
name|struct
name|cgen_insn
modifier|*
name|insn
decl_stmt|;
comment|/* Index into operand table.  */
name|int
name|opindex
decl_stmt|;
comment|/* Target specific data, usually reloc number.  */
name|int
name|opinfo
decl_stmt|;
block|}
name|fr_cgen
struct|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TC_FRAG_TYPE
name|TC_FRAG_TYPE
name|tc_frag_data
decl_stmt|;
endif|#
directive|endif
comment|/* Where the frag was created, or where it became a variant frag.  */
name|char
modifier|*
name|fr_file
decl_stmt|;
name|unsigned
name|int
name|fr_line
decl_stmt|;
comment|/* Data begins here.  */
name|char
name|fr_literal
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIZEOF_STRUCT_FRAG
define|\
value|((char *) zero_address_frag.fr_literal - (char *)&zero_address_frag)
end_define

begin_comment
comment|/* We want to say fr_literal[0] above.  */
end_comment

begin_comment
comment|/* Current frag we are building.  This frag is incomplete.  It is,    however, included in frchain_now.  The fr_fix field is bogus;    instead, use frag_now_fix ().  */
end_comment

begin_decl_stmt
name|COMMON
name|fragS
modifier|*
name|frag_now
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|addressT
name|frag_now_fix
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|addressT
name|frag_now_fix_octets
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For foreign-segment symbol fixups.  */
end_comment

begin_decl_stmt
name|COMMON
name|fragS
name|zero_address_frag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For local common (N_BSS segment) fixups.  */
end_comment

begin_decl_stmt
name|COMMON
name|fragS
name|bss_address_frag
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* A macro to speed up appending exactly 1 char to current frag.  */
end_comment

begin_comment
comment|/* JF changed< 1 to<= 1 to avoid a race conditon.  */
end_comment

begin_define
define|#
directive|define
name|FRAG_APPEND_1_CHAR
parameter_list|(
name|datum
parameter_list|)
define|\
value|{							\   if (obstack_room (&frags)<= 1)			\     {							\       frag_wane (frag_now);				\       frag_new (0);					\     }							\   obstack_1grow (&frags, datum);			\ }
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
name|frag_align_code
name|PARAMS
argument_list|(
operator|(
name|int
name|alignment
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FRAGS_H */
end_comment

end_unit


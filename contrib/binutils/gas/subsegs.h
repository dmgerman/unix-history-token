begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* subsegs.h -> subsegs.c    Copyright (C) 1987, 92, 93, 94, 95, 1996 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  * For every sub-segment the user mentions in the ASsembler program,  * we make one struct frchain. Each sub-segment has exactly one struct frchain  * and vice versa.  *  * Struct frchain's are forward chained (in ascending order of sub-segment  * code number). The chain runs through frch_next of each subsegment.  * This makes it hard to find a subsegment's frags  * if programmer uses a lot of them. Most programs only use text0 and  * data0, so they don't suffer. At least this way:  * (1)	There are no "arbitrary" restrictions on how many subsegments  *	can be programmed;  * (2)	Subsegments' frchain-s are (later) chained together in the order in  *	which they are emitted for object file viz text then data.  *  * From each struct frchain dangles a chain of struct frags. The frags  * represent code fragments, for that sub-segment, forward chained.  */
end_comment

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_struct
struct|struct
name|frchain
comment|/* control building of a frag chain */
block|{
comment|/* FRCH = FRagment CHain control */
name|struct
name|frag
modifier|*
name|frch_root
decl_stmt|;
comment|/* 1st struct frag in chain, or NULL */
name|struct
name|frag
modifier|*
name|frch_last
decl_stmt|;
comment|/* last struct frag in chain, or NULL */
name|struct
name|frchain
modifier|*
name|frch_next
decl_stmt|;
comment|/* next in chain of struct frchain-s */
name|segT
name|frch_seg
decl_stmt|;
comment|/* SEG_TEXT or SEG_DATA. */
name|subsegT
name|frch_subseg
decl_stmt|;
comment|/* subsegment number of this chain */
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
name|fixS
modifier|*
name|fix_root
decl_stmt|;
comment|/* Root of fixups for this subsegment.  */
name|fixS
modifier|*
name|fix_tail
decl_stmt|;
comment|/* Last fixup for this subsegment.  */
endif|#
directive|endif
name|struct
name|obstack
name|frch_obstack
decl_stmt|;
comment|/* for objects in this frag chain */
name|fragS
modifier|*
name|frch_frag_now
decl_stmt|;
comment|/* frag_now for this subsegment */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|frchain
name|frchainS
typedef|;
end_typedef

begin_comment
comment|/* All subsegments' chains hang off here.  NULL means no frchains yet.  */
end_comment

begin_decl_stmt
specifier|extern
name|frchainS
modifier|*
name|frchain_root
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Frchain we are assembling into now.  That is, the current segment's    frag chain, even if it contains no (complete) frags. */
end_comment

begin_decl_stmt
specifier|extern
name|frchainS
modifier|*
name|frchain_now
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|frchainS
modifier|*
name|frchainP
decl_stmt|;
name|unsigned
name|int
name|hadone
range|:
literal|1
decl_stmt|;
comment|/* This field is set if this is a .bss section which does not really      have any contents.  Once upon a time a .bss section did not have      any frags, but that is no longer true.  This field prevent the      SEC_HAS_CONTENTS flag from being set for the section even if      there are frags.  */
name|unsigned
name|int
name|bss
range|:
literal|1
decl_stmt|;
name|int
name|user_stuff
decl_stmt|;
comment|/* Fixups for this segment.  If BFD_ASSEMBLER, this is only valid      after the frchains are run together.  */
name|fixS
modifier|*
name|fix_root
decl_stmt|;
name|fixS
modifier|*
name|fix_tail
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|MANY_SEGMENTS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BFD_ASSEMBLER
argument_list|)
name|struct
name|internal_scnhdr
name|scnhdr
decl_stmt|;
name|enum
name|linkonce_type
name|linkonce
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
endif|#
directive|endif
name|symbolS
modifier|*
name|dot
decl_stmt|;
name|struct
name|lineno_list
modifier|*
name|lineno_list_head
decl_stmt|;
name|struct
name|lineno_list
modifier|*
name|lineno_list_tail
decl_stmt|;
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
comment|/* Which BFD section does this gas segment correspond to?  */
name|asection
modifier|*
name|bfd_section
decl_stmt|;
comment|/* NULL, or pointer to the gas symbol that is the section symbol for      this section.  sym->bsym and bfd_section->symbol should be the same.  */
name|symbolS
modifier|*
name|sym
decl_stmt|;
endif|#
directive|endif
union|union
block|{
comment|/* Current size of section holding stabs strings.  */
name|unsigned
name|long
name|stab_string_size
decl_stmt|;
comment|/* Initial frag for ELF.  */
name|char
modifier|*
name|p
decl_stmt|;
block|}
name|stabu
union|;
ifdef|#
directive|ifdef
name|NEED_LITERAL_POOL
name|unsigned
name|long
name|literal_pool_size
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TC_SEGMENT_INFO_TYPE
name|TC_SEGMENT_INFO_TYPE
name|tc_segment_info_data
decl_stmt|;
endif|#
directive|endif
block|}
name|segment_info_type
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_decl_stmt
specifier|extern
name|segment_info_type
modifier|*
name|seg_info
name|PARAMS
argument_list|(
operator|(
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|section_symbol
name|PARAMS
argument_list|(
operator|(
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! BFD_ASSEMBLER */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MANY_SEGMENTS
end_ifdef

begin_decl_stmt
specifier|extern
name|segment_info_type
name|segment_info
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|seg_info
parameter_list|(
name|SEC
parameter_list|)
value|(&segment_info[SEC])
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Sentinel for frchain crawling.  Points to the 1st data-segment    frchain.  (Which is pointed to by the last text-segment frchain.) */
end_comment

begin_decl_stmt
specifier|extern
name|frchainS
modifier|*
name|data0_frchainP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frchainS
modifier|*
name|bss0_frchainP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dummy so stuff can compile.  Should never be used.  */
end_comment

begin_struct
struct|struct
name|seg_info_trash
block|{
struct|struct
block|{
name|unsigned
name|stab_string_size
range|:
literal|1
decl_stmt|;
block|}
name|stabu
struct|;
name|unsigned
name|hadone
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|seg_info
parameter_list|(
name|S
parameter_list|)
value|(abort (), (struct seg_info_trash *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BFD_ASSEMBLER */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|subsegs_print_statistics
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of subsegs.h */
end_comment

end_unit

